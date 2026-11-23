/* dplay.c: GTA1's DirectPlay (IDirectPlay2A over TCP). */
#ifndef GTA_DPLAY_H
#define GTA_DPLAY_H
extern char g_dp_join[128];   /* --join ADDR[:PORT]: where the host is */
extern int  g_dp_port;        /* --port: where the host listens (2350) */
void dplay_bridge_create(void);      /* DPLAYX ordinal 1 */
void dplay_bridge_enumerate(void);   /* DPLAYX ordinal 2 */
/* coop.c */
extern int g_coop;                          /* --coop */
const char *coop_redirect(const char *path);
#endif
