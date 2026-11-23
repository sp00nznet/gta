/*
 * dplay.c -- a DirectPlay of our own, for GTA1's network game, over TCP.
 *
 * GTA1 plays up to four over DirectPlay 5's IDirectPlay2A, and uses ten of its
 * methods (its network layer is 0x486880-0x487620): it enumerates the service
 * providers, creates a DirectPlay on the first, then
 *
 *   host:  Open(DPOPEN_CREATE, "session name", max 4)  CreatePlayer
 *   join:  EnumSessions -> its list -> Open(DPOPEN_JOIN)  CreatePlayer
 *   both:  EnumPlayers (sorted by id: the order is the player number),
 *          Send to each other player, Receive(DPRECEIVE_ALL) <= 256 bytes,
 *          ignoring anything not to its own player (system messages too),
 *          DestroyPlayer, Close, Release.
 *
 * So that is what this implements, as a star: the host listens on TCP
 * (port 2350 by default), each client keeps one connection to it, and the
 * host routes. Player ids are handed out by the host in join order, so the
 * host is player 1 and the order is the same on every machine. Messages are
 * length-prefixed records; nothing about real DirectPlay's wire format
 * matters, since both ends are this file.
 *
 * Where to find the host: --join ADDR[:PORT] (default 127.0.0.1), or
 * [net] join= in gta1.ini; the host listens on --port (2350) on every
 * interface. Network tests stay on 127.0.0.1 or the LAN.
 */
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#endif

#define RECOMP_GENERATED_CODE
#include "../engine/recomp_runtime.h"
#include "dplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DP_OK               0u
#define DPERR_GENERIC       0x80004005u
#define DPERR_NOMESSAGES    0x88770190u
#define DPERR_BUFFERTOOSMALL 0x8877001Eu
#define DPERR_NOSESSIONS    0x88770168u
#define DPERR_INVALIDPLAYER 0x88770096u
#define DPOPEN_JOIN         1u
#define DPOPEN_CREATE       2u
#define DPESC_TIMEDOUT      1u

#define MAX_PLAYERS 4
#define MAX_MSG     1024
#define INBOX       16384   /* a frame is a few messages; never drop one: a lost frame stalls the game */

char g_dp_join[128] = "127.0.0.1";   /* settings.c: --join / [net] join= */
int  g_dp_port = 2350;               /* --port / [net] port= */

extern u32 g_bridge_hit;
extern u32 recomp_alloc_bridge(const char *name, void (*handler)(void));

/* ------------------------------------------------------------ wire ------- */

enum { M_QUERY = 1, M_SESSION, M_JOIN, M_CREATE, M_YOURID, M_PLAYERS, M_DATA, M_DESTROY };

typedef struct { u32 type, a, b, len; unsigned char data[MAX_MSG]; } msg_t;
#define HDR 16

static int send_all(SOCKET s, const void *p, int n) {
    const char *c = p;
    while (n > 0) { int k = send(s, c, n, 0); if (k <= 0) return 0; c += k; n -= k; }
    return 1;
}
static int recv_all(SOCKET s, void *p, int n) {
    char *c = p;
    while (n > 0) { int k = recv(s, c, n, 0); if (k <= 0) return 0; c += k; n -= k; }
    return 1;
}
static int put(SOCKET s, u32 type, u32 a, u32 b, const void *data, u32 len) {
    msg_t m;
    if (s == INVALID_SOCKET || len > MAX_MSG) return 0;
    m.type = type; m.a = a; m.b = b; m.len = len;
    if (len) memcpy(m.data, data, len);
    return send_all(s, &m, HDR + (int)len);
}
static int get(SOCKET s, msg_t *m) {
    if (!recv_all(s, m, HDR) || m->len > MAX_MSG) return 0;
    return recv_all(s, m->data, (int)m->len);
}

/* ------------------------------------------------------------ state ------ */

