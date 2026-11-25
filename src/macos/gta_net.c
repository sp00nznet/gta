/* gta_net.c -- a DirectPlay of our own, for the native macOS host: GTA1's
 * network game over TCP.
 *
 * Ported from src/net/dplay.c (the Windows host's), on the same design: the
 * game uses ten of IDirectPlay2A's methods (its network layer is
 * 0x486880-0x487620); it enumerates the service providers, creates a
 * DirectPlay on the first, then
 *
 *   host:  Open(DPOPEN_CREATE, "session name", max 4)  CreatePlayer
 *   join:  EnumSessions -> its list -> Open(DPOPEN_JOIN)  CreatePlayer
 *   both:  EnumPlayers (sorted by id: the order is the player number),
 *          Send to each other player, Receive(DPRECEIVE_ALL) <= 256 bytes,
 *          ignoring anything not to its own player (system messages too),
 *          DestroyPlayer, Close, Release.
 *
 * A star: the host listens on TCP (port 2350 by default), each client keeps
 * one connection to it, and the host routes. Player ids are handed out by
 * the host in join order, so the host is player 1 and the order is the same
 * on every machine. Messages are length-prefixed records; nothing about real
 * DirectPlay's wire format matters, since both ends are this file.
 *
 * The port: BSD sockets and pthreads for winsock and Windows events, and
 * win32hle's COM instead of the Windows host's bridge cookies -- the ten
 * methods are shims ("IDirectPlay2A::Open" ...), the vtable win32hle builds
 * from them, and a callback into the guest is hle_call_guest. Blocking waits
 * give the machine up (hle_block_begin/_end), so a client waiting on its
 * host does not hold the game.
 *
 * Where to find the host: --join ADDR[:PORT] (default 127.0.0.1); the host
 * listens on --port (2350) on every interface.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "win32hle.h"

#define DP_OK                 0u
#define DPERR_GENERIC         0x80004005u
#define DPERR_NOMESSAGES      0x88770190u
#define DPERR_BUFFERTOOSMALL  0x8877001Eu
#define DPERR_NOSESSIONS      0x88770168u
#define DPOPEN_JOIN           1u
#define DPOPEN_CREATE         2u
#define DPESC_TIMEDOUT        1u

#define MAX_PLAYERS 4
#define MAX_MSG     1024
#define INBOX       16384   /* a frame is a few messages; never drop one: a lost frame stalls the game */

char g_dp_join[128] = "127.0.0.1";   /* main.c: --join */
int  g_dp_port = 2350;               /* --port */

typedef uint32_t u32;
typedef uint8_t  u8;

/* ------------------------------------------------------------ wire ------- */

enum { M_QUERY = 1, M_SESSION, M_JOIN, M_CREATE, M_YOURID, M_PLAYERS, M_DATA, M_DESTROY };

typedef struct { u32 type, a, b, len; unsigned char data[MAX_MSG]; } msg_t;
#define HDR 16
#define DP_BAD  -1

static int send_all(int s, const void *p, int n) {
    const char *c = p;
    while (n > 0) { int k = (int)send(s, c, (size_t)n, 0); if (k <= 0) return 0; c += k; n -= k; }
    return 1;
}
static int recv_all(int s, void *p, int n) {
    char *c = p;
    while (n > 0) { int k = (int)recv(s, c, (size_t)n, 0); if (k <= 0) return 0; c += k; n -= k; }
    return 1;
}
static int put(int s, u32 type, u32 a, u32 b, const void *data, u32 len) {
    msg_t m;
    if (s == DP_BAD || len > MAX_MSG) return 0;
    m.type = type; m.a = a; m.b = b; m.len = len;
    if (len) memcpy(m.data, data, len);
    return send_all(s, &m, HDR + (int)len);
}
static int get(int s, msg_t *m) {
    if (!recv_all(s, m, HDR) || m->len > MAX_MSG) return 0;
    return recv_all(s, m->data, (int)m->len);
}

/* ------------------------------------------------------------ state ------ */

static pthread_mutex_t s_lock = PTHREAD_MUTEX_INITIALIZER;
/* the client's "a reply arrived" wait: a condvar with the machine given up */
static pthread_mutex_t s_reply_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  s_reply_cond = PTHREAD_COND_INITIALIZER;
static int s_reply_set;

