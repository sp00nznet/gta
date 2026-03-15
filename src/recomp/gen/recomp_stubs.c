/*
 * Stub implementations for functions not found during discovery.
 *
 * These functions exist in the original binary but were not reached
 * by our E8 call scan. They may be called only via indirect dispatch,
 * or the call target analysis may have missed them.
 *
 * TODO: Add these addresses to the discovery seed list and re-lift.
 */

#include "../../engine/recomp_runtime.h"
#include <stdio.h>

void sub_00417B70(void) { fprintf(stderr, "STUB: sub_00417B70 called\n"); }
void sub_0041ADB0(void) { fprintf(stderr, "STUB: sub_0041ADB0 called\n"); }
void sub_0042E0E0(void) { fprintf(stderr, "STUB: sub_0042E0E0 called\n"); }
void sub_0042E180(void) { fprintf(stderr, "STUB: sub_0042E180 called\n"); }
void sub_0042E220(void) { fprintf(stderr, "STUB: sub_0042E220 called\n"); }
void sub_00472980(void) { fprintf(stderr, "STUB: sub_00472980 called\n"); }
void sub_00474A20(void) { fprintf(stderr, "STUB: sub_00474A20 called\n"); }
void sub_E942E951(void) { fprintf(stderr, "STUB: sub_E942E951 called (bogus address)\n"); }