static CRITICAL_SECTION s_lock;
static int    s_is_host, s_open;
static SOCKET s_listen = INVALID_SOCKET, s_link = INVALID_SOCKET;   /* client: to the host */
static char   s_session[64];
static struct { u32 id; SOCKET via; char name[32]; } s_players[MAX_PLAYERS];   /* via: host's link to its owner */
static int    s_nplayers;
static u32    s_next_id = 0x1001;
static u32    s_my_id;
static HANDLE s_reply;                 /* client: M_YOURID / M_SESSION arrived */
static u32    s_reply_id;
static struct { u32 from, to, len; unsigned char data[256]; } s_inbox[INBOX];
static int    s_in_head, s_in_tail;
static SOCKET s_clients[MAX_PLAYERS];
static unsigned s_stat_in, s_stat_drop, s_stat_out, s_stat_got;   /* GTA_NET_STATS */

static void inbox_push(u32 from, u32 to, const void *data, u32 len) {
    int next;
    if (len > 256) len = 256;
    EnterCriticalSection(&s_lock);
    next = (s_in_tail + 1) % INBOX;
    if (next != s_in_head) {
        s_inbox[s_in_tail].from = from; s_inbox[s_in_tail].to = to; s_inbox[s_in_tail].len = len;
        memcpy(s_inbox[s_in_tail].data, data, len);
        s_in_tail = next;
        s_stat_in++;
    } else s_stat_drop++;
    LeaveCriticalSection(&s_lock);
}

static int local_player(u32 id) {   /* ours: created in this process */
    return id && id == s_my_id;
}

/* Host: the player list to every client. Under s_lock. */
static void broadcast_players(void) {
    u32 ids[MAX_PLAYERS];
    int i;
    for (i = 0; i < s_nplayers; i++) ids[i] = s_players[i].id;
    for (i = 0; i < MAX_PLAYERS; i++)
        if (s_clients[i] != INVALID_SOCKET) put(s_clients[i], M_PLAYERS, (u32)s_nplayers, 0, ids, 4u * s_nplayers);
}

static void remove_player(u32 id) {
    int i;
    for (i = 0; i < s_nplayers; i++)
        if (s_players[i].id == id) {
            s_players[i] = s_players[--s_nplayers];
            break;
        }
}

/* Host: route one data message. Under s_lock. */
static void route(u32 from, u32 to, const void *data, u32 len) {
    int i;
    if (local_player(to)) { inbox_push(from, to, data, len); return; }   /* the lock is re-entrant */
    for (i = 0; i < s_nplayers; i++)
        if (s_players[i].id == to && s_players[i].via != INVALID_SOCKET) {
            put(s_players[i].via, M_DATA, from, to, data, len);
            return;
        }
}

/* Host: one client connection. */
static DWORD WINAPI host_client_thread(LPVOID arg) {
    SOCKET c = (SOCKET)(uintptr_t)arg;
    msg_t *mm = malloc(sizeof *mm);
    int slot = -1, i;
    EnterCriticalSection(&s_lock);
    for (i = 0; i < MAX_PLAYERS; i++) if (s_clients[i] == INVALID_SOCKET) { s_clients[i] = c; slot = i; break; }
    LeaveCriticalSection(&s_lock);
    while (mm && slot >= 0 && get(c, mm)) {
        EnterCriticalSection(&s_lock);
        switch (mm->type) {
        case M_QUERY:
            put(c, M_SESSION, MAX_PLAYERS, (u32)s_nplayers, s_session, (u32)strlen(s_session) + 1);
            break;
        case M_JOIN:
            break;
        case M_CREATE:
            if (s_nplayers < MAX_PLAYERS) {
                u32 id = s_next_id++;
                s_players[s_nplayers].id = id;
                s_players[s_nplayers].via = c;
                lstrcpynA(s_players[s_nplayers].name, (const char *)mm->data, sizeof s_players[0].name);
                s_nplayers++;
                put(c, M_YOURID, id, 0, NULL, 0);
                fprintf(stderr, "[dplay] host: player 0x%X joined (%d now)\n", id, s_nplayers);
                broadcast_players();
            } else {
                put(c, M_YOURID, 0, 0, NULL, 0);
            }
            break;
        case M_DATA:
            route(mm->a, mm->b, mm->data, mm->len);
            break;
        case M_DESTROY:
            remove_player(mm->a);
            broadcast_players();
            break;
        }
        LeaveCriticalSection(&s_lock);
    }
    EnterCriticalSection(&s_lock);
    for (i = 0; i < s_nplayers; )                    /* its players leave with it */
        if (s_players[i].via == c) remove_player(s_players[i].id); else i++;
    if (slot >= 0) s_clients[slot] = INVALID_SOCKET;
    broadcast_players();
    LeaveCriticalSection(&s_lock);
    closesocket(c);
    free(mm);
    return 0;
}