static int    s_is_host, s_open;
static int    s_listen = DP_BAD, s_link = DP_BAD;   /* client: to the host */
static char   s_session[64];
static struct { u32 id; int via; char name[32]; } s_players[MAX_PLAYERS];   /* via: host's link to its owner */
static int    s_nplayers;
static u32    s_next_id = 0x1001;
static u32    s_my_id;
static u32    s_reply_id;
static struct { u32 from, to, len; unsigned char data[256]; } s_inbox[INBOX];
static int    s_in_head, s_in_tail;
static int    s_clients[MAX_PLAYERS];
static unsigned s_stat_in, s_stat_drop, s_stat_out, s_stat_got;

static void lock(void)   { pthread_mutex_lock(&s_lock); }
static void unlock(void) { pthread_mutex_unlock(&s_lock); }

/* A blocking wait that gives the machine up, so the game's thread is not
 * held while the host answers. */
static int reply_wait(unsigned ms) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += (time_t)ms / 1000u;
    ts.tv_nsec += (long)(ms % 1000u) * 1000000L;
    if (ts.tv_nsec >= 1000000000L) { ts.tv_sec++; ts.tv_nsec -= 1000000000L; }
    pthread_mutex_lock(&s_reply_lock);
    s_reply_set = 0;
    hle_block_begin();
    while (!s_reply_set) {
        int rc = pthread_cond_timedwait(&s_reply_cond, &s_reply_lock, &ts);
        if (rc == ETIMEDOUT) break;
        if (rc && rc != EINTR) break;
    }
    hle_block_end();
    pthread_mutex_unlock(&s_reply_lock);
    return s_reply_set;
}
static void reply_signal(void) {
    pthread_mutex_lock(&s_reply_lock);
    s_reply_set = 1;
    pthread_cond_broadcast(&s_reply_cond);
    pthread_mutex_unlock(&s_reply_lock);
}

static void inbox_push(u32 from, u32 to, const void *data, u32 len) {
    int next;
    if (len > 256) len = 256;
    lock();
    next = (s_in_tail + 1) % INBOX;
    if (next != s_in_head) {
        s_inbox[s_in_tail].from = from; s_inbox[s_in_tail].to = to; s_inbox[s_in_tail].len = len;
        memcpy(s_inbox[s_in_tail].data, data, len);
        s_in_tail = next;
        s_stat_in++;
    } else s_stat_drop++;
    unlock();
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
        if (s_clients[i] != DP_BAD) put(s_clients[i], M_PLAYERS, (u32)s_nplayers, 0, ids, 4u * s_nplayers);
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
    if (local_player(to)) { inbox_push(from, to, data, len); return; }
    for (i = 0; i < s_nplayers; i++)
        if (s_players[i].id == to && s_players[i].via != DP_BAD) {
            put(s_players[i].via, M_DATA, from, to, data, len);
            return;
        }
}

/* Host: one client connection. */
static void *host_client_thread(void *arg) {
    int c = (int)(intptr_t)arg;
    msg_t *mm = malloc(sizeof *mm);
    int slot = -1, i;
    lock();
    for (i = 0; i < MAX_PLAYERS; i++) if (s_clients[i] == DP_BAD) { s_clients[i] = c; slot = i; break; }
    unlock();
    while (mm && slot >= 0 && get(c, mm)) {
        lock();
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
                snprintf(s_players[s_nplayers].name, sizeof s_players[0].name, "%s", (const char *)mm->data);
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
        unlock();
    }
    lock();
    for (i = 0; i < s_nplayers; )                    /* its players leave with it */
        if (s_players[i].via == c) remove_player(s_players[i].id); else i++;
    if (slot >= 0) s_clients[slot] = DP_BAD;
    broadcast_players();
    unlock();
    close(c);
    free(mm);
    return NULL;
}

