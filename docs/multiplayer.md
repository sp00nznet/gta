# Network play

GTA1's own network game -- up to four, deathmatch, through DirectPlay --
between recompiled copies, on one machine or over a LAN.

```
gta1.exe "Grand Theft Auto.exe"                          # the host: Gather Network
gta1.exe "Grand Theft Auto.exe" --join 192.168.1.20      # a joiner: Join Network
```

The host listens on TCP port 2350 (`--port`, or `[net] port=` in `gta1.ini`);
a joiner finds it at `--join ADDR[:PORT]` (`[net] join=`, default
`127.0.0.1`). Allow `gta1.exe` through the firewall on the host for a LAN game.

In the game, as it shipped:

1. Host: **Gather Network**, a character, a city, *Multiplayer Options*
   (end on a score or a time), the connection (*Internet TCP/IP Connection*),
   a session name. The gather screen counts the joiners: Enter starts.
2. Joiner: **Join Network**, a character, the connection, the session.

## What the game asks of DirectPlay

Its network layer is small (0x486880-0x487620) and uses ten methods of
DirectPlay 5's `IDirectPlay2A`, which it gets by `QueryInterface` from a
`DirectPlayCreate` on the first service provider:

| | |
|---|---|
| host | `Open(DPOPEN_CREATE)` with the session name and four players, `CreatePlayer` |
| joiner | `EnumSessions` (synchronous; its callback stops at `DPESC_TIMEDOUT`), `Open(DPOPEN_JOIN)`, `CreatePlayer` |
| both | `EnumPlayers`, polled; the ids **sorted** are the player numbers |
| play | `Send` to each other player in turn, `Receive(DPRECEIVE_ALL)` into 256 bytes; anything not addressed to its own player -- system messages included -- is ignored |
| end | `DestroyPlayer`, `Close`, `Release` |

The game's own protocol runs on top: a startup handshake (`sub_0044BD70`,
message types 2-4, carrying each player's name and the host's mission number)
and then the frames, in lock-step.

## How it is done here

`src/net/dplay.c` is that `IDirectPlay2A`, on the same bridge-cookie vtables as
the DirectDraw shim, over TCP. It is a star: the host listens, each joiner keeps
one connection to it, and the host routes every `Send`. The host hands out
player ids in join order (0x1001 is the host), so the sorted order -- the
player numbers -- is the same on every copy. Messages are length-prefixed
records; real DirectPlay's wire format does not matter, since both ends are
this file.

Two copies on one machine also needed the game's single-instance mutex
(`Grand Theft Auto`) made per process; the second copy used to see the first
and quit.

## Testing it

`tools/net_pair.sh` runs a host and a joiner, each on its own hidden desktop,
muted, driven by scripted keys (`GTA_KEYS`, gated on the front end's state),
and keeps their logs and frames in `work/net/`. With `CARGS="--join <LAN IP>"`
the joiner connects through the LAN interface rather than loopback.

```
== host
[dplay] Open
[dplay] host: session 'GTA Game' on port 2350
[dplay] our player is 0x1001 ('Katie')
[dplay] host: a client connected
[dplay] host: player 0x1002 joined (2 now)
== cli
[dplay] client: connected to 192.168.100.129:2350
[dplay] client: found session 'GTA Game'
[dplay] Open
[dplay] client: 2 players
[dplay] our player is 0x1002 ('Katie')
```

Both then load the deathmatch level, each player at its own spawn point, and
play: the frames in `docs/screenshots/` are each copy's own surface.

Not done: four players at once (the code allows it; tested with two), and play
across the internet (no NAT traversal; a forwarded port 2350 would do).