static DWORD WINAPI host_listen_thread(LPVOID arg) {
    (void)arg;
    for (;;) {
        SOCKET c = accept(s_listen, NULL, NULL);
        if (c == INVALID_SOCKET) return 0;
        { int one = 1; setsockopt(c, IPPROTO_TCP, TCP_NODELAY, (const char *)&one, sizeof one); }
        fprintf(stderr, "[dplay] host: a client connected\n");
        CreateThread(NULL, 0, host_client_thread, (LPVOID)(uintptr_t)c, 0, NULL);
    }
}

/* Client: everything from the host. */
static DWORD WINAPI client_thread(LPVOID arg) {
    msg_t *m = malloc(sizeof *m);
    int i;
    (void)arg;
    while (m && get(s_link, m)) {
        switch (m->type) {
        case M_SESSION:
            EnterCriticalSection(&s_lock);
            lstrcpynA(s_session, (const char *)m->data, sizeof s_session);
            s_nplayers = (int)m->b;
            LeaveCriticalSection(&s_lock);
            SetEvent(s_reply);
            break;
        case M_YOURID:
            s_reply_id = m->a;
            SetEvent(s_reply);
            break;
        case M_PLAYERS:
            EnterCriticalSection(&s_lock);
            s_nplayers = (int)(m->a > MAX_PLAYERS ? MAX_PLAYERS : m->a);
            for (i = 0; i < s_nplayers; i++) {
                s_players[i].id = ((u32 *)m->data)[i];
                s_players[i].via = INVALID_SOCKET;
            }
            LeaveCriticalSection(&s_lock);
            fprintf(stderr, "[dplay] client: %d players\n", s_nplayers);
            break;
        case M_DATA:
            inbox_push(m->a, m->b, m->data, m->len);
            break;
        }
    }
    fprintf(stderr, "[dplay] client: the host is gone\n");
    EnterCriticalSection(&s_lock);
    s_nplayers = 0;
    LeaveCriticalSection(&s_lock);
    free(m);
    return 0;
}

static void net_init(void) {
    static int done;
    WSADATA w;
    int i;
    if (done) return;
    done = 1;
    WSAStartup(MAKEWORD(2, 2), &w);
    InitializeCriticalSection(&s_lock);
    s_reply = CreateEventA(NULL, FALSE, FALSE, NULL);
    for (i = 0; i < MAX_PLAYERS; i++) s_clients[i] = INVALID_SOCKET;
}

/* Client: a connection to the host, if there is none. */
static int connect_host(void) {
    char host[128], *colon;
    int port = g_dp_port;
    struct addrinfo hints = {0}, *ai = NULL;
    char ports[16];
    if (s_link != INVALID_SOCKET) return 1;
    lstrcpynA(host, g_dp_join, sizeof host);
    colon = strrchr(host, ':');
    if (colon) { *colon = 0; port = atoi(colon + 1); }
    sprintf(ports, "%d", port);
    hints.ai_family = AF_INET; hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, ports, &hints, &ai) || !ai) return 0;
    s_link = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connect(s_link, ai->ai_addr, (int)ai->ai_addrlen)) {
        closesocket(s_link); s_link = INVALID_SOCKET; freeaddrinfo(ai);
        return 0;
    }
    freeaddrinfo(ai);
    { int one = 1; setsockopt(s_link, IPPROTO_TCP, TCP_NODELAY, (const char *)&one, sizeof one); }
    fprintf(stderr, "[dplay] client: connected to %s:%d\n", host, port);
    CreateThread(NULL, 0, client_thread, NULL, 0, NULL);
    return 1;
}