static void *host_listen_thread(void *arg) {
    (void)arg;
    for (;;) {
        int c = accept(s_listen, NULL, NULL);
        if (c < 0) return NULL;
        { int one = 1; setsockopt(c, IPPROTO_TCP, TCP_NODELAY, &one, sizeof one); }
        fprintf(stderr, "[dplay] host: a client connected\n");
        pthread_t t;
        if (pthread_create(&t, NULL, host_client_thread, (void *)(intptr_t)c) == 0) pthread_detach(t);
        else host_client_thread((void *)(intptr_t)c);
    }
}

/* Client: everything from the host. */
static void *client_thread(void *arg) {
    msg_t *m = malloc(sizeof *m);
    int i;
    (void)arg;
    while (m && get(s_link, m)) {
        switch (m->type) {
        case M_SESSION:
            lock();
            snprintf(s_session, sizeof s_session, "%s", (const char *)m->data);
            s_nplayers = (int)m->b;
            unlock();
            reply_signal();
            break;
        case M_YOURID:
            s_reply_id = m->a;
            reply_signal();
            break;
        case M_PLAYERS:
            lock();
            s_nplayers = (int)(m->a > MAX_PLAYERS ? MAX_PLAYERS : m->a);
            for (i = 0; i < s_nplayers; i++) {
                s_players[i].id = ((u32 *)m->data)[i];
                s_players[i].via = DP_BAD;
            }
            unlock();
            fprintf(stderr, "[dplay] client: %d players\n", s_nplayers);
            break;
        case M_DATA:
            inbox_push(m->a, m->b, m->data, m->len);
            break;
        }
    }
    fprintf(stderr, "[dplay] client: the host is gone\n");
    lock();
    s_nplayers = 0;
    unlock();
    free(m);
    return NULL;
}

/* Client: a connection to the host, if there is none. */
static int connect_host(void) {
    char host[128], *colon;
    int port = g_dp_port;
    struct addrinfo hints = {0}, *ai = NULL;
    char ports[16];
    if (s_link != DP_BAD) return 1;
    snprintf(host, sizeof host, "%s", g_dp_join);
    colon = strrchr(host, ':');
    if (colon) { *colon = 0; port = atoi(colon + 1); }
    sprintf(ports, "%d", port);
    hints.ai_family = AF_INET; hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, ports, &hints, &ai) || !ai) return 0;
    s_link = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connect(s_link, ai->ai_addr, (socklen_t)ai->ai_addrlen)) {
        close(s_link); s_link = DP_BAD; freeaddrinfo(ai);
        return 0;
    }
    freeaddrinfo(ai);
    { int one = 1; setsockopt(s_link, IPPROTO_TCP, TCP_NODELAY, &one, sizeof one); }
    fprintf(stderr, "[dplay] client: connected to %s:%d\n", host, port);
    pthread_t t;
    if (pthread_create(&t, NULL, client_thread, NULL) == 0) pthread_detach(t);
    else client_thread(NULL);
    return 1;
}

static int host_start(const char *name) {
    struct sockaddr_in a;
    int one = 1;
    memset(&a, 0, sizeof a);
    snprintf(s_session, sizeof s_session, "%s", name && *name ? name : "GTA");
    s_listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    setsockopt(s_listen, SOL_SOCKET, SO_REUSEADDR, &one, sizeof one);
    a.sin_family = AF_INET; a.sin_port = htons((uint16_t)g_dp_port); a.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(s_listen, (struct sockaddr *)&a, sizeof a) || listen(s_listen, 4)) {
        fprintf(stderr, "[dplay] host: cannot listen on port %d (%s)\n", g_dp_port, strerror(errno));
        close(s_listen); s_listen = DP_BAD;
        return 0;
    }
    s_is_host = 1;
    pthread_t t;
    if (pthread_create(&t, NULL, host_listen_thread, NULL) == 0) pthread_detach(t);
    fprintf(stderr, "[dplay] host: session '%s' on port %d\n", s_session, g_dp_port);
    return 1;
}

/* ------------------------------------------------------------ methods ---- */