static int host_start(const char *name) {
    struct sockaddr_in a = {0};
    int one = 1;
    lstrcpynA(s_session, name && *name ? name : "GTA", sizeof s_session);
    s_listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    setsockopt(s_listen, SOL_SOCKET, SO_REUSEADDR, (const char *)&one, sizeof one);
    a.sin_family = AF_INET; a.sin_port = htons((u_short)g_dp_port); a.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(s_listen, (struct sockaddr *)&a, sizeof a) || listen(s_listen, 4)) {
        fprintf(stderr, "[dplay] host: cannot listen on port %d (%d)\n", g_dp_port, WSAGetLastError());
        closesocket(s_listen); s_listen = INVALID_SOCKET;
        return 0;
    }
    s_is_host = 1;
    CreateThread(NULL, 0, host_listen_thread, NULL, 0, NULL);
    fprintf(stderr, "[dplay] host: session '%s' on port %d\n", s_session, g_dp_port);
    return 1;
}

/* ------------------------------------------------------------ COM -------- */

static u32 call_lifted(u32 va, const u32 *args, int n) {
    recomp_func_t fn = recomp_lookup(va);
    u32 saved_esp = esp, result;
    int i;
    if (!fn) { fprintf(stderr, "[dplay] callback 0x%08X is not lifted\n", va); return 0; }
    for (i = n - 1; i >= 0; i--) PUSH32(esp, args[i]);
    PUSH32(esp, RECOMP_RETADDR);
    fn();
    result = eax;
    esp = saved_esp;
    return result;
}

#define DP_SLOTS 32
/* Stack slots per method, `this` included: what the callee pops. */
static const unsigned char k_argc[DP_SLOTS] = {
    3, 1, 1, 3, 1, 6, 7, 3, 2, 2, 6, 5, 5, 6, 3, 5,
    4, 3, 4, 4, 5, 4, 3, 2, 3, 6, 6, 5, 4, 5, 4, 3
};
static const char *const k_name[DP_SLOTS] = {
    "QueryInterface", "AddRef", "Release", "AddPlayerToGroup", "Close", "CreateGroup", "CreatePlayer",
    "DeletePlayerFromGroup", "DestroyGroup", "DestroyPlayer", "EnumGroupPlayers", "EnumGroups",
    "EnumPlayers", "EnumSessions", "GetCaps", "GetGroupData", "GetGroupName", "GetMessageCount",
    "GetPlayerAddress", "GetPlayerCaps", "GetPlayerData", "GetPlayerName", "GetSessionDesc",
    "Initialize", "Open", "Receive", "Send", "SetGroupData", "SetGroupName", "SetPlayerData",
    "SetPlayerName", "SetSessionDesc"
};

static u32 s_vtable, s_object;
static unsigned char s_slot_of[1024];