static u32 enum_sessions(u32 cb, u32 ctx) {
    static u32 desc, name, timeout;
    u32 args[4];
    if (!desc) { desc = (u32)(uintptr_t)hle_alloc(0x50); name = (u32)(uintptr_t)hle_alloc(64); timeout = (u32)(uintptr_t)hle_alloc(4); }
    if (!s_is_host && connect_host()) {
        if (reply_wait(2000)) {
            int i;
            for (i = 0; i < 0x50; i += 4) MEM32(desc + i) = 0;
            MEM32(desc + 0x00) = 0x50;
            MEM32(desc + 0x08) = 0x47544131;               /* guidInstance: the one session */
            MEM32(desc + 0x28) = MAX_PLAYERS;
            MEM32(desc + 0x2C) = (u32)s_nplayers;
            lock();
            for (i = 0; i < 63 && s_session[i]; i++) MEM8(name + i) = (u8)s_session[i];
            unlock();
            MEM8(name + i) = 0;
            MEM32(desc + 0x30) = name;
            MEM32(timeout) = 0;
            fprintf(stderr, "[dplay] client: found session '%s'\n", s_session);
            args[0] = desc; args[1] = timeout; args[2] = 0; args[3] = ctx;
            hle_call_guest(cb, 4, args);
        }
    }
    MEM32(timeout) = 0;
    args[0] = 0; args[1] = timeout; args[2] = DPESC_TIMEDOUT; args[3] = ctx;
    hle_call_guest(cb, 4, args);
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
        lock();
        if (s_nplayers >= MAX_PLAYERS) { unlock(); return DPERR_GENERIC; }
        s_my_id = s_next_id++;
        s_players[s_nplayers].id = s_my_id;
        s_players[s_nplayers].via = DP_BAD;
        snprintf(s_players[s_nplayers].name, sizeof s_players[0].name, "%s", name);
        s_nplayers++;
        broadcast_players();
        unlock();
    } else {
        if (s_link == DP_BAD) return DPERR_GENERIC;
        s_reply_id = 0;
        if (!put(s_link, M_CREATE, 0, 0, name, (u32)strlen(name) + 1)) return DPERR_GENERIC;
        if (!reply_wait(5000) || !s_reply_id) return DPERR_GENERIC;
        s_my_id = s_reply_id;
        {   /* the player list follows its id */
            struct timespec ts = { 0, 50 * 1000000L };
            hle_block_begin();
            nanosleep(&ts, NULL);
            hle_block_end();
        }
    }
    fprintf(stderr, "[dplay] our player is 0x%X ('%s')\n", s_my_id, name);
    if (pid_out) MEM32(pid_out) = s_my_id;
    return DP_OK;
}