/* EnumSessions(lpsd, dwTimeout, cb, ctx, flags) */
static u32 enum_sessions(u32 cb, u32 ctx) {
    static u32 desc, name, timeout;
    u32 args[4];
    if (!desc) { desc = recomp_scratch_alloc(0x50); name = recomp_scratch_alloc(64); timeout = recomp_scratch_alloc(4); }
    if (!s_is_host && connect_host()) {
        ResetEvent(s_reply);
        put(s_link, M_QUERY, 0, 0, NULL, 0);
        if (WaitForSingleObject(s_reply, 2000) == WAIT_OBJECT_0) {
            int i;
            for (i = 0; i < 0x50; i += 4) MEM32(desc + i) = 0;
            MEM32(desc + 0x00) = 0x50;
            MEM32(desc + 0x08) = 0x47544131;               /* guidInstance: the one session */
            MEM32(desc + 0x28) = MAX_PLAYERS;
            MEM32(desc + 0x2C) = (u32)s_nplayers;
            EnterCriticalSection(&s_lock);
            for (i = 0; i < 63 && s_session[i]; i++) MEM8(name + i) = (u8)s_session[i];
            LeaveCriticalSection(&s_lock);
            MEM8(name + i) = 0;
            MEM32(desc + 0x30) = name;
            MEM32(timeout) = 0;
            fprintf(stderr, "[dplay] client: found session '%s'\n", s_session);
            args[0] = desc; args[1] = timeout; args[2] = 0; args[3] = ctx;
            call_lifted(cb, args, 4);
        }
    }
    MEM32(timeout) = 0;
    args[0] = 0; args[1] = timeout; args[2] = DPESC_TIMEDOUT; args[3] = ctx;
    call_lifted(cb, args, 4);
    return DP_OK;
}

static u32 create_player(u32 pid_out, u32 name_va) {
    char name[32] = "";
    if (name_va && MEM32(name_va + 8)) {
        u32 p = MEM32(name_va + 8);
        int i;
        for (i = 0; i < 31 && MEM8(p + i); i++) name[i] = (char)MEM8(p + i);
        name[i] = 0;
    }
    if (s_is_host) {
        EnterCriticalSection(&s_lock);
        if (s_nplayers >= MAX_PLAYERS) { LeaveCriticalSection(&s_lock); return DPERR_GENERIC; }
        s_my_id = s_next_id++;
        s_players[s_nplayers].id = s_my_id;
        s_players[s_nplayers].via = INVALID_SOCKET;
        lstrcpynA(s_players[s_nplayers].name, name, sizeof s_players[0].name);
        s_nplayers++;
        broadcast_players();
        LeaveCriticalSection(&s_lock);
    } else {
        if (s_link == INVALID_SOCKET) return DPERR_GENERIC;
        ResetEvent(s_reply);
        s_reply_id = 0;
        put(s_link, M_CREATE, 0, 0, name, (u32)strlen(name) + 1);
        if (WaitForSingleObject(s_reply, 5000) != WAIT_OBJECT_0 || !s_reply_id) return DPERR_GENERIC;
        s_my_id = s_reply_id;
        Sleep(50);                                     /* the player list follows its id */
    }
    fprintf(stderr, "[dplay] our player is 0x%X ('%s')\n", s_my_id, name);
    if (pid_out) MEM32(pid_out) = s_my_id;
    return DP_OK;
}

static u32 enum_players(u32 cb, u32 ctx) {
    static u32 dpname;
    u32 ids[MAX_PLAYERS], args[5];
    int n, i;
    if (!dpname) { dpname = recomp_scratch_alloc(16); MEM32(dpname) = 16; }
    EnterCriticalSection(&s_lock);
    n = s_nplayers;
    for (i = 0; i < n; i++) ids[i] = s_players[i].id;
    LeaveCriticalSection(&s_lock);
    for (i = 0; i < n; i++) {
        args[0] = ids[i]; args[1] = 0 /* DPPLAYERTYPE_PLAYER */; args[2] = dpname; args[3] = 0; args[4] = ctx;
        if (!call_lifted(cb, args, 5)) break;
    }
    return DP_OK;
}

/* Send(from, to, flags, data, size) */
static u32 dp_send(u32 from, u32 to, u32 data, u32 size) {
    unsigned char buf[MAX_MSG];
    u32 i;
    if (size > MAX_MSG) return DPERR_GENERIC;
    for (i = 0; i < size; i++) buf[i] = MEM8(data + i);
    s_stat_out++;
    if (s_is_host) {
        EnterCriticalSection(&s_lock);
        if (to == 0) {                                 /* DPID_ALLPLAYERS */
            int k;
            for (k = 0; k < s_nplayers; k++)
                if (s_players[k].id != from) route(from, s_players[k].id, buf, size);
        } else route(from, to, buf, size);
        LeaveCriticalSection(&s_lock);
        return DP_OK;
    }
    if (to == 0) {
        int k;
        for (k = 0; k < s_nplayers; k++)
            if (s_players[k].id != from && !put(s_link, M_DATA, from, s_players[k].id, buf, size)) return DPERR_GENERIC;
        return DP_OK;
    }
    return put(s_link, M_DATA, from, to, buf, size) ? DP_OK : DPERR_GENERIC;
}

/* Receive(lpidFrom, lpidTo, flags, data, lpdwSize) */
static u32 dp_receive(u32 pfrom, u32 pto, u32 data, u32 psize) {
    u32 r = DPERR_NOMESSAGES, i, cap = psize ? MEM32(psize) : 0;
    static DWORD last;
    if (GetTickCount() - last > 5000) {   /* every 5 s: traffic, for the test logs */
        last = GetTickCount();
        fprintf(stderr, "[dplay] stats: in %u got %u out %u dropped %u queued %d\n", s_stat_in, s_stat_got,
                s_stat_out, s_stat_drop, (s_in_tail - s_in_head + INBOX) % INBOX);
    }
    EnterCriticalSection(&s_lock);
    if (s_in_head != s_in_tail) {
        if (s_inbox[s_in_head].len > cap || !data) {
            if (psize) MEM32(psize) = s_inbox[s_in_head].len;
            r = DPERR_BUFFERTOOSMALL;
        } else {
            if (pfrom) MEM32(pfrom) = s_inbox[s_in_head].from;
            if (pto) MEM32(pto) = s_inbox[s_in_head].to;
            for (i = 0; i < s_inbox[s_in_head].len; i++) MEM8(data + i) = s_inbox[s_in_head].data[i];
            MEM32(psize) = s_inbox[s_in_head].len;
            s_in_head = (s_in_head + 1) % INBOX;
            s_stat_got++;
            r = DP_OK;
        }
    }
    LeaveCriticalSection(&s_lock);
    return r;
}

static void dp_close(void) {
    if (!s_open) return;
    s_open = 0;
    if (s_is_host) {
        int i;
        EnterCriticalSection(&s_lock);
        for (i = 0; i < MAX_PLAYERS; i++)
            if (s_clients[i] != INVALID_SOCKET) shutdown(s_clients[i], SD_BOTH);
        LeaveCriticalSection(&s_lock);
        if (s_listen != INVALID_SOCKET) { closesocket(s_listen); s_listen = INVALID_SOCKET; }
    } else if (s_link != INVALID_SOCKET) {
        shutdown(s_link, SD_BOTH);
        closesocket(s_link);
        s_link = INVALID_SOCKET;
    }
    EnterCriticalSection(&s_lock);
    s_nplayers = 0; s_my_id = 0; s_is_host = 0;
    s_in_head = s_in_tail = 0;
    LeaveCriticalSection(&s_lock);
    fprintf(stderr, "[dplay] closed\n");
}