static u32 enum_players(u32 cb, u32 ctx) {
    static u32 dpname;
    u32 ids[MAX_PLAYERS], args[5];
    int n, i;
    if (!dpname) { dpname = (u32)(uintptr_t)hle_alloc(16); MEM32(dpname) = 16; }
    lock();
    n = s_nplayers;
    for (i = 0; i < n; i++) ids[i] = s_players[i].id;
    unlock();
    for (i = 0; i < n; i++) {
        args[0] = ids[i]; args[1] = 0 /* DPPLAYERTYPE_PLAYER */; args[2] = dpname; args[3] = 0; args[4] = ctx;
        if (!hle_call_guest(cb, 5, args)) break;
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
        lock();
        if (to == 0) {                                 /* DPID_ALLPLAYERS */
            int k;
            for (k = 0; k < s_nplayers; k++)
                if (s_players[k].id != from) route(from, s_players[k].id, buf, size);
        } else route(from, to, buf, size);
        unlock();
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
    static uint32_t last;
    uint32_t now = hle_ticks_ms();
    if (now - last > 5000) {   /* every 5 s: traffic, for the test logs */
        last = now;
        fprintf(stderr, "[dplay] stats: in %u got %u out %u dropped %u queued %d\n", s_stat_in, s_stat_got,
                s_stat_out, s_stat_drop, (s_in_tail - s_in_head + INBOX) % INBOX);
    }
    lock();
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
    unlock();
    return r;
}

static void dp_close(void) {
    if (!s_open) return;
    s_open = 0;
    if (s_is_host) {
        int i;
        lock();
        for (i = 0; i < MAX_PLAYERS; i++)
            if (s_clients[i] != DP_BAD) shutdown(s_clients[i], SHUT_RDWR);
        unlock();
        if (s_listen != DP_BAD) { close(s_listen); s_listen = DP_BAD; }
    } else if (s_link != DP_BAD) {
        shutdown(s_link, SHUT_RDWR);
        close(s_link);
        s_link = DP_BAD;
    }
    lock();
    s_nplayers = 0; s_my_id = 0; s_is_host = 0;
    s_in_head = s_in_tail = 0;
    unlock();
    fprintf(stderr, "[dplay] closed\n");
}

/* ------------------------------------------------------------ COM -------- */

/* IDirectDraw2A's 32 vtable slots, in order; win32hle numbers them by the
 * table's. The ten the game uses are real; the rest answer DP_OK, as the
 * Windows host's dispatch answers them, with the arity each must pop.
 * src/net/dplay.c k_argc. */
static void dp_QueryInterface(void) {                     /* (this, iid, &out): we are IDirectPlay2A */
    if (A32(2)) MEM32(A32(2)) = A32(0);
    RET(0, 3);
}
static void dp_AddRef(void) { MEM32(A32(0) + 4)++; RET(1, 1); }
static void dp_Release(void) { uint32_t n = MEM32(A32(0) + 4) ? --MEM32(A32(0) + 4) : 0; RET(n, 1); }
static void dp_arity2(void) { RET(DP_OK, 2); }
static void dp_arity3(void) { RET(DP_OK, 3); }
static void dp_arity4(void) { RET(DP_OK, 4); }
static void dp_arity5(void) { RET(DP_OK, 5); }
static void dp_arity6(void) { RET(DP_OK, 6); }
static void dp_arity7(void) { RET(DP_OK, 7); }

static void dp_Close(void) { dp_close(); RET(DP_OK, 1); }

static void dp_CreatePlayer(void) {                      /* (this, lpid, name, ev, data, size, flags) */
    RET(create_player(A32(1), A32(2)), 7);
}

static void dp_DestroyPlayer(void) {                      /* (this, id) */
    if (s_is_host) { lock(); remove_player(A32(1)); broadcast_players(); unlock(); }
    else put(s_link, M_DESTROY, A32(1), 0, NULL, 0);
    if (A32(1) == s_my_id) s_my_id = 0;
    RET(DP_OK, 2);
}

static void dp_EnumPlayers(void) {                       /* (this, guid, cb, ctx, flags) */
    RET(enum_players(A32(2), A32(3)), 5);
}

static void dp_EnumSessions(void) {                      /* (this, sd, timeout, cb, ctx, flags) */
    RET(enum_sessions(A32(3), A32(4)), 6);
}

static void dp_Open(void) {                             /* (this, sd, flags) */
    u32 r = DP_OK;
    if (A32(2) & DPOPEN_CREATE) {
        char name[64] = "";
        u32 p = MEM32(A32(1) + 0x30);
        int i;
        for (i = 0; p && i < 63 && MEM8(p + i); i++) name[i] = (char)MEM8(p + i);
        name[i] = 0;
        r = host_start(name) ? DP_OK : DPERR_GENERIC;
    } else {
        r = connect_host() ? DP_OK : DPERR_NOSESSIONS;
        if (r == DP_OK) put(s_link, M_JOIN, 0, 0, NULL, 0);
    }
    if (r == DP_OK) s_open = 1;
    RET(r, 3);
}

static void dp_Receive(void) {                           /* (this, from, to, flags, data, size) */
    RET(dp_receive(A32(1), A32(2), A32(4), A32(5)), 6);
}

static void dp_Send(void) {                             /* (this, from, to, flags, data, size) */
    RET(dp_send(A32(1), A32(2), A32(4), A32(5)), 6);
}

/* The slots in IDirectPlay2A's order (src/net/dplay.c k_name); each pops
 * what the real one pops, so the game's stack stays true even on the ones
 * it never calls. */
static const win32hle_shim g_dp_vtable[] = {
    { "IDirectPlay2A::QueryInterface",     dp_QueryInterface },
    { "IDirectPlay2A::AddRef",             dp_AddRef },
    { "IDirectPlay2A::Release",            dp_Release },
    { "IDirectPlay2A::AddPlayerToGroup",   dp_arity3 },
    { "IDirectPlay2A::Close",              dp_Close },
    { "IDirectPlay2A::CreateGroup",        dp_arity6 },
    { "IDirectPlay2A::CreatePlayer",       dp_CreatePlayer },
    { "IDirectPlay2A::DeletePlayerFromGroup", dp_arity3 },
    { "IDirectPlay2A::DestroyGroup",       dp_arity2 },
    { "IDirectPlay2A::DestroyPlayer",      dp_DestroyPlayer },
    { "IDirectPlay2A::EnumGroupPlayers",   dp_arity6 },
    { "IDirectPlay2A::EnumGroups",         dp_arity5 },
    { "IDirectPlay2A::EnumPlayers",        dp_EnumPlayers },
    { "IDirectPlay2A::EnumSessions",       dp_EnumSessions },
    { "IDirectPlay2A::GetCaps",             dp_arity3 },
    { "IDirectPlay2A::GetGroupData",       dp_arity5 },
    { "IDirectPlay2A::GetGroupName",       dp_arity4 },
    { "IDirectPlay2A::GetMessageCount",    dp_arity4 },
    { "IDirectPlay2A::GetPlayerAddress",   dp_arity4 },
    { "IDirectPlay2A::GetPlayerCaps",      dp_arity4 },
    { "IDirectPlay2A::GetPlayerData",      dp_arity5 },
    { "IDirectPlay2A::GetPlayerName",      dp_arity4 },
    { "IDirectPlay2A::GetSessionDesc",     dp_arity3 },
    { "IDirectPlay2A::Initialize",         dp_arity2 },
    { "IDirectPlay2A::Open",               dp_Open },
    { "IDirectPlay2A::Receive",            dp_Receive },
    { "IDirectPlay2A::Send",               dp_Send },
    { "IDirectPlay2A::SetGroupData",       dp_arity5 },
    { "IDirectPlay2A::SetGroupName",       dp_arity4 },
    { "IDirectPlay2A::SetPlayerData",      dp_arity5 },
    { "IDirectPlay2A::SetPlayerName",      dp_arity4 },
    { "IDirectPlay2A::SetSessionDesc",     dp_arity3 },
    { 0, 0 }
};

/* DirectPlayCreate(lpGUID, lplpDP, pUnk) -- ordinal 1. */
static void x_DirectPlayCreate(void) {
    static u32 s_object;
    if (!s_object) {
        uint32_t vt = hle_com_vtable(g_dp_vtable);
        s_object = hle_com_new(vt, 8);
    }
    if (A32(1)) MEM32(A32(1)) = s_object;
    RET(DP_OK, 3);
}

/* DirectPlayEnumerateA(cb, ctx) -- ordinal 2.
 *
 * Enumerating is not optional, even for a single-player game. GTA1's front end
 * counts the service providers the callback reports, and the count gates
 * everything downstream: with none, state 0 never routed to state 15 or 16,
 * so states 5 and 3 -- the two that promote the audio mode -- were
 * unreachable, and the play state span forever. One provider is reported. */
static void x_DirectPlayEnumerateA(void) {
    static u32 guid_va, name_va;
    u32 cb = A32(0), ctx = A32(1), args[5];
    if (!guid_va) {
        static const unsigned char guid[16] = {   /* ours; the game only stores and compares it */
            0x36,0x3B,0x58,0x5A,0x3B,0xE1,0x11,0xD0,0x9C,0x0B,0x00,0xA0,0xC9,0x06,0x28,0x02 };
        void *g = hle_alloc(16);
        memcpy(g, guid, 16);
        guid_va = (u32)(uintptr_t)g;
        name_va = hle_guest_strdup("Internet TCP/IP Connection");
    }
    args[0] = guid_va; args[1] = name_va; args[2] = 9; args[3] = 0; args[4] = ctx;
    if (cb) hle_call_guest(cb, 5, args);
    RET(DP_OK, 2);
}

const win32hle_shim gta_net_shims[] = {
    { "dplayx.dll#1", x_DirectPlayCreate },
    { "dplayx.dll#2", x_DirectPlayEnumerateA },
    { 0, 0 }
};