static void dp_dispatch(void) {
    int slot = s_slot_of[(g_bridge_hit) & 1023];
    int argc = slot < DP_SLOTS ? k_argc[slot] : 1;
    u32 r = DP_OK;
    if (slot != 25 && slot != 26 && slot != 12) fprintf(stderr, "[dplay] %s\n", k_name[slot]);
    switch (slot) {
    case 0:  if (ARG(3)) MEM32(ARG(3)) = s_object; break;            /* QueryInterface: we are IDirectPlay2A */
    case 1:  r = 1; break;                                           /* AddRef */
    case 2:  r = 0; break;                                           /* Release */
    case 4:  dp_close(); break;                                      /* Close */
    case 6:  r = create_player(ARG(2), ARG(3)); break;               /* CreatePlayer(lpid, name, ev, data, size, flags) */
    case 9:                                                          /* DestroyPlayer(id) */
        if (s_is_host) { EnterCriticalSection(&s_lock); remove_player(ARG(2)); broadcast_players(); LeaveCriticalSection(&s_lock); }
        else put(s_link, M_DESTROY, ARG(2), 0, NULL, 0);
        if (ARG(2) == s_my_id) s_my_id = 0;
        break;
    case 12: r = enum_players(ARG(3), ARG(4)); break;                /* EnumPlayers(guid, cb, ctx, flags) */
    case 13: r = enum_sessions(ARG(4), ARG(5)); break;               /* EnumSessions(sd, timeout, cb, ctx, flags) */
    case 24:                                                         /* Open(sd, flags) */
        if (ARG(3) & DPOPEN_CREATE) {
            char name[64] = "";
            u32 p = MEM32(ARG(2) + 0x30);
            int i;
            for (i = 0; p && i < 63 && MEM8(p + i); i++) name[i] = (char)MEM8(p + i);
            name[i] = 0;
            r = host_start(name) ? DP_OK : DPERR_GENERIC;
        } else {
            r = connect_host() ? DP_OK : DPERR_NOSESSIONS;
            if (r == DP_OK) put(s_link, M_JOIN, 0, 0, NULL, 0);
        }
        if (r == DP_OK) s_open = 1;
        break;
    case 25: r = dp_receive(ARG(2), ARG(3), ARG(5), ARG(6)); break;
    case 26: r = dp_send(ARG(2), ARG(3), ARG(5), ARG(6)); break;
    default:
        fprintf(stderr, "[dplay] %s: not implemented, DP_OK\n", k_name[slot]);
        break;
    }
    eax = r;
    esp += 4 + 4 * argc;
}

static void make_object(void) {
    int i;
    if (s_object) return;
    net_init();
    s_vtable = recomp_scratch_alloc(DP_SLOTS * 4);
    for (i = 0; i < DP_SLOTS; i++) {
        u32 cookie = recomp_alloc_bridge("IDirectPlay2A", dp_dispatch);
        s_slot_of[cookie & 1023] = (unsigned char)i;
        MEM32(s_vtable + i * 4) = cookie;
    }
    s_object = recomp_scratch_alloc(8);
    MEM32(s_object) = s_vtable;
}

/* DirectPlayCreate(lpGUID, lplpDP, pUnk) -- ordinal 1 */
void dplay_bridge_create(void) {
    make_object();
    if (ARG(2)) MEM32(ARG(2)) = s_object;
    eax = DP_OK;
    esp += 4 + 12;
}

/* DirectPlayEnumerateA(cb, ctx) -- ordinal 2.
 *
 * Enumerating is not optional, even for a single-player game. GTA1's front end
 * counts the service providers the callback reports, and the count gates
 * everything downstream: with none, state 0 never routed to state 15 or 16,
 * so states 5 and 3 -- the two that promote the audio mode -- were
 * unreachable, and the play state span forever. One provider is reported. */
void dplay_bridge_enumerate(void) {
    u32 cb = ARG(1), ctx = ARG(2);
    static u32 guid_va, name_va;
    u32 args[5];
    if (!guid_va) {
        static const unsigned char guid[16] = {   /* ours; the game only stores and compares it */
            0x36,0x3B,0x58,0x5A,0x3B,0xE1,0x11,0xD0,0x9C,0x0B,0x00,0xA0,0xC9,0x06,0x28,0x02 };
        int i;
        guid_va = recomp_scratch_alloc(16);
        for (i = 0; i < 16; i++) MEM8(guid_va + i) = guid[i];
        name_va = recomp_scratch_str("Internet TCP/IP Connection");
    }
    args[0] = guid_va; args[1] = name_va; args[2] = 9; args[3] = 0; args[4] = ctx;
    if (cb) call_lifted(cb, args, 5);
    eax = DP_OK;
    esp += 4 + 8;
}
