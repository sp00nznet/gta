/* Auto-generated -- London 1969 functions 2000-2136 */
/* 0x004DA5E2 - 0x004EDBC1 */

#define RECOMP_GENERATED_CODE
#include "../../engine/recomp_runtime.h"
#include <math.h>
#include <string.h>

void sub_004DA5E2(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DA5E2:
    MEM8(eax) = (uint8_t)(MEM8(eax) | LO8(eax)); /* 0x004DA5E2: or byte ptr [eax], al */
    if (/* or result */ TEST_Z(MEM8(eax), LO8(eax))) goto L_004DA5EE; /* 0x004DA5E4: je 0x4da5ee */

L_004DA5E6:
    eax = MEM32(ebp + 0x8); /* 0x004DA5E6: mov eax, dword ptr [ebp + 8] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DA5E9: mov dword ptr [ebp - 8], eax */
    goto L_004DA5F5; /* 0x004DA5EC: jmp 0x4da5f5 */

L_004DA5EE:
    MEM32(ebp + (-0x8)) = 1; /* 0x004DA5EE: mov dword ptr [ebp - 8], 1 */

L_004DA5F5:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DA5F5: mov ecx, dword ptr [ebp - 8] */
    MEM32(ebp + 0x8) = ecx; /* 0x004DA5F8: mov dword ptr [ebp + 8], ecx */

L_004DA5FB:
    /* cmp MEM32(ebp + 0x8), 0xFFFFFFE0u */ /* 0x004DA5FB: cmp dword ptr [ebp + 8], -0x20 */
    if (CMP_A(MEM32(ebp + 0x8), 0xFFFFFFE0u)) goto L_004DA612; /* 0x004DA5FF: ja 0x4da612 */

L_004DA601:
    edx = MEM32(ebp + 0x8); /* 0x004DA601: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004DA604: push edx */
    RECOMP_CALL(sub_004DA650); /* 0x004DA605: call 0x4da650 */
    esp = esp + 4; /* 0x004DA60A: add esp, 4 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DA60D: mov dword ptr [ebp - 4], eax */
    goto L_004DA619; /* 0x004DA610: jmp 0x4da619 */

L_004DA612:
    MEM32(ebp + (-0x4)) = 0; /* 0x004DA612: mov dword ptr [ebp - 4], 0 */

L_004DA619:
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DA619: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004DA625; /* 0x004DA61D: jne 0x4da625 */

L_004DA61F:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004DA61F: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_NE(MEM32(ebp + 0xC), 0)) goto L_004DA62A; /* 0x004DA623: jne 0x4da62a */

L_004DA625:
    eax = MEM32(ebp + (-0x4)); /* 0x004DA625: mov eax, dword ptr [ebp - 4] */
    goto L_004DA640; /* 0x004DA628: jmp 0x4da640 */

L_004DA62A:
    eax = MEM32(ebp + 0x8); /* 0x004DA62A: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004DA62D: push eax */
    RECOMP_CALL(sub_004D4CD0); /* 0x004DA62E: call 0x4d4cd0 */
    esp = esp + 4; /* 0x004DA633: add esp, 4 */
    /* test eax, eax */ /* 0x004DA636: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004DA63E; /* 0x004DA638: jne 0x4da63e */

L_004DA63A:
    eax = 0; /* 0x004DA63A: xor eax, eax */
    goto L_004DA640; /* 0x004DA63C: jmp 0x4da640 */

L_004DA63E:
    goto L_004DA5FB; /* 0x004DA63E: jmp 0x4da5fb */

L_004DA640:
    esp = ebp; /* 0x004DA640: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DA642: pop ebp */
    return; /* 0x004DA643: ret  */

}

void sub_004DA760(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DA760:
    RECOMP_CALL(sub_004DA5B0); /* 0x004DA760: call 0x4da5b0 */
    esp = esp + 4; /* 0x004DA765: add esp, 4 */
    goto L_004DA927; /* 0x004DA768: jmp 0x4da927 */

L_004DA927:
    esp = ebp; /* 0x004DA927: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DA929: pop ebp */
    return; /* 0x004DA92A: ret  */

}

void sub_004DAA10(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DAA10:
    /* test MEM32(eax), eax */ /* 0x004DAA10: test dword ptr [eax], eax */
    MEM32(0x855DA0) = eax; /* 0x004DAA12: mov dword ptr [0x855da0], eax */
    /* cmp MEM32(0x855DA0), 0 */ /* 0x004DAA17: cmp dword ptr [0x855da0], 0 */
    if (CMP_NE(MEM32(0x855DA0), 0)) goto L_004DAA24; /* 0x004DAA1E: jne 0x4daa24 */

L_004DAA20:
    eax = 0; /* 0x004DAA20: xor eax, eax */
    goto L_004DAA42; /* 0x004DAA22: jmp 0x4daa42 */

L_004DAA24:
    RECOMP_CALL(sub_004DAAE0); /* 0x004DAA24: call 0x4daae0 */
    /* test eax, eax */ /* 0x004DAA29: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004DAA3D; /* 0x004DAA2B: jne 0x4daa3d */

L_004DAA2D:
    eax = MEM32(0x855DA0); /* 0x004DAA2D: mov eax, dword ptr [0x855da0] */
    PUSH32(esp, eax); /* 0x004DAA32: push eax */
    RECOMP_ICALL(MEM32(0x858690)); /* 0x004DAA33: call dword ptr [0x858690] */
    eax = 0; /* 0x004DAA39: xor eax, eax */
    goto L_004DAA42; /* 0x004DAA3B: jmp 0x4daa42 */

L_004DAA3D:
    eax = 1; /* 0x004DAA3D: mov eax, 1 */

L_004DAA42:
    ebp = POP32_VAL(esp); /* 0x004DAA42: pop ebp */
    return; /* 0x004DAA43: ret  */

}

void sub_004DAB80(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DAB80:
    eax = eax + 0x0050964Cu; /* 0x004DAB80: add eax, 0x50964c */
    eax = eax - 1; /* 0x004DAB85: dec eax */
    { uint32_t _tmp = esi; /* 0x004DAB86: xchg esi, eax */
      esi = eax;
      eax = _tmp; }
    PUSH32(esp, eax); /* 0x004DAB87: push eax */
    SET_LO8(ebx, LO8(ebx) + HI8(ecx)); /* 0x004DAB88: add bl, ch */
    MEM32(ebx + 0x2C7F455) = MEM32(ebx + 0x2C7F455) - ecx; /* 0x004DAB8A: sub dword ptr [ebx + 0x2c7f455], ecx */
    eax = eax - 1; /* 0x004DAB90: dec eax */
    { uint32_t _tmp = esi; /* 0x004DAB91: xchg esi, eax */
      esi = eax;
      eax = _tmp; }
    PUSH32(esp, eax); /* 0x004DAB92: push eax */
    MEM8(ebx + 0xD8BF445) = (uint8_t)(MEM8(ebx + 0xD8BF445) + LO8(ecx)); /* 0x004DAB93: add byte ptr [ebx + 0xd8bf445], cl */
    esp = esp - 1; /* 0x004DAB99: dec esp */
    { uint32_t _tmp = esi; /* 0x004DAB9A: xchg esi, eax */
      esi = eax;
      eax = _tmp; }
    PUSH32(esp, eax); /* 0x004DAB9B: push eax */
    MEM8(ecx + 0x558B0448) = (uint8_t)(MEM8(ecx + 0x558B0448) + LO8(ecx)); /* 0x004DAB9C: add byte ptr [ecx + 0x558b0448], cl */
    /* UNIMPLEMENTED: hlt  */ /* 0x004DABA2: hlt  */
    MEM32(0x50964C) = edx; /* 0x004DABA3: mov dword ptr [0x50964c], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004DABA9: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(eax + 0x4); /* 0x004DABAC: mov ecx, dword ptr [eax + 4] */
    edx = MEM32(ebp + (-0xC)); /* 0x004DABAF: mov edx, dword ptr [ebp - 0xc] */
    MEM32(ecx) = edx; /* 0x004DABB2: mov dword ptr [ecx], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004DABB4: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DABB7: mov ecx, dword ptr [ebp - 4] */
    MEM32(eax + 0x10) = ecx; /* 0x004DABBA: mov dword ptr [eax + 0x10], ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004DABBD: mov edx, dword ptr [ebp - 4] */
    edx = edx + 0x00400000u; /* 0x004DABC0: add edx, 0x400000 */
    eax = MEM32(ebp + (-0xC)); /* 0x004DABC6: mov eax, dword ptr [ebp - 0xc] */
    MEM32(eax + 0x14) = edx; /* 0x004DABC9: mov dword ptr [eax + 0x14], edx */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DABCC: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + 0x18u; /* 0x004DABCF: add ecx, 0x18 */
    edx = MEM32(ebp + (-0xC)); /* 0x004DABD2: mov edx, dword ptr [ebp - 0xc] */
    MEM32(edx + 0x8) = ecx; /* 0x004DABD5: mov dword ptr [edx + 8], ecx */
    eax = MEM32(ebp + (-0xC)); /* 0x004DABD8: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 0x98u; /* 0x004DABDB: add eax, 0x98 */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DABE0: mov ecx, dword ptr [ebp - 0xc] */
    MEM32(ecx + 0xC) = eax; /* 0x004DABE3: mov dword ptr [ecx + 0xc], eax */
    MEM32(ebp + (-0x8)) = 0; /* 0x004DABE6: mov dword ptr [ebp - 8], 0 */
    goto L_004DABF8; /* 0x004DABED: jmp 0x4dabf8 */

L_004DABEF:
    edx = MEM32(ebp + (-0x8)); /* 0x004DABEF: mov edx, dword ptr [ebp - 8] */
    edx = edx + 1; /* 0x004DABF2: add edx, 1 */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DABF5: mov dword ptr [ebp - 8], edx */

L_004DABF8:
    /* cmp MEM32(ebp + (-0x8)), 0x400u */ /* 0x004DABF8: cmp dword ptr [ebp - 8], 0x400 */
    if (CMP_GE(MEM32(ebp + (-0x8)), 0x400u)) goto L_004DAC35; /* 0x004DABFF: jge 0x4dac35 */

L_004DAC01:
    /* cmp MEM32(ebp + (-0x8)), 0x10u */ /* 0x004DAC01: cmp dword ptr [ebp - 8], 0x10 */
    if (CMP_GE(MEM32(ebp + (-0x8)), 0x10u)) goto L_004DAC17; /* 0x004DAC05: jge 0x4dac17 */

L_004DAC07:
    eax = MEM32(ebp + (-0x8)); /* 0x004DAC07: mov eax, dword ptr [ebp - 8] */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DAC0A: mov ecx, dword ptr [ebp - 0xc] */
    MEM32(ecx + eax * 8 + 0x18) = 0xF0u; /* 0x004DAC0D: mov dword ptr [ecx + eax*8 + 0x18], 0xf0 */
    goto L_004DAC25; /* 0x004DAC15: jmp 0x4dac25 */

L_004DAC17:
    edx = MEM32(ebp + (-0x8)); /* 0x004DAC17: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(ebp + (-0xC)); /* 0x004DAC1A: mov eax, dword ptr [ebp - 0xc] */
    MEM32(eax + edx * 8 + 0x18) = 0xFFFFFFFFu; /* 0x004DAC1D: mov dword ptr [eax + edx*8 + 0x18], 0xffffffff */

L_004DAC25:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DAC25: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ebp + (-0xC)); /* 0x004DAC28: mov edx, dword ptr [ebp - 0xc] */
    MEM32(edx + ecx * 8 + 0x1C) = 0xF1u; /* 0x004DAC2B: mov dword ptr [edx + ecx*8 + 0x1c], 0xf1 */
    goto L_004DABEF; /* 0x004DAC33: jmp 0x4dabef */

L_004DAC35:
    PUSH32(esp, 0x00010000u); /* 0x004DAC35: push 0x10000 */
    PUSH32(esp, 0); /* 0x004DAC3A: push 0 */
    eax = MEM32(ebp + (-0x4)); /* 0x004DAC3C: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004DAC3F: push eax */
    RECOMP_CALL(sub_004DA550); /* 0x004DAC40: call 0x4da550 */
    esp = esp + 0xCu; /* 0x004DAC45: add esp, 0xc */

L_004DAC48:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DAC48: mov ecx, dword ptr [ebp - 0xc] */
    edx = MEM32(ecx + 0x10); /* 0x004DAC4B: mov edx, dword ptr [ecx + 0x10] */
    edx = edx + 0x00010000u; /* 0x004DAC4E: add edx, 0x10000 */
    /* cmp MEM32(ebp + (-0x4)), edx */ /* 0x004DAC54: cmp dword ptr [ebp - 4], edx */
    if (CMP_AE(MEM32(ebp + (-0x4)), edx)) goto L_004DAC86; /* 0x004DAC57: jae 0x4dac86 */

L_004DAC59:
    eax = MEM32(ebp + (-0x4)); /* 0x004DAC59: mov eax, dword ptr [ebp - 4] */
    eax = eax + 8; /* 0x004DAC5C: add eax, 8 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DAC5F: mov ecx, dword ptr [ebp - 4] */
    MEM32(ecx) = eax; /* 0x004DAC62: mov dword ptr [ecx], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004DAC64: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0x4) = 0xF0u; /* 0x004DAC67: mov dword ptr [edx + 4], 0xf0 */
    eax = MEM32(ebp + (-0x4)); /* 0x004DAC6E: mov eax, dword ptr [ebp - 4] */
    MEM8(eax + 0xF8) = (uint8_t)(0xFFu); /* 0x004DAC71: mov byte ptr [eax + 0xf8], 0xff */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DAC78: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 0x1000u; /* 0x004DAC7B: add ecx, 0x1000 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DAC81: mov dword ptr [ebp - 4], ecx */
    goto L_004DAC48; /* 0x004DAC84: jmp 0x4dac48 */

L_004DAC86:
    eax = MEM32(ebp + (-0xC)); /* 0x004DAC86: mov eax, dword ptr [ebp - 0xc] */
    goto L_004DACBA; /* 0x004DAC89: jmp 0x4dacba */

L_004DACBA:
    esp = ebp; /* 0x004DACBA: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DACBC: pop ebp */
    return; /* 0x004DACBD: ret  */

}

void sub_004DAC73(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DAC48:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DAC48: mov ecx, dword ptr [ebp - 0xc] */
    edx = MEM32(ecx + 0x10); /* 0x004DAC4B: mov edx, dword ptr [ecx + 0x10] */
    edx = edx + 0x00010000u; /* 0x004DAC4E: add edx, 0x10000 */
    /* cmp MEM32(ebp + (-0x4)), edx */ /* 0x004DAC54: cmp dword ptr [ebp - 4], edx */
    if (CMP_AE(MEM32(ebp + (-0x4)), edx)) goto L_004DAC86; /* 0x004DAC57: jae 0x4dac86 */

L_004DAC59:
    eax = MEM32(ebp + (-0x4)); /* 0x004DAC59: mov eax, dword ptr [ebp - 4] */
    eax = eax + 8; /* 0x004DAC5C: add eax, 8 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DAC5F: mov ecx, dword ptr [ebp - 4] */
    MEM32(ecx) = eax; /* 0x004DAC62: mov dword ptr [ecx], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004DAC64: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0x4) = 0xF0u; /* 0x004DAC67: mov dword ptr [edx + 4], 0xf0 */
    eax = MEM32(ebp + (-0x4)); /* 0x004DAC6E: mov eax, dword ptr [ebp - 4] */
    MEM8(eax + 0xF8) = (uint8_t)(0xFFu); /* 0x004DAC71: mov byte ptr [eax + 0xf8], 0xff */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DAC78: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 0x1000u; /* 0x004DAC7B: add ecx, 0x1000 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DAC81: mov dword ptr [ebp - 4], ecx */
    goto L_004DAC48; /* 0x004DAC84: jmp 0x4dac48 */

L_004DAC73:
    _cf = 0; /* 0x004DAC73: clc  */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DAC74: add byte ptr [eax], al */
    SET_HI8(ebx, HI8(ebx) + HI8(ebx)); /* 0x004DAC76: add bh, bh */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DAC78: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 0x1000u; /* 0x004DAC7B: add ecx, 0x1000 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DAC81: mov dword ptr [ebp - 4], ecx */
    goto L_004DAC48; /* 0x004DAC84: jmp 0x4dac48 */

L_004DAC86:
    eax = MEM32(ebp + (-0xC)); /* 0x004DAC86: mov eax, dword ptr [ebp - 0xc] */
    goto L_004DACBA; /* 0x004DAC89: jmp 0x4dacba */

L_004DACBA:
    esp = ebp; /* 0x004DACBA: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DACBC: pop ebp */
    return; /* 0x004DACBD: ret  */

}

void sub_004DADC0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DAD4E:
    ecx = MEM32(ebp + (-0x14)); /* 0x004DAD4E: mov ecx, dword ptr [ebp - 0x14] */
    /* cmp MEM32(ecx + 0x10), 0xFFFFFFFFu */ /* 0x004DAD51: cmp dword ptr [ecx + 0x10], -1 */
    if (CMP_EQ(MEM32(ecx + 0x10), 0xFFFFFFFFu)) goto L_004DAE7E; /* 0x004DAD55: je 0x4dae7e */

L_004DAD5B:
    MEM32(ebp + (-0xC)) = 0x3FFu; /* 0x004DAD5B: mov dword ptr [ebp - 0xc], 0x3ff */
    MEM32(ebp + (-0x10)) = 0; /* 0x004DAD62: mov dword ptr [ebp - 0x10], 0 */
    edx = MEM32(ebp + (-0xC)); /* 0x004DAD69: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + (-0x14)); /* 0x004DAD6C: mov eax, dword ptr [ebp - 0x14] */
    ecx = eax + edx * 8 + 0x18; /* 0x004DAD6F: lea ecx, [eax + edx*8 + 0x18] */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DAD73: mov dword ptr [ebp - 4], ecx */
    goto L_004DAD8A; /* 0x004DAD76: jmp 0x4dad8a */

L_004DAD78:
    edx = MEM32(ebp + (-0xC)); /* 0x004DAD78: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - 1; /* 0x004DAD7B: sub edx, 1 */
    MEM32(ebp + (-0xC)) = edx; /* 0x004DAD7E: mov dword ptr [ebp - 0xc], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DAD81: mov eax, dword ptr [ebp - 4] */
    eax = eax - 8; /* 0x004DAD84: sub eax, 8 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DAD87: mov dword ptr [ebp - 4], eax */

L_004DAD8A:
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004DAD8A: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_L(MEM32(ebp + (-0xC)), 0)) goto L_004DAE14; /* 0x004DAD8E: jl 0x4dae14 */

L_004DAD94:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DAD94: mov ecx, dword ptr [ebp - 4] */
    /* cmp MEM32(ecx), 0xF0u */ /* 0x004DAD97: cmp dword ptr [ecx], 0xf0 */
    if (CMP_NE(MEM32(ecx), 0xF0u)) goto L_004DAE0F; /* 0x004DAD9D: jne 0x4dae0f */

L_004DAD9F:
    PUSH32(esp, 0x4000u); /* 0x004DAD9F: push 0x4000 */
    PUSH32(esp, 0x1000u); /* 0x004DADA4: push 0x1000 */
    edx = MEM32(ebp + (-0xC)); /* 0x004DADA9: mov edx, dword ptr [ebp - 0xc] */
    edx = edx << 0xCu; /* 0x004DADAC: shl edx, 0xc */
    eax = MEM32(ebp + (-0x14)); /* 0x004DADAF: mov eax, dword ptr [ebp - 0x14] */
    ecx = MEM32(eax + 0x10); /* 0x004DADB2: mov ecx, dword ptr [eax + 0x10] */
    ecx = ecx + edx; /* 0x004DADB5: add ecx, edx */
    PUSH32(esp, ecx); /* 0x004DADB7: push ecx */
    RECOMP_ICALL(MEM32(0x858708)); /* 0x004DADB8: call dword ptr [0x858708] */
    /* test eax, eax */ /* 0x004DADBE: test eax, eax */

L_004DADC0:
    if (/* no flag state for je */ _cf) goto L_004DAE0F; /* 0x004DADC0: je 0x4dae0f */

L_004DADC2:
    edx = MEM32(ebp + (-0x4)); /* 0x004DADC2: mov edx, dword ptr [ebp - 4] */
    MEM32(edx) = 0xFFFFFFFFu; /* 0x004DADC5: mov dword ptr [edx], 0xffffffff */
    eax = MEM32(0x84B854); /* 0x004DADCB: mov eax, dword ptr [0x84b854] */
    eax = eax - 1; /* 0x004DADD0: sub eax, 1 */
    MEM32(0x84B854) = eax; /* 0x004DADD3: mov dword ptr [0x84b854], eax */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DADD8: mov ecx, dword ptr [ebp - 0x14] */
    /* cmp MEM32(ecx + 0xC), 0 */ /* 0x004DADDB: cmp dword ptr [ecx + 0xc], 0 */
    if (CMP_EQ(MEM32(ecx + 0xC), 0)) goto L_004DADEC; /* 0x004DADDF: je 0x4dadec */

L_004DADE1:
    edx = MEM32(ebp + (-0x14)); /* 0x004DADE1: mov edx, dword ptr [ebp - 0x14] */
    eax = MEM32(edx + 0xC); /* 0x004DADE4: mov eax, dword ptr [edx + 0xc] */
    /* cmp eax, MEM32(ebp + (-0x4)) */ /* 0x004DADE7: cmp eax, dword ptr [ebp - 4] */
    if (CMP_BE(eax, MEM32(ebp + (-0x4)))) goto L_004DADF5; /* 0x004DADEA: jbe 0x4dadf5 */

L_004DADEC:
    ecx = MEM32(ebp + (-0x14)); /* 0x004DADEC: mov ecx, dword ptr [ebp - 0x14] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DADEF: mov edx, dword ptr [ebp - 4] */
    MEM32(ecx + 0xC) = edx; /* 0x004DADF2: mov dword ptr [ecx + 0xc], edx */

L_004DADF5:
    eax = MEM32(ebp + (-0x10)); /* 0x004DADF5: mov eax, dword ptr [ebp - 0x10] */
    eax = eax + 1; /* 0x004DADF8: add eax, 1 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DADFB: mov dword ptr [ebp - 0x10], eax */
    ecx = MEM32(ebp + 0x8); /* 0x004DADFE: mov ecx, dword ptr [ebp + 8] */
    ecx = ecx - 1; /* 0x004DAE01: sub ecx, 1 */
    MEM32(ebp + 0x8) = ecx; /* 0x004DAE04: mov dword ptr [ebp + 8], ecx */
    /* cmp MEM32(ebp + 0x8), 0 */ /* 0x004DAE07: cmp dword ptr [ebp + 8], 0 */
    if (CMP_NE(MEM32(ebp + 0x8), 0)) goto L_004DAE0F; /* 0x004DAE0B: jne 0x4dae0f */

L_004DAE0D:
    goto L_004DAE14; /* 0x004DAE0D: jmp 0x4dae14 */

L_004DAE0F:
    goto L_004DAD78; /* 0x004DAE0F: jmp 0x4dad78 */

L_004DAE14:
    edx = MEM32(ebp + (-0x14)); /* 0x004DAE14: mov edx, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DAE17: mov dword ptr [ebp - 8], edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004DAE1A: mov eax, dword ptr [ebp - 0x14] */
    ecx = MEM32(eax + 0x4); /* 0x004DAE1D: mov ecx, dword ptr [eax + 4] */
    MEM32(ebp + (-0x14)) = ecx; /* 0x004DAE20: mov dword ptr [ebp - 0x14], ecx */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004DAE23: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x10)), 0)) goto L_004DAE7E; /* 0x004DAE27: je 0x4dae7e */

L_004DAE29:
    edx = MEM32(ebp + (-0x8)); /* 0x004DAE29: mov edx, dword ptr [ebp - 8] */
    /* cmp MEM32(edx + 0x18), 0xFFFFFFFFu */ /* 0x004DAE2C: cmp dword ptr [edx + 0x18], -1 */
    if (CMP_NE(MEM32(edx + 0x18), 0xFFFFFFFFu)) goto L_004DAE7E; /* 0x004DAE30: jne 0x4dae7e */

L_004DAE32:
    MEM32(ebp + (-0xC)) = 1; /* 0x004DAE32: mov dword ptr [ebp - 0xc], 1 */
    eax = MEM32(ebp + (-0x8)); /* 0x004DAE39: mov eax, dword ptr [ebp - 8] */
    eax = eax + 0x20u; /* 0x004DAE3C: add eax, 0x20 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DAE3F: mov dword ptr [ebp - 4], eax */
    goto L_004DAE56; /* 0x004DAE42: jmp 0x4dae56 */

L_004DAE44:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DAE44: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + 1; /* 0x004DAE47: add ecx, 1 */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DAE4A: mov dword ptr [ebp - 0xc], ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004DAE4D: mov edx, dword ptr [ebp - 4] */
    edx = edx + 8; /* 0x004DAE50: add edx, 8 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DAE53: mov dword ptr [ebp - 4], edx */

L_004DAE56:
    /* cmp MEM32(ebp + (-0xC)), 0x400u */ /* 0x004DAE56: cmp dword ptr [ebp - 0xc], 0x400 */
    if (CMP_GE(MEM32(ebp + (-0xC)), 0x400u)) goto L_004DAE69; /* 0x004DAE5D: jge 0x4dae69 */

L_004DAE5F:
    eax = MEM32(ebp + (-0x4)); /* 0x004DAE5F: mov eax, dword ptr [ebp - 4] */
    /* cmp MEM32(eax), 0xFFFFFFFFu */ /* 0x004DAE62: cmp dword ptr [eax], -1 */
    if (CMP_NE(MEM32(eax), 0xFFFFFFFFu)) goto L_004DAE69; /* 0x004DAE65: jne 0x4dae69 */

L_004DAE67:
    goto L_004DAE44; /* 0x004DAE67: jmp 0x4dae44 */

L_004DAE69:
    /* cmp MEM32(ebp + (-0xC)), 0x400u */ /* 0x004DAE69: cmp dword ptr [ebp - 0xc], 0x400 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0x400u)) goto L_004DAE7E; /* 0x004DAE70: jne 0x4dae7e */

L_004DAE72:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DAE72: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DAE75: push ecx */
    RECOMP_CALL(sub_004DACC0); /* 0x004DAE76: call 0x4dacc0 */
    esp = esp + 4; /* 0x004DAE7B: add esp, 4 */

L_004DAE7E:
    edx = MEM32(ebp + (-0x14)); /* 0x004DAE7E: mov edx, dword ptr [ebp - 0x14] */
    /* cmp edx, MEM32(0x50964C) */ /* 0x004DAE81: cmp edx, dword ptr [0x50964c] */
    if (CMP_EQ(edx, MEM32(0x50964C))) goto L_004DAE93; /* 0x004DAE87: je 0x4dae93 */

L_004DAE89:
    /* cmp MEM32(ebp + 0x8), 0 */ /* 0x004DAE89: cmp dword ptr [ebp + 8], 0 */
    if (CMP_G(MEM32(ebp + 0x8), 0)) goto L_004DAD4E; /* 0x004DAE8D: jg 0x4dad4e */

L_004DAE93:
    esp = ebp; /* 0x004DAE93: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DAE95: pop ebp */
    return; /* 0x004DAE96: ret  */

}

void sub_004DAEB0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DAEAD:
    eax = MEM32(ebp + (-0x8)); /* 0x004DAEAD: mov eax, dword ptr [ebp - 8] */

L_004DAEB0:
    ecx = MEM32(ebp + 0x8); /* 0x004DAEB0: mov ecx, dword ptr [ebp + 8] */
    /* cmp ecx, MEM32(eax + 0x10) */ /* 0x004DAEB3: cmp ecx, dword ptr [eax + 0x10] */
    if (CMP_BE(ecx, MEM32(eax + 0x10))) goto L_004DAF19; /* 0x004DAEB6: jbe 0x4daf19 */

L_004DAEB8:
    edx = MEM32(ebp + (-0x8)); /* 0x004DAEB8: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(ebp + 0x8); /* 0x004DAEBB: mov eax, dword ptr [ebp + 8] */
    /* cmp eax, MEM32(edx + 0x14) */ /* 0x004DAEBE: cmp eax, dword ptr [edx + 0x14] */
    if (CMP_AE(eax, MEM32(edx + 0x14))) goto L_004DAF19; /* 0x004DAEC1: jae 0x4daf19 */

L_004DAEC3:
    ecx = MEM32(ebp + 0x8); /* 0x004DAEC3: mov ecx, dword ptr [ebp + 8] */
    ecx = ecx & 0xFu; /* 0x004DAEC6: and ecx, 0xf */
    /* test ecx, ecx */ /* 0x004DAEC9: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DAF15; /* 0x004DAECB: jne 0x4daf15 */

L_004DAECD:
    edx = MEM32(ebp + 0x8); /* 0x004DAECD: mov edx, dword ptr [ebp + 8] */
    edx = edx & 0xFFFu; /* 0x004DAED0: and edx, 0xfff */
    eax = 0; /* 0x004DAED6: xor eax, eax */
    eax = eax + 0x100u; /* 0x004DAED8: add eax, 0x100 */
    /* cmp edx, eax */ /* 0x004DAEDD: cmp edx, eax */
    if (CMP_B(edx, eax)) goto L_004DAF15; /* 0x004DAEDF: jb 0x4daf15 */

L_004DAEE1:
    ecx = MEM32(ebp + 0xC); /* 0x004DAEE1: mov ecx, dword ptr [ebp + 0xc] */
    edx = MEM32(ebp + (-0x8)); /* 0x004DAEE4: mov edx, dword ptr [ebp - 8] */
    MEM32(ecx) = edx; /* 0x004DAEE7: mov dword ptr [ecx], edx */
    eax = MEM32(ebp + 0x8); /* 0x004DAEE9: mov eax, dword ptr [ebp + 8] */
    eax = eax & 0xFFFFF000u; /* 0x004DAEEC: and eax, 0xfffff000 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DAEF1: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + 0x10); /* 0x004DAEF4: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DAEF7: mov edx, dword ptr [ebp - 4] */
    MEM32(ecx) = edx; /* 0x004DAEFA: mov dword ptr [ecx], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DAEFC: mov eax, dword ptr [ebp - 4] */
    eax = eax + 0x100u; /* 0x004DAEFF: add eax, 0x100 */
    ecx = MEM32(ebp + 0x8); /* 0x004DAF04: mov ecx, dword ptr [ebp + 8] */
    ecx = ecx - eax; /* 0x004DAF07: sub ecx, eax */
    ecx = (uint32_t)((int32_t)ecx >> 4); /* 0x004DAF09: sar ecx, 4 */
    edx = MEM32(ebp + (-0x4)); /* 0x004DAF0C: mov edx, dword ptr [ebp - 4] */
    eax = edx + ecx + 0x8; /* 0x004DAF0F: lea eax, [edx + ecx + 8] */
    goto L_004DAF2C; /* 0x004DAF13: jmp 0x4daf2c */

L_004DAF15:
    eax = 0; /* 0x004DAF15: xor eax, eax */
    goto L_004DAF2C; /* 0x004DAF17: jmp 0x4daf2c */

L_004DAF19:
    eax = MEM32(ebp + (-0x8)); /* 0x004DAF19: mov eax, dword ptr [ebp - 8] */
    ecx = MEM32(eax); /* 0x004DAF1C: mov ecx, dword ptr [eax] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DAF1E: mov dword ptr [ebp - 8], ecx */
    /* cmp MEM32(ebp + (-0x8)), 0x00509648u */ /* 0x004DAF21: cmp dword ptr [ebp - 8], 0x509648 */
    if (CMP_NE(MEM32(ebp + (-0x8)), 0x00509648u)) goto L_004DAEAD; /* 0x004DAF28: jne 0x4daead */

L_004DAF2A:
    eax = 0; /* 0x004DAF2A: xor eax, eax */

L_004DAF2C:
    esp = ebp; /* 0x004DAF2C: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DAF2E: pop ebp */
    return; /* 0x004DAF2F: ret  */

}

void sub_004DB220(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DB1F0:
    ecx = MEM32(ebp + (-0x18)); /* 0x004DB1F0: mov ecx, dword ptr [ebp - 0x18] */
    ecx = ecx + 1; /* 0x004DB1F3: add ecx, 1 */
    MEM32(ebp + (-0x18)) = ecx; /* 0x004DB1F6: mov dword ptr [ebp - 0x18], ecx */
    edx = MEM32(ebp + (-0x1C)); /* 0x004DB1F9: mov edx, dword ptr [ebp - 0x1c] */
    edx = edx + 0x1000u; /* 0x004DB1FC: add edx, 0x1000 */
    MEM32(ebp + (-0x1C)) = edx; /* 0x004DB202: mov dword ptr [ebp - 0x1c], edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004DB205: mov eax, dword ptr [ebp - 0x10] */
    eax = eax + 8; /* 0x004DB208: add eax, 8 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DB20B: mov dword ptr [ebp - 0x10], eax */
    ecx = MEM32(ebp + (-0x18)); /* 0x004DB20E: mov ecx, dword ptr [ebp - 0x18] */
    /* cmp ecx, MEM32(ebp + (-0x14)) */ /* 0x004DB211: cmp ecx, dword ptr [ebp - 0x14] */
    if (CMP_GE(ecx, MEM32(ebp + (-0x14)))) goto L_004DB24A; /* 0x004DB214: jge 0x4db24a */

L_004DB216:
    edx = MEM32(ebp + (-0x1C)); /* 0x004DB216: mov edx, dword ptr [ebp - 0x1c] */
    edx = edx + 8; /* 0x004DB219: add edx, 8 */
    eax = MEM32(ebp + (-0x1C)); /* 0x004DB21C: mov eax, dword ptr [ebp - 0x1c] */
    MEM32(eax) = edx; /* 0x004DB21F: mov dword ptr [eax], edx */
    ecx = MEM32(ebp + (-0x1C)); /* 0x004DB221: mov ecx, dword ptr [ebp - 0x1c] */
    MEM32(ecx + 0x4) = 0xF0u; /* 0x004DB224: mov dword ptr [ecx + 4], 0xf0 */
    edx = MEM32(ebp + (-0x1C)); /* 0x004DB22B: mov edx, dword ptr [ebp - 0x1c] */
    MEM8(edx + 0xF8) = (uint8_t)(0xFFu); /* 0x004DB22E: mov byte ptr [edx + 0xf8], 0xff */
    eax = MEM32(ebp + (-0x10)); /* 0x004DB235: mov eax, dword ptr [ebp - 0x10] */
    MEM32(eax) = 0xF0u; /* 0x004DB238: mov dword ptr [eax], 0xf0 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004DB23E: mov ecx, dword ptr [ebp - 0x10] */
    MEM32(ecx + 0x4) = 0xF1u; /* 0x004DB241: mov dword ptr [ecx + 4], 0xf1 */
    goto L_004DB1F0; /* 0x004DB248: jmp 0x4db1f0 */

L_004DB220:
    MEM8(ebx + 0x41C7E44D) = (uint8_t)(MEM8(ebx + 0x41C7E44D) + LO8(ecx) + _cf); /* 0x004DB220: adc byte ptr [ebx + 0x41c7e44d], cl */
    SET_LO8(eax, LO8(eax) + 0xF0u); /* 0x004DB226: add al, 0xf0 */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DB228: add byte ptr [eax], al */
    MEM8(ebx + (-0x7D391BAB)) = (uint8_t)(MEM8(ebx + (-0x7D391BAB)) + LO8(ecx)); /* 0x004DB22A: add byte ptr [ebx - 0x7d391bab], cl */
    _cf = 0; /* 0x004DB230: clc  */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DB231: add byte ptr [eax], al */
    SET_HI8(ebx, HI8(ebx) + HI8(ebx)); /* 0x004DB233: add bh, bh */
    eax = MEM32(ebp + (-0x10)); /* 0x004DB235: mov eax, dword ptr [ebp - 0x10] */
    MEM32(eax) = 0xF0u; /* 0x004DB238: mov dword ptr [eax], 0xf0 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004DB23E: mov ecx, dword ptr [ebp - 0x10] */
    MEM32(ecx + 0x4) = 0xF1u; /* 0x004DB241: mov dword ptr [ecx + 4], 0xf1 */
    goto L_004DB1F0; /* 0x004DB248: jmp 0x4db1f0 */

L_004DB24A:
    edx = MEM32(ebp + (-0x20)); /* 0x004DB24A: mov edx, dword ptr [ebp - 0x20] */
    MEM32(0x50B668) = edx; /* 0x004DB24D: mov dword ptr [0x50b668], edx */

L_004DB253:
    eax = MEM32(ebp + (-0x20)); /* 0x004DB253: mov eax, dword ptr [ebp - 0x20] */
    eax = eax + 0x2018u; /* 0x004DB256: add eax, 0x2018 */
    /* cmp MEM32(ebp + (-0x10)), eax */ /* 0x004DB25B: cmp dword ptr [ebp - 0x10], eax */
    if (CMP_AE(MEM32(ebp + (-0x10)), eax)) goto L_004DB273; /* 0x004DB25E: jae 0x4db273 */

L_004DB260:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DB260: mov ecx, dword ptr [ebp - 0x10] */
    /* cmp MEM32(ecx), 0xFFFFFFFFu */ /* 0x004DB263: cmp dword ptr [ecx], -1 */
    if (CMP_EQ(MEM32(ecx), 0xFFFFFFFFu)) goto L_004DB273; /* 0x004DB266: je 0x4db273 */

L_004DB268:
    edx = MEM32(ebp + (-0x10)); /* 0x004DB268: mov edx, dword ptr [ebp - 0x10] */
    edx = edx + 8; /* 0x004DB26B: add edx, 8 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DB26E: mov dword ptr [ebp - 0x10], edx */
    goto L_004DB253; /* 0x004DB271: jmp 0x4db253 */

L_004DB273:
    eax = MEM32(ebp + (-0x20)); /* 0x004DB273: mov eax, dword ptr [ebp - 0x20] */
    eax = eax + 0x2018u; /* 0x004DB276: add eax, 0x2018 */
    /* cmp MEM32(ebp + (-0x10)), eax */ /* 0x004DB27B: cmp dword ptr [ebp - 0x10], eax */
    ecx = _cf ? 0xFFFFFFFFu : 0; /* 0x004DB27E: sbb ecx, ecx */
    ecx = ecx & MEM32(ebp + (-0x10)); /* 0x004DB280: and ecx, dword ptr [ebp - 0x10] */
    edx = MEM32(ebp + (-0x20)); /* 0x004DB283: mov edx, dword ptr [ebp - 0x20] */
    MEM32(edx + 0xC) = ecx; /* 0x004DB286: mov dword ptr [edx + 0xc], ecx */
    eax = MEM32(ebp + (-0x8)); /* 0x004DB289: mov eax, dword ptr [ebp - 8] */
    SET_LO8(ecx, MEM8(ebp + 0x8)); /* 0x004DB28C: mov cl, byte ptr [ebp + 8] */
    MEM8(eax + 0x8) = (uint8_t)(LO8(ecx)); /* 0x004DB28F: mov byte ptr [eax + 8], cl */
    edx = MEM32(ebp + (-0x20)); /* 0x004DB292: mov edx, dword ptr [ebp - 0x20] */
    eax = MEM32(ebp + (-0x4)); /* 0x004DB295: mov eax, dword ptr [ebp - 4] */
    MEM32(edx + 0x8) = eax; /* 0x004DB298: mov dword ptr [edx + 8], eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DB29B: mov ecx, dword ptr [ebp - 4] */
    edx = MEM32(ecx); /* 0x004DB29E: mov edx, dword ptr [ecx] */
    edx = edx - MEM32(ebp + 0x8); /* 0x004DB2A0: sub edx, dword ptr [ebp + 8] */
    eax = MEM32(ebp + (-0x4)); /* 0x004DB2A3: mov eax, dword ptr [ebp - 4] */
    MEM32(eax) = edx; /* 0x004DB2A6: mov dword ptr [eax], edx */
    ecx = MEM32(ebp + 0x8); /* 0x004DB2A8: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ebp + (-0x8)); /* 0x004DB2AB: mov edx, dword ptr [ebp - 8] */
    eax = edx + ecx + 0x8; /* 0x004DB2AE: lea eax, [edx + ecx + 8] */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DB2B2: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx) = eax; /* 0x004DB2B5: mov dword ptr [ecx], eax */
    edx = MEM32(ebp + (-0x8)); /* 0x004DB2B7: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0x4); /* 0x004DB2BA: mov eax, dword ptr [edx + 4] */
    eax = eax - MEM32(ebp + 0x8); /* 0x004DB2BD: sub eax, dword ptr [ebp + 8] */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DB2C0: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx + 0x4) = eax; /* 0x004DB2C3: mov dword ptr [ecx + 4], eax */
    eax = MEM32(ebp + (-0x8)); /* 0x004DB2C6: mov eax, dword ptr [ebp - 8] */
    eax = eax + 0x100u; /* 0x004DB2C9: add eax, 0x100 */
    goto L_004DB354; /* 0x004DB2CE: jmp 0x4db354 */

L_004DB354:
    esp = ebp; /* 0x004DB354: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DB356: pop ebp */
    return; /* 0x004DB357: ret  */

}

void sub_004DB2F0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DB2F0:
    MEM32(ecx + 0x7D83E045) = MEM32(ecx + 0x7D83E045) - 1; /* 0x004DB2F0: dec dword ptr [ecx + 0x7d83e045] */
    /* UNIMPLEMENTED: loopne 0x4db2f8 */ /* 0x004DB2F6: loopne 0x4db2f8 */
    if (/* dec result */ CMP_EQ(MEM32(ecx + 0x7D83E045), 1)) goto L_004DB352; /* 0x004DB2F8: je 0x4db352 */

L_004DB2FA:
    ecx = MEM32(ebp + (-0x20)); /* 0x004DB2FA: mov ecx, dword ptr [ebp - 0x20] */
    edx = MEM32(ecx + 0x10); /* 0x004DB2FD: mov edx, dword ptr [ecx + 0x10] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DB300: mov dword ptr [ebp - 8], edx */
    eax = MEM32(ebp + (-0x8)); /* 0x004DB303: mov eax, dword ptr [ebp - 8] */
    SET_LO8(ecx, MEM8(ebp + 0x8)); /* 0x004DB306: mov cl, byte ptr [ebp + 8] */
    MEM8(eax + 0x8) = (uint8_t)(LO8(ecx)); /* 0x004DB309: mov byte ptr [eax + 8], cl */
    edx = MEM32(ebp + (-0x20)); /* 0x004DB30C: mov edx, dword ptr [ebp - 0x20] */
    MEM32(0x50B668) = edx; /* 0x004DB30F: mov dword ptr [0x50b668], edx */
    eax = MEM32(ebp + 0x8); /* 0x004DB315: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DB318: mov ecx, dword ptr [ebp - 8] */
    edx = ecx + eax + 0x8; /* 0x004DB31B: lea edx, [ecx + eax + 8] */
    eax = MEM32(ebp + (-0x8)); /* 0x004DB31F: mov eax, dword ptr [ebp - 8] */
    MEM32(eax) = edx; /* 0x004DB322: mov dword ptr [eax], edx */
    ecx = 0xF0u; /* 0x004DB324: mov ecx, 0xf0 */
    ecx = ecx - MEM32(ebp + 0x8); /* 0x004DB329: sub ecx, dword ptr [ebp + 8] */
    edx = MEM32(ebp + (-0x8)); /* 0x004DB32C: mov edx, dword ptr [ebp - 8] */
    MEM32(edx + 0x4) = ecx; /* 0x004DB32F: mov dword ptr [edx + 4], ecx */
    eax = MEM32(ebp + 0x8); /* 0x004DB332: mov eax, dword ptr [ebp + 8] */
    eax = eax & 0xFFu; /* 0x004DB335: and eax, 0xff */
    ecx = MEM32(ebp + (-0x20)); /* 0x004DB33A: mov ecx, dword ptr [ebp - 0x20] */
    edx = MEM32(ecx + 0x18); /* 0x004DB33D: mov edx, dword ptr [ecx + 0x18] */
    edx = edx - eax; /* 0x004DB340: sub edx, eax */
    eax = MEM32(ebp + (-0x20)); /* 0x004DB342: mov eax, dword ptr [ebp - 0x20] */
    MEM32(eax + 0x18) = edx; /* 0x004DB345: mov dword ptr [eax + 0x18], edx */
    eax = MEM32(ebp + (-0x8)); /* 0x004DB348: mov eax, dword ptr [ebp - 8] */
    eax = eax + 0x100u; /* 0x004DB34B: add eax, 0x100 */
    goto L_004DB354; /* 0x004DB350: jmp 0x4db354 */

L_004DB352:
    eax = 0; /* 0x004DB352: xor eax, eax */

L_004DB354:
    esp = ebp; /* 0x004DB354: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DB356: pop ebp */
    return; /* 0x004DB357: ret  */

}

void sub_004DB530(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DB512:
    edx = MEM32(ebp + (-0x8)); /* 0x004DB512: mov edx, dword ptr [ebp - 8] */
    /* cmp edx, MEM32(ebp + (-0x4)) */ /* 0x004DB515: cmp edx, dword ptr [ebp - 4] */
    if (CMP_AE(edx, MEM32(ebp + (-0x4)))) goto L_004DB603; /* 0x004DB518: jae 0x4db603 */

L_004DB51E:
    eax = MEM32(ebp + (-0x8)); /* 0x004DB51E: mov eax, dword ptr [ebp - 8] */
    eax = eax + MEM32(ebp + 0x10); /* 0x004DB521: add eax, dword ptr [ebp + 0x10] */
    /* cmp eax, MEM32(ebp + (-0x14)) */ /* 0x004DB524: cmp eax, dword ptr [ebp - 0x14] */
    if (CMP_AE(eax, MEM32(ebp + (-0x14)))) goto L_004DB603; /* 0x004DB527: jae 0x4db603 */

L_004DB52D:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DB52D: mov ecx, dword ptr [ebp - 8] */

L_004DB530:
    edx = 0; /* 0x004DB530: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DB532: mov dl, byte ptr [ecx] */
    /* test edx, edx */ /* 0x004DB534: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004DB5EF; /* 0x004DB536: jne 0x4db5ef */

L_004DB53C:
    eax = MEM32(ebp + (-0x8)); /* 0x004DB53C: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DB53F: add eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DB542: mov dword ptr [ebp - 0xc], eax */
    MEM32(ebp + (-0x10)) = 1; /* 0x004DB545: mov dword ptr [ebp - 0x10], 1 */
    goto L_004DB560; /* 0x004DB54C: jmp 0x4db560 */

L_004DB54E:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DB54E: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + 1; /* 0x004DB551: add ecx, 1 */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DB554: mov dword ptr [ebp - 0xc], ecx */
    edx = MEM32(ebp + (-0x10)); /* 0x004DB557: mov edx, dword ptr [ebp - 0x10] */
    edx = edx + 1; /* 0x004DB55A: add edx, 1 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DB55D: mov dword ptr [ebp - 0x10], edx */

L_004DB560:
    eax = MEM32(ebp + (-0xC)); /* 0x004DB560: mov eax, dword ptr [ebp - 0xc] */
    ecx = 0; /* 0x004DB563: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DB565: mov cl, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DB567: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DB56D; /* 0x004DB569: jne 0x4db56d */

L_004DB56B:
    goto L_004DB54E; /* 0x004DB56B: jmp 0x4db54e */

L_004DB56D:
    edx = MEM32(ebp + (-0x10)); /* 0x004DB56D: mov edx, dword ptr [ebp - 0x10] */
    /* cmp edx, MEM32(ebp + 0x10) */ /* 0x004DB570: cmp edx, dword ptr [ebp + 0x10] */
    if (CMP_AE(edx, MEM32(ebp + 0x10))) goto L_004DB592; /* 0x004DB573: jae 0x4db592 */

L_004DB575:
    eax = MEM32(ebp + 0xC); /* 0x004DB575: mov eax, dword ptr [ebp + 0xc] */
    eax = eax - MEM32(ebp + (-0x10)); /* 0x004DB578: sub eax, dword ptr [ebp - 0x10] */
    MEM32(ebp + 0xC) = eax; /* 0x004DB57B: mov dword ptr [ebp + 0xc], eax */
    ecx = MEM32(ebp + 0xC); /* 0x004DB57E: mov ecx, dword ptr [ebp + 0xc] */
    /* cmp ecx, MEM32(ebp + 0x10) */ /* 0x004DB581: cmp ecx, dword ptr [ebp + 0x10] */
    if (CMP_AE(ecx, MEM32(ebp + 0x10))) goto L_004DB58A; /* 0x004DB584: jae 0x4db58a */

L_004DB586:
    eax = 0; /* 0x004DB586: xor eax, eax */
    goto L_004DB605; /* 0x004DB588: jmp 0x4db605 */

L_004DB58A:
    edx = MEM32(ebp + (-0xC)); /* 0x004DB58A: mov edx, dword ptr [ebp - 0xc] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DB58D: mov dword ptr [ebp - 8], edx */
    goto L_004DB5ED; /* 0x004DB590: jmp 0x4db5ed */

L_004DB592:
    eax = MEM32(ebp + (-0x8)); /* 0x004DB592: mov eax, dword ptr [ebp - 8] */
    eax = eax + MEM32(ebp + 0x10); /* 0x004DB595: add eax, dword ptr [ebp + 0x10] */
    /* cmp eax, MEM32(ebp + (-0x14)) */ /* 0x004DB598: cmp eax, dword ptr [ebp - 0x14] */
    if (CMP_AE(eax, MEM32(ebp + (-0x14)))) goto L_004DB5B6; /* 0x004DB59B: jae 0x4db5b6 */

L_004DB59D:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DB59D: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + MEM32(ebp + 0x10); /* 0x004DB5A0: add ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + 0x8); /* 0x004DB5A3: mov edx, dword ptr [ebp + 8] */
    MEM32(edx) = ecx; /* 0x004DB5A6: mov dword ptr [edx], ecx */
    eax = MEM32(ebp + (-0x10)); /* 0x004DB5A8: mov eax, dword ptr [ebp - 0x10] */
    eax = eax - MEM32(ebp + 0x10); /* 0x004DB5AB: sub eax, dword ptr [ebp + 0x10] */
    ecx = MEM32(ebp + 0x8); /* 0x004DB5AE: mov ecx, dword ptr [ebp + 8] */
    MEM32(ecx + 0x4) = eax; /* 0x004DB5B1: mov dword ptr [ecx + 4], eax */
    goto L_004DB5CB; /* 0x004DB5B4: jmp 0x4db5cb */

L_004DB5B6:
    edx = MEM32(ebp + 0x8); /* 0x004DB5B6: mov edx, dword ptr [ebp + 8] */
    edx = edx + 8; /* 0x004DB5B9: add edx, 8 */
    eax = MEM32(ebp + 0x8); /* 0x004DB5BC: mov eax, dword ptr [ebp + 8] */
    MEM32(eax) = edx; /* 0x004DB5BF: mov dword ptr [eax], edx */
    ecx = MEM32(ebp + 0x8); /* 0x004DB5C1: mov ecx, dword ptr [ebp + 8] */
    MEM32(ecx + 0x4) = 0; /* 0x004DB5C4: mov dword ptr [ecx + 4], 0 */

L_004DB5CB:
    edx = MEM32(ebp + (-0x8)); /* 0x004DB5CB: mov edx, dword ptr [ebp - 8] */
    SET_LO8(eax, MEM8(ebp + 0x10)); /* 0x004DB5CE: mov al, byte ptr [ebp + 0x10] */
    MEM8(edx) = (uint8_t)(LO8(eax)); /* 0x004DB5D1: mov byte ptr [edx], al */
    ecx = MEM32(ebp + 0x8); /* 0x004DB5D3: mov ecx, dword ptr [ebp + 8] */
    ecx = ecx + 8; /* 0x004DB5D6: add ecx, 8 */
    edx = MEM32(ebp + (-0x8)); /* 0x004DB5D9: mov edx, dword ptr [ebp - 8] */
    edx = edx - ecx; /* 0x004DB5DC: sub edx, ecx */
    edx = edx << 4; /* 0x004DB5DE: shl edx, 4 */
    eax = MEM32(ebp + 0x8); /* 0x004DB5E1: mov eax, dword ptr [ebp + 8] */
    eax = eax + edx + 0x100; /* 0x004DB5E4: lea eax, [eax + edx + 0x100] */
    goto L_004DB605; /* 0x004DB5EB: jmp 0x4db605 */

L_004DB5ED:
    goto L_004DB5FE; /* 0x004DB5ED: jmp 0x4db5fe */

L_004DB5EF:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DB5EF: mov ecx, dword ptr [ebp - 8] */
    edx = 0; /* 0x004DB5F2: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DB5F4: mov dl, byte ptr [ecx] */
    eax = MEM32(ebp + (-0x8)); /* 0x004DB5F6: mov eax, dword ptr [ebp - 8] */
    eax = eax + edx; /* 0x004DB5F9: add eax, edx */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DB5FB: mov dword ptr [ebp - 8], eax */

L_004DB5FE:
    goto L_004DB512; /* 0x004DB5FE: jmp 0x4db512 */

L_004DB603:
    eax = 0; /* 0x004DB603: xor eax, eax */

L_004DB605:
    esp = ebp; /* 0x004DB605: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DB607: pop ebp */
    return; /* 0x004DB608: ret  */

}

void sub_004DB6F0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DB6F0:
    /* cmp eax, MEM32(edx) */ /* 0x004DB6F0: cmp eax, dword ptr [edx] */
    if (CMP_BE(eax, MEM32(edx))) goto L_004DB752; /* 0x004DB6F2: jbe 0x4db752 */

L_004DB6F4:
    ecx = MEM32(ebp + 0xC); /* 0x004DB6F4: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx + 0xF8u; /* 0x004DB6F7: add ecx, 0xf8 */
    /* cmp MEM32(ebp + (-0x18)), ecx */ /* 0x004DB6FD: cmp dword ptr [ebp - 0x18], ecx */
    if (CMP_AE(MEM32(ebp + (-0x18)), ecx)) goto L_004DB73D; /* 0x004DB700: jae 0x4db73d */

L_004DB702:
    edx = MEM32(ebp + 0xC); /* 0x004DB702: mov edx, dword ptr [ebp + 0xc] */
    eax = MEM32(ebp + (-0x18)); /* 0x004DB705: mov eax, dword ptr [ebp - 0x18] */
    MEM32(edx) = eax; /* 0x004DB708: mov dword ptr [edx], eax */
    MEM32(ebp + (-0x8)) = 0; /* 0x004DB70A: mov dword ptr [ebp - 8], 0 */
    goto L_004DB725; /* 0x004DB711: jmp 0x4db725 */

L_004DB713:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DB713: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DB716: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DB719: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x18)); /* 0x004DB71C: mov edx, dword ptr [ebp - 0x18] */
    edx = edx + 1; /* 0x004DB71F: add edx, 1 */
    MEM32(ebp + (-0x18)) = edx; /* 0x004DB722: mov dword ptr [ebp - 0x18], edx */

L_004DB725:
    eax = MEM32(ebp + (-0x18)); /* 0x004DB725: mov eax, dword ptr [ebp - 0x18] */
    ecx = 0; /* 0x004DB728: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DB72A: mov cl, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DB72C: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DB732; /* 0x004DB72E: jne 0x4db732 */

L_004DB730:
    goto L_004DB713; /* 0x004DB730: jmp 0x4db713 */

L_004DB732:
    edx = MEM32(ebp + 0xC); /* 0x004DB732: mov edx, dword ptr [ebp + 0xc] */
    eax = MEM32(ebp + (-0x8)); /* 0x004DB735: mov eax, dword ptr [ebp - 8] */
    MEM32(edx + 0x4) = eax; /* 0x004DB738: mov dword ptr [edx + 4], eax */
    goto L_004DB752; /* 0x004DB73B: jmp 0x4db752 */

L_004DB73D:
    ecx = MEM32(ebp + 0xC); /* 0x004DB73D: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx + 8; /* 0x004DB740: add ecx, 8 */
    edx = MEM32(ebp + 0xC); /* 0x004DB743: mov edx, dword ptr [ebp + 0xc] */
    MEM32(edx) = ecx; /* 0x004DB746: mov dword ptr [edx], ecx */
    eax = MEM32(ebp + 0xC); /* 0x004DB748: mov eax, dword ptr [ebp + 0xc] */
    MEM32(eax + 0x4) = 0; /* 0x004DB74B: mov dword ptr [eax + 4], 0 */

L_004DB752:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DB752: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx - MEM32(ebp + 0x14); /* 0x004DB755: sub ecx, dword ptr [ebp + 0x14] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DB758: mov edx, dword ptr [ebp - 4] */
    eax = MEM32(edx); /* 0x004DB75B: mov eax, dword ptr [edx] */
    eax = eax + ecx; /* 0x004DB75D: add eax, ecx */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DB75F: mov ecx, dword ptr [ebp - 4] */
    MEM32(ecx) = eax; /* 0x004DB762: mov dword ptr [ecx], eax */
    edx = MEM32(ebp + (-0x14)); /* 0x004DB764: mov edx, dword ptr [ebp - 0x14] */
    edx = edx + 1; /* 0x004DB767: add edx, 1 */
    MEM32(ebp + (-0x14)) = edx; /* 0x004DB76A: mov dword ptr [ebp - 0x14], edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004DB76D: mov eax, dword ptr [ebp - 0x14] */
    esp = ebp; /* 0x004DB770: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DB772: pop ebp */
    return; /* 0x004DB773: ret  */

}

void sub_004DB750(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DB750:
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DB750: add byte ptr [eax], al */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DB752: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx - MEM32(ebp + 0x14); /* 0x004DB755: sub ecx, dword ptr [ebp + 0x14] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DB758: mov edx, dword ptr [ebp - 4] */
    eax = MEM32(edx); /* 0x004DB75B: mov eax, dword ptr [edx] */
    eax = eax + ecx; /* 0x004DB75D: add eax, ecx */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DB75F: mov ecx, dword ptr [ebp - 4] */
    MEM32(ecx) = eax; /* 0x004DB762: mov dword ptr [ecx], eax */
    edx = MEM32(ebp + (-0x14)); /* 0x004DB764: mov edx, dword ptr [ebp - 0x14] */
    edx = edx + 1; /* 0x004DB767: add edx, 1 */
    MEM32(ebp + (-0x14)) = edx; /* 0x004DB76A: mov dword ptr [ebp - 0x14], edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004DB76D: mov eax, dword ptr [ebp - 0x14] */
    esp = ebp; /* 0x004DB770: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DB772: pop ebp */
    return; /* 0x004DB773: ret  */

}

void sub_004DB810(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DB810:
    return; /* far return */ /* 0x004DB810: retf 0x8b18 */

}

void sub_004DB860(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DB860:
    goto L_004DB9B3; /* 0x004DB860: jmp 0x4db9b3 */

L_004DB9B3:
    esp = ebp; /* 0x004DB9B3: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DB9B5: pop ebp */
    return; /* 0x004DB9B6: ret  */

}

void sub_004DB9E0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DB9E0:
    /* UNIMPLEMENTED: pushal  */ /* 0x004DB9E0: pushal  */
    esp = POP32_VAL(esp); /* 0x004DB9E1: pop esp */
    /* test MEM32(eax), eax */ /* 0x004DB9E2: test dword ptr [eax], eax */
    ecx = (int32_t)(int8_t)MEM8(eax + edx * 8 + 0x4); /* 0x004DB9E4: movsx ecx, byte ptr [eax + edx*8 + 4] */
    ecx = ecx & 1; /* 0x004DB9E9: and ecx, 1 */
    /* test ecx, ecx */ /* 0x004DB9EC: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DBA0C; /* 0x004DB9EE: jne 0x4dba0c */

L_004DB9F0:
    MEM32(0x84B7AC) = 9; /* 0x004DB9F0: mov dword ptr [0x84b7ac], 9 */
    MEM32(0x84B7B0) = 0; /* 0x004DB9FA: mov dword ptr [0x84b7b0], 0 */
    eax = eax | 0xFFFFFFFFu; /* 0x004DBA04: or eax, 0xffffffff */
    goto L_004DBAAA; /* 0x004DBA07: jmp 0x4dbaaa */

L_004DBA0C:
    edx = MEM32(ebp + 0x8); /* 0x004DBA0C: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004DBA0F: push edx */
    RECOMP_CALL(sub_004E0780); /* 0x004DBA10: call 0x4e0780 */
    esp = esp + 4; /* 0x004DBA15: add esp, 4 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DBA18: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0xFFFFFFFFu */ /* 0x004DBA1B: cmp dword ptr [ebp - 0xc], -1 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0xFFFFFFFFu)) goto L_004DBA30; /* 0x004DBA1F: jne 0x4dba30 */

L_004DBA21:
    MEM32(0x84B7AC) = 9; /* 0x004DBA21: mov dword ptr [0x84b7ac], 9 */
    eax = eax | 0xFFFFFFFFu; /* 0x004DBA2B: or eax, 0xffffffff */
    goto L_004DBAAA; /* 0x004DBA2E: jmp 0x4dbaaa */

L_004DBA30:
    eax = MEM32(ebp + 0x10); /* 0x004DBA30: mov eax, dword ptr [ebp + 0x10] */
    PUSH32(esp, eax); /* 0x004DBA33: push eax */
    PUSH32(esp, 0); /* 0x004DBA34: push 0 */
    ecx = MEM32(ebp + 0xC); /* 0x004DBA36: mov ecx, dword ptr [ebp + 0xc] */
    PUSH32(esp, ecx); /* 0x004DBA39: push ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004DBA3A: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004DBA3D: push edx */
    RECOMP_ICALL(MEM32(0x858688)); /* 0x004DBA3E: call dword ptr [0x858688] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DBA44: mov dword ptr [ebp - 8], eax */
    /* cmp MEM32(ebp + (-0x8)), 0xFFFFFFFFu */ /* 0x004DBA47: cmp dword ptr [ebp - 8], -1 */
    if (CMP_NE(MEM32(ebp + (-0x8)), 0xFFFFFFFFu)) goto L_004DBA58; /* 0x004DBA4B: jne 0x4dba58 */

L_004DBA4D:
    RECOMP_ICALL(MEM32(0x85867C)); /* 0x004DBA4D: call dword ptr [0x85867c] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DBA53: mov dword ptr [ebp - 4], eax */
    goto L_004DBA5F; /* 0x004DBA56: jmp 0x4dba5f */

L_004DBA58:
    MEM32(ebp + (-0x4)) = 0; /* 0x004DBA58: mov dword ptr [ebp - 4], 0 */

L_004DBA5F:
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DBA5F: cmp dword ptr [ebp - 4], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0)) goto L_004DBA76; /* 0x004DBA63: je 0x4dba76 */

L_004DBA65:
    eax = MEM32(ebp + (-0x4)); /* 0x004DBA65: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004DBA68: push eax */
    RECOMP_CALL(sub_004E0440); /* 0x004DBA69: call 0x4e0440 */
    esp = esp + 4; /* 0x004DBA6E: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004DBA71: or eax, 0xffffffff */
    goto L_004DBAAA; /* 0x004DBA74: jmp 0x4dbaaa */

L_004DBA76:
    ecx = MEM32(ebp + 0x8); /* 0x004DBA76: mov ecx, dword ptr [ebp + 8] */
    ecx = (uint32_t)((int32_t)ecx >> 5); /* 0x004DBA79: sar ecx, 5 */
    edx = MEM32(ebp + 0x8); /* 0x004DBA7C: mov edx, dword ptr [ebp + 8] */
    edx = edx & 0x1Fu; /* 0x004DBA7F: and edx, 0x1f */
    eax = MEM32(ecx * 4 + 0x855C60); /* 0x004DBA82: mov eax, dword ptr [ecx*4 + 0x855c60] */
    SET_LO8(ecx, MEM8(eax + edx * 8 + 0x4)); /* 0x004DBA89: mov cl, byte ptr [eax + edx*8 + 4] */
    SET_LO8(ecx, LO8(ecx) & 0xFDu); /* 0x004DBA8D: and cl, 0xfd */
    edx = MEM32(ebp + 0x8); /* 0x004DBA90: mov edx, dword ptr [ebp + 8] */
    edx = (uint32_t)((int32_t)edx >> 5); /* 0x004DBA93: sar edx, 5 */
    eax = MEM32(ebp + 0x8); /* 0x004DBA96: mov eax, dword ptr [ebp + 8] */
    eax = eax & 0x1Fu; /* 0x004DBA99: and eax, 0x1f */
    edx = MEM32(edx * 4 + 0x855C60); /* 0x004DBA9C: mov edx, dword ptr [edx*4 + 0x855c60] */
    MEM8(edx + eax * 8 + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBAA3: mov byte ptr [edx + eax*8 + 4], cl */
    eax = MEM32(ebp + (-0x8)); /* 0x004DBAA7: mov eax, dword ptr [ebp - 8] */

L_004DBAAA:
    esp = ebp; /* 0x004DBAAA: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DBAAC: pop ebp */
    return; /* 0x004DBAAD: ret  */

}

void sub_004DBAE0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DBAE0:
    /* UNIMPLEMENTED: les eax, ptr [ebx + ecx*4] */ /* 0x004DBAE0: les eax, ptr [ebx + ecx*4] */
    ebp = ebp + 1; /* 0x004DBAE3: inc ebp */
    SET_LO8(eax, 0xA3u); /* 0x004DBAE4: mov al, 0xa3 */
    /* UNIMPLEMENTED: pushal  */ /* 0x004DBAE6: pushal  */
    esp = POP32_VAL(esp); /* 0x004DBAE7: pop esp */
    /* test MEM32(eax), eax */ /* 0x004DBAE8: test dword ptr [eax], eax */
    MEM32(0x855D9C) = 0x20u; /* 0x004DBAEA: mov dword ptr [0x855d9c], 0x20 */
    goto L_004DBAFF; /* 0x004DBAF4: jmp 0x4dbaff */

L_004DBAF6:
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBAF6: mov ecx, dword ptr [ebp - 0x50] */
    ecx = ecx + 8; /* 0x004DBAF9: add ecx, 8 */
    MEM32(ebp + (-0x50)) = ecx; /* 0x004DBAFC: mov dword ptr [ebp - 0x50], ecx */

L_004DBAFF:
    edx = MEM32(0x855C60); /* 0x004DBAFF: mov edx, dword ptr [0x855c60] */
    edx = edx + 0x100u; /* 0x004DBB05: add edx, 0x100 */
    /* cmp MEM32(ebp + (-0x50)), edx */ /* 0x004DBB0B: cmp dword ptr [ebp - 0x50], edx */
    if (CMP_AE(MEM32(ebp + (-0x50)), edx)) goto L_004DBB29; /* 0x004DBB0E: jae 0x4dbb29 */

L_004DBB10:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBB10: mov eax, dword ptr [ebp - 0x50] */
    MEM8(eax + 0x4) = (uint8_t)(0); /* 0x004DBB13: mov byte ptr [eax + 4], 0 */
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBB17: mov ecx, dword ptr [ebp - 0x50] */
    MEM32(ecx) = 0xFFFFFFFFu; /* 0x004DBB1A: mov dword ptr [ecx], 0xffffffff */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBB20: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x5) = (uint8_t)(0xAu); /* 0x004DBB23: mov byte ptr [edx + 5], 0xa */
    goto L_004DBAF6; /* 0x004DBB27: jmp 0x4dbaf6 */

L_004DBB29:
    eax = ebp + (-0x48); /* 0x004DBB29: lea eax, [ebp - 0x48] */
    PUSH32(esp, eax); /* 0x004DBB2C: push eax */
    RECOMP_ICALL(MEM32(0x858684)); /* 0x004DBB2D: call dword ptr [0x858684] */
    ecx = MEM32(ebp + (-0x16)); /* 0x004DBB33: mov ecx, dword ptr [ebp - 0x16] */
    ecx = ecx & 0xFFFFu; /* 0x004DBB36: and ecx, 0xffff */
    /* test ecx, ecx */ /* 0x004DBB3C: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DBCBE; /* 0x004DBB3E: je 0x4dbcbe */

L_004DBB44:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DBB44: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x14)), 0)) goto L_004DBCBE; /* 0x004DBB48: je 0x4dbcbe */

L_004DBB4E:
    edx = MEM32(ebp + (-0x14)); /* 0x004DBB4E: mov edx, dword ptr [ebp - 0x14] */
    eax = MEM32(edx); /* 0x004DBB51: mov eax, dword ptr [edx] */
    MEM32(ebp + (-0x64)) = eax; /* 0x004DBB53: mov dword ptr [ebp - 0x64], eax */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DBB56: mov ecx, dword ptr [ebp - 0x14] */
    ecx = ecx + 4; /* 0x004DBB59: add ecx, 4 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DBB5C: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004DBB5F: mov edx, dword ptr [ebp - 4] */
    edx = edx + MEM32(ebp + (-0x64)); /* 0x004DBB62: add edx, dword ptr [ebp - 0x64] */
    MEM32(ebp + (-0x60)) = edx; /* 0x004DBB65: mov dword ptr [ebp - 0x60], edx */
    /* cmp MEM32(ebp + (-0x64)), 0x800u */ /* 0x004DBB68: cmp dword ptr [ebp - 0x64], 0x800 */
    if (CMP_GE(MEM32(ebp + (-0x64)), 0x800u)) goto L_004DBB79; /* 0x004DBB6F: jge 0x4dbb79 */

L_004DBB71:
    eax = MEM32(ebp + (-0x64)); /* 0x004DBB71: mov eax, dword ptr [ebp - 0x64] */
    MEM32(ebp + (-0x68)) = eax; /* 0x004DBB74: mov dword ptr [ebp - 0x68], eax */
    goto L_004DBB80; /* 0x004DBB77: jmp 0x4dbb80 */

L_004DBB79:
    MEM32(ebp + (-0x68)) = 0x800u; /* 0x004DBB79: mov dword ptr [ebp - 0x68], 0x800 */

L_004DBB80:
    ecx = MEM32(ebp + (-0x68)); /* 0x004DBB80: mov ecx, dword ptr [ebp - 0x68] */
    MEM32(ebp + (-0x64)) = ecx; /* 0x004DBB83: mov dword ptr [ebp - 0x64], ecx */
    MEM32(ebp + (-0x5C)) = 1; /* 0x004DBB86: mov dword ptr [ebp - 0x5c], 1 */
    goto L_004DBB98; /* 0x004DBB8D: jmp 0x4dbb98 */

L_004DBB8F:
    edx = MEM32(ebp + (-0x5C)); /* 0x004DBB8F: mov edx, dword ptr [ebp - 0x5c] */
    edx = edx + 1; /* 0x004DBB92: add edx, 1 */
    MEM32(ebp + (-0x5C)) = edx; /* 0x004DBB95: mov dword ptr [ebp - 0x5c], edx */

L_004DBB98:
    eax = MEM32(0x855D9C); /* 0x004DBB98: mov eax, dword ptr [0x855d9c] */
    /* cmp eax, MEM32(ebp + (-0x64)) */ /* 0x004DBB9D: cmp eax, dword ptr [ebp - 0x64] */
    if (CMP_GE(eax, MEM32(ebp + (-0x64)))) goto L_004DBC2D; /* 0x004DBBA0: jge 0x4dbc2d */

L_004DBBA6:
    PUSH32(esp, 0xB6u); /* 0x004DBBA6: push 0xb6 */
    PUSH32(esp, 0x004F4364u); /* 0x004DBBAB: push 0x4f4364 */
    PUSH32(esp, 2); /* 0x004DBBB0: push 2 */
    PUSH32(esp, 0x100u); /* 0x004DBBB2: push 0x100 */
    RECOMP_CALL(sub_004D25A0); /* 0x004DBBB7: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DBBBC: add esp, 0x10 */
    MEM32(ebp + (-0x50)) = eax; /* 0x004DBBBF: mov dword ptr [ebp - 0x50], eax */
    /* cmp MEM32(ebp + (-0x50)), 0 */ /* 0x004DBBC2: cmp dword ptr [ebp - 0x50], 0 */
    if (CMP_NE(MEM32(ebp + (-0x50)), 0)) goto L_004DBBD3; /* 0x004DBBC6: jne 0x4dbbd3 */

L_004DBBC8:
    ecx = MEM32(0x855D9C); /* 0x004DBBC8: mov ecx, dword ptr [0x855d9c] */
    MEM32(ebp + (-0x64)) = ecx; /* 0x004DBBCE: mov dword ptr [ebp - 0x64], ecx */
    goto L_004DBC2D; /* 0x004DBBD1: jmp 0x4dbc2d */

L_004DBBD3:
    edx = MEM32(ebp + (-0x5C)); /* 0x004DBBD3: mov edx, dword ptr [ebp - 0x5c] */
    eax = MEM32(ebp + (-0x50)); /* 0x004DBBD6: mov eax, dword ptr [ebp - 0x50] */
    MEM32(edx * 4 + 0x855C60) = eax; /* 0x004DBBD9: mov dword ptr [edx*4 + 0x855c60], eax */
    ecx = MEM32(0x855D9C); /* 0x004DBBE0: mov ecx, dword ptr [0x855d9c] */
    ecx = ecx + 0x20u; /* 0x004DBBE6: add ecx, 0x20 */
    MEM32(0x855D9C) = ecx; /* 0x004DBBE9: mov dword ptr [0x855d9c], ecx */
    goto L_004DBBFA; /* 0x004DBBEF: jmp 0x4dbbfa */

L_004DBBF1:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBBF1: mov edx, dword ptr [ebp - 0x50] */
    edx = edx + 8; /* 0x004DBBF4: add edx, 8 */
    MEM32(ebp + (-0x50)) = edx; /* 0x004DBBF7: mov dword ptr [ebp - 0x50], edx */

L_004DBBFA:
    eax = MEM32(ebp + (-0x5C)); /* 0x004DBBFA: mov eax, dword ptr [ebp - 0x5c] */
    ecx = MEM32(eax * 4 + 0x855C60); /* 0x004DBBFD: mov ecx, dword ptr [eax*4 + 0x855c60] */
    ecx = ecx + 0x100u; /* 0x004DBC04: add ecx, 0x100 */
    /* cmp MEM32(ebp + (-0x50)), ecx */ /* 0x004DBC0A: cmp dword ptr [ebp - 0x50], ecx */
    if (CMP_AE(MEM32(ebp + (-0x50)), ecx)) goto L_004DBC28; /* 0x004DBC0D: jae 0x4dbc28 */

L_004DBC0F:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBC0F: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(0); /* 0x004DBC12: mov byte ptr [edx + 4], 0 */
    eax = MEM32(ebp + (-0x50)); /* 0x004DBC16: mov eax, dword ptr [ebp - 0x50] */
    MEM32(eax) = 0xFFFFFFFFu; /* 0x004DBC19: mov dword ptr [eax], 0xffffffff */
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBC1F: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x5) = (uint8_t)(0xAu); /* 0x004DBC22: mov byte ptr [ecx + 5], 0xa */
    goto L_004DBBF1; /* 0x004DBC26: jmp 0x4dbbf1 */

L_004DBC28:
    goto L_004DBB8F; /* 0x004DBC28: jmp 0x4dbb8f */

L_004DBC2D:
    MEM32(ebp + (-0x58)) = 0; /* 0x004DBC2D: mov dword ptr [ebp - 0x58], 0 */
    goto L_004DBC51; /* 0x004DBC34: jmp 0x4dbc51 */

L_004DBC36:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBC36: mov edx, dword ptr [ebp - 0x58] */
    edx = edx + 1; /* 0x004DBC39: add edx, 1 */
    MEM32(ebp + (-0x58)) = edx; /* 0x004DBC3C: mov dword ptr [ebp - 0x58], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DBC3F: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DBC42: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DBC45: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + (-0x60)); /* 0x004DBC48: mov ecx, dword ptr [ebp - 0x60] */
    ecx = ecx + 4; /* 0x004DBC4B: add ecx, 4 */
    MEM32(ebp + (-0x60)) = ecx; /* 0x004DBC4E: mov dword ptr [ebp - 0x60], ecx */

L_004DBC51:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBC51: mov edx, dword ptr [ebp - 0x58] */
    /* cmp edx, MEM32(ebp + (-0x64)) */ /* 0x004DBC54: cmp edx, dword ptr [ebp - 0x64] */
    if (CMP_GE(edx, MEM32(ebp + (-0x64)))) goto L_004DBCBE; /* 0x004DBC57: jge 0x4dbcbe */

L_004DBC59:
    eax = MEM32(ebp + (-0x60)); /* 0x004DBC59: mov eax, dword ptr [ebp - 0x60] */
    /* cmp MEM32(eax), 0xFFFFFFFFu */ /* 0x004DBC5C: cmp dword ptr [eax], -1 */
    if (CMP_EQ(MEM32(eax), 0xFFFFFFFFu)) goto L_004DBCB9; /* 0x004DBC5F: je 0x4dbcb9 */

L_004DBC61:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DBC61: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DBC64: movsx edx, byte ptr [ecx] */
    edx = edx & 1; /* 0x004DBC67: and edx, 1 */
    /* test edx, edx */ /* 0x004DBC6A: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DBCB9; /* 0x004DBC6C: je 0x4dbcb9 */

L_004DBC6E:
    eax = MEM32(ebp + (-0x4)); /* 0x004DBC6E: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DBC71: movsx ecx, byte ptr [eax] */
    ecx = ecx & 8; /* 0x004DBC74: and ecx, 8 */
    /* test ecx, ecx */ /* 0x004DBC77: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DBC8B; /* 0x004DBC79: jne 0x4dbc8b */

L_004DBC7B:
    edx = MEM32(ebp + (-0x60)); /* 0x004DBC7B: mov edx, dword ptr [ebp - 0x60] */
    eax = MEM32(edx); /* 0x004DBC7E: mov eax, dword ptr [edx] */
    PUSH32(esp, eax); /* 0x004DBC80: push eax */
    RECOMP_ICALL(MEM32(0x858700)); /* 0x004DBC81: call dword ptr [0x858700] */
    /* test eax, eax */ /* 0x004DBC87: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DBCB9; /* 0x004DBC89: je 0x4dbcb9 */

L_004DBC8B:
    ecx = MEM32(ebp + (-0x58)); /* 0x004DBC8B: mov ecx, dword ptr [ebp - 0x58] */
    ecx = (uint32_t)((int32_t)ecx >> 5); /* 0x004DBC8E: sar ecx, 5 */
    edx = MEM32(ebp + (-0x58)); /* 0x004DBC91: mov edx, dword ptr [ebp - 0x58] */
    edx = edx & 0x1Fu; /* 0x004DBC94: and edx, 0x1f */
    eax = MEM32(ecx * 4 + 0x855C60); /* 0x004DBC97: mov eax, dword ptr [ecx*4 + 0x855c60] */
    ecx = eax + edx * 8; /* 0x004DBC9E: lea ecx, [eax + edx*8] */
    MEM32(ebp + (-0x50)) = ecx; /* 0x004DBCA1: mov dword ptr [ebp - 0x50], ecx */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBCA4: mov edx, dword ptr [ebp - 0x50] */
    eax = MEM32(ebp + (-0x60)); /* 0x004DBCA7: mov eax, dword ptr [ebp - 0x60] */
    ecx = MEM32(eax); /* 0x004DBCAA: mov ecx, dword ptr [eax] */
    MEM32(edx) = ecx; /* 0x004DBCAC: mov dword ptr [edx], ecx */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBCAE: mov edx, dword ptr [ebp - 0x50] */
    eax = MEM32(ebp + (-0x4)); /* 0x004DBCB1: mov eax, dword ptr [ebp - 4] */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DBCB4: mov cl, byte ptr [eax] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBCB6: mov byte ptr [edx + 4], cl */

L_004DBCB9:
    goto L_004DBC36; /* 0x004DBCB9: jmp 0x4dbc36 */

L_004DBCBE:
    MEM32(ebp + (-0x58)) = 0; /* 0x004DBCBE: mov dword ptr [ebp - 0x58], 0 */
    goto L_004DBCD0; /* 0x004DBCC5: jmp 0x4dbcd0 */

L_004DBCC7:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBCC7: mov edx, dword ptr [ebp - 0x58] */
    edx = edx + 1; /* 0x004DBCCA: add edx, 1 */
    MEM32(ebp + (-0x58)) = edx; /* 0x004DBCCD: mov dword ptr [ebp - 0x58], edx */

L_004DBCD0:
    /* cmp MEM32(ebp + (-0x58)), 3 */ /* 0x004DBCD0: cmp dword ptr [ebp - 0x58], 3 */
    if (CMP_GE(MEM32(ebp + (-0x58)), 3)) goto L_004DBDAB; /* 0x004DBCD4: jge 0x4dbdab */

L_004DBCDA:
    eax = MEM32(ebp + (-0x58)); /* 0x004DBCDA: mov eax, dword ptr [ebp - 0x58] */
    ecx = MEM32(0x855C60); /* 0x004DBCDD: mov ecx, dword ptr [0x855c60] */
    edx = ecx + eax * 8; /* 0x004DBCE3: lea edx, [ecx + eax*8] */
    MEM32(ebp + (-0x50)) = edx; /* 0x004DBCE6: mov dword ptr [ebp - 0x50], edx */
    eax = MEM32(ebp + (-0x50)); /* 0x004DBCE9: mov eax, dword ptr [ebp - 0x50] */
    /* cmp MEM32(eax), 0xFFFFFFFFu */ /* 0x004DBCEC: cmp dword ptr [eax], -1 */
    if (CMP_NE(MEM32(eax), 0xFFFFFFFFu)) goto L_004DBD97; /* 0x004DBCEF: jne 0x4dbd97 */

L_004DBCF5:
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBCF5: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x4) = (uint8_t)(0x81u); /* 0x004DBCF8: mov byte ptr [ecx + 4], 0x81 */
    /* cmp MEM32(ebp + (-0x58)), 0 */ /* 0x004DBCFC: cmp dword ptr [ebp - 0x58], 0 */
    if (CMP_NE(MEM32(ebp + (-0x58)), 0)) goto L_004DBD0B; /* 0x004DBD00: jne 0x4dbd0b */

L_004DBD02:
    MEM32(ebp + (-0x6C)) = 0xFFFFFFF6u; /* 0x004DBD02: mov dword ptr [ebp - 0x6c], 0xfffffff6 */
    goto L_004DBD1B; /* 0x004DBD09: jmp 0x4dbd1b */

L_004DBD0B:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBD0B: mov edx, dword ptr [ebp - 0x58] */
    edx = edx - 1; /* 0x004DBD0E: sub edx, 1 */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004DBD11: neg edx */
    edx = _cf ? 0xFFFFFFFFu : 0; /* 0x004DBD13: sbb edx, edx */
    edx = edx + 0xFFFFFFF5u; /* 0x004DBD15: add edx, -0xb */
    MEM32(ebp + (-0x6C)) = edx; /* 0x004DBD18: mov dword ptr [ebp - 0x6c], edx */

L_004DBD1B:
    eax = MEM32(ebp + (-0x6C)); /* 0x004DBD1B: mov eax, dword ptr [ebp - 0x6c] */
    PUSH32(esp, eax); /* 0x004DBD1E: push eax */
    RECOMP_ICALL(MEM32(0x858758)); /* 0x004DBD1F: call dword ptr [0x858758] */
    MEM32(ebp + (-0x4C)) = eax; /* 0x004DBD25: mov dword ptr [ebp - 0x4c], eax */
    /* cmp MEM32(ebp + (-0x4C)), 0xFFFFFFFFu */ /* 0x004DBD28: cmp dword ptr [ebp - 0x4c], -1 */
    if (CMP_EQ(MEM32(ebp + (-0x4C)), 0xFFFFFFFFu)) goto L_004DBD86; /* 0x004DBD2C: je 0x4dbd86 */

L_004DBD2E:
    ecx = MEM32(ebp + (-0x4C)); /* 0x004DBD2E: mov ecx, dword ptr [ebp - 0x4c] */
    PUSH32(esp, ecx); /* 0x004DBD31: push ecx */
    RECOMP_ICALL(MEM32(0x858700)); /* 0x004DBD32: call dword ptr [0x858700] */
    MEM32(ebp + (-0x54)) = eax; /* 0x004DBD38: mov dword ptr [ebp - 0x54], eax */
    /* cmp MEM32(ebp + (-0x54)), 0 */ /* 0x004DBD3B: cmp dword ptr [ebp - 0x54], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x54)), 0)) goto L_004DBD86; /* 0x004DBD3F: je 0x4dbd86 */

L_004DBD41:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD41: mov edx, dword ptr [ebp - 0x50] */
    eax = MEM32(ebp + (-0x4C)); /* 0x004DBD44: mov eax, dword ptr [ebp - 0x4c] */
    MEM32(edx) = eax; /* 0x004DBD47: mov dword ptr [edx], eax */
    ecx = MEM32(ebp + (-0x54)); /* 0x004DBD49: mov ecx, dword ptr [ebp - 0x54] */
    ecx = ecx & 0xFFu; /* 0x004DBD4C: and ecx, 0xff */
    /* cmp ecx, 2 */ /* 0x004DBD52: cmp ecx, 2 */
    if (CMP_NE(ecx, 2)) goto L_004DBD67; /* 0x004DBD55: jne 0x4dbd67 */

L_004DBD57:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD57: mov edx, dword ptr [ebp - 0x50] */
    SET_LO8(eax, MEM8(edx + 0x4)); /* 0x004DBD5A: mov al, byte ptr [edx + 4] */
    SET_LO8(eax, LO8(eax) | 0x40u); /* 0x004DBD5D: or al, 0x40 */
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBD5F: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x4) = (uint8_t)(LO8(eax)); /* 0x004DBD62: mov byte ptr [ecx + 4], al */
    goto L_004DBD84; /* 0x004DBD65: jmp 0x4dbd84 */

L_004DBD67:
    edx = MEM32(ebp + (-0x54)); /* 0x004DBD67: mov edx, dword ptr [ebp - 0x54] */
    edx = edx & 0xFFu; /* 0x004DBD6A: and edx, 0xff */
    /* cmp edx, 3 */ /* 0x004DBD70: cmp edx, 3 */
    if (CMP_NE(edx, 3)) goto L_004DBD84; /* 0x004DBD73: jne 0x4dbd84 */

L_004DBD75:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD75: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD78: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 8); /* 0x004DBD7B: or cl, 8 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD7E: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBD81: mov byte ptr [edx + 4], cl */

L_004DBD84:
    goto L_004DBD95; /* 0x004DBD84: jmp 0x4dbd95 */

L_004DBD86:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD86: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD89: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 0x40u); /* 0x004DBD8C: or cl, 0x40 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD8F: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBD92: mov byte ptr [edx + 4], cl */

L_004DBD95:
    goto L_004DBDA6; /* 0x004DBD95: jmp 0x4dbda6 */

L_004DBD97:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD97: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD9A: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 0x80u); /* 0x004DBD9D: or cl, 0x80 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBDA0: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBDA3: mov byte ptr [edx + 4], cl */

L_004DBDA6:
    goto L_004DBCC7; /* 0x004DBDA6: jmp 0x4dbcc7 */

L_004DBDAB:
    eax = MEM32(0x855D9C); /* 0x004DBDAB: mov eax, dword ptr [0x855d9c] */
    PUSH32(esp, eax); /* 0x004DBDB0: push eax */
    RECOMP_ICALL(MEM32(0x85868C)); /* 0x004DBDB1: call dword ptr [0x85868c] */
    esp = ebp; /* 0x004DBDB7: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DBDB9: pop ebp */
    return; /* 0x004DBDBA: ret  */

}

void sub_004DBC10(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DBB8F:
    edx = MEM32(ebp + (-0x5C)); /* 0x004DBB8F: mov edx, dword ptr [ebp - 0x5c] */
    edx = edx + 1; /* 0x004DBB92: add edx, 1 */
    MEM32(ebp + (-0x5C)) = edx; /* 0x004DBB95: mov dword ptr [ebp - 0x5c], edx */
    eax = MEM32(0x855D9C); /* 0x004DBB98: mov eax, dword ptr [0x855d9c] */
    /* cmp eax, MEM32(ebp + (-0x64)) */ /* 0x004DBB9D: cmp eax, dword ptr [ebp - 0x64] */
    if (CMP_GE(eax, MEM32(ebp + (-0x64)))) goto L_004DBC2D; /* 0x004DBBA0: jge 0x4dbc2d */

L_004DBBA6:
    PUSH32(esp, 0xB6u); /* 0x004DBBA6: push 0xb6 */
    PUSH32(esp, 0x004F4364u); /* 0x004DBBAB: push 0x4f4364 */
    PUSH32(esp, 2); /* 0x004DBBB0: push 2 */
    PUSH32(esp, 0x100u); /* 0x004DBBB2: push 0x100 */
    RECOMP_CALL(sub_004D25A0); /* 0x004DBBB7: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DBBBC: add esp, 0x10 */
    MEM32(ebp + (-0x50)) = eax; /* 0x004DBBBF: mov dword ptr [ebp - 0x50], eax */
    /* cmp MEM32(ebp + (-0x50)), 0 */ /* 0x004DBBC2: cmp dword ptr [ebp - 0x50], 0 */
    if (CMP_NE(MEM32(ebp + (-0x50)), 0)) goto L_004DBBD3; /* 0x004DBBC6: jne 0x4dbbd3 */

L_004DBBC8:
    ecx = MEM32(0x855D9C); /* 0x004DBBC8: mov ecx, dword ptr [0x855d9c] */
    MEM32(ebp + (-0x64)) = ecx; /* 0x004DBBCE: mov dword ptr [ebp - 0x64], ecx */
    goto L_004DBC2D; /* 0x004DBBD1: jmp 0x4dbc2d */

L_004DBBD3:
    edx = MEM32(ebp + (-0x5C)); /* 0x004DBBD3: mov edx, dword ptr [ebp - 0x5c] */
    eax = MEM32(ebp + (-0x50)); /* 0x004DBBD6: mov eax, dword ptr [ebp - 0x50] */
    MEM32(edx * 4 + 0x855C60) = eax; /* 0x004DBBD9: mov dword ptr [edx*4 + 0x855c60], eax */
    ecx = MEM32(0x855D9C); /* 0x004DBBE0: mov ecx, dword ptr [0x855d9c] */
    ecx = ecx + 0x20u; /* 0x004DBBE6: add ecx, 0x20 */
    MEM32(0x855D9C) = ecx; /* 0x004DBBE9: mov dword ptr [0x855d9c], ecx */
    goto L_004DBBFA; /* 0x004DBBEF: jmp 0x4dbbfa */

L_004DBBF1:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBBF1: mov edx, dword ptr [ebp - 0x50] */
    edx = edx + 8; /* 0x004DBBF4: add edx, 8 */
    MEM32(ebp + (-0x50)) = edx; /* 0x004DBBF7: mov dword ptr [ebp - 0x50], edx */

L_004DBBFA:
    eax = MEM32(ebp + (-0x5C)); /* 0x004DBBFA: mov eax, dword ptr [ebp - 0x5c] */
    ecx = MEM32(eax * 4 + 0x855C60); /* 0x004DBBFD: mov ecx, dword ptr [eax*4 + 0x855c60] */
    ecx = ecx + 0x100u; /* 0x004DBC04: add ecx, 0x100 */
    /* cmp MEM32(ebp + (-0x50)), ecx */ /* 0x004DBC0A: cmp dword ptr [ebp - 0x50], ecx */
    if (CMP_AE(MEM32(ebp + (-0x50)), ecx)) goto L_004DBC28; /* 0x004DBC0D: jae 0x4dbc28 */

L_004DBC0F:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBC0F: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(0); /* 0x004DBC12: mov byte ptr [edx + 4], 0 */
    eax = MEM32(ebp + (-0x50)); /* 0x004DBC16: mov eax, dword ptr [ebp - 0x50] */
    MEM32(eax) = 0xFFFFFFFFu; /* 0x004DBC19: mov dword ptr [eax], 0xffffffff */
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBC1F: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x5) = (uint8_t)(0xAu); /* 0x004DBC22: mov byte ptr [ecx + 5], 0xa */
    goto L_004DBBF1; /* 0x004DBC26: jmp 0x4dbbf1 */

L_004DBC10:
    PUSH32(esp, ebp); /* 0x004DBC10: push ebp */
    SET_LO8(eax, 0xC6u); /* 0x004DBC11: mov al, 0xc6 */
    edx = edx + 1; /* 0x004DBC13: inc edx */
    SET_LO8(eax, LO8(eax) + 0); /* 0x004DBC14: add al, 0 */
    eax = MEM32(ebp + (-0x50)); /* 0x004DBC16: mov eax, dword ptr [ebp - 0x50] */
    MEM32(eax) = 0xFFFFFFFFu; /* 0x004DBC19: mov dword ptr [eax], 0xffffffff */
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBC1F: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x5) = (uint8_t)(0xAu); /* 0x004DBC22: mov byte ptr [ecx + 5], 0xa */
    goto L_004DBBF1; /* 0x004DBC26: jmp 0x4dbbf1 */

L_004DBC28:
    goto L_004DBB8F; /* 0x004DBC28: jmp 0x4dbb8f */

L_004DBC2D:
    MEM32(ebp + (-0x58)) = 0; /* 0x004DBC2D: mov dword ptr [ebp - 0x58], 0 */
    goto L_004DBC51; /* 0x004DBC34: jmp 0x4dbc51 */

L_004DBC36:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBC36: mov edx, dword ptr [ebp - 0x58] */
    edx = edx + 1; /* 0x004DBC39: add edx, 1 */
    MEM32(ebp + (-0x58)) = edx; /* 0x004DBC3C: mov dword ptr [ebp - 0x58], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DBC3F: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DBC42: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DBC45: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + (-0x60)); /* 0x004DBC48: mov ecx, dword ptr [ebp - 0x60] */
    ecx = ecx + 4; /* 0x004DBC4B: add ecx, 4 */
    MEM32(ebp + (-0x60)) = ecx; /* 0x004DBC4E: mov dword ptr [ebp - 0x60], ecx */

L_004DBC51:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBC51: mov edx, dword ptr [ebp - 0x58] */
    /* cmp edx, MEM32(ebp + (-0x64)) */ /* 0x004DBC54: cmp edx, dword ptr [ebp - 0x64] */
    if (CMP_GE(edx, MEM32(ebp + (-0x64)))) goto L_004DBCBE; /* 0x004DBC57: jge 0x4dbcbe */

L_004DBC59:
    eax = MEM32(ebp + (-0x60)); /* 0x004DBC59: mov eax, dword ptr [ebp - 0x60] */
    /* cmp MEM32(eax), 0xFFFFFFFFu */ /* 0x004DBC5C: cmp dword ptr [eax], -1 */
    if (CMP_EQ(MEM32(eax), 0xFFFFFFFFu)) goto L_004DBCB9; /* 0x004DBC5F: je 0x4dbcb9 */

L_004DBC61:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DBC61: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DBC64: movsx edx, byte ptr [ecx] */
    edx = edx & 1; /* 0x004DBC67: and edx, 1 */
    /* test edx, edx */ /* 0x004DBC6A: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DBCB9; /* 0x004DBC6C: je 0x4dbcb9 */

L_004DBC6E:
    eax = MEM32(ebp + (-0x4)); /* 0x004DBC6E: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DBC71: movsx ecx, byte ptr [eax] */
    ecx = ecx & 8; /* 0x004DBC74: and ecx, 8 */
    /* test ecx, ecx */ /* 0x004DBC77: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DBC8B; /* 0x004DBC79: jne 0x4dbc8b */

L_004DBC7B:
    edx = MEM32(ebp + (-0x60)); /* 0x004DBC7B: mov edx, dword ptr [ebp - 0x60] */
    eax = MEM32(edx); /* 0x004DBC7E: mov eax, dword ptr [edx] */
    PUSH32(esp, eax); /* 0x004DBC80: push eax */
    RECOMP_ICALL(MEM32(0x858700)); /* 0x004DBC81: call dword ptr [0x858700] */
    /* test eax, eax */ /* 0x004DBC87: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DBCB9; /* 0x004DBC89: je 0x4dbcb9 */

L_004DBC8B:
    ecx = MEM32(ebp + (-0x58)); /* 0x004DBC8B: mov ecx, dword ptr [ebp - 0x58] */
    ecx = (uint32_t)((int32_t)ecx >> 5); /* 0x004DBC8E: sar ecx, 5 */
    edx = MEM32(ebp + (-0x58)); /* 0x004DBC91: mov edx, dword ptr [ebp - 0x58] */
    edx = edx & 0x1Fu; /* 0x004DBC94: and edx, 0x1f */
    eax = MEM32(ecx * 4 + 0x855C60); /* 0x004DBC97: mov eax, dword ptr [ecx*4 + 0x855c60] */
    ecx = eax + edx * 8; /* 0x004DBC9E: lea ecx, [eax + edx*8] */
    MEM32(ebp + (-0x50)) = ecx; /* 0x004DBCA1: mov dword ptr [ebp - 0x50], ecx */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBCA4: mov edx, dword ptr [ebp - 0x50] */
    eax = MEM32(ebp + (-0x60)); /* 0x004DBCA7: mov eax, dword ptr [ebp - 0x60] */
    ecx = MEM32(eax); /* 0x004DBCAA: mov ecx, dword ptr [eax] */
    MEM32(edx) = ecx; /* 0x004DBCAC: mov dword ptr [edx], ecx */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBCAE: mov edx, dword ptr [ebp - 0x50] */
    eax = MEM32(ebp + (-0x4)); /* 0x004DBCB1: mov eax, dword ptr [ebp - 4] */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DBCB4: mov cl, byte ptr [eax] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBCB6: mov byte ptr [edx + 4], cl */

L_004DBCB9:
    goto L_004DBC36; /* 0x004DBCB9: jmp 0x4dbc36 */

L_004DBCBE:
    MEM32(ebp + (-0x58)) = 0; /* 0x004DBCBE: mov dword ptr [ebp - 0x58], 0 */
    goto L_004DBCD0; /* 0x004DBCC5: jmp 0x4dbcd0 */

L_004DBCC7:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBCC7: mov edx, dword ptr [ebp - 0x58] */
    edx = edx + 1; /* 0x004DBCCA: add edx, 1 */
    MEM32(ebp + (-0x58)) = edx; /* 0x004DBCCD: mov dword ptr [ebp - 0x58], edx */

L_004DBCD0:
    /* cmp MEM32(ebp + (-0x58)), 3 */ /* 0x004DBCD0: cmp dword ptr [ebp - 0x58], 3 */
    if (CMP_GE(MEM32(ebp + (-0x58)), 3)) goto L_004DBDAB; /* 0x004DBCD4: jge 0x4dbdab */

L_004DBCDA:
    eax = MEM32(ebp + (-0x58)); /* 0x004DBCDA: mov eax, dword ptr [ebp - 0x58] */
    ecx = MEM32(0x855C60); /* 0x004DBCDD: mov ecx, dword ptr [0x855c60] */
    edx = ecx + eax * 8; /* 0x004DBCE3: lea edx, [ecx + eax*8] */
    MEM32(ebp + (-0x50)) = edx; /* 0x004DBCE6: mov dword ptr [ebp - 0x50], edx */
    eax = MEM32(ebp + (-0x50)); /* 0x004DBCE9: mov eax, dword ptr [ebp - 0x50] */
    /* cmp MEM32(eax), 0xFFFFFFFFu */ /* 0x004DBCEC: cmp dword ptr [eax], -1 */
    if (CMP_NE(MEM32(eax), 0xFFFFFFFFu)) goto L_004DBD97; /* 0x004DBCEF: jne 0x4dbd97 */

L_004DBCF5:
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBCF5: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x4) = (uint8_t)(0x81u); /* 0x004DBCF8: mov byte ptr [ecx + 4], 0x81 */
    /* cmp MEM32(ebp + (-0x58)), 0 */ /* 0x004DBCFC: cmp dword ptr [ebp - 0x58], 0 */
    if (CMP_NE(MEM32(ebp + (-0x58)), 0)) goto L_004DBD0B; /* 0x004DBD00: jne 0x4dbd0b */

L_004DBD02:
    MEM32(ebp + (-0x6C)) = 0xFFFFFFF6u; /* 0x004DBD02: mov dword ptr [ebp - 0x6c], 0xfffffff6 */
    goto L_004DBD1B; /* 0x004DBD09: jmp 0x4dbd1b */

L_004DBD0B:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBD0B: mov edx, dword ptr [ebp - 0x58] */
    edx = edx - 1; /* 0x004DBD0E: sub edx, 1 */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004DBD11: neg edx */
    edx = _cf ? 0xFFFFFFFFu : 0; /* 0x004DBD13: sbb edx, edx */
    edx = edx + 0xFFFFFFF5u; /* 0x004DBD15: add edx, -0xb */
    MEM32(ebp + (-0x6C)) = edx; /* 0x004DBD18: mov dword ptr [ebp - 0x6c], edx */

L_004DBD1B:
    eax = MEM32(ebp + (-0x6C)); /* 0x004DBD1B: mov eax, dword ptr [ebp - 0x6c] */
    PUSH32(esp, eax); /* 0x004DBD1E: push eax */
    RECOMP_ICALL(MEM32(0x858758)); /* 0x004DBD1F: call dword ptr [0x858758] */
    MEM32(ebp + (-0x4C)) = eax; /* 0x004DBD25: mov dword ptr [ebp - 0x4c], eax */
    /* cmp MEM32(ebp + (-0x4C)), 0xFFFFFFFFu */ /* 0x004DBD28: cmp dword ptr [ebp - 0x4c], -1 */
    if (CMP_EQ(MEM32(ebp + (-0x4C)), 0xFFFFFFFFu)) goto L_004DBD86; /* 0x004DBD2C: je 0x4dbd86 */

L_004DBD2E:
    ecx = MEM32(ebp + (-0x4C)); /* 0x004DBD2E: mov ecx, dword ptr [ebp - 0x4c] */
    PUSH32(esp, ecx); /* 0x004DBD31: push ecx */
    RECOMP_ICALL(MEM32(0x858700)); /* 0x004DBD32: call dword ptr [0x858700] */
    MEM32(ebp + (-0x54)) = eax; /* 0x004DBD38: mov dword ptr [ebp - 0x54], eax */
    /* cmp MEM32(ebp + (-0x54)), 0 */ /* 0x004DBD3B: cmp dword ptr [ebp - 0x54], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x54)), 0)) goto L_004DBD86; /* 0x004DBD3F: je 0x4dbd86 */

L_004DBD41:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD41: mov edx, dword ptr [ebp - 0x50] */
    eax = MEM32(ebp + (-0x4C)); /* 0x004DBD44: mov eax, dword ptr [ebp - 0x4c] */
    MEM32(edx) = eax; /* 0x004DBD47: mov dword ptr [edx], eax */
    ecx = MEM32(ebp + (-0x54)); /* 0x004DBD49: mov ecx, dword ptr [ebp - 0x54] */
    ecx = ecx & 0xFFu; /* 0x004DBD4C: and ecx, 0xff */
    /* cmp ecx, 2 */ /* 0x004DBD52: cmp ecx, 2 */
    if (CMP_NE(ecx, 2)) goto L_004DBD67; /* 0x004DBD55: jne 0x4dbd67 */

L_004DBD57:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD57: mov edx, dword ptr [ebp - 0x50] */
    SET_LO8(eax, MEM8(edx + 0x4)); /* 0x004DBD5A: mov al, byte ptr [edx + 4] */
    SET_LO8(eax, LO8(eax) | 0x40u); /* 0x004DBD5D: or al, 0x40 */
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBD5F: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x4) = (uint8_t)(LO8(eax)); /* 0x004DBD62: mov byte ptr [ecx + 4], al */
    goto L_004DBD84; /* 0x004DBD65: jmp 0x4dbd84 */

L_004DBD67:
    edx = MEM32(ebp + (-0x54)); /* 0x004DBD67: mov edx, dword ptr [ebp - 0x54] */
    edx = edx & 0xFFu; /* 0x004DBD6A: and edx, 0xff */
    /* cmp edx, 3 */ /* 0x004DBD70: cmp edx, 3 */
    if (CMP_NE(edx, 3)) goto L_004DBD84; /* 0x004DBD73: jne 0x4dbd84 */

L_004DBD75:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD75: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD78: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 8); /* 0x004DBD7B: or cl, 8 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD7E: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBD81: mov byte ptr [edx + 4], cl */

L_004DBD84:
    goto L_004DBD95; /* 0x004DBD84: jmp 0x4dbd95 */

L_004DBD86:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD86: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD89: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 0x40u); /* 0x004DBD8C: or cl, 0x40 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD8F: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBD92: mov byte ptr [edx + 4], cl */

L_004DBD95:
    goto L_004DBDA6; /* 0x004DBD95: jmp 0x4dbda6 */

L_004DBD97:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD97: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD9A: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 0x80u); /* 0x004DBD9D: or cl, 0x80 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBDA0: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBDA3: mov byte ptr [edx + 4], cl */

L_004DBDA6:
    goto L_004DBCC7; /* 0x004DBDA6: jmp 0x4dbcc7 */

L_004DBDAB:
    eax = MEM32(0x855D9C); /* 0x004DBDAB: mov eax, dword ptr [0x855d9c] */
    PUSH32(esp, eax); /* 0x004DBDB0: push eax */
    RECOMP_ICALL(MEM32(0x85868C)); /* 0x004DBDB1: call dword ptr [0x85868c] */
    esp = ebp; /* 0x004DBDB7: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DBDB9: pop ebp */
    return; /* 0x004DBDBA: ret  */

}

void sub_004DBC20(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DBC20:
    ebp = ebp - 1; /* 0x004DBC20: dec ebp */
    SET_LO8(eax, 0xC6u); /* 0x004DBC21: mov al, 0xc6 */
    ecx = ecx + 1; /* 0x004DBC23: inc ecx */
    eax = eax + 0xE9C9EB0Au; /* 0x004DBC24: add eax, 0xe9c9eb0a */

}

void sub_004DBD00(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DBCC7:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBCC7: mov edx, dword ptr [ebp - 0x58] */
    edx = edx + 1; /* 0x004DBCCA: add edx, 1 */
    MEM32(ebp + (-0x58)) = edx; /* 0x004DBCCD: mov dword ptr [ebp - 0x58], edx */
    /* cmp MEM32(ebp + (-0x58)), 3 */ /* 0x004DBCD0: cmp dword ptr [ebp - 0x58], 3 */
    if (CMP_GE(MEM32(ebp + (-0x58)), 3)) goto L_004DBDAB; /* 0x004DBCD4: jge 0x4dbdab */

L_004DBCDA:
    eax = MEM32(ebp + (-0x58)); /* 0x004DBCDA: mov eax, dword ptr [ebp - 0x58] */
    ecx = MEM32(0x855C60); /* 0x004DBCDD: mov ecx, dword ptr [0x855c60] */
    edx = ecx + eax * 8; /* 0x004DBCE3: lea edx, [ecx + eax*8] */
    MEM32(ebp + (-0x50)) = edx; /* 0x004DBCE6: mov dword ptr [ebp - 0x50], edx */
    eax = MEM32(ebp + (-0x50)); /* 0x004DBCE9: mov eax, dword ptr [ebp - 0x50] */
    /* cmp MEM32(eax), 0xFFFFFFFFu */ /* 0x004DBCEC: cmp dword ptr [eax], -1 */
    if (CMP_NE(MEM32(eax), 0xFFFFFFFFu)) goto L_004DBD97; /* 0x004DBCEF: jne 0x4dbd97 */

L_004DBCF5:
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBCF5: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x4) = (uint8_t)(0x81u); /* 0x004DBCF8: mov byte ptr [ecx + 4], 0x81 */
    /* cmp MEM32(ebp + (-0x58)), 0 */ /* 0x004DBCFC: cmp dword ptr [ebp - 0x58], 0 */

L_004DBD00:
    if (/* no flag state for jne */ _cf) goto L_004DBD0B; /* 0x004DBD00: jne 0x4dbd0b */

L_004DBD02:
    MEM32(ebp + (-0x6C)) = 0xFFFFFFF6u; /* 0x004DBD02: mov dword ptr [ebp - 0x6c], 0xfffffff6 */
    goto L_004DBD1B; /* 0x004DBD09: jmp 0x4dbd1b */

L_004DBD0B:
    edx = MEM32(ebp + (-0x58)); /* 0x004DBD0B: mov edx, dword ptr [ebp - 0x58] */
    edx = edx - 1; /* 0x004DBD0E: sub edx, 1 */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004DBD11: neg edx */
    edx = _cf ? 0xFFFFFFFFu : 0; /* 0x004DBD13: sbb edx, edx */
    edx = edx + 0xFFFFFFF5u; /* 0x004DBD15: add edx, -0xb */
    MEM32(ebp + (-0x6C)) = edx; /* 0x004DBD18: mov dword ptr [ebp - 0x6c], edx */

L_004DBD1B:
    eax = MEM32(ebp + (-0x6C)); /* 0x004DBD1B: mov eax, dword ptr [ebp - 0x6c] */
    PUSH32(esp, eax); /* 0x004DBD1E: push eax */
    RECOMP_ICALL(MEM32(0x858758)); /* 0x004DBD1F: call dword ptr [0x858758] */
    MEM32(ebp + (-0x4C)) = eax; /* 0x004DBD25: mov dword ptr [ebp - 0x4c], eax */
    /* cmp MEM32(ebp + (-0x4C)), 0xFFFFFFFFu */ /* 0x004DBD28: cmp dword ptr [ebp - 0x4c], -1 */
    if (CMP_EQ(MEM32(ebp + (-0x4C)), 0xFFFFFFFFu)) goto L_004DBD86; /* 0x004DBD2C: je 0x4dbd86 */

L_004DBD2E:
    ecx = MEM32(ebp + (-0x4C)); /* 0x004DBD2E: mov ecx, dword ptr [ebp - 0x4c] */
    PUSH32(esp, ecx); /* 0x004DBD31: push ecx */
    RECOMP_ICALL(MEM32(0x858700)); /* 0x004DBD32: call dword ptr [0x858700] */
    MEM32(ebp + (-0x54)) = eax; /* 0x004DBD38: mov dword ptr [ebp - 0x54], eax */
    /* cmp MEM32(ebp + (-0x54)), 0 */ /* 0x004DBD3B: cmp dword ptr [ebp - 0x54], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x54)), 0)) goto L_004DBD86; /* 0x004DBD3F: je 0x4dbd86 */

L_004DBD41:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD41: mov edx, dword ptr [ebp - 0x50] */
    eax = MEM32(ebp + (-0x4C)); /* 0x004DBD44: mov eax, dword ptr [ebp - 0x4c] */
    MEM32(edx) = eax; /* 0x004DBD47: mov dword ptr [edx], eax */
    ecx = MEM32(ebp + (-0x54)); /* 0x004DBD49: mov ecx, dword ptr [ebp - 0x54] */
    ecx = ecx & 0xFFu; /* 0x004DBD4C: and ecx, 0xff */
    /* cmp ecx, 2 */ /* 0x004DBD52: cmp ecx, 2 */
    if (CMP_NE(ecx, 2)) goto L_004DBD67; /* 0x004DBD55: jne 0x4dbd67 */

L_004DBD57:
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD57: mov edx, dword ptr [ebp - 0x50] */
    SET_LO8(eax, MEM8(edx + 0x4)); /* 0x004DBD5A: mov al, byte ptr [edx + 4] */
    SET_LO8(eax, LO8(eax) | 0x40u); /* 0x004DBD5D: or al, 0x40 */
    ecx = MEM32(ebp + (-0x50)); /* 0x004DBD5F: mov ecx, dword ptr [ebp - 0x50] */
    MEM8(ecx + 0x4) = (uint8_t)(LO8(eax)); /* 0x004DBD62: mov byte ptr [ecx + 4], al */
    goto L_004DBD84; /* 0x004DBD65: jmp 0x4dbd84 */

L_004DBD67:
    edx = MEM32(ebp + (-0x54)); /* 0x004DBD67: mov edx, dword ptr [ebp - 0x54] */
    edx = edx & 0xFFu; /* 0x004DBD6A: and edx, 0xff */
    /* cmp edx, 3 */ /* 0x004DBD70: cmp edx, 3 */
    if (CMP_NE(edx, 3)) goto L_004DBD84; /* 0x004DBD73: jne 0x4dbd84 */

L_004DBD75:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD75: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD78: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 8); /* 0x004DBD7B: or cl, 8 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD7E: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBD81: mov byte ptr [edx + 4], cl */

L_004DBD84:
    goto L_004DBD95; /* 0x004DBD84: jmp 0x4dbd95 */

L_004DBD86:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD86: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD89: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 0x40u); /* 0x004DBD8C: or cl, 0x40 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBD8F: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBD92: mov byte ptr [edx + 4], cl */

L_004DBD95:
    goto L_004DBDA6; /* 0x004DBD95: jmp 0x4dbda6 */

L_004DBD97:
    eax = MEM32(ebp + (-0x50)); /* 0x004DBD97: mov eax, dword ptr [ebp - 0x50] */
    SET_LO8(ecx, MEM8(eax + 0x4)); /* 0x004DBD9A: mov cl, byte ptr [eax + 4] */
    SET_LO8(ecx, LO8(ecx) | 0x80u); /* 0x004DBD9D: or cl, 0x80 */
    edx = MEM32(ebp + (-0x50)); /* 0x004DBDA0: mov edx, dword ptr [ebp - 0x50] */
    MEM8(edx + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004DBDA3: mov byte ptr [edx + 4], cl */

L_004DBDA6:
    goto L_004DBCC7; /* 0x004DBDA6: jmp 0x4dbcc7 */

L_004DBDAB:
    eax = MEM32(0x855D9C); /* 0x004DBDAB: mov eax, dword ptr [0x855d9c] */
    PUSH32(esp, eax); /* 0x004DBDB0: push eax */
    RECOMP_ICALL(MEM32(0x85868C)); /* 0x004DBDB1: call dword ptr [0x85868c] */
    esp = ebp; /* 0x004DBDB7: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DBDB9: pop ebp */
    return; /* 0x004DBDBA: ret  */

}

void sub_004DBE60(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DBE60:
    edx = MEM32(ebp + 0x8); /* 0x004DBE60: mov edx, dword ptr [ebp + 8] */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DBE63: mov dword ptr [ebp - 4], edx */
    PUSH32(esp, 0x3Bu); /* 0x004DBE66: push 0x3b */
    PUSH32(esp, 0x004F4370u); /* 0x004DBE68: push 0x4f4370 */
    PUSH32(esp, 2); /* 0x004DBE6D: push 2 */
    PUSH32(esp, 0x1000u); /* 0x004DBE6F: push 0x1000 */
    RECOMP_CALL(sub_004D25A0); /* 0x004DBE74: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DBE79: add esp, 0x10 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DBE7C: mov ecx, dword ptr [ebp - 4] */
    MEM32(ecx + 0x8) = eax; /* 0x004DBE7F: mov dword ptr [ecx + 8], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004DBE82: mov edx, dword ptr [ebp - 4] */
    /* cmp MEM32(edx + 0x8), 0 */ /* 0x004DBE85: cmp dword ptr [edx + 8], 0 */
    if (CMP_EQ(MEM32(edx + 0x8), 0)) goto L_004DBEA6; /* 0x004DBE89: je 0x4dbea6 */

L_004DBE8B:
    eax = MEM32(ebp + (-0x4)); /* 0x004DBE8B: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(eax + 0xC); /* 0x004DBE8E: mov ecx, dword ptr [eax + 0xc] */
    ecx = ecx | 8; /* 0x004DBE91: or ecx, 8 */
    edx = MEM32(ebp + (-0x4)); /* 0x004DBE94: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0xC) = ecx; /* 0x004DBE97: mov dword ptr [edx + 0xc], ecx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DBE9A: mov eax, dword ptr [ebp - 4] */
    MEM32(eax + 0x18) = 0x1000u; /* 0x004DBE9D: mov dword ptr [eax + 0x18], 0x1000 */
    goto L_004DBECB; /* 0x004DBEA4: jmp 0x4dbecb */

L_004DBEA6:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DBEA6: mov ecx, dword ptr [ebp - 4] */
    edx = MEM32(ecx + 0xC); /* 0x004DBEA9: mov edx, dword ptr [ecx + 0xc] */
    edx = edx | 4; /* 0x004DBEAC: or edx, 4 */
    eax = MEM32(ebp + (-0x4)); /* 0x004DBEAF: mov eax, dword ptr [ebp - 4] */
    MEM32(eax + 0xC) = edx; /* 0x004DBEB2: mov dword ptr [eax + 0xc], edx */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DBEB5: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 0x14u; /* 0x004DBEB8: add ecx, 0x14 */
    edx = MEM32(ebp + (-0x4)); /* 0x004DBEBB: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0x8) = ecx; /* 0x004DBEBE: mov dword ptr [edx + 8], ecx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DBEC1: mov eax, dword ptr [ebp - 4] */
    MEM32(eax + 0x18) = 2; /* 0x004DBEC4: mov dword ptr [eax + 0x18], 2 */

L_004DBECB:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DBECB: mov ecx, dword ptr [ebp - 4] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DBECE: mov edx, dword ptr [ebp - 4] */
    eax = MEM32(edx + 0x8); /* 0x004DBED1: mov eax, dword ptr [edx + 8] */
    MEM32(ecx) = eax; /* 0x004DBED4: mov dword ptr [ecx], eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DBED6: mov ecx, dword ptr [ebp - 4] */
    MEM32(ecx + 0x4) = 0; /* 0x004DBED9: mov dword ptr [ecx + 4], 0 */
    edi = POP32_VAL(esp); /* 0x004DBEE0: pop edi */
    esi = POP32_VAL(esp); /* 0x004DBEE1: pop esi */
    ebx = POP32_VAL(esp); /* 0x004DBEE2: pop ebx */
    esp = ebp; /* 0x004DBEE3: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DBEE5: pop ebp */
    return; /* 0x004DBEE6: ret  */

}

void sub_004DC010(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DC010:
    PUSH32(esp, _seg_cs); /* 0x004DC010: push cs */
    /* cmp MEM32(ebp + 0x8), 4 */ /* 0x004DC011: cmp dword ptr [ebp + 8], 4 */
    if (CMP_EQ(MEM32(ebp + 0x8), 4)) goto L_004DC01F; /* 0x004DC015: je 0x4dc01f */

L_004DC017:
    /* cmp MEM32(ebp + 0x8), 0xBu */ /* 0x004DC017: cmp dword ptr [ebp + 8], 0xb */
    if (CMP_EQ(MEM32(ebp + 0x8), 0xBu)) goto L_004DC01F; /* 0x004DC01B: je 0x4dc01f */

L_004DC01D:
    goto L_004DC079; /* 0x004DC01D: jmp 0x4dc079 */

L_004DC01F:
    eax = MEM32(ebp + 0x8); /* 0x004DC01F: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004DC022: push eax */
    RECOMP_CALL(sub_004DC2F0); /* 0x004DC023: call 0x4dc2f0 */
    esp = esp + 4; /* 0x004DC028: add esp, 4 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DC02B: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DC02E: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004DC036; /* 0x004DC032: jne 0x4dc036 */

L_004DC034:
    goto L_004DC079; /* 0x004DC034: jmp 0x4dc079 */

L_004DC036:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC036: mov ecx, dword ptr [ebp - 4] */
    edx = MEM32(ecx + 0x8); /* 0x004DC039: mov edx, dword ptr [ecx + 8] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DC03C: mov dword ptr [ebp - 8], edx */

L_004DC03F:
    eax = MEM32(ebp + (-0x4)); /* 0x004DC03F: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(eax + 0x4); /* 0x004DC042: mov ecx, dword ptr [eax + 4] */
    /* cmp ecx, MEM32(ebp + 0x8) */ /* 0x004DC045: cmp ecx, dword ptr [ebp + 8] */
    if (CMP_NE(ecx, MEM32(ebp + 0x8))) goto L_004DC074; /* 0x004DC048: jne 0x4dc074 */

L_004DC04A:
    edx = MEM32(ebp + (-0x4)); /* 0x004DC04A: mov edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + 0xC); /* 0x004DC04D: mov eax, dword ptr [ebp + 0xc] */
    MEM32(edx + 0x8) = eax; /* 0x004DC050: mov dword ptr [edx + 8], eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC053: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 0xCu; /* 0x004DC056: add ecx, 0xc */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DC059: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(0x50B700); /* 0x004DC05C: mov edx, dword ptr [0x50b700] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0xCu); /* 0x004DC062: imul edx, edx, 0xc */
    edx = edx + 0x0050B680u; /* 0x004DC065: add edx, 0x50b680 */
    /* cmp MEM32(ebp + (-0x4)), edx */ /* 0x004DC06B: cmp dword ptr [ebp - 4], edx */
    if (CMP_B(MEM32(ebp + (-0x4)), edx)) goto L_004DC072; /* 0x004DC06E: jb 0x4dc072 */

L_004DC070:
    goto L_004DC074; /* 0x004DC070: jmp 0x4dc074 */

L_004DC072:
    goto L_004DC03F; /* 0x004DC072: jmp 0x4dc03f */

L_004DC074:
    eax = MEM32(ebp + (-0x8)); /* 0x004DC074: mov eax, dword ptr [ebp - 8] */
    goto L_004DC086; /* 0x004DC077: jmp 0x4dc086 */

L_004DC079:
    MEM32(0x84B7AC) = 0x16u; /* 0x004DC079: mov dword ptr [0x84b7ac], 0x16 */
    eax = eax | 0xFFFFFFFFu; /* 0x004DC083: or eax, 0xffffffff */

L_004DC086:
    esp = ebp; /* 0x004DC086: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DC088: pop ebp */
    return; /* 0x004DC089: ret  */

}

void sub_004DC170(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

}

void sub_004DC1F0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DC1F0:
    MEM8(esi * 2 + (-0x47875ED5)) = (uint8_t)(MEM8(esi * 2 + (-0x47875ED5)) | LO8(eax)); /* 0x004DC1F0: or byte ptr [esi*2 - 0x47875ed5], al */
    /* test MEM8(eax), LO8(eax) */ /* 0x004DC1F7: test byte ptr [eax], al */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DC1F9: mov dword ptr [ebp - 0xc], eax */
    MEM32(0x84B878) = 0; /* 0x004DC1FC: mov dword ptr [0x84b878], 0 */
    /* cmp MEM32(ebp + 0x8), 8 */ /* 0x004DC206: cmp dword ptr [ebp + 8], 8 */
    if (CMP_NE(MEM32(ebp + 0x8), 8)) goto L_004DC21F; /* 0x004DC20A: jne 0x4dc21f */

L_004DC20C:
    ecx = MEM32(0x50B704); /* 0x004DC20C: mov ecx, dword ptr [0x50b704] */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DC212: mov dword ptr [ebp - 4], ecx */
    MEM32(0x50B704) = 0x8Cu; /* 0x004DC215: mov dword ptr [0x50b704], 0x8c */

L_004DC21F:
    /* cmp MEM32(ebp + 0x8), 8 */ /* 0x004DC21F: cmp dword ptr [ebp + 8], 8 */
    if (CMP_NE(MEM32(ebp + 0x8), 8)) goto L_004DC25E; /* 0x004DC223: jne 0x4dc25e */

L_004DC225:
    edx = MEM32(0x50B6F8); /* 0x004DC225: mov edx, dword ptr [0x50b6f8] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DC22B: mov dword ptr [ebp - 8], edx */
    goto L_004DC239; /* 0x004DC22E: jmp 0x4dc239 */

L_004DC230:
    eax = MEM32(ebp + (-0x8)); /* 0x004DC230: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DC233: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DC236: mov dword ptr [ebp - 8], eax */

L_004DC239:
    ecx = MEM32(0x50B6F8); /* 0x004DC239: mov ecx, dword ptr [0x50b6f8] */
    ecx = ecx + MEM32(0x50B6FC); /* 0x004DC23F: add ecx, dword ptr [0x50b6fc] */
    /* cmp MEM32(ebp + (-0x8)), ecx */ /* 0x004DC245: cmp dword ptr [ebp - 8], ecx */
    if (CMP_GE(MEM32(ebp + (-0x8)), ecx)) goto L_004DC25C; /* 0x004DC248: jge 0x4dc25c */

L_004DC24A:
    edx = MEM32(ebp + (-0x8)); /* 0x004DC24A: mov edx, dword ptr [ebp - 8] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0xCu); /* 0x004DC24D: imul edx, edx, 0xc */
    MEM32(edx + 0x50B688) = 0; /* 0x004DC250: mov dword ptr [edx + 0x50b688], 0 */
    goto L_004DC230; /* 0x004DC25A: jmp 0x4dc230 */

L_004DC25C:
    goto L_004DC267; /* 0x004DC25C: jmp 0x4dc267 */

L_004DC25E:
    eax = MEM32(ebp + (-0x10)); /* 0x004DC25E: mov eax, dword ptr [ebp - 0x10] */
    MEM32(eax) = 0; /* 0x004DC261: mov dword ptr [eax], 0 */

L_004DC267:
    /* cmp MEM32(ebp + 0x8), 8 */ /* 0x004DC267: cmp dword ptr [ebp + 8], 8 */
    if (CMP_NE(MEM32(ebp + 0x8), 8)) goto L_004DC27E; /* 0x004DC26B: jne 0x4dc27e */

L_004DC26D:
    ecx = MEM32(0x50B704); /* 0x004DC26D: mov ecx, dword ptr [0x50b704] */
    PUSH32(esp, ecx); /* 0x004DC273: push ecx */
    PUSH32(esp, 8); /* 0x004DC274: push 8 */
    RECOMP_ICALL(MEM32(ebp + (-0x14))); /* 0x004DC276: call dword ptr [ebp - 0x14] */
    esp = esp + 8; /* 0x004DC279: add esp, 8 */
    goto L_004DC288; /* 0x004DC27C: jmp 0x4dc288 */

L_004DC27E:
    edx = MEM32(ebp + 0x8); /* 0x004DC27E: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004DC281: push edx */
    RECOMP_ICALL(MEM32(ebp + (-0x14))); /* 0x004DC282: call dword ptr [ebp - 0x14] */
    esp = esp + 4; /* 0x004DC285: add esp, 4 */

L_004DC288:
    /* cmp MEM32(ebp + 0x8), 8 */ /* 0x004DC288: cmp dword ptr [ebp + 8], 8 */
    if (CMP_EQ(MEM32(ebp + 0x8), 8)) goto L_004DC29A; /* 0x004DC28C: je 0x4dc29a */

L_004DC28E:
    /* cmp MEM32(ebp + 0x8), 0xBu */ /* 0x004DC28E: cmp dword ptr [ebp + 8], 0xb */
    if (CMP_EQ(MEM32(ebp + 0x8), 0xBu)) goto L_004DC29A; /* 0x004DC292: je 0x4dc29a */

L_004DC294:
    /* cmp MEM32(ebp + 0x8), 4 */ /* 0x004DC294: cmp dword ptr [ebp + 8], 4 */
    if (CMP_NE(MEM32(ebp + 0x8), 4)) goto L_004DC2B1; /* 0x004DC298: jne 0x4dc2b1 */

L_004DC29A:
    eax = MEM32(ebp + (-0xC)); /* 0x004DC29A: mov eax, dword ptr [ebp - 0xc] */
    MEM32(0x84B878) = eax; /* 0x004DC29D: mov dword ptr [0x84b878], eax */
    /* cmp MEM32(ebp + 0x8), 8 */ /* 0x004DC2A2: cmp dword ptr [ebp + 8], 8 */
    if (CMP_NE(MEM32(ebp + 0x8), 8)) goto L_004DC2B1; /* 0x004DC2A6: jne 0x4dc2b1 */

L_004DC2A8:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC2A8: mov ecx, dword ptr [ebp - 4] */
    MEM32(0x50B704) = ecx; /* 0x004DC2AB: mov dword ptr [0x50b704], ecx */

L_004DC2B1:
    eax = 0; /* 0x004DC2B1: xor eax, eax */
    esp = ebp; /* 0x004DC2B3: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DC2B5: pop ebp */
    return; /* 0x004DC2B6: ret  */

}

void sub_004DC260(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

}

void sub_004DC3A0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DC3A0:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DC3A0: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DC3A3: push ecx */
    RECOMP_ICALL(MEM32(0x858738)); /* 0x004DC3A4: call dword ptr [0x858738] */
    MEM32(0x84B870) = eax; /* 0x004DC3AA: mov dword ptr [0x84b870], eax */
    PUSH32(esp, 0x004F437Cu); /* 0x004DC3AF: push 0x4f437c */
    edx = MEM32(ebp + (-0x8)); /* 0x004DC3B4: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DC3B7: push edx */
    RECOMP_ICALL(MEM32(0x858738)); /* 0x004DC3B8: call dword ptr [0x858738] */
    MEM32(0x84B874) = eax; /* 0x004DC3BE: mov dword ptr [0x84b874], eax */
    /* cmp MEM32(0x84B870), 0 */ /* 0x004DC3C3: cmp dword ptr [0x84b870], 0 */
    if (CMP_EQ(MEM32(0x84B870), 0)) goto L_004DC3D5; /* 0x004DC3CA: je 0x4dc3d5 */

L_004DC3CC:
    RECOMP_ICALL(MEM32(0x84B870)); /* 0x004DC3CC: call dword ptr [0x84b870] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DC3D2: mov dword ptr [ebp - 4], eax */

L_004DC3D5:
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DC3D5: cmp dword ptr [ebp - 4], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0)) goto L_004DC3F1; /* 0x004DC3D9: je 0x4dc3f1 */

L_004DC3DB:
    /* cmp MEM32(0x84B874), 0 */ /* 0x004DC3DB: cmp dword ptr [0x84b874], 0 */
    if (CMP_EQ(MEM32(0x84B874), 0)) goto L_004DC3F1; /* 0x004DC3E2: je 0x4dc3f1 */

L_004DC3E4:
    eax = MEM32(ebp + (-0x4)); /* 0x004DC3E4: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004DC3E7: push eax */
    RECOMP_ICALL(MEM32(0x84B874)); /* 0x004DC3E8: call dword ptr [0x84b874] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DC3EE: mov dword ptr [ebp - 4], eax */

L_004DC3F1:
    ecx = MEM32(ebp + 0x10); /* 0x004DC3F1: mov ecx, dword ptr [ebp + 0x10] */
    PUSH32(esp, ecx); /* 0x004DC3F4: push ecx */
    edx = MEM32(ebp + 0xC); /* 0x004DC3F5: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004DC3F8: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004DC3F9: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004DC3FC: push eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC3FD: mov ecx, dword ptr [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004DC400: push ecx */
    RECOMP_ICALL(MEM32(0x84B86C)); /* 0x004DC401: call dword ptr [0x84b86c] */
    esp = ebp; /* 0x004DC407: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DC409: pop ebp */
    return; /* 0x004DC40A: ret  */

}

void sub_004DC470(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DC470:
    if (/* no flag state for je */ _cf) goto L_004DC489; /* 0x004DC470: je 0x4dc489 */

L_004DC472:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC472: mov ecx, dword ptr [ebp - 4] */
    MEM8(ecx) = (uint8_t)(0x2Du); /* 0x004DC475: mov byte ptr [ecx], 0x2d */
    edx = MEM32(ebp + (-0x4)); /* 0x004DC478: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DC47B: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DC47E: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + 0x8); /* 0x004DC481: mov eax, dword ptr [ebp + 8] */
    eax = (uint32_t)(-(int32_t)eax); /* 0x004DC484: neg eax */
    MEM32(ebp + 0x8) = eax; /* 0x004DC486: mov dword ptr [ebp + 8], eax */

L_004DC489:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC489: mov ecx, dword ptr [ebp - 4] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DC48C: mov dword ptr [ebp - 8], ecx */

L_004DC48F:
    eax = MEM32(ebp + 0x8); /* 0x004DC48F: mov eax, dword ptr [ebp + 8] */
    edx = 0; /* 0x004DC492: xor edx, edx */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax; /* 0x004DC494: div dword ptr [ebp + 0x10] */
      eax = (uint32_t)(_dividend / (uint32_t)MEM32(ebp + 0x10));
      edx = (uint32_t)(_dividend % (uint32_t)MEM32(ebp + 0x10)); }
    MEM32(ebp + (-0xC)) = edx; /* 0x004DC497: mov dword ptr [ebp - 0xc], edx */
    eax = MEM32(ebp + 0x8); /* 0x004DC49A: mov eax, dword ptr [ebp + 8] */
    edx = 0; /* 0x004DC49D: xor edx, edx */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax; /* 0x004DC49F: div dword ptr [ebp + 0x10] */
      eax = (uint32_t)(_dividend / (uint32_t)MEM32(ebp + 0x10));
      edx = (uint32_t)(_dividend % (uint32_t)MEM32(ebp + 0x10)); }
    MEM32(ebp + 0x8) = eax; /* 0x004DC4A2: mov dword ptr [ebp + 8], eax */
    /* cmp MEM32(ebp + (-0xC)), 9 */ /* 0x004DC4A5: cmp dword ptr [ebp - 0xc], 9 */
    if (CMP_BE(MEM32(ebp + (-0xC)), 9)) goto L_004DC4C1; /* 0x004DC4A9: jbe 0x4dc4c1 */

L_004DC4AB:
    edx = MEM32(ebp + (-0xC)); /* 0x004DC4AB: mov edx, dword ptr [ebp - 0xc] */
    edx = edx + 0x57u; /* 0x004DC4AE: add edx, 0x57 */
    eax = MEM32(ebp + (-0x4)); /* 0x004DC4B1: mov eax, dword ptr [ebp - 4] */
    MEM8(eax) = (uint8_t)(LO8(edx)); /* 0x004DC4B4: mov byte ptr [eax], dl */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC4B6: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DC4B9: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DC4BC: mov dword ptr [ebp - 4], ecx */
    goto L_004DC4D5; /* 0x004DC4BF: jmp 0x4dc4d5 */

L_004DC4C1:
    edx = MEM32(ebp + (-0xC)); /* 0x004DC4C1: mov edx, dword ptr [ebp - 0xc] */
    edx = edx + 0x30u; /* 0x004DC4C4: add edx, 0x30 */
    eax = MEM32(ebp + (-0x4)); /* 0x004DC4C7: mov eax, dword ptr [ebp - 4] */
    MEM8(eax) = (uint8_t)(LO8(edx)); /* 0x004DC4CA: mov byte ptr [eax], dl */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC4CC: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DC4CF: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DC4D2: mov dword ptr [ebp - 4], ecx */

L_004DC4D5:
    /* cmp MEM32(ebp + 0x8), 0 */ /* 0x004DC4D5: cmp dword ptr [ebp + 8], 0 */
    if (CMP_A(MEM32(ebp + 0x8), 0)) goto L_004DC48F; /* 0x004DC4D9: ja 0x4dc48f */

L_004DC4DB:
    edx = MEM32(ebp + (-0x4)); /* 0x004DC4DB: mov edx, dword ptr [ebp - 4] */
    MEM8(edx) = (uint8_t)(0); /* 0x004DC4DE: mov byte ptr [edx], 0 */
    eax = MEM32(ebp + (-0x4)); /* 0x004DC4E1: mov eax, dword ptr [ebp - 4] */
    eax = eax - 1; /* 0x004DC4E4: sub eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DC4E7: mov dword ptr [ebp - 4], eax */

L_004DC4EA:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC4EA: mov ecx, dword ptr [ebp - 4] */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DC4ED: mov dl, byte ptr [ecx] */
    MEM8(ebp + (-0x10)) = (uint8_t)(LO8(edx)); /* 0x004DC4EF: mov byte ptr [ebp - 0x10], dl */
    eax = MEM32(ebp + (-0x4)); /* 0x004DC4F2: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DC4F5: mov ecx, dword ptr [ebp - 8] */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DC4F8: mov dl, byte ptr [ecx] */
    MEM8(eax) = (uint8_t)(LO8(edx)); /* 0x004DC4FA: mov byte ptr [eax], dl */
    eax = MEM32(ebp + (-0x8)); /* 0x004DC4FC: mov eax, dword ptr [ebp - 8] */
    SET_LO8(ecx, MEM8(ebp + (-0x10))); /* 0x004DC4FF: mov cl, byte ptr [ebp - 0x10] */
    MEM8(eax) = (uint8_t)(LO8(ecx)); /* 0x004DC502: mov byte ptr [eax], cl */
    edx = MEM32(ebp + (-0x4)); /* 0x004DC504: mov edx, dword ptr [ebp - 4] */
    edx = edx - 1; /* 0x004DC507: sub edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DC50A: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + (-0x8)); /* 0x004DC50D: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DC510: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DC513: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DC516: mov ecx, dword ptr [ebp - 8] */
    /* cmp ecx, MEM32(ebp + (-0x4)) */ /* 0x004DC519: cmp ecx, dword ptr [ebp - 4] */
    if (CMP_B(ecx, MEM32(ebp + (-0x4)))) goto L_004DC4EA; /* 0x004DC51C: jb 0x4dc4ea */

L_004DC51E:
    esp = ebp; /* 0x004DC51E: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DC520: pop ebp */
    return; /* 0x004DC521: ret  */

}

void sub_004DC616(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DC607:
    ecx = MEM32(ebp + 0x14); /* 0x004DC607: mov ecx, dword ptr [ebp + 0x14] */
    edx = 0; /* 0x004DC60A: xor edx, edx */
    PUSH32(esp, edx); /* 0x004DC60C: push edx */
    PUSH32(esp, ecx); /* 0x004DC60D: push ecx */
    eax = MEM32(ebp + 0xC); /* 0x004DC60E: mov eax, dword ptr [ebp + 0xc] */
    PUSH32(esp, eax); /* 0x004DC611: push eax */
    ecx = MEM32(ebp + 0x8); /* 0x004DC612: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004DC615: push ecx */

L_004DC616:
    RECOMP_CALL(sub_004DF4A0); /* 0x004DC616: call 0x4df4a0 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DC61B: mov dword ptr [ebp - 0xc], eax */
    edx = MEM32(ebp + 0x14); /* 0x004DC61E: mov edx, dword ptr [ebp + 0x14] */
    eax = 0; /* 0x004DC621: xor eax, eax */
    PUSH32(esp, eax); /* 0x004DC623: push eax */
    PUSH32(esp, edx); /* 0x004DC624: push edx */
    ecx = MEM32(ebp + 0xC); /* 0x004DC625: mov ecx, dword ptr [ebp + 0xc] */
    PUSH32(esp, ecx); /* 0x004DC628: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004DC629: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004DC62C: push edx */
    RECOMP_CALL(sub_004DF430); /* 0x004DC62D: call 0x4df430 */
    MEM32(ebp + 0x8) = eax; /* 0x004DC632: mov dword ptr [ebp + 8], eax */
    MEM32(ebp + 0xC) = edx; /* 0x004DC635: mov dword ptr [ebp + 0xc], edx */
    /* cmp MEM32(ebp + (-0xC)), 9 */ /* 0x004DC638: cmp dword ptr [ebp - 0xc], 9 */
    if (CMP_BE(MEM32(ebp + (-0xC)), 9)) goto L_004DC654; /* 0x004DC63C: jbe 0x4dc654 */

L_004DC63E:
    eax = MEM32(ebp + (-0xC)); /* 0x004DC63E: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 0x57u; /* 0x004DC641: add eax, 0x57 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC644: mov ecx, dword ptr [ebp - 4] */
    MEM8(ecx) = (uint8_t)(LO8(eax)); /* 0x004DC647: mov byte ptr [ecx], al */
    edx = MEM32(ebp + (-0x4)); /* 0x004DC649: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DC64C: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DC64F: mov dword ptr [ebp - 4], edx */
    goto L_004DC668; /* 0x004DC652: jmp 0x4dc668 */

L_004DC654:
    eax = MEM32(ebp + (-0xC)); /* 0x004DC654: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 0x30u; /* 0x004DC657: add eax, 0x30 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC65A: mov ecx, dword ptr [ebp - 4] */
    MEM8(ecx) = (uint8_t)(LO8(eax)); /* 0x004DC65D: mov byte ptr [ecx], al */
    edx = MEM32(ebp + (-0x4)); /* 0x004DC65F: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DC662: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DC665: mov dword ptr [ebp - 4], edx */

L_004DC668:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004DC668: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_A(MEM32(ebp + 0xC), 0)) goto L_004DC607; /* 0x004DC66C: ja 0x4dc607 */

L_004DC66E:
    if (/* no flag state for jb */ _cf) goto L_004DC676; /* 0x004DC66E: jb 0x4dc676 */

L_004DC670:
    /* cmp MEM32(ebp + 0x8), 0 */ /* 0x004DC670: cmp dword ptr [ebp + 8], 0 */
    if (CMP_A(MEM32(ebp + 0x8), 0)) goto L_004DC607; /* 0x004DC674: ja 0x4dc607 */

L_004DC676:
    eax = MEM32(ebp + (-0x4)); /* 0x004DC676: mov eax, dword ptr [ebp - 4] */
    MEM8(eax) = (uint8_t)(0); /* 0x004DC679: mov byte ptr [eax], 0 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC67C: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx - 1; /* 0x004DC67F: sub ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DC682: mov dword ptr [ebp - 4], ecx */

L_004DC685:
    edx = MEM32(ebp + (-0x4)); /* 0x004DC685: mov edx, dword ptr [ebp - 4] */
    SET_LO8(eax, MEM8(edx)); /* 0x004DC688: mov al, byte ptr [edx] */
    MEM8(ebp + (-0x10)) = (uint8_t)(LO8(eax)); /* 0x004DC68A: mov byte ptr [ebp - 0x10], al */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DC68D: mov ecx, dword ptr [ebp - 4] */
    edx = MEM32(ebp + (-0x8)); /* 0x004DC690: mov edx, dword ptr [ebp - 8] */
    SET_LO8(eax, MEM8(edx)); /* 0x004DC693: mov al, byte ptr [edx] */
    MEM8(ecx) = (uint8_t)(LO8(eax)); /* 0x004DC695: mov byte ptr [ecx], al */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DC697: mov ecx, dword ptr [ebp - 8] */
    SET_LO8(edx, MEM8(ebp + (-0x10))); /* 0x004DC69A: mov dl, byte ptr [ebp - 0x10] */
    MEM8(ecx) = (uint8_t)(LO8(edx)); /* 0x004DC69D: mov byte ptr [ecx], dl */
    eax = MEM32(ebp + (-0x4)); /* 0x004DC69F: mov eax, dword ptr [ebp - 4] */
    eax = eax - 1; /* 0x004DC6A2: sub eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DC6A5: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DC6A8: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DC6AB: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DC6AE: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DC6B1: mov edx, dword ptr [ebp - 8] */
    /* cmp edx, MEM32(ebp + (-0x4)) */ /* 0x004DC6B4: cmp edx, dword ptr [ebp - 4] */
    if (CMP_B(edx, MEM32(ebp + (-0x4)))) goto L_004DC685; /* 0x004DC6B7: jb 0x4dc685 */

L_004DC6B9:
    esp = ebp; /* 0x004DC6B9: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DC6BB: pop ebp */
    esp += 20; return; /* 0x004DC6BC: ret 0x14 */

}

void sub_004DCB20(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DCB20:
    SET_LO8(eax, LO8(eax) + 0xB7u); /* 0x004DCB20: add al, 0xb7 */
    PUSH32(esp, eax); /* 0x004DCB22: push eax */
    MEM8(ecx + 0x4D8BF845) = (uint8_t)(MEM8(ecx + 0x4D8BF845) + LO8(ecx)); /* 0x004DCB23: add byte ptr [ecx + 0x4d8bf845], cl */
    /* UNIMPLEMENTED: hlt  */ /* 0x004DCB29: hlt  */
    /* cmp MEM32(ecx), 0xC000008Eu */ /* 0x004DCB2A: cmp dword ptr [ecx], 0xc000008e */
    if (CMP_NE(MEM32(ecx), 0xC000008Eu)) goto L_004DCB41; /* 0x004DCB30: jne 0x4dcb41 */

L_004DCB32:
    MEM32(0x50B704) = 0x83u; /* 0x004DCB32: mov dword ptr [0x50b704], 0x83 */
    goto L_004DCBC9; /* 0x004DCB3C: jmp 0x4dcbc9 */

L_004DCB41:
    edx = MEM32(ebp + (-0xC)); /* 0x004DCB41: mov edx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(edx), 0xC0000090u */ /* 0x004DCB44: cmp dword ptr [edx], 0xc0000090 */
    if (CMP_NE(MEM32(edx), 0xC0000090u)) goto L_004DCB58; /* 0x004DCB4A: jne 0x4dcb58 */

L_004DCB4C:
    MEM32(0x50B704) = 0x81u; /* 0x004DCB4C: mov dword ptr [0x50b704], 0x81 */
    goto L_004DCBC9; /* 0x004DCB56: jmp 0x4dcbc9 */

L_004DCB58:
    eax = MEM32(ebp + (-0xC)); /* 0x004DCB58: mov eax, dword ptr [ebp - 0xc] */
    /* cmp MEM32(eax), 0xC0000091u */ /* 0x004DCB5B: cmp dword ptr [eax], 0xc0000091 */
    if (CMP_NE(MEM32(eax), 0xC0000091u)) goto L_004DCB6F; /* 0x004DCB61: jne 0x4dcb6f */

L_004DCB63:
    MEM32(0x50B704) = 0x84u; /* 0x004DCB63: mov dword ptr [0x50b704], 0x84 */
    goto L_004DCBC9; /* 0x004DCB6D: jmp 0x4dcbc9 */

L_004DCB6F:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DCB6F: mov ecx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(ecx), 0xC0000093u */ /* 0x004DCB72: cmp dword ptr [ecx], 0xc0000093 */
    if (CMP_NE(MEM32(ecx), 0xC0000093u)) goto L_004DCB86; /* 0x004DCB78: jne 0x4dcb86 */

L_004DCB7A:
    MEM32(0x50B704) = 0x85u; /* 0x004DCB7A: mov dword ptr [0x50b704], 0x85 */
    goto L_004DCBC9; /* 0x004DCB84: jmp 0x4dcbc9 */

L_004DCB86:
    edx = MEM32(ebp + (-0xC)); /* 0x004DCB86: mov edx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(edx), 0xC000008Du */ /* 0x004DCB89: cmp dword ptr [edx], 0xc000008d */
    if (CMP_NE(MEM32(edx), 0xC000008Du)) goto L_004DCB9D; /* 0x004DCB8F: jne 0x4dcb9d */

L_004DCB91:
    MEM32(0x50B704) = 0x82u; /* 0x004DCB91: mov dword ptr [0x50b704], 0x82 */
    goto L_004DCBC9; /* 0x004DCB9B: jmp 0x4dcbc9 */

L_004DCB9D:
    eax = MEM32(ebp + (-0xC)); /* 0x004DCB9D: mov eax, dword ptr [ebp - 0xc] */
    /* cmp MEM32(eax), 0xC000008Fu */ /* 0x004DCBA0: cmp dword ptr [eax], 0xc000008f */
    if (CMP_NE(MEM32(eax), 0xC000008Fu)) goto L_004DCBB4; /* 0x004DCBA6: jne 0x4dcbb4 */

L_004DCBA8:
    MEM32(0x50B704) = 0x86u; /* 0x004DCBA8: mov dword ptr [0x50b704], 0x86 */
    goto L_004DCBC9; /* 0x004DCBB2: jmp 0x4dcbc9 */

L_004DCBB4:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DCBB4: mov ecx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(ecx), 0xC0000092u */ /* 0x004DCBB7: cmp dword ptr [ecx], 0xc0000092 */
    if (CMP_NE(MEM32(ecx), 0xC0000092u)) goto L_004DCBC9; /* 0x004DCBBD: jne 0x4dcbc9 */

L_004DCBBF:
    MEM32(0x50B704) = 0x8Au; /* 0x004DCBBF: mov dword ptr [0x50b704], 0x8a */

L_004DCBC9:
    edx = MEM32(0x50B704); /* 0x004DCBC9: mov edx, dword ptr [0x50b704] */
    PUSH32(esp, edx); /* 0x004DCBCF: push edx */
    PUSH32(esp, 8); /* 0x004DCBD0: push 8 */
    RECOMP_ICALL(MEM32(ebp + (-0x4))); /* 0x004DCBD2: call dword ptr [ebp - 4] */
    esp = esp + 8; /* 0x004DCBD5: add esp, 8 */
    eax = MEM32(ebp + (-0x8)); /* 0x004DCBD8: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B704) = eax; /* 0x004DCBDB: mov dword ptr [0x50b704], eax */
    goto L_004DCBF9; /* 0x004DCBE0: jmp 0x4dcbf9 */

L_004DCBF9:
    ecx = MEM32(ebp + (-0x14)); /* 0x004DCBF9: mov ecx, dword ptr [ebp - 0x14] */
    MEM32(0x84B878) = ecx; /* 0x004DCBFC: mov dword ptr [0x84b878], ecx */
    eax = eax | 0xFFFFFFFFu; /* 0x004DCC02: or eax, 0xffffffff */
    esp = ebp; /* 0x004DCC05: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DCC07: pop ebp */
    return; /* 0x004DCC08: ret  */

}

void sub_004DCB34(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DCB34:
    SET_LO8(eax, LO8(eax) + 0xB7u); /* 0x004DCB34: add al, 0xb7 */
    PUSH32(esp, eax); /* 0x004DCB36: push eax */
    MEM8(ebx + (-0x17000000)) = (uint8_t)(MEM8(ebx + (-0x17000000)) + LO8(eax)); /* 0x004DCB37: add byte ptr [ebx - 0x17000000], al */
    MEM8(eax) = (uint8_t)(LO8(eax)); /* 0x004DCB3D: mov byte ptr [eax], al */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DCB3F: add byte ptr [eax], al */
    edx = MEM32(ebp + (-0xC)); /* 0x004DCB41: mov edx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(edx), 0xC0000090u */ /* 0x004DCB44: cmp dword ptr [edx], 0xc0000090 */
    if (CMP_NE(MEM32(edx), 0xC0000090u)) goto L_004DCB58; /* 0x004DCB4A: jne 0x4dcb58 */

L_004DCB4C:
    MEM32(0x50B704) = 0x81u; /* 0x004DCB4C: mov dword ptr [0x50b704], 0x81 */
    goto L_004DCBC9; /* 0x004DCB56: jmp 0x4dcbc9 */

L_004DCB58:
    eax = MEM32(ebp + (-0xC)); /* 0x004DCB58: mov eax, dword ptr [ebp - 0xc] */
    /* cmp MEM32(eax), 0xC0000091u */ /* 0x004DCB5B: cmp dword ptr [eax], 0xc0000091 */
    if (CMP_NE(MEM32(eax), 0xC0000091u)) goto L_004DCB6F; /* 0x004DCB61: jne 0x4dcb6f */

L_004DCB63:
    MEM32(0x50B704) = 0x84u; /* 0x004DCB63: mov dword ptr [0x50b704], 0x84 */
    goto L_004DCBC9; /* 0x004DCB6D: jmp 0x4dcbc9 */

L_004DCB6F:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DCB6F: mov ecx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(ecx), 0xC0000093u */ /* 0x004DCB72: cmp dword ptr [ecx], 0xc0000093 */
    if (CMP_NE(MEM32(ecx), 0xC0000093u)) goto L_004DCB86; /* 0x004DCB78: jne 0x4dcb86 */

L_004DCB7A:
    MEM32(0x50B704) = 0x85u; /* 0x004DCB7A: mov dword ptr [0x50b704], 0x85 */
    goto L_004DCBC9; /* 0x004DCB84: jmp 0x4dcbc9 */

L_004DCB86:
    edx = MEM32(ebp + (-0xC)); /* 0x004DCB86: mov edx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(edx), 0xC000008Du */ /* 0x004DCB89: cmp dword ptr [edx], 0xc000008d */
    if (CMP_NE(MEM32(edx), 0xC000008Du)) goto L_004DCB9D; /* 0x004DCB8F: jne 0x4dcb9d */

L_004DCB91:
    MEM32(0x50B704) = 0x82u; /* 0x004DCB91: mov dword ptr [0x50b704], 0x82 */
    goto L_004DCBC9; /* 0x004DCB9B: jmp 0x4dcbc9 */

L_004DCB9D:
    eax = MEM32(ebp + (-0xC)); /* 0x004DCB9D: mov eax, dword ptr [ebp - 0xc] */
    /* cmp MEM32(eax), 0xC000008Fu */ /* 0x004DCBA0: cmp dword ptr [eax], 0xc000008f */
    if (CMP_NE(MEM32(eax), 0xC000008Fu)) goto L_004DCBB4; /* 0x004DCBA6: jne 0x4dcbb4 */

L_004DCBA8:
    MEM32(0x50B704) = 0x86u; /* 0x004DCBA8: mov dword ptr [0x50b704], 0x86 */
    goto L_004DCBC9; /* 0x004DCBB2: jmp 0x4dcbc9 */

L_004DCBB4:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DCBB4: mov ecx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(ecx), 0xC0000092u */ /* 0x004DCBB7: cmp dword ptr [ecx], 0xc0000092 */
    if (CMP_NE(MEM32(ecx), 0xC0000092u)) goto L_004DCBC9; /* 0x004DCBBD: jne 0x4dcbc9 */

L_004DCBBF:
    MEM32(0x50B704) = 0x8Au; /* 0x004DCBBF: mov dword ptr [0x50b704], 0x8a */

L_004DCBC9:
    edx = MEM32(0x50B704); /* 0x004DCBC9: mov edx, dword ptr [0x50b704] */
    PUSH32(esp, edx); /* 0x004DCBCF: push edx */
    PUSH32(esp, 8); /* 0x004DCBD0: push 8 */
    RECOMP_ICALL(MEM32(ebp + (-0x4))); /* 0x004DCBD2: call dword ptr [ebp - 4] */
    esp = esp + 8; /* 0x004DCBD5: add esp, 8 */
    eax = MEM32(ebp + (-0x8)); /* 0x004DCBD8: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B704) = eax; /* 0x004DCBDB: mov dword ptr [0x50b704], eax */
    goto L_004DCBF9; /* 0x004DCBE0: jmp 0x4dcbf9 */

L_004DCBF9:
    ecx = MEM32(ebp + (-0x14)); /* 0x004DCBF9: mov ecx, dword ptr [ebp - 0x14] */
    MEM32(0x84B878) = ecx; /* 0x004DCBFC: mov dword ptr [0x84b878], ecx */
    eax = eax | 0xFFFFFFFFu; /* 0x004DCC02: or eax, 0xffffffff */
    esp = ebp; /* 0x004DCC05: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DCC07: pop ebp */
    return; /* 0x004DCC08: ret  */

}

void sub_004DCB39(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DCB39:
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DCB39: add byte ptr [eax], al */
    SET_LO8(ecx, LO8(ecx) + HI8(ecx)); /* 0x004DCB3B: add cl, ch */
    MEM8(eax) = (uint8_t)(LO8(eax)); /* 0x004DCB3D: mov byte ptr [eax], al */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DCB3F: add byte ptr [eax], al */
    edx = MEM32(ebp + (-0xC)); /* 0x004DCB41: mov edx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(edx), 0xC0000090u */ /* 0x004DCB44: cmp dword ptr [edx], 0xc0000090 */
    if (CMP_NE(MEM32(edx), 0xC0000090u)) goto L_004DCB58; /* 0x004DCB4A: jne 0x4dcb58 */

L_004DCB4C:
    MEM32(0x50B704) = 0x81u; /* 0x004DCB4C: mov dword ptr [0x50b704], 0x81 */
    goto L_004DCBC9; /* 0x004DCB56: jmp 0x4dcbc9 */

L_004DCB58:
    eax = MEM32(ebp + (-0xC)); /* 0x004DCB58: mov eax, dword ptr [ebp - 0xc] */
    /* cmp MEM32(eax), 0xC0000091u */ /* 0x004DCB5B: cmp dword ptr [eax], 0xc0000091 */
    if (CMP_NE(MEM32(eax), 0xC0000091u)) goto L_004DCB6F; /* 0x004DCB61: jne 0x4dcb6f */

L_004DCB63:
    MEM32(0x50B704) = 0x84u; /* 0x004DCB63: mov dword ptr [0x50b704], 0x84 */
    goto L_004DCBC9; /* 0x004DCB6D: jmp 0x4dcbc9 */

L_004DCB6F:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DCB6F: mov ecx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(ecx), 0xC0000093u */ /* 0x004DCB72: cmp dword ptr [ecx], 0xc0000093 */
    if (CMP_NE(MEM32(ecx), 0xC0000093u)) goto L_004DCB86; /* 0x004DCB78: jne 0x4dcb86 */

L_004DCB7A:
    MEM32(0x50B704) = 0x85u; /* 0x004DCB7A: mov dword ptr [0x50b704], 0x85 */
    goto L_004DCBC9; /* 0x004DCB84: jmp 0x4dcbc9 */

L_004DCB86:
    edx = MEM32(ebp + (-0xC)); /* 0x004DCB86: mov edx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(edx), 0xC000008Du */ /* 0x004DCB89: cmp dword ptr [edx], 0xc000008d */
    if (CMP_NE(MEM32(edx), 0xC000008Du)) goto L_004DCB9D; /* 0x004DCB8F: jne 0x4dcb9d */

L_004DCB91:
    MEM32(0x50B704) = 0x82u; /* 0x004DCB91: mov dword ptr [0x50b704], 0x82 */
    goto L_004DCBC9; /* 0x004DCB9B: jmp 0x4dcbc9 */

L_004DCB9D:
    eax = MEM32(ebp + (-0xC)); /* 0x004DCB9D: mov eax, dword ptr [ebp - 0xc] */
    /* cmp MEM32(eax), 0xC000008Fu */ /* 0x004DCBA0: cmp dword ptr [eax], 0xc000008f */
    if (CMP_NE(MEM32(eax), 0xC000008Fu)) goto L_004DCBB4; /* 0x004DCBA6: jne 0x4dcbb4 */

L_004DCBA8:
    MEM32(0x50B704) = 0x86u; /* 0x004DCBA8: mov dword ptr [0x50b704], 0x86 */
    goto L_004DCBC9; /* 0x004DCBB2: jmp 0x4dcbc9 */

L_004DCBB4:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DCBB4: mov ecx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(ecx), 0xC0000092u */ /* 0x004DCBB7: cmp dword ptr [ecx], 0xc0000092 */
    if (CMP_NE(MEM32(ecx), 0xC0000092u)) goto L_004DCBC9; /* 0x004DCBBD: jne 0x4dcbc9 */

L_004DCBBF:
    MEM32(0x50B704) = 0x8Au; /* 0x004DCBBF: mov dword ptr [0x50b704], 0x8a */

L_004DCBC9:
    edx = MEM32(0x50B704); /* 0x004DCBC9: mov edx, dword ptr [0x50b704] */
    PUSH32(esp, edx); /* 0x004DCBCF: push edx */
    PUSH32(esp, 8); /* 0x004DCBD0: push 8 */
    RECOMP_ICALL(MEM32(ebp + (-0x4))); /* 0x004DCBD2: call dword ptr [ebp - 4] */
    esp = esp + 8; /* 0x004DCBD5: add esp, 8 */
    eax = MEM32(ebp + (-0x8)); /* 0x004DCBD8: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B704) = eax; /* 0x004DCBDB: mov dword ptr [0x50b704], eax */
    goto L_004DCBF9; /* 0x004DCBE0: jmp 0x4dcbf9 */

L_004DCBF9:
    ecx = MEM32(ebp + (-0x14)); /* 0x004DCBF9: mov ecx, dword ptr [ebp - 0x14] */
    MEM32(0x84B878) = ecx; /* 0x004DCBFC: mov dword ptr [0x84b878], ecx */
    eax = eax | 0xFFFFFFFFu; /* 0x004DCC02: or eax, 0xffffffff */
    esp = ebp; /* 0x004DCC05: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DCC07: pop ebp */
    return; /* 0x004DCC08: ret  */

}

void sub_004DCC6F(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DCC6F:
    /* int3 breakpoint */ /* 0x004DCC6F: int3  */

}

void sub_004DCD40(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DCD40:
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DCD40: add byte ptr [eax], al */
    MEM8(ebx + (-0x3CA2F33C)) = (uint8_t)(MEM8(ebx + (-0x3CA2F33C)) + LO8(eax)); /* 0x004DCD42: add byte ptr [ebx - 0x3ca2f33c], al */
    /* int3 breakpoint */ /* 0x004DCD48: int3  */

}

void sub_004DD040(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD040:
    ebp = ebp - 1; /* 0x004DD040: dec ebp */
    _cf = 0; /* 0x004DD041: clc  */
    PUSH32(esp, ecx); /* 0x004DD042: push ecx */
    edx = MEM32(ebp + (-0x10)); /* 0x004DD043: mov edx, dword ptr [ebp - 0x10] */
    PUSH32(esp, edx); /* 0x004DD046: push edx */
    RECOMP_CALL(sub_004DD070); /* 0x004DD047: call 0x4dd070 */
    esp = esp + 0x14u; /* 0x004DD04C: add esp, 0x14 */
    eax = MEM32(ebp + (-0xC)); /* 0x004DD04F: mov eax, dword ptr [ebp - 0xc] */
    eax = eax - 1; /* 0x004DD052: sub eax, 1 */
    MEM32(0x84B7C8) = eax; /* 0x004DD055: mov dword ptr [0x84b7c8], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DD05A: mov ecx, dword ptr [ebp - 8] */
    MEM32(0x84B7CC) = ecx; /* 0x004DD05D: mov dword ptr [0x84b7cc], ecx */
    esp = ebp; /* 0x004DD063: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD065: pop ebp */
    return; /* 0x004DD066: ret  */

}

void sub_004DD0A0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD0A0:
    esp += 35076; return; /* 0x004DD0A0: ret 0x8904 */

}

void sub_004DD120(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD0B4:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD0B4: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD0B7: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD0BA: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DD0BD: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD0C0: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x22u */ /* 0x004DD0C3: cmp ecx, 0x22 */
    if (CMP_EQ(ecx, 0x22u)) goto L_004DD142; /* 0x004DD0C6: je 0x4dd142 */

L_004DD0C8:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD0C8: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD0CB: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD0CE: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD142; /* 0x004DD0D0: je 0x4dd142 */

L_004DD0D2:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD0D2: mov ecx, dword ptr [ebp - 4] */
    edx = 0; /* 0x004DD0D5: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DD0D7: mov dl, byte ptr [ecx] */
    eax = 0; /* 0x004DD0D9: xor eax, eax */
    SET_LO8(eax, MEM8(edx + 0x84B991)); /* 0x004DD0DB: mov al, byte ptr [edx + 0x84b991] */
    eax = eax & 4; /* 0x004DD0E1: and eax, 4 */
    /* test eax, eax */ /* 0x004DD0E4: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD117; /* 0x004DD0E6: je 0x4dd117 */

L_004DD0E8:
    ecx = MEM32(ebp + 0x18); /* 0x004DD0E8: mov ecx, dword ptr [ebp + 0x18] */
    edx = MEM32(ecx); /* 0x004DD0EB: mov edx, dword ptr [ecx] */
    edx = edx + 1; /* 0x004DD0ED: add edx, 1 */
    eax = MEM32(ebp + 0x18); /* 0x004DD0F0: mov eax, dword ptr [ebp + 0x18] */
    MEM32(eax) = edx; /* 0x004DD0F3: mov dword ptr [eax], edx */
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD0F5: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD117; /* 0x004DD0F9: je 0x4dd117 */

L_004DD0FB:
    ecx = MEM32(ebp + 0x10); /* 0x004DD0FB: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DD0FE: mov edx, dword ptr [ebp - 4] */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD101: mov al, byte ptr [edx] */
    MEM8(ecx) = (uint8_t)(LO8(eax)); /* 0x004DD103: mov byte ptr [ecx], al */
    ecx = MEM32(ebp + 0x10); /* 0x004DD105: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx + 1; /* 0x004DD108: add ecx, 1 */
    MEM32(ebp + 0x10) = ecx; /* 0x004DD10B: mov dword ptr [ebp + 0x10], ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004DD10E: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD111: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD114: mov dword ptr [ebp - 4], edx */

L_004DD117:
    eax = MEM32(ebp + 0x18); /* 0x004DD117: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD11A: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD11C: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD11F: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD122: mov dword ptr [edx], ecx */
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD124: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD13D; /* 0x004DD128: je 0x4dd13d */

L_004DD120:
    PUSH32(esp, ebp); /* 0x004DD120: push ebp */
    MEM8(ecx + 0x107D830A) = (uint8_t)(MEM8(ecx + 0x107D830A) - LO8(ecx) - _cf); /* 0x004DD121: sbb byte ptr [ecx + 0x107d830a], cl */
    MEM8(ebx + edx + (-0x75)) = (uint8_t)(MEM8(ebx + edx + (-0x75)) + HI8(edx)); /* 0x004DD127: add byte ptr [ebx + edx - 0x75], dh */
    ebp = ebp + 1; /* 0x004DD12B: inc ebp */
    MEM8(ebx + 0x118AFC4D) = (uint8_t)(MEM8(ebx + 0x118AFC4D) + LO8(ecx) + _cf); /* 0x004DD12C: adc byte ptr [ebx + 0x118afc4d], cl */
    MEM8(eax) = (uint8_t)(LO8(edx)); /* 0x004DD132: mov byte ptr [eax], dl */
    eax = MEM32(ebp + 0x10); /* 0x004DD134: mov eax, dword ptr [ebp + 0x10] */
    eax = eax + 1; /* 0x004DD137: add eax, 1 */
    MEM32(ebp + 0x10) = eax; /* 0x004DD13A: mov dword ptr [ebp + 0x10], eax */

L_004DD12A:
    eax = MEM32(ebp + 0x10); /* 0x004DD12A: mov eax, dword ptr [ebp + 0x10] */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD12D: mov ecx, dword ptr [ebp - 4] */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DD130: mov dl, byte ptr [ecx] */
    MEM8(eax) = (uint8_t)(LO8(edx)); /* 0x004DD132: mov byte ptr [eax], dl */
    eax = MEM32(ebp + 0x10); /* 0x004DD134: mov eax, dword ptr [ebp + 0x10] */
    eax = eax + 1; /* 0x004DD137: add eax, 1 */
    MEM32(ebp + 0x10) = eax; /* 0x004DD13A: mov dword ptr [ebp + 0x10], eax */

L_004DD13D:
    goto L_004DD0B4; /* 0x004DD13D: jmp 0x4dd0b4 */

L_004DD142:
    ecx = MEM32(ebp + 0x18); /* 0x004DD142: mov ecx, dword ptr [ebp + 0x18] */
    edx = MEM32(ecx); /* 0x004DD145: mov edx, dword ptr [ecx] */
    edx = edx + 1; /* 0x004DD147: add edx, 1 */
    eax = MEM32(ebp + 0x18); /* 0x004DD14A: mov eax, dword ptr [ebp + 0x18] */
    MEM32(eax) = edx; /* 0x004DD14D: mov dword ptr [eax], edx */
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD14F: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD164; /* 0x004DD153: je 0x4dd164 */

L_004DD155:
    ecx = MEM32(ebp + 0x10); /* 0x004DD155: mov ecx, dword ptr [ebp + 0x10] */
    MEM8(ecx) = (uint8_t)(0); /* 0x004DD158: mov byte ptr [ecx], 0 */
    edx = MEM32(ebp + 0x10); /* 0x004DD15B: mov edx, dword ptr [ebp + 0x10] */
    edx = edx + 1; /* 0x004DD15E: add edx, 1 */
    MEM32(ebp + 0x10) = edx; /* 0x004DD161: mov dword ptr [ebp + 0x10], edx */

L_004DD164:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD164: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD167: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x22u */ /* 0x004DD16A: cmp ecx, 0x22 */
    if (CMP_NE(ecx, 0x22u)) goto L_004DD178; /* 0x004DD16D: jne 0x4dd178 */

L_004DD16F:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD16F: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD172: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD175: mov dword ptr [ebp - 4], edx */

L_004DD178:
    goto L_004DD24C; /* 0x004DD178: jmp 0x4dd24c */

L_004DD24C:
    MEM32(ebp + (-0x14)) = 0; /* 0x004DD24C: mov dword ptr [ebp - 0x14], 0 */

L_004DD253:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD253: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD256: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD259: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD27E; /* 0x004DD25B: je 0x4dd27e */

L_004DD25D:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD25D: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DD260: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x20u */ /* 0x004DD263: cmp edx, 0x20 */
    if (CMP_EQ(edx, 0x20u)) goto L_004DD273; /* 0x004DD266: je 0x4dd273 */

L_004DD268:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD268: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD26B: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 9 */ /* 0x004DD26E: cmp ecx, 9 */
    if (CMP_NE(ecx, 9)) goto L_004DD27E; /* 0x004DD271: jne 0x4dd27e */

L_004DD273:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD273: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD276: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD279: mov dword ptr [ebp - 4], edx */
    goto L_004DD25D; /* 0x004DD27C: jmp 0x4dd25d */

L_004DD27E:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD27E: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD281: movsx ecx, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DD284: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DD28D; /* 0x004DD286: jne 0x4dd28d */

L_004DD288:
    goto L_004DD46B; /* 0x004DD288: jmp 0x4dd46b */

L_004DD28D:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004DD28D: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + 0xC), 0)) goto L_004DD2A4; /* 0x004DD291: je 0x4dd2a4 */

L_004DD293:
    edx = MEM32(ebp + 0xC); /* 0x004DD293: mov edx, dword ptr [ebp + 0xc] */
    eax = MEM32(ebp + 0x10); /* 0x004DD296: mov eax, dword ptr [ebp + 0x10] */
    MEM32(edx) = eax; /* 0x004DD299: mov dword ptr [edx], eax */
    ecx = MEM32(ebp + 0xC); /* 0x004DD29B: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx + 4; /* 0x004DD29E: add ecx, 4 */
    MEM32(ebp + 0xC) = ecx; /* 0x004DD2A1: mov dword ptr [ebp + 0xc], ecx */

L_004DD2A4:
    edx = MEM32(ebp + 0x14); /* 0x004DD2A4: mov edx, dword ptr [ebp + 0x14] */
    eax = MEM32(edx); /* 0x004DD2A7: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD2A9: add eax, 1 */
    ecx = MEM32(ebp + 0x14); /* 0x004DD2AC: mov ecx, dword ptr [ebp + 0x14] */
    MEM32(ecx) = eax; /* 0x004DD2AF: mov dword ptr [ecx], eax */

L_004DD2B1:
    MEM32(ebp + (-0x8)) = 1; /* 0x004DD2B1: mov dword ptr [ebp - 8], 1 */
    MEM32(ebp + (-0x10)) = 0; /* 0x004DD2B8: mov dword ptr [ebp - 0x10], 0 */

L_004DD2BF:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD2BF: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD2C2: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x5Cu */ /* 0x004DD2C5: cmp eax, 0x5c */
    if (CMP_NE(eax, 0x5Cu)) goto L_004DD2DE; /* 0x004DD2C8: jne 0x4dd2de */

L_004DD2CA:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD2CA: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DD2CD: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DD2D0: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + (-0x10)); /* 0x004DD2D3: mov edx, dword ptr [ebp - 0x10] */
    edx = edx + 1; /* 0x004DD2D6: add edx, 1 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DD2D9: mov dword ptr [ebp - 0x10], edx */
    goto L_004DD2BF; /* 0x004DD2DC: jmp 0x4dd2bf */

L_004DD2DE:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD2DE: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD2E1: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x22u */ /* 0x004DD2E4: cmp ecx, 0x22 */
    if (CMP_NE(ecx, 0x22u)) goto L_004DD33A; /* 0x004DD2E7: jne 0x4dd33a */

L_004DD2E9:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD2E9: mov eax, dword ptr [ebp - 0x10] */
    edx = 0; /* 0x004DD2EC: xor edx, edx */
    ecx = 2; /* 0x004DD2EE: mov ecx, 2 */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax; /* 0x004DD2F3: div ecx */
      eax = (uint32_t)(_dividend / (uint32_t)ecx);
      edx = (uint32_t)(_dividend % (uint32_t)ecx); }
    /* test edx, edx */ /* 0x004DD2F5: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004DD332; /* 0x004DD2F7: jne 0x4dd332 */

L_004DD2F9:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD2F9: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x14)), 0)) goto L_004DD31F; /* 0x004DD2FD: je 0x4dd31f */

L_004DD2FF:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD2FF: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx + 0x1); /* 0x004DD302: movsx eax, byte ptr [edx + 1] */
    /* cmp eax, 0x22u */ /* 0x004DD306: cmp eax, 0x22 */
    if (CMP_NE(eax, 0x22u)) goto L_004DD316; /* 0x004DD309: jne 0x4dd316 */

L_004DD30B:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD30B: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DD30E: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DD311: mov dword ptr [ebp - 4], ecx */
    goto L_004DD31D; /* 0x004DD314: jmp 0x4dd31d */

L_004DD316:
    MEM32(ebp + (-0x8)) = 0; /* 0x004DD316: mov dword ptr [ebp - 8], 0 */

L_004DD31D:
    goto L_004DD326; /* 0x004DD31D: jmp 0x4dd326 */

L_004DD31F:
    MEM32(ebp + (-0x8)) = 0; /* 0x004DD31F: mov dword ptr [ebp - 8], 0 */

L_004DD326:
    edx = 0; /* 0x004DD326: xor edx, edx */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD328: cmp dword ptr [ebp - 0x14], 0 */
    SET_LO8(edx, (CMP_EQ(MEM32(ebp + (-0x14)), 0)) ? 1 : 0); /* 0x004DD32C: sete dl */
    MEM32(ebp + (-0x14)) = edx; /* 0x004DD32F: mov dword ptr [ebp - 0x14], edx */

L_004DD332:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD332: mov eax, dword ptr [ebp - 0x10] */
    eax = eax >> 1; /* 0x004DD335: shr eax, 1 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DD337: mov dword ptr [ebp - 0x10], eax */

L_004DD33A:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD33A: mov ecx, dword ptr [ebp - 0x10] */
    edx = MEM32(ebp + (-0x10)); /* 0x004DD33D: mov edx, dword ptr [ebp - 0x10] */
    edx = edx - 1; /* 0x004DD340: sub edx, 1 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DD343: mov dword ptr [ebp - 0x10], edx */
    /* test ecx, ecx */ /* 0x004DD346: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD36E; /* 0x004DD348: je 0x4dd36e */

L_004DD34A:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD34A: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD35F; /* 0x004DD34E: je 0x4dd35f */

L_004DD350:
    eax = MEM32(ebp + 0x10); /* 0x004DD350: mov eax, dword ptr [ebp + 0x10] */
    MEM8(eax) = (uint8_t)(0x5Cu); /* 0x004DD353: mov byte ptr [eax], 0x5c */
    ecx = MEM32(ebp + 0x10); /* 0x004DD356: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx + 1; /* 0x004DD359: add ecx, 1 */
    MEM32(ebp + 0x10) = ecx; /* 0x004DD35C: mov dword ptr [ebp + 0x10], ecx */

L_004DD35F:
    edx = MEM32(ebp + 0x18); /* 0x004DD35F: mov edx, dword ptr [ebp + 0x18] */
    eax = MEM32(edx); /* 0x004DD362: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD364: add eax, 1 */
    ecx = MEM32(ebp + 0x18); /* 0x004DD367: mov ecx, dword ptr [ebp + 0x18] */
    MEM32(ecx) = eax; /* 0x004DD36A: mov dword ptr [ecx], eax */
    goto L_004DD33A; /* 0x004DD36C: jmp 0x4dd33a */

L_004DD36E:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD36E: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD371: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD374: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD394; /* 0x004DD376: je 0x4dd394 */

L_004DD378:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD378: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004DD399; /* 0x004DD37C: jne 0x4dd399 */

L_004DD37E:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD37E: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DD381: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x20u */ /* 0x004DD384: cmp edx, 0x20 */
    if (CMP_EQ(edx, 0x20u)) goto L_004DD394; /* 0x004DD387: je 0x4dd394 */

L_004DD389:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD389: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD38C: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 9 */ /* 0x004DD38F: cmp ecx, 9 */
    if (CMP_NE(ecx, 9)) goto L_004DD399; /* 0x004DD392: jne 0x4dd399 */

L_004DD394:
    goto L_004DD444; /* 0x004DD394: jmp 0x4dd444 */

L_004DD399:
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004DD399: cmp dword ptr [ebp - 8], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x8)), 0)) goto L_004DD436; /* 0x004DD39D: je 0x4dd436 */

L_004DD3A3:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD3A3: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD3FD; /* 0x004DD3A7: je 0x4dd3fd */

L_004DD3A9:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3A9: mov edx, dword ptr [ebp - 4] */
    eax = 0; /* 0x004DD3AC: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD3AE: mov al, byte ptr [edx] */
    ecx = 0; /* 0x004DD3B0: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DD3B2: mov cl, byte ptr [eax + 0x84b991] */
    ecx = ecx & 4; /* 0x004DD3B8: and ecx, 4 */
    /* test ecx, ecx */ /* 0x004DD3BB: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD3E8; /* 0x004DD3BD: je 0x4dd3e8 */

L_004DD3BF:
    edx = MEM32(ebp + 0x10); /* 0x004DD3BF: mov edx, dword ptr [ebp + 0x10] */
    eax = MEM32(ebp + (-0x4)); /* 0x004DD3C2: mov eax, dword ptr [ebp - 4] */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DD3C5: mov cl, byte ptr [eax] */
    MEM8(edx) = (uint8_t)(LO8(ecx)); /* 0x004DD3C7: mov byte ptr [edx], cl */
    edx = MEM32(ebp + 0x10); /* 0x004DD3C9: mov edx, dword ptr [ebp + 0x10] */
    edx = edx + 1; /* 0x004DD3CC: add edx, 1 */
    MEM32(ebp + 0x10) = edx; /* 0x004DD3CF: mov dword ptr [ebp + 0x10], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DD3D2: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DD3D5: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD3D8: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + 0x18); /* 0x004DD3DB: mov ecx, dword ptr [ebp + 0x18] */
    edx = MEM32(ecx); /* 0x004DD3DE: mov edx, dword ptr [ecx] */
    edx = edx + 1; /* 0x004DD3E0: add edx, 1 */
    eax = MEM32(ebp + 0x18); /* 0x004DD3E3: mov eax, dword ptr [ebp + 0x18] */
    MEM32(eax) = edx; /* 0x004DD3E6: mov dword ptr [eax], edx */

L_004DD3E8:
    ecx = MEM32(ebp + 0x10); /* 0x004DD3E8: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3EB: mov edx, dword ptr [ebp - 4] */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD3EE: mov al, byte ptr [edx] */
    MEM8(ecx) = (uint8_t)(LO8(eax)); /* 0x004DD3F0: mov byte ptr [ecx], al */
    ecx = MEM32(ebp + 0x10); /* 0x004DD3F2: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx + 1; /* 0x004DD3F5: add ecx, 1 */
    MEM32(ebp + 0x10) = ecx; /* 0x004DD3F8: mov dword ptr [ebp + 0x10], ecx */
    goto L_004DD429; /* 0x004DD3FB: jmp 0x4dd429 */

L_004DD3FD:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3FD: mov edx, dword ptr [ebp - 4] */
    eax = 0; /* 0x004DD400: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD402: mov al, byte ptr [edx] */
    ecx = 0; /* 0x004DD404: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DD406: mov cl, byte ptr [eax + 0x84b991] */
    ecx = ecx & 4; /* 0x004DD40C: and ecx, 4 */
    /* test ecx, ecx */ /* 0x004DD40F: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD429; /* 0x004DD411: je 0x4dd429 */

L_004DD413:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD413: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD416: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD419: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + 0x18); /* 0x004DD41C: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD41F: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD421: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD424: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD427: mov dword ptr [edx], ecx */

L_004DD429:
    eax = MEM32(ebp + 0x18); /* 0x004DD429: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD42C: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD42E: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD431: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD434: mov dword ptr [edx], ecx */

L_004DD436:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD436: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DD439: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD43C: mov dword ptr [ebp - 4], eax */
    goto L_004DD2B1; /* 0x004DD43F: jmp 0x4dd2b1 */

L_004DD444:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD444: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD459; /* 0x004DD448: je 0x4dd459 */

L_004DD44A:
    ecx = MEM32(ebp + 0x10); /* 0x004DD44A: mov ecx, dword ptr [ebp + 0x10] */
    MEM8(ecx) = (uint8_t)(0); /* 0x004DD44D: mov byte ptr [ecx], 0 */
    edx = MEM32(ebp + 0x10); /* 0x004DD450: mov edx, dword ptr [ebp + 0x10] */
    edx = edx + 1; /* 0x004DD453: add edx, 1 */
    MEM32(ebp + 0x10) = edx; /* 0x004DD456: mov dword ptr [ebp + 0x10], edx */

L_004DD459:
    eax = MEM32(ebp + 0x18); /* 0x004DD459: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD45C: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD45E: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD461: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD464: mov dword ptr [edx], ecx */
    goto L_004DD253; /* 0x004DD466: jmp 0x4dd253 */

L_004DD46B:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004DD46B: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + 0xC), 0)) goto L_004DD483; /* 0x004DD46F: je 0x4dd483 */

L_004DD471:
    eax = MEM32(ebp + 0xC); /* 0x004DD471: mov eax, dword ptr [ebp + 0xc] */
    MEM32(eax) = 0; /* 0x004DD474: mov dword ptr [eax], 0 */
    ecx = MEM32(ebp + 0xC); /* 0x004DD47A: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx + 4; /* 0x004DD47D: add ecx, 4 */
    MEM32(ebp + 0xC) = ecx; /* 0x004DD480: mov dword ptr [ebp + 0xc], ecx */

L_004DD483:
    edx = MEM32(ebp + 0x14); /* 0x004DD483: mov edx, dword ptr [ebp + 0x14] */
    eax = MEM32(edx); /* 0x004DD486: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD488: add eax, 1 */
    ecx = MEM32(ebp + 0x14); /* 0x004DD48B: mov ecx, dword ptr [ebp + 0x14] */
    MEM32(ecx) = eax; /* 0x004DD48E: mov dword ptr [ecx], eax */
    esp = ebp; /* 0x004DD490: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD492: pop ebp */
    return; /* 0x004DD493: ret  */

}

void sub_004DD1A0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD17D:
    eax = MEM32(ebp + 0x18); /* 0x004DD17D: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD180: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD182: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD185: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD188: mov dword ptr [edx], ecx */
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD18A: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD1A3; /* 0x004DD18E: je 0x4dd1a3 */

L_004DD190:
    eax = MEM32(ebp + 0x10); /* 0x004DD190: mov eax, dword ptr [ebp + 0x10] */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD193: mov ecx, dword ptr [ebp - 4] */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DD196: mov dl, byte ptr [ecx] */
    MEM8(eax) = (uint8_t)(LO8(edx)); /* 0x004DD198: mov byte ptr [eax], dl */
    eax = MEM32(ebp + 0x10); /* 0x004DD19A: mov eax, dword ptr [ebp + 0x10] */
    eax = eax + 1; /* 0x004DD19D: add eax, 1 */

L_004DD1A0:
    MEM32(ebp + 0x10) = eax; /* 0x004DD1A0: mov dword ptr [ebp + 0x10], eax */

L_004DD1A3:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD1A3: mov ecx, dword ptr [ebp - 4] */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DD1A6: mov dl, byte ptr [ecx] */
    MEM8(ebp + (-0xC)) = (uint8_t)(LO8(edx)); /* 0x004DD1A8: mov byte ptr [ebp - 0xc], dl */
    eax = MEM32(ebp + (-0x4)); /* 0x004DD1AB: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DD1AE: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD1B1: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD1B4: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx & 0xFFu; /* 0x004DD1B7: and ecx, 0xff */
    edx = 0; /* 0x004DD1BD: xor edx, edx */
    SET_LO8(edx, MEM8(ecx + 0x84B991)); /* 0x004DD1BF: mov dl, byte ptr [ecx + 0x84b991] */
    edx = edx & 4; /* 0x004DD1C5: and edx, 4 */
    /* test edx, edx */ /* 0x004DD1C8: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DD1FB; /* 0x004DD1CA: je 0x4dd1fb */

L_004DD1CC:
    eax = MEM32(ebp + 0x18); /* 0x004DD1CC: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD1CF: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD1D1: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD1D4: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD1D7: mov dword ptr [edx], ecx */
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD1D9: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD1F2; /* 0x004DD1DD: je 0x4dd1f2 */

L_004DD1DF:
    eax = MEM32(ebp + 0x10); /* 0x004DD1DF: mov eax, dword ptr [ebp + 0x10] */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD1E2: mov ecx, dword ptr [ebp - 4] */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DD1E5: mov dl, byte ptr [ecx] */
    MEM8(eax) = (uint8_t)(LO8(edx)); /* 0x004DD1E7: mov byte ptr [eax], dl */
    eax = MEM32(ebp + 0x10); /* 0x004DD1E9: mov eax, dword ptr [ebp + 0x10] */
    eax = eax + 1; /* 0x004DD1EC: add eax, 1 */
    MEM32(ebp + 0x10) = eax; /* 0x004DD1EF: mov dword ptr [ebp + 0x10], eax */

L_004DD1F2:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD1F2: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DD1F5: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DD1F8: mov dword ptr [ebp - 4], ecx */

L_004DD1FB:
    edx = MEM32(ebp + (-0xC)); /* 0x004DD1FB: mov edx, dword ptr [ebp - 0xc] */
    edx = edx & 0xFFu; /* 0x004DD1FE: and edx, 0xff */
    /* cmp edx, 0x20u */ /* 0x004DD204: cmp edx, 0x20 */
    if (CMP_EQ(edx, 0x20u)) goto L_004DD227; /* 0x004DD207: je 0x4dd227 */

L_004DD209:
    eax = MEM32(ebp + (-0xC)); /* 0x004DD209: mov eax, dword ptr [ebp - 0xc] */
    eax = eax & 0xFFu; /* 0x004DD20C: and eax, 0xff */
    /* test eax, eax */ /* 0x004DD211: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD227; /* 0x004DD213: je 0x4dd227 */

L_004DD215:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD215: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx & 0xFFu; /* 0x004DD218: and ecx, 0xff */
    /* cmp ecx, 9 */ /* 0x004DD21E: cmp ecx, 9 */
    if (CMP_NE(ecx, 9)) goto L_004DD17D; /* 0x004DD221: jne 0x4dd17d */

L_004DD227:
    edx = MEM32(ebp + (-0xC)); /* 0x004DD227: mov edx, dword ptr [ebp - 0xc] */
    edx = edx & 0xFFu; /* 0x004DD22A: and edx, 0xff */
    /* test edx, edx */ /* 0x004DD230: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004DD23F; /* 0x004DD232: jne 0x4dd23f */

L_004DD234:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD234: mov eax, dword ptr [ebp - 4] */
    eax = eax - 1; /* 0x004DD237: sub eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD23A: mov dword ptr [ebp - 4], eax */
    goto L_004DD24C; /* 0x004DD23D: jmp 0x4dd24c */

L_004DD23F:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD23F: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD24C; /* 0x004DD243: je 0x4dd24c */

L_004DD245:
    ecx = MEM32(ebp + 0x10); /* 0x004DD245: mov ecx, dword ptr [ebp + 0x10] */
    MEM8(ecx + (-0x1)) = (uint8_t)(0); /* 0x004DD248: mov byte ptr [ecx - 1], 0 */

L_004DD24C:
    MEM32(ebp + (-0x14)) = 0; /* 0x004DD24C: mov dword ptr [ebp - 0x14], 0 */

L_004DD253:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD253: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD256: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD259: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD27E; /* 0x004DD25B: je 0x4dd27e */

L_004DD25D:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD25D: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DD260: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x20u */ /* 0x004DD263: cmp edx, 0x20 */
    if (CMP_EQ(edx, 0x20u)) goto L_004DD273; /* 0x004DD266: je 0x4dd273 */

L_004DD268:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD268: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD26B: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 9 */ /* 0x004DD26E: cmp ecx, 9 */
    if (CMP_NE(ecx, 9)) goto L_004DD27E; /* 0x004DD271: jne 0x4dd27e */

L_004DD273:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD273: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD276: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD279: mov dword ptr [ebp - 4], edx */
    goto L_004DD25D; /* 0x004DD27C: jmp 0x4dd25d */

L_004DD27E:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD27E: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD281: movsx ecx, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DD284: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DD28D; /* 0x004DD286: jne 0x4dd28d */

L_004DD288:
    goto L_004DD46B; /* 0x004DD288: jmp 0x4dd46b */

L_004DD28D:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004DD28D: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + 0xC), 0)) goto L_004DD2A4; /* 0x004DD291: je 0x4dd2a4 */

L_004DD293:
    edx = MEM32(ebp + 0xC); /* 0x004DD293: mov edx, dword ptr [ebp + 0xc] */
    eax = MEM32(ebp + 0x10); /* 0x004DD296: mov eax, dword ptr [ebp + 0x10] */
    MEM32(edx) = eax; /* 0x004DD299: mov dword ptr [edx], eax */
    ecx = MEM32(ebp + 0xC); /* 0x004DD29B: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx + 4; /* 0x004DD29E: add ecx, 4 */
    MEM32(ebp + 0xC) = ecx; /* 0x004DD2A1: mov dword ptr [ebp + 0xc], ecx */

L_004DD2A4:
    edx = MEM32(ebp + 0x14); /* 0x004DD2A4: mov edx, dword ptr [ebp + 0x14] */
    eax = MEM32(edx); /* 0x004DD2A7: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD2A9: add eax, 1 */
    ecx = MEM32(ebp + 0x14); /* 0x004DD2AC: mov ecx, dword ptr [ebp + 0x14] */
    MEM32(ecx) = eax; /* 0x004DD2AF: mov dword ptr [ecx], eax */

L_004DD2B1:
    MEM32(ebp + (-0x8)) = 1; /* 0x004DD2B1: mov dword ptr [ebp - 8], 1 */
    MEM32(ebp + (-0x10)) = 0; /* 0x004DD2B8: mov dword ptr [ebp - 0x10], 0 */

L_004DD2BF:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD2BF: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD2C2: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x5Cu */ /* 0x004DD2C5: cmp eax, 0x5c */
    if (CMP_NE(eax, 0x5Cu)) goto L_004DD2DE; /* 0x004DD2C8: jne 0x4dd2de */

L_004DD2CA:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD2CA: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DD2CD: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DD2D0: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + (-0x10)); /* 0x004DD2D3: mov edx, dword ptr [ebp - 0x10] */
    edx = edx + 1; /* 0x004DD2D6: add edx, 1 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DD2D9: mov dword ptr [ebp - 0x10], edx */
    goto L_004DD2BF; /* 0x004DD2DC: jmp 0x4dd2bf */

L_004DD2DE:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD2DE: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD2E1: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x22u */ /* 0x004DD2E4: cmp ecx, 0x22 */
    if (CMP_NE(ecx, 0x22u)) goto L_004DD33A; /* 0x004DD2E7: jne 0x4dd33a */

L_004DD2E9:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD2E9: mov eax, dword ptr [ebp - 0x10] */
    edx = 0; /* 0x004DD2EC: xor edx, edx */
    ecx = 2; /* 0x004DD2EE: mov ecx, 2 */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax; /* 0x004DD2F3: div ecx */
      eax = (uint32_t)(_dividend / (uint32_t)ecx);
      edx = (uint32_t)(_dividend % (uint32_t)ecx); }
    /* test edx, edx */ /* 0x004DD2F5: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004DD332; /* 0x004DD2F7: jne 0x4dd332 */

L_004DD2F9:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD2F9: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x14)), 0)) goto L_004DD31F; /* 0x004DD2FD: je 0x4dd31f */

L_004DD2FF:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD2FF: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx + 0x1); /* 0x004DD302: movsx eax, byte ptr [edx + 1] */
    /* cmp eax, 0x22u */ /* 0x004DD306: cmp eax, 0x22 */
    if (CMP_NE(eax, 0x22u)) goto L_004DD316; /* 0x004DD309: jne 0x4dd316 */

L_004DD30B:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD30B: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DD30E: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DD311: mov dword ptr [ebp - 4], ecx */
    goto L_004DD31D; /* 0x004DD314: jmp 0x4dd31d */

L_004DD316:
    MEM32(ebp + (-0x8)) = 0; /* 0x004DD316: mov dword ptr [ebp - 8], 0 */

L_004DD31D:
    goto L_004DD326; /* 0x004DD31D: jmp 0x4dd326 */

L_004DD31F:
    MEM32(ebp + (-0x8)) = 0; /* 0x004DD31F: mov dword ptr [ebp - 8], 0 */

L_004DD326:
    edx = 0; /* 0x004DD326: xor edx, edx */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD328: cmp dword ptr [ebp - 0x14], 0 */
    SET_LO8(edx, (CMP_EQ(MEM32(ebp + (-0x14)), 0)) ? 1 : 0); /* 0x004DD32C: sete dl */
    MEM32(ebp + (-0x14)) = edx; /* 0x004DD32F: mov dword ptr [ebp - 0x14], edx */

L_004DD332:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD332: mov eax, dword ptr [ebp - 0x10] */
    eax = eax >> 1; /* 0x004DD335: shr eax, 1 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DD337: mov dword ptr [ebp - 0x10], eax */

L_004DD33A:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD33A: mov ecx, dword ptr [ebp - 0x10] */
    edx = MEM32(ebp + (-0x10)); /* 0x004DD33D: mov edx, dword ptr [ebp - 0x10] */
    edx = edx - 1; /* 0x004DD340: sub edx, 1 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DD343: mov dword ptr [ebp - 0x10], edx */
    /* test ecx, ecx */ /* 0x004DD346: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD36E; /* 0x004DD348: je 0x4dd36e */

L_004DD34A:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD34A: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD35F; /* 0x004DD34E: je 0x4dd35f */

L_004DD350:
    eax = MEM32(ebp + 0x10); /* 0x004DD350: mov eax, dword ptr [ebp + 0x10] */
    MEM8(eax) = (uint8_t)(0x5Cu); /* 0x004DD353: mov byte ptr [eax], 0x5c */
    ecx = MEM32(ebp + 0x10); /* 0x004DD356: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx + 1; /* 0x004DD359: add ecx, 1 */
    MEM32(ebp + 0x10) = ecx; /* 0x004DD35C: mov dword ptr [ebp + 0x10], ecx */

L_004DD35F:
    edx = MEM32(ebp + 0x18); /* 0x004DD35F: mov edx, dword ptr [ebp + 0x18] */
    eax = MEM32(edx); /* 0x004DD362: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD364: add eax, 1 */
    ecx = MEM32(ebp + 0x18); /* 0x004DD367: mov ecx, dword ptr [ebp + 0x18] */
    MEM32(ecx) = eax; /* 0x004DD36A: mov dword ptr [ecx], eax */
    goto L_004DD33A; /* 0x004DD36C: jmp 0x4dd33a */

L_004DD36E:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD36E: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD371: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD374: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD394; /* 0x004DD376: je 0x4dd394 */

L_004DD378:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD378: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004DD399; /* 0x004DD37C: jne 0x4dd399 */

L_004DD37E:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD37E: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DD381: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x20u */ /* 0x004DD384: cmp edx, 0x20 */
    if (CMP_EQ(edx, 0x20u)) goto L_004DD394; /* 0x004DD387: je 0x4dd394 */

L_004DD389:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD389: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD38C: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 9 */ /* 0x004DD38F: cmp ecx, 9 */
    if (CMP_NE(ecx, 9)) goto L_004DD399; /* 0x004DD392: jne 0x4dd399 */

L_004DD394:
    goto L_004DD444; /* 0x004DD394: jmp 0x4dd444 */

L_004DD399:
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004DD399: cmp dword ptr [ebp - 8], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x8)), 0)) goto L_004DD436; /* 0x004DD39D: je 0x4dd436 */

L_004DD3A3:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD3A3: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD3FD; /* 0x004DD3A7: je 0x4dd3fd */

L_004DD3A9:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3A9: mov edx, dword ptr [ebp - 4] */
    eax = 0; /* 0x004DD3AC: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD3AE: mov al, byte ptr [edx] */
    ecx = 0; /* 0x004DD3B0: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DD3B2: mov cl, byte ptr [eax + 0x84b991] */
    ecx = ecx & 4; /* 0x004DD3B8: and ecx, 4 */
    /* test ecx, ecx */ /* 0x004DD3BB: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD3E8; /* 0x004DD3BD: je 0x4dd3e8 */

L_004DD3BF:
    edx = MEM32(ebp + 0x10); /* 0x004DD3BF: mov edx, dword ptr [ebp + 0x10] */
    eax = MEM32(ebp + (-0x4)); /* 0x004DD3C2: mov eax, dword ptr [ebp - 4] */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DD3C5: mov cl, byte ptr [eax] */
    MEM8(edx) = (uint8_t)(LO8(ecx)); /* 0x004DD3C7: mov byte ptr [edx], cl */
    edx = MEM32(ebp + 0x10); /* 0x004DD3C9: mov edx, dword ptr [ebp + 0x10] */
    edx = edx + 1; /* 0x004DD3CC: add edx, 1 */
    MEM32(ebp + 0x10) = edx; /* 0x004DD3CF: mov dword ptr [ebp + 0x10], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DD3D2: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DD3D5: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD3D8: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + 0x18); /* 0x004DD3DB: mov ecx, dword ptr [ebp + 0x18] */
    edx = MEM32(ecx); /* 0x004DD3DE: mov edx, dword ptr [ecx] */
    edx = edx + 1; /* 0x004DD3E0: add edx, 1 */
    eax = MEM32(ebp + 0x18); /* 0x004DD3E3: mov eax, dword ptr [ebp + 0x18] */
    MEM32(eax) = edx; /* 0x004DD3E6: mov dword ptr [eax], edx */

L_004DD3E8:
    ecx = MEM32(ebp + 0x10); /* 0x004DD3E8: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3EB: mov edx, dword ptr [ebp - 4] */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD3EE: mov al, byte ptr [edx] */
    MEM8(ecx) = (uint8_t)(LO8(eax)); /* 0x004DD3F0: mov byte ptr [ecx], al */
    ecx = MEM32(ebp + 0x10); /* 0x004DD3F2: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx + 1; /* 0x004DD3F5: add ecx, 1 */
    MEM32(ebp + 0x10) = ecx; /* 0x004DD3F8: mov dword ptr [ebp + 0x10], ecx */
    goto L_004DD429; /* 0x004DD3FB: jmp 0x4dd429 */

L_004DD3FD:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3FD: mov edx, dword ptr [ebp - 4] */
    eax = 0; /* 0x004DD400: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD402: mov al, byte ptr [edx] */
    ecx = 0; /* 0x004DD404: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DD406: mov cl, byte ptr [eax + 0x84b991] */
    ecx = ecx & 4; /* 0x004DD40C: and ecx, 4 */
    /* test ecx, ecx */ /* 0x004DD40F: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD429; /* 0x004DD411: je 0x4dd429 */

L_004DD413:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD413: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD416: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD419: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + 0x18); /* 0x004DD41C: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD41F: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD421: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD424: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD427: mov dword ptr [edx], ecx */

L_004DD429:
    eax = MEM32(ebp + 0x18); /* 0x004DD429: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD42C: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD42E: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD431: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD434: mov dword ptr [edx], ecx */

L_004DD436:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD436: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DD439: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD43C: mov dword ptr [ebp - 4], eax */
    goto L_004DD2B1; /* 0x004DD43F: jmp 0x4dd2b1 */

L_004DD444:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD444: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD459; /* 0x004DD448: je 0x4dd459 */

L_004DD44A:
    ecx = MEM32(ebp + 0x10); /* 0x004DD44A: mov ecx, dword ptr [ebp + 0x10] */
    MEM8(ecx) = (uint8_t)(0); /* 0x004DD44D: mov byte ptr [ecx], 0 */
    edx = MEM32(ebp + 0x10); /* 0x004DD450: mov edx, dword ptr [ebp + 0x10] */
    edx = edx + 1; /* 0x004DD453: add edx, 1 */
    MEM32(ebp + 0x10) = edx; /* 0x004DD456: mov dword ptr [ebp + 0x10], edx */

L_004DD459:
    eax = MEM32(ebp + 0x18); /* 0x004DD459: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD45C: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD45E: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD461: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD464: mov dword ptr [edx], ecx */
    goto L_004DD253; /* 0x004DD466: jmp 0x4dd253 */

L_004DD46B:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004DD46B: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + 0xC), 0)) goto L_004DD483; /* 0x004DD46F: je 0x4dd483 */

L_004DD471:
    eax = MEM32(ebp + 0xC); /* 0x004DD471: mov eax, dword ptr [ebp + 0xc] */
    MEM32(eax) = 0; /* 0x004DD474: mov dword ptr [eax], 0 */
    ecx = MEM32(ebp + 0xC); /* 0x004DD47A: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx + 4; /* 0x004DD47D: add ecx, 4 */
    MEM32(ebp + 0xC) = ecx; /* 0x004DD480: mov dword ptr [ebp + 0xc], ecx */

L_004DD483:
    edx = MEM32(ebp + 0x14); /* 0x004DD483: mov edx, dword ptr [ebp + 0x14] */
    eax = MEM32(edx); /* 0x004DD486: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD488: add eax, 1 */
    ecx = MEM32(ebp + 0x14); /* 0x004DD48B: mov ecx, dword ptr [ebp + 0x14] */
    MEM32(ecx) = eax; /* 0x004DD48E: mov dword ptr [ecx], eax */
    esp = ebp; /* 0x004DD490: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD492: pop ebp */
    return; /* 0x004DD493: ret  */

}

void sub_004DD312(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD253:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD253: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD256: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD259: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD27E; /* 0x004DD25B: je 0x4dd27e */

L_004DD25D:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD25D: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DD260: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x20u */ /* 0x004DD263: cmp edx, 0x20 */
    if (CMP_EQ(edx, 0x20u)) goto L_004DD273; /* 0x004DD266: je 0x4dd273 */

L_004DD268:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD268: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD26B: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 9 */ /* 0x004DD26E: cmp ecx, 9 */
    if (CMP_NE(ecx, 9)) goto L_004DD27E; /* 0x004DD271: jne 0x4dd27e */

L_004DD273:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD273: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD276: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD279: mov dword ptr [ebp - 4], edx */
    goto L_004DD25D; /* 0x004DD27C: jmp 0x4dd25d */

L_004DD27E:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD27E: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD281: movsx ecx, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DD284: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DD28D; /* 0x004DD286: jne 0x4dd28d */

L_004DD288:
    goto L_004DD46B; /* 0x004DD288: jmp 0x4dd46b */

L_004DD28D:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004DD28D: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + 0xC), 0)) goto L_004DD2A4; /* 0x004DD291: je 0x4dd2a4 */

L_004DD293:
    edx = MEM32(ebp + 0xC); /* 0x004DD293: mov edx, dword ptr [ebp + 0xc] */
    eax = MEM32(ebp + 0x10); /* 0x004DD296: mov eax, dword ptr [ebp + 0x10] */
    MEM32(edx) = eax; /* 0x004DD299: mov dword ptr [edx], eax */
    ecx = MEM32(ebp + 0xC); /* 0x004DD29B: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx + 4; /* 0x004DD29E: add ecx, 4 */
    MEM32(ebp + 0xC) = ecx; /* 0x004DD2A1: mov dword ptr [ebp + 0xc], ecx */

L_004DD2A4:
    edx = MEM32(ebp + 0x14); /* 0x004DD2A4: mov edx, dword ptr [ebp + 0x14] */
    eax = MEM32(edx); /* 0x004DD2A7: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD2A9: add eax, 1 */
    ecx = MEM32(ebp + 0x14); /* 0x004DD2AC: mov ecx, dword ptr [ebp + 0x14] */
    MEM32(ecx) = eax; /* 0x004DD2AF: mov dword ptr [ecx], eax */

L_004DD2B1:
    MEM32(ebp + (-0x8)) = 1; /* 0x004DD2B1: mov dword ptr [ebp - 8], 1 */
    MEM32(ebp + (-0x10)) = 0; /* 0x004DD2B8: mov dword ptr [ebp - 0x10], 0 */

L_004DD2BF:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD2BF: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD2C2: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x5Cu */ /* 0x004DD2C5: cmp eax, 0x5c */
    if (CMP_NE(eax, 0x5Cu)) goto L_004DD2DE; /* 0x004DD2C8: jne 0x4dd2de */

L_004DD2CA:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD2CA: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DD2CD: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DD2D0: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + (-0x10)); /* 0x004DD2D3: mov edx, dword ptr [ebp - 0x10] */
    edx = edx + 1; /* 0x004DD2D6: add edx, 1 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DD2D9: mov dword ptr [ebp - 0x10], edx */
    goto L_004DD2BF; /* 0x004DD2DC: jmp 0x4dd2bf */

L_004DD2DE:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD2DE: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD2E1: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x22u */ /* 0x004DD2E4: cmp ecx, 0x22 */
    if (CMP_NE(ecx, 0x22u)) goto L_004DD33A; /* 0x004DD2E7: jne 0x4dd33a */

L_004DD2E9:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD2E9: mov eax, dword ptr [ebp - 0x10] */
    edx = 0; /* 0x004DD2EC: xor edx, edx */
    ecx = 2; /* 0x004DD2EE: mov ecx, 2 */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax; /* 0x004DD2F3: div ecx */
      eax = (uint32_t)(_dividend / (uint32_t)ecx);
      edx = (uint32_t)(_dividend % (uint32_t)ecx); }
    /* test edx, edx */ /* 0x004DD2F5: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004DD332; /* 0x004DD2F7: jne 0x4dd332 */

L_004DD2F9:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD2F9: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x14)), 0)) goto L_004DD31F; /* 0x004DD2FD: je 0x4dd31f */

L_004DD2FF:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD2FF: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx + 0x1); /* 0x004DD302: movsx eax, byte ptr [edx + 1] */
    /* cmp eax, 0x22u */ /* 0x004DD306: cmp eax, 0x22 */
    if (CMP_NE(eax, 0x22u)) goto L_004DD316; /* 0x004DD309: jne 0x4dd316 */

L_004DD30B:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD30B: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DD30E: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DD311: mov dword ptr [ebp - 4], ecx */
    goto L_004DD31D; /* 0x004DD314: jmp 0x4dd31d */

L_004DD312:
    ebp = ebp - 1; /* 0x004DD312: dec ebp */
    _df = 1; /* 0x004DD313: cld  */
    goto L_004DD31D; /* 0x004DD314: jmp 0x4dd31d */

L_004DD316:
    MEM32(ebp + (-0x8)) = 0; /* 0x004DD316: mov dword ptr [ebp - 8], 0 */

L_004DD31D:
    goto L_004DD326; /* 0x004DD31D: jmp 0x4dd326 */

L_004DD31F:
    MEM32(ebp + (-0x8)) = 0; /* 0x004DD31F: mov dword ptr [ebp - 8], 0 */

L_004DD326:
    edx = 0; /* 0x004DD326: xor edx, edx */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD328: cmp dword ptr [ebp - 0x14], 0 */
    SET_LO8(edx, (CMP_EQ(MEM32(ebp + (-0x14)), 0)) ? 1 : 0); /* 0x004DD32C: sete dl */
    MEM32(ebp + (-0x14)) = edx; /* 0x004DD32F: mov dword ptr [ebp - 0x14], edx */

L_004DD332:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD332: mov eax, dword ptr [ebp - 0x10] */
    eax = eax >> 1; /* 0x004DD335: shr eax, 1 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DD337: mov dword ptr [ebp - 0x10], eax */

L_004DD33A:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD33A: mov ecx, dword ptr [ebp - 0x10] */
    edx = MEM32(ebp + (-0x10)); /* 0x004DD33D: mov edx, dword ptr [ebp - 0x10] */
    edx = edx - 1; /* 0x004DD340: sub edx, 1 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DD343: mov dword ptr [ebp - 0x10], edx */
    /* test ecx, ecx */ /* 0x004DD346: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD36E; /* 0x004DD348: je 0x4dd36e */

L_004DD34A:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD34A: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD35F; /* 0x004DD34E: je 0x4dd35f */

L_004DD350:
    eax = MEM32(ebp + 0x10); /* 0x004DD350: mov eax, dword ptr [ebp + 0x10] */
    MEM8(eax) = (uint8_t)(0x5Cu); /* 0x004DD353: mov byte ptr [eax], 0x5c */
    ecx = MEM32(ebp + 0x10); /* 0x004DD356: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx + 1; /* 0x004DD359: add ecx, 1 */
    MEM32(ebp + 0x10) = ecx; /* 0x004DD35C: mov dword ptr [ebp + 0x10], ecx */

L_004DD35F:
    edx = MEM32(ebp + 0x18); /* 0x004DD35F: mov edx, dword ptr [ebp + 0x18] */
    eax = MEM32(edx); /* 0x004DD362: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD364: add eax, 1 */
    ecx = MEM32(ebp + 0x18); /* 0x004DD367: mov ecx, dword ptr [ebp + 0x18] */
    MEM32(ecx) = eax; /* 0x004DD36A: mov dword ptr [ecx], eax */
    goto L_004DD33A; /* 0x004DD36C: jmp 0x4dd33a */

L_004DD36E:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD36E: mov edx, dword ptr [ebp - 4] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD371: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD374: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD394; /* 0x004DD376: je 0x4dd394 */

L_004DD378:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD378: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004DD399; /* 0x004DD37C: jne 0x4dd399 */

L_004DD37E:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DD37E: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DD381: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x20u */ /* 0x004DD384: cmp edx, 0x20 */
    if (CMP_EQ(edx, 0x20u)) goto L_004DD394; /* 0x004DD387: je 0x4dd394 */

L_004DD389:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD389: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD38C: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 9 */ /* 0x004DD38F: cmp ecx, 9 */
    if (CMP_NE(ecx, 9)) goto L_004DD399; /* 0x004DD392: jne 0x4dd399 */

L_004DD394:
    goto L_004DD444; /* 0x004DD394: jmp 0x4dd444 */

L_004DD399:
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004DD399: cmp dword ptr [ebp - 8], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x8)), 0)) goto L_004DD436; /* 0x004DD39D: je 0x4dd436 */

L_004DD3A3:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD3A3: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD3FD; /* 0x004DD3A7: je 0x4dd3fd */

L_004DD3A9:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3A9: mov edx, dword ptr [ebp - 4] */
    eax = 0; /* 0x004DD3AC: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD3AE: mov al, byte ptr [edx] */
    ecx = 0; /* 0x004DD3B0: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DD3B2: mov cl, byte ptr [eax + 0x84b991] */
    ecx = ecx & 4; /* 0x004DD3B8: and ecx, 4 */
    /* test ecx, ecx */ /* 0x004DD3BB: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD3E8; /* 0x004DD3BD: je 0x4dd3e8 */

L_004DD3BF:
    edx = MEM32(ebp + 0x10); /* 0x004DD3BF: mov edx, dword ptr [ebp + 0x10] */
    eax = MEM32(ebp + (-0x4)); /* 0x004DD3C2: mov eax, dword ptr [ebp - 4] */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DD3C5: mov cl, byte ptr [eax] */
    MEM8(edx) = (uint8_t)(LO8(ecx)); /* 0x004DD3C7: mov byte ptr [edx], cl */
    edx = MEM32(ebp + 0x10); /* 0x004DD3C9: mov edx, dword ptr [ebp + 0x10] */
    edx = edx + 1; /* 0x004DD3CC: add edx, 1 */
    MEM32(ebp + 0x10) = edx; /* 0x004DD3CF: mov dword ptr [ebp + 0x10], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DD3D2: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DD3D5: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD3D8: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + 0x18); /* 0x004DD3DB: mov ecx, dword ptr [ebp + 0x18] */
    edx = MEM32(ecx); /* 0x004DD3DE: mov edx, dword ptr [ecx] */
    edx = edx + 1; /* 0x004DD3E0: add edx, 1 */
    eax = MEM32(ebp + 0x18); /* 0x004DD3E3: mov eax, dword ptr [ebp + 0x18] */
    MEM32(eax) = edx; /* 0x004DD3E6: mov dword ptr [eax], edx */

L_004DD3E8:
    ecx = MEM32(ebp + 0x10); /* 0x004DD3E8: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3EB: mov edx, dword ptr [ebp - 4] */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD3EE: mov al, byte ptr [edx] */
    MEM8(ecx) = (uint8_t)(LO8(eax)); /* 0x004DD3F0: mov byte ptr [ecx], al */
    ecx = MEM32(ebp + 0x10); /* 0x004DD3F2: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx + 1; /* 0x004DD3F5: add ecx, 1 */
    MEM32(ebp + 0x10) = ecx; /* 0x004DD3F8: mov dword ptr [ebp + 0x10], ecx */
    goto L_004DD429; /* 0x004DD3FB: jmp 0x4dd429 */

L_004DD3FD:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD3FD: mov edx, dword ptr [ebp - 4] */
    eax = 0; /* 0x004DD400: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004DD402: mov al, byte ptr [edx] */
    ecx = 0; /* 0x004DD404: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DD406: mov cl, byte ptr [eax + 0x84b991] */
    ecx = ecx & 4; /* 0x004DD40C: and ecx, 4 */
    /* test ecx, ecx */ /* 0x004DD40F: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD429; /* 0x004DD411: je 0x4dd429 */

L_004DD413:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD413: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DD416: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DD419: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + 0x18); /* 0x004DD41C: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD41F: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD421: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD424: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD427: mov dword ptr [edx], ecx */

L_004DD429:
    eax = MEM32(ebp + 0x18); /* 0x004DD429: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD42C: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD42E: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD431: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD434: mov dword ptr [edx], ecx */

L_004DD436:
    eax = MEM32(ebp + (-0x4)); /* 0x004DD436: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DD439: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD43C: mov dword ptr [ebp - 4], eax */
    goto L_004DD2B1; /* 0x004DD43F: jmp 0x4dd2b1 */

L_004DD444:
    /* cmp MEM32(ebp + 0x10), 0 */ /* 0x004DD444: cmp dword ptr [ebp + 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + 0x10), 0)) goto L_004DD459; /* 0x004DD448: je 0x4dd459 */

L_004DD44A:
    ecx = MEM32(ebp + 0x10); /* 0x004DD44A: mov ecx, dword ptr [ebp + 0x10] */
    MEM8(ecx) = (uint8_t)(0); /* 0x004DD44D: mov byte ptr [ecx], 0 */
    edx = MEM32(ebp + 0x10); /* 0x004DD450: mov edx, dword ptr [ebp + 0x10] */
    edx = edx + 1; /* 0x004DD453: add edx, 1 */
    MEM32(ebp + 0x10) = edx; /* 0x004DD456: mov dword ptr [ebp + 0x10], edx */

L_004DD459:
    eax = MEM32(ebp + 0x18); /* 0x004DD459: mov eax, dword ptr [ebp + 0x18] */
    ecx = MEM32(eax); /* 0x004DD45C: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DD45E: add ecx, 1 */
    edx = MEM32(ebp + 0x18); /* 0x004DD461: mov edx, dword ptr [ebp + 0x18] */
    MEM32(edx) = ecx; /* 0x004DD464: mov dword ptr [edx], ecx */
    goto L_004DD253; /* 0x004DD466: jmp 0x4dd253 */

L_004DD46B:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004DD46B: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + 0xC), 0)) goto L_004DD483; /* 0x004DD46F: je 0x4dd483 */

L_004DD471:
    eax = MEM32(ebp + 0xC); /* 0x004DD471: mov eax, dword ptr [ebp + 0xc] */
    MEM32(eax) = 0; /* 0x004DD474: mov dword ptr [eax], 0 */
    ecx = MEM32(ebp + 0xC); /* 0x004DD47A: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx + 4; /* 0x004DD47D: add ecx, 4 */
    MEM32(ebp + 0xC) = ecx; /* 0x004DD480: mov dword ptr [ebp + 0xc], ecx */

L_004DD483:
    edx = MEM32(ebp + 0x14); /* 0x004DD483: mov edx, dword ptr [ebp + 0x14] */
    eax = MEM32(edx); /* 0x004DD486: mov eax, dword ptr [edx] */
    eax = eax + 1; /* 0x004DD488: add eax, 1 */
    ecx = MEM32(ebp + 0x14); /* 0x004DD48B: mov ecx, dword ptr [ebp + 0x14] */
    MEM32(ecx) = eax; /* 0x004DD48E: mov dword ptr [ecx], eax */
    esp = ebp; /* 0x004DD490: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD492: pop ebp */
    return; /* 0x004DD493: ret  */

}

void sub_004DD4D0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD4D0:
    /* test MEM8(eax), LO8(eax) */ /* 0x004DD4D0: test byte ptr [eax], al */
    MEM32(eax) = MEM32(eax) + eax; /* 0x004DD4D2: add dword ptr [eax], eax */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DD4D4: add byte ptr [eax], al */
    goto L_004DD4FA; /* 0x004DD4D6: jmp 0x4dd4fa */

L_004DD4FA:
    /* cmp MEM32(0x84B984), 1 */ /* 0x004DD4FA: cmp dword ptr [0x84b984], 1 */
    if (CMP_NE(MEM32(0x84B984), 1)) goto L_004DD5B6; /* 0x004DD501: jne 0x4dd5b6 */

L_004DD507:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD507: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004DD523; /* 0x004DD50B: jne 0x4dd523 */

L_004DD50D:
    RECOMP_ICALL(MEM32(0x8586E4)); /* 0x004DD50D: call dword ptr [0x8586e4] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004DD513: mov dword ptr [ebp - 0x14], eax */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD516: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004DD523; /* 0x004DD51A: jne 0x4dd523 */

L_004DD51C:
    eax = 0; /* 0x004DD51C: xor eax, eax */
    goto L_004DD715; /* 0x004DD51E: jmp 0x4dd715 */

L_004DD523:
    eax = MEM32(ebp + (-0x14)); /* 0x004DD523: mov eax, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DD526: mov dword ptr [ebp - 0x10], eax */

L_004DD529:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD529: mov ecx, dword ptr [ebp - 0x10] */
    edx = 0; /* 0x004DD52C: xor edx, edx */
    SET_LO16(edx, MEM16(ecx)); /* 0x004DD52E: mov dx, word ptr [ecx] */
    /* test edx, edx */ /* 0x004DD531: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DD555; /* 0x004DD533: je 0x4dd555 */

L_004DD535:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD535: mov eax, dword ptr [ebp - 0x10] */
    eax = eax + 2; /* 0x004DD538: add eax, 2 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DD53B: mov dword ptr [ebp - 0x10], eax */
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD53E: mov ecx, dword ptr [ebp - 0x10] */
    edx = 0; /* 0x004DD541: xor edx, edx */
    SET_LO16(edx, MEM16(ecx)); /* 0x004DD543: mov dx, word ptr [ecx] */
    /* test edx, edx */ /* 0x004DD546: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004DD553; /* 0x004DD548: jne 0x4dd553 */

L_004DD54A:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD54A: mov eax, dword ptr [ebp - 0x10] */
    eax = eax + 2; /* 0x004DD54D: add eax, 2 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DD550: mov dword ptr [ebp - 0x10], eax */

L_004DD553:
    goto L_004DD529; /* 0x004DD553: jmp 0x4dd529 */

L_004DD555:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD555: mov ecx, dword ptr [ebp - 0x10] */
    ecx = ecx - MEM32(ebp + (-0x14)); /* 0x004DD558: sub ecx, dword ptr [ebp - 0x14] */
    ecx = ecx + 2; /* 0x004DD55B: add ecx, 2 */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DD55E: mov dword ptr [ebp - 0xc], ecx */
    PUSH32(esp, 0x57u); /* 0x004DD561: push 0x57 */
    PUSH32(esp, 0x004F43D0u); /* 0x004DD563: push 0x4f43d0 */
    PUSH32(esp, 2); /* 0x004DD568: push 2 */
    edx = MEM32(ebp + (-0xC)); /* 0x004DD56A: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004DD56D: push edx */
    RECOMP_CALL(sub_004D25A0); /* 0x004DD56E: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DD573: add esp, 0x10 */
    MEM32(ebp + (-0x18)) = eax; /* 0x004DD576: mov dword ptr [ebp - 0x18], eax */
    /* cmp MEM32(ebp + (-0x18)), 0 */ /* 0x004DD579: cmp dword ptr [ebp - 0x18], 0 */
    if (CMP_NE(MEM32(ebp + (-0x18)), 0)) goto L_004DD590; /* 0x004DD57D: jne 0x4dd590 */

L_004DD57F:
    eax = MEM32(ebp + (-0x14)); /* 0x004DD57F: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004DD582: push eax */
    RECOMP_ICALL(MEM32(0x8586EC)); /* 0x004DD583: call dword ptr [0x8586ec] */
    eax = 0; /* 0x004DD589: xor eax, eax */
    goto L_004DD715; /* 0x004DD58B: jmp 0x4dd715 */

L_004DD590:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD590: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004DD593: push ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004DD594: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004DD597: push edx */
    eax = MEM32(ebp + (-0x18)); /* 0x004DD598: mov eax, dword ptr [ebp - 0x18] */
    PUSH32(esp, eax); /* 0x004DD59B: push eax */
    RECOMP_CALL(sub_004D58F0); /* 0x004DD59C: call 0x4d58f0 */
    esp = esp + 0xCu; /* 0x004DD5A1: add esp, 0xc */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DD5A4: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004DD5A7: push ecx */
    RECOMP_ICALL(MEM32(0x8586EC)); /* 0x004DD5A8: call dword ptr [0x8586ec] */
    eax = MEM32(ebp + (-0x18)); /* 0x004DD5AE: mov eax, dword ptr [ebp - 0x18] */
    goto L_004DD715; /* 0x004DD5B1: jmp 0x4dd715 */

L_004DD5B6:
    /* cmp MEM32(0x84B984), 2 */ /* 0x004DD5B6: cmp dword ptr [0x84b984], 2 */
    if (CMP_NE(MEM32(0x84B984), 2)) goto L_004DD715; /* 0x004DD5BD: jne 0x4dd715 */

L_004DD5C3:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD5C3: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004DD5DF; /* 0x004DD5C7: jne 0x4dd5df */

L_004DD5C9:
    RECOMP_ICALL(MEM32(0x8586E8)); /* 0x004DD5C9: call dword ptr [0x8586e8] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004DD5CF: mov dword ptr [ebp - 0x14], eax */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD5D2: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004DD5DF; /* 0x004DD5D6: jne 0x4dd5df */

L_004DD5D8:
    eax = 0; /* 0x004DD5D8: xor eax, eax */
    goto L_004DD715; /* 0x004DD5DA: jmp 0x4dd715 */

L_004DD5DF:
    edx = MEM32(ebp + (-0x14)); /* 0x004DD5DF: mov edx, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DD5E2: mov dword ptr [ebp - 8], edx */

L_004DD5E5:
    eax = MEM32(ebp + (-0x8)); /* 0x004DD5E5: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD5E8: movsx ecx, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DD5EB: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD638; /* 0x004DD5ED: je 0x4dd638 */

L_004DD5EF:
    PUSH32(esp, 0); /* 0x004DD5EF: push 0 */
    PUSH32(esp, 0); /* 0x004DD5F1: push 0 */
    PUSH32(esp, 0xFFFFFFFFu); /* 0x004DD5F3: push -1 */
    edx = MEM32(ebp + (-0x8)); /* 0x004DD5F5: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DD5F8: push edx */
    PUSH32(esp, 1); /* 0x004DD5F9: push 1 */
    eax = MEM32(0x84BCD0); /* 0x004DD5FB: mov eax, dword ptr [0x84bcd0] */
    PUSH32(esp, eax); /* 0x004DD600: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004DD601: call dword ptr [0x8586f0] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD607: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DD60A: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004DD617; /* 0x004DD60E: jne 0x4dd617 */

L_004DD610:
    eax = 0; /* 0x004DD610: xor eax, eax */
    goto L_004DD715; /* 0x004DD612: jmp 0x4dd715 */

L_004DD617:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD617: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + MEM32(ebp + (-0x4)); /* 0x004DD61A: add ecx, dword ptr [ebp - 4] */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DD61D: mov dword ptr [ebp - 0xc], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DD620: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DD623: push edx */
    RECOMP_CALL(sub_004D5870); /* 0x004DD624: call 0x4d5870 */
    esp = esp + 4; /* 0x004DD629: add esp, 4 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DD62C: mov ecx, dword ptr [ebp - 8] */
    edx = ecx + eax + 0x1; /* 0x004DD62F: lea edx, [ecx + eax + 1] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DD633: mov dword ptr [ebp - 8], edx */
    goto L_004DD5E5; /* 0x004DD636: jmp 0x4dd5e5 */

L_004DD638:
    eax = MEM32(ebp + (-0xC)); /* 0x004DD638: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 1; /* 0x004DD63B: add eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DD63E: mov dword ptr [ebp - 0xc], eax */
    PUSH32(esp, 0x87u); /* 0x004DD641: push 0x87 */
    PUSH32(esp, 0x004F43D0u); /* 0x004DD646: push 0x4f43d0 */
    PUSH32(esp, 2); /* 0x004DD64B: push 2 */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD64D: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx << 1; /* 0x004DD650: shl ecx, 1 */
    PUSH32(esp, ecx); /* 0x004DD652: push ecx */
    RECOMP_CALL(sub_004D25A0); /* 0x004DD653: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DD658: add esp, 0x10 */
    MEM32(ebp + (-0x18)) = eax; /* 0x004DD65B: mov dword ptr [ebp - 0x18], eax */
    /* cmp MEM32(ebp + (-0x18)), 0 */ /* 0x004DD65E: cmp dword ptr [ebp - 0x18], 0 */
    if (CMP_NE(MEM32(ebp + (-0x18)), 0)) goto L_004DD675; /* 0x004DD662: jne 0x4dd675 */

L_004DD664:
    edx = MEM32(ebp + (-0x14)); /* 0x004DD664: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004DD667: push edx */
    RECOMP_ICALL(MEM32(0x8586F4)); /* 0x004DD668: call dword ptr [0x8586f4] */
    eax = 0; /* 0x004DD66E: xor eax, eax */
    goto L_004DD715; /* 0x004DD670: jmp 0x4dd715 */

L_004DD675:
    eax = MEM32(ebp + (-0x14)); /* 0x004DD675: mov eax, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DD678: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x18)); /* 0x004DD67B: mov ecx, dword ptr [ebp - 0x18] */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004DD67E: mov dword ptr [ebp - 0x10], ecx */

L_004DD681:
    edx = MEM32(ebp + (-0x8)); /* 0x004DD681: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD684: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD687: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD700; /* 0x004DD689: je 0x4dd700 */

L_004DD68B:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD68B: mov ecx, dword ptr [ebp - 0x10] */
    ecx = ecx - MEM32(ebp + (-0x18)); /* 0x004DD68E: sub ecx, dword ptr [ebp - 0x18] */
    ecx = (uint32_t)((int32_t)ecx >> 1); /* 0x004DD691: sar ecx, 1 */
    edx = MEM32(ebp + (-0xC)); /* 0x004DD693: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - ecx; /* 0x004DD696: sub edx, ecx */
    PUSH32(esp, edx); /* 0x004DD698: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004DD699: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004DD69C: push eax */
    PUSH32(esp, 0xFFFFFFFFu); /* 0x004DD69D: push -1 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DD69F: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DD6A2: push ecx */
    PUSH32(esp, 1); /* 0x004DD6A3: push 1 */
    edx = MEM32(0x84BCD0); /* 0x004DD6A5: mov edx, dword ptr [0x84bcd0] */
    PUSH32(esp, edx); /* 0x004DD6AB: push edx */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004DD6AC: call dword ptr [0x8586f0] */
    /* test eax, eax */ /* 0x004DD6B2: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004DD6D2; /* 0x004DD6B4: jne 0x4dd6d2 */

L_004DD6B6:
    PUSH32(esp, 2); /* 0x004DD6B6: push 2 */
    eax = MEM32(ebp + (-0x18)); /* 0x004DD6B8: mov eax, dword ptr [ebp - 0x18] */
    PUSH32(esp, eax); /* 0x004DD6BB: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004DD6BC: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004DD6C1: add esp, 8 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DD6C4: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004DD6C7: push ecx */
    RECOMP_ICALL(MEM32(0x8586F4)); /* 0x004DD6C8: call dword ptr [0x8586f4] */
    eax = 0; /* 0x004DD6CE: xor eax, eax */
    goto L_004DD715; /* 0x004DD6D0: jmp 0x4dd715 */

L_004DD6D2:
    edx = MEM32(ebp + (-0x8)); /* 0x004DD6D2: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DD6D5: push edx */
    RECOMP_CALL(sub_004D5870); /* 0x004DD6D6: call 0x4d5870 */
    esp = esp + 4; /* 0x004DD6DB: add esp, 4 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DD6DE: mov ecx, dword ptr [ebp - 8] */
    edx = ecx + eax + 0x1; /* 0x004DD6E1: lea edx, [ecx + eax + 1] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DD6E5: mov dword ptr [ebp - 8], edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004DD6E8: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004DD6EB: push eax */
    RECOMP_CALL(sub_004E1180); /* 0x004DD6EC: call 0x4e1180 */
    esp = esp + 4; /* 0x004DD6F1: add esp, 4 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD6F4: mov ecx, dword ptr [ebp - 0x10] */
    edx = ecx + eax * 2 + 0x2; /* 0x004DD6F7: lea edx, [ecx + eax*2 + 2] */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DD6FB: mov dword ptr [ebp - 0x10], edx */
    goto L_004DD681; /* 0x004DD6FE: jmp 0x4dd681 */

L_004DD700:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD700: mov eax, dword ptr [ebp - 0x10] */
    MEM16(eax) = (uint16_t)(0); /* 0x004DD703: mov word ptr [eax], 0 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DD708: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004DD70B: push ecx */
    RECOMP_ICALL(MEM32(0x8586F4)); /* 0x004DD70C: call dword ptr [0x8586f4] */
    eax = MEM32(ebp + (-0x18)); /* 0x004DD712: mov eax, dword ptr [ebp - 0x18] */

L_004DD715:
    esp = ebp; /* 0x004DD715: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD717: pop ebp */
    return; /* 0x004DD718: ret  */

}

void sub_004DD5C0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD5C0:
    MEM32(eax) = MEM32(eax) + eax; /* 0x004DD5C0: add dword ptr [eax], eax */
    MEM8(ebx + 0x7500EC7D) = (uint8_t)(MEM8(ebx + 0x7500EC7D) + LO8(eax)); /* 0x004DD5C2: add byte ptr [ebx + 0x7500ec7d], al */
    PUSH32(esp, _seg_ss); /* 0x004DD5C8: push ss */
    RECOMP_ICALL(MEM32(0x8586E8)); /* 0x004DD5C9: call dword ptr [0x8586e8] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004DD5CF: mov dword ptr [ebp - 0x14], eax */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004DD5D2: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004DD5DF; /* 0x004DD5D6: jne 0x4dd5df */

L_004DD5D8:
    eax = 0; /* 0x004DD5D8: xor eax, eax */
    goto L_004DD715; /* 0x004DD5DA: jmp 0x4dd715 */

L_004DD5DF:
    edx = MEM32(ebp + (-0x14)); /* 0x004DD5DF: mov edx, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DD5E2: mov dword ptr [ebp - 8], edx */

L_004DD5E5:
    eax = MEM32(ebp + (-0x8)); /* 0x004DD5E5: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DD5E8: movsx ecx, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DD5EB: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DD638; /* 0x004DD5ED: je 0x4dd638 */

L_004DD5EF:
    PUSH32(esp, 0); /* 0x004DD5EF: push 0 */
    PUSH32(esp, 0); /* 0x004DD5F1: push 0 */
    PUSH32(esp, 0xFFFFFFFFu); /* 0x004DD5F3: push -1 */
    edx = MEM32(ebp + (-0x8)); /* 0x004DD5F5: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DD5F8: push edx */
    PUSH32(esp, 1); /* 0x004DD5F9: push 1 */
    eax = MEM32(0x84BCD0); /* 0x004DD5FB: mov eax, dword ptr [0x84bcd0] */
    PUSH32(esp, eax); /* 0x004DD600: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004DD601: call dword ptr [0x8586f0] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DD607: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DD60A: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004DD617; /* 0x004DD60E: jne 0x4dd617 */

L_004DD610:
    eax = 0; /* 0x004DD610: xor eax, eax */
    goto L_004DD715; /* 0x004DD612: jmp 0x4dd715 */

L_004DD617:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD617: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + MEM32(ebp + (-0x4)); /* 0x004DD61A: add ecx, dword ptr [ebp - 4] */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DD61D: mov dword ptr [ebp - 0xc], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DD620: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DD623: push edx */
    RECOMP_CALL(sub_004D5870); /* 0x004DD624: call 0x4d5870 */
    esp = esp + 4; /* 0x004DD629: add esp, 4 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DD62C: mov ecx, dword ptr [ebp - 8] */
    edx = ecx + eax + 0x1; /* 0x004DD62F: lea edx, [ecx + eax + 1] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DD633: mov dword ptr [ebp - 8], edx */
    goto L_004DD5E5; /* 0x004DD636: jmp 0x4dd5e5 */

L_004DD638:
    eax = MEM32(ebp + (-0xC)); /* 0x004DD638: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 1; /* 0x004DD63B: add eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DD63E: mov dword ptr [ebp - 0xc], eax */
    PUSH32(esp, 0x87u); /* 0x004DD641: push 0x87 */
    PUSH32(esp, 0x004F43D0u); /* 0x004DD646: push 0x4f43d0 */
    PUSH32(esp, 2); /* 0x004DD64B: push 2 */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD64D: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx << 1; /* 0x004DD650: shl ecx, 1 */
    PUSH32(esp, ecx); /* 0x004DD652: push ecx */
    RECOMP_CALL(sub_004D25A0); /* 0x004DD653: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DD658: add esp, 0x10 */
    MEM32(ebp + (-0x18)) = eax; /* 0x004DD65B: mov dword ptr [ebp - 0x18], eax */
    /* cmp MEM32(ebp + (-0x18)), 0 */ /* 0x004DD65E: cmp dword ptr [ebp - 0x18], 0 */
    if (CMP_NE(MEM32(ebp + (-0x18)), 0)) goto L_004DD675; /* 0x004DD662: jne 0x4dd675 */

L_004DD664:
    edx = MEM32(ebp + (-0x14)); /* 0x004DD664: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004DD667: push edx */
    RECOMP_ICALL(MEM32(0x8586F4)); /* 0x004DD668: call dword ptr [0x8586f4] */
    eax = 0; /* 0x004DD66E: xor eax, eax */
    goto L_004DD715; /* 0x004DD670: jmp 0x4dd715 */

L_004DD675:
    eax = MEM32(ebp + (-0x14)); /* 0x004DD675: mov eax, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DD678: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x18)); /* 0x004DD67B: mov ecx, dword ptr [ebp - 0x18] */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004DD67E: mov dword ptr [ebp - 0x10], ecx */

L_004DD681:
    edx = MEM32(ebp + (-0x8)); /* 0x004DD681: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DD684: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DD687: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DD700; /* 0x004DD689: je 0x4dd700 */

L_004DD68B:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD68B: mov ecx, dword ptr [ebp - 0x10] */
    ecx = ecx - MEM32(ebp + (-0x18)); /* 0x004DD68E: sub ecx, dword ptr [ebp - 0x18] */
    ecx = (uint32_t)((int32_t)ecx >> 1); /* 0x004DD691: sar ecx, 1 */
    edx = MEM32(ebp + (-0xC)); /* 0x004DD693: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - ecx; /* 0x004DD696: sub edx, ecx */
    PUSH32(esp, edx); /* 0x004DD698: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004DD699: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004DD69C: push eax */
    PUSH32(esp, 0xFFFFFFFFu); /* 0x004DD69D: push -1 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DD69F: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DD6A2: push ecx */
    PUSH32(esp, 1); /* 0x004DD6A3: push 1 */
    edx = MEM32(0x84BCD0); /* 0x004DD6A5: mov edx, dword ptr [0x84bcd0] */
    PUSH32(esp, edx); /* 0x004DD6AB: push edx */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004DD6AC: call dword ptr [0x8586f0] */
    /* test eax, eax */ /* 0x004DD6B2: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004DD6D2; /* 0x004DD6B4: jne 0x4dd6d2 */

L_004DD6B6:
    PUSH32(esp, 2); /* 0x004DD6B6: push 2 */
    eax = MEM32(ebp + (-0x18)); /* 0x004DD6B8: mov eax, dword ptr [ebp - 0x18] */
    PUSH32(esp, eax); /* 0x004DD6BB: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004DD6BC: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004DD6C1: add esp, 8 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DD6C4: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004DD6C7: push ecx */
    RECOMP_ICALL(MEM32(0x8586F4)); /* 0x004DD6C8: call dword ptr [0x8586f4] */
    eax = 0; /* 0x004DD6CE: xor eax, eax */
    goto L_004DD715; /* 0x004DD6D0: jmp 0x4dd715 */

L_004DD6D2:
    edx = MEM32(ebp + (-0x8)); /* 0x004DD6D2: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DD6D5: push edx */
    RECOMP_CALL(sub_004D5870); /* 0x004DD6D6: call 0x4d5870 */
    esp = esp + 4; /* 0x004DD6DB: add esp, 4 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DD6DE: mov ecx, dword ptr [ebp - 8] */
    edx = ecx + eax + 0x1; /* 0x004DD6E1: lea edx, [ecx + eax + 1] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DD6E5: mov dword ptr [ebp - 8], edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004DD6E8: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004DD6EB: push eax */
    RECOMP_CALL(sub_004E1180); /* 0x004DD6EC: call 0x4e1180 */
    esp = esp + 4; /* 0x004DD6F1: add esp, 4 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD6F4: mov ecx, dword ptr [ebp - 0x10] */
    edx = ecx + eax * 2 + 0x2; /* 0x004DD6F7: lea edx, [ecx + eax*2 + 2] */
    MEM32(ebp + (-0x10)) = edx; /* 0x004DD6FB: mov dword ptr [ebp - 0x10], edx */
    goto L_004DD681; /* 0x004DD6FE: jmp 0x4dd681 */

L_004DD700:
    eax = MEM32(ebp + (-0x10)); /* 0x004DD700: mov eax, dword ptr [ebp - 0x10] */
    MEM16(eax) = (uint16_t)(0); /* 0x004DD703: mov word ptr [eax], 0 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DD708: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004DD70B: push ecx */
    RECOMP_ICALL(MEM32(0x8586F4)); /* 0x004DD70C: call dword ptr [0x8586f4] */
    eax = MEM32(ebp + (-0x18)); /* 0x004DD712: mov eax, dword ptr [ebp - 0x18] */

L_004DD715:
    esp = ebp; /* 0x004DD715: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD717: pop ebp */
    return; /* 0x004DD718: ret  */

}

void sub_004DD610(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD610:
    eax = 0; /* 0x004DD610: xor eax, eax */
    goto L_004DD715; /* 0x004DD612: jmp 0x4dd715 */

L_004DD715:
    esp = ebp; /* 0x004DD715: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD717: pop ebp */
    return; /* 0x004DD718: ret  */

}

void sub_004DD860(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD860:
    RECOMP_CALL(sub_004D2FE0); /* 0x004DD860: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004DD865: add esp, 8 */
    MEM32(ebp + (-0x18)) = 0; /* 0x004DD868: mov dword ptr [ebp - 0x18], 0 */
    edx = MEM32(ebp + (-0x14)); /* 0x004DD86F: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004DD872: push edx */
    RECOMP_ICALL(MEM32(0x8586EC)); /* 0x004DD873: call dword ptr [0x8586ec] */
    eax = MEM32(ebp + (-0x18)); /* 0x004DD879: mov eax, dword ptr [ebp - 0x18] */
    goto L_004DD938; /* 0x004DD87C: jmp 0x4dd938 */

L_004DD938:
    esp = ebp; /* 0x004DD938: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD93A: pop ebp */
    return; /* 0x004DD93B: ret  */

}

void sub_004DD8B0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD8B0:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD8B0: mov ecx, dword ptr [ebp - 0xc] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DD8B3: movsx edx, byte ptr [ecx] */
    /* test edx, edx */ /* 0x004DD8B6: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DD8D8; /* 0x004DD8B8: je 0x4dd8d8 */

L_004DD8BA:
    eax = MEM32(ebp + (-0xC)); /* 0x004DD8BA: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 1; /* 0x004DD8BD: add eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DD8C0: mov dword ptr [ebp - 0xc], eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD8C3: mov ecx, dword ptr [ebp - 0xc] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DD8C6: movsx edx, byte ptr [ecx] */
    /* test edx, edx */ /* 0x004DD8C9: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004DD8D6; /* 0x004DD8CB: jne 0x4dd8d6 */

L_004DD8CD:
    eax = MEM32(ebp + (-0xC)); /* 0x004DD8CD: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 1; /* 0x004DD8D0: add eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DD8D3: mov dword ptr [ebp - 0xc], eax */

L_004DD8D6:
    goto L_004DD8B0; /* 0x004DD8D6: jmp 0x4dd8b0 */

L_004DD8D8:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD8D8: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx - MEM32(ebp + (-0x18)); /* 0x004DD8DB: sub ecx, dword ptr [ebp - 0x18] */
    ecx = ecx + 1; /* 0x004DD8DE: add ecx, 1 */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004DD8E1: mov dword ptr [ebp - 0x10], ecx */
    PUSH32(esp, 0x126u); /* 0x004DD8E4: push 0x126 */
    PUSH32(esp, 0x004F43D0u); /* 0x004DD8E9: push 0x4f43d0 */
    PUSH32(esp, 2); /* 0x004DD8EE: push 2 */
    edx = MEM32(ebp + (-0x10)); /* 0x004DD8F0: mov edx, dword ptr [ebp - 0x10] */
    PUSH32(esp, edx); /* 0x004DD8F3: push edx */
    RECOMP_CALL(sub_004D25A0); /* 0x004DD8F4: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DD8F9: add esp, 0x10 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DD8FC: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004DD8FF: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004DD913; /* 0x004DD903: jne 0x4dd913 */

L_004DD905:
    eax = MEM32(ebp + (-0x18)); /* 0x004DD905: mov eax, dword ptr [ebp - 0x18] */
    PUSH32(esp, eax); /* 0x004DD908: push eax */
    RECOMP_ICALL(MEM32(0x8586F4)); /* 0x004DD909: call dword ptr [0x8586f4] */
    eax = 0; /* 0x004DD90F: xor eax, eax */
    goto L_004DD938; /* 0x004DD911: jmp 0x4dd938 */

L_004DD913:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DD913: mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(esp, ecx); /* 0x004DD916: push ecx */
    edx = MEM32(ebp + (-0x18)); /* 0x004DD917: mov edx, dword ptr [ebp - 0x18] */
    PUSH32(esp, edx); /* 0x004DD91A: push edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004DD91B: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004DD91E: push eax */
    RECOMP_CALL(sub_004D58F0); /* 0x004DD91F: call 0x4d58f0 */
    esp = esp + 0xCu; /* 0x004DD924: add esp, 0xc */
    ecx = MEM32(ebp + (-0x18)); /* 0x004DD927: mov ecx, dword ptr [ebp - 0x18] */
    PUSH32(esp, ecx); /* 0x004DD92A: push ecx */
    RECOMP_ICALL(MEM32(0x8586F4)); /* 0x004DD92B: call dword ptr [0x8586f4] */
    eax = MEM32(ebp + (-0xC)); /* 0x004DD931: mov eax, dword ptr [ebp - 0xc] */
    goto L_004DD938; /* 0x004DD934: jmp 0x4dd938 */

L_004DD938:
    esp = ebp; /* 0x004DD938: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DD93A: pop ebp */
    return; /* 0x004DD93B: ret  */

}

void sub_004DD960(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD960:
    eax = 0; /* 0x004DD960: xor eax, eax */
    goto L_004DDC3A; /* 0x004DD962: jmp 0x4ddc3a */

L_004DDC3A:
    esp = ebp; /* 0x004DDC3A: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DDC3C: pop ebp */
    return; /* 0x004DDC3D: ret  */

}

void sub_004DD9F0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DD9DF:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DD9DF: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + 1; /* 0x004DD9E2: add ecx, 1 */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DD9E5: mov dword ptr [ebp - 0xc], ecx */
    /* cmp MEM32(ebp + (-0xC)), 4 */ /* 0x004DD9E8: cmp dword ptr [ebp - 0xc], 4 */
    if (CMP_AE(MEM32(ebp + (-0xC)), 4)) goto L_004DDA69; /* 0x004DD9EC: jae 0x4dda69 */

L_004DD9EE:
    edx = MEM32(ebp + (-0x4)); /* 0x004DD9EE: mov edx, dword ptr [ebp - 4] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x30u); /* 0x004DD9F1: imul edx, edx, 0x30 */
    eax = MEM32(ebp + (-0xC)); /* 0x004DD9F4: mov eax, dword ptr [ebp - 0xc] */
    ecx = edx + eax * 8 + 0x50B720; /* 0x004DD9F7: lea ecx, [edx + eax*8 + 0x50b720] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DD9FE: mov dword ptr [ebp - 8], ecx */
    goto L_004DDA0C; /* 0x004DDA01: jmp 0x4dda0c */

L_004DD9F0:
    _df = 1; /* 0x004DD9F0: cld  */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x30u); /* 0x004DD9F1: imul edx, edx, 0x30 */
    eax = MEM32(ebp + (-0xC)); /* 0x004DD9F4: mov eax, dword ptr [ebp - 0xc] */
    ecx = edx + eax * 8 + 0x50B720; /* 0x004DD9F7: lea ecx, [edx + eax*8 + 0x50b720] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DD9FE: mov dword ptr [ebp - 8], ecx */
    goto L_004DDA0C; /* 0x004DDA01: jmp 0x4dda0c */

L_004DDA03:
    edx = MEM32(ebp + (-0x8)); /* 0x004DDA03: mov edx, dword ptr [ebp - 8] */
    edx = edx + 2; /* 0x004DDA06: add edx, 2 */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DDA09: mov dword ptr [ebp - 8], edx */

L_004DDA0C:
    eax = MEM32(ebp + (-0x8)); /* 0x004DDA0C: mov eax, dword ptr [ebp - 8] */
    ecx = 0; /* 0x004DDA0F: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DDA11: mov cl, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DDA13: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DDA64; /* 0x004DDA15: je 0x4dda64 */

L_004DDA17:
    edx = MEM32(ebp + (-0x8)); /* 0x004DDA17: mov edx, dword ptr [ebp - 8] */
    eax = 0; /* 0x004DDA1A: xor eax, eax */
    SET_LO8(eax, MEM8(edx + 0x1)); /* 0x004DDA1C: mov al, byte ptr [edx + 1] */
    /* test eax, eax */ /* 0x004DDA1F: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DDA64; /* 0x004DDA21: je 0x4dda64 */

L_004DDA23:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DDA23: mov ecx, dword ptr [ebp - 8] */
    edx = 0; /* 0x004DDA26: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DDA28: mov dl, byte ptr [ecx] */
    MEM32(ebp + (-0x24)) = edx; /* 0x004DDA2A: mov dword ptr [ebp - 0x24], edx */
    goto L_004DDA38; /* 0x004DDA2D: jmp 0x4dda38 */

L_004DDA2F:
    eax = MEM32(ebp + (-0x24)); /* 0x004DDA2F: mov eax, dword ptr [ebp - 0x24] */
    eax = eax + 1; /* 0x004DDA32: add eax, 1 */
    MEM32(ebp + (-0x24)) = eax; /* 0x004DDA35: mov dword ptr [ebp - 0x24], eax */

L_004DDA38:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DDA38: mov ecx, dword ptr [ebp - 8] */
    edx = 0; /* 0x004DDA3B: xor edx, edx */
    SET_LO8(edx, MEM8(ecx + 0x1)); /* 0x004DDA3D: mov dl, byte ptr [ecx + 1] */
    /* cmp MEM32(ebp + (-0x24)), edx */ /* 0x004DDA40: cmp dword ptr [ebp - 0x24], edx */
    if (CMP_A(MEM32(ebp + (-0x24)), edx)) goto L_004DDA62; /* 0x004DDA43: ja 0x4dda62 */

L_004DDA45:
    eax = MEM32(ebp + (-0x24)); /* 0x004DDA45: mov eax, dword ptr [ebp - 0x24] */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DDA48: mov ecx, dword ptr [ebp - 0xc] */
    SET_LO8(edx, MEM8(eax + 0x84B991)); /* 0x004DDA4B: mov dl, byte ptr [eax + 0x84b991] */
    SET_LO8(edx, LO8(edx) | MEM8(ecx + 0x50B708)); /* 0x004DDA51: or dl, byte ptr [ecx + 0x50b708] */
    eax = MEM32(ebp + (-0x24)); /* 0x004DDA57: mov eax, dword ptr [ebp - 0x24] */
    MEM8(eax + 0x84B991) = (uint8_t)(LO8(edx)); /* 0x004DDA5A: mov byte ptr [eax + 0x84b991], dl */
    goto L_004DDA2F; /* 0x004DDA60: jmp 0x4dda2f */

L_004DDA62:
    goto L_004DDA03; /* 0x004DDA62: jmp 0x4dda03 */

L_004DDA64:
    goto L_004DD9DF; /* 0x004DDA64: jmp 0x4dd9df */

L_004DDA69:
    ecx = MEM32(ebp + 0x8); /* 0x004DDA69: mov ecx, dword ptr [ebp + 8] */
    MEM32(0x84BB98) = ecx; /* 0x004DDA6C: mov dword ptr [0x84bb98], ecx */
    MEM32(0x855C44) = 1; /* 0x004DDA72: mov dword ptr [0x855c44], 1 */
    edx = MEM32(0x84BB98); /* 0x004DDA7C: mov edx, dword ptr [0x84bb98] */
    PUSH32(esp, edx); /* 0x004DDA82: push edx */
    RECOMP_CALL(sub_004DDCA0); /* 0x004DDA83: call 0x4ddca0 */
    esp = esp + 4; /* 0x004DDA88: add esp, 4 */
    MEM32(0x84BB9C) = eax; /* 0x004DDA8B: mov dword ptr [0x84bb9c], eax */
    MEM32(ebp + (-0xC)) = 0; /* 0x004DDA90: mov dword ptr [ebp - 0xc], 0 */
    goto L_004DDAA2; /* 0x004DDA97: jmp 0x4ddaa2 */

L_004DDA99:
    eax = MEM32(ebp + (-0xC)); /* 0x004DDA99: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 1; /* 0x004DDA9C: add eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DDA9F: mov dword ptr [ebp - 0xc], eax */

L_004DDAA2:
    /* cmp MEM32(ebp + (-0xC)), 6 */ /* 0x004DDAA2: cmp dword ptr [ebp - 0xc], 6 */
    if (CMP_AE(MEM32(ebp + (-0xC)), 6)) goto L_004DDAC6; /* 0x004DDAA6: jae 0x4ddac6 */

L_004DDAA8:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DDAA8: mov ecx, dword ptr [ebp - 4] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x30u); /* 0x004DDAAB: imul ecx, ecx, 0x30 */
    edx = MEM32(ebp + (-0xC)); /* 0x004DDAAE: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + (-0xC)); /* 0x004DDAB1: mov eax, dword ptr [ebp - 0xc] */
    SET_LO16(ecx, MEM16(ecx + eax * 2 + 0x50B714)); /* 0x004DDAB4: mov cx, word ptr [ecx + eax*2 + 0x50b714] */
    MEM16(edx * 2 + 0x84BBA0) = (uint16_t)(LO16(ecx)); /* 0x004DDABC: mov word ptr [edx*2 + 0x84bba0], cx */
    goto L_004DDA99; /* 0x004DDAC4: jmp 0x4dda99 */

L_004DDAC6:
    RECOMP_CALL(sub_004DDDA0); /* 0x004DDAC6: call 0x4ddda0 */
    eax = 0; /* 0x004DDACB: xor eax, eax */
    goto L_004DDC3A; /* 0x004DDACD: jmp 0x4ddc3a */

L_004DDC3A:
    esp = ebp; /* 0x004DDC3A: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DDC3C: pop ebp */
    return; /* 0x004DDC3D: ret  */

}

void sub_004DDAA0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDA99:
    eax = MEM32(ebp + (-0xC)); /* 0x004DDA99: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 1; /* 0x004DDA9C: add eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DDA9F: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 6 */ /* 0x004DDAA2: cmp dword ptr [ebp - 0xc], 6 */
    if (CMP_AE(MEM32(ebp + (-0xC)), 6)) goto L_004DDAC6; /* 0x004DDAA6: jae 0x4ddac6 */

L_004DDAA0:
    ebp = ebp + 1; /* 0x004DDAA0: inc ebp */
    /* UNIMPLEMENTED: hlt  */ /* 0x004DDAA1: hlt  */
    /* cmp MEM32(ebp + (-0xC)), 6 */ /* 0x004DDAA2: cmp dword ptr [ebp - 0xc], 6 */
    if (CMP_AE(MEM32(ebp + (-0xC)), 6)) goto L_004DDAC6; /* 0x004DDAA6: jae 0x4ddac6 */

L_004DDAA8:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DDAA8: mov ecx, dword ptr [ebp - 4] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x30u); /* 0x004DDAAB: imul ecx, ecx, 0x30 */
    edx = MEM32(ebp + (-0xC)); /* 0x004DDAAE: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + (-0xC)); /* 0x004DDAB1: mov eax, dword ptr [ebp - 0xc] */
    SET_LO16(ecx, MEM16(ecx + eax * 2 + 0x50B714)); /* 0x004DDAB4: mov cx, word ptr [ecx + eax*2 + 0x50b714] */
    MEM16(edx * 2 + 0x84BBA0) = (uint16_t)(LO16(ecx)); /* 0x004DDABC: mov word ptr [edx*2 + 0x84bba0], cx */
    goto L_004DDA99; /* 0x004DDAC4: jmp 0x4dda99 */

L_004DDAC6:
    RECOMP_CALL(sub_004DDDA0); /* 0x004DDAC6: call 0x4ddda0 */
    eax = 0; /* 0x004DDACB: xor eax, eax */
    goto L_004DDC3A; /* 0x004DDACD: jmp 0x4ddc3a */

L_004DDC3A:
    esp = ebp; /* 0x004DDC3A: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DDC3C: pop ebp */
    return; /* 0x004DDC3D: ret  */

}

void sub_004DDB60(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDB39:
    edx = MEM32(ebp + (-0x28)); /* 0x004DDB39: mov edx, dword ptr [ebp - 0x28] */
    edx = edx + 2; /* 0x004DDB3C: add edx, 2 */
    MEM32(ebp + (-0x28)) = edx; /* 0x004DDB3F: mov dword ptr [ebp - 0x28], edx */
    eax = MEM32(ebp + (-0x28)); /* 0x004DDB42: mov eax, dword ptr [ebp - 0x28] */
    ecx = 0; /* 0x004DDB45: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DDB47: mov cl, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004DDB49: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DDB94; /* 0x004DDB4B: je 0x4ddb94 */

L_004DDB4D:
    edx = MEM32(ebp + (-0x28)); /* 0x004DDB4D: mov edx, dword ptr [ebp - 0x28] */
    eax = 0; /* 0x004DDB50: xor eax, eax */
    SET_LO8(eax, MEM8(edx + 0x1)); /* 0x004DDB52: mov al, byte ptr [edx + 1] */
    /* test eax, eax */ /* 0x004DDB55: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DDB94; /* 0x004DDB57: je 0x4ddb94 */

L_004DDB59:
    ecx = MEM32(ebp + (-0x28)); /* 0x004DDB59: mov ecx, dword ptr [ebp - 0x28] */
    edx = 0; /* 0x004DDB5C: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DDB5E: mov dl, byte ptr [ecx] */

L_004DDB60:
    MEM32(ebp + (-0x24)) = edx; /* 0x004DDB60: mov dword ptr [ebp - 0x24], edx */
    goto L_004DDB6E; /* 0x004DDB63: jmp 0x4ddb6e */

L_004DDB65:
    eax = MEM32(ebp + (-0x24)); /* 0x004DDB65: mov eax, dword ptr [ebp - 0x24] */
    eax = eax + 1; /* 0x004DDB68: add eax, 1 */
    MEM32(ebp + (-0x24)) = eax; /* 0x004DDB6B: mov dword ptr [ebp - 0x24], eax */

L_004DDB6E:
    ecx = MEM32(ebp + (-0x28)); /* 0x004DDB6E: mov ecx, dword ptr [ebp - 0x28] */
    edx = 0; /* 0x004DDB71: xor edx, edx */
    SET_LO8(edx, MEM8(ecx + 0x1)); /* 0x004DDB73: mov dl, byte ptr [ecx + 1] */
    /* cmp MEM32(ebp + (-0x24)), edx */ /* 0x004DDB76: cmp dword ptr [ebp - 0x24], edx */
    if (CMP_A(MEM32(ebp + (-0x24)), edx)) goto L_004DDB92; /* 0x004DDB79: ja 0x4ddb92 */

L_004DDB7B:
    eax = MEM32(ebp + (-0x24)); /* 0x004DDB7B: mov eax, dword ptr [ebp - 0x24] */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DDB7E: mov cl, byte ptr [eax + 0x84b991] */
    SET_LO8(ecx, LO8(ecx) | 4); /* 0x004DDB84: or cl, 4 */
    edx = MEM32(ebp + (-0x24)); /* 0x004DDB87: mov edx, dword ptr [ebp - 0x24] */
    MEM8(edx + 0x84B991) = (uint8_t)(LO8(ecx)); /* 0x004DDB8A: mov byte ptr [edx + 0x84b991], cl */
    goto L_004DDB65; /* 0x004DDB90: jmp 0x4ddb65 */

L_004DDB92:
    goto L_004DDB39; /* 0x004DDB92: jmp 0x4ddb39 */

L_004DDB94:
    MEM32(ebp + (-0x24)) = 1; /* 0x004DDB94: mov dword ptr [ebp - 0x24], 1 */
    goto L_004DDBA6; /* 0x004DDB9B: jmp 0x4ddba6 */

L_004DDB9D:
    eax = MEM32(ebp + (-0x24)); /* 0x004DDB9D: mov eax, dword ptr [ebp - 0x24] */
    eax = eax + 1; /* 0x004DDBA0: add eax, 1 */
    MEM32(ebp + (-0x24)) = eax; /* 0x004DDBA3: mov dword ptr [ebp - 0x24], eax */

L_004DDBA6:
    /* cmp MEM32(ebp + (-0x24)), 0xFFu */ /* 0x004DDBA6: cmp dword ptr [ebp - 0x24], 0xff */
    if (CMP_AE(MEM32(ebp + (-0x24)), 0xFFu)) goto L_004DDBC6; /* 0x004DDBAD: jae 0x4ddbc6 */

L_004DDBAF:
    ecx = MEM32(ebp + (-0x24)); /* 0x004DDBAF: mov ecx, dword ptr [ebp - 0x24] */
    SET_LO8(edx, MEM8(ecx + 0x84B991)); /* 0x004DDBB2: mov dl, byte ptr [ecx + 0x84b991] */
    SET_LO8(edx, LO8(edx) | 8); /* 0x004DDBB8: or dl, 8 */
    eax = MEM32(ebp + (-0x24)); /* 0x004DDBBB: mov eax, dword ptr [ebp - 0x24] */
    MEM8(eax + 0x84B991) = (uint8_t)(LO8(edx)); /* 0x004DDBBE: mov byte ptr [eax + 0x84b991], dl */
    goto L_004DDB9D; /* 0x004DDBC4: jmp 0x4ddb9d */

L_004DDBC6:
    ecx = MEM32(0x84BB98); /* 0x004DDBC6: mov ecx, dword ptr [0x84bb98] */
    PUSH32(esp, ecx); /* 0x004DDBCC: push ecx */
    RECOMP_CALL(sub_004DDCA0); /* 0x004DDBCD: call 0x4ddca0 */
    esp = esp + 4; /* 0x004DDBD2: add esp, 4 */
    MEM32(0x84BB9C) = eax; /* 0x004DDBD5: mov dword ptr [0x84bb9c], eax */
    MEM32(0x855C44) = 1; /* 0x004DDBDA: mov dword ptr [0x855c44], 1 */
    goto L_004DDBF0; /* 0x004DDBE4: jmp 0x4ddbf0 */

L_004DDBF0:
    MEM32(ebp + (-0xC)) = 0; /* 0x004DDBF0: mov dword ptr [ebp - 0xc], 0 */
    goto L_004DDC02; /* 0x004DDBF7: jmp 0x4ddc02 */

L_004DDBF9:
    edx = MEM32(ebp + (-0xC)); /* 0x004DDBF9: mov edx, dword ptr [ebp - 0xc] */
    edx = edx + 1; /* 0x004DDBFC: add edx, 1 */
    MEM32(ebp + (-0xC)) = edx; /* 0x004DDBFF: mov dword ptr [ebp - 0xc], edx */

L_004DDC02:
    /* cmp MEM32(ebp + (-0xC)), 6 */ /* 0x004DDC02: cmp dword ptr [ebp - 0xc], 6 */
    if (CMP_AE(MEM32(ebp + (-0xC)), 6)) goto L_004DDC17; /* 0x004DDC06: jae 0x4ddc17 */

L_004DDC08:
    eax = MEM32(ebp + (-0xC)); /* 0x004DDC08: mov eax, dword ptr [ebp - 0xc] */
    MEM16(eax * 2 + 0x84BBA0) = (uint16_t)(0); /* 0x004DDC0B: mov word ptr [eax*2 + 0x84bba0], 0 */
    goto L_004DDBF9; /* 0x004DDC15: jmp 0x4ddbf9 */

L_004DDC17:
    RECOMP_CALL(sub_004DDDA0); /* 0x004DDC17: call 0x4ddda0 */
    eax = 0; /* 0x004DDC1C: xor eax, eax */
    goto L_004DDC3A; /* 0x004DDC1E: jmp 0x4ddc3a */

L_004DDC3A:
    esp = ebp; /* 0x004DDC3A: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DDC3C: pop ebp */
    return; /* 0x004DDC3D: ret  */

}

void sub_004DDC90(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDC90:
    /* test MEM8(eax), LO8(eax) */ /* 0x004DDC90: test byte ptr [eax], al */
    goto L_004DDC97; /* 0x004DDC92: jmp 0x4ddc97 */

L_004DDC97:
    ebp = POP32_VAL(esp); /* 0x004DDC97: pop ebp */
    return; /* 0x004DDC98: ret  */

}

void sub_004DDD20(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDD20:
    PUSH32(esp, ebp); /* 0x004DDD20: push ebp */
    ebp = esp; /* 0x004DDD21: mov ebp, esp */
    PUSH32(esp, ecx); /* 0x004DDD23: push ecx */
    MEM32(ebp + (-0x4)) = 0; /* 0x004DDD24: mov dword ptr [ebp - 4], 0 */
    goto L_004DDD36; /* 0x004DDD2B: jmp 0x4ddd36 */

L_004DDD2D:
    eax = MEM32(ebp + (-0x4)); /* 0x004DDD2D: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DDD30: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DDD33: mov dword ptr [ebp - 4], eax */

L_004DDD36:
    /* cmp MEM32(ebp + (-0x4)), 0x101u */ /* 0x004DDD36: cmp dword ptr [ebp - 4], 0x101 */
    if (CMP_GE(MEM32(ebp + (-0x4)), 0x101u)) goto L_004DDD4B; /* 0x004DDD3D: jge 0x4ddd4b */

L_004DDD3F:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DDD3F: mov ecx, dword ptr [ebp - 4] */
    MEM8(ecx + 0x84B990) = (uint8_t)(0); /* 0x004DDD42: mov byte ptr [ecx + 0x84b990], 0 */
    goto L_004DDD2D; /* 0x004DDD49: jmp 0x4ddd2d */

L_004DDD4B:
    MEM32(0x84BB98) = 0; /* 0x004DDD4B: mov dword ptr [0x84bb98], 0 */
    MEM32(0x855C44) = 0; /* 0x004DDD55: mov dword ptr [0x855c44], 0 */
    MEM32(0x84BB9C) = 0; /* 0x004DDD5F: mov dword ptr [0x84bb9c], 0 */
    MEM32(ebp + (-0x4)) = 0; /* 0x004DDD69: mov dword ptr [ebp - 4], 0 */
    goto L_004DDD7B; /* 0x004DDD70: jmp 0x4ddd7b */

L_004DDD72:
    edx = MEM32(ebp + (-0x4)); /* 0x004DDD72: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004DDD75: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DDD78: mov dword ptr [ebp - 4], edx */

L_004DDD7B:
    /* cmp MEM32(ebp + (-0x4)), 6 */ /* 0x004DDD7B: cmp dword ptr [ebp - 4], 6 */
    if (CMP_GE(MEM32(ebp + (-0x4)), 6)) goto L_004DDD90; /* 0x004DDD7F: jge 0x4ddd90 */

L_004DDD81:
    eax = MEM32(ebp + (-0x4)); /* 0x004DDD81: mov eax, dword ptr [ebp - 4] */
    MEM16(eax * 2 + 0x84BBA0) = (uint16_t)(0); /* 0x004DDD84: mov word ptr [eax*2 + 0x84bba0], 0 */
    goto L_004DDD72; /* 0x004DDD8E: jmp 0x4ddd72 */

L_004DDD90:
    esp = ebp; /* 0x004DDD90: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DDD92: pop ebp */
    return; /* 0x004DDD93: ret  */

}

void sub_004DDDD0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDDD0:
    goto L_004DDDE1; /* 0x004DDDD0: jmp 0x4ddde1 */

L_004DDDD2:
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDDD2: mov edx, dword ptr [ebp - 0x51c] */
    edx = edx + 1; /* 0x004DDDD8: add edx, 1 */
    MEM32(ebp + (-0x51C)) = edx; /* 0x004DDDDB: mov dword ptr [ebp - 0x51c], edx */

L_004DDDE1:
    /* cmp MEM32(ebp + (-0x51C)), 0x100u */ /* 0x004DDDE1: cmp dword ptr [ebp - 0x51c], 0x100 */
    if (CMP_AE(MEM32(ebp + (-0x51C)), 0x100u)) goto L_004DDE02; /* 0x004DDDEB: jae 0x4dde02 */

L_004DDDED:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDDED: mov eax, dword ptr [ebp - 0x51c] */
    SET_LO8(ecx, MEM8(ebp + (-0x51C))); /* 0x004DDDF3: mov cl, byte ptr [ebp - 0x51c] */
    MEM8(ebp + eax + (-0x304)) = (uint8_t)(LO8(ecx)); /* 0x004DDDF9: mov byte ptr [ebp + eax - 0x304], cl */
    goto L_004DDDD2; /* 0x004DDE00: jmp 0x4dddd2 */

L_004DDE02:
    MEM8(ebp + (-0x304)) = (uint8_t)(0x20u); /* 0x004DDE02: mov byte ptr [ebp - 0x304], 0x20 */
    edx = ebp + (-0x312); /* 0x004DDE09: lea edx, [ebp - 0x312] */
    MEM32(ebp + (-0x4)) = edx; /* 0x004DDE0F: mov dword ptr [ebp - 4], edx */
    goto L_004DDE1D; /* 0x004DDE12: jmp 0x4dde1d */

L_004DDE14:
    eax = MEM32(ebp + (-0x4)); /* 0x004DDE14: mov eax, dword ptr [ebp - 4] */
    eax = eax + 2; /* 0x004DDE17: add eax, 2 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DDE1A: mov dword ptr [ebp - 4], eax */

L_004DDE1D:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DDE1D: mov ecx, dword ptr [ebp - 4] */
    edx = 0; /* 0x004DDE20: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004DDE22: mov dl, byte ptr [ecx] */
    /* test edx, edx */ /* 0x004DDE24: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DDE68; /* 0x004DDE26: je 0x4dde68 */

L_004DDE28:
    eax = MEM32(ebp + (-0x4)); /* 0x004DDE28: mov eax, dword ptr [ebp - 4] */
    ecx = 0; /* 0x004DDE2B: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004DDE2D: mov cl, byte ptr [eax] */
    MEM32(ebp + (-0x51C)) = ecx; /* 0x004DDE2F: mov dword ptr [ebp - 0x51c], ecx */
    goto L_004DDE46; /* 0x004DDE35: jmp 0x4dde46 */

L_004DDE37:
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDE37: mov edx, dword ptr [ebp - 0x51c] */
    edx = edx + 1; /* 0x004DDE3D: add edx, 1 */
    MEM32(ebp + (-0x51C)) = edx; /* 0x004DDE40: mov dword ptr [ebp - 0x51c], edx */

L_004DDE46:
    eax = MEM32(ebp + (-0x4)); /* 0x004DDE46: mov eax, dword ptr [ebp - 4] */
    ecx = 0; /* 0x004DDE49: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x1)); /* 0x004DDE4B: mov cl, byte ptr [eax + 1] */
    /* cmp MEM32(ebp + (-0x51C)), ecx */ /* 0x004DDE4E: cmp dword ptr [ebp - 0x51c], ecx */
    if (CMP_A(MEM32(ebp + (-0x51C)), ecx)) goto L_004DDE66; /* 0x004DDE54: ja 0x4dde66 */

L_004DDE56:
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDE56: mov edx, dword ptr [ebp - 0x51c] */
    MEM8(ebp + edx + (-0x304)) = (uint8_t)(0x20u); /* 0x004DDE5C: mov byte ptr [ebp + edx - 0x304], 0x20 */
    goto L_004DDE37; /* 0x004DDE64: jmp 0x4dde37 */

L_004DDE66:
    goto L_004DDE14; /* 0x004DDE66: jmp 0x4dde14 */

L_004DDE68:
    PUSH32(esp, 0); /* 0x004DDE68: push 0 */
    eax = MEM32(0x84BB9C); /* 0x004DDE6A: mov eax, dword ptr [0x84bb9c] */
    PUSH32(esp, eax); /* 0x004DDE6F: push eax */
    ecx = MEM32(0x84BB98); /* 0x004DDE70: mov ecx, dword ptr [0x84bb98] */
    PUSH32(esp, ecx); /* 0x004DDE76: push ecx */
    edx = ebp + (-0x204); /* 0x004DDE77: lea edx, [ebp - 0x204] */
    PUSH32(esp, edx); /* 0x004DDE7D: push edx */
    PUSH32(esp, 0x100u); /* 0x004DDE7E: push 0x100 */
    eax = ebp + (-0x304); /* 0x004DDE83: lea eax, [ebp - 0x304] */
    PUSH32(esp, eax); /* 0x004DDE89: push eax */
    PUSH32(esp, 1); /* 0x004DDE8A: push 1 */
    RECOMP_CALL(sub_004E1010); /* 0x004DDE8C: call 0x4e1010 */
    esp = esp + 0x1Cu; /* 0x004DDE91: add esp, 0x1c */
    PUSH32(esp, 0); /* 0x004DDE94: push 0 */
    ecx = MEM32(0x84BB98); /* 0x004DDE96: mov ecx, dword ptr [0x84bb98] */
    PUSH32(esp, ecx); /* 0x004DDE9C: push ecx */
    PUSH32(esp, 0x100u); /* 0x004DDE9D: push 0x100 */
    edx = ebp + (-0x418); /* 0x004DDEA2: lea edx, [ebp - 0x418] */
    PUSH32(esp, edx); /* 0x004DDEA8: push edx */
    PUSH32(esp, 0x100u); /* 0x004DDEA9: push 0x100 */
    eax = ebp + (-0x304); /* 0x004DDEAE: lea eax, [ebp - 0x304] */
    PUSH32(esp, eax); /* 0x004DDEB4: push eax */
    PUSH32(esp, 0x100u); /* 0x004DDEB5: push 0x100 */
    ecx = MEM32(0x84BB9C); /* 0x004DDEBA: mov ecx, dword ptr [0x84bb9c] */
    PUSH32(esp, ecx); /* 0x004DDEC0: push ecx */
    RECOMP_CALL(sub_004E14C0); /* 0x004DDEC1: call 0x4e14c0 */
    esp = esp + 0x20u; /* 0x004DDEC6: add esp, 0x20 */
    PUSH32(esp, 0); /* 0x004DDEC9: push 0 */
    edx = MEM32(0x84BB98); /* 0x004DDECB: mov edx, dword ptr [0x84bb98] */
    PUSH32(esp, edx); /* 0x004DDED1: push edx */
    PUSH32(esp, 0x100u); /* 0x004DDED2: push 0x100 */
    eax = ebp + (-0x518); /* 0x004DDED7: lea eax, [ebp - 0x518] */
    PUSH32(esp, eax); /* 0x004DDEDD: push eax */
    PUSH32(esp, 0x100u); /* 0x004DDEDE: push 0x100 */
    ecx = ebp + (-0x304); /* 0x004DDEE3: lea ecx, [ebp - 0x304] */
    PUSH32(esp, ecx); /* 0x004DDEE9: push ecx */
    PUSH32(esp, 0x200u); /* 0x004DDEEA: push 0x200 */
    edx = MEM32(0x84BB9C); /* 0x004DDEEF: mov edx, dword ptr [0x84bb9c] */
    PUSH32(esp, edx); /* 0x004DDEF5: push edx */
    RECOMP_CALL(sub_004E14C0); /* 0x004DDEF6: call 0x4e14c0 */
    esp = esp + 0x20u; /* 0x004DDEFB: add esp, 0x20 */
    MEM32(ebp + (-0x51C)) = 0; /* 0x004DDEFE: mov dword ptr [ebp - 0x51c], 0 */
    goto L_004DDF19; /* 0x004DDF08: jmp 0x4ddf19 */

L_004DDF0A:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDF0A: mov eax, dword ptr [ebp - 0x51c] */
    eax = eax + 1; /* 0x004DDF10: add eax, 1 */
    MEM32(ebp + (-0x51C)) = eax; /* 0x004DDF13: mov dword ptr [ebp - 0x51c], eax */

L_004DDF19:
    /* cmp MEM32(ebp + (-0x51C)), 0x100u */ /* 0x004DDF19: cmp dword ptr [ebp - 0x51c], 0x100 */
    if (CMP_AE(MEM32(ebp + (-0x51C)), 0x100u)) goto L_004DDFD4; /* 0x004DDF23: jae 0x4ddfd4 */

L_004DDF29:
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DDF29: mov ecx, dword ptr [ebp - 0x51c] */
    edx = 0; /* 0x004DDF2F: xor edx, edx */
    SET_LO16(edx, MEM16(ebp + ecx * 2 + (-0x204))); /* 0x004DDF31: mov dx, word ptr [ebp + ecx*2 - 0x204] */
    edx = edx & 1; /* 0x004DDF39: and edx, 1 */
    /* test edx, edx */ /* 0x004DDF3C: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DDF76; /* 0x004DDF3E: je 0x4ddf76 */

L_004DDF40:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDF40: mov eax, dword ptr [ebp - 0x51c] */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DDF46: mov cl, byte ptr [eax + 0x84b991] */
    SET_LO8(ecx, LO8(ecx) | 0x10u); /* 0x004DDF4C: or cl, 0x10 */
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDF4F: mov edx, dword ptr [ebp - 0x51c] */
    MEM8(edx + 0x84B991) = (uint8_t)(LO8(ecx)); /* 0x004DDF55: mov byte ptr [edx + 0x84b991], cl */
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDF5B: mov eax, dword ptr [ebp - 0x51c] */
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DDF61: mov ecx, dword ptr [ebp - 0x51c] */
    SET_LO8(edx, MEM8(ebp + ecx + (-0x418))); /* 0x004DDF67: mov dl, byte ptr [ebp + ecx - 0x418] */
    MEM8(eax + 0x84BA98) = (uint8_t)(LO8(edx)); /* 0x004DDF6E: mov byte ptr [eax + 0x84ba98], dl */
    goto L_004DDFCF; /* 0x004DDF74: jmp 0x4ddfcf */

L_004DDF76:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDF76: mov eax, dword ptr [ebp - 0x51c] */
    ecx = 0; /* 0x004DDF7C: xor ecx, ecx */
    SET_LO16(ecx, MEM16(ebp + eax * 2 + (-0x204))); /* 0x004DDF7E: mov cx, word ptr [ebp + eax*2 - 0x204] */
    ecx = ecx & 2; /* 0x004DDF86: and ecx, 2 */
    /* test ecx, ecx */ /* 0x004DDF89: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DDFC2; /* 0x004DDF8B: je 0x4ddfc2 */

L_004DDF8D:
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDF8D: mov edx, dword ptr [ebp - 0x51c] */
    SET_LO8(eax, MEM8(edx + 0x84B991)); /* 0x004DDF93: mov al, byte ptr [edx + 0x84b991] */
    SET_LO8(eax, LO8(eax) | 0x20u); /* 0x004DDF99: or al, 0x20 */
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DDF9B: mov ecx, dword ptr [ebp - 0x51c] */
    MEM8(ecx + 0x84B991) = (uint8_t)(LO8(eax)); /* 0x004DDFA1: mov byte ptr [ecx + 0x84b991], al */
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDFA7: mov edx, dword ptr [ebp - 0x51c] */
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDFAD: mov eax, dword ptr [ebp - 0x51c] */
    SET_LO8(ecx, MEM8(ebp + eax + (-0x518))); /* 0x004DDFB3: mov cl, byte ptr [ebp + eax - 0x518] */
    MEM8(edx + 0x84BA98) = (uint8_t)(LO8(ecx)); /* 0x004DDFBA: mov byte ptr [edx + 0x84ba98], cl */
    goto L_004DDFCF; /* 0x004DDFC0: jmp 0x4ddfcf */

L_004DDFC2:
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDFC2: mov edx, dword ptr [ebp - 0x51c] */
    MEM8(edx + 0x84BA98) = (uint8_t)(0); /* 0x004DDFC8: mov byte ptr [edx + 0x84ba98], 0 */

L_004DDFCF:
    goto L_004DDF0A; /* 0x004DDFCF: jmp 0x4ddf0a */

L_004DDFD4:
    goto L_004DE09E; /* 0x004DDFD4: jmp 0x4de09e */

L_004DE09E:
    esp = ebp; /* 0x004DE09E: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE0A0: pop ebp */
    return; /* 0x004DE0A1: ret  */

}

void sub_004DDDDD(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDDDD:
    /* UNIMPLEMENTED: in al, 0xfa */ /* 0x004DDDDD: in al, 0xfa */

}

void sub_004DDEB0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDEB0:
    _df = 1; /* 0x004DDEB0: cld  */
    _df = 1; /* 0x004DDEB1: cld  */

}

void sub_004DDF00(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDF00:
    /* UNIMPLEMENTED: in al, 0xfa */ /* 0x004DDF00: in al, 0xfa */

}

void sub_004DDF30(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDF30:
    MEM8(esi + (-0x75)) = (uint8_t)(MEM8(esi + (-0x75)) << LO8(ecx)); /* 0x004DDF30: shl byte ptr [esi - 0x75], cl */
    { uint32_t _tmp = esp; /* 0x004DDF33: xchg esp, eax */
      esp = eax;
      eax = _tmp; }
    ebp = ebp - 1; /* 0x004DDF34: dec ebp */
    _df = 1; /* 0x004DDF35: cld  */
    _df = -1; /* 0x004DDF36: std  */

}

void sub_004DDF70(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDF0A:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDF0A: mov eax, dword ptr [ebp - 0x51c] */
    eax = eax + 1; /* 0x004DDF10: add eax, 1 */
    MEM32(ebp + (-0x51C)) = eax; /* 0x004DDF13: mov dword ptr [ebp - 0x51c], eax */
    /* cmp MEM32(ebp + (-0x51C)), 0x100u */ /* 0x004DDF19: cmp dword ptr [ebp - 0x51c], 0x100 */
    if (CMP_AE(MEM32(ebp + (-0x51C)), 0x100u)) goto L_004DDFD4; /* 0x004DDF23: jae 0x4ddfd4 */

L_004DDF29:
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DDF29: mov ecx, dword ptr [ebp - 0x51c] */
    edx = 0; /* 0x004DDF2F: xor edx, edx */
    SET_LO16(edx, MEM16(ebp + ecx * 2 + (-0x204))); /* 0x004DDF31: mov dx, word ptr [ebp + ecx*2 - 0x204] */
    edx = edx & 1; /* 0x004DDF39: and edx, 1 */
    /* test edx, edx */ /* 0x004DDF3C: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DDF76; /* 0x004DDF3E: je 0x4ddf76 */

L_004DDF40:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDF40: mov eax, dword ptr [ebp - 0x51c] */
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DDF46: mov cl, byte ptr [eax + 0x84b991] */
    SET_LO8(ecx, LO8(ecx) | 0x10u); /* 0x004DDF4C: or cl, 0x10 */
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDF4F: mov edx, dword ptr [ebp - 0x51c] */
    MEM8(edx + 0x84B991) = (uint8_t)(LO8(ecx)); /* 0x004DDF55: mov byte ptr [edx + 0x84b991], cl */
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDF5B: mov eax, dword ptr [ebp - 0x51c] */
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DDF61: mov ecx, dword ptr [ebp - 0x51c] */
    SET_LO8(edx, MEM8(ebp + ecx + (-0x418))); /* 0x004DDF67: mov dl, byte ptr [ebp + ecx - 0x418] */
    MEM8(eax + 0x84BA98) = (uint8_t)(LO8(edx)); /* 0x004DDF6E: mov byte ptr [eax + 0x84ba98], dl */
    goto L_004DDFCF; /* 0x004DDF74: jmp 0x4ddfcf */

L_004DDF70:
    eax = (uint32_t)(int32_t)(int16_t)LO16(eax); /* 0x004DDF70: cwde  */
    edx = 0x59EB0084u; /* 0x004DDF71: mov edx, 0x59eb0084 */

L_004DDF76:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDF76: mov eax, dword ptr [ebp - 0x51c] */
    ecx = 0; /* 0x004DDF7C: xor ecx, ecx */
    SET_LO16(ecx, MEM16(ebp + eax * 2 + (-0x204))); /* 0x004DDF7E: mov cx, word ptr [ebp + eax*2 - 0x204] */
    ecx = ecx & 2; /* 0x004DDF86: and ecx, 2 */
    /* test ecx, ecx */ /* 0x004DDF89: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DDFC2; /* 0x004DDF8B: je 0x4ddfc2 */

L_004DDF8D:
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDF8D: mov edx, dword ptr [ebp - 0x51c] */
    SET_LO8(eax, MEM8(edx + 0x84B991)); /* 0x004DDF93: mov al, byte ptr [edx + 0x84b991] */
    SET_LO8(eax, LO8(eax) | 0x20u); /* 0x004DDF99: or al, 0x20 */
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DDF9B: mov ecx, dword ptr [ebp - 0x51c] */
    MEM8(ecx + 0x84B991) = (uint8_t)(LO8(eax)); /* 0x004DDFA1: mov byte ptr [ecx + 0x84b991], al */
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDFA7: mov edx, dword ptr [ebp - 0x51c] */
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDFAD: mov eax, dword ptr [ebp - 0x51c] */
    SET_LO8(ecx, MEM8(ebp + eax + (-0x518))); /* 0x004DDFB3: mov cl, byte ptr [ebp + eax - 0x518] */
    MEM8(edx + 0x84BA98) = (uint8_t)(LO8(ecx)); /* 0x004DDFBA: mov byte ptr [edx + 0x84ba98], cl */
    goto L_004DDFCF; /* 0x004DDFC0: jmp 0x4ddfcf */

L_004DDFC2:
    edx = MEM32(ebp + (-0x51C)); /* 0x004DDFC2: mov edx, dword ptr [ebp - 0x51c] */
    MEM8(edx + 0x84BA98) = (uint8_t)(0); /* 0x004DDFC8: mov byte ptr [edx + 0x84ba98], 0 */

L_004DDFCF:
    goto L_004DDF0A; /* 0x004DDFCF: jmp 0x4ddf0a */

L_004DDFD4:
    goto L_004DE09E; /* 0x004DDFD4: jmp 0x4de09e */

L_004DE09E:
    esp = ebp; /* 0x004DE09E: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE0A0: pop ebp */
    return; /* 0x004DE0A1: ret  */

}

void sub_004DE060(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DDFE5:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DDFE5: mov eax, dword ptr [ebp - 0x51c] */
    eax = eax + 1; /* 0x004DDFEB: add eax, 1 */
    MEM32(ebp + (-0x51C)) = eax; /* 0x004DDFEE: mov dword ptr [ebp - 0x51c], eax */
    /* cmp MEM32(ebp + (-0x51C)), 0x100u */ /* 0x004DDFF4: cmp dword ptr [ebp - 0x51c], 0x100 */
    if (CMP_AE(MEM32(ebp + (-0x51C)), 0x100u)) goto L_004DE09E; /* 0x004DDFFE: jae 0x4de09e */

L_004DE004:
    /* cmp MEM32(ebp + (-0x51C)), 0x41u */ /* 0x004DE004: cmp dword ptr [ebp - 0x51c], 0x41 */
    if (CMP_B(MEM32(ebp + (-0x51C)), 0x41u)) goto L_004DE048; /* 0x004DE00B: jb 0x4de048 */

L_004DE00D:
    /* cmp MEM32(ebp + (-0x51C)), 0x5Au */ /* 0x004DE00D: cmp dword ptr [ebp - 0x51c], 0x5a */
    if (CMP_A(MEM32(ebp + (-0x51C)), 0x5Au)) goto L_004DE048; /* 0x004DE014: ja 0x4de048 */

L_004DE016:
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DE016: mov ecx, dword ptr [ebp - 0x51c] */
    SET_LO8(edx, MEM8(ecx + 0x84B991)); /* 0x004DE01C: mov dl, byte ptr [ecx + 0x84b991] */
    SET_LO8(edx, LO8(edx) | 0x10u); /* 0x004DE022: or dl, 0x10 */
    eax = MEM32(ebp + (-0x51C)); /* 0x004DE025: mov eax, dword ptr [ebp - 0x51c] */
    MEM8(eax + 0x84B991) = (uint8_t)(LO8(edx)); /* 0x004DE02B: mov byte ptr [eax + 0x84b991], dl */
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DE031: mov ecx, dword ptr [ebp - 0x51c] */
    ecx = ecx + 0x20u; /* 0x004DE037: add ecx, 0x20 */
    edx = MEM32(ebp + (-0x51C)); /* 0x004DE03A: mov edx, dword ptr [ebp - 0x51c] */
    MEM8(edx + 0x84BA98) = (uint8_t)(LO8(ecx)); /* 0x004DE040: mov byte ptr [edx + 0x84ba98], cl */
    goto L_004DE099; /* 0x004DE046: jmp 0x4de099 */

L_004DE048:
    /* cmp MEM32(ebp + (-0x51C)), 0x61u */ /* 0x004DE048: cmp dword ptr [ebp - 0x51c], 0x61 */
    if (CMP_B(MEM32(ebp + (-0x51C)), 0x61u)) goto L_004DE08C; /* 0x004DE04F: jb 0x4de08c */

L_004DE051:
    /* cmp MEM32(ebp + (-0x51C)), 0x7Au */ /* 0x004DE051: cmp dword ptr [ebp - 0x51c], 0x7a */
    if (CMP_A(MEM32(ebp + (-0x51C)), 0x7Au)) goto L_004DE08C; /* 0x004DE058: ja 0x4de08c */

L_004DE05A:
    eax = MEM32(ebp + (-0x51C)); /* 0x004DE05A: mov eax, dword ptr [ebp - 0x51c] */

L_004DE060:
    SET_LO8(ecx, MEM8(eax + 0x84B991)); /* 0x004DE060: mov cl, byte ptr [eax + 0x84b991] */
    SET_LO8(ecx, LO8(ecx) | 0x20u); /* 0x004DE066: or cl, 0x20 */
    edx = MEM32(ebp + (-0x51C)); /* 0x004DE069: mov edx, dword ptr [ebp - 0x51c] */
    MEM8(edx + 0x84B991) = (uint8_t)(LO8(ecx)); /* 0x004DE06F: mov byte ptr [edx + 0x84b991], cl */
    eax = MEM32(ebp + (-0x51C)); /* 0x004DE075: mov eax, dword ptr [ebp - 0x51c] */
    eax = eax - 0x20u; /* 0x004DE07B: sub eax, 0x20 */
    ecx = MEM32(ebp + (-0x51C)); /* 0x004DE07E: mov ecx, dword ptr [ebp - 0x51c] */
    MEM8(ecx + 0x84BA98) = (uint8_t)(LO8(eax)); /* 0x004DE084: mov byte ptr [ecx + 0x84ba98], al */
    goto L_004DE099; /* 0x004DE08A: jmp 0x4de099 */

L_004DE08C:
    edx = MEM32(ebp + (-0x51C)); /* 0x004DE08C: mov edx, dword ptr [ebp - 0x51c] */
    MEM8(edx + 0x84BA98) = (uint8_t)(0); /* 0x004DE092: mov byte ptr [edx + 0x84ba98], 0 */

L_004DE099:
    goto L_004DDFE5; /* 0x004DE099: jmp 0x4ddfe5 */

L_004DE09E:
    esp = ebp; /* 0x004DE09E: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE0A0: pop ebp */
    return; /* 0x004DE0A1: ret  */

}

void sub_004DE143(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE11B:
    /* cmp esi, 0xFFFFFFFFu */ /* 0x004DE11B: cmp esi, -1 */
    if (CMP_EQ(esi, 0xFFFFFFFFu)) goto L_004DE181; /* 0x004DE11E: je 0x4de181 */

L_004DE120:
    ecx = esi + esi * 2; /* 0x004DE120: lea ecx, [esi + esi*2] */
    /* cmp MEM32(edi + ecx * 4 + 0x4), 0 */ /* 0x004DE123: cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (CMP_EQ(MEM32(edi + ecx * 4 + 0x4), 0)) goto L_004DE16F; /* 0x004DE128: je 0x4de16f */

L_004DE12A:
    PUSH32(esp, esi); /* 0x004DE12A: push esi */
    PUSH32(esp, ebp); /* 0x004DE12B: push ebp */
    ebp = ebx + 0x10; /* 0x004DE12C: lea ebp, [ebx + 0x10] */
    RECOMP_ICALL(MEM32(edi + ecx * 4 + 0x4)); /* 0x004DE12F: call dword ptr [edi + ecx*4 + 4] */
    ebp = POP32_VAL(esp); /* 0x004DE133: pop ebp */
    esi = POP32_VAL(esp); /* 0x004DE134: pop esi */
    ebx = MEM32(ebp + 0xC); /* 0x004DE135: mov ebx, dword ptr [ebp + 0xc] */
    eax = eax | eax; /* 0x004DE138: or eax, eax */
    if (/* or result */ TEST_Z(eax, eax)) goto L_004DE16F; /* 0x004DE13A: je 0x4de16f */

L_004DE13C:
    if (/* no flag state for js */ _cf) goto L_004DE17A; /* 0x004DE13C: js 0x4de17a */

L_004DE13E:
    edi = MEM32(ebx + 0x8); /* 0x004DE13E: mov edi, dword ptr [ebx + 8] */
    PUSH32(esp, ebx); /* 0x004DE141: push ebx */
    RECOMP_CALL(sub_004D1580); /* 0x004DE142: call 0x4d1580 */
    esp = esp + 4; /* 0x004DE147: add esp, 4 */
    ebp = ebx + 0x10; /* 0x004DE14A: lea ebp, [ebx + 0x10] */
    PUSH32(esp, esi); /* 0x004DE14D: push esi */
    PUSH32(esp, ebx); /* 0x004DE14E: push ebx */
    RECOMP_CALL(sub_004D15C2); /* 0x004DE14F: call 0x4d15c2 */
    esp = esp + 8; /* 0x004DE154: add esp, 8 */
    ecx = esi + esi * 2; /* 0x004DE157: lea ecx, [esi + esi*2] */
    PUSH32(esp, 1); /* 0x004DE15A: push 1 */
    eax = MEM32(edi + ecx * 4 + 0x8); /* 0x004DE15C: mov eax, dword ptr [edi + ecx*4 + 8] */
    RECOMP_CALL(sub_004D1656); /* 0x004DE160: call 0x4d1656 */
    eax = MEM32(edi + ecx * 4); /* 0x004DE165: mov eax, dword ptr [edi + ecx*4] */
    MEM32(ebx + 0xC) = eax; /* 0x004DE168: mov dword ptr [ebx + 0xc], eax */
    RECOMP_ICALL(MEM32(edi + ecx * 4 + 0x8)); /* 0x004DE16B: call dword ptr [edi + ecx*4 + 8] */

L_004DE143:
    /* cmp MEM32(edi + edi * 8), esi */ /* 0x004DE143: cmp dword ptr [edi + edi*8], esi */
    MEM32(ebx + 0x6B8D04C4) = MEM32(ebx + 0x6B8D04C4) + 1; /* 0x004DE146: inc dword ptr [ebx + 0x6b8d04c4] */
    MEM8(esi + 0x53) = (uint8_t)(MEM8(esi + 0x53) + LO8(edx) + _cf); /* 0x004DE14C: adc byte ptr [esi + 0x53], dl */
    RECOMP_CALL(sub_004D15C2); /* 0x004DE14F: call 0x4d15c2 */
    esp = esp + 8; /* 0x004DE154: add esp, 8 */
    ecx = esi + esi * 2; /* 0x004DE157: lea ecx, [esi + esi*2] */
    PUSH32(esp, 1); /* 0x004DE15A: push 1 */
    eax = MEM32(edi + ecx * 4 + 0x8); /* 0x004DE15C: mov eax, dword ptr [edi + ecx*4 + 8] */
    RECOMP_CALL(sub_004D1656); /* 0x004DE160: call 0x4d1656 */
    eax = MEM32(edi + ecx * 4); /* 0x004DE165: mov eax, dword ptr [edi + ecx*4] */
    MEM32(ebx + 0xC) = eax; /* 0x004DE168: mov dword ptr [ebx + 0xc], eax */
    RECOMP_ICALL(MEM32(edi + ecx * 4 + 0x8)); /* 0x004DE16B: call dword ptr [edi + ecx*4 + 8] */

L_004DE16F:
    edi = MEM32(ebx + 0x8); /* 0x004DE16F: mov edi, dword ptr [ebx + 8] */
    ecx = esi + esi * 2; /* 0x004DE172: lea ecx, [esi + esi*2] */
    esi = MEM32(edi + ecx * 4); /* 0x004DE175: mov esi, dword ptr [edi + ecx*4] */
    goto L_004DE11B; /* 0x004DE178: jmp 0x4de11b */

L_004DE17A:
    eax = 0; /* 0x004DE17A: mov eax, 0 */
    goto L_004DE19D; /* 0x004DE17F: jmp 0x4de19d */

L_004DE181:
    eax = 1; /* 0x004DE181: mov eax, 1 */
    goto L_004DE19D; /* 0x004DE186: jmp 0x4de19d */

L_004DE19D:
    ebp = POP32_VAL(esp); /* 0x004DE19D: pop ebp */
    edi = POP32_VAL(esp); /* 0x004DE19E: pop edi */
    esi = POP32_VAL(esp); /* 0x004DE19F: pop esi */
    ebx = POP32_VAL(esp); /* 0x004DE1A0: pop ebx */
    esp = ebp; /* 0x004DE1A1: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE1A3: pop ebp */
    return; /* 0x004DE1A4: ret  */

}

void sub_004DE1EA(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE1EA:
    SET_LO8(eax, LO8(eax) + 0x83u); /* 0x004DE1EA: add al, 0x83 */
    /* cmp eax, 0x0084BBB0u */ /* 0x004DE1EC: cmp eax, 0x84bbb0 */
    MEM8(esi + eax + (-0x1)) = (uint8_t)(MEM8(esi + eax + (-0x1)) + HI8(edx)); /* 0x004DE1F1: add byte ptr [esi + eax - 1], dh */
    eax = eax + 0x0084BBB0u + _cf; /* 0x004DE1F5: adc eax, 0x84bbb0 */
    PUSH32(esp, 0xFFu); /* 0x004DE1FA: push 0xff */
    RECOMP_CALL(sub_004DE210); /* 0x004DE1FF: call 0x4de210 */
    esp = esp + 4; /* 0x004DE204: add esp, 4 */
    ebp = POP32_VAL(esp); /* 0x004DE207: pop ebp */
    return; /* 0x004DE208: ret  */

}

void sub_004DE2B0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE2B0:
    SET_HI8(ebx, HI8(ebx) + HI8(ebx) + _cf); /* 0x004DE2B0: adc bh, bh */
    if (/* no flag state for je */ _cf) goto L_004DE2C5; /* 0x004DE2B2: je 0x4de2c5 */

L_004DE2B4:
    edx = MEM32(0x855C60); /* 0x004DE2B4: mov edx, dword ptr [0x855c60] */
    eax = MEM32(edx + 0x10); /* 0x004DE2BA: mov eax, dword ptr [edx + 0x10] */
    MEM32(ebp + (-0x1B4)) = eax; /* 0x004DE2BD: mov dword ptr [ebp - 0x1b4], eax */
    goto L_004DE2D3; /* 0x004DE2C3: jmp 0x4de2d3 */

L_004DE2C5:
    PUSH32(esp, 0xFFFFFFF4u); /* 0x004DE2C5: push -0xc */
    RECOMP_ICALL(MEM32(0x858758)); /* 0x004DE2C7: call dword ptr [0x858758] */
    MEM32(ebp + (-0x1B4)) = eax; /* 0x004DE2CD: mov dword ptr [ebp - 0x1b4], eax */

L_004DE2D3:
    PUSH32(esp, 0); /* 0x004DE2D3: push 0 */
    ecx = ebp + (-0x4); /* 0x004DE2D5: lea ecx, [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004DE2D8: push ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DE2D9: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx * 8 + 0x50B804); /* 0x004DE2DC: mov eax, dword ptr [edx*8 + 0x50b804] */
    PUSH32(esp, eax); /* 0x004DE2E3: push eax */
    RECOMP_CALL(sub_004D5870); /* 0x004DE2E4: call 0x4d5870 */
    esp = esp + 4; /* 0x004DE2E9: add esp, 4 */
    PUSH32(esp, eax); /* 0x004DE2EC: push eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DE2ED: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx * 8 + 0x50B804); /* 0x004DE2F0: mov edx, dword ptr [ecx*8 + 0x50b804] */
    PUSH32(esp, edx); /* 0x004DE2F7: push edx */
    eax = MEM32(ebp + (-0x1B4)); /* 0x004DE2F8: mov eax, dword ptr [ebp - 0x1b4] */
    PUSH32(esp, eax); /* 0x004DE2FE: push eax */
    RECOMP_ICALL(MEM32(0x858724)); /* 0x004DE2FF: call dword ptr [0x858724] */
    goto L_004DE3FA; /* 0x004DE305: jmp 0x4de3fa */

L_004DE3FA:
    edi = POP32_VAL(esp); /* 0x004DE3FA: pop edi */
    esi = POP32_VAL(esp); /* 0x004DE3FB: pop esi */
    ebx = POP32_VAL(esp); /* 0x004DE3FC: pop ebx */
    esp = ebp; /* 0x004DE3FD: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE3FF: pop ebp */
    return; /* 0x004DE400: ret  */

}

void sub_004DE2D0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

}

void sub_004DE2F0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE2F0:
    edx = MEM32(ecx * 8 + 0x50B804); /* 0x004DE2F0: mov edx, dword ptr [ecx*8 + 0x50b804] */
    PUSH32(esp, edx); /* 0x004DE2F7: push edx */
    eax = MEM32(ebp + (-0x1B4)); /* 0x004DE2F8: mov eax, dword ptr [ebp - 0x1b4] */
    PUSH32(esp, eax); /* 0x004DE2FE: push eax */
    RECOMP_ICALL(MEM32(0x858724)); /* 0x004DE2FF: call dword ptr [0x858724] */
    goto L_004DE3FA; /* 0x004DE305: jmp 0x4de3fa */

L_004DE3FA:
    edi = POP32_VAL(esp); /* 0x004DE3FA: pop edi */
    esi = POP32_VAL(esp); /* 0x004DE3FB: pop esi */
    ebx = POP32_VAL(esp); /* 0x004DE3FC: pop ebx */
    esp = ebp; /* 0x004DE3FD: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE3FF: pop ebp */
    return; /* 0x004DE400: ret  */

}

void sub_004DE3B0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE3B0:
    esp = esp + 8; /* 0x004DE3B0: add esp, 8 */
    PUSH32(esp, 0x004F3E14u); /* 0x004DE3B3: push 0x4f3e14 */
    ecx = ebp + (-0x1B0); /* 0x004DE3B8: lea ecx, [ebp - 0x1b0] */
    PUSH32(esp, ecx); /* 0x004DE3BE: push ecx */
    RECOMP_CALL(sub_004DC820); /* 0x004DE3BF: call 0x4dc820 */
    esp = esp + 8; /* 0x004DE3C4: add esp, 8 */
    edx = MEM32(ebp + (-0x8)); /* 0x004DE3C7: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx * 8 + 0x50B804); /* 0x004DE3CA: mov eax, dword ptr [edx*8 + 0x50b804] */
    PUSH32(esp, eax); /* 0x004DE3D1: push eax */
    ecx = ebp + (-0x1B0); /* 0x004DE3D2: lea ecx, [ebp - 0x1b0] */
    PUSH32(esp, ecx); /* 0x004DE3D8: push ecx */
    RECOMP_CALL(sub_004DC820); /* 0x004DE3D9: call 0x4dc820 */
    esp = esp + 8; /* 0x004DE3DE: add esp, 8 */
    PUSH32(esp, 0x00012010u); /* 0x004DE3E1: push 0x12010 */
    PUSH32(esp, 0x004F3E20u); /* 0x004DE3E6: push 0x4f3e20 */
    edx = ebp + (-0x1B0); /* 0x004DE3EB: lea edx, [ebp - 0x1b0] */
    PUSH32(esp, edx); /* 0x004DE3F1: push edx */
    RECOMP_CALL(sub_004DC350); /* 0x004DE3F2: call 0x4dc350 */
    esp = esp + 0xCu; /* 0x004DE3F7: add esp, 0xc */
    edi = POP32_VAL(esp); /* 0x004DE3FA: pop edi */
    esi = POP32_VAL(esp); /* 0x004DE3FB: pop esi */
    ebx = POP32_VAL(esp); /* 0x004DE3FC: pop ebx */
    esp = ebp; /* 0x004DE3FD: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE3FF: pop ebp */
    return; /* 0x004DE400: ret  */

}

void sub_004DE430(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE430:
    PUSH32(esp, ebp); /* 0x004DE430: push ebp */
    MEM8(ebx) = (uint8_t)(MEM8(ebx) | HI8(ebx)); /* 0x004DE431: or byte ptr [ebx], bh */
    SET_LO8(eax, LO8(eax) + 0xCDu + _cf); /* 0x004DE433: adc al, 0xcd */
    MEM8(eax + 0x2750050) = (uint8_t)(MEM8(eax + 0x2750050) + HI8(ebx)); /* 0x004DE435: add byte ptr [eax + 0x2750050], bh */
    goto L_004DE43F; /* 0x004DE43B: jmp 0x4de43f */

L_004DE43F:
    eax = MEM32(ebp + (-0x4)); /* 0x004DE43F: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(ebp + 0x8); /* 0x004DE442: mov ecx, dword ptr [ebp + 8] */
    /* cmp ecx, MEM32(eax * 8 + 0x50B800) */ /* 0x004DE445: cmp ecx, dword ptr [eax*8 + 0x50b800] */
    if (CMP_NE(ecx, MEM32(eax * 8 + 0x50B800))) goto L_004DE45A; /* 0x004DE44C: jne 0x4de45a */

L_004DE44E:
    edx = MEM32(ebp + (-0x4)); /* 0x004DE44E: mov edx, dword ptr [ebp - 4] */
    eax = MEM32(edx * 8 + 0x50B804); /* 0x004DE451: mov eax, dword ptr [edx*8 + 0x50b804] */
    goto L_004DE45C; /* 0x004DE458: jmp 0x4de45c */

L_004DE45A:
    eax = 0; /* 0x004DE45A: xor eax, eax */

L_004DE45C:
    esp = ebp; /* 0x004DE45C: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE45E: pop ebp */
    return; /* 0x004DE45F: ret  */

}

void sub_004DE470(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE470:
    ebx = 0x8B500084u; /* 0x004DE470: mov ebx, 0x8b500084 */
    ebp = ebp - 1; /* 0x004DE475: dec ebp */
    MEM8(ecx + (-0x75)) = (uint8_t)(MEM8(ecx + (-0x75)) + LO8(edx) + _cf); /* 0x004DE476: adc byte ptr [ecx - 0x75], dl */
    PUSH32(esp, ebp); /* 0x004DE479: push ebp */
    SET_LO8(eax, LO8(eax) | 0x52u); /* 0x004DE47A: or al, 0x52 */
    eax = MEM32(ebp + 0x10); /* 0x004DE47C: mov eax, dword ptr [ebp + 0x10] */
    PUSH32(esp, eax); /* 0x004DE47F: push eax */
    ecx = MEM32(ebp + 0x8); /* 0x004DE480: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004DE483: push ecx */
    PUSH32(esp, 1); /* 0x004DE484: push 1 */
    edx = MEM32(0x84BB9C); /* 0x004DE486: mov edx, dword ptr [0x84bb9c] */
    PUSH32(esp, edx); /* 0x004DE48C: push edx */
    RECOMP_CALL(sub_004E1AE0); /* 0x004DE48D: call 0x4e1ae0 */
    esp = esp + 0x1Cu; /* 0x004DE492: add esp, 0x1c */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DE495: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DE498: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004DE4A5; /* 0x004DE49C: jne 0x4de4a5 */

L_004DE49E:
    eax = 0x7FFFFFFFu; /* 0x004DE49E: mov eax, 0x7fffffff */
    goto L_004DE4AB; /* 0x004DE4A3: jmp 0x4de4ab */

L_004DE4A5:
    eax = MEM32(ebp + (-0x4)); /* 0x004DE4A5: mov eax, dword ptr [ebp - 4] */
    eax = eax - 2; /* 0x004DE4A8: sub eax, 2 */

L_004DE4AB:
    esp = ebp; /* 0x004DE4AB: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE4AD: pop ebp */
    return; /* 0x004DE4AE: ret  */

}

void sub_004DE560(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE560:
    edx = MEM32(esp + 0x4); /* 0x004DE560: mov edx, dword ptr [esp + 4] */
    ecx = MEM32(esp + 0x8); /* 0x004DE564: mov ecx, dword ptr [esp + 8] */
    /* test edx, 3 */ /* 0x004DE568: test edx, 3 */
    if (TEST_NZ(edx, 3)) goto L_004DE5AC; /* 0x004DE56E: jne 0x4de5ac */

L_004DE570:
    eax = MEM32(edx); /* 0x004DE570: mov eax, dword ptr [edx] */
    /* cmp LO8(eax), MEM8(ecx) */ /* 0x004DE572: cmp al, byte ptr [ecx] */
    if (CMP_NE(LO8(eax), MEM8(ecx))) goto L_004DE5A4; /* 0x004DE574: jne 0x4de5a4 */

L_004DE576:
    SET_LO8(eax, LO8(eax) | LO8(eax)); /* 0x004DE576: or al, al */
    if (/* or result */ TEST_Z(LO8(eax), LO8(eax))) goto L_004DE5A0; /* 0x004DE578: je 0x4de5a0 */

L_004DE57A:
    /* cmp HI8(eax), MEM8(ecx + 0x1) */ /* 0x004DE57A: cmp ah, byte ptr [ecx + 1] */
    if (CMP_NE(HI8(eax), MEM8(ecx + 0x1))) goto L_004DE5A4; /* 0x004DE57D: jne 0x4de5a4 */

L_004DE57F:
    SET_HI8(eax, HI8(eax) | HI8(eax)); /* 0x004DE57F: or ah, ah */
    if (/* or result */ TEST_Z(HI8(eax), HI8(eax))) goto L_004DE5A0; /* 0x004DE581: je 0x4de5a0 */

L_004DE583:
    eax = eax >> 0x10u; /* 0x004DE583: shr eax, 0x10 */
    /* cmp LO8(eax), MEM8(ecx + 0x2) */ /* 0x004DE586: cmp al, byte ptr [ecx + 2] */
    if (CMP_NE(LO8(eax), MEM8(ecx + 0x2))) goto L_004DE5A4; /* 0x004DE589: jne 0x4de5a4 */

L_004DE58B:
    SET_LO8(eax, LO8(eax) | LO8(eax)); /* 0x004DE58B: or al, al */
    if (/* or result */ TEST_Z(LO8(eax), LO8(eax))) goto L_004DE5A0; /* 0x004DE58D: je 0x4de5a0 */

L_004DE58F:
    /* cmp HI8(eax), MEM8(ecx + 0x3) */ /* 0x004DE58F: cmp ah, byte ptr [ecx + 3] */
    if (CMP_NE(HI8(eax), MEM8(ecx + 0x3))) goto L_004DE5A4; /* 0x004DE592: jne 0x4de5a4 */

L_004DE594:
    ecx = ecx + 4; /* 0x004DE594: add ecx, 4 */
    edx = edx + 4; /* 0x004DE597: add edx, 4 */
    SET_HI8(eax, HI8(eax) | HI8(eax)); /* 0x004DE59A: or ah, ah */
    if (/* or result */ TEST_NZ(HI8(eax), HI8(eax))) goto L_004DE570; /* 0x004DE59C: jne 0x4de570 */

L_004DE59E:
    eax = eax; /* 0x004DE59E: mov eax, eax */

L_004DE5A0:
    eax = 0; /* 0x004DE5A0: xor eax, eax */
    return; /* 0x004DE5A2: ret  */

L_004DE5A4:
    eax = _cf ? 0xFFFFFFFFu : 0; /* 0x004DE5A4: sbb eax, eax */
    eax = eax << 1; /* 0x004DE5A6: shl eax, 1 */
    eax = eax + 1; /* 0x004DE5A8: inc eax */
    return; /* 0x004DE5A9: ret  */

L_004DE5AC:
    /* test edx, 1 */ /* 0x004DE5AC: test edx, 1 */
    if (TEST_Z(edx, 1)) goto L_004DE5C8; /* 0x004DE5B2: je 0x4de5c8 */

L_004DE5B4:
    SET_LO8(eax, MEM8(edx)); /* 0x004DE5B4: mov al, byte ptr [edx] */
    edx = edx + 1; /* 0x004DE5B6: inc edx */
    /* cmp LO8(eax), MEM8(ecx) */ /* 0x004DE5B7: cmp al, byte ptr [ecx] */
    if (CMP_NE(LO8(eax), MEM8(ecx))) goto L_004DE5A4; /* 0x004DE5B9: jne 0x4de5a4 */

L_004DE5BB:
    ecx = ecx + 1; /* 0x004DE5BB: inc ecx */
    SET_LO8(eax, LO8(eax) | LO8(eax)); /* 0x004DE5BC: or al, al */
    if (/* or result */ TEST_Z(LO8(eax), LO8(eax))) goto L_004DE5A0; /* 0x004DE5BE: je 0x4de5a0 */

L_004DE5C0:
    /* test edx, 2 */ /* 0x004DE5C0: test edx, 2 */
    if (TEST_Z(edx, 2)) goto L_004DE570; /* 0x004DE5C6: je 0x4de570 */

L_004DE5C8:
    SET_LO16(eax, MEM16(edx)); /* 0x004DE5C8: mov ax, word ptr [edx] */
    edx = edx + 2; /* 0x004DE5CB: add edx, 2 */
    /* cmp LO8(eax), MEM8(ecx) */ /* 0x004DE5CE: cmp al, byte ptr [ecx] */
    if (CMP_NE(LO8(eax), MEM8(ecx))) goto L_004DE5A4; /* 0x004DE5D0: jne 0x4de5a4 */

L_004DE5D2:
    SET_LO8(eax, LO8(eax) | LO8(eax)); /* 0x004DE5D2: or al, al */
    if (/* or result */ TEST_Z(LO8(eax), LO8(eax))) goto L_004DE5A0; /* 0x004DE5D4: je 0x4de5a0 */

L_004DE5D6:
    /* cmp HI8(eax), MEM8(ecx + 0x1) */ /* 0x004DE5D6: cmp ah, byte ptr [ecx + 1] */
    if (CMP_NE(HI8(eax), MEM8(ecx + 0x1))) goto L_004DE5A4; /* 0x004DE5D9: jne 0x4de5a4 */

L_004DE5DB:
    SET_HI8(eax, HI8(eax) | HI8(eax)); /* 0x004DE5DB: or ah, ah */
    if (/* or result */ TEST_Z(HI8(eax), HI8(eax))) goto L_004DE5A0; /* 0x004DE5DD: je 0x4de5a0 */

L_004DE5DF:
    ecx = ecx + 2; /* 0x004DE5DF: add ecx, 2 */
    goto L_004DE570; /* 0x004DE5E2: jmp 0x4de570 */

}

void sub_004DE5E0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE5E0:
    MEM32(edx) = ROL32(MEM32(edx), 0xEBu); /* 0x004DE5E0: rol dword ptr [edx], 0xeb */
    esp = _seg_cs; /* 0x004DE5E3: mov esp, cs */
    /* int3 breakpoint */ /* 0x004DE5E5: int3  */

}

void sub_004DE760(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE760:
    PUSH32(esp, ebp); /* 0x004DE760: push ebp */
    ebp = esp; /* 0x004DE761: mov ebp, esp */
    esp = esp - 0x10u; /* 0x004DE763: sub esp, 0x10 */
    /* cmp MEM32(0x84BCC0), 0 */ /* 0x004DE766: cmp dword ptr [0x84bcc0], 0 */
    if (CMP_NE(MEM32(0x84BCC0), 0)) goto L_004DE78C; /* 0x004DE76D: jne 0x4de78c */

L_004DE76F:
    /* cmp MEM32(ebp + 0x8), 0x41u */ /* 0x004DE76F: cmp dword ptr [ebp + 8], 0x41 */
    if (CMP_L(MEM32(ebp + 0x8), 0x41u)) goto L_004DE784; /* 0x004DE773: jl 0x4de784 */

L_004DE775:
    /* cmp MEM32(ebp + 0x8), 0x5Au */ /* 0x004DE775: cmp dword ptr [ebp + 8], 0x5a */
    if (CMP_G(MEM32(ebp + 0x8), 0x5Au)) goto L_004DE784; /* 0x004DE779: jg 0x4de784 */

L_004DE77B:
    eax = MEM32(ebp + 0x8); /* 0x004DE77B: mov eax, dword ptr [ebp + 8] */
    eax = eax + 0x20u; /* 0x004DE77E: add eax, 0x20 */
    MEM32(ebp + 0x8) = eax; /* 0x004DE781: mov dword ptr [ebp + 8], eax */

L_004DE784:
    eax = MEM32(ebp + 0x8); /* 0x004DE784: mov eax, dword ptr [ebp + 8] */
    goto L_004DE887; /* 0x004DE787: jmp 0x4de887 */

L_004DE78C:
    /* cmp MEM32(ebp + 0x8), 0x100u */ /* 0x004DE78C: cmp dword ptr [ebp + 8], 0x100 */
    if (CMP_GE(MEM32(ebp + 0x8), 0x100u)) goto L_004DE7D3; /* 0x004DE793: jge 0x4de7d3 */

L_004DE795:
    /* cmp MEM32(0x509634), 1 */ /* 0x004DE795: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004DE7B1; /* 0x004DE79C: jle 0x4de7b1 */

L_004DE79E:
    PUSH32(esp, 1); /* 0x004DE79E: push 1 */
    ecx = MEM32(ebp + 0x8); /* 0x004DE7A0: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004DE7A3: push ecx */
    RECOMP_CALL(sub_004DA490); /* 0x004DE7A4: call 0x4da490 */
    esp = esp + 8; /* 0x004DE7A9: add esp, 8 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DE7AC: mov dword ptr [ebp - 0x10], eax */
    goto L_004DE7C5; /* 0x004DE7AF: jmp 0x4de7c5 */

L_004DE7B1:
    edx = MEM32(ebp + 0x8); /* 0x004DE7B1: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(0x509428); /* 0x004DE7B4: mov eax, dword ptr [0x509428] */
    ecx = 0; /* 0x004DE7B9: xor ecx, ecx */
    SET_LO16(ecx, MEM16(eax + edx * 2)); /* 0x004DE7BB: mov cx, word ptr [eax + edx*2] */
    ecx = ecx & 1; /* 0x004DE7BF: and ecx, 1 */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004DE7C2: mov dword ptr [ebp - 0x10], ecx */

L_004DE7C5:
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004DE7C5: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004DE7D3; /* 0x004DE7C9: jne 0x4de7d3 */

L_004DE7CB:
    eax = MEM32(ebp + 0x8); /* 0x004DE7CB: mov eax, dword ptr [ebp + 8] */
    goto L_004DE887; /* 0x004DE7CE: jmp 0x4de887 */

L_004DE7D3:
    edx = MEM32(ebp + 0x8); /* 0x004DE7D3: mov edx, dword ptr [ebp + 8] */
    edx = (uint32_t)((int32_t)edx >> 8); /* 0x004DE7D6: sar edx, 8 */
    edx = edx & 0xFFu; /* 0x004DE7D9: and edx, 0xff */
    edx = edx & 0xFFu; /* 0x004DE7DF: and edx, 0xff */
    eax = MEM32(0x509428); /* 0x004DE7E5: mov eax, dword ptr [0x509428] */
    ecx = 0; /* 0x004DE7EA: xor ecx, ecx */
    SET_LO16(ecx, MEM16(eax + edx * 2)); /* 0x004DE7EC: mov cx, word ptr [eax + edx*2] */
    ecx = ecx & 0x8000u; /* 0x004DE7F0: and ecx, 0x8000 */
    /* test ecx, ecx */ /* 0x004DE7F6: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DE81C; /* 0x004DE7F8: je 0x4de81c */

L_004DE7FA:
    edx = MEM32(ebp + 0x8); /* 0x004DE7FA: mov edx, dword ptr [ebp + 8] */
    edx = (uint32_t)((int32_t)edx >> 8); /* 0x004DE7FD: sar edx, 8 */
    edx = edx & 0xFFu; /* 0x004DE800: and edx, 0xff */
    MEM8(ebp + (-0x8)) = (uint8_t)(LO8(edx)); /* 0x004DE806: mov byte ptr [ebp - 8], dl */
    SET_LO8(eax, MEM8(ebp + 0x8)); /* 0x004DE809: mov al, byte ptr [ebp + 8] */
    MEM8(ebp + (-0x7)) = (uint8_t)(LO8(eax)); /* 0x004DE80C: mov byte ptr [ebp - 7], al */
    MEM8(ebp + (-0x6)) = (uint8_t)(0); /* 0x004DE80F: mov byte ptr [ebp - 6], 0 */
    MEM32(ebp + (-0x4)) = 2; /* 0x004DE813: mov dword ptr [ebp - 4], 2 */
    goto L_004DE82D; /* 0x004DE81A: jmp 0x4de82d */

L_004DE81C:
    SET_LO8(ecx, MEM8(ebp + 0x8)); /* 0x004DE81C: mov cl, byte ptr [ebp + 8] */
    MEM8(ebp + (-0x8)) = (uint8_t)(LO8(ecx)); /* 0x004DE81F: mov byte ptr [ebp - 8], cl */
    MEM8(ebp + (-0x7)) = (uint8_t)(0); /* 0x004DE822: mov byte ptr [ebp - 7], 0 */
    MEM32(ebp + (-0x4)) = 1; /* 0x004DE826: mov dword ptr [ebp - 4], 1 */

L_004DE82D:
    PUSH32(esp, 1); /* 0x004DE82D: push 1 */
    PUSH32(esp, 0); /* 0x004DE82F: push 0 */
    PUSH32(esp, 3); /* 0x004DE831: push 3 */
    edx = ebp + (-0xC); /* 0x004DE833: lea edx, [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004DE836: push edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DE837: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004DE83A: push eax */
    ecx = ebp + (-0x8); /* 0x004DE83B: lea ecx, [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DE83E: push ecx */
    PUSH32(esp, 0x100u); /* 0x004DE83F: push 0x100 */
    edx = MEM32(0x84BCC0); /* 0x004DE844: mov edx, dword ptr [0x84bcc0] */
    PUSH32(esp, edx); /* 0x004DE84A: push edx */
    RECOMP_CALL(sub_004E14C0); /* 0x004DE84B: call 0x4e14c0 */
    esp = esp + 0x20u; /* 0x004DE850: add esp, 0x20 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DE853: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DE856: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004DE861; /* 0x004DE85A: jne 0x4de861 */

L_004DE85C:
    eax = MEM32(ebp + 0x8); /* 0x004DE85C: mov eax, dword ptr [ebp + 8] */
    goto L_004DE887; /* 0x004DE85F: jmp 0x4de887 */

L_004DE861:
    /* cmp MEM32(ebp + (-0x4)), 1 */ /* 0x004DE861: cmp dword ptr [ebp - 4], 1 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 1)) goto L_004DE871; /* 0x004DE865: jne 0x4de871 */

L_004DE867:
    eax = MEM32(ebp + (-0xC)); /* 0x004DE867: mov eax, dword ptr [ebp - 0xc] */
    eax = eax & 0xFFu; /* 0x004DE86A: and eax, 0xff */
    goto L_004DE887; /* 0x004DE86F: jmp 0x4de887 */

L_004DE871:
    eax = MEM32(ebp + (-0xC)); /* 0x004DE871: mov eax, dword ptr [ebp - 0xc] */
    eax = eax & 0xFFu; /* 0x004DE874: and eax, 0xff */
    ecx = MEM32(ebp + (-0xB)); /* 0x004DE879: mov ecx, dword ptr [ebp - 0xb] */
    ecx = ecx & 0xFFu; /* 0x004DE87C: and ecx, 0xff */
    ecx = ecx << 8; /* 0x004DE882: shl ecx, 8 */
    eax = eax | ecx; /* 0x004DE885: or eax, ecx */

L_004DE887:
    esp = ebp; /* 0x004DE887: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE889: pop ebp */
    return; /* 0x004DE88A: ret  */

}

void sub_004DE790(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE790:
    MEM32(eax) = MEM32(eax) + eax; /* 0x004DE790: add dword ptr [eax], eax */
    MEM8(ebp + 0x3E) = (uint8_t)(MEM8(ebp + 0x3E) + HI8(ebx)); /* 0x004DE792: add byte ptr [ebp + 0x3e], bh */
    /* cmp MEM32(0x509634), 1 */ /* 0x004DE795: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004DE7B1; /* 0x004DE79C: jle 0x4de7b1 */

L_004DE79E:
    PUSH32(esp, 1); /* 0x004DE79E: push 1 */
    ecx = MEM32(ebp + 0x8); /* 0x004DE7A0: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004DE7A3: push ecx */
    RECOMP_CALL(sub_004DA490); /* 0x004DE7A4: call 0x4da490 */
    esp = esp + 8; /* 0x004DE7A9: add esp, 8 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DE7AC: mov dword ptr [ebp - 0x10], eax */
    goto L_004DE7C5; /* 0x004DE7AF: jmp 0x4de7c5 */

L_004DE7B1:
    edx = MEM32(ebp + 0x8); /* 0x004DE7B1: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(0x509428); /* 0x004DE7B4: mov eax, dword ptr [0x509428] */
    ecx = 0; /* 0x004DE7B9: xor ecx, ecx */
    SET_LO16(ecx, MEM16(eax + edx * 2)); /* 0x004DE7BB: mov cx, word ptr [eax + edx*2] */
    ecx = ecx & 1; /* 0x004DE7BF: and ecx, 1 */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004DE7C2: mov dword ptr [ebp - 0x10], ecx */

L_004DE7C5:
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004DE7C5: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004DE7D3; /* 0x004DE7C9: jne 0x4de7d3 */

L_004DE7CB:
    eax = MEM32(ebp + 0x8); /* 0x004DE7CB: mov eax, dword ptr [ebp + 8] */
    goto L_004DE887; /* 0x004DE7CE: jmp 0x4de887 */

L_004DE7D3:
    edx = MEM32(ebp + 0x8); /* 0x004DE7D3: mov edx, dword ptr [ebp + 8] */
    edx = (uint32_t)((int32_t)edx >> 8); /* 0x004DE7D6: sar edx, 8 */
    edx = edx & 0xFFu; /* 0x004DE7D9: and edx, 0xff */
    edx = edx & 0xFFu; /* 0x004DE7DF: and edx, 0xff */
    eax = MEM32(0x509428); /* 0x004DE7E5: mov eax, dword ptr [0x509428] */
    ecx = 0; /* 0x004DE7EA: xor ecx, ecx */
    SET_LO16(ecx, MEM16(eax + edx * 2)); /* 0x004DE7EC: mov cx, word ptr [eax + edx*2] */
    ecx = ecx & 0x8000u; /* 0x004DE7F0: and ecx, 0x8000 */
    /* test ecx, ecx */ /* 0x004DE7F6: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004DE81C; /* 0x004DE7F8: je 0x4de81c */

L_004DE7FA:
    edx = MEM32(ebp + 0x8); /* 0x004DE7FA: mov edx, dword ptr [ebp + 8] */
    edx = (uint32_t)((int32_t)edx >> 8); /* 0x004DE7FD: sar edx, 8 */
    edx = edx & 0xFFu; /* 0x004DE800: and edx, 0xff */
    MEM8(ebp + (-0x8)) = (uint8_t)(LO8(edx)); /* 0x004DE806: mov byte ptr [ebp - 8], dl */
    SET_LO8(eax, MEM8(ebp + 0x8)); /* 0x004DE809: mov al, byte ptr [ebp + 8] */
    MEM8(ebp + (-0x7)) = (uint8_t)(LO8(eax)); /* 0x004DE80C: mov byte ptr [ebp - 7], al */
    MEM8(ebp + (-0x6)) = (uint8_t)(0); /* 0x004DE80F: mov byte ptr [ebp - 6], 0 */
    MEM32(ebp + (-0x4)) = 2; /* 0x004DE813: mov dword ptr [ebp - 4], 2 */
    goto L_004DE82D; /* 0x004DE81A: jmp 0x4de82d */

L_004DE81C:
    SET_LO8(ecx, MEM8(ebp + 0x8)); /* 0x004DE81C: mov cl, byte ptr [ebp + 8] */
    MEM8(ebp + (-0x8)) = (uint8_t)(LO8(ecx)); /* 0x004DE81F: mov byte ptr [ebp - 8], cl */
    MEM8(ebp + (-0x7)) = (uint8_t)(0); /* 0x004DE822: mov byte ptr [ebp - 7], 0 */
    MEM32(ebp + (-0x4)) = 1; /* 0x004DE826: mov dword ptr [ebp - 4], 1 */

L_004DE82D:
    PUSH32(esp, 1); /* 0x004DE82D: push 1 */
    PUSH32(esp, 0); /* 0x004DE82F: push 0 */
    PUSH32(esp, 3); /* 0x004DE831: push 3 */
    edx = ebp + (-0xC); /* 0x004DE833: lea edx, [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004DE836: push edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DE837: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004DE83A: push eax */
    ecx = ebp + (-0x8); /* 0x004DE83B: lea ecx, [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DE83E: push ecx */
    PUSH32(esp, 0x100u); /* 0x004DE83F: push 0x100 */
    edx = MEM32(0x84BCC0); /* 0x004DE844: mov edx, dword ptr [0x84bcc0] */
    PUSH32(esp, edx); /* 0x004DE84A: push edx */
    RECOMP_CALL(sub_004E14C0); /* 0x004DE84B: call 0x4e14c0 */
    esp = esp + 0x20u; /* 0x004DE850: add esp, 0x20 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DE853: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DE856: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004DE861; /* 0x004DE85A: jne 0x4de861 */

L_004DE85C:
    eax = MEM32(ebp + 0x8); /* 0x004DE85C: mov eax, dword ptr [ebp + 8] */
    goto L_004DE887; /* 0x004DE85F: jmp 0x4de887 */

L_004DE861:
    /* cmp MEM32(ebp + (-0x4)), 1 */ /* 0x004DE861: cmp dword ptr [ebp - 4], 1 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 1)) goto L_004DE871; /* 0x004DE865: jne 0x4de871 */

L_004DE867:
    eax = MEM32(ebp + (-0xC)); /* 0x004DE867: mov eax, dword ptr [ebp - 0xc] */
    eax = eax & 0xFFu; /* 0x004DE86A: and eax, 0xff */
    goto L_004DE887; /* 0x004DE86F: jmp 0x4de887 */

L_004DE871:
    eax = MEM32(ebp + (-0xC)); /* 0x004DE871: mov eax, dword ptr [ebp - 0xc] */
    eax = eax & 0xFFu; /* 0x004DE874: and eax, 0xff */
    ecx = MEM32(ebp + (-0xB)); /* 0x004DE879: mov ecx, dword ptr [ebp - 0xb] */
    ecx = ecx & 0xFFu; /* 0x004DE87C: and ecx, 0xff */
    ecx = ecx << 8; /* 0x004DE882: shl ecx, 8 */
    eax = eax | ecx; /* 0x004DE885: or eax, ecx */

L_004DE887:
    esp = ebp; /* 0x004DE887: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE889: pop ebp */
    return; /* 0x004DE88A: ret  */

}

void sub_004DE830(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE830:
    MEM8(edx + 0x3) = (uint8_t)(MEM8(edx + 0x3) + HI8(ecx)); /* 0x004DE830: add byte ptr [edx + 3], ch */
    edx = ebp + (-0xC); /* 0x004DE833: lea edx, [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004DE836: push edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004DE837: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004DE83A: push eax */
    ecx = ebp + (-0x8); /* 0x004DE83B: lea ecx, [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DE83E: push ecx */
    PUSH32(esp, 0x100u); /* 0x004DE83F: push 0x100 */
    edx = MEM32(0x84BCC0); /* 0x004DE844: mov edx, dword ptr [0x84bcc0] */
    PUSH32(esp, edx); /* 0x004DE84A: push edx */
    RECOMP_CALL(sub_004E14C0); /* 0x004DE84B: call 0x4e14c0 */
    esp = esp + 0x20u; /* 0x004DE850: add esp, 0x20 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DE853: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DE856: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004DE861; /* 0x004DE85A: jne 0x4de861 */

L_004DE85C:
    eax = MEM32(ebp + 0x8); /* 0x004DE85C: mov eax, dword ptr [ebp + 8] */
    goto L_004DE887; /* 0x004DE85F: jmp 0x4de887 */

L_004DE861:
    /* cmp MEM32(ebp + (-0x4)), 1 */ /* 0x004DE861: cmp dword ptr [ebp - 4], 1 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 1)) goto L_004DE871; /* 0x004DE865: jne 0x4de871 */

L_004DE867:
    eax = MEM32(ebp + (-0xC)); /* 0x004DE867: mov eax, dword ptr [ebp - 0xc] */
    eax = eax & 0xFFu; /* 0x004DE86A: and eax, 0xff */
    goto L_004DE887; /* 0x004DE86F: jmp 0x4de887 */

L_004DE871:
    eax = MEM32(ebp + (-0xC)); /* 0x004DE871: mov eax, dword ptr [ebp - 0xc] */
    eax = eax & 0xFFu; /* 0x004DE874: and eax, 0xff */
    ecx = MEM32(ebp + (-0xB)); /* 0x004DE879: mov ecx, dword ptr [ebp - 0xb] */
    ecx = ecx & 0xFFu; /* 0x004DE87C: and ecx, 0xff */
    ecx = ecx << 8; /* 0x004DE882: shl ecx, 8 */
    eax = eax | ecx; /* 0x004DE885: or eax, ecx */

L_004DE887:
    esp = ebp; /* 0x004DE887: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE889: pop ebp */
    return; /* 0x004DE88A: ret  */

}

void sub_004DE8A0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE8A0:
    _cf = 0; /* 0x004DE8A0: clc  */
    eax = eax + 0x8BF44589u; /* 0x004DE8A1: add eax, 0x8bf44589 */
    ebp = ebp + 1; /* 0x004DE8A6: inc ebp */
    SET_LO8(eax, LO8(eax) | 0x99u); /* 0x004DE8A7: or al, 0x99 */
    eax = eax ^ edx; /* 0x004DE8A9: xor eax, edx */
    eax = eax - edx; /* 0x004DE8AB: sub eax, edx */
    eax = eax & 0x1Fu; /* 0x004DE8AD: and eax, 0x1f */
    eax = eax ^ edx; /* 0x004DE8B0: xor eax, edx */
    eax = eax - edx; /* 0x004DE8B2: sub eax, edx */
    ecx = 0x1Fu; /* 0x004DE8B4: mov ecx, 0x1f */
    ecx = ecx - eax; /* 0x004DE8B9: sub ecx, eax */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DE8BB: mov dword ptr [ebp - 4], ecx */
    edx = edx | 0xFFFFFFFFu; /* 0x004DE8BE: or edx, 0xffffffff */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DE8C1: mov ecx, dword ptr [ebp - 4] */
    edx = edx << LO8(ecx); /* 0x004DE8C4: shl edx, cl */
    edx = ~edx; /* 0x004DE8C6: not edx */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DE8C8: mov dword ptr [ebp - 8], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004DE8CB: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(ebp + 0x8); /* 0x004DE8CE: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + eax * 4); /* 0x004DE8D1: mov edx, dword ptr [ecx + eax*4] */
    edx = edx & MEM32(ebp + (-0x8)); /* 0x004DE8D4: and edx, dword ptr [ebp - 8] */
    /* test edx, edx */ /* 0x004DE8D7: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DE8DF; /* 0x004DE8D9: je 0x4de8df */

L_004DE8DB:
    eax = 0; /* 0x004DE8DB: xor eax, eax */
    goto L_004DE910; /* 0x004DE8DD: jmp 0x4de910 */

L_004DE8DF:
    eax = MEM32(ebp + (-0xC)); /* 0x004DE8DF: mov eax, dword ptr [ebp - 0xc] */
    eax = eax + 1; /* 0x004DE8E2: add eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DE8E5: mov dword ptr [ebp - 0xc], eax */
    goto L_004DE8F3; /* 0x004DE8E8: jmp 0x4de8f3 */

L_004DE8EA:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DE8EA: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + 1; /* 0x004DE8ED: add ecx, 1 */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DE8F0: mov dword ptr [ebp - 0xc], ecx */

L_004DE8F3:
    /* cmp MEM32(ebp + (-0xC)), 3 */ /* 0x004DE8F3: cmp dword ptr [ebp - 0xc], 3 */
    if (CMP_GE(MEM32(ebp + (-0xC)), 3)) goto L_004DE90B; /* 0x004DE8F7: jge 0x4de90b */

L_004DE8F9:
    edx = MEM32(ebp + (-0xC)); /* 0x004DE8F9: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + 0x8); /* 0x004DE8FC: mov eax, dword ptr [ebp + 8] */
    /* cmp MEM32(eax + edx * 4), 0 */ /* 0x004DE8FF: cmp dword ptr [eax + edx*4], 0 */
    if (CMP_EQ(MEM32(eax + edx * 4), 0)) goto L_004DE909; /* 0x004DE903: je 0x4de909 */

L_004DE905:
    eax = 0; /* 0x004DE905: xor eax, eax */
    goto L_004DE910; /* 0x004DE907: jmp 0x4de910 */

L_004DE909:
    goto L_004DE8EA; /* 0x004DE909: jmp 0x4de8ea */

L_004DE90B:
    eax = 1; /* 0x004DE90B: mov eax, 1 */

L_004DE910:
    esp = ebp; /* 0x004DE910: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE912: pop ebp */
    return; /* 0x004DE913: ret  */

}

void sub_004DE920(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DE920:
    PUSH32(esp, ebp); /* 0x004DE920: push ebp */
    ebp = esp; /* 0x004DE921: mov ebp, esp */
    esp = esp - 0x10u; /* 0x004DE923: sub esp, 0x10 */
    eax = MEM32(ebp + 0xC); /* 0x004DE926: mov eax, dword ptr [ebp + 0xc] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004DE929: cdq  */
    edx = edx & 0x1Fu; /* 0x004DE92A: and edx, 0x1f */
    eax = eax + edx; /* 0x004DE92D: add eax, edx */
    eax = (uint32_t)((int32_t)eax >> 5); /* 0x004DE92F: sar eax, 5 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DE932: mov dword ptr [ebp - 0xc], eax */
    eax = MEM32(ebp + 0xC); /* 0x004DE935: mov eax, dword ptr [ebp + 0xc] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004DE938: cdq  */
    eax = eax ^ edx; /* 0x004DE939: xor eax, edx */
    eax = eax - edx; /* 0x004DE93B: sub eax, edx */
    eax = eax & 0x1Fu; /* 0x004DE93D: and eax, 0x1f */
    eax = eax ^ edx; /* 0x004DE940: xor eax, edx */
    eax = eax - edx; /* 0x004DE942: sub eax, edx */
    ecx = 0x1Fu; /* 0x004DE944: mov ecx, 0x1f */
    ecx = ecx - eax; /* 0x004DE949: sub ecx, eax */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DE94B: mov dword ptr [ebp - 4], ecx */
    edx = 1; /* 0x004DE94E: mov edx, 1 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DE953: mov ecx, dword ptr [ebp - 4] */
    edx = edx << LO8(ecx); /* 0x004DE956: shl edx, cl */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DE958: mov dword ptr [ebp - 8], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004DE95B: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(ebp + 0x8); /* 0x004DE95E: mov ecx, dword ptr [ebp + 8] */
    edx = ecx + eax * 4; /* 0x004DE961: lea edx, [ecx + eax*4] */
    PUSH32(esp, edx); /* 0x004DE964: push edx */
    eax = MEM32(ebp + (-0x8)); /* 0x004DE965: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004DE968: push eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DE969: mov ecx, dword ptr [ebp - 0xc] */
    edx = MEM32(ebp + 0x8); /* 0x004DE96C: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + ecx * 4); /* 0x004DE96F: mov eax, dword ptr [edx + ecx*4] */
    PUSH32(esp, eax); /* 0x004DE972: push eax */
    RECOMP_CALL(sub_004E2340); /* 0x004DE973: call 0x4e2340 */
    esp = esp + 0xCu; /* 0x004DE978: add esp, 0xc */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DE97B: mov dword ptr [ebp - 0x10], eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004DE97E: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx - 1; /* 0x004DE981: sub ecx, 1 */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DE984: mov dword ptr [ebp - 0xc], ecx */
    goto L_004DE992; /* 0x004DE987: jmp 0x4de992 */

L_004DE989:
    edx = MEM32(ebp + (-0xC)); /* 0x004DE989: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - 1; /* 0x004DE98C: sub edx, 1 */
    MEM32(ebp + (-0xC)) = edx; /* 0x004DE98F: mov dword ptr [ebp - 0xc], edx */

L_004DE992:
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004DE992: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_L(MEM32(ebp + (-0xC)), 0)) goto L_004DE9C1; /* 0x004DE996: jl 0x4de9c1 */

L_004DE998:
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004DE998: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x10)), 0)) goto L_004DE9C1; /* 0x004DE99C: je 0x4de9c1 */

L_004DE99E:
    eax = MEM32(ebp + (-0xC)); /* 0x004DE99E: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(ebp + 0x8); /* 0x004DE9A1: mov ecx, dword ptr [ebp + 8] */
    edx = ecx + eax * 4; /* 0x004DE9A4: lea edx, [ecx + eax*4] */
    PUSH32(esp, edx); /* 0x004DE9A7: push edx */
    PUSH32(esp, 1); /* 0x004DE9A8: push 1 */
    eax = MEM32(ebp + (-0xC)); /* 0x004DE9AA: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(ebp + 0x8); /* 0x004DE9AD: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + eax * 4); /* 0x004DE9B0: mov edx, dword ptr [ecx + eax*4] */
    PUSH32(esp, edx); /* 0x004DE9B3: push edx */
    RECOMP_CALL(sub_004E2340); /* 0x004DE9B4: call 0x4e2340 */
    esp = esp + 0xCu; /* 0x004DE9B9: add esp, 0xc */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DE9BC: mov dword ptr [ebp - 0x10], eax */
    goto L_004DE989; /* 0x004DE9BF: jmp 0x4de989 */

L_004DE9C1:
    eax = MEM32(ebp + (-0x10)); /* 0x004DE9C1: mov eax, dword ptr [ebp - 0x10] */
    esp = ebp; /* 0x004DE9C4: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DE9C6: pop ebp */
    return; /* 0x004DE9C7: ret  */

}

void sub_004DEA20(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DEA20:
    /* UNIMPLEMENTED: loopne 0x4de9ab */ /* 0x004DEA20: loopne 0x4de9ab */
    ebp = ebp + 1; /* 0x004DEA22: inc ebp */
    /* UNIMPLEMENTED: in al, 0x8b */ /* 0x004DEA23: in al, 0x8b */
    ebp = ebp - 1; /* 0x004DEA25: dec ebp */
    /* UNIMPLEMENTED: in al, dx */ /* 0x004DEA26: in al, dx */
    edx = MEM32(ebp + 0x8); /* 0x004DEA27: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + ecx * 4); /* 0x004DEA2A: mov eax, dword ptr [edx + ecx*4] */
    eax = eax & MEM32(ebp + (-0x1C)); /* 0x004DEA2D: and eax, dword ptr [ebp - 0x1c] */
    /* test eax, eax */ /* 0x004DEA30: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DEA5E; /* 0x004DEA32: je 0x4dea5e */

L_004DEA34:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DEA34: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + 1; /* 0x004DEA37: add ecx, 1 */
    PUSH32(esp, ecx); /* 0x004DEA3A: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004DEA3B: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004DEA3E: push edx */
    RECOMP_CALL(sub_004DE890); /* 0x004DEA3F: call 0x4de890 */
    esp = esp + 8; /* 0x004DEA44: add esp, 8 */
    /* test eax, eax */ /* 0x004DEA47: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004DEA5E; /* 0x004DEA49: jne 0x4dea5e */

L_004DEA4B:
    eax = MEM32(ebp + (-0x4)); /* 0x004DEA4B: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004DEA4E: push eax */
    ecx = MEM32(ebp + 0x8); /* 0x004DEA4F: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004DEA52: push ecx */
    RECOMP_CALL(sub_004DE920); /* 0x004DEA53: call 0x4de920 */
    esp = esp + 8; /* 0x004DEA58: add esp, 8 */
    MEM32(ebp + (-0x18)) = eax; /* 0x004DEA5B: mov dword ptr [ebp - 0x18], eax */

L_004DEA5E:
    edx = edx | 0xFFFFFFFFu; /* 0x004DEA5E: or edx, 0xffffffff */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DEA61: mov ecx, dword ptr [ebp - 8] */
    edx = edx << LO8(ecx); /* 0x004DEA64: shl edx, cl */
    eax = MEM32(ebp + (-0x14)); /* 0x004DEA66: mov eax, dword ptr [ebp - 0x14] */
    ecx = MEM32(ebp + 0x8); /* 0x004DEA69: mov ecx, dword ptr [ebp + 8] */
    eax = MEM32(ecx + eax * 4); /* 0x004DEA6C: mov eax, dword ptr [ecx + eax*4] */
    eax = eax & edx; /* 0x004DEA6F: and eax, edx */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DEA71: mov ecx, dword ptr [ebp - 0x14] */
    edx = MEM32(ebp + 0x8); /* 0x004DEA74: mov edx, dword ptr [ebp + 8] */
    MEM32(edx + ecx * 4) = eax; /* 0x004DEA77: mov dword ptr [edx + ecx*4], eax */
    eax = MEM32(ebp + (-0x14)); /* 0x004DEA7A: mov eax, dword ptr [ebp - 0x14] */
    eax = eax + 1; /* 0x004DEA7D: add eax, 1 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004DEA80: mov dword ptr [ebp - 0x10], eax */
    goto L_004DEA8E; /* 0x004DEA83: jmp 0x4dea8e */

L_004DEA85:
    ecx = MEM32(ebp + (-0x10)); /* 0x004DEA85: mov ecx, dword ptr [ebp - 0x10] */
    ecx = ecx + 1; /* 0x004DEA88: add ecx, 1 */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004DEA8B: mov dword ptr [ebp - 0x10], ecx */

L_004DEA8E:
    /* cmp MEM32(ebp + (-0x10)), 3 */ /* 0x004DEA8E: cmp dword ptr [ebp - 0x10], 3 */
    if (CMP_GE(MEM32(ebp + (-0x10)), 3)) goto L_004DEAA3; /* 0x004DEA92: jge 0x4deaa3 */

L_004DEA94:
    edx = MEM32(ebp + (-0x10)); /* 0x004DEA94: mov edx, dword ptr [ebp - 0x10] */
    eax = MEM32(ebp + 0x8); /* 0x004DEA97: mov eax, dword ptr [ebp + 8] */
    MEM32(eax + edx * 4) = 0; /* 0x004DEA9A: mov dword ptr [eax + edx*4], 0 */
    goto L_004DEA85; /* 0x004DEAA1: jmp 0x4dea85 */

L_004DEAA3:
    eax = MEM32(ebp + (-0x18)); /* 0x004DEAA3: mov eax, dword ptr [ebp - 0x18] */
    esp = ebp; /* 0x004DEAA6: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DEAA8: pop ebp */
    return; /* 0x004DEAA9: ret  */

}

void sub_004DEB20(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DEB0D:
    eax = MEM32(ebp + (-0x4)); /* 0x004DEB0D: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DEB10: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DEB13: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 3 */ /* 0x004DEB16: cmp dword ptr [ebp - 4], 3 */
    if (CMP_GE(MEM32(ebp + (-0x4)), 3)) goto L_004DEB2B; /* 0x004DEB1A: jge 0x4deb2b */

L_004DEB1C:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DEB1C: mov ecx, dword ptr [ebp - 4] */
    edx = MEM32(ebp + 0x8); /* 0x004DEB1F: mov edx, dword ptr [ebp + 8] */
    MEM32(edx + ecx * 4) = 0; /* 0x004DEB22: mov dword ptr [edx + ecx*4], 0 */
    goto L_004DEB0D; /* 0x004DEB29: jmp 0x4deb0d */

L_004DEB20:
    PUSH32(esp, ebp); /* 0x004DEB20: push ebp */
    SET_HI8(ebx, HI8(ebx) | LO8(eax)); /* 0x004DEB21: or bh, al */
    SET_LO8(eax, LO8(eax) + 0x8Au); /* 0x004DEB23: add al, 0x8a */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DEB25: add byte ptr [eax], al */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DEB27: add byte ptr [eax], al */
    goto L_004DEB0D; /* 0x004DEB29: jmp 0x4deb0d */

L_004DEB2B:
    esp = ebp; /* 0x004DEB2B: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DEB2D: pop ebp */
    return; /* 0x004DEB2E: ret  */

}

void sub_004DEB50(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DEB3D:
    eax = MEM32(ebp + (-0x4)); /* 0x004DEB3D: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004DEB40: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DEB43: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 3 */ /* 0x004DEB46: cmp dword ptr [ebp - 4], 3 */
    if (CMP_GE(MEM32(ebp + (-0x4)), 3)) goto L_004DEB5E; /* 0x004DEB4A: jge 0x4deb5e */

L_004DEB4C:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DEB4C: mov ecx, dword ptr [ebp - 4] */
    edx = MEM32(ebp + 0x8); /* 0x004DEB4F: mov edx, dword ptr [ebp + 8] */
    /* cmp MEM32(edx + ecx * 4), 0 */ /* 0x004DEB52: cmp dword ptr [edx + ecx*4], 0 */
    if (CMP_EQ(MEM32(edx + ecx * 4), 0)) goto L_004DEB5C; /* 0x004DEB56: je 0x4deb5c */

L_004DEB50:
    PUSH32(esp, ebp); /* 0x004DEB50: push ebp */
    MEM8(ebx + 0x74008A3C) = (uint8_t)(MEM8(ebx + 0x74008A3C) | LO8(eax)); /* 0x004DEB51: or byte ptr [ebx + 0x74008a3c], al */
    SET_LO8(eax, LO8(eax) + 0x33u); /* 0x004DEB57: add al, 0x33 */
    SET_LO8(ebx, LO8(ebx) >> 7); /* 0x004DEB59: shr bl, 7 */

L_004DEB58:
    eax = 0; /* 0x004DEB58: xor eax, eax */
    goto L_004DEB63; /* 0x004DEB5A: jmp 0x4deb63 */

L_004DEB5C:
    goto L_004DEB3D; /* 0x004DEB5C: jmp 0x4deb3d */

L_004DEB5E:
    eax = 1; /* 0x004DEB5E: mov eax, 1 */

L_004DEB63:
    esp = ebp; /* 0x004DEB63: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DEB65: pop ebp */
    return; /* 0x004DEB66: ret  */

}

void sub_004DEB80(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DEB80:
    eax = (uint32_t)((int32_t)eax >> 5); /* 0x004DEB80: sar eax, 5 */
    MEM32(ebp + (-0x18)) = eax; /* 0x004DEB83: mov dword ptr [ebp - 0x18], eax */
    eax = MEM32(ebp + 0xC); /* 0x004DEB86: mov eax, dword ptr [ebp + 0xc] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004DEB89: cdq  */
    eax = eax ^ edx; /* 0x004DEB8A: xor eax, edx */
    eax = eax - edx; /* 0x004DEB8C: sub eax, edx */
    eax = eax & 0x1Fu; /* 0x004DEB8E: and eax, 0x1f */
    eax = eax ^ edx; /* 0x004DEB91: xor eax, edx */
    eax = eax - edx; /* 0x004DEB93: sub eax, edx */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DEB95: mov dword ptr [ebp - 4], eax */
    eax = eax | 0xFFFFFFFFu; /* 0x004DEB98: or eax, 0xffffffff */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DEB9B: mov ecx, dword ptr [ebp - 4] */
    eax = eax << LO8(ecx); /* 0x004DEB9E: shl eax, cl */
    eax = ~eax; /* 0x004DEBA0: not eax */
    MEM32(ebp + (-0x14)) = eax; /* 0x004DEBA2: mov dword ptr [ebp - 0x14], eax */
    MEM32(ebp + (-0x8)) = 0; /* 0x004DEBA5: mov dword ptr [ebp - 8], 0 */
    MEM32(ebp + (-0xC)) = 0; /* 0x004DEBAC: mov dword ptr [ebp - 0xc], 0 */
    goto L_004DEBBE; /* 0x004DEBB3: jmp 0x4debbe */

L_004DEBB5:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DEBB5: mov ecx, dword ptr [ebp - 0xc] */
    ecx = ecx + 1; /* 0x004DEBB8: add ecx, 1 */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004DEBBB: mov dword ptr [ebp - 0xc], ecx */

L_004DEBBE:
    /* cmp MEM32(ebp + (-0xC)), 3 */ /* 0x004DEBBE: cmp dword ptr [ebp - 0xc], 3 */
    if (CMP_GE(MEM32(ebp + (-0xC)), 3)) goto L_004DEC11; /* 0x004DEBC2: jge 0x4dec11 */

L_004DEBC4:
    edx = MEM32(ebp + (-0xC)); /* 0x004DEBC4: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + 0x8); /* 0x004DEBC7: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + edx * 4); /* 0x004DEBCA: mov ecx, dword ptr [eax + edx*4] */
    ecx = ecx & MEM32(ebp + (-0x14)); /* 0x004DEBCD: and ecx, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004DEBD0: mov dword ptr [ebp - 0x10], ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004DEBD3: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + 0x8); /* 0x004DEBD6: mov eax, dword ptr [ebp + 8] */
    edx = MEM32(eax + edx * 4); /* 0x004DEBD9: mov edx, dword ptr [eax + edx*4] */
    ecx = MEM32(ebp + (-0x4)); /* 0x004DEBDC: mov ecx, dword ptr [ebp - 4] */
    edx = edx >> LO8(ecx); /* 0x004DEBDF: shr edx, cl */
    eax = MEM32(ebp + (-0xC)); /* 0x004DEBE1: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(ebp + 0x8); /* 0x004DEBE4: mov ecx, dword ptr [ebp + 8] */
    MEM32(ecx + eax * 4) = edx; /* 0x004DEBE7: mov dword ptr [ecx + eax*4], edx */
    edx = MEM32(ebp + (-0xC)); /* 0x004DEBEA: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + 0x8); /* 0x004DEBED: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + edx * 4); /* 0x004DEBF0: mov ecx, dword ptr [eax + edx*4] */
    ecx = ecx | MEM32(ebp + (-0x8)); /* 0x004DEBF3: or ecx, dword ptr [ebp - 8] */
    edx = MEM32(ebp + (-0xC)); /* 0x004DEBF6: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + 0x8); /* 0x004DEBF9: mov eax, dword ptr [ebp + 8] */
    MEM32(eax + edx * 4) = ecx; /* 0x004DEBFC: mov dword ptr [eax + edx*4], ecx */
    ecx = 0x20u; /* 0x004DEBFF: mov ecx, 0x20 */
    ecx = ecx - MEM32(ebp + (-0x4)); /* 0x004DEC04: sub ecx, dword ptr [ebp - 4] */
    edx = MEM32(ebp + (-0x10)); /* 0x004DEC07: mov edx, dword ptr [ebp - 0x10] */
    edx = edx << LO8(ecx); /* 0x004DEC0A: shl edx, cl */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DEC0C: mov dword ptr [ebp - 8], edx */
    goto L_004DEBB5; /* 0x004DEC0F: jmp 0x4debb5 */

L_004DEC11:
    MEM32(ebp + (-0xC)) = 2; /* 0x004DEC11: mov dword ptr [ebp - 0xc], 2 */
    goto L_004DEC23; /* 0x004DEC18: jmp 0x4dec23 */

L_004DEC1A:
    eax = MEM32(ebp + (-0xC)); /* 0x004DEC1A: mov eax, dword ptr [ebp - 0xc] */
    eax = eax - 1; /* 0x004DEC1D: sub eax, 1 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004DEC20: mov dword ptr [ebp - 0xc], eax */

L_004DEC23:
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004DEC23: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_L(MEM32(ebp + (-0xC)), 0)) goto L_004DEC57; /* 0x004DEC27: jl 0x4dec57 */

L_004DEC29:
    ecx = MEM32(ebp + (-0xC)); /* 0x004DEC29: mov ecx, dword ptr [ebp - 0xc] */
    /* cmp ecx, MEM32(ebp + (-0x18)) */ /* 0x004DEC2C: cmp ecx, dword ptr [ebp - 0x18] */
    if (CMP_L(ecx, MEM32(ebp + (-0x18)))) goto L_004DEC48; /* 0x004DEC2F: jl 0x4dec48 */

L_004DEC31:
    edx = MEM32(ebp + (-0xC)); /* 0x004DEC31: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - MEM32(ebp + (-0x18)); /* 0x004DEC34: sub edx, dword ptr [ebp - 0x18] */
    eax = MEM32(ebp + (-0xC)); /* 0x004DEC37: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(ebp + 0x8); /* 0x004DEC3A: mov ecx, dword ptr [ebp + 8] */
    esi = MEM32(ebp + 0x8); /* 0x004DEC3D: mov esi, dword ptr [ebp + 8] */
    edx = MEM32(esi + edx * 4); /* 0x004DEC40: mov edx, dword ptr [esi + edx*4] */
    MEM32(ecx + eax * 4) = edx; /* 0x004DEC43: mov dword ptr [ecx + eax*4], edx */
    goto L_004DEC55; /* 0x004DEC46: jmp 0x4dec55 */

L_004DEC48:
    eax = MEM32(ebp + (-0xC)); /* 0x004DEC48: mov eax, dword ptr [ebp - 0xc] */
    ecx = MEM32(ebp + 0x8); /* 0x004DEC4B: mov ecx, dword ptr [ebp + 8] */
    MEM32(ecx + eax * 4) = 0; /* 0x004DEC4E: mov dword ptr [ecx + eax*4], 0 */

L_004DEC55:
    goto L_004DEC1A; /* 0x004DEC55: jmp 0x4dec1a */

L_004DEC57:
    esi = POP32_VAL(esp); /* 0x004DEC57: pop esi */
    esp = ebp; /* 0x004DEC58: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DEC5A: pop ebp */
    return; /* 0x004DEC5B: ret  */

}

void sub_004DEEB0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DEEB0:
    PUSH32(esp, ebp); /* 0x004DEEB0: push ebp */
    ebp = esp; /* 0x004DEEB1: mov ebp, esp */
    PUSH32(esp, 0x0050B890u); /* 0x004DEEB3: push 0x50b890 */
    eax = MEM32(ebp + 0xC); /* 0x004DEEB8: mov eax, dword ptr [ebp + 0xc] */
    PUSH32(esp, eax); /* 0x004DEEBB: push eax */
    ecx = MEM32(ebp + 0x8); /* 0x004DEEBC: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004DEEBF: push ecx */
    RECOMP_CALL(sub_004DEC60); /* 0x004DEEC0: call 0x4dec60 */
    esp = esp + 0xCu; /* 0x004DEEC5: add esp, 0xc */
    ebp = POP32_VAL(esp); /* 0x004DEEC8: pop ebp */
    return; /* 0x004DEEC9: ret  */

}

void sub_004DF1B0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF1B0:
    MEM8(edi) = (uint8_t)(MEM8(edi) + LO8(ecx)); /* 0x004DF1B0: add byte ptr [edi], cl */
    edi = 0x84BBB815u; /* 0x004DF1B2: mov edi, 0x84bbb815 */
    MEM8(ecx + (-0x7B4423EB)) = (uint8_t)(MEM8(ecx + (-0x7B4423EB)) + LO8(ecx)); /* 0x004DF1B7: add byte ptr [ecx - 0x7b4423eb], cl */
    SET_HI8(ebx, HI8(ebx) + LO8(eax)); /* 0x004DF1BD: add bh, al */
    eax = eax + 0x0084BBE4u; /* 0x004DF1BF: add eax, 0x84bbe4 */
    esp = 0xB80084BBu; /* 0x004DF1C4: mov esp, 0xb80084bb */
    _st[0] = (double)*(float*)ADDR(ebx + (-0x1A74FF7C)) / _st[0]; /* 0x004DF1C9: fdivr dword ptr [ebx - 0x1a74ff7c] */
    ebp = POP32_VAL(esp); /* 0x004DF1CF: pop ebp */
    return; /* 0x004DF1D0: ret  */

}

void sub_004DF3B0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

}

void sub_004DF3F0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF3F0:
    PUSH32(esp, edx); /* 0x004DF3F0: push edx */
    PUSH32(esp, 1); /* 0x004DF3F1: push 1 */
    eax = ebp + 0xC; /* 0x004DF3F3: lea eax, [ebp + 0xc] */
    PUSH32(esp, eax); /* 0x004DF3F6: push eax */
    PUSH32(esp, 0x220u); /* 0x004DF3F7: push 0x220 */
    ecx = MEM32(0x84BCD0); /* 0x004DF3FC: mov ecx, dword ptr [0x84bcd0] */
    PUSH32(esp, ecx); /* 0x004DF402: push ecx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004DF403: call dword ptr [0x8586e0] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004DF409: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DF40C: cmp dword ptr [ebp - 4], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0)) goto L_004DF418; /* 0x004DF410: je 0x4df418 */

L_004DF412:
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004DF412: cmp dword ptr [ebp - 8], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x8)), 0)) goto L_004DF427; /* 0x004DF416: je 0x4df427 */

L_004DF418:
    MEM32(0x84B7AC) = 0x2Au; /* 0x004DF418: mov dword ptr [0x84b7ac], 0x2a */
    eax = eax | 0xFFFFFFFFu; /* 0x004DF422: or eax, 0xffffffff */
    goto L_004DF42A; /* 0x004DF425: jmp 0x4df42a */

L_004DF427:
    eax = MEM32(ebp + (-0x4)); /* 0x004DF427: mov eax, dword ptr [ebp - 4] */

L_004DF42A:
    esp = ebp; /* 0x004DF42A: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DF42C: pop ebp */
    return; /* 0x004DF42D: ret  */

}

void sub_004DF5AC(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF5AC:
    SET_LO8(eax, LO8(eax) + 0x8Bu); /* 0x004DF5AC: add al, 0x8b */
    PUSH32(esp, ebp); /* 0x004DF5AE: push ebp */
    /* UNIMPLEMENTED: aam 0x52 */ /* 0x004DF5AF: aam 0x52 */
    eax = MEM32(ebp + 0x10); /* 0x004DF5B1: mov eax, dword ptr [ebp + 0x10] */
    PUSH32(esp, eax); /* 0x004DF5B4: push eax */
    ecx = MEM32(ebp + (-0x24)); /* 0x004DF5B5: mov ecx, dword ptr [ebp - 0x24] */
    PUSH32(esp, ecx); /* 0x004DF5B8: push ecx */
    RECOMP_CALL(sub_004D6D90); /* 0x004DF5B9: call 0x4d6d90 */
    esp = esp + 0xCu; /* 0x004DF5BE: add esp, 0xc */
    MEM32(ebp + (-0x28)) = eax; /* 0x004DF5C1: mov dword ptr [ebp - 0x28], eax */
    edx = MEM32(ebp + (-0x24)); /* 0x004DF5C4: mov edx, dword ptr [ebp - 0x24] */
    eax = MEM32(edx + 0x4); /* 0x004DF5C7: mov eax, dword ptr [edx + 4] */
    eax = eax - 1; /* 0x004DF5CA: sub eax, 1 */
    ecx = MEM32(ebp + (-0x24)); /* 0x004DF5CD: mov ecx, dword ptr [ebp - 0x24] */
    MEM32(ecx + 0x4) = eax; /* 0x004DF5D0: mov dword ptr [ecx + 4], eax */
    edx = MEM32(ebp + (-0x24)); /* 0x004DF5D3: mov edx, dword ptr [ebp - 0x24] */
    /* cmp MEM32(edx + 0x4), 0 */ /* 0x004DF5D6: cmp dword ptr [edx + 4], 0 */
    if (CMP_L(MEM32(edx + 0x4), 0)) goto L_004DF5FE; /* 0x004DF5DA: jl 0x4df5fe */

L_004DF5DC:
    eax = MEM32(ebp + (-0x24)); /* 0x004DF5DC: mov eax, dword ptr [ebp - 0x24] */
    ecx = MEM32(eax); /* 0x004DF5DF: mov ecx, dword ptr [eax] */
    MEM8(ecx) = (uint8_t)(0); /* 0x004DF5E1: mov byte ptr [ecx], 0 */
    edx = 0; /* 0x004DF5E4: xor edx, edx */
    edx = edx & 0xFFu; /* 0x004DF5E6: and edx, 0xff */
    MEM32(ebp + (-0x30)) = edx; /* 0x004DF5EC: mov dword ptr [ebp - 0x30], edx */
    eax = MEM32(ebp + (-0x24)); /* 0x004DF5EF: mov eax, dword ptr [ebp - 0x24] */
    ecx = MEM32(eax); /* 0x004DF5F2: mov ecx, dword ptr [eax] */
    ecx = ecx + 1; /* 0x004DF5F4: add ecx, 1 */
    edx = MEM32(ebp + (-0x24)); /* 0x004DF5F7: mov edx, dword ptr [ebp - 0x24] */
    MEM32(edx) = ecx; /* 0x004DF5FA: mov dword ptr [edx], ecx */
    goto L_004DF60F; /* 0x004DF5FC: jmp 0x4df60f */

L_004DF5FE:
    eax = MEM32(ebp + (-0x24)); /* 0x004DF5FE: mov eax, dword ptr [ebp - 0x24] */
    PUSH32(esp, eax); /* 0x004DF601: push eax */
    PUSH32(esp, 0); /* 0x004DF602: push 0 */
    RECOMP_CALL(sub_004D6B10); /* 0x004DF604: call 0x4d6b10 */
    esp = esp + 8; /* 0x004DF609: add esp, 8 */
    MEM32(ebp + (-0x30)) = eax; /* 0x004DF60C: mov dword ptr [ebp - 0x30], eax */

L_004DF60F:
    eax = MEM32(ebp + (-0x28)); /* 0x004DF60F: mov eax, dword ptr [ebp - 0x28] */
    edi = POP32_VAL(esp); /* 0x004DF612: pop edi */
    esi = POP32_VAL(esp); /* 0x004DF613: pop esi */
    ebx = POP32_VAL(esp); /* 0x004DF614: pop ebx */
    esp = ebp; /* 0x004DF615: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DF617: pop ebp */
    return; /* 0x004DF618: ret  */

}

void sub_004DF7B0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF7B0:
    RECOMP_CALL(sub_004D51B0); /* 0x004DF7B0: call 0x4d51b0 */
    esp = esp + 4; /* 0x004DF7B5: add esp, 4 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DF7B8: mov dword ptr [ebp - 8], eax */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004DF7BB: cmp dword ptr [ebp - 8], 0 */
    if (CMP_NE(MEM32(ebp + (-0x8)), 0)) goto L_004DF8A2; /* 0x004DF7BF: jne 0x4df8a2 */

L_004DF7C5:
    PUSH32(esp, 0x0084BBF0u); /* 0x004DF7C5: push 0x84bbf0 */
    RECOMP_ICALL(MEM32(0x858710)); /* 0x004DF7CA: call dword ptr [0x858710] */
    /* cmp eax, 0xFFFFFFFFu */ /* 0x004DF7D0: cmp eax, -1 */
    if (CMP_EQ(eax, 0xFFFFFFFFu)) goto L_004DF89D; /* 0x004DF7D3: je 0x4df89d */

L_004DF7D9:
    MEM32(0x84BBE8) = 1; /* 0x004DF7D9: mov dword ptr [0x84bbe8], 1 */
    ecx = MEM32(0x84BBF0); /* 0x004DF7E3: mov ecx, dword ptr [0x84bbf0] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004DF7E9: imul ecx, ecx, 0x3c */
    MEM32(0x50B8C0) = ecx; /* 0x004DF7EC: mov dword ptr [0x50b8c0], ecx */
    edx = 0; /* 0x004DF7F2: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC36)); /* 0x004DF7F4: mov dx, word ptr [0x84bc36] */
    /* test edx, edx */ /* 0x004DF7FB: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DF815; /* 0x004DF7FD: je 0x4df815 */

L_004DF7FF:
    eax = MEM32(0x84BC44); /* 0x004DF7FF: mov eax, dword ptr [0x84bc44] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3Cu); /* 0x004DF804: imul eax, eax, 0x3c */
    ecx = MEM32(0x50B8C0); /* 0x004DF807: mov ecx, dword ptr [0x50b8c0] */
    ecx = ecx + eax; /* 0x004DF80D: add ecx, eax */
    MEM32(0x50B8C0) = ecx; /* 0x004DF80F: mov dword ptr [0x50b8c0], ecx */

L_004DF815:
    edx = 0; /* 0x004DF815: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC8A)); /* 0x004DF817: mov dx, word ptr [0x84bc8a] */
    /* test edx, edx */ /* 0x004DF81E: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DF84A; /* 0x004DF820: je 0x4df84a */

L_004DF822:
    /* cmp MEM32(0x84BC98), 0 */ /* 0x004DF822: cmp dword ptr [0x84bc98], 0 */
    if (CMP_EQ(MEM32(0x84BC98), 0)) goto L_004DF84A; /* 0x004DF829: je 0x4df84a */

L_004DF82B:
    MEM32(0x50B8C4) = 1; /* 0x004DF82B: mov dword ptr [0x50b8c4], 1 */
    eax = MEM32(0x84BC98); /* 0x004DF835: mov eax, dword ptr [0x84bc98] */
    eax = eax - MEM32(0x84BC44); /* 0x004DF83A: sub eax, dword ptr [0x84bc44] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3Cu); /* 0x004DF840: imul eax, eax, 0x3c */
    MEM32(0x50B8C8) = eax; /* 0x004DF843: mov dword ptr [0x50b8c8], eax */
    goto L_004DF85E; /* 0x004DF848: jmp 0x4df85e */

L_004DF84A:
    MEM32(0x50B8C4) = 0; /* 0x004DF84A: mov dword ptr [0x50b8c4], 0 */
    MEM32(0x50B8C8) = 0; /* 0x004DF854: mov dword ptr [0x50b8c8], 0 */

L_004DF85E:
    PUSH32(esp, 0x40u); /* 0x004DF85E: push 0x40 */
    PUSH32(esp, 0x0084BBF4u); /* 0x004DF860: push 0x84bbf4 */
    ecx = MEM32(0x50B950); /* 0x004DF865: mov ecx, dword ptr [0x50b950] */
    PUSH32(esp, ecx); /* 0x004DF86B: push ecx */
    RECOMP_CALL(sub_004E3940); /* 0x004DF86C: call 0x4e3940 */
    esp = esp + 0xCu; /* 0x004DF871: add esp, 0xc */
    PUSH32(esp, 0x40u); /* 0x004DF874: push 0x40 */
    PUSH32(esp, 0x0084BC48u); /* 0x004DF876: push 0x84bc48 */
    edx = MEM32(0x50B954); /* 0x004DF87B: mov edx, dword ptr [0x50b954] */
    PUSH32(esp, edx); /* 0x004DF881: push edx */
    RECOMP_CALL(sub_004E3940); /* 0x004DF882: call 0x4e3940 */
    esp = esp + 0xCu; /* 0x004DF887: add esp, 0xc */
    eax = MEM32(0x50B954); /* 0x004DF88A: mov eax, dword ptr [0x50b954] */
    MEM8(eax + 0x3F) = (uint8_t)(0); /* 0x004DF88F: mov byte ptr [eax + 0x3f], 0 */
    ecx = MEM32(0x50B950); /* 0x004DF893: mov ecx, dword ptr [0x50b950] */
    MEM8(ecx + 0x3F) = (uint8_t)(0); /* 0x004DF899: mov byte ptr [ecx + 0x3f], 0 */

L_004DF89D:
    goto L_004DFAA8; /* 0x004DF89D: jmp 0x4dfaa8 */

L_004DF8A2:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF8A2: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF8A5: movsx eax, byte ptr [edx] */
    /* test eax, eax */ /* 0x004DF8A8: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004DF8CC; /* 0x004DF8AA: je 0x4df8cc */

L_004DF8AC:
    /* cmp MEM32(0x84BC9C), 0 */ /* 0x004DF8AC: cmp dword ptr [0x84bc9c], 0 */
    if (CMP_EQ(MEM32(0x84BC9C), 0)) goto L_004DF8D1; /* 0x004DF8B3: je 0x4df8d1 */

L_004DF8B5:
    ecx = MEM32(0x84BC9C); /* 0x004DF8B5: mov ecx, dword ptr [0x84bc9c] */
    PUSH32(esp, ecx); /* 0x004DF8BB: push ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DF8BC: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DF8BF: push edx */
    RECOMP_CALL(sub_004DE560); /* 0x004DF8C0: call 0x4de560 */
    esp = esp + 8; /* 0x004DF8C5: add esp, 8 */
    /* test eax, eax */ /* 0x004DF8C8: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004DF8D1; /* 0x004DF8CA: jne 0x4df8d1 */

L_004DF8CC:
    goto L_004DFAA8; /* 0x004DF8CC: jmp 0x4dfaa8 */

L_004DF8D1:
    PUSH32(esp, 2); /* 0x004DF8D1: push 2 */
    eax = MEM32(0x84BC9C); /* 0x004DF8D3: mov eax, dword ptr [0x84bc9c] */
    PUSH32(esp, eax); /* 0x004DF8D8: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004DF8D9: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004DF8DE: add esp, 8 */
    PUSH32(esp, 0xECu); /* 0x004DF8E1: push 0xec */
    PUSH32(esp, 0x004F46E0u); /* 0x004DF8E6: push 0x4f46e0 */
    PUSH32(esp, 2); /* 0x004DF8EB: push 2 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF8ED: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DF8F0: push ecx */
    RECOMP_CALL(sub_004D5870); /* 0x004DF8F1: call 0x4d5870 */
    esp = esp + 4; /* 0x004DF8F6: add esp, 4 */
    eax = eax + 1; /* 0x004DF8F9: add eax, 1 */
    PUSH32(esp, eax); /* 0x004DF8FC: push eax */
    RECOMP_CALL(sub_004D25A0); /* 0x004DF8FD: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DF902: add esp, 0x10 */
    MEM32(0x84BC9C) = eax; /* 0x004DF905: mov dword ptr [0x84bc9c], eax */
    /* cmp MEM32(0x84BC9C), 0 */ /* 0x004DF90A: cmp dword ptr [0x84bc9c], 0 */
    if (CMP_NE(MEM32(0x84BC9C), 0)) goto L_004DF918; /* 0x004DF911: jne 0x4df918 */

L_004DF913:
    goto L_004DFAA8; /* 0x004DF913: jmp 0x4dfaa8 */

L_004DF918:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF918: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DF91B: push edx */
    eax = MEM32(0x84BC9C); /* 0x004DF91C: mov eax, dword ptr [0x84bc9c] */
    PUSH32(esp, eax); /* 0x004DF921: push eax */
    RECOMP_CALL(sub_004DC810); /* 0x004DF922: call 0x4dc810 */
    esp = esp + 8; /* 0x004DF927: add esp, 8 */
    PUSH32(esp, 3); /* 0x004DF92A: push 3 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF92C: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DF92F: push ecx */
    edx = MEM32(0x50B950); /* 0x004DF930: mov edx, dword ptr [0x50b950] */
    PUSH32(esp, edx); /* 0x004DF936: push edx */
    RECOMP_CALL(sub_004D1B70); /* 0x004DF937: call 0x4d1b70 */
    esp = esp + 0xCu; /* 0x004DF93C: add esp, 0xc */
    eax = MEM32(0x50B950); /* 0x004DF93F: mov eax, dword ptr [0x50b950] */
    MEM8(eax + 0x3) = (uint8_t)(0); /* 0x004DF944: mov byte ptr [eax + 3], 0 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF948: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 3; /* 0x004DF94B: add ecx, 3 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DF94E: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DF951: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF954: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x2Du */ /* 0x004DF957: cmp eax, 0x2d */
    if (CMP_NE(eax, 0x2Du)) goto L_004DF96E; /* 0x004DF95A: jne 0x4df96e */

L_004DF95C:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DF95C: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DF95F: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DF962: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DF965: mov edx, dword ptr [ebp - 8] */
    edx = edx + 1; /* 0x004DF968: add edx, 1 */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DF96B: mov dword ptr [ebp - 8], edx */

L_004DF96E:
    eax = MEM32(ebp + (-0x8)); /* 0x004DF96E: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004DF971: push eax */
    RECOMP_CALL(sub_004E36F0); /* 0x004DF972: call 0x4e36f0 */
    esp = esp + 4; /* 0x004DF977: add esp, 4 */
    eax = (uint32_t)((int32_t)eax * (int32_t)0xE10u); /* 0x004DF97A: imul eax, eax, 0xe10 */
    MEM32(0x50B8C0) = eax; /* 0x004DF980: mov dword ptr [0x50b8c0], eax */

L_004DF985:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF985: mov ecx, dword ptr [ebp - 8] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DF988: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x2Bu */ /* 0x004DF98B: cmp edx, 0x2b */
    if (CMP_EQ(edx, 0x2Bu)) goto L_004DF9A6; /* 0x004DF98E: je 0x4df9a6 */

L_004DF990:
    eax = MEM32(ebp + (-0x8)); /* 0x004DF990: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DF993: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x30u */ /* 0x004DF996: cmp ecx, 0x30 */
    if (CMP_L(ecx, 0x30u)) goto L_004DF9B1; /* 0x004DF999: jl 0x4df9b1 */

L_004DF99B:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF99B: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF99E: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x39u */ /* 0x004DF9A1: cmp eax, 0x39 */
    if (CMP_G(eax, 0x39u)) goto L_004DF9B1; /* 0x004DF9A4: jg 0x4df9b1 */

L_004DF9A6:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF9A6: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DF9A9: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DF9AC: mov dword ptr [ebp - 8], ecx */
    goto L_004DF985; /* 0x004DF9AF: jmp 0x4df985 */

L_004DF9B1:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF9B1: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF9B4: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x3Au */ /* 0x004DF9B7: cmp eax, 0x3a */
    if (CMP_NE(eax, 0x3Au)) goto L_004DFA56; /* 0x004DF9BA: jne 0x4dfa56 */

L_004DF9C0:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF9C0: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DF9C3: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DF9C6: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DF9C9: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DF9CC: push edx */
    RECOMP_CALL(sub_004E36F0); /* 0x004DF9CD: call 0x4e36f0 */
    esp = esp + 4; /* 0x004DF9D2: add esp, 4 */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3Cu); /* 0x004DF9D5: imul eax, eax, 0x3c */
    ecx = MEM32(0x50B8C0); /* 0x004DF9D8: mov ecx, dword ptr [0x50b8c0] */
    ecx = ecx + eax; /* 0x004DF9DE: add ecx, eax */
    MEM32(0x50B8C0) = ecx; /* 0x004DF9E0: mov dword ptr [0x50b8c0], ecx */

L_004DF9E6:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF9E6: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF9E9: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x30u */ /* 0x004DF9EC: cmp eax, 0x30 */
    if (CMP_L(eax, 0x30u)) goto L_004DFA07; /* 0x004DF9EF: jl 0x4dfa07 */

L_004DF9F1:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF9F1: mov ecx, dword ptr [ebp - 8] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DF9F4: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x39u */ /* 0x004DF9F7: cmp edx, 0x39 */
    if (CMP_G(edx, 0x39u)) goto L_004DFA07; /* 0x004DF9FA: jg 0x4dfa07 */

L_004DF9FC:
    eax = MEM32(ebp + (-0x8)); /* 0x004DF9FC: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DF9FF: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DFA02: mov dword ptr [ebp - 8], eax */
    goto L_004DF9E6; /* 0x004DFA05: jmp 0x4df9e6 */

L_004DFA07:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA07: mov ecx, dword ptr [ebp - 8] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DFA0A: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x3Au */ /* 0x004DFA0D: cmp edx, 0x3a */
    if (CMP_NE(edx, 0x3Au)) goto L_004DFA56; /* 0x004DFA10: jne 0x4dfa56 */

L_004DFA12:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA12: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DFA15: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DFA18: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA1B: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DFA1E: push ecx */
    RECOMP_CALL(sub_004E36F0); /* 0x004DFA1F: call 0x4e36f0 */
    esp = esp + 4; /* 0x004DFA24: add esp, 4 */
    edx = MEM32(0x50B8C0); /* 0x004DFA27: mov edx, dword ptr [0x50b8c0] */
    edx = edx + eax; /* 0x004DFA2D: add edx, eax */
    MEM32(0x50B8C0) = edx; /* 0x004DFA2F: mov dword ptr [0x50b8c0], edx */

L_004DFA35:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA35: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DFA38: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x30u */ /* 0x004DFA3B: cmp ecx, 0x30 */
    if (CMP_L(ecx, 0x30u)) goto L_004DFA56; /* 0x004DFA3E: jl 0x4dfa56 */

L_004DFA40:
    edx = MEM32(ebp + (-0x8)); /* 0x004DFA40: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DFA43: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x39u */ /* 0x004DFA46: cmp eax, 0x39 */
    if (CMP_G(eax, 0x39u)) goto L_004DFA56; /* 0x004DFA49: jg 0x4dfa56 */

L_004DFA4B:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA4B: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DFA4E: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DFA51: mov dword ptr [ebp - 8], ecx */
    goto L_004DFA35; /* 0x004DFA54: jmp 0x4dfa35 */

L_004DFA56:
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DFA56: cmp dword ptr [ebp - 4], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0)) goto L_004DFA6A; /* 0x004DFA5A: je 0x4dfa6a */

L_004DFA5C:
    edx = MEM32(0x50B8C0); /* 0x004DFA5C: mov edx, dword ptr [0x50b8c0] */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004DFA62: neg edx */
    MEM32(0x50B8C0) = edx; /* 0x004DFA64: mov dword ptr [0x50b8c0], edx */

L_004DFA6A:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA6A: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DFA6D: movsx ecx, byte ptr [eax] */
    MEM32(0x50B8C4) = ecx; /* 0x004DFA70: mov dword ptr [0x50b8c4], ecx */
    /* cmp MEM32(0x50B8C4), 0 */ /* 0x004DFA76: cmp dword ptr [0x50b8c4], 0 */
    if (CMP_EQ(MEM32(0x50B8C4), 0)) goto L_004DFA9F; /* 0x004DFA7D: je 0x4dfa9f */

L_004DFA7F:
    PUSH32(esp, 3); /* 0x004DFA7F: push 3 */
    edx = MEM32(ebp + (-0x8)); /* 0x004DFA81: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DFA84: push edx */
    eax = MEM32(0x50B954); /* 0x004DFA85: mov eax, dword ptr [0x50b954] */
    PUSH32(esp, eax); /* 0x004DFA8A: push eax */
    RECOMP_CALL(sub_004D1B70); /* 0x004DFA8B: call 0x4d1b70 */
    esp = esp + 0xCu; /* 0x004DFA90: add esp, 0xc */
    ecx = MEM32(0x50B954); /* 0x004DFA93: mov ecx, dword ptr [0x50b954] */
    MEM8(ecx + 0x3) = (uint8_t)(0); /* 0x004DFA99: mov byte ptr [ecx + 3], 0 */
    goto L_004DFAA8; /* 0x004DFA9D: jmp 0x4dfaa8 */

L_004DFA9F:
    edx = MEM32(0x50B954); /* 0x004DFA9F: mov edx, dword ptr [0x50b954] */
    MEM8(edx) = (uint8_t)(0); /* 0x004DFAA5: mov byte ptr [edx], 0 */

L_004DFAA8:
    esp = ebp; /* 0x004DFAA8: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFAAA: pop ebp */
    return; /* 0x004DFAAB: ret  */

}

void sub_004DF7E0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF7E0:
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DF7E0: add byte ptr [eax], al */
    MEM8(ebx + (-0x7B440FF3)) = (uint8_t)(MEM8(ebx + (-0x7B440FF3)) + LO8(ecx)); /* 0x004DF7E2: add byte ptr [ebx - 0x7b440ff3], cl */
    MEM8(ebx + (-0x37)) = (uint8_t)(MEM8(ebx + (-0x37)) + HI8(ecx)); /* 0x004DF7E8: add byte ptr [ebx - 0x37], ch */
    /* cmp LO8(eax), 0x89u */ /* 0x004DF7EB: cmp al, 0x89 */
    eax = eax | 0x0050B8C0u; /* 0x004DF7ED: or eax, 0x50b8c0 */
    edx = 0; /* 0x004DF7F2: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC36)); /* 0x004DF7F4: mov dx, word ptr [0x84bc36] */
    /* test edx, edx */ /* 0x004DF7FB: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DF815; /* 0x004DF7FD: je 0x4df815 */

L_004DF7FF:
    eax = MEM32(0x84BC44); /* 0x004DF7FF: mov eax, dword ptr [0x84bc44] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3Cu); /* 0x004DF804: imul eax, eax, 0x3c */
    ecx = MEM32(0x50B8C0); /* 0x004DF807: mov ecx, dword ptr [0x50b8c0] */
    ecx = ecx + eax; /* 0x004DF80D: add ecx, eax */
    MEM32(0x50B8C0) = ecx; /* 0x004DF80F: mov dword ptr [0x50b8c0], ecx */

L_004DF815:
    edx = 0; /* 0x004DF815: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC8A)); /* 0x004DF817: mov dx, word ptr [0x84bc8a] */
    /* test edx, edx */ /* 0x004DF81E: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DF84A; /* 0x004DF820: je 0x4df84a */

L_004DF822:
    /* cmp MEM32(0x84BC98), 0 */ /* 0x004DF822: cmp dword ptr [0x84bc98], 0 */
    if (CMP_EQ(MEM32(0x84BC98), 0)) goto L_004DF84A; /* 0x004DF829: je 0x4df84a */

L_004DF82B:
    MEM32(0x50B8C4) = 1; /* 0x004DF82B: mov dword ptr [0x50b8c4], 1 */
    eax = MEM32(0x84BC98); /* 0x004DF835: mov eax, dword ptr [0x84bc98] */
    eax = eax - MEM32(0x84BC44); /* 0x004DF83A: sub eax, dword ptr [0x84bc44] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3Cu); /* 0x004DF840: imul eax, eax, 0x3c */
    MEM32(0x50B8C8) = eax; /* 0x004DF843: mov dword ptr [0x50b8c8], eax */
    goto L_004DF85E; /* 0x004DF848: jmp 0x4df85e */

L_004DF84A:
    MEM32(0x50B8C4) = 0; /* 0x004DF84A: mov dword ptr [0x50b8c4], 0 */
    MEM32(0x50B8C8) = 0; /* 0x004DF854: mov dword ptr [0x50b8c8], 0 */

L_004DF85E:
    PUSH32(esp, 0x40u); /* 0x004DF85E: push 0x40 */
    PUSH32(esp, 0x0084BBF4u); /* 0x004DF860: push 0x84bbf4 */
    ecx = MEM32(0x50B950); /* 0x004DF865: mov ecx, dword ptr [0x50b950] */
    PUSH32(esp, ecx); /* 0x004DF86B: push ecx */
    RECOMP_CALL(sub_004E3940); /* 0x004DF86C: call 0x4e3940 */
    esp = esp + 0xCu; /* 0x004DF871: add esp, 0xc */
    PUSH32(esp, 0x40u); /* 0x004DF874: push 0x40 */
    PUSH32(esp, 0x0084BC48u); /* 0x004DF876: push 0x84bc48 */
    edx = MEM32(0x50B954); /* 0x004DF87B: mov edx, dword ptr [0x50b954] */
    PUSH32(esp, edx); /* 0x004DF881: push edx */
    RECOMP_CALL(sub_004E3940); /* 0x004DF882: call 0x4e3940 */
    esp = esp + 0xCu; /* 0x004DF887: add esp, 0xc */
    eax = MEM32(0x50B954); /* 0x004DF88A: mov eax, dword ptr [0x50b954] */
    MEM8(eax + 0x3F) = (uint8_t)(0); /* 0x004DF88F: mov byte ptr [eax + 0x3f], 0 */
    ecx = MEM32(0x50B950); /* 0x004DF893: mov ecx, dword ptr [0x50b950] */
    MEM8(ecx + 0x3F) = (uint8_t)(0); /* 0x004DF899: mov byte ptr [ecx + 0x3f], 0 */
    goto L_004DFAA8; /* 0x004DF89D: jmp 0x4dfaa8 */

L_004DFAA8:
    esp = ebp; /* 0x004DFAA8: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFAAA: pop ebp */
    return; /* 0x004DFAAB: ret  */

}

void sub_004DF810(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF810:
    eax = eax | 0x0050B8C0u; /* 0x004DF810: or eax, 0x50b8c0 */
    edx = 0; /* 0x004DF815: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC8A)); /* 0x004DF817: mov dx, word ptr [0x84bc8a] */
    /* test edx, edx */ /* 0x004DF81E: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004DF84A; /* 0x004DF820: je 0x4df84a */

L_004DF822:
    /* cmp MEM32(0x84BC98), 0 */ /* 0x004DF822: cmp dword ptr [0x84bc98], 0 */
    if (CMP_EQ(MEM32(0x84BC98), 0)) goto L_004DF84A; /* 0x004DF829: je 0x4df84a */

L_004DF82B:
    MEM32(0x50B8C4) = 1; /* 0x004DF82B: mov dword ptr [0x50b8c4], 1 */
    eax = MEM32(0x84BC98); /* 0x004DF835: mov eax, dword ptr [0x84bc98] */
    eax = eax - MEM32(0x84BC44); /* 0x004DF83A: sub eax, dword ptr [0x84bc44] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3Cu); /* 0x004DF840: imul eax, eax, 0x3c */
    MEM32(0x50B8C8) = eax; /* 0x004DF843: mov dword ptr [0x50b8c8], eax */
    goto L_004DF85E; /* 0x004DF848: jmp 0x4df85e */

L_004DF84A:
    MEM32(0x50B8C4) = 0; /* 0x004DF84A: mov dword ptr [0x50b8c4], 0 */
    MEM32(0x50B8C8) = 0; /* 0x004DF854: mov dword ptr [0x50b8c8], 0 */

L_004DF85E:
    PUSH32(esp, 0x40u); /* 0x004DF85E: push 0x40 */
    PUSH32(esp, 0x0084BBF4u); /* 0x004DF860: push 0x84bbf4 */
    ecx = MEM32(0x50B950); /* 0x004DF865: mov ecx, dword ptr [0x50b950] */
    PUSH32(esp, ecx); /* 0x004DF86B: push ecx */
    RECOMP_CALL(sub_004E3940); /* 0x004DF86C: call 0x4e3940 */
    esp = esp + 0xCu; /* 0x004DF871: add esp, 0xc */
    PUSH32(esp, 0x40u); /* 0x004DF874: push 0x40 */
    PUSH32(esp, 0x0084BC48u); /* 0x004DF876: push 0x84bc48 */
    edx = MEM32(0x50B954); /* 0x004DF87B: mov edx, dword ptr [0x50b954] */
    PUSH32(esp, edx); /* 0x004DF881: push edx */
    RECOMP_CALL(sub_004E3940); /* 0x004DF882: call 0x4e3940 */
    esp = esp + 0xCu; /* 0x004DF887: add esp, 0xc */
    eax = MEM32(0x50B954); /* 0x004DF88A: mov eax, dword ptr [0x50b954] */
    MEM8(eax + 0x3F) = (uint8_t)(0); /* 0x004DF88F: mov byte ptr [eax + 0x3f], 0 */
    ecx = MEM32(0x50B950); /* 0x004DF893: mov ecx, dword ptr [0x50b950] */
    MEM8(ecx + 0x3F) = (uint8_t)(0); /* 0x004DF899: mov byte ptr [ecx + 0x3f], 0 */
    goto L_004DFAA8; /* 0x004DF89D: jmp 0x4dfaa8 */

L_004DFAA8:
    esp = ebp; /* 0x004DFAA8: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFAAA: pop ebp */
    return; /* 0x004DFAAB: ret  */

}

void sub_004DF840(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF840:
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3Cu); /* 0x004DF840: imul eax, eax, 0x3c */
    MEM32(0x50B8C8) = eax; /* 0x004DF843: mov dword ptr [0x50b8c8], eax */
    goto L_004DF85E; /* 0x004DF848: jmp 0x4df85e */

L_004DF85E:
    PUSH32(esp, 0x40u); /* 0x004DF85E: push 0x40 */
    PUSH32(esp, 0x0084BBF4u); /* 0x004DF860: push 0x84bbf4 */
    ecx = MEM32(0x50B950); /* 0x004DF865: mov ecx, dword ptr [0x50b950] */
    PUSH32(esp, ecx); /* 0x004DF86B: push ecx */
    RECOMP_CALL(sub_004E3940); /* 0x004DF86C: call 0x4e3940 */
    esp = esp + 0xCu; /* 0x004DF871: add esp, 0xc */
    PUSH32(esp, 0x40u); /* 0x004DF874: push 0x40 */
    PUSH32(esp, 0x0084BC48u); /* 0x004DF876: push 0x84bc48 */
    edx = MEM32(0x50B954); /* 0x004DF87B: mov edx, dword ptr [0x50b954] */
    PUSH32(esp, edx); /* 0x004DF881: push edx */
    RECOMP_CALL(sub_004E3940); /* 0x004DF882: call 0x4e3940 */
    esp = esp + 0xCu; /* 0x004DF887: add esp, 0xc */
    eax = MEM32(0x50B954); /* 0x004DF88A: mov eax, dword ptr [0x50b954] */
    MEM8(eax + 0x3F) = (uint8_t)(0); /* 0x004DF88F: mov byte ptr [eax + 0x3f], 0 */
    ecx = MEM32(0x50B950); /* 0x004DF893: mov ecx, dword ptr [0x50b950] */
    MEM8(ecx + 0x3F) = (uint8_t)(0); /* 0x004DF899: mov byte ptr [ecx + 0x3f], 0 */
    goto L_004DFAA8; /* 0x004DF89D: jmp 0x4dfaa8 */

L_004DFAA8:
    esp = ebp; /* 0x004DFAA8: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFAAA: pop ebp */
    return; /* 0x004DFAAB: ret  */

}

void sub_004DF8D0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF8D0:
    MEM8(edx + 0x2) = (uint8_t)(MEM8(edx + 0x2) + HI8(ecx)); /* 0x004DF8D0: add byte ptr [edx + 2], ch */
    eax = MEM32(0x84BC9C); /* 0x004DF8D3: mov eax, dword ptr [0x84bc9c] */
    PUSH32(esp, eax); /* 0x004DF8D8: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004DF8D9: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004DF8DE: add esp, 8 */
    PUSH32(esp, 0xECu); /* 0x004DF8E1: push 0xec */
    PUSH32(esp, 0x004F46E0u); /* 0x004DF8E6: push 0x4f46e0 */
    PUSH32(esp, 2); /* 0x004DF8EB: push 2 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF8ED: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DF8F0: push ecx */
    RECOMP_CALL(sub_004D5870); /* 0x004DF8F1: call 0x4d5870 */
    esp = esp + 4; /* 0x004DF8F6: add esp, 4 */
    eax = eax + 1; /* 0x004DF8F9: add eax, 1 */
    PUSH32(esp, eax); /* 0x004DF8FC: push eax */
    RECOMP_CALL(sub_004D25A0); /* 0x004DF8FD: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004DF902: add esp, 0x10 */
    MEM32(0x84BC9C) = eax; /* 0x004DF905: mov dword ptr [0x84bc9c], eax */
    /* cmp MEM32(0x84BC9C), 0 */ /* 0x004DF90A: cmp dword ptr [0x84bc9c], 0 */
    if (CMP_NE(MEM32(0x84BC9C), 0)) goto L_004DF918; /* 0x004DF911: jne 0x4df918 */

L_004DF913:
    goto L_004DFAA8; /* 0x004DF913: jmp 0x4dfaa8 */

L_004DF918:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF918: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DF91B: push edx */
    eax = MEM32(0x84BC9C); /* 0x004DF91C: mov eax, dword ptr [0x84bc9c] */
    PUSH32(esp, eax); /* 0x004DF921: push eax */
    RECOMP_CALL(sub_004DC810); /* 0x004DF922: call 0x4dc810 */
    esp = esp + 8; /* 0x004DF927: add esp, 8 */
    PUSH32(esp, 3); /* 0x004DF92A: push 3 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF92C: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DF92F: push ecx */
    edx = MEM32(0x50B950); /* 0x004DF930: mov edx, dword ptr [0x50b950] */
    PUSH32(esp, edx); /* 0x004DF936: push edx */
    RECOMP_CALL(sub_004D1B70); /* 0x004DF937: call 0x4d1b70 */
    esp = esp + 0xCu; /* 0x004DF93C: add esp, 0xc */
    eax = MEM32(0x50B950); /* 0x004DF93F: mov eax, dword ptr [0x50b950] */
    MEM8(eax + 0x3) = (uint8_t)(0); /* 0x004DF944: mov byte ptr [eax + 3], 0 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF948: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 3; /* 0x004DF94B: add ecx, 3 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DF94E: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DF951: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF954: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x2Du */ /* 0x004DF957: cmp eax, 0x2d */
    if (CMP_NE(eax, 0x2Du)) goto L_004DF96E; /* 0x004DF95A: jne 0x4df96e */

L_004DF95C:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DF95C: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004DF95F: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DF962: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DF965: mov edx, dword ptr [ebp - 8] */
    edx = edx + 1; /* 0x004DF968: add edx, 1 */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DF96B: mov dword ptr [ebp - 8], edx */

L_004DF96E:
    eax = MEM32(ebp + (-0x8)); /* 0x004DF96E: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004DF971: push eax */
    RECOMP_CALL(sub_004E36F0); /* 0x004DF972: call 0x4e36f0 */
    esp = esp + 4; /* 0x004DF977: add esp, 4 */
    eax = (uint32_t)((int32_t)eax * (int32_t)0xE10u); /* 0x004DF97A: imul eax, eax, 0xe10 */
    MEM32(0x50B8C0) = eax; /* 0x004DF980: mov dword ptr [0x50b8c0], eax */

L_004DF985:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF985: mov ecx, dword ptr [ebp - 8] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DF988: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x2Bu */ /* 0x004DF98B: cmp edx, 0x2b */
    if (CMP_EQ(edx, 0x2Bu)) goto L_004DF9A6; /* 0x004DF98E: je 0x4df9a6 */

L_004DF990:
    eax = MEM32(ebp + (-0x8)); /* 0x004DF990: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DF993: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x30u */ /* 0x004DF996: cmp ecx, 0x30 */
    if (CMP_L(ecx, 0x30u)) goto L_004DF9B1; /* 0x004DF999: jl 0x4df9b1 */

L_004DF99B:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF99B: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF99E: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x39u */ /* 0x004DF9A1: cmp eax, 0x39 */
    if (CMP_G(eax, 0x39u)) goto L_004DF9B1; /* 0x004DF9A4: jg 0x4df9b1 */

L_004DF9A6:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF9A6: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DF9A9: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DF9AC: mov dword ptr [ebp - 8], ecx */
    goto L_004DF985; /* 0x004DF9AF: jmp 0x4df985 */

L_004DF9B1:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF9B1: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF9B4: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x3Au */ /* 0x004DF9B7: cmp eax, 0x3a */
    if (CMP_NE(eax, 0x3Au)) goto L_004DFA56; /* 0x004DF9BA: jne 0x4dfa56 */

L_004DF9C0:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF9C0: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DF9C3: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DF9C6: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DF9C9: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DF9CC: push edx */
    RECOMP_CALL(sub_004E36F0); /* 0x004DF9CD: call 0x4e36f0 */
    esp = esp + 4; /* 0x004DF9D2: add esp, 4 */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3Cu); /* 0x004DF9D5: imul eax, eax, 0x3c */
    ecx = MEM32(0x50B8C0); /* 0x004DF9D8: mov ecx, dword ptr [0x50b8c0] */
    ecx = ecx + eax; /* 0x004DF9DE: add ecx, eax */
    MEM32(0x50B8C0) = ecx; /* 0x004DF9E0: mov dword ptr [0x50b8c0], ecx */

L_004DF9E6:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF9E6: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF9E9: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x30u */ /* 0x004DF9EC: cmp eax, 0x30 */
    if (CMP_L(eax, 0x30u)) goto L_004DFA07; /* 0x004DF9EF: jl 0x4dfa07 */

L_004DF9F1:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF9F1: mov ecx, dword ptr [ebp - 8] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DF9F4: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x39u */ /* 0x004DF9F7: cmp edx, 0x39 */
    if (CMP_G(edx, 0x39u)) goto L_004DFA07; /* 0x004DF9FA: jg 0x4dfa07 */

L_004DF9FC:
    eax = MEM32(ebp + (-0x8)); /* 0x004DF9FC: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DF9FF: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DFA02: mov dword ptr [ebp - 8], eax */
    goto L_004DF9E6; /* 0x004DFA05: jmp 0x4df9e6 */

L_004DFA07:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA07: mov ecx, dword ptr [ebp - 8] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DFA0A: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x3Au */ /* 0x004DFA0D: cmp edx, 0x3a */
    if (CMP_NE(edx, 0x3Au)) goto L_004DFA56; /* 0x004DFA10: jne 0x4dfa56 */

L_004DFA12:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA12: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DFA15: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DFA18: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA1B: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DFA1E: push ecx */
    RECOMP_CALL(sub_004E36F0); /* 0x004DFA1F: call 0x4e36f0 */
    esp = esp + 4; /* 0x004DFA24: add esp, 4 */
    edx = MEM32(0x50B8C0); /* 0x004DFA27: mov edx, dword ptr [0x50b8c0] */
    edx = edx + eax; /* 0x004DFA2D: add edx, eax */
    MEM32(0x50B8C0) = edx; /* 0x004DFA2F: mov dword ptr [0x50b8c0], edx */

L_004DFA35:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA35: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DFA38: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x30u */ /* 0x004DFA3B: cmp ecx, 0x30 */
    if (CMP_L(ecx, 0x30u)) goto L_004DFA56; /* 0x004DFA3E: jl 0x4dfa56 */

L_004DFA40:
    edx = MEM32(ebp + (-0x8)); /* 0x004DFA40: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DFA43: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x39u */ /* 0x004DFA46: cmp eax, 0x39 */
    if (CMP_G(eax, 0x39u)) goto L_004DFA56; /* 0x004DFA49: jg 0x4dfa56 */

L_004DFA4B:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA4B: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DFA4E: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DFA51: mov dword ptr [ebp - 8], ecx */
    goto L_004DFA35; /* 0x004DFA54: jmp 0x4dfa35 */

L_004DFA56:
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DFA56: cmp dword ptr [ebp - 4], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0)) goto L_004DFA6A; /* 0x004DFA5A: je 0x4dfa6a */

L_004DFA5C:
    edx = MEM32(0x50B8C0); /* 0x004DFA5C: mov edx, dword ptr [0x50b8c0] */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004DFA62: neg edx */
    MEM32(0x50B8C0) = edx; /* 0x004DFA64: mov dword ptr [0x50b8c0], edx */

L_004DFA6A:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA6A: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DFA6D: movsx ecx, byte ptr [eax] */
    MEM32(0x50B8C4) = ecx; /* 0x004DFA70: mov dword ptr [0x50b8c4], ecx */
    /* cmp MEM32(0x50B8C4), 0 */ /* 0x004DFA76: cmp dword ptr [0x50b8c4], 0 */
    if (CMP_EQ(MEM32(0x50B8C4), 0)) goto L_004DFA9F; /* 0x004DFA7D: je 0x4dfa9f */

L_004DFA7F:
    PUSH32(esp, 3); /* 0x004DFA7F: push 3 */
    edx = MEM32(ebp + (-0x8)); /* 0x004DFA81: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DFA84: push edx */
    eax = MEM32(0x50B954); /* 0x004DFA85: mov eax, dword ptr [0x50b954] */
    PUSH32(esp, eax); /* 0x004DFA8A: push eax */
    RECOMP_CALL(sub_004D1B70); /* 0x004DFA8B: call 0x4d1b70 */
    esp = esp + 0xCu; /* 0x004DFA90: add esp, 0xc */
    ecx = MEM32(0x50B954); /* 0x004DFA93: mov ecx, dword ptr [0x50b954] */
    MEM8(ecx + 0x3) = (uint8_t)(0); /* 0x004DFA99: mov byte ptr [ecx + 3], 0 */
    goto L_004DFAA8; /* 0x004DFA9D: jmp 0x4dfaa8 */

L_004DFA9F:
    edx = MEM32(0x50B954); /* 0x004DFA9F: mov edx, dword ptr [0x50b954] */
    MEM8(edx) = (uint8_t)(0); /* 0x004DFAA5: mov byte ptr [edx], 0 */

L_004DFAA8:
    esp = ebp; /* 0x004DFAA8: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFAAA: pop ebp */
    return; /* 0x004DFAAB: ret  */

}

void sub_004DFA00(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DF9E6:
    edx = MEM32(ebp + (-0x8)); /* 0x004DF9E6: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DF9E9: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x30u */ /* 0x004DF9EC: cmp eax, 0x30 */
    if (CMP_L(eax, 0x30u)) goto L_004DFA07; /* 0x004DF9EF: jl 0x4dfa07 */

L_004DF9F1:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DF9F1: mov ecx, dword ptr [ebp - 8] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DF9F4: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x39u */ /* 0x004DF9F7: cmp edx, 0x39 */
    if (CMP_G(edx, 0x39u)) goto L_004DFA07; /* 0x004DF9FA: jg 0x4dfa07 */

L_004DF9FC:
    eax = MEM32(ebp + (-0x8)); /* 0x004DF9FC: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DF9FF: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DFA02: mov dword ptr [ebp - 8], eax */
    goto L_004DF9E6; /* 0x004DFA05: jmp 0x4df9e6 */

L_004DFA00:
    MEM8(ecx) = (uint8_t)(ROL32(MEM8(ecx), 0x89u)); /* 0x004DFA00: rol byte ptr [ecx], 0x89 */
    ebp = ebp + 1; /* 0x004DFA03: inc ebp */
    _cf = 0; /* 0x004DFA04: clc  */
    goto L_004DF9E6; /* 0x004DFA05: jmp 0x4df9e6 */

L_004DFA07:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA07: mov ecx, dword ptr [ebp - 8] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004DFA0A: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x3Au */ /* 0x004DFA0D: cmp edx, 0x3a */
    if (CMP_NE(edx, 0x3Au)) goto L_004DFA56; /* 0x004DFA10: jne 0x4dfa56 */

L_004DFA12:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA12: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004DFA15: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004DFA18: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA1B: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004DFA1E: push ecx */
    RECOMP_CALL(sub_004E36F0); /* 0x004DFA1F: call 0x4e36f0 */
    esp = esp + 4; /* 0x004DFA24: add esp, 4 */
    edx = MEM32(0x50B8C0); /* 0x004DFA27: mov edx, dword ptr [0x50b8c0] */
    edx = edx + eax; /* 0x004DFA2D: add edx, eax */
    MEM32(0x50B8C0) = edx; /* 0x004DFA2F: mov dword ptr [0x50b8c0], edx */

L_004DFA35:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA35: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DFA38: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x30u */ /* 0x004DFA3B: cmp ecx, 0x30 */
    if (CMP_L(ecx, 0x30u)) goto L_004DFA56; /* 0x004DFA3E: jl 0x4dfa56 */

L_004DFA40:
    edx = MEM32(ebp + (-0x8)); /* 0x004DFA40: mov edx, dword ptr [ebp - 8] */
    eax = (int32_t)(int8_t)MEM8(edx); /* 0x004DFA43: movsx eax, byte ptr [edx] */
    /* cmp eax, 0x39u */ /* 0x004DFA46: cmp eax, 0x39 */
    if (CMP_G(eax, 0x39u)) goto L_004DFA56; /* 0x004DFA49: jg 0x4dfa56 */

L_004DFA4B:
    ecx = MEM32(ebp + (-0x8)); /* 0x004DFA4B: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 1; /* 0x004DFA4E: add ecx, 1 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DFA51: mov dword ptr [ebp - 8], ecx */
    goto L_004DFA35; /* 0x004DFA54: jmp 0x4dfa35 */

L_004DFA56:
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004DFA56: cmp dword ptr [ebp - 4], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0)) goto L_004DFA6A; /* 0x004DFA5A: je 0x4dfa6a */

L_004DFA5C:
    edx = MEM32(0x50B8C0); /* 0x004DFA5C: mov edx, dword ptr [0x50b8c0] */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004DFA62: neg edx */
    MEM32(0x50B8C0) = edx; /* 0x004DFA64: mov dword ptr [0x50b8c0], edx */

L_004DFA6A:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFA6A: mov eax, dword ptr [ebp - 8] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004DFA6D: movsx ecx, byte ptr [eax] */
    MEM32(0x50B8C4) = ecx; /* 0x004DFA70: mov dword ptr [0x50b8c4], ecx */
    /* cmp MEM32(0x50B8C4), 0 */ /* 0x004DFA76: cmp dword ptr [0x50b8c4], 0 */
    if (CMP_EQ(MEM32(0x50B8C4), 0)) goto L_004DFA9F; /* 0x004DFA7D: je 0x4dfa9f */

L_004DFA7F:
    PUSH32(esp, 3); /* 0x004DFA7F: push 3 */
    edx = MEM32(ebp + (-0x8)); /* 0x004DFA81: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004DFA84: push edx */
    eax = MEM32(0x50B954); /* 0x004DFA85: mov eax, dword ptr [0x50b954] */
    PUSH32(esp, eax); /* 0x004DFA8A: push eax */
    RECOMP_CALL(sub_004D1B70); /* 0x004DFA8B: call 0x4d1b70 */
    esp = esp + 0xCu; /* 0x004DFA90: add esp, 0xc */
    ecx = MEM32(0x50B954); /* 0x004DFA93: mov ecx, dword ptr [0x50b954] */
    MEM8(ecx + 0x3) = (uint8_t)(0); /* 0x004DFA99: mov byte ptr [ecx + 3], 0 */
    goto L_004DFAA8; /* 0x004DFA9D: jmp 0x4dfaa8 */

L_004DFA9F:
    edx = MEM32(0x50B954); /* 0x004DFA9F: mov edx, dword ptr [0x50b954] */
    MEM8(edx) = (uint8_t)(0); /* 0x004DFAA5: mov byte ptr [edx], 0 */

L_004DFAA8:
    esp = ebp; /* 0x004DFAA8: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFAAA: pop ebp */
    return; /* 0x004DFAAB: ret  */

}

void sub_004DFAB0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DFAB0:
    PUSH32(esp, ebp); /* 0x004DFAB0: push ebp */
    ebp = esp; /* 0x004DFAB1: mov ebp, esp */
    PUSH32(esp, ecx); /* 0x004DFAB3: push ecx */
    /* cmp MEM32(0x50B8C4), 0 */ /* 0x004DFAB4: cmp dword ptr [0x50b8c4], 0 */
    if (CMP_NE(MEM32(0x50B8C4), 0)) goto L_004DFAC4; /* 0x004DFABB: jne 0x4dfac4 */

L_004DFABD:
    eax = 0; /* 0x004DFABD: xor eax, eax */
    goto L_004DFDA6; /* 0x004DFABF: jmp 0x4dfda6 */

L_004DFAC4:
    eax = MEM32(ebp + 0x8); /* 0x004DFAC4: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x14); /* 0x004DFAC7: mov ecx, dword ptr [eax + 0x14] */
    /* cmp ecx, MEM32(0x50B958) */ /* 0x004DFACA: cmp ecx, dword ptr [0x50b958] */
    if (CMP_NE(ecx, MEM32(0x50B958))) goto L_004DFAE4; /* 0x004DFAD0: jne 0x4dfae4 */

L_004DFAD2:
    edx = MEM32(ebp + 0x8); /* 0x004DFAD2: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x14); /* 0x004DFAD5: mov eax, dword ptr [edx + 0x14] */
    /* cmp eax, MEM32(0x50B968) */ /* 0x004DFAD8: cmp eax, dword ptr [0x50b968] */
    if (CMP_EQ(eax, MEM32(0x50B968))) goto L_004DFCAB; /* 0x004DFADE: je 0x4dfcab */

L_004DFAE4:
    /* cmp MEM32(0x84BBE8), 0 */ /* 0x004DFAE4: cmp dword ptr [0x84bbe8], 0 */
    if (CMP_EQ(MEM32(0x84BBE8), 0)) goto L_004DFC65; /* 0x004DFAEB: je 0x4dfc65 */

L_004DFAF1:
    ecx = 0; /* 0x004DFAF1: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC88)); /* 0x004DFAF3: mov cx, word ptr [0x84bc88] */
    /* test ecx, ecx */ /* 0x004DFAFA: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DFB59; /* 0x004DFAFC: jne 0x4dfb59 */

L_004DFAFE:
    edx = 0; /* 0x004DFAFE: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC96)); /* 0x004DFB00: mov dx, word ptr [0x84bc96] */
    PUSH32(esp, edx); /* 0x004DFB07: push edx */
    eax = 0; /* 0x004DFB08: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC94)); /* 0x004DFB0A: mov ax, word ptr [0x84bc94] */
    PUSH32(esp, eax); /* 0x004DFB10: push eax */
    ecx = 0; /* 0x004DFB11: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC92)); /* 0x004DFB13: mov cx, word ptr [0x84bc92] */
    PUSH32(esp, ecx); /* 0x004DFB1A: push ecx */
    edx = 0; /* 0x004DFB1B: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC90)); /* 0x004DFB1D: mov dx, word ptr [0x84bc90] */
    PUSH32(esp, edx); /* 0x004DFB24: push edx */
    PUSH32(esp, 0); /* 0x004DFB25: push 0 */
    eax = 0; /* 0x004DFB27: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC8C)); /* 0x004DFB29: mov ax, word ptr [0x84bc8c] */
    PUSH32(esp, eax); /* 0x004DFB2F: push eax */
    ecx = 0; /* 0x004DFB30: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC8E)); /* 0x004DFB32: mov cx, word ptr [0x84bc8e] */
    PUSH32(esp, ecx); /* 0x004DFB39: push ecx */
    edx = 0; /* 0x004DFB3A: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC8A)); /* 0x004DFB3C: mov dx, word ptr [0x84bc8a] */
    PUSH32(esp, edx); /* 0x004DFB43: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004DFB44: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x14); /* 0x004DFB47: mov ecx, dword ptr [eax + 0x14] */
    PUSH32(esp, ecx); /* 0x004DFB4A: push ecx */
    PUSH32(esp, 1); /* 0x004DFB4B: push 1 */
    PUSH32(esp, 1); /* 0x004DFB4D: push 1 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFB4F: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFB54: add esp, 0x2c */
    goto L_004DFBAA; /* 0x004DFB57: jmp 0x4dfbaa */

L_004DFB59:
    edx = 0; /* 0x004DFB59: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC96)); /* 0x004DFB5B: mov dx, word ptr [0x84bc96] */
    PUSH32(esp, edx); /* 0x004DFB62: push edx */
    eax = 0; /* 0x004DFB63: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC94)); /* 0x004DFB65: mov ax, word ptr [0x84bc94] */
    PUSH32(esp, eax); /* 0x004DFB6B: push eax */
    ecx = 0; /* 0x004DFB6C: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC92)); /* 0x004DFB6E: mov cx, word ptr [0x84bc92] */
    PUSH32(esp, ecx); /* 0x004DFB75: push ecx */
    edx = 0; /* 0x004DFB76: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC90)); /* 0x004DFB78: mov dx, word ptr [0x84bc90] */
    PUSH32(esp, edx); /* 0x004DFB7F: push edx */
    eax = 0; /* 0x004DFB80: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC8E)); /* 0x004DFB82: mov ax, word ptr [0x84bc8e] */
    PUSH32(esp, eax); /* 0x004DFB88: push eax */
    PUSH32(esp, 0); /* 0x004DFB89: push 0 */
    PUSH32(esp, 0); /* 0x004DFB8B: push 0 */
    ecx = 0; /* 0x004DFB8D: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC8A)); /* 0x004DFB8F: mov cx, word ptr [0x84bc8a] */
    PUSH32(esp, ecx); /* 0x004DFB96: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004DFB97: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x14); /* 0x004DFB9A: mov eax, dword ptr [edx + 0x14] */
    PUSH32(esp, eax); /* 0x004DFB9D: push eax */
    PUSH32(esp, 0); /* 0x004DFB9E: push 0 */
    PUSH32(esp, 1); /* 0x004DFBA0: push 1 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFBA2: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFBA7: add esp, 0x2c */

L_004DFBAA:
    ecx = 0; /* 0x004DFBAA: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC34)); /* 0x004DFBAC: mov cx, word ptr [0x84bc34] */
    /* test ecx, ecx */ /* 0x004DFBB3: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DFC12; /* 0x004DFBB5: jne 0x4dfc12 */

L_004DFBB7:
    edx = 0; /* 0x004DFBB7: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC42)); /* 0x004DFBB9: mov dx, word ptr [0x84bc42] */
    PUSH32(esp, edx); /* 0x004DFBC0: push edx */
    eax = 0; /* 0x004DFBC1: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC40)); /* 0x004DFBC3: mov ax, word ptr [0x84bc40] */
    PUSH32(esp, eax); /* 0x004DFBC9: push eax */
    ecx = 0; /* 0x004DFBCA: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC3E)); /* 0x004DFBCC: mov cx, word ptr [0x84bc3e] */
    PUSH32(esp, ecx); /* 0x004DFBD3: push ecx */
    edx = 0; /* 0x004DFBD4: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC3C)); /* 0x004DFBD6: mov dx, word ptr [0x84bc3c] */
    PUSH32(esp, edx); /* 0x004DFBDD: push edx */
    PUSH32(esp, 0); /* 0x004DFBDE: push 0 */
    eax = 0; /* 0x004DFBE0: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC38)); /* 0x004DFBE2: mov ax, word ptr [0x84bc38] */
    PUSH32(esp, eax); /* 0x004DFBE8: push eax */
    ecx = 0; /* 0x004DFBE9: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC3A)); /* 0x004DFBEB: mov cx, word ptr [0x84bc3a] */
    PUSH32(esp, ecx); /* 0x004DFBF2: push ecx */
    edx = 0; /* 0x004DFBF3: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC36)); /* 0x004DFBF5: mov dx, word ptr [0x84bc36] */
    PUSH32(esp, edx); /* 0x004DFBFC: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004DFBFD: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x14); /* 0x004DFC00: mov ecx, dword ptr [eax + 0x14] */
    PUSH32(esp, ecx); /* 0x004DFC03: push ecx */
    PUSH32(esp, 1); /* 0x004DFC04: push 1 */
    PUSH32(esp, 0); /* 0x004DFC06: push 0 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFC08: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFC0D: add esp, 0x2c */
    goto L_004DFC63; /* 0x004DFC10: jmp 0x4dfc63 */

L_004DFC12:
    edx = 0; /* 0x004DFC12: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC42)); /* 0x004DFC14: mov dx, word ptr [0x84bc42] */
    PUSH32(esp, edx); /* 0x004DFC1B: push edx */
    eax = 0; /* 0x004DFC1C: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC40)); /* 0x004DFC1E: mov ax, word ptr [0x84bc40] */
    PUSH32(esp, eax); /* 0x004DFC24: push eax */
    ecx = 0; /* 0x004DFC25: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC3E)); /* 0x004DFC27: mov cx, word ptr [0x84bc3e] */
    PUSH32(esp, ecx); /* 0x004DFC2E: push ecx */
    edx = 0; /* 0x004DFC2F: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC3C)); /* 0x004DFC31: mov dx, word ptr [0x84bc3c] */
    PUSH32(esp, edx); /* 0x004DFC38: push edx */
    eax = 0; /* 0x004DFC39: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC3A)); /* 0x004DFC3B: mov ax, word ptr [0x84bc3a] */
    PUSH32(esp, eax); /* 0x004DFC41: push eax */
    PUSH32(esp, 0); /* 0x004DFC42: push 0 */
    PUSH32(esp, 0); /* 0x004DFC44: push 0 */
    ecx = 0; /* 0x004DFC46: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC36)); /* 0x004DFC48: mov cx, word ptr [0x84bc36] */
    PUSH32(esp, ecx); /* 0x004DFC4F: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004DFC50: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x14); /* 0x004DFC53: mov eax, dword ptr [edx + 0x14] */
    PUSH32(esp, eax); /* 0x004DFC56: push eax */
    PUSH32(esp, 0); /* 0x004DFC57: push 0 */
    PUSH32(esp, 0); /* 0x004DFC59: push 0 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFC5B: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFC60: add esp, 0x2c */

L_004DFC63:
    goto L_004DFCAB; /* 0x004DFC63: jmp 0x4dfcab */

L_004DFC65:
    PUSH32(esp, 0); /* 0x004DFC65: push 0 */
    PUSH32(esp, 0); /* 0x004DFC67: push 0 */
    PUSH32(esp, 0); /* 0x004DFC69: push 0 */
    PUSH32(esp, 2); /* 0x004DFC6B: push 2 */
    PUSH32(esp, 0); /* 0x004DFC6D: push 0 */
    PUSH32(esp, 0); /* 0x004DFC6F: push 0 */
    PUSH32(esp, 1); /* 0x004DFC71: push 1 */
    PUSH32(esp, 4); /* 0x004DFC73: push 4 */
    ecx = MEM32(ebp + 0x8); /* 0x004DFC75: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x14); /* 0x004DFC78: mov edx, dword ptr [ecx + 0x14] */
    PUSH32(esp, edx); /* 0x004DFC7B: push edx */
    PUSH32(esp, 1); /* 0x004DFC7C: push 1 */
    PUSH32(esp, 1); /* 0x004DFC7E: push 1 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFC80: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFC85: add esp, 0x2c */
    PUSH32(esp, 0); /* 0x004DFC88: push 0 */
    PUSH32(esp, 0); /* 0x004DFC8A: push 0 */
    PUSH32(esp, 0); /* 0x004DFC8C: push 0 */
    PUSH32(esp, 2); /* 0x004DFC8E: push 2 */
    PUSH32(esp, 0); /* 0x004DFC90: push 0 */
    PUSH32(esp, 0); /* 0x004DFC92: push 0 */
    PUSH32(esp, 5); /* 0x004DFC94: push 5 */
    PUSH32(esp, 0xAu); /* 0x004DFC96: push 0xa */
    eax = MEM32(ebp + 0x8); /* 0x004DFC98: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x14); /* 0x004DFC9B: mov ecx, dword ptr [eax + 0x14] */
    PUSH32(esp, ecx); /* 0x004DFC9E: push ecx */
    PUSH32(esp, 1); /* 0x004DFC9F: push 1 */
    PUSH32(esp, 0); /* 0x004DFCA1: push 0 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFCA3: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFCA8: add esp, 0x2c */

L_004DFCAB:
    edx = MEM32(0x50B95C); /* 0x004DFCAB: mov edx, dword ptr [0x50b95c] */
    /* cmp edx, MEM32(0x50B96C) */ /* 0x004DFCB1: cmp edx, dword ptr [0x50b96c] */
    if (CMP_GE(edx, MEM32(0x50B96C))) goto L_004DFD04; /* 0x004DFCB7: jge 0x4dfd04 */

L_004DFCB9:
    eax = MEM32(ebp + 0x8); /* 0x004DFCB9: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x1C); /* 0x004DFCBC: mov ecx, dword ptr [eax + 0x1c] */
    /* cmp ecx, MEM32(0x50B95C) */ /* 0x004DFCBF: cmp ecx, dword ptr [0x50b95c] */
    if (CMP_L(ecx, MEM32(0x50B95C))) goto L_004DFCD5; /* 0x004DFCC5: jl 0x4dfcd5 */

L_004DFCC7:
    edx = MEM32(ebp + 0x8); /* 0x004DFCC7: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x1C); /* 0x004DFCCA: mov eax, dword ptr [edx + 0x1c] */
    /* cmp eax, MEM32(0x50B96C) */ /* 0x004DFCCD: cmp eax, dword ptr [0x50b96c] */
    if (CMP_LE(eax, MEM32(0x50B96C))) goto L_004DFCDC; /* 0x004DFCD3: jle 0x4dfcdc */

L_004DFCD5:
    eax = 0; /* 0x004DFCD5: xor eax, eax */
    goto L_004DFDA6; /* 0x004DFCD7: jmp 0x4dfda6 */

L_004DFCDC:
    ecx = MEM32(ebp + 0x8); /* 0x004DFCDC: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004DFCDF: mov edx, dword ptr [ecx + 0x1c] */
    /* cmp edx, MEM32(0x50B95C) */ /* 0x004DFCE2: cmp edx, dword ptr [0x50b95c] */
    if (CMP_LE(edx, MEM32(0x50B95C))) goto L_004DFD02; /* 0x004DFCE8: jle 0x4dfd02 */

L_004DFCEA:
    eax = MEM32(ebp + 0x8); /* 0x004DFCEA: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x1C); /* 0x004DFCED: mov ecx, dword ptr [eax + 0x1c] */
    /* cmp ecx, MEM32(0x50B96C) */ /* 0x004DFCF0: cmp ecx, dword ptr [0x50b96c] */
    if (CMP_GE(ecx, MEM32(0x50B96C))) goto L_004DFD02; /* 0x004DFCF6: jge 0x4dfd02 */

L_004DFCF8:
    eax = 1; /* 0x004DFCF8: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFCFD: jmp 0x4dfda6 */

L_004DFD02:
    goto L_004DFD47; /* 0x004DFD02: jmp 0x4dfd47 */

L_004DFD04:
    edx = MEM32(ebp + 0x8); /* 0x004DFD04: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x1C); /* 0x004DFD07: mov eax, dword ptr [edx + 0x1c] */
    /* cmp eax, MEM32(0x50B96C) */ /* 0x004DFD0A: cmp eax, dword ptr [0x50b96c] */
    if (CMP_L(eax, MEM32(0x50B96C))) goto L_004DFD20; /* 0x004DFD10: jl 0x4dfd20 */

L_004DFD12:
    ecx = MEM32(ebp + 0x8); /* 0x004DFD12: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004DFD15: mov edx, dword ptr [ecx + 0x1c] */
    /* cmp edx, MEM32(0x50B95C) */ /* 0x004DFD18: cmp edx, dword ptr [0x50b95c] */
    if (CMP_LE(edx, MEM32(0x50B95C))) goto L_004DFD27; /* 0x004DFD1E: jle 0x4dfd27 */

L_004DFD20:
    eax = 1; /* 0x004DFD20: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFD25: jmp 0x4dfda6 */

L_004DFD27:
    eax = MEM32(ebp + 0x8); /* 0x004DFD27: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x1C); /* 0x004DFD2A: mov ecx, dword ptr [eax + 0x1c] */
    /* cmp ecx, MEM32(0x50B96C) */ /* 0x004DFD2D: cmp ecx, dword ptr [0x50b96c] */
    if (CMP_LE(ecx, MEM32(0x50B96C))) goto L_004DFD47; /* 0x004DFD33: jle 0x4dfd47 */

L_004DFD35:
    edx = MEM32(ebp + 0x8); /* 0x004DFD35: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x1C); /* 0x004DFD38: mov eax, dword ptr [edx + 0x1c] */
    /* cmp eax, MEM32(0x50B95C) */ /* 0x004DFD3B: cmp eax, dword ptr [0x50b95c] */
    if (CMP_GE(eax, MEM32(0x50B95C))) goto L_004DFD47; /* 0x004DFD41: jge 0x4dfd47 */

L_004DFD43:
    eax = 0; /* 0x004DFD43: xor eax, eax */
    goto L_004DFDA6; /* 0x004DFD45: jmp 0x4dfda6 */

L_004DFD47:
    ecx = MEM32(ebp + 0x8); /* 0x004DFD47: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x4); /* 0x004DFD4A: mov edx, dword ptr [ecx + 4] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFD4D: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x8); /* 0x004DFD50: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax); /* 0x004DFD53: mov ecx, dword ptr [eax] */
    ecx = ecx + edx; /* 0x004DFD55: add ecx, edx */
    edx = MEM32(ebp + 0x8); /* 0x004DFD57: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x8); /* 0x004DFD5A: mov eax, dword ptr [edx + 8] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0xE10u); /* 0x004DFD5D: imul eax, eax, 0xe10 */
    ecx = ecx + eax; /* 0x004DFD63: add ecx, eax */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3E8u); /* 0x004DFD65: imul ecx, ecx, 0x3e8 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DFD6B: mov dword ptr [ebp - 4], ecx */
    ecx = MEM32(ebp + 0x8); /* 0x004DFD6E: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004DFD71: mov edx, dword ptr [ecx + 0x1c] */
    /* cmp edx, MEM32(0x50B95C) */ /* 0x004DFD74: cmp edx, dword ptr [0x50b95c] */
    if (CMP_NE(edx, MEM32(0x50B95C))) goto L_004DFD92; /* 0x004DFD7A: jne 0x4dfd92 */

L_004DFD7C:
    eax = MEM32(ebp + (-0x4)); /* 0x004DFD7C: mov eax, dword ptr [ebp - 4] */
    /* cmp eax, MEM32(0x50B960) */ /* 0x004DFD7F: cmp eax, dword ptr [0x50b960] */
    if (CMP_L(eax, MEM32(0x50B960))) goto L_004DFD8E; /* 0x004DFD85: jl 0x4dfd8e */

L_004DFD87:
    eax = 1; /* 0x004DFD87: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFD8C: jmp 0x4dfda6 */

L_004DFD8E:
    eax = 0; /* 0x004DFD8E: xor eax, eax */
    goto L_004DFDA6; /* 0x004DFD90: jmp 0x4dfda6 */

L_004DFD92:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DFD92: mov ecx, dword ptr [ebp - 4] */
    /* cmp ecx, MEM32(0x50B970) */ /* 0x004DFD95: cmp ecx, dword ptr [0x50b970] */
    if (CMP_GE(ecx, MEM32(0x50B970))) goto L_004DFDA4; /* 0x004DFD9B: jge 0x4dfda4 */

L_004DFD9D:
    eax = 1; /* 0x004DFD9D: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFDA2: jmp 0x4dfda6 */

L_004DFDA4:
    eax = 0; /* 0x004DFDA4: xor eax, eax */

L_004DFDA6:
    esp = ebp; /* 0x004DFDA6: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFDA8: pop ebp */
    return; /* 0x004DFDA9: ret  */

}

void sub_004DFB80(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DFB80:
    eax = 0; /* 0x004DFB80: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC8E)); /* 0x004DFB82: mov ax, word ptr [0x84bc8e] */
    PUSH32(esp, eax); /* 0x004DFB88: push eax */
    PUSH32(esp, 0); /* 0x004DFB89: push 0 */
    PUSH32(esp, 0); /* 0x004DFB8B: push 0 */
    ecx = 0; /* 0x004DFB8D: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC8A)); /* 0x004DFB8F: mov cx, word ptr [0x84bc8a] */
    PUSH32(esp, ecx); /* 0x004DFB96: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004DFB97: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x14); /* 0x004DFB9A: mov eax, dword ptr [edx + 0x14] */
    PUSH32(esp, eax); /* 0x004DFB9D: push eax */
    PUSH32(esp, 0); /* 0x004DFB9E: push 0 */
    PUSH32(esp, 1); /* 0x004DFBA0: push 1 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFBA2: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFBA7: add esp, 0x2c */
    ecx = 0; /* 0x004DFBAA: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC34)); /* 0x004DFBAC: mov cx, word ptr [0x84bc34] */
    /* test ecx, ecx */ /* 0x004DFBB3: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004DFC12; /* 0x004DFBB5: jne 0x4dfc12 */

L_004DFBB7:
    edx = 0; /* 0x004DFBB7: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC42)); /* 0x004DFBB9: mov dx, word ptr [0x84bc42] */
    PUSH32(esp, edx); /* 0x004DFBC0: push edx */
    eax = 0; /* 0x004DFBC1: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC40)); /* 0x004DFBC3: mov ax, word ptr [0x84bc40] */
    PUSH32(esp, eax); /* 0x004DFBC9: push eax */
    ecx = 0; /* 0x004DFBCA: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC3E)); /* 0x004DFBCC: mov cx, word ptr [0x84bc3e] */
    PUSH32(esp, ecx); /* 0x004DFBD3: push ecx */
    edx = 0; /* 0x004DFBD4: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC3C)); /* 0x004DFBD6: mov dx, word ptr [0x84bc3c] */
    PUSH32(esp, edx); /* 0x004DFBDD: push edx */
    PUSH32(esp, 0); /* 0x004DFBDE: push 0 */
    eax = 0; /* 0x004DFBE0: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC38)); /* 0x004DFBE2: mov ax, word ptr [0x84bc38] */
    PUSH32(esp, eax); /* 0x004DFBE8: push eax */
    ecx = 0; /* 0x004DFBE9: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC3A)); /* 0x004DFBEB: mov cx, word ptr [0x84bc3a] */
    PUSH32(esp, ecx); /* 0x004DFBF2: push ecx */
    edx = 0; /* 0x004DFBF3: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC36)); /* 0x004DFBF5: mov dx, word ptr [0x84bc36] */
    PUSH32(esp, edx); /* 0x004DFBFC: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004DFBFD: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x14); /* 0x004DFC00: mov ecx, dword ptr [eax + 0x14] */
    PUSH32(esp, ecx); /* 0x004DFC03: push ecx */
    PUSH32(esp, 1); /* 0x004DFC04: push 1 */
    PUSH32(esp, 0); /* 0x004DFC06: push 0 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFC08: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFC0D: add esp, 0x2c */
    goto L_004DFC63; /* 0x004DFC10: jmp 0x4dfc63 */

L_004DFC12:
    edx = 0; /* 0x004DFC12: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC42)); /* 0x004DFC14: mov dx, word ptr [0x84bc42] */
    PUSH32(esp, edx); /* 0x004DFC1B: push edx */
    eax = 0; /* 0x004DFC1C: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC40)); /* 0x004DFC1E: mov ax, word ptr [0x84bc40] */
    PUSH32(esp, eax); /* 0x004DFC24: push eax */
    ecx = 0; /* 0x004DFC25: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC3E)); /* 0x004DFC27: mov cx, word ptr [0x84bc3e] */
    PUSH32(esp, ecx); /* 0x004DFC2E: push ecx */
    edx = 0; /* 0x004DFC2F: xor edx, edx */
    SET_LO16(edx, MEM16(0x84BC3C)); /* 0x004DFC31: mov dx, word ptr [0x84bc3c] */
    PUSH32(esp, edx); /* 0x004DFC38: push edx */
    eax = 0; /* 0x004DFC39: xor eax, eax */
    SET_LO16(eax, MEM16(0x84BC3A)); /* 0x004DFC3B: mov ax, word ptr [0x84bc3a] */
    PUSH32(esp, eax); /* 0x004DFC41: push eax */
    PUSH32(esp, 0); /* 0x004DFC42: push 0 */
    PUSH32(esp, 0); /* 0x004DFC44: push 0 */
    ecx = 0; /* 0x004DFC46: xor ecx, ecx */
    SET_LO16(ecx, MEM16(0x84BC36)); /* 0x004DFC48: mov cx, word ptr [0x84bc36] */
    PUSH32(esp, ecx); /* 0x004DFC4F: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004DFC50: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x14); /* 0x004DFC53: mov eax, dword ptr [edx + 0x14] */
    PUSH32(esp, eax); /* 0x004DFC56: push eax */
    PUSH32(esp, 0); /* 0x004DFC57: push 0 */
    PUSH32(esp, 0); /* 0x004DFC59: push 0 */
    RECOMP_CALL(sub_004DFDB0); /* 0x004DFC5B: call 0x4dfdb0 */
    esp = esp + 0x2Cu; /* 0x004DFC60: add esp, 0x2c */

L_004DFC63:
    goto L_004DFCAB; /* 0x004DFC63: jmp 0x4dfcab */

L_004DFCAB:
    edx = MEM32(0x50B95C); /* 0x004DFCAB: mov edx, dword ptr [0x50b95c] */
    /* cmp edx, MEM32(0x50B96C) */ /* 0x004DFCB1: cmp edx, dword ptr [0x50b96c] */
    if (CMP_GE(edx, MEM32(0x50B96C))) goto L_004DFD04; /* 0x004DFCB7: jge 0x4dfd04 */

L_004DFCB9:
    eax = MEM32(ebp + 0x8); /* 0x004DFCB9: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x1C); /* 0x004DFCBC: mov ecx, dword ptr [eax + 0x1c] */
    /* cmp ecx, MEM32(0x50B95C) */ /* 0x004DFCBF: cmp ecx, dword ptr [0x50b95c] */
    if (CMP_L(ecx, MEM32(0x50B95C))) goto L_004DFCD5; /* 0x004DFCC5: jl 0x4dfcd5 */

L_004DFCC7:
    edx = MEM32(ebp + 0x8); /* 0x004DFCC7: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x1C); /* 0x004DFCCA: mov eax, dword ptr [edx + 0x1c] */
    /* cmp eax, MEM32(0x50B96C) */ /* 0x004DFCCD: cmp eax, dword ptr [0x50b96c] */
    if (CMP_LE(eax, MEM32(0x50B96C))) goto L_004DFCDC; /* 0x004DFCD3: jle 0x4dfcdc */

L_004DFCD5:
    eax = 0; /* 0x004DFCD5: xor eax, eax */
    goto L_004DFDA6; /* 0x004DFCD7: jmp 0x4dfda6 */

L_004DFCDC:
    ecx = MEM32(ebp + 0x8); /* 0x004DFCDC: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004DFCDF: mov edx, dword ptr [ecx + 0x1c] */
    /* cmp edx, MEM32(0x50B95C) */ /* 0x004DFCE2: cmp edx, dword ptr [0x50b95c] */
    if (CMP_LE(edx, MEM32(0x50B95C))) goto L_004DFD02; /* 0x004DFCE8: jle 0x4dfd02 */

L_004DFCEA:
    eax = MEM32(ebp + 0x8); /* 0x004DFCEA: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x1C); /* 0x004DFCED: mov ecx, dword ptr [eax + 0x1c] */
    /* cmp ecx, MEM32(0x50B96C) */ /* 0x004DFCF0: cmp ecx, dword ptr [0x50b96c] */
    if (CMP_GE(ecx, MEM32(0x50B96C))) goto L_004DFD02; /* 0x004DFCF6: jge 0x4dfd02 */

L_004DFCF8:
    eax = 1; /* 0x004DFCF8: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFCFD: jmp 0x4dfda6 */

L_004DFD02:
    goto L_004DFD47; /* 0x004DFD02: jmp 0x4dfd47 */

L_004DFD04:
    edx = MEM32(ebp + 0x8); /* 0x004DFD04: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x1C); /* 0x004DFD07: mov eax, dword ptr [edx + 0x1c] */
    /* cmp eax, MEM32(0x50B96C) */ /* 0x004DFD0A: cmp eax, dword ptr [0x50b96c] */
    if (CMP_L(eax, MEM32(0x50B96C))) goto L_004DFD20; /* 0x004DFD10: jl 0x4dfd20 */

L_004DFD12:
    ecx = MEM32(ebp + 0x8); /* 0x004DFD12: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004DFD15: mov edx, dword ptr [ecx + 0x1c] */
    /* cmp edx, MEM32(0x50B95C) */ /* 0x004DFD18: cmp edx, dword ptr [0x50b95c] */
    if (CMP_LE(edx, MEM32(0x50B95C))) goto L_004DFD27; /* 0x004DFD1E: jle 0x4dfd27 */

L_004DFD20:
    eax = 1; /* 0x004DFD20: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFD25: jmp 0x4dfda6 */

L_004DFD27:
    eax = MEM32(ebp + 0x8); /* 0x004DFD27: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax + 0x1C); /* 0x004DFD2A: mov ecx, dword ptr [eax + 0x1c] */
    /* cmp ecx, MEM32(0x50B96C) */ /* 0x004DFD2D: cmp ecx, dword ptr [0x50b96c] */
    if (CMP_LE(ecx, MEM32(0x50B96C))) goto L_004DFD47; /* 0x004DFD33: jle 0x4dfd47 */

L_004DFD35:
    edx = MEM32(ebp + 0x8); /* 0x004DFD35: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x1C); /* 0x004DFD38: mov eax, dword ptr [edx + 0x1c] */
    /* cmp eax, MEM32(0x50B95C) */ /* 0x004DFD3B: cmp eax, dword ptr [0x50b95c] */
    if (CMP_GE(eax, MEM32(0x50B95C))) goto L_004DFD47; /* 0x004DFD41: jge 0x4dfd47 */

L_004DFD43:
    eax = 0; /* 0x004DFD43: xor eax, eax */
    goto L_004DFDA6; /* 0x004DFD45: jmp 0x4dfda6 */

L_004DFD47:
    ecx = MEM32(ebp + 0x8); /* 0x004DFD47: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x4); /* 0x004DFD4A: mov edx, dword ptr [ecx + 4] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFD4D: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x8); /* 0x004DFD50: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax); /* 0x004DFD53: mov ecx, dword ptr [eax] */
    ecx = ecx + edx; /* 0x004DFD55: add ecx, edx */
    edx = MEM32(ebp + 0x8); /* 0x004DFD57: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x8); /* 0x004DFD5A: mov eax, dword ptr [edx + 8] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0xE10u); /* 0x004DFD5D: imul eax, eax, 0xe10 */
    ecx = ecx + eax; /* 0x004DFD63: add ecx, eax */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3E8u); /* 0x004DFD65: imul ecx, ecx, 0x3e8 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DFD6B: mov dword ptr [ebp - 4], ecx */
    ecx = MEM32(ebp + 0x8); /* 0x004DFD6E: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004DFD71: mov edx, dword ptr [ecx + 0x1c] */
    /* cmp edx, MEM32(0x50B95C) */ /* 0x004DFD74: cmp edx, dword ptr [0x50b95c] */
    if (CMP_NE(edx, MEM32(0x50B95C))) goto L_004DFD92; /* 0x004DFD7A: jne 0x4dfd92 */

L_004DFD7C:
    eax = MEM32(ebp + (-0x4)); /* 0x004DFD7C: mov eax, dword ptr [ebp - 4] */
    /* cmp eax, MEM32(0x50B960) */ /* 0x004DFD7F: cmp eax, dword ptr [0x50b960] */
    if (CMP_L(eax, MEM32(0x50B960))) goto L_004DFD8E; /* 0x004DFD85: jl 0x4dfd8e */

L_004DFD87:
    eax = 1; /* 0x004DFD87: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFD8C: jmp 0x4dfda6 */

L_004DFD8E:
    eax = 0; /* 0x004DFD8E: xor eax, eax */
    goto L_004DFDA6; /* 0x004DFD90: jmp 0x4dfda6 */

L_004DFD92:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DFD92: mov ecx, dword ptr [ebp - 4] */
    /* cmp ecx, MEM32(0x50B970) */ /* 0x004DFD95: cmp ecx, dword ptr [0x50b970] */
    if (CMP_GE(ecx, MEM32(0x50B970))) goto L_004DFDA4; /* 0x004DFD9B: jge 0x4dfda4 */

L_004DFD9D:
    eax = 1; /* 0x004DFD9D: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFDA2: jmp 0x4dfda6 */

L_004DFDA4:
    eax = 0; /* 0x004DFDA4: xor eax, eax */

L_004DFDA6:
    esp = ebp; /* 0x004DFDA6: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFDA8: pop ebp */
    return; /* 0x004DFDA9: ret  */

}

void sub_004DFD00(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DFD00:
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004DFD00: add byte ptr [eax], al */
    goto L_004DFD47; /* 0x004DFD02: jmp 0x4dfd47 */

L_004DFD47:
    ecx = MEM32(ebp + 0x8); /* 0x004DFD47: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x4); /* 0x004DFD4A: mov edx, dword ptr [ecx + 4] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFD4D: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x8); /* 0x004DFD50: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax); /* 0x004DFD53: mov ecx, dword ptr [eax] */
    ecx = ecx + edx; /* 0x004DFD55: add ecx, edx */
    edx = MEM32(ebp + 0x8); /* 0x004DFD57: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(edx + 0x8); /* 0x004DFD5A: mov eax, dword ptr [edx + 8] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0xE10u); /* 0x004DFD5D: imul eax, eax, 0xe10 */
    ecx = ecx + eax; /* 0x004DFD63: add ecx, eax */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3E8u); /* 0x004DFD65: imul ecx, ecx, 0x3e8 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004DFD6B: mov dword ptr [ebp - 4], ecx */
    ecx = MEM32(ebp + 0x8); /* 0x004DFD6E: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004DFD71: mov edx, dword ptr [ecx + 0x1c] */
    /* cmp edx, MEM32(0x50B95C) */ /* 0x004DFD74: cmp edx, dword ptr [0x50b95c] */
    if (CMP_NE(edx, MEM32(0x50B95C))) goto L_004DFD92; /* 0x004DFD7A: jne 0x4dfd92 */

L_004DFD7C:
    eax = MEM32(ebp + (-0x4)); /* 0x004DFD7C: mov eax, dword ptr [ebp - 4] */
    /* cmp eax, MEM32(0x50B960) */ /* 0x004DFD7F: cmp eax, dword ptr [0x50b960] */
    if (CMP_L(eax, MEM32(0x50B960))) goto L_004DFD8E; /* 0x004DFD85: jl 0x4dfd8e */

L_004DFD87:
    eax = 1; /* 0x004DFD87: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFD8C: jmp 0x4dfda6 */

L_004DFD8E:
    eax = 0; /* 0x004DFD8E: xor eax, eax */
    goto L_004DFDA6; /* 0x004DFD90: jmp 0x4dfda6 */

L_004DFD92:
    ecx = MEM32(ebp + (-0x4)); /* 0x004DFD92: mov ecx, dword ptr [ebp - 4] */
    /* cmp ecx, MEM32(0x50B970) */ /* 0x004DFD95: cmp ecx, dword ptr [0x50b970] */
    if (CMP_GE(ecx, MEM32(0x50B970))) goto L_004DFDA4; /* 0x004DFD9B: jge 0x4dfda4 */

L_004DFD9D:
    eax = 1; /* 0x004DFD9D: mov eax, 1 */
    goto L_004DFDA6; /* 0x004DFDA2: jmp 0x4dfda6 */

L_004DFDA4:
    eax = 0; /* 0x004DFDA4: xor eax, eax */

L_004DFDA6:
    esp = ebp; /* 0x004DFDA6: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFDA8: pop ebp */
    return; /* 0x004DFDA9: ret  */

}

void sub_004DFEAA(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DFEAA:
    { uint32_t _tmp = ebp; /* 0x004DFEAA: xchg ebp, eax */
      ebp = eax;
      eax = _tmp; }
    SET_LO8(eax, MEM8(esi)); esi += _df; /* 0x004DFEAB: lodsb al, byte ptr [esi] */
    ecx = 0x45890050u; /* 0x004DFEAC: mov ecx, 0x45890050 */
    /* UNIMPLEMENTED: in al, dx */ /* 0x004DFEB1: in al, dx */
    ecx = MEM32(ebp + (-0x14)); /* 0x004DFEB2: mov ecx, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DFEB5: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DFEB8: mov edx, dword ptr [ebp - 8] */
    edx = edx + MEM32(ebp + 0x20); /* 0x004DFEBB: add edx, dword ptr [ebp + 0x20] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DFEBE: mov dword ptr [ebp - 8], edx */
    /* cmp MEM32(ebp + 0x8), 1 */ /* 0x004DFEC1: cmp dword ptr [ebp + 8], 1 */
    if (CMP_NE(MEM32(ebp + 0x8), 1)) goto L_004DFF01; /* 0x004DFEC5: jne 0x4dff01 */

L_004DFEC7:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFEC7: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B95C) = eax; /* 0x004DFECA: mov dword ptr [0x50b95c], eax */
    ecx = MEM32(ebp + 0x24); /* 0x004DFECF: mov ecx, dword ptr [ebp + 0x24] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004DFED2: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + 0x28); /* 0x004DFED5: mov edx, dword ptr [ebp + 0x28] */
    edx = edx + ecx; /* 0x004DFED8: add edx, ecx */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFEDA: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x2C); /* 0x004DFEDD: mov eax, dword ptr [ebp + 0x2c] */
    eax = eax + edx; /* 0x004DFEE0: add eax, edx */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3E8u); /* 0x004DFEE2: imul eax, eax, 0x3e8 */
    ecx = MEM32(ebp + 0x30); /* 0x004DFEE8: mov ecx, dword ptr [ebp + 0x30] */
    ecx = ecx + eax; /* 0x004DFEEB: add ecx, eax */
    MEM32(0x50B960) = ecx; /* 0x004DFEED: mov dword ptr [0x50b960], ecx */
    edx = MEM32(ebp + 0x10); /* 0x004DFEF3: mov edx, dword ptr [ebp + 0x10] */
    MEM32(0x50B958) = edx; /* 0x004DFEF6: mov dword ptr [0x50b958], edx */
    goto L_004DFFA4; /* 0x004DFEFC: jmp 0x4dffa4 */

L_004DFF01:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFF01: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B96C) = eax; /* 0x004DFF04: mov dword ptr [0x50b96c], eax */
    ecx = MEM32(ebp + 0x24); /* 0x004DFF09: mov ecx, dword ptr [ebp + 0x24] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004DFF0C: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + 0x28); /* 0x004DFF0F: mov edx, dword ptr [ebp + 0x28] */
    edx = edx + ecx; /* 0x004DFF12: add edx, ecx */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFF14: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x2C); /* 0x004DFF17: mov eax, dword ptr [ebp + 0x2c] */
    eax = eax + edx; /* 0x004DFF1A: add eax, edx */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3E8u); /* 0x004DFF1C: imul eax, eax, 0x3e8 */
    ecx = MEM32(ebp + 0x30); /* 0x004DFF22: mov ecx, dword ptr [ebp + 0x30] */
    ecx = ecx + eax; /* 0x004DFF25: add ecx, eax */
    MEM32(0x50B970) = ecx; /* 0x004DFF27: mov dword ptr [0x50b970], ecx */
    edx = MEM32(0x50B8C8); /* 0x004DFF2D: mov edx, dword ptr [0x50b8c8] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3E8u); /* 0x004DFF33: imul edx, edx, 0x3e8 */
    eax = MEM32(0x50B970); /* 0x004DFF39: mov eax, dword ptr [0x50b970] */
    eax = eax + edx; /* 0x004DFF3E: add eax, edx */
    MEM32(0x50B970) = eax; /* 0x004DFF40: mov dword ptr [0x50b970], eax */
    /* cmp MEM32(0x50B970), 0 */ /* 0x004DFF45: cmp dword ptr [0x50b970], 0 */
    if (CMP_GE(MEM32(0x50B970), 0)) goto L_004DFF71; /* 0x004DFF4C: jge 0x4dff71 */

L_004DFF4E:
    ecx = MEM32(0x50B970); /* 0x004DFF4E: mov ecx, dword ptr [0x50b970] */
    ecx = ecx + 0x05265C00u; /* 0x004DFF54: add ecx, 0x5265c00 */
    MEM32(0x50B970) = ecx; /* 0x004DFF5A: mov dword ptr [0x50b970], ecx */
    edx = MEM32(0x50B970); /* 0x004DFF60: mov edx, dword ptr [0x50b970] */
    edx = edx - 1; /* 0x004DFF66: sub edx, 1 */
    MEM32(0x50B970) = edx; /* 0x004DFF69: mov dword ptr [0x50b970], edx */
    goto L_004DFF9B; /* 0x004DFF6F: jmp 0x4dff9b */

L_004DFF71:
    /* cmp MEM32(0x50B970), 0x05265C00u */ /* 0x004DFF71: cmp dword ptr [0x50b970], 0x5265c00 */
    if (CMP_L(MEM32(0x50B970), 0x05265C00u)) goto L_004DFF9B; /* 0x004DFF7B: jl 0x4dff9b */

L_004DFF7D:
    eax = MEM32(0x50B970); /* 0x004DFF7D: mov eax, dword ptr [0x50b970] */
    eax = eax - 0x05265C00u; /* 0x004DFF82: sub eax, 0x5265c00 */
    MEM32(0x50B970) = eax; /* 0x004DFF87: mov dword ptr [0x50b970], eax */
    ecx = MEM32(0x50B970); /* 0x004DFF8C: mov ecx, dword ptr [0x50b970] */
    ecx = ecx + 1; /* 0x004DFF92: add ecx, 1 */
    MEM32(0x50B970) = ecx; /* 0x004DFF95: mov dword ptr [0x50b970], ecx */

L_004DFF9B:
    edx = MEM32(ebp + 0x10); /* 0x004DFF9B: mov edx, dword ptr [ebp + 0x10] */
    MEM32(0x50B968) = edx; /* 0x004DFF9E: mov dword ptr [0x50b968], edx */

L_004DFFA4:
    esp = ebp; /* 0x004DFFA4: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFFA6: pop ebp */
    return; /* 0x004DFFA7: ret  */

}

void sub_004DFEB4(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DFEB4:
    /* UNIMPLEMENTED: in al, dx */ /* 0x004DFEB4: in al, dx */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004DFEB5: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004DFEB8: mov edx, dword ptr [ebp - 8] */
    edx = edx + MEM32(ebp + 0x20); /* 0x004DFEBB: add edx, dword ptr [ebp + 0x20] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DFEBE: mov dword ptr [ebp - 8], edx */
    /* cmp MEM32(ebp + 0x8), 1 */ /* 0x004DFEC1: cmp dword ptr [ebp + 8], 1 */
    if (CMP_NE(MEM32(ebp + 0x8), 1)) goto L_004DFF01; /* 0x004DFEC5: jne 0x4dff01 */

L_004DFEC7:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFEC7: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B95C) = eax; /* 0x004DFECA: mov dword ptr [0x50b95c], eax */
    ecx = MEM32(ebp + 0x24); /* 0x004DFECF: mov ecx, dword ptr [ebp + 0x24] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004DFED2: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + 0x28); /* 0x004DFED5: mov edx, dword ptr [ebp + 0x28] */
    edx = edx + ecx; /* 0x004DFED8: add edx, ecx */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFEDA: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x2C); /* 0x004DFEDD: mov eax, dword ptr [ebp + 0x2c] */
    eax = eax + edx; /* 0x004DFEE0: add eax, edx */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3E8u); /* 0x004DFEE2: imul eax, eax, 0x3e8 */
    ecx = MEM32(ebp + 0x30); /* 0x004DFEE8: mov ecx, dword ptr [ebp + 0x30] */
    ecx = ecx + eax; /* 0x004DFEEB: add ecx, eax */
    MEM32(0x50B960) = ecx; /* 0x004DFEED: mov dword ptr [0x50b960], ecx */
    edx = MEM32(ebp + 0x10); /* 0x004DFEF3: mov edx, dword ptr [ebp + 0x10] */
    MEM32(0x50B958) = edx; /* 0x004DFEF6: mov dword ptr [0x50b958], edx */
    goto L_004DFFA4; /* 0x004DFEFC: jmp 0x4dffa4 */

L_004DFF01:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFF01: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B96C) = eax; /* 0x004DFF04: mov dword ptr [0x50b96c], eax */
    ecx = MEM32(ebp + 0x24); /* 0x004DFF09: mov ecx, dword ptr [ebp + 0x24] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004DFF0C: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + 0x28); /* 0x004DFF0F: mov edx, dword ptr [ebp + 0x28] */
    edx = edx + ecx; /* 0x004DFF12: add edx, ecx */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFF14: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x2C); /* 0x004DFF17: mov eax, dword ptr [ebp + 0x2c] */
    eax = eax + edx; /* 0x004DFF1A: add eax, edx */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3E8u); /* 0x004DFF1C: imul eax, eax, 0x3e8 */
    ecx = MEM32(ebp + 0x30); /* 0x004DFF22: mov ecx, dword ptr [ebp + 0x30] */
    ecx = ecx + eax; /* 0x004DFF25: add ecx, eax */
    MEM32(0x50B970) = ecx; /* 0x004DFF27: mov dword ptr [0x50b970], ecx */
    edx = MEM32(0x50B8C8); /* 0x004DFF2D: mov edx, dword ptr [0x50b8c8] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3E8u); /* 0x004DFF33: imul edx, edx, 0x3e8 */
    eax = MEM32(0x50B970); /* 0x004DFF39: mov eax, dword ptr [0x50b970] */
    eax = eax + edx; /* 0x004DFF3E: add eax, edx */
    MEM32(0x50B970) = eax; /* 0x004DFF40: mov dword ptr [0x50b970], eax */
    /* cmp MEM32(0x50B970), 0 */ /* 0x004DFF45: cmp dword ptr [0x50b970], 0 */
    if (CMP_GE(MEM32(0x50B970), 0)) goto L_004DFF71; /* 0x004DFF4C: jge 0x4dff71 */

L_004DFF4E:
    ecx = MEM32(0x50B970); /* 0x004DFF4E: mov ecx, dword ptr [0x50b970] */
    ecx = ecx + 0x05265C00u; /* 0x004DFF54: add ecx, 0x5265c00 */
    MEM32(0x50B970) = ecx; /* 0x004DFF5A: mov dword ptr [0x50b970], ecx */
    edx = MEM32(0x50B970); /* 0x004DFF60: mov edx, dword ptr [0x50b970] */
    edx = edx - 1; /* 0x004DFF66: sub edx, 1 */
    MEM32(0x50B970) = edx; /* 0x004DFF69: mov dword ptr [0x50b970], edx */
    goto L_004DFF9B; /* 0x004DFF6F: jmp 0x4dff9b */

L_004DFF71:
    /* cmp MEM32(0x50B970), 0x05265C00u */ /* 0x004DFF71: cmp dword ptr [0x50b970], 0x5265c00 */
    if (CMP_L(MEM32(0x50B970), 0x05265C00u)) goto L_004DFF9B; /* 0x004DFF7B: jl 0x4dff9b */

L_004DFF7D:
    eax = MEM32(0x50B970); /* 0x004DFF7D: mov eax, dword ptr [0x50b970] */
    eax = eax - 0x05265C00u; /* 0x004DFF82: sub eax, 0x5265c00 */
    MEM32(0x50B970) = eax; /* 0x004DFF87: mov dword ptr [0x50b970], eax */
    ecx = MEM32(0x50B970); /* 0x004DFF8C: mov ecx, dword ptr [0x50b970] */
    ecx = ecx + 1; /* 0x004DFF92: add ecx, 1 */
    MEM32(0x50B970) = ecx; /* 0x004DFF95: mov dword ptr [0x50b970], ecx */

L_004DFF9B:
    edx = MEM32(ebp + 0x10); /* 0x004DFF9B: mov edx, dword ptr [ebp + 0x10] */
    MEM32(0x50B968) = edx; /* 0x004DFF9E: mov dword ptr [0x50b968], edx */

L_004DFFA4:
    esp = ebp; /* 0x004DFFA4: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFFA6: pop ebp */
    return; /* 0x004DFFA7: ret  */

}

void sub_004DFEBA(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DFEBA:
    _cf = 0; /* 0x004DFEBA: clc  */
    edx = edx + MEM32(ebp + 0x20); /* 0x004DFEBB: add edx, dword ptr [ebp + 0x20] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004DFEBE: mov dword ptr [ebp - 8], edx */
    /* cmp MEM32(ebp + 0x8), 1 */ /* 0x004DFEC1: cmp dword ptr [ebp + 8], 1 */
    if (CMP_NE(MEM32(ebp + 0x8), 1)) goto L_004DFF01; /* 0x004DFEC5: jne 0x4dff01 */

L_004DFEC7:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFEC7: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B95C) = eax; /* 0x004DFECA: mov dword ptr [0x50b95c], eax */
    ecx = MEM32(ebp + 0x24); /* 0x004DFECF: mov ecx, dword ptr [ebp + 0x24] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004DFED2: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + 0x28); /* 0x004DFED5: mov edx, dword ptr [ebp + 0x28] */
    edx = edx + ecx; /* 0x004DFED8: add edx, ecx */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFEDA: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x2C); /* 0x004DFEDD: mov eax, dword ptr [ebp + 0x2c] */
    eax = eax + edx; /* 0x004DFEE0: add eax, edx */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3E8u); /* 0x004DFEE2: imul eax, eax, 0x3e8 */
    ecx = MEM32(ebp + 0x30); /* 0x004DFEE8: mov ecx, dword ptr [ebp + 0x30] */
    ecx = ecx + eax; /* 0x004DFEEB: add ecx, eax */
    MEM32(0x50B960) = ecx; /* 0x004DFEED: mov dword ptr [0x50b960], ecx */
    edx = MEM32(ebp + 0x10); /* 0x004DFEF3: mov edx, dword ptr [ebp + 0x10] */
    MEM32(0x50B958) = edx; /* 0x004DFEF6: mov dword ptr [0x50b958], edx */
    goto L_004DFFA4; /* 0x004DFEFC: jmp 0x4dffa4 */

L_004DFF01:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFF01: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B96C) = eax; /* 0x004DFF04: mov dword ptr [0x50b96c], eax */
    ecx = MEM32(ebp + 0x24); /* 0x004DFF09: mov ecx, dword ptr [ebp + 0x24] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004DFF0C: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + 0x28); /* 0x004DFF0F: mov edx, dword ptr [ebp + 0x28] */
    edx = edx + ecx; /* 0x004DFF12: add edx, ecx */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFF14: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x2C); /* 0x004DFF17: mov eax, dword ptr [ebp + 0x2c] */
    eax = eax + edx; /* 0x004DFF1A: add eax, edx */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3E8u); /* 0x004DFF1C: imul eax, eax, 0x3e8 */
    ecx = MEM32(ebp + 0x30); /* 0x004DFF22: mov ecx, dword ptr [ebp + 0x30] */
    ecx = ecx + eax; /* 0x004DFF25: add ecx, eax */
    MEM32(0x50B970) = ecx; /* 0x004DFF27: mov dword ptr [0x50b970], ecx */
    edx = MEM32(0x50B8C8); /* 0x004DFF2D: mov edx, dword ptr [0x50b8c8] */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3E8u); /* 0x004DFF33: imul edx, edx, 0x3e8 */
    eax = MEM32(0x50B970); /* 0x004DFF39: mov eax, dword ptr [0x50b970] */
    eax = eax + edx; /* 0x004DFF3E: add eax, edx */
    MEM32(0x50B970) = eax; /* 0x004DFF40: mov dword ptr [0x50b970], eax */
    /* cmp MEM32(0x50B970), 0 */ /* 0x004DFF45: cmp dword ptr [0x50b970], 0 */
    if (CMP_GE(MEM32(0x50B970), 0)) goto L_004DFF71; /* 0x004DFF4C: jge 0x4dff71 */

L_004DFF4E:
    ecx = MEM32(0x50B970); /* 0x004DFF4E: mov ecx, dword ptr [0x50b970] */
    ecx = ecx + 0x05265C00u; /* 0x004DFF54: add ecx, 0x5265c00 */
    MEM32(0x50B970) = ecx; /* 0x004DFF5A: mov dword ptr [0x50b970], ecx */
    edx = MEM32(0x50B970); /* 0x004DFF60: mov edx, dword ptr [0x50b970] */
    edx = edx - 1; /* 0x004DFF66: sub edx, 1 */
    MEM32(0x50B970) = edx; /* 0x004DFF69: mov dword ptr [0x50b970], edx */
    goto L_004DFF9B; /* 0x004DFF6F: jmp 0x4dff9b */

L_004DFF71:
    /* cmp MEM32(0x50B970), 0x05265C00u */ /* 0x004DFF71: cmp dword ptr [0x50b970], 0x5265c00 */
    if (CMP_L(MEM32(0x50B970), 0x05265C00u)) goto L_004DFF9B; /* 0x004DFF7B: jl 0x4dff9b */

L_004DFF7D:
    eax = MEM32(0x50B970); /* 0x004DFF7D: mov eax, dword ptr [0x50b970] */
    eax = eax - 0x05265C00u; /* 0x004DFF82: sub eax, 0x5265c00 */
    MEM32(0x50B970) = eax; /* 0x004DFF87: mov dword ptr [0x50b970], eax */
    ecx = MEM32(0x50B970); /* 0x004DFF8C: mov ecx, dword ptr [0x50b970] */
    ecx = ecx + 1; /* 0x004DFF92: add ecx, 1 */
    MEM32(0x50B970) = ecx; /* 0x004DFF95: mov dword ptr [0x50b970], ecx */

L_004DFF9B:
    edx = MEM32(ebp + 0x10); /* 0x004DFF9B: mov edx, dword ptr [ebp + 0x10] */
    MEM32(0x50B968) = edx; /* 0x004DFF9E: mov dword ptr [0x50b968], edx */

L_004DFFA4:
    esp = ebp; /* 0x004DFFA4: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFFA6: pop ebp */
    return; /* 0x004DFFA7: ret  */

}

void sub_004DFEC7(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DFEC7:
    eax = MEM32(ebp + (-0x8)); /* 0x004DFEC7: mov eax, dword ptr [ebp - 8] */
    MEM32(0x50B95C) = eax; /* 0x004DFECA: mov dword ptr [0x50b95c], eax */
    ecx = MEM32(ebp + 0x24); /* 0x004DFECF: mov ecx, dword ptr [ebp + 0x24] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004DFED2: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + 0x28); /* 0x004DFED5: mov edx, dword ptr [ebp + 0x28] */
    edx = edx + ecx; /* 0x004DFED8: add edx, ecx */
    edx = (uint32_t)((int32_t)edx * (int32_t)0x3Cu); /* 0x004DFEDA: imul edx, edx, 0x3c */
    eax = MEM32(ebp + 0x2C); /* 0x004DFEDD: mov eax, dword ptr [ebp + 0x2c] */
    eax = eax + edx; /* 0x004DFEE0: add eax, edx */
    eax = (uint32_t)((int32_t)eax * (int32_t)0x3E8u); /* 0x004DFEE2: imul eax, eax, 0x3e8 */
    ecx = MEM32(ebp + 0x30); /* 0x004DFEE8: mov ecx, dword ptr [ebp + 0x30] */
    ecx = ecx + eax; /* 0x004DFEEB: add ecx, eax */
    MEM32(0x50B960) = ecx; /* 0x004DFEED: mov dword ptr [0x50b960], ecx */
    edx = MEM32(ebp + 0x10); /* 0x004DFEF3: mov edx, dword ptr [ebp + 0x10] */
    MEM32(0x50B958) = edx; /* 0x004DFEF6: mov dword ptr [0x50b958], edx */
    goto L_004DFFA4; /* 0x004DFEFC: jmp 0x4dffa4 */

L_004DFFA4:
    esp = ebp; /* 0x004DFFA4: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004DFFA6: pop ebp */
    return; /* 0x004DFFA7: ret  */

}

void sub_004DFECD(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004DFECD:
    PUSH32(esp, eax); /* 0x004DFECD: push eax */
    MEM8(ebx + (-0x3694DBB3)) = (uint8_t)(MEM8(ebx + (-0x3694DBB3)) + LO8(ecx)); /* 0x004DFECE: add byte ptr [ebx - 0x3694dbb3], cl */
    /* cmp LO8(eax), 0x8Bu */ /* 0x004DFED4: cmp al, 0x8b */
    PUSH32(esp, ebp); /* 0x004DFED6: push ebp */
    MEM8(ebx) = (uint8_t)(MEM8(ebx) - LO8(eax)); /* 0x004DFED7: sub byte ptr [ebx], al */
    MEM32(ebx + (-0x2E)) = MEM32(ebx + (-0x2E)) >> 1; /* 0x004DFED9: shr dword ptr [ebx - 0x2e], 1 */
    /* cmp LO8(eax), 0x8Bu */ /* 0x004DFEDC: cmp al, 0x8b */
    ebp = ebp + 1; /* 0x004DFEDE: inc ebp */
    SET_LO8(eax, LO8(eax) - 3); /* 0x004DFEDF: sub al, 3 */
    esp += 49257; return; /* 0x004DFEE1: ret 0xc069 */

}

void sub_004E0410(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E0410:
    PUSH32(esp, ebp); /* 0x004E0410: push ebp */
    ebp = esp; /* 0x004E0411: mov ebp, esp */
    PUSH32(esp, ecx); /* 0x004E0413: push ecx */
    MEM32(ebp + (-0x4)) = 1; /* 0x004E0414: mov dword ptr [ebp - 4], 1 */
    eax = MEM32(ebp + 0x8); /* 0x004E041B: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004E041E: push eax */
    RECOMP_ICALL(MEM32(0x8586C8)); /* 0x004E041F: call dword ptr [0x8586c8] */
    /* test eax, eax */ /* 0x004E0425: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004E0430; /* 0x004E0427: je 0x4e0430 */

L_004E0429:
    MEM32(ebp + (-0x4)) = 0; /* 0x004E0429: mov dword ptr [ebp - 4], 0 */

L_004E0430:
    eax = MEM32(ebp + (-0x4)); /* 0x004E0430: mov eax, dword ptr [ebp - 4] */
    esp = ebp; /* 0x004E0433: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E0435: pop ebp */
    return; /* 0x004E0436: ret  */

}

void sub_004E0580(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E0580:
    MEM32(eax) = MEM32(eax) + eax; /* 0x004E0580: add dword ptr [eax], eax */
    SET_LO8(eax, LO8(eax) + HI8(ecx)); /* 0x004E0582: add al, ch */
    MEM8(eax) = (uint8_t)(MEM8(eax) - HI8(eax) - _cf); /* 0x004E0584: sbb byte ptr [eax], ah */

}

void sub_004E0860(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E0860:
    /* cmp MEM32(ebp + (-0x8)), 0xFFFFFFFFu */ /* 0x004E0860: cmp dword ptr [ebp - 8], -1 */
    if (CMP_NE(MEM32(ebp + (-0x8)), 0xFFFFFFFFu)) goto L_004E087F; /* 0x004E0864: jne 0x4e087f */

L_004E0866:
    MEM32(0x84B7AC) = 0x18u; /* 0x004E0866: mov dword ptr [0x84b7ac], 0x18 */
    MEM32(0x84B7B0) = 0; /* 0x004E0870: mov dword ptr [0x84b7b0], 0 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E087A: or eax, 0xffffffff */
    goto L_004E08B4; /* 0x004E087D: jmp 0x4e08b4 */

L_004E087F:
    ecx = MEM32(ebp + 0x8); /* 0x004E087F: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004E0882: push ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004E0883: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004E0886: push edx */
    RECOMP_CALL(sub_004E0600); /* 0x004E0887: call 0x4e0600 */
    esp = esp + 8; /* 0x004E088C: add esp, 8 */
    SET_LO8(eax, MEM8(ebp + (-0xC))); /* 0x004E088F: mov al, byte ptr [ebp - 0xc] */
    SET_LO8(eax, LO8(eax) | 1); /* 0x004E0892: or al, 1 */
    MEM8(ebp + (-0xC)) = (uint8_t)(LO8(eax)); /* 0x004E0894: mov byte ptr [ebp - 0xc], al */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E0897: mov ecx, dword ptr [ebp - 8] */
    ecx = (uint32_t)((int32_t)ecx >> 5); /* 0x004E089A: sar ecx, 5 */
    edx = MEM32(ebp + (-0x8)); /* 0x004E089D: mov edx, dword ptr [ebp - 8] */
    edx = edx & 0x1Fu; /* 0x004E08A0: and edx, 0x1f */
    eax = MEM32(ecx * 4 + 0x855C60); /* 0x004E08A3: mov eax, dword ptr [ecx*4 + 0x855c60] */
    SET_LO8(ecx, MEM8(ebp + (-0xC))); /* 0x004E08AA: mov cl, byte ptr [ebp - 0xc] */
    MEM8(eax + edx * 8 + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004E08AD: mov byte ptr [eax + edx*8 + 4], cl */
    eax = MEM32(ebp + (-0x8)); /* 0x004E08B1: mov eax, dword ptr [ebp - 8] */

L_004E08B4:
    esp = ebp; /* 0x004E08B4: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E08B6: pop ebp */
    return; /* 0x004E08B7: ret  */

}

void sub_004E08C0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E08C0:
    PUSH32(esp, ebp); /* 0x004E08C0: push ebp */
    ebp = esp; /* 0x004E08C1: mov ebp, esp */
    esp = esp - 8; /* 0x004E08C3: sub esp, 8 */
    eax = ebp + 0x10; /* 0x004E08C6: lea eax, [ebp + 0x10] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E08C9: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E08CC: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx + 4; /* 0x004E08CF: add ecx, 4 */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004E08D2: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004E08D5: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + (-0x4)); /* 0x004E08D8: mov eax, dword ptr [edx - 4] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E08DB: mov dword ptr [ebp - 4], eax */
    MEM32(ebp + (-0x8)) = 0; /* 0x004E08DE: mov dword ptr [ebp - 8], 0 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E08E5: mov ecx, dword ptr [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004E08E8: push ecx */
    PUSH32(esp, 0x40u); /* 0x004E08E9: push 0x40 */
    edx = MEM32(ebp + 0xC); /* 0x004E08EB: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004E08EE: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004E08EF: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004E08F2: push eax */
    RECOMP_CALL(sub_004E0900); /* 0x004E08F3: call 0x4e0900 */
    esp = esp + 0x10u; /* 0x004E08F8: add esp, 0x10 */
    esp = ebp; /* 0x004E08FB: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E08FD: pop ebp */
    return; /* 0x004E08FE: ret  */

}

void sub_004E0B90(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E0B90:
    if (/* no flag state for je */ _cf) goto L_004E0B9E; /* 0x004E0B90: je 0x4e0b9e */

L_004E0B92:
    edx = MEM32(ebp + (-0x28)); /* 0x004E0B92: mov edx, dword ptr [ebp - 0x28] */
    edx = edx | 0x10000000u; /* 0x004E0B95: or edx, 0x10000000 */
    MEM32(ebp + (-0x28)) = edx; /* 0x004E0B9B: mov dword ptr [ebp - 0x28], edx */

L_004E0B9E:
    RECOMP_CALL(sub_004E04D0); /* 0x004E0B9E: call 0x4e04d0 */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E0BA3: mov dword ptr [ebp - 0x14], eax */
    /* cmp MEM32(ebp + (-0x14)), 0xFFFFFFFFu */ /* 0x004E0BA6: cmp dword ptr [ebp - 0x14], -1 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0xFFFFFFFFu)) goto L_004E0BC8; /* 0x004E0BAA: jne 0x4e0bc8 */

L_004E0BAC:
    MEM32(0x84B7AC) = 0x18u; /* 0x004E0BAC: mov dword ptr [0x84b7ac], 0x18 */
    MEM32(0x84B7B0) = 0; /* 0x004E0BB6: mov dword ptr [0x84b7b0], 0 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0BC0: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0BC3: jmp 0x4e0db2 */

L_004E0BC8:
    PUSH32(esp, 0); /* 0x004E0BC8: push 0 */
    eax = MEM32(ebp + (-0x28)); /* 0x004E0BCA: mov eax, dword ptr [ebp - 0x28] */
    PUSH32(esp, eax); /* 0x004E0BCD: push eax */
    ecx = MEM32(ebp + (-0x18)); /* 0x004E0BCE: mov ecx, dword ptr [ebp - 0x18] */
    PUSH32(esp, ecx); /* 0x004E0BD1: push ecx */
    edx = ebp + (-0x24); /* 0x004E0BD2: lea edx, [ebp - 0x24] */
    PUSH32(esp, edx); /* 0x004E0BD5: push edx */
    eax = MEM32(ebp + (-0x8)); /* 0x004E0BD6: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E0BD9: push eax */
    ecx = MEM32(ebp + (-0x34)); /* 0x004E0BDA: mov ecx, dword ptr [ebp - 0x34] */
    PUSH32(esp, ecx); /* 0x004E0BDD: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E0BDE: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E0BE1: push edx */
    RECOMP_ICALL(MEM32(0x8586C0)); /* 0x004E0BE2: call dword ptr [0x8586c0] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E0BE8: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0xFFFFFFFFu */ /* 0x004E0BEB: cmp dword ptr [ebp - 4], -1 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0xFFFFFFFFu)) goto L_004E0C08; /* 0x004E0BEF: jne 0x4e0c08 */

L_004E0BF1:
    RECOMP_ICALL(MEM32(0x85867C)); /* 0x004E0BF1: call dword ptr [0x85867c] */
    PUSH32(esp, eax); /* 0x004E0BF7: push eax */
    RECOMP_CALL(sub_004E0440); /* 0x004E0BF8: call 0x4e0440 */
    esp = esp + 4; /* 0x004E0BFD: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0C00: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0C03: jmp 0x4e0db2 */

L_004E0C08:
    eax = MEM32(ebp + (-0x4)); /* 0x004E0C08: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004E0C0B: push eax */
    RECOMP_ICALL(MEM32(0x858700)); /* 0x004E0C0C: call dword ptr [0x858700] */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E0C12: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E0C15: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E0C3C; /* 0x004E0C19: jne 0x4e0c3c */

L_004E0C1B:
    ecx = MEM32(ebp + (-0x4)); /* 0x004E0C1B: mov ecx, dword ptr [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004E0C1E: push ecx */
    RECOMP_ICALL(MEM32(0x85869C)); /* 0x004E0C1F: call dword ptr [0x85869c] */
    RECOMP_ICALL(MEM32(0x85867C)); /* 0x004E0C25: call dword ptr [0x85867c] */
    PUSH32(esp, eax); /* 0x004E0C2B: push eax */
    RECOMP_CALL(sub_004E0440); /* 0x004E0C2C: call 0x4e0440 */
    esp = esp + 4; /* 0x004E0C31: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0C34: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0C37: jmp 0x4e0db2 */

L_004E0C3C:
    /* cmp MEM32(ebp + (-0xC)), 2 */ /* 0x004E0C3C: cmp dword ptr [ebp - 0xc], 2 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 2)) goto L_004E0C4D; /* 0x004E0C40: jne 0x4e0c4d */

L_004E0C42:
    SET_LO8(edx, MEM8(ebp + (-0x38))); /* 0x004E0C42: mov dl, byte ptr [ebp - 0x38] */
    SET_LO8(edx, LO8(edx) | 0x40u); /* 0x004E0C45: or dl, 0x40 */
    MEM8(ebp + (-0x38)) = (uint8_t)(LO8(edx)); /* 0x004E0C48: mov byte ptr [ebp - 0x38], dl */
    goto L_004E0C5B; /* 0x004E0C4B: jmp 0x4e0c5b */

L_004E0C4D:
    /* cmp MEM32(ebp + (-0xC)), 3 */ /* 0x004E0C4D: cmp dword ptr [ebp - 0xc], 3 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 3)) goto L_004E0C5B; /* 0x004E0C51: jne 0x4e0c5b */

L_004E0C53:
    SET_LO8(eax, MEM8(ebp + (-0x38))); /* 0x004E0C53: mov al, byte ptr [ebp - 0x38] */
    SET_LO8(eax, LO8(eax) | 8); /* 0x004E0C56: or al, 8 */
    MEM8(ebp + (-0x38)) = (uint8_t)(LO8(eax)); /* 0x004E0C58: mov byte ptr [ebp - 0x38], al */

L_004E0C5B:
    ecx = MEM32(ebp + (-0x4)); /* 0x004E0C5B: mov ecx, dword ptr [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004E0C5E: push ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004E0C5F: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0C62: push edx */
    RECOMP_CALL(sub_004E0600); /* 0x004E0C63: call 0x4e0600 */
    esp = esp + 8; /* 0x004E0C68: add esp, 8 */
    SET_LO8(eax, MEM8(ebp + (-0x38))); /* 0x004E0C6B: mov al, byte ptr [ebp - 0x38] */
    SET_LO8(eax, LO8(eax) | 1); /* 0x004E0C6E: or al, 1 */
    MEM8(ebp + (-0x38)) = (uint8_t)(LO8(eax)); /* 0x004E0C70: mov byte ptr [ebp - 0x38], al */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0C73: mov ecx, dword ptr [ebp - 0x14] */
    ecx = (uint32_t)((int32_t)ecx >> 5); /* 0x004E0C76: sar ecx, 5 */
    edx = MEM32(ebp + (-0x14)); /* 0x004E0C79: mov edx, dword ptr [ebp - 0x14] */
    edx = edx & 0x1Fu; /* 0x004E0C7C: and edx, 0x1f */
    eax = MEM32(ecx * 4 + 0x855C60); /* 0x004E0C7F: mov eax, dword ptr [ecx*4 + 0x855c60] */
    SET_LO8(ecx, MEM8(ebp + (-0x38))); /* 0x004E0C86: mov cl, byte ptr [ebp - 0x38] */
    MEM8(eax + edx * 8 + 0x4) = (uint8_t)(LO8(ecx)); /* 0x004E0C89: mov byte ptr [eax + edx*8 + 4], cl */
    edx = (int32_t)(int8_t)MEM8(ebp + (-0x38)); /* 0x004E0C8D: movsx edx, byte ptr [ebp - 0x38] */
    edx = edx & 0x48u; /* 0x004E0C91: and edx, 0x48 */
    /* test edx, edx */ /* 0x004E0C94: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004E0D69; /* 0x004E0C96: jne 0x4e0d69 */

L_004E0C9C:
    eax = (int32_t)(int8_t)MEM8(ebp + (-0x38)); /* 0x004E0C9C: movsx eax, byte ptr [ebp - 0x38] */
    eax = eax & 0x80u; /* 0x004E0CA0: and eax, 0x80 */
    /* test eax, eax */ /* 0x004E0CA5: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004E0D69; /* 0x004E0CA7: je 0x4e0d69 */

L_004E0CAD:
    ecx = MEM32(ebp + 0xC); /* 0x004E0CAD: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx & 2; /* 0x004E0CB0: and ecx, 2 */
    /* test ecx, ecx */ /* 0x004E0CB3: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004E0D69; /* 0x004E0CB5: je 0x4e0d69 */

L_004E0CBB:
    PUSH32(esp, 2); /* 0x004E0CBB: push 2 */
    PUSH32(esp, 0xFFFFFFFFu); /* 0x004E0CBD: push -1 */
    edx = MEM32(ebp + (-0x14)); /* 0x004E0CBF: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0CC2: push edx */
    RECOMP_CALL(sub_004DB9C0); /* 0x004E0CC3: call 0x4db9c0 */
    esp = esp + 0xCu; /* 0x004E0CC8: add esp, 0xc */
    MEM32(ebp + (-0x3C)) = eax; /* 0x004E0CCB: mov dword ptr [ebp - 0x3c], eax */
    /* cmp MEM32(ebp + (-0x3C)), 0xFFFFFFFFu */ /* 0x004E0CCE: cmp dword ptr [ebp - 0x3c], -1 */
    if (CMP_NE(MEM32(ebp + (-0x3C)), 0xFFFFFFFFu)) goto L_004E0CF6; /* 0x004E0CD2: jne 0x4e0cf6 */

L_004E0CD4:
    /* cmp MEM32(0x84B7B0), 0x83u */ /* 0x004E0CD4: cmp dword ptr [0x84b7b0], 0x83 */
    if (CMP_EQ(MEM32(0x84B7B0), 0x83u)) goto L_004E0CF4; /* 0x004E0CDE: je 0x4e0cf4 */

L_004E0CE0:
    eax = MEM32(ebp + (-0x14)); /* 0x004E0CE0: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E0CE3: push eax */
    RECOMP_CALL(sub_004D9370); /* 0x004E0CE4: call 0x4d9370 */
    esp = esp + 4; /* 0x004E0CE9: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0CEC: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0CEF: jmp 0x4e0db2 */

L_004E0CF4:
    goto L_004E0D69; /* 0x004E0CF4: jmp 0x4e0d69 */

L_004E0CF6:
    MEM8(ebp + (-0x30)) = (uint8_t)(0); /* 0x004E0CF6: mov byte ptr [ebp - 0x30], 0 */
    PUSH32(esp, 1); /* 0x004E0CFA: push 1 */
    ecx = ebp + (-0x30); /* 0x004E0CFC: lea ecx, [ebp - 0x30] */
    PUSH32(esp, ecx); /* 0x004E0CFF: push ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004E0D00: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0D03: push edx */
    RECOMP_CALL(sub_004D9D80); /* 0x004E0D04: call 0x4d9d80 */
    esp = esp + 0xCu; /* 0x004E0D09: add esp, 0xc */
    /* test eax, eax */ /* 0x004E0D0C: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E0D3F; /* 0x004E0D0E: jne 0x4e0d3f */

L_004E0D10:
    eax = (int32_t)(int8_t)MEM8(ebp + (-0x30)); /* 0x004E0D10: movsx eax, byte ptr [ebp - 0x30] */
    /* cmp eax, 0x1Au */ /* 0x004E0D14: cmp eax, 0x1a */
    if (CMP_NE(eax, 0x1Au)) goto L_004E0D3F; /* 0x004E0D17: jne 0x4e0d3f */

L_004E0D19:
    ecx = MEM32(ebp + (-0x3C)); /* 0x004E0D19: mov ecx, dword ptr [ebp - 0x3c] */
    PUSH32(esp, ecx); /* 0x004E0D1C: push ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004E0D1D: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0D20: push edx */
    RECOMP_CALL(sub_004E40C0); /* 0x004E0D21: call 0x4e40c0 */
    esp = esp + 8; /* 0x004E0D26: add esp, 8 */
    /* cmp eax, 0xFFFFFFFFu */ /* 0x004E0D29: cmp eax, -1 */
    if (CMP_NE(eax, 0xFFFFFFFFu)) goto L_004E0D3F; /* 0x004E0D2C: jne 0x4e0d3f */

L_004E0D2E:
    eax = MEM32(ebp + (-0x14)); /* 0x004E0D2E: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E0D31: push eax */
    RECOMP_CALL(sub_004D9370); /* 0x004E0D32: call 0x4d9370 */
    esp = esp + 4; /* 0x004E0D37: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0D3A: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0D3D: jmp 0x4e0db2 */

L_004E0D3F:
    PUSH32(esp, 0); /* 0x004E0D3F: push 0 */
    PUSH32(esp, 0); /* 0x004E0D41: push 0 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0D43: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E0D46: push ecx */
    RECOMP_CALL(sub_004DB9C0); /* 0x004E0D47: call 0x4db9c0 */
    esp = esp + 0xCu; /* 0x004E0D4C: add esp, 0xc */
    MEM32(ebp + (-0x3C)) = eax; /* 0x004E0D4F: mov dword ptr [ebp - 0x3c], eax */
    /* cmp MEM32(ebp + (-0x3C)), 0xFFFFFFFFu */ /* 0x004E0D52: cmp dword ptr [ebp - 0x3c], -1 */
    if (CMP_NE(MEM32(ebp + (-0x3C)), 0xFFFFFFFFu)) goto L_004E0D69; /* 0x004E0D56: jne 0x4e0d69 */

L_004E0D58:
    edx = MEM32(ebp + (-0x14)); /* 0x004E0D58: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0D5B: push edx */
    RECOMP_CALL(sub_004D9370); /* 0x004E0D5C: call 0x4d9370 */
    esp = esp + 4; /* 0x004E0D61: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0D64: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0D67: jmp 0x4e0db2 */

L_004E0D69:
    eax = (int32_t)(int8_t)MEM8(ebp + (-0x38)); /* 0x004E0D69: movsx eax, byte ptr [ebp - 0x38] */
    eax = eax & 0x48u; /* 0x004E0D6D: and eax, 0x48 */
    /* test eax, eax */ /* 0x004E0D70: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E0DAF; /* 0x004E0D72: jne 0x4e0daf */

L_004E0D74:
    ecx = MEM32(ebp + 0xC); /* 0x004E0D74: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx & 8; /* 0x004E0D77: and ecx, 8 */
    /* test ecx, ecx */ /* 0x004E0D7A: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004E0DAF; /* 0x004E0D7C: je 0x4e0daf */

L_004E0D7E:
    edx = MEM32(ebp + (-0x14)); /* 0x004E0D7E: mov edx, dword ptr [ebp - 0x14] */
    edx = (uint32_t)((int32_t)edx >> 5); /* 0x004E0D81: sar edx, 5 */
    eax = MEM32(ebp + (-0x14)); /* 0x004E0D84: mov eax, dword ptr [ebp - 0x14] */
    eax = eax & 0x1Fu; /* 0x004E0D87: and eax, 0x1f */
    ecx = MEM32(edx * 4 + 0x855C60); /* 0x004E0D8A: mov ecx, dword ptr [edx*4 + 0x855c60] */
    SET_LO8(edx, MEM8(ecx + eax * 8 + 0x4)); /* 0x004E0D91: mov dl, byte ptr [ecx + eax*8 + 4] */
    SET_LO8(edx, LO8(edx) | 0x20u); /* 0x004E0D95: or dl, 0x20 */
    eax = MEM32(ebp + (-0x14)); /* 0x004E0D98: mov eax, dword ptr [ebp - 0x14] */
    eax = (uint32_t)((int32_t)eax >> 5); /* 0x004E0D9B: sar eax, 5 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0D9E: mov ecx, dword ptr [ebp - 0x14] */
    ecx = ecx & 0x1Fu; /* 0x004E0DA1: and ecx, 0x1f */
    eax = MEM32(eax * 4 + 0x855C60); /* 0x004E0DA4: mov eax, dword ptr [eax*4 + 0x855c60] */
    MEM8(eax + ecx * 8 + 0x4) = (uint8_t)(LO8(edx)); /* 0x004E0DAB: mov byte ptr [eax + ecx*8 + 4], dl */

L_004E0DAF:
    eax = MEM32(ebp + (-0x14)); /* 0x004E0DAF: mov eax, dword ptr [ebp - 0x14] */

L_004E0DB2:
    esp = ebp; /* 0x004E0DB2: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E0DB4: pop ebp */
    return; /* 0x004E0DB5: ret  */

}

void sub_004E0C97(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E0C97:
    /* test ebp, ecx */ /* 0x004E0C97: test ebp, ecx */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E0C99: add byte ptr [eax], al */
    MEM8(edi) = (uint8_t)(MEM8(edi) + LO8(ecx)); /* 0x004E0C9B: add byte ptr [edi], cl */
    esi = 0x8025C845u; /* 0x004E0C9D: mov esi, 0x8025c845 */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E0CA2: add byte ptr [eax], al */
    MEM8(ebp + (-0x437BF040)) = (uint8_t)(MEM8(ebp + (-0x437BF040)) + LO8(eax)); /* 0x004E0CA4: add byte ptr [ebp - 0x437bf040], al */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E0CAA: add byte ptr [eax], al */
    MEM8(ebx + (-0x1E7CF3B3)) = (uint8_t)(MEM8(ebx + (-0x1E7CF3B3)) + LO8(ecx)); /* 0x004E0CAC: add byte ptr [ebx - 0x1e7cf3b3], cl */
    SET_LO8(eax, LO8(eax) + MEM8(ebp + (-0x517BF037))); /* 0x004E0CB2: add al, byte ptr [ebp - 0x517bf037] */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E0CB8: add byte ptr [eax], al */
    MEM8(edx + 0x2) = (uint8_t)(MEM8(edx + 0x2) + HI8(ecx)); /* 0x004E0CBA: add byte ptr [edx + 2], ch */
    PUSH32(esp, 0xFFFFFFFFu); /* 0x004E0CBD: push -1 */
    edx = MEM32(ebp + (-0x14)); /* 0x004E0CBF: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0CC2: push edx */
    RECOMP_CALL(sub_004DB9C0); /* 0x004E0CC3: call 0x4db9c0 */
    esp = esp + 0xCu; /* 0x004E0CC8: add esp, 0xc */
    MEM32(ebp + (-0x3C)) = eax; /* 0x004E0CCB: mov dword ptr [ebp - 0x3c], eax */
    /* cmp MEM32(ebp + (-0x3C)), 0xFFFFFFFFu */ /* 0x004E0CCE: cmp dword ptr [ebp - 0x3c], -1 */
    if (CMP_NE(MEM32(ebp + (-0x3C)), 0xFFFFFFFFu)) goto L_004E0CF6; /* 0x004E0CD2: jne 0x4e0cf6 */

L_004E0CD4:
    /* cmp MEM32(0x84B7B0), 0x83u */ /* 0x004E0CD4: cmp dword ptr [0x84b7b0], 0x83 */
    if (CMP_EQ(MEM32(0x84B7B0), 0x83u)) goto L_004E0CF4; /* 0x004E0CDE: je 0x4e0cf4 */

L_004E0CE0:
    eax = MEM32(ebp + (-0x14)); /* 0x004E0CE0: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E0CE3: push eax */
    RECOMP_CALL(sub_004D9370); /* 0x004E0CE4: call 0x4d9370 */
    esp = esp + 4; /* 0x004E0CE9: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0CEC: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0CEF: jmp 0x4e0db2 */

L_004E0CF4:
    goto L_004E0D69; /* 0x004E0CF4: jmp 0x4e0d69 */

L_004E0CF6:
    MEM8(ebp + (-0x30)) = (uint8_t)(0); /* 0x004E0CF6: mov byte ptr [ebp - 0x30], 0 */
    PUSH32(esp, 1); /* 0x004E0CFA: push 1 */
    ecx = ebp + (-0x30); /* 0x004E0CFC: lea ecx, [ebp - 0x30] */
    PUSH32(esp, ecx); /* 0x004E0CFF: push ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004E0D00: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0D03: push edx */
    RECOMP_CALL(sub_004D9D80); /* 0x004E0D04: call 0x4d9d80 */
    esp = esp + 0xCu; /* 0x004E0D09: add esp, 0xc */
    /* test eax, eax */ /* 0x004E0D0C: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E0D3F; /* 0x004E0D0E: jne 0x4e0d3f */

L_004E0D10:
    eax = (int32_t)(int8_t)MEM8(ebp + (-0x30)); /* 0x004E0D10: movsx eax, byte ptr [ebp - 0x30] */
    /* cmp eax, 0x1Au */ /* 0x004E0D14: cmp eax, 0x1a */
    if (CMP_NE(eax, 0x1Au)) goto L_004E0D3F; /* 0x004E0D17: jne 0x4e0d3f */

L_004E0D19:
    ecx = MEM32(ebp + (-0x3C)); /* 0x004E0D19: mov ecx, dword ptr [ebp - 0x3c] */
    PUSH32(esp, ecx); /* 0x004E0D1C: push ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004E0D1D: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0D20: push edx */
    RECOMP_CALL(sub_004E40C0); /* 0x004E0D21: call 0x4e40c0 */
    esp = esp + 8; /* 0x004E0D26: add esp, 8 */
    /* cmp eax, 0xFFFFFFFFu */ /* 0x004E0D29: cmp eax, -1 */
    if (CMP_NE(eax, 0xFFFFFFFFu)) goto L_004E0D3F; /* 0x004E0D2C: jne 0x4e0d3f */

L_004E0D2E:
    eax = MEM32(ebp + (-0x14)); /* 0x004E0D2E: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E0D31: push eax */
    RECOMP_CALL(sub_004D9370); /* 0x004E0D32: call 0x4d9370 */
    esp = esp + 4; /* 0x004E0D37: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0D3A: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0D3D: jmp 0x4e0db2 */

L_004E0D3F:
    PUSH32(esp, 0); /* 0x004E0D3F: push 0 */
    PUSH32(esp, 0); /* 0x004E0D41: push 0 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0D43: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E0D46: push ecx */
    RECOMP_CALL(sub_004DB9C0); /* 0x004E0D47: call 0x4db9c0 */
    esp = esp + 0xCu; /* 0x004E0D4C: add esp, 0xc */
    MEM32(ebp + (-0x3C)) = eax; /* 0x004E0D4F: mov dword ptr [ebp - 0x3c], eax */
    /* cmp MEM32(ebp + (-0x3C)), 0xFFFFFFFFu */ /* 0x004E0D52: cmp dword ptr [ebp - 0x3c], -1 */
    if (CMP_NE(MEM32(ebp + (-0x3C)), 0xFFFFFFFFu)) goto L_004E0D69; /* 0x004E0D56: jne 0x4e0d69 */

L_004E0D58:
    edx = MEM32(ebp + (-0x14)); /* 0x004E0D58: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E0D5B: push edx */
    RECOMP_CALL(sub_004D9370); /* 0x004E0D5C: call 0x4d9370 */
    esp = esp + 4; /* 0x004E0D61: add esp, 4 */
    eax = eax | 0xFFFFFFFFu; /* 0x004E0D64: or eax, 0xffffffff */
    goto L_004E0DB2; /* 0x004E0D67: jmp 0x4e0db2 */

L_004E0D69:
    eax = (int32_t)(int8_t)MEM8(ebp + (-0x38)); /* 0x004E0D69: movsx eax, byte ptr [ebp - 0x38] */
    eax = eax & 0x48u; /* 0x004E0D6D: and eax, 0x48 */
    /* test eax, eax */ /* 0x004E0D70: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E0DAF; /* 0x004E0D72: jne 0x4e0daf */

L_004E0D74:
    ecx = MEM32(ebp + 0xC); /* 0x004E0D74: mov ecx, dword ptr [ebp + 0xc] */
    ecx = ecx & 8; /* 0x004E0D77: and ecx, 8 */
    /* test ecx, ecx */ /* 0x004E0D7A: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004E0DAF; /* 0x004E0D7C: je 0x4e0daf */

L_004E0D7E:
    edx = MEM32(ebp + (-0x14)); /* 0x004E0D7E: mov edx, dword ptr [ebp - 0x14] */
    edx = (uint32_t)((int32_t)edx >> 5); /* 0x004E0D81: sar edx, 5 */
    eax = MEM32(ebp + (-0x14)); /* 0x004E0D84: mov eax, dword ptr [ebp - 0x14] */
    eax = eax & 0x1Fu; /* 0x004E0D87: and eax, 0x1f */
    ecx = MEM32(edx * 4 + 0x855C60); /* 0x004E0D8A: mov ecx, dword ptr [edx*4 + 0x855c60] */
    SET_LO8(edx, MEM8(ecx + eax * 8 + 0x4)); /* 0x004E0D91: mov dl, byte ptr [ecx + eax*8 + 4] */
    SET_LO8(edx, LO8(edx) | 0x20u); /* 0x004E0D95: or dl, 0x20 */
    eax = MEM32(ebp + (-0x14)); /* 0x004E0D98: mov eax, dword ptr [ebp - 0x14] */
    eax = (uint32_t)((int32_t)eax >> 5); /* 0x004E0D9B: sar eax, 5 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0D9E: mov ecx, dword ptr [ebp - 0x14] */
    ecx = ecx & 0x1Fu; /* 0x004E0DA1: and ecx, 0x1f */
    eax = MEM32(eax * 4 + 0x855C60); /* 0x004E0DA4: mov eax, dword ptr [eax*4 + 0x855c60] */
    MEM8(eax + ecx * 8 + 0x4) = (uint8_t)(LO8(edx)); /* 0x004E0DAB: mov byte ptr [eax + ecx*8 + 4], dl */

L_004E0DAF:
    eax = MEM32(ebp + (-0x14)); /* 0x004E0DAF: mov eax, dword ptr [ebp - 0x14] */

L_004E0DB2:
    esp = ebp; /* 0x004E0DB2: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E0DB4: pop ebp */
    return; /* 0x004E0DB5: ret  */

}

void sub_004E0E80(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E0E80:
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E0E80: add byte ptr [eax], al */
    /* cmp MEM32(0x84BCAC), 2 */ /* 0x004E0E82: cmp dword ptr [0x84bcac], 2 */
    if (CMP_NE(MEM32(0x84BCAC), 2)) goto L_004E100C; /* 0x004E0E89: jne 0x4e100c */

L_004E0E8F:
    MEM32(ebp + (-0x8)) = 0; /* 0x004E0E8F: mov dword ptr [ebp - 8], 0 */
    MEM32(ebp + (-0x14)) = 0; /* 0x004E0E96: mov dword ptr [ebp - 0x14], 0 */
    MEM32(ebp + (-0xC)) = 0; /* 0x004E0E9D: mov dword ptr [ebp - 0xc], 0 */
    /* cmp MEM32(ebp + 0x18), 0 */ /* 0x004E0EA4: cmp dword ptr [ebp + 0x18], 0 */
    if (CMP_NE(MEM32(ebp + 0x18), 0)) goto L_004E0EB2; /* 0x004E0EA8: jne 0x4e0eb2 */

L_004E0EAA:
    eax = MEM32(0x84BCD0); /* 0x004E0EAA: mov eax, dword ptr [0x84bcd0] */
    MEM32(ebp + 0x18) = eax; /* 0x004E0EAF: mov dword ptr [ebp + 0x18], eax */

L_004E0EB2:
    PUSH32(esp, 0); /* 0x004E0EB2: push 0 */
    PUSH32(esp, 0); /* 0x004E0EB4: push 0 */
    PUSH32(esp, 0); /* 0x004E0EB6: push 0 */
    PUSH32(esp, 0); /* 0x004E0EB8: push 0 */
    ecx = MEM32(ebp + 0x10); /* 0x004E0EBA: mov ecx, dword ptr [ebp + 0x10] */
    PUSH32(esp, ecx); /* 0x004E0EBD: push ecx */
    edx = MEM32(ebp + 0xC); /* 0x004E0EBE: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004E0EC1: push edx */
    PUSH32(esp, 0x220u); /* 0x004E0EC2: push 0x220 */
    eax = MEM32(ebp + 0x18); /* 0x004E0EC7: mov eax, dword ptr [ebp + 0x18] */
    PUSH32(esp, eax); /* 0x004E0ECA: push eax */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E0ECB: call dword ptr [0x8586e0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E0ED1: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E0ED4: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E0EE1; /* 0x004E0ED8: jne 0x4e0ee1 */

L_004E0EDA:
    eax = 0; /* 0x004E0EDA: xor eax, eax */
    goto L_004E100C; /* 0x004E0EDC: jmp 0x4e100c */

L_004E0EE1:
    PUSH32(esp, 0x78u); /* 0x004E0EE1: push 0x78 */
    PUSH32(esp, 0x004F46F8u); /* 0x004E0EE3: push 0x4f46f8 */
    PUSH32(esp, 2); /* 0x004E0EE8: push 2 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E0EEA: mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(esp, ecx); /* 0x004E0EED: push ecx */
    PUSH32(esp, 1); /* 0x004E0EEE: push 1 */
    RECOMP_CALL(sub_004D29A0); /* 0x004E0EF0: call 0x4d29a0 */
    esp = esp + 0x14u; /* 0x004E0EF5: add esp, 0x14 */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E0EF8: mov dword ptr [ebp - 0x14], eax */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004E0EFB: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004E0F08; /* 0x004E0EFF: jne 0x4e0f08 */

L_004E0F01:
    eax = 0; /* 0x004E0F01: xor eax, eax */
    goto L_004E100C; /* 0x004E0F03: jmp 0x4e100c */

L_004E0F08:
    PUSH32(esp, 0); /* 0x004E0F08: push 0 */
    PUSH32(esp, 0); /* 0x004E0F0A: push 0 */
    edx = MEM32(ebp + (-0x10)); /* 0x004E0F0C: mov edx, dword ptr [ebp - 0x10] */
    PUSH32(esp, edx); /* 0x004E0F0F: push edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004E0F10: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E0F13: push eax */
    ecx = MEM32(ebp + 0x10); /* 0x004E0F14: mov ecx, dword ptr [ebp + 0x10] */
    PUSH32(esp, ecx); /* 0x004E0F17: push ecx */
    edx = MEM32(ebp + 0xC); /* 0x004E0F18: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004E0F1B: push edx */
    PUSH32(esp, 0x220u); /* 0x004E0F1C: push 0x220 */
    eax = MEM32(ebp + 0x18); /* 0x004E0F21: mov eax, dword ptr [ebp + 0x18] */
    PUSH32(esp, eax); /* 0x004E0F24: push eax */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E0F25: call dword ptr [0x8586e0] */
    MEM32(ebp + (-0x18)) = eax; /* 0x004E0F2B: mov dword ptr [ebp - 0x18], eax */
    /* cmp MEM32(ebp + (-0x18)), 0 */ /* 0x004E0F2E: cmp dword ptr [ebp - 0x18], 0 */
    if (CMP_NE(MEM32(ebp + (-0x18)), 0)) goto L_004E0F39; /* 0x004E0F32: jne 0x4e0f39 */

L_004E0F34:
    goto L_004E0FED; /* 0x004E0F34: jmp 0x4e0fed */

L_004E0F39:
    PUSH32(esp, 0x83u); /* 0x004E0F39: push 0x83 */
    PUSH32(esp, 0x004F46F8u); /* 0x004E0F3E: push 0x4f46f8 */
    PUSH32(esp, 2); /* 0x004E0F43: push 2 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E0F45: mov ecx, dword ptr [ebp - 0x10] */
    edx = ecx + ecx + 0x2; /* 0x004E0F48: lea edx, [ecx + ecx + 2] */
    PUSH32(esp, edx); /* 0x004E0F4C: push edx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E0F4D: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E0F52: add esp, 0x10 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E0F55: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E0F58: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E0F63; /* 0x004E0F5C: jne 0x4e0f63 */

L_004E0F5E:
    goto L_004E0FED; /* 0x004E0F5E: jmp 0x4e0fed */

L_004E0F63:
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E0F63: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_NE(MEM32(ebp + 0x1C), 0)) goto L_004E0F71; /* 0x004E0F67: jne 0x4e0f71 */

L_004E0F69:
    eax = MEM32(0x84BCC0); /* 0x004E0F69: mov eax, dword ptr [0x84bcc0] */
    MEM32(ebp + 0x1C) = eax; /* 0x004E0F6E: mov dword ptr [ebp + 0x1c], eax */

L_004E0F71:
    ecx = MEM32(ebp + 0x10); /* 0x004E0F71: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0F74: mov edx, dword ptr [ebp - 0xc] */
    MEM16(edx + ecx * 2) = (uint16_t)(0xFFFFu); /* 0x004E0F77: mov word ptr [edx + ecx*2], 0xffff */
    eax = MEM32(ebp + 0x10); /* 0x004E0F7D: mov eax, dword ptr [ebp + 0x10] */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E0F80: mov ecx, dword ptr [ebp - 0xc] */
    MEM16(ecx + eax * 2 + (-0x2)) = (uint16_t)(0xFFFFu); /* 0x004E0F83: mov word ptr [ecx + eax*2 - 2], 0xffff */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0F8A: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E0F8D: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E0F8E: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004E0F91: push eax */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0F92: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E0F95: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E0F96: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E0F99: push edx */
    eax = MEM32(ebp + 0x1C); /* 0x004E0F9A: mov eax, dword ptr [ebp + 0x1c] */
    PUSH32(esp, eax); /* 0x004E0F9D: push eax */
    RECOMP_ICALL(MEM32(0x8586BC)); /* 0x004E0F9E: call dword ptr [0x8586bc] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E0FA4: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + 0x10); /* 0x004E0FA7: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0FAA: mov edx, dword ptr [ebp - 0xc] */
    eax = 0; /* 0x004E0FAD: xor eax, eax */
    SET_LO16(eax, MEM16(edx + ecx * 2 + (-0x2))); /* 0x004E0FAF: mov ax, word ptr [edx + ecx*2 - 2] */
    /* cmp eax, 0xFFFFu */ /* 0x004E0FB4: cmp eax, 0xffff */
    if (CMP_EQ(eax, 0xFFFFu)) goto L_004E0FCE; /* 0x004E0FB9: je 0x4e0fce */

L_004E0FBB:
    ecx = MEM32(ebp + 0x10); /* 0x004E0FBB: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0FBE: mov edx, dword ptr [ebp - 0xc] */
    eax = 0; /* 0x004E0FC1: xor eax, eax */
    SET_LO16(eax, MEM16(edx + ecx * 2)); /* 0x004E0FC3: mov ax, word ptr [edx + ecx*2] */
    /* cmp eax, 0xFFFFu */ /* 0x004E0FC7: cmp eax, 0xffff */
    if (CMP_EQ(eax, 0xFFFFu)) goto L_004E0FD7; /* 0x004E0FCC: je 0x4e0fd7 */

L_004E0FCE:
    MEM32(ebp + (-0x8)) = 0; /* 0x004E0FCE: mov dword ptr [ebp - 8], 0 */
    goto L_004E0FED; /* 0x004E0FD5: jmp 0x4e0fed */

L_004E0FD7:
    ecx = MEM32(ebp + 0x10); /* 0x004E0FD7: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx << 1; /* 0x004E0FDA: shl ecx, 1 */
    PUSH32(esp, ecx); /* 0x004E0FDC: push ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0FDD: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E0FE0: push edx */
    eax = MEM32(ebp + 0x14); /* 0x004E0FE1: mov eax, dword ptr [ebp + 0x14] */
    PUSH32(esp, eax); /* 0x004E0FE4: push eax */
    RECOMP_CALL(sub_004D5FA0); /* 0x004E0FE5: call 0x4d5fa0 */
    esp = esp + 0xCu; /* 0x004E0FEA: add esp, 0xc */

L_004E0FED:
    PUSH32(esp, 2); /* 0x004E0FED: push 2 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0FEF: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E0FF2: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E0FF3: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E0FF8: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E0FFB: push 2 */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0FFD: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E1000: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1001: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1006: add esp, 8 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E1009: mov eax, dword ptr [ebp - 8] */

L_004E100C:
    esp = ebp; /* 0x004E100C: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E100E: pop ebp */
    return; /* 0x004E100F: ret  */

}

void sub_004E0EE0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E0EE0:
    MEM8(edx + 0x78) = (uint8_t)(MEM8(edx + 0x78) + HI8(ecx)); /* 0x004E0EE0: add byte ptr [edx + 0x78], ch */
    PUSH32(esp, 0x004F46F8u); /* 0x004E0EE3: push 0x4f46f8 */
    PUSH32(esp, 2); /* 0x004E0EE8: push 2 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E0EEA: mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(esp, ecx); /* 0x004E0EED: push ecx */
    PUSH32(esp, 1); /* 0x004E0EEE: push 1 */
    RECOMP_CALL(sub_004D29A0); /* 0x004E0EF0: call 0x4d29a0 */
    esp = esp + 0x14u; /* 0x004E0EF5: add esp, 0x14 */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E0EF8: mov dword ptr [ebp - 0x14], eax */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004E0EFB: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004E0F08; /* 0x004E0EFF: jne 0x4e0f08 */

L_004E0F01:
    eax = 0; /* 0x004E0F01: xor eax, eax */
    goto L_004E100C; /* 0x004E0F03: jmp 0x4e100c */

L_004E0F08:
    PUSH32(esp, 0); /* 0x004E0F08: push 0 */
    PUSH32(esp, 0); /* 0x004E0F0A: push 0 */
    edx = MEM32(ebp + (-0x10)); /* 0x004E0F0C: mov edx, dword ptr [ebp - 0x10] */
    PUSH32(esp, edx); /* 0x004E0F0F: push edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004E0F10: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E0F13: push eax */
    ecx = MEM32(ebp + 0x10); /* 0x004E0F14: mov ecx, dword ptr [ebp + 0x10] */
    PUSH32(esp, ecx); /* 0x004E0F17: push ecx */
    edx = MEM32(ebp + 0xC); /* 0x004E0F18: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004E0F1B: push edx */
    PUSH32(esp, 0x220u); /* 0x004E0F1C: push 0x220 */
    eax = MEM32(ebp + 0x18); /* 0x004E0F21: mov eax, dword ptr [ebp + 0x18] */
    PUSH32(esp, eax); /* 0x004E0F24: push eax */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E0F25: call dword ptr [0x8586e0] */
    MEM32(ebp + (-0x18)) = eax; /* 0x004E0F2B: mov dword ptr [ebp - 0x18], eax */
    /* cmp MEM32(ebp + (-0x18)), 0 */ /* 0x004E0F2E: cmp dword ptr [ebp - 0x18], 0 */
    if (CMP_NE(MEM32(ebp + (-0x18)), 0)) goto L_004E0F39; /* 0x004E0F32: jne 0x4e0f39 */

L_004E0F34:
    goto L_004E0FED; /* 0x004E0F34: jmp 0x4e0fed */

L_004E0F39:
    PUSH32(esp, 0x83u); /* 0x004E0F39: push 0x83 */
    PUSH32(esp, 0x004F46F8u); /* 0x004E0F3E: push 0x4f46f8 */
    PUSH32(esp, 2); /* 0x004E0F43: push 2 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E0F45: mov ecx, dword ptr [ebp - 0x10] */
    edx = ecx + ecx + 0x2; /* 0x004E0F48: lea edx, [ecx + ecx + 2] */
    PUSH32(esp, edx); /* 0x004E0F4C: push edx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E0F4D: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E0F52: add esp, 0x10 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E0F55: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E0F58: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E0F63; /* 0x004E0F5C: jne 0x4e0f63 */

L_004E0F5E:
    goto L_004E0FED; /* 0x004E0F5E: jmp 0x4e0fed */

L_004E0F63:
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E0F63: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_NE(MEM32(ebp + 0x1C), 0)) goto L_004E0F71; /* 0x004E0F67: jne 0x4e0f71 */

L_004E0F69:
    eax = MEM32(0x84BCC0); /* 0x004E0F69: mov eax, dword ptr [0x84bcc0] */
    MEM32(ebp + 0x1C) = eax; /* 0x004E0F6E: mov dword ptr [ebp + 0x1c], eax */

L_004E0F71:
    ecx = MEM32(ebp + 0x10); /* 0x004E0F71: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0F74: mov edx, dword ptr [ebp - 0xc] */
    MEM16(edx + ecx * 2) = (uint16_t)(0xFFFFu); /* 0x004E0F77: mov word ptr [edx + ecx*2], 0xffff */
    eax = MEM32(ebp + 0x10); /* 0x004E0F7D: mov eax, dword ptr [ebp + 0x10] */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E0F80: mov ecx, dword ptr [ebp - 0xc] */
    MEM16(ecx + eax * 2 + (-0x2)) = (uint16_t)(0xFFFFu); /* 0x004E0F83: mov word ptr [ecx + eax*2 - 2], 0xffff */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0F8A: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E0F8D: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E0F8E: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004E0F91: push eax */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0F92: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E0F95: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E0F96: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E0F99: push edx */
    eax = MEM32(ebp + 0x1C); /* 0x004E0F9A: mov eax, dword ptr [ebp + 0x1c] */
    PUSH32(esp, eax); /* 0x004E0F9D: push eax */
    RECOMP_ICALL(MEM32(0x8586BC)); /* 0x004E0F9E: call dword ptr [0x8586bc] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E0FA4: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + 0x10); /* 0x004E0FA7: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0FAA: mov edx, dword ptr [ebp - 0xc] */
    eax = 0; /* 0x004E0FAD: xor eax, eax */
    SET_LO16(eax, MEM16(edx + ecx * 2 + (-0x2))); /* 0x004E0FAF: mov ax, word ptr [edx + ecx*2 - 2] */
    /* cmp eax, 0xFFFFu */ /* 0x004E0FB4: cmp eax, 0xffff */
    if (CMP_EQ(eax, 0xFFFFu)) goto L_004E0FCE; /* 0x004E0FB9: je 0x4e0fce */

L_004E0FBB:
    ecx = MEM32(ebp + 0x10); /* 0x004E0FBB: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0FBE: mov edx, dword ptr [ebp - 0xc] */
    eax = 0; /* 0x004E0FC1: xor eax, eax */
    SET_LO16(eax, MEM16(edx + ecx * 2)); /* 0x004E0FC3: mov ax, word ptr [edx + ecx*2] */
    /* cmp eax, 0xFFFFu */ /* 0x004E0FC7: cmp eax, 0xffff */
    if (CMP_EQ(eax, 0xFFFFu)) goto L_004E0FD7; /* 0x004E0FCC: je 0x4e0fd7 */

L_004E0FCE:
    MEM32(ebp + (-0x8)) = 0; /* 0x004E0FCE: mov dword ptr [ebp - 8], 0 */
    goto L_004E0FED; /* 0x004E0FD5: jmp 0x4e0fed */

L_004E0FD7:
    ecx = MEM32(ebp + 0x10); /* 0x004E0FD7: mov ecx, dword ptr [ebp + 0x10] */
    ecx = ecx << 1; /* 0x004E0FDA: shl ecx, 1 */
    PUSH32(esp, ecx); /* 0x004E0FDC: push ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0FDD: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E0FE0: push edx */
    eax = MEM32(ebp + 0x14); /* 0x004E0FE1: mov eax, dword ptr [ebp + 0x14] */
    PUSH32(esp, eax); /* 0x004E0FE4: push eax */
    RECOMP_CALL(sub_004D5FA0); /* 0x004E0FE5: call 0x4d5fa0 */
    esp = esp + 0xCu; /* 0x004E0FEA: add esp, 0xc */

L_004E0FED:
    PUSH32(esp, 2); /* 0x004E0FED: push 2 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E0FEF: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E0FF2: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E0FF3: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E0FF8: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E0FFB: push 2 */
    edx = MEM32(ebp + (-0xC)); /* 0x004E0FFD: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E1000: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1001: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1006: add esp, 8 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E1009: mov eax, dword ptr [ebp - 8] */

L_004E100C:
    esp = ebp; /* 0x004E100C: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E100E: pop ebp */
    return; /* 0x004E100F: ret  */

}

void sub_004E12A0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E12A0:
    /* UNIMPLEMENTED: loopne 0x4e1228 */ /* 0x004E12A0: loopne 0x4e1228 */
    /* test MEM32(eax), eax */ /* 0x004E12A2: test dword ptr [eax], eax */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E12A4: mov dword ptr [ebp - 8], eax */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E12A7: cmp dword ptr [ebp - 8], 0 */
    if (CMP_NE(MEM32(ebp + (-0x8)), 0)) goto L_004E12B4; /* 0x004E12AB: jne 0x4e12b4 */

L_004E12AD:
    eax = 0; /* 0x004E12AD: xor eax, eax */
    goto L_004E1453; /* 0x004E12AF: jmp 0x4e1453 */

L_004E12B4:
    PUSH32(esp, 0xCCu); /* 0x004E12B4: push 0xcc */
    PUSH32(esp, 0x004F470Cu); /* 0x004E12B9: push 0x4f470c */
    PUSH32(esp, 2); /* 0x004E12BE: push 2 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E12C0: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E12C3: push eax */
    RECOMP_CALL(sub_004D25A0); /* 0x004E12C4: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E12C9: add esp, 0x10 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E12CC: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004E12CF: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004E12DC; /* 0x004E12D3: jne 0x4e12dc */

L_004E12D5:
    eax = 0; /* 0x004E12D5: xor eax, eax */
    goto L_004E1453; /* 0x004E12D7: jmp 0x4e1453 */

L_004E12DC:
    PUSH32(esp, 0); /* 0x004E12DC: push 0 */
    PUSH32(esp, 0); /* 0x004E12DE: push 0 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E12E0: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004E12E3: push ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004E12E4: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E12E7: push edx */
    eax = MEM32(ebp + 0x14); /* 0x004E12E8: mov eax, dword ptr [ebp + 0x14] */
    PUSH32(esp, eax); /* 0x004E12EB: push eax */
    ecx = MEM32(ebp + 0x10); /* 0x004E12EC: mov ecx, dword ptr [ebp + 0x10] */
    PUSH32(esp, ecx); /* 0x004E12EF: push ecx */
    PUSH32(esp, 0x220u); /* 0x004E12F0: push 0x220 */
    edx = MEM32(ebp + 0x20); /* 0x004E12F5: mov edx, dword ptr [ebp + 0x20] */
    PUSH32(esp, edx); /* 0x004E12F8: push edx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E12F9: call dword ptr [0x8586e0] */
    /* test eax, eax */ /* 0x004E12FF: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E1308; /* 0x004E1301: jne 0x4e1308 */

L_004E1303:
    goto L_004E1435; /* 0x004E1303: jmp 0x4e1435 */

L_004E1308:
    PUSH32(esp, 0); /* 0x004E1308: push 0 */
    PUSH32(esp, 0); /* 0x004E130A: push 0 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E130C: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E130F: push eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E1310: mov ecx, dword ptr [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004E1313: push ecx */
    edx = MEM32(ebp + 0xC); /* 0x004E1314: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004E1317: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004E1318: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004E131B: push eax */
    RECOMP_ICALL(MEM32(0x8586B4)); /* 0x004E131C: call dword ptr [0x8586b4] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E1322: mov dword ptr [ebp - 0x14], eax */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004E1325: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004E1330; /* 0x004E1329: jne 0x4e1330 */

L_004E132B:
    goto L_004E1435; /* 0x004E132B: jmp 0x4e1435 */

L_004E1330:
    PUSH32(esp, 0xDBu); /* 0x004E1330: push 0xdb */
    PUSH32(esp, 0x004F470Cu); /* 0x004E1335: push 0x4f470c */
    PUSH32(esp, 2); /* 0x004E133A: push 2 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E133C: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E133F: push ecx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E1340: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E1345: add esp, 0x10 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E1348: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E134B: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E1356; /* 0x004E134F: jne 0x4e1356 */

L_004E1351:
    goto L_004E1435; /* 0x004E1351: jmp 0x4e1435 */

L_004E1356:
    edx = MEM32(ebp + (-0x14)); /* 0x004E1356: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E1359: push edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E135A: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E135D: push eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E135E: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004E1361: push ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004E1362: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E1365: push edx */
    eax = MEM32(ebp + 0xC); /* 0x004E1366: mov eax, dword ptr [ebp + 0xc] */
    PUSH32(esp, eax); /* 0x004E1369: push eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E136A: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004E136D: push ecx */
    RECOMP_ICALL(MEM32(0x8586B4)); /* 0x004E136E: call dword ptr [0x8586b4] */
    /* test eax, eax */ /* 0x004E1374: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E137D; /* 0x004E1376: jne 0x4e137d */

L_004E1378:
    goto L_004E1435; /* 0x004E1378: jmp 0x4e1435 */

L_004E137D:
    edx = MEM32(ebp + 0xC); /* 0x004E137D: mov edx, dword ptr [ebp + 0xc] */
    edx = edx & 0x400u; /* 0x004E1380: and edx, 0x400 */
    /* test edx, edx */ /* 0x004E1386: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004E13C2; /* 0x004E1388: je 0x4e13c2 */

L_004E138A:
    eax = MEM32(ebp + (-0x14)); /* 0x004E138A: mov eax, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E138D: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E1390: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_EQ(MEM32(ebp + 0x1C), 0)) goto L_004E13C0; /* 0x004E1394: je 0x4e13c0 */

L_004E1396:
    ecx = MEM32(ebp + 0x1C); /* 0x004E1396: mov ecx, dword ptr [ebp + 0x1c] */
    /* cmp ecx, MEM32(ebp + (-0x14)) */ /* 0x004E1399: cmp ecx, dword ptr [ebp - 0x14] */
    if (CMP_GE(ecx, MEM32(ebp + (-0x14)))) goto L_004E13A6; /* 0x004E139C: jge 0x4e13a6 */

L_004E139E:
    edx = MEM32(ebp + 0x1C); /* 0x004E139E: mov edx, dword ptr [ebp + 0x1c] */
    MEM32(ebp + (-0x18)) = edx; /* 0x004E13A1: mov dword ptr [ebp - 0x18], edx */
    goto L_004E13AC; /* 0x004E13A4: jmp 0x4e13ac */

L_004E13A6:
    eax = MEM32(ebp + (-0x14)); /* 0x004E13A6: mov eax, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x18)) = eax; /* 0x004E13A9: mov dword ptr [ebp - 0x18], eax */

L_004E13AC:
    ecx = MEM32(ebp + (-0x18)); /* 0x004E13AC: mov ecx, dword ptr [ebp - 0x18] */
    PUSH32(esp, ecx); /* 0x004E13AF: push ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004E13B0: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E13B3: push edx */
    eax = MEM32(ebp + 0x18); /* 0x004E13B4: mov eax, dword ptr [ebp + 0x18] */
    PUSH32(esp, eax); /* 0x004E13B7: push eax */
    RECOMP_CALL(sub_004D1B70); /* 0x004E13B8: call 0x4d1b70 */
    esp = esp + 0xCu; /* 0x004E13BD: add esp, 0xc */

L_004E13C0:
    goto L_004E1414; /* 0x004E13C0: jmp 0x4e1414 */

L_004E13C2:
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E13C2: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_NE(MEM32(ebp + 0x1C), 0)) goto L_004E13ED; /* 0x004E13C6: jne 0x4e13ed */

L_004E13C8:
    PUSH32(esp, 0); /* 0x004E13C8: push 0 */
    PUSH32(esp, 0); /* 0x004E13CA: push 0 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E13CC: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E13CF: push ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004E13D0: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E13D3: push edx */
    PUSH32(esp, 1); /* 0x004E13D4: push 1 */
    eax = MEM32(ebp + 0x20); /* 0x004E13D6: mov eax, dword ptr [ebp + 0x20] */
    PUSH32(esp, eax); /* 0x004E13D9: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E13DA: call dword ptr [0x8586f0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E13E0: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E13E3: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E13EB; /* 0x004E13E7: jne 0x4e13eb */

L_004E13E9:
    goto L_004E1435; /* 0x004E13E9: jmp 0x4e1435 */

L_004E13EB:
    goto L_004E1414; /* 0x004E13EB: jmp 0x4e1414 */

L_004E13ED:
    ecx = MEM32(ebp + 0x1C); /* 0x004E13ED: mov ecx, dword ptr [ebp + 0x1c] */
    PUSH32(esp, ecx); /* 0x004E13F0: push ecx */
    edx = MEM32(ebp + 0x18); /* 0x004E13F1: mov edx, dword ptr [ebp + 0x18] */
    PUSH32(esp, edx); /* 0x004E13F4: push edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004E13F5: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E13F8: push eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E13F9: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E13FC: push ecx */
    PUSH32(esp, 1); /* 0x004E13FD: push 1 */
    edx = MEM32(ebp + 0x20); /* 0x004E13FF: mov edx, dword ptr [ebp + 0x20] */
    PUSH32(esp, edx); /* 0x004E1402: push edx */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E1403: call dword ptr [0x8586f0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E1409: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E140C: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E1414; /* 0x004E1410: jne 0x4e1414 */

L_004E1412:
    goto L_004E1435; /* 0x004E1412: jmp 0x4e1435 */

L_004E1414:
    PUSH32(esp, 2); /* 0x004E1414: push 2 */
    eax = MEM32(ebp + (-0x4)); /* 0x004E1416: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004E1419: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E141A: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E141F: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E1422: push 2 */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E1424: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E1427: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1428: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E142D: add esp, 8 */
    eax = MEM32(ebp + (-0x10)); /* 0x004E1430: mov eax, dword ptr [ebp - 0x10] */
    goto L_004E1453; /* 0x004E1433: jmp 0x4e1453 */

L_004E1435:
    PUSH32(esp, 2); /* 0x004E1435: push 2 */
    edx = MEM32(ebp + (-0x4)); /* 0x004E1437: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E143A: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E143B: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1440: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E1443: push 2 */
    eax = MEM32(ebp + (-0xC)); /* 0x004E1445: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E1448: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1449: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E144E: add esp, 8 */
    eax = 0; /* 0x004E1451: xor eax, eax */

L_004E1453:
    esp = ebp; /* 0x004E1453: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1455: pop ebp */
    return; /* 0x004E1456: ret  */

}

void sub_004E12F0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E12F0:
    PUSH32(esp, 0x220u); /* 0x004E12F0: push 0x220 */
    edx = MEM32(ebp + 0x20); /* 0x004E12F5: mov edx, dword ptr [ebp + 0x20] */
    PUSH32(esp, edx); /* 0x004E12F8: push edx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E12F9: call dword ptr [0x8586e0] */
    /* test eax, eax */ /* 0x004E12FF: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E1308; /* 0x004E1301: jne 0x4e1308 */

L_004E1303:
    goto L_004E1435; /* 0x004E1303: jmp 0x4e1435 */

L_004E1308:
    PUSH32(esp, 0); /* 0x004E1308: push 0 */
    PUSH32(esp, 0); /* 0x004E130A: push 0 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E130C: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E130F: push eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E1310: mov ecx, dword ptr [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004E1313: push ecx */
    edx = MEM32(ebp + 0xC); /* 0x004E1314: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004E1317: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004E1318: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004E131B: push eax */
    RECOMP_ICALL(MEM32(0x8586B4)); /* 0x004E131C: call dword ptr [0x8586b4] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E1322: mov dword ptr [ebp - 0x14], eax */
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004E1325: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004E1330; /* 0x004E1329: jne 0x4e1330 */

L_004E132B:
    goto L_004E1435; /* 0x004E132B: jmp 0x4e1435 */

L_004E1330:
    PUSH32(esp, 0xDBu); /* 0x004E1330: push 0xdb */
    PUSH32(esp, 0x004F470Cu); /* 0x004E1335: push 0x4f470c */
    PUSH32(esp, 2); /* 0x004E133A: push 2 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E133C: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E133F: push ecx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E1340: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E1345: add esp, 0x10 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E1348: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E134B: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E1356; /* 0x004E134F: jne 0x4e1356 */

L_004E1351:
    goto L_004E1435; /* 0x004E1351: jmp 0x4e1435 */

L_004E1356:
    edx = MEM32(ebp + (-0x14)); /* 0x004E1356: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E1359: push edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E135A: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E135D: push eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E135E: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004E1361: push ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004E1362: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E1365: push edx */
    eax = MEM32(ebp + 0xC); /* 0x004E1366: mov eax, dword ptr [ebp + 0xc] */
    PUSH32(esp, eax); /* 0x004E1369: push eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E136A: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004E136D: push ecx */
    RECOMP_ICALL(MEM32(0x8586B4)); /* 0x004E136E: call dword ptr [0x8586b4] */
    /* test eax, eax */ /* 0x004E1374: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E137D; /* 0x004E1376: jne 0x4e137d */

L_004E1378:
    goto L_004E1435; /* 0x004E1378: jmp 0x4e1435 */

L_004E137D:
    edx = MEM32(ebp + 0xC); /* 0x004E137D: mov edx, dword ptr [ebp + 0xc] */
    edx = edx & 0x400u; /* 0x004E1380: and edx, 0x400 */
    /* test edx, edx */ /* 0x004E1386: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004E13C2; /* 0x004E1388: je 0x4e13c2 */

L_004E138A:
    eax = MEM32(ebp + (-0x14)); /* 0x004E138A: mov eax, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E138D: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E1390: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_EQ(MEM32(ebp + 0x1C), 0)) goto L_004E13C0; /* 0x004E1394: je 0x4e13c0 */

L_004E1396:
    ecx = MEM32(ebp + 0x1C); /* 0x004E1396: mov ecx, dword ptr [ebp + 0x1c] */
    /* cmp ecx, MEM32(ebp + (-0x14)) */ /* 0x004E1399: cmp ecx, dword ptr [ebp - 0x14] */
    if (CMP_GE(ecx, MEM32(ebp + (-0x14)))) goto L_004E13A6; /* 0x004E139C: jge 0x4e13a6 */

L_004E139E:
    edx = MEM32(ebp + 0x1C); /* 0x004E139E: mov edx, dword ptr [ebp + 0x1c] */
    MEM32(ebp + (-0x18)) = edx; /* 0x004E13A1: mov dword ptr [ebp - 0x18], edx */
    goto L_004E13AC; /* 0x004E13A4: jmp 0x4e13ac */

L_004E13A6:
    eax = MEM32(ebp + (-0x14)); /* 0x004E13A6: mov eax, dword ptr [ebp - 0x14] */
    MEM32(ebp + (-0x18)) = eax; /* 0x004E13A9: mov dword ptr [ebp - 0x18], eax */

L_004E13AC:
    ecx = MEM32(ebp + (-0x18)); /* 0x004E13AC: mov ecx, dword ptr [ebp - 0x18] */
    PUSH32(esp, ecx); /* 0x004E13AF: push ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004E13B0: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E13B3: push edx */
    eax = MEM32(ebp + 0x18); /* 0x004E13B4: mov eax, dword ptr [ebp + 0x18] */
    PUSH32(esp, eax); /* 0x004E13B7: push eax */
    RECOMP_CALL(sub_004D1B70); /* 0x004E13B8: call 0x4d1b70 */
    esp = esp + 0xCu; /* 0x004E13BD: add esp, 0xc */

L_004E13C0:
    goto L_004E1414; /* 0x004E13C0: jmp 0x4e1414 */

L_004E13C2:
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E13C2: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_NE(MEM32(ebp + 0x1C), 0)) goto L_004E13ED; /* 0x004E13C6: jne 0x4e13ed */

L_004E13C8:
    PUSH32(esp, 0); /* 0x004E13C8: push 0 */
    PUSH32(esp, 0); /* 0x004E13CA: push 0 */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E13CC: mov ecx, dword ptr [ebp - 0x14] */
    PUSH32(esp, ecx); /* 0x004E13CF: push ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004E13D0: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E13D3: push edx */
    PUSH32(esp, 1); /* 0x004E13D4: push 1 */
    eax = MEM32(ebp + 0x20); /* 0x004E13D6: mov eax, dword ptr [ebp + 0x20] */
    PUSH32(esp, eax); /* 0x004E13D9: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E13DA: call dword ptr [0x8586f0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E13E0: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E13E3: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E13EB; /* 0x004E13E7: jne 0x4e13eb */

L_004E13E9:
    goto L_004E1435; /* 0x004E13E9: jmp 0x4e1435 */

L_004E13EB:
    goto L_004E1414; /* 0x004E13EB: jmp 0x4e1414 */

L_004E13ED:
    ecx = MEM32(ebp + 0x1C); /* 0x004E13ED: mov ecx, dword ptr [ebp + 0x1c] */
    PUSH32(esp, ecx); /* 0x004E13F0: push ecx */
    edx = MEM32(ebp + 0x18); /* 0x004E13F1: mov edx, dword ptr [ebp + 0x18] */
    PUSH32(esp, edx); /* 0x004E13F4: push edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004E13F5: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E13F8: push eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E13F9: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E13FC: push ecx */
    PUSH32(esp, 1); /* 0x004E13FD: push 1 */
    edx = MEM32(ebp + 0x20); /* 0x004E13FF: mov edx, dword ptr [ebp + 0x20] */
    PUSH32(esp, edx); /* 0x004E1402: push edx */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E1403: call dword ptr [0x8586f0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E1409: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E140C: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E1414; /* 0x004E1410: jne 0x4e1414 */

L_004E1412:
    goto L_004E1435; /* 0x004E1412: jmp 0x4e1435 */

L_004E1414:
    PUSH32(esp, 2); /* 0x004E1414: push 2 */
    eax = MEM32(ebp + (-0x4)); /* 0x004E1416: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004E1419: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E141A: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E141F: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E1422: push 2 */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E1424: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E1427: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1428: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E142D: add esp, 8 */
    eax = MEM32(ebp + (-0x10)); /* 0x004E1430: mov eax, dword ptr [ebp - 0x10] */
    goto L_004E1453; /* 0x004E1433: jmp 0x4e1453 */

L_004E1435:
    PUSH32(esp, 2); /* 0x004E1435: push 2 */
    edx = MEM32(ebp + (-0x4)); /* 0x004E1437: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E143A: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E143B: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1440: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E1443: push 2 */
    eax = MEM32(ebp + (-0xC)); /* 0x004E1445: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E1448: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1449: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E144E: add esp, 8 */
    eax = 0; /* 0x004E1451: xor eax, eax */

L_004E1453:
    esp = ebp; /* 0x004E1453: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1455: pop ebp */
    return; /* 0x004E1456: ret  */

}

void sub_004E15D0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E15D0:
    edi = edi + 1; /* 0x004E15D0: inc edi */
    edi = edi - 1; /* 0x004E15D1: dec edi */
    MEM8(edx + 0x2) = (uint8_t)(MEM8(edx + 0x2) + HI8(ecx)); /* 0x004E15D2: add byte ptr [edx + 2], ch */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E15D5: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx << 1; /* 0x004E15D8: shl ecx, 1 */
    PUSH32(esp, ecx); /* 0x004E15DA: push ecx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E15DB: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E15E0: add esp, 0x10 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E15E3: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E15E6: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E15F3; /* 0x004E15EA: jne 0x4e15f3 */

L_004E15EC:
    eax = 0; /* 0x004E15EC: xor eax, eax */
    goto L_004E1780; /* 0x004E15EE: jmp 0x4e1780 */

L_004E15F3:
    edx = MEM32(ebp + (-0x4)); /* 0x004E15F3: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E15F6: push edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E15F7: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E15FA: push eax */
    ecx = MEM32(ebp + 0x14); /* 0x004E15FB: mov ecx, dword ptr [ebp + 0x14] */
    PUSH32(esp, ecx); /* 0x004E15FE: push ecx */
    edx = MEM32(ebp + 0x10); /* 0x004E15FF: mov edx, dword ptr [ebp + 0x10] */
    PUSH32(esp, edx); /* 0x004E1602: push edx */
    PUSH32(esp, 1); /* 0x004E1603: push 1 */
    eax = MEM32(ebp + 0x20); /* 0x004E1605: mov eax, dword ptr [ebp + 0x20] */
    PUSH32(esp, eax); /* 0x004E1608: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E1609: call dword ptr [0x8586f0] */
    /* test eax, eax */ /* 0x004E160F: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E1618; /* 0x004E1611: jne 0x4e1618 */

L_004E1613:
    goto L_004E1762; /* 0x004E1613: jmp 0x4e1762 */

L_004E1618:
    PUSH32(esp, 0); /* 0x004E1618: push 0 */
    PUSH32(esp, 0); /* 0x004E161A: push 0 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E161C: mov ecx, dword ptr [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004E161F: push ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004E1620: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E1623: push edx */
    eax = MEM32(ebp + 0xC); /* 0x004E1624: mov eax, dword ptr [ebp + 0xc] */
    PUSH32(esp, eax); /* 0x004E1627: push eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E1628: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004E162B: push ecx */
    RECOMP_ICALL(MEM32(0x8586B0)); /* 0x004E162C: call dword ptr [0x8586b0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E1632: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E1635: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E1640; /* 0x004E1639: jne 0x4e1640 */

L_004E163B:
    goto L_004E1762; /* 0x004E163B: jmp 0x4e1762 */

L_004E1640:
    edx = MEM32(ebp + 0xC); /* 0x004E1640: mov edx, dword ptr [ebp + 0xc] */
    edx = edx & 0x400u; /* 0x004E1643: and edx, 0x400 */
    /* test edx, edx */ /* 0x004E1649: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004E168C; /* 0x004E164B: je 0x4e168c */

L_004E164D:
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E164D: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_EQ(MEM32(ebp + 0x1C), 0)) goto L_004E1687; /* 0x004E1651: je 0x4e1687 */

L_004E1653:
    eax = MEM32(ebp + (-0x10)); /* 0x004E1653: mov eax, dword ptr [ebp - 0x10] */
    /* cmp eax, MEM32(ebp + 0x1C) */ /* 0x004E1656: cmp eax, dword ptr [ebp + 0x1c] */
    if (CMP_LE(eax, MEM32(ebp + 0x1C))) goto L_004E1660; /* 0x004E1659: jle 0x4e1660 */

L_004E165B:
    goto L_004E1762; /* 0x004E165B: jmp 0x4e1762 */

L_004E1660:
    ecx = MEM32(ebp + 0x1C); /* 0x004E1660: mov ecx, dword ptr [ebp + 0x1c] */
    PUSH32(esp, ecx); /* 0x004E1663: push ecx */
    edx = MEM32(ebp + 0x18); /* 0x004E1664: mov edx, dword ptr [ebp + 0x18] */
    PUSH32(esp, edx); /* 0x004E1667: push edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E1668: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004E166B: push eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E166C: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E166F: push ecx */
    edx = MEM32(ebp + 0xC); /* 0x004E1670: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004E1673: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004E1674: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004E1677: push eax */
    RECOMP_ICALL(MEM32(0x8586B0)); /* 0x004E1678: call dword ptr [0x8586b0] */
    /* test eax, eax */ /* 0x004E167E: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E1687; /* 0x004E1680: jne 0x4e1687 */

L_004E1682:
    goto L_004E1762; /* 0x004E1682: jmp 0x4e1762 */

L_004E1687:
    goto L_004E1741; /* 0x004E1687: jmp 0x4e1741 */

L_004E168C:
    ecx = MEM32(ebp + (-0x10)); /* 0x004E168C: mov ecx, dword ptr [ebp - 0x10] */
    MEM32(ebp + (-0x14)) = ecx; /* 0x004E168F: mov dword ptr [ebp - 0x14], ecx */
    PUSH32(esp, 0x198u); /* 0x004E1692: push 0x198 */
    PUSH32(esp, 0x004F470Cu); /* 0x004E1697: push 0x4f470c */
    PUSH32(esp, 2); /* 0x004E169C: push 2 */
    edx = MEM32(ebp + (-0x14)); /* 0x004E169E: mov edx, dword ptr [ebp - 0x14] */
    edx = edx << 1; /* 0x004E16A1: shl edx, 1 */
    PUSH32(esp, edx); /* 0x004E16A3: push edx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E16A4: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E16A9: add esp, 0x10 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E16AC: mov dword ptr [ebp - 8], eax */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E16AF: cmp dword ptr [ebp - 8], 0 */
    if (CMP_NE(MEM32(ebp + (-0x8)), 0)) goto L_004E16BA; /* 0x004E16B3: jne 0x4e16ba */

L_004E16B5:
    goto L_004E1762; /* 0x004E16B5: jmp 0x4e1762 */

L_004E16BA:
    eax = MEM32(ebp + (-0x14)); /* 0x004E16BA: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E16BD: push eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E16BE: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004E16C1: push ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004E16C2: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E16C5: push edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E16C6: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E16C9: push eax */
    ecx = MEM32(ebp + 0xC); /* 0x004E16CA: mov ecx, dword ptr [ebp + 0xc] */
    PUSH32(esp, ecx); /* 0x004E16CD: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E16CE: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E16D1: push edx */
    RECOMP_ICALL(MEM32(0x8586B0)); /* 0x004E16D2: call dword ptr [0x8586b0] */
    /* test eax, eax */ /* 0x004E16D8: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E16E1; /* 0x004E16DA: jne 0x4e16e1 */

L_004E16DC:
    goto L_004E1762; /* 0x004E16DC: jmp 0x4e1762 */

L_004E16E1:
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E16E1: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_NE(MEM32(ebp + 0x1C), 0)) goto L_004E1713; /* 0x004E16E5: jne 0x4e1713 */

L_004E16E7:
    PUSH32(esp, 0); /* 0x004E16E7: push 0 */
    PUSH32(esp, 0); /* 0x004E16E9: push 0 */
    PUSH32(esp, 0); /* 0x004E16EB: push 0 */
    PUSH32(esp, 0); /* 0x004E16ED: push 0 */
    eax = MEM32(ebp + (-0x14)); /* 0x004E16EF: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E16F2: push eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E16F3: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004E16F6: push ecx */
    PUSH32(esp, 0x220u); /* 0x004E16F7: push 0x220 */
    edx = MEM32(ebp + 0x20); /* 0x004E16FC: mov edx, dword ptr [ebp + 0x20] */
    PUSH32(esp, edx); /* 0x004E16FF: push edx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E1700: call dword ptr [0x8586e0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E1706: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E1709: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E1711; /* 0x004E170D: jne 0x4e1711 */

L_004E170F:
    goto L_004E1762; /* 0x004E170F: jmp 0x4e1762 */

L_004E1711:
    goto L_004E1741; /* 0x004E1711: jmp 0x4e1741 */

L_004E1713:
    PUSH32(esp, 0); /* 0x004E1713: push 0 */
    PUSH32(esp, 0); /* 0x004E1715: push 0 */
    eax = MEM32(ebp + 0x1C); /* 0x004E1717: mov eax, dword ptr [ebp + 0x1c] */
    PUSH32(esp, eax); /* 0x004E171A: push eax */
    ecx = MEM32(ebp + 0x18); /* 0x004E171B: mov ecx, dword ptr [ebp + 0x18] */
    PUSH32(esp, ecx); /* 0x004E171E: push ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004E171F: mov edx, dword ptr [ebp - 0x14] */
    PUSH32(esp, edx); /* 0x004E1722: push edx */
    eax = MEM32(ebp + (-0x8)); /* 0x004E1723: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E1726: push eax */
    PUSH32(esp, 0x220u); /* 0x004E1727: push 0x220 */
    ecx = MEM32(ebp + 0x20); /* 0x004E172C: mov ecx, dword ptr [ebp + 0x20] */
    PUSH32(esp, ecx); /* 0x004E172F: push ecx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E1730: call dword ptr [0x8586e0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E1736: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E1739: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E1741; /* 0x004E173D: jne 0x4e1741 */

L_004E173F:
    goto L_004E1762; /* 0x004E173F: jmp 0x4e1762 */

L_004E1741:
    PUSH32(esp, 2); /* 0x004E1741: push 2 */
    edx = MEM32(ebp + (-0xC)); /* 0x004E1743: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E1746: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1747: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E174C: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E174F: push 2 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E1751: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E1754: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1755: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E175A: add esp, 8 */
    eax = MEM32(ebp + (-0x10)); /* 0x004E175D: mov eax, dword ptr [ebp - 0x10] */
    goto L_004E1780; /* 0x004E1760: jmp 0x4e1780 */

L_004E1762:
    PUSH32(esp, 2); /* 0x004E1762: push 2 */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E1764: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E1767: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1768: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E176D: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E1770: push 2 */
    edx = MEM32(ebp + (-0x8)); /* 0x004E1772: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004E1775: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1776: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E177B: add esp, 8 */
    eax = 0; /* 0x004E177E: xor eax, eax */

L_004E1780:
    esp = ebp; /* 0x004E1780: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1782: pop ebp */
    return; /* 0x004E1783: ret  */

}

void sub_004E1650(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1650:
    MEM8(esp + esi + (-0x75)) = (uint8_t)(MEM8(esp + esi + (-0x75)) + HI8(edx)); /* 0x004E1650: add byte ptr [esp + esi - 0x75], dh */
    ebp = ebp + 1; /* 0x004E1654: inc ebp */

}

void sub_004E1740(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1740:
    MEM32(edx + 0x2) = MEM32(edx + 0x2) & ebp; /* 0x004E1740: and dword ptr [edx + 2], ebp */
    edx = MEM32(ebp + (-0xC)); /* 0x004E1743: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E1746: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1747: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E174C: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E174F: push 2 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E1751: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E1754: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1755: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E175A: add esp, 8 */
    eax = MEM32(ebp + (-0x10)); /* 0x004E175D: mov eax, dword ptr [ebp - 0x10] */
    goto L_004E1780; /* 0x004E1760: jmp 0x4e1780 */

L_004E1780:
    esp = ebp; /* 0x004E1780: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1782: pop ebp */
    return; /* 0x004E1783: ret  */

}

void sub_004E1780(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1780:
    esp = ebp; /* 0x004E1780: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1782: pop ebp */
    return; /* 0x004E1783: ret  */

}

void sub_004E1830(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1830:
    MEM8(esp + ecx + (-0x39)) = (uint8_t)(MEM8(esp + ecx + (-0x39)) << 5); /* 0x004E1830: sal byte ptr [esp + ecx - 0x39], 5 */
    _st[0] = *(double*)ADDR(esp + eax * 4 + 0x200) / _st[0]; /* 0x004E1835: fdivr qword ptr [esp + eax*4 + 0x200] */
    SET_LO8(ebx, LO8(ebx) + HI8(ecx)); /* 0x004E183C: add bl, ch */
    _seg_es = POP32_VAL(esp); /* 0x004E183E: pop es */
    eax = 0; /* 0x004E183F: xor eax, eax */
    goto L_004E1A6E; /* 0x004E1841: jmp 0x4e1a6e */

L_004E1A6E:
    esp = ebp; /* 0x004E1A6E: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1A70: pop ebp */
    return; /* 0x004E1A71: ret  */

}

void sub_004E1890(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1890:
    RECOMP_CALL(sub_004E1897); /* 0x004E1890: call 0x4e1897 */
    goto L_004E18AD; /* 0x004E1895: jmp 0x4e18ad */

L_004E18AD:
    eax = MEM32(ebp + (-0x18)); /* 0x004E18AD: mov eax, dword ptr [ebp - 0x18] */
    goto L_004E1A6E; /* 0x004E18B0: jmp 0x4e1a6e */

L_004E1A6E:
    esp = ebp; /* 0x004E1A6E: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1A70: pop ebp */
    return; /* 0x004E1A71: ret  */

}

void sub_004E1900(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1900:
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E1900: add byte ptr [eax], al */
    MEM8(ebx + 0x7500207D) = (uint8_t)(MEM8(ebx + 0x7500207D) + LO8(eax)); /* 0x004E1902: add byte ptr [ebx + 0x7500207d], al */
    MEM32(ebx + (-0x7B432FF3)) = MEM32(ebx + (-0x7B432FF3)) | ecx; /* 0x004E1908: or dword ptr [ebx - 0x7b432ff3], ecx */
    MEM8(ecx + 0x6A204D) = (uint8_t)(MEM8(ecx + 0x6A204D) + LO8(ecx)); /* 0x004E190E: add byte ptr [ecx + 0x6a204d], cl */
    PUSH32(esp, 0); /* 0x004E1914: push 0 */
    PUSH32(esp, 0); /* 0x004E1916: push 0 */
    PUSH32(esp, 0); /* 0x004E1918: push 0 */
    edx = MEM32(ebp + 0x14); /* 0x004E191A: mov edx, dword ptr [ebp + 0x14] */
    PUSH32(esp, edx); /* 0x004E191D: push edx */
    eax = MEM32(ebp + 0x10); /* 0x004E191E: mov eax, dword ptr [ebp + 0x10] */
    PUSH32(esp, eax); /* 0x004E1921: push eax */
    PUSH32(esp, 0x220u); /* 0x004E1922: push 0x220 */
    ecx = MEM32(ebp + 0x20); /* 0x004E1927: mov ecx, dword ptr [ebp + 0x20] */
    PUSH32(esp, ecx); /* 0x004E192A: push ecx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E192B: call dword ptr [0x8586e0] */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E1931: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E1934: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E1941; /* 0x004E1938: jne 0x4e1941 */

L_004E193A:
    eax = 0; /* 0x004E193A: xor eax, eax */
    goto L_004E1A6E; /* 0x004E193C: jmp 0x4e1a6e */

L_004E1941:
    PUSH32(esp, 0xC4u); /* 0x004E1941: push 0xc4 */
    PUSH32(esp, 0x004F4718u); /* 0x004E1946: push 0x4f4718 */
    PUSH32(esp, 2); /* 0x004E194B: push 2 */
    edx = MEM32(ebp + (-0xC)); /* 0x004E194D: mov edx, dword ptr [ebp - 0xc] */
    PUSH32(esp, edx); /* 0x004E1950: push edx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E1951: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E1956: add esp, 0x10 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E1959: mov dword ptr [ebp - 8], eax */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E195C: cmp dword ptr [ebp - 8], 0 */
    if (CMP_NE(MEM32(ebp + (-0x8)), 0)) goto L_004E1969; /* 0x004E1960: jne 0x4e1969 */

L_004E1962:
    eax = 0; /* 0x004E1962: xor eax, eax */
    goto L_004E1A6E; /* 0x004E1964: jmp 0x4e1a6e */

L_004E1969:
    PUSH32(esp, 0); /* 0x004E1969: push 0 */
    PUSH32(esp, 0); /* 0x004E196B: push 0 */
    eax = MEM32(ebp + (-0xC)); /* 0x004E196D: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E1970: push eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E1971: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004E1974: push ecx */
    edx = MEM32(ebp + 0x14); /* 0x004E1975: mov edx, dword ptr [ebp + 0x14] */
    PUSH32(esp, edx); /* 0x004E1978: push edx */
    eax = MEM32(ebp + 0x10); /* 0x004E1979: mov eax, dword ptr [ebp + 0x10] */
    PUSH32(esp, eax); /* 0x004E197C: push eax */
    PUSH32(esp, 0x220u); /* 0x004E197D: push 0x220 */
    ecx = MEM32(ebp + 0x20); /* 0x004E1982: mov ecx, dword ptr [ebp + 0x20] */
    PUSH32(esp, ecx); /* 0x004E1985: push ecx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E1986: call dword ptr [0x8586e0] */
    /* test eax, eax */ /* 0x004E198C: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E1995; /* 0x004E198E: jne 0x4e1995 */

L_004E1990:
    goto L_004E1A50; /* 0x004E1990: jmp 0x4e1a50 */

L_004E1995:
    PUSH32(esp, 0); /* 0x004E1995: push 0 */
    PUSH32(esp, 0); /* 0x004E1997: push 0 */
    PUSH32(esp, 0); /* 0x004E1999: push 0 */
    PUSH32(esp, 0); /* 0x004E199B: push 0 */
    edx = MEM32(ebp + 0x1C); /* 0x004E199D: mov edx, dword ptr [ebp + 0x1c] */
    PUSH32(esp, edx); /* 0x004E19A0: push edx */
    eax = MEM32(ebp + 0x18); /* 0x004E19A1: mov eax, dword ptr [ebp + 0x18] */
    PUSH32(esp, eax); /* 0x004E19A4: push eax */
    PUSH32(esp, 0x220u); /* 0x004E19A5: push 0x220 */
    ecx = MEM32(ebp + 0x20); /* 0x004E19AA: mov ecx, dword ptr [ebp + 0x20] */
    PUSH32(esp, ecx); /* 0x004E19AD: push ecx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E19AE: call dword ptr [0x8586e0] */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E19B4: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E19B7: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E19C2; /* 0x004E19BB: jne 0x4e19c2 */

L_004E19BD:
    goto L_004E1A50; /* 0x004E19BD: jmp 0x4e1a50 */

L_004E19C2:
    PUSH32(esp, 0xD5u); /* 0x004E19C2: push 0xd5 */
    PUSH32(esp, 0x004F4718u); /* 0x004E19C7: push 0x4f4718 */
    PUSH32(esp, 2); /* 0x004E19CC: push 2 */
    edx = MEM32(ebp + (-0x10)); /* 0x004E19CE: mov edx, dword ptr [ebp - 0x10] */
    PUSH32(esp, edx); /* 0x004E19D1: push edx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E19D2: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E19D7: add esp, 0x10 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E19DA: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004E19DD: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004E19E5; /* 0x004E19E1: jne 0x4e19e5 */

L_004E19E3:
    goto L_004E1A50; /* 0x004E19E3: jmp 0x4e1a50 */

L_004E19E5:
    PUSH32(esp, 0); /* 0x004E19E5: push 0 */
    PUSH32(esp, 0); /* 0x004E19E7: push 0 */
    eax = MEM32(ebp + (-0x10)); /* 0x004E19E9: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004E19EC: push eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E19ED: mov ecx, dword ptr [ebp - 4] */
    PUSH32(esp, ecx); /* 0x004E19F0: push ecx */
    edx = MEM32(ebp + 0x1C); /* 0x004E19F1: mov edx, dword ptr [ebp + 0x1c] */
    PUSH32(esp, edx); /* 0x004E19F4: push edx */
    eax = MEM32(ebp + 0x18); /* 0x004E19F5: mov eax, dword ptr [ebp + 0x18] */
    PUSH32(esp, eax); /* 0x004E19F8: push eax */
    PUSH32(esp, 0x220u); /* 0x004E19F9: push 0x220 */
    ecx = MEM32(ebp + 0x20); /* 0x004E19FE: mov ecx, dword ptr [ebp + 0x20] */
    PUSH32(esp, ecx); /* 0x004E1A01: push ecx */
    RECOMP_ICALL(MEM32(0x8586E0)); /* 0x004E1A02: call dword ptr [0x8586e0] */
    /* test eax, eax */ /* 0x004E1A08: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E1A0E; /* 0x004E1A0A: jne 0x4e1a0e */

L_004E1A0C:
    goto L_004E1A50; /* 0x004E1A0C: jmp 0x4e1a50 */

L_004E1A0E:
    edx = MEM32(ebp + (-0x10)); /* 0x004E1A0E: mov edx, dword ptr [ebp - 0x10] */
    PUSH32(esp, edx); /* 0x004E1A11: push edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E1A12: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004E1A15: push eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E1A16: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E1A19: push ecx */
    edx = MEM32(ebp + (-0x8)); /* 0x004E1A1A: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004E1A1D: push edx */
    eax = MEM32(ebp + 0xC); /* 0x004E1A1E: mov eax, dword ptr [ebp + 0xc] */
    PUSH32(esp, eax); /* 0x004E1A21: push eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E1A22: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004E1A25: push ecx */
    RECOMP_ICALL(MEM32(0x8586AC)); /* 0x004E1A26: call dword ptr [0x8586ac] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E1A2C: mov dword ptr [ebp - 0x14], eax */
    PUSH32(esp, 2); /* 0x004E1A2F: push 2 */
    edx = MEM32(ebp + (-0x8)); /* 0x004E1A31: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004E1A34: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1A35: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1A3A: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E1A3D: push 2 */
    eax = MEM32(ebp + (-0x4)); /* 0x004E1A3F: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004E1A42: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1A43: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1A48: add esp, 8 */
    eax = MEM32(ebp + (-0x14)); /* 0x004E1A4B: mov eax, dword ptr [ebp - 0x14] */
    goto L_004E1A6E; /* 0x004E1A4E: jmp 0x4e1a6e */

L_004E1A50:
    PUSH32(esp, 2); /* 0x004E1A50: push 2 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E1A52: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004E1A55: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1A56: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1A5B: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E1A5E: push 2 */
    edx = MEM32(ebp + (-0x4)); /* 0x004E1A60: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E1A63: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1A64: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1A69: add esp, 8 */
    eax = 0; /* 0x004E1A6C: xor eax, eax */

L_004E1A6E:
    esp = ebp; /* 0x004E1A6E: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1A70: pop ebp */
    return; /* 0x004E1A71: ret  */

}

void sub_004E1A40(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1A40:
    ebp = ebp + 1; /* 0x004E1A40: inc ebp */
    _df = 1; /* 0x004E1A41: cld  */
    PUSH32(esp, eax); /* 0x004E1A42: push eax */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1A43: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1A48: add esp, 8 */
    eax = MEM32(ebp + (-0x14)); /* 0x004E1A4B: mov eax, dword ptr [ebp - 0x14] */
    goto L_004E1A6E; /* 0x004E1A4E: jmp 0x4e1a6e */

L_004E1A6E:
    esp = ebp; /* 0x004E1A6E: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1A70: pop ebp */
    return; /* 0x004E1A71: ret  */

}

void sub_004E1A78(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1A78:
    /* int3 breakpoint */ /* 0x004E1A78: int3  */

}

void sub_004E1C87(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1C41:
    /* cmp MEM32(ebp + 0x14), 0 */ /* 0x004E1C41: cmp dword ptr [ebp + 0x14], 0 */
    if (CMP_NE(MEM32(ebp + 0x14), 0)) goto L_004E1C4D; /* 0x004E1C45: jne 0x4e1c4d */

L_004E1C47:
    /* cmp MEM32(ebp + 0x1C), 1 */ /* 0x004E1C47: cmp dword ptr [ebp + 0x1c], 1 */
    if (CMP_EQ(MEM32(ebp + 0x1C), 1)) goto L_004E1C7A; /* 0x004E1C4B: je 0x4e1c7a */

L_004E1C4D:
    /* cmp MEM32(ebp + 0x14), 1 */ /* 0x004E1C4D: cmp dword ptr [ebp + 0x14], 1 */
    if (CMP_NE(MEM32(ebp + 0x14), 1)) goto L_004E1C59; /* 0x004E1C51: jne 0x4e1c59 */

L_004E1C53:
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E1C53: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_EQ(MEM32(ebp + 0x1C), 0)) goto L_004E1C7A; /* 0x004E1C57: je 0x4e1c7a */

L_004E1C59:
    PUSH32(esp, 0x004F4724u); /* 0x004E1C59: push 0x4f4724 */
    PUSH32(esp, 0); /* 0x004E1C5E: push 0 */
    PUSH32(esp, 0x163u); /* 0x004E1C60: push 0x163 */
    PUSH32(esp, 0x004F4718u); /* 0x004E1C65: push 0x4f4718 */
    PUSH32(esp, 2); /* 0x004E1C6A: push 2 */
    RECOMP_CALL(sub_004D7D40); /* 0x004E1C6C: call 0x4d7d40 */
    esp = esp + 0x14u; /* 0x004E1C71: add esp, 0x14 */
    /* cmp eax, 1 */ /* 0x004E1C74: cmp eax, 1 */
    if (CMP_NE(eax, 1)) goto L_004E1C7A; /* 0x004E1C77: jne 0x4e1c7a */

L_004E1C61:
    /* UNIMPLEMENTED: arpl word ptr [ecx], ax */ /* 0x004E1C61: arpl word ptr [ecx], ax */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E1C63: add byte ptr [eax], al */
    PUSH32(esp, 0x004F4718u); /* 0x004E1C65: push 0x4f4718 */
    PUSH32(esp, 2); /* 0x004E1C6A: push 2 */
    RECOMP_CALL(sub_004D7D40); /* 0x004E1C6C: call 0x4d7d40 */
    esp = esp + 0x14u; /* 0x004E1C71: add esp, 0x14 */
    /* cmp eax, 1 */ /* 0x004E1C74: cmp eax, 1 */
    if (CMP_NE(eax, 1)) goto L_004E1C7A; /* 0x004E1C77: jne 0x4e1c7a */

L_004E1C79:
    /* int3 breakpoint */ /* 0x004E1C79: int3  */

L_004E1C7A:
    edx = 0; /* 0x004E1C7A: xor edx, edx */
    /* test edx, edx */ /* 0x004E1C7C: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004E1C41; /* 0x004E1C7E: jne 0x4e1c41 */

L_004E1C80:
    /* cmp MEM32(ebp + 0x14), 0 */ /* 0x004E1C80: cmp dword ptr [ebp + 0x14], 0 */
    if (CMP_LE(MEM32(ebp + 0x14), 0)) goto L_004E1CF9; /* 0x004E1C84: jle 0x4e1cf9 */

L_004E1C86:
    /* cmp MEM32(ebp + (-0x28)), 2 */ /* 0x004E1C86: cmp dword ptr [ebp - 0x28], 2 */
    if (CMP_AE(MEM32(ebp + (-0x28)), 2)) goto L_004E1C96; /* 0x004E1C8A: jae 0x4e1c96 */

L_004E1C87:
    if (/* no flag state for jge */ _cf) goto L_004E1C61; /* 0x004E1C87: jge 0x4e1c61 */

L_004E1C89:
    SET_HI8(edx, HI8(edx) + MEM8(ebx + 0xA)); /* 0x004E1C89: add dh, byte ptr [ebx + 0xa] */

L_004E1C8C:
    eax = 3; /* 0x004E1C8C: mov eax, 3 */
    goto L_004E1E93; /* 0x004E1C91: jmp 0x4e1e93 */

L_004E1C96:
    eax = ebp + (-0x22); /* 0x004E1C96: lea eax, [ebp - 0x22] */
    MEM32(ebp + (-0x2C)) = eax; /* 0x004E1C99: mov dword ptr [ebp - 0x2c], eax */
    goto L_004E1CA7; /* 0x004E1C9C: jmp 0x4e1ca7 */

L_004E1C9E:
    ecx = MEM32(ebp + (-0x2C)); /* 0x004E1C9E: mov ecx, dword ptr [ebp - 0x2c] */
    ecx = ecx + 2; /* 0x004E1CA1: add ecx, 2 */
    MEM32(ebp + (-0x2C)) = ecx; /* 0x004E1CA4: mov dword ptr [ebp - 0x2c], ecx */

L_004E1CA7:
    edx = MEM32(ebp + (-0x2C)); /* 0x004E1CA7: mov edx, dword ptr [ebp - 0x2c] */
    eax = 0; /* 0x004E1CAA: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E1CAC: mov al, byte ptr [edx] */
    /* test eax, eax */ /* 0x004E1CAE: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004E1CEF; /* 0x004E1CB0: je 0x4e1cef */

L_004E1CB2:
    ecx = MEM32(ebp + (-0x2C)); /* 0x004E1CB2: mov ecx, dword ptr [ebp - 0x2c] */
    edx = 0; /* 0x004E1CB5: xor edx, edx */
    SET_LO8(edx, MEM8(ecx + 0x1)); /* 0x004E1CB7: mov dl, byte ptr [ecx + 1] */
    /* test edx, edx */ /* 0x004E1CBA: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004E1CEF; /* 0x004E1CBC: je 0x4e1cef */

L_004E1CBE:
    eax = MEM32(ebp + 0x10); /* 0x004E1CBE: mov eax, dword ptr [ebp + 0x10] */
    ecx = 0; /* 0x004E1CC1: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E1CC3: mov cl, byte ptr [eax] */
    edx = MEM32(ebp + (-0x2C)); /* 0x004E1CC5: mov edx, dword ptr [ebp - 0x2c] */
    eax = 0; /* 0x004E1CC8: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E1CCA: mov al, byte ptr [edx] */
    /* cmp ecx, eax */ /* 0x004E1CCC: cmp ecx, eax */
    if (CMP_L(ecx, eax)) goto L_004E1CED; /* 0x004E1CCE: jl 0x4e1ced */

L_004E1CD0:
    ecx = MEM32(ebp + 0x10); /* 0x004E1CD0: mov ecx, dword ptr [ebp + 0x10] */
    edx = 0; /* 0x004E1CD3: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004E1CD5: mov dl, byte ptr [ecx] */
    eax = MEM32(ebp + (-0x2C)); /* 0x004E1CD7: mov eax, dword ptr [ebp - 0x2c] */
    ecx = 0; /* 0x004E1CDA: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x1)); /* 0x004E1CDC: mov cl, byte ptr [eax + 1] */
    /* cmp edx, ecx */ /* 0x004E1CDF: cmp edx, ecx */
    if (CMP_G(edx, ecx)) goto L_004E1CED; /* 0x004E1CE1: jg 0x4e1ced */

L_004E1CE3:
    eax = 2; /* 0x004E1CE3: mov eax, 2 */
    goto L_004E1E93; /* 0x004E1CE8: jmp 0x4e1e93 */

L_004E1CED:
    goto L_004E1C9E; /* 0x004E1CED: jmp 0x4e1c9e */

L_004E1CEF:
    eax = 3; /* 0x004E1CEF: mov eax, 3 */
    goto L_004E1E93; /* 0x004E1CF4: jmp 0x4e1e93 */

L_004E1CF9:
    /* cmp MEM32(ebp + 0x1C), 0 */ /* 0x004E1CF9: cmp dword ptr [ebp + 0x1c], 0 */
    if (CMP_LE(MEM32(ebp + 0x1C), 0)) goto L_004E1D72; /* 0x004E1CFD: jle 0x4e1d72 */

L_004E1CFF:
    /* cmp MEM32(ebp + (-0x28)), 2 */ /* 0x004E1CFF: cmp dword ptr [ebp - 0x28], 2 */
    if (CMP_AE(MEM32(ebp + (-0x28)), 2)) goto L_004E1D0F; /* 0x004E1D03: jae 0x4e1d0f */

L_004E1D05:
    eax = 1; /* 0x004E1D05: mov eax, 1 */
    goto L_004E1E93; /* 0x004E1D0A: jmp 0x4e1e93 */

L_004E1D0F:
    edx = ebp + (-0x22); /* 0x004E1D0F: lea edx, [ebp - 0x22] */
    MEM32(ebp + (-0x2C)) = edx; /* 0x004E1D12: mov dword ptr [ebp - 0x2c], edx */
    goto L_004E1D20; /* 0x004E1D15: jmp 0x4e1d20 */

L_004E1D17:
    eax = MEM32(ebp + (-0x2C)); /* 0x004E1D17: mov eax, dword ptr [ebp - 0x2c] */
    eax = eax + 2; /* 0x004E1D1A: add eax, 2 */
    MEM32(ebp + (-0x2C)) = eax; /* 0x004E1D1D: mov dword ptr [ebp - 0x2c], eax */

L_004E1D20:
    ecx = MEM32(ebp + (-0x2C)); /* 0x004E1D20: mov ecx, dword ptr [ebp - 0x2c] */
    edx = 0; /* 0x004E1D23: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004E1D25: mov dl, byte ptr [ecx] */
    /* test edx, edx */ /* 0x004E1D27: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004E1D68; /* 0x004E1D29: je 0x4e1d68 */

L_004E1D2B:
    eax = MEM32(ebp + (-0x2C)); /* 0x004E1D2B: mov eax, dword ptr [ebp - 0x2c] */
    ecx = 0; /* 0x004E1D2E: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x1)); /* 0x004E1D30: mov cl, byte ptr [eax + 1] */
    /* test ecx, ecx */ /* 0x004E1D33: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004E1D68; /* 0x004E1D35: je 0x4e1d68 */

L_004E1D37:
    edx = MEM32(ebp + 0x18); /* 0x004E1D37: mov edx, dword ptr [ebp + 0x18] */
    eax = 0; /* 0x004E1D3A: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E1D3C: mov al, byte ptr [edx] */
    ecx = MEM32(ebp + (-0x2C)); /* 0x004E1D3E: mov ecx, dword ptr [ebp - 0x2c] */
    edx = 0; /* 0x004E1D41: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004E1D43: mov dl, byte ptr [ecx] */
    /* cmp eax, edx */ /* 0x004E1D45: cmp eax, edx */
    if (CMP_L(eax, edx)) goto L_004E1D66; /* 0x004E1D47: jl 0x4e1d66 */

L_004E1D49:
    eax = MEM32(ebp + 0x18); /* 0x004E1D49: mov eax, dword ptr [ebp + 0x18] */
    ecx = 0; /* 0x004E1D4C: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E1D4E: mov cl, byte ptr [eax] */
    edx = MEM32(ebp + (-0x2C)); /* 0x004E1D50: mov edx, dword ptr [ebp - 0x2c] */
    eax = 0; /* 0x004E1D53: xor eax, eax */
    SET_LO8(eax, MEM8(edx + 0x1)); /* 0x004E1D55: mov al, byte ptr [edx + 1] */
    /* cmp ecx, eax */ /* 0x004E1D58: cmp ecx, eax */
    if (CMP_G(ecx, eax)) goto L_004E1D66; /* 0x004E1D5A: jg 0x4e1d66 */

L_004E1D5C:
    eax = 2; /* 0x004E1D5C: mov eax, 2 */
    goto L_004E1E93; /* 0x004E1D61: jmp 0x4e1e93 */

L_004E1D66:
    goto L_004E1D17; /* 0x004E1D66: jmp 0x4e1d17 */

L_004E1D68:
    eax = 1; /* 0x004E1D68: mov eax, 1 */
    goto L_004E1E93; /* 0x004E1D6D: jmp 0x4e1e93 */

L_004E1D72:
    PUSH32(esp, 0); /* 0x004E1D72: push 0 */
    PUSH32(esp, 0); /* 0x004E1D74: push 0 */
    ecx = MEM32(ebp + 0x14); /* 0x004E1D76: mov ecx, dword ptr [ebp + 0x14] */
    PUSH32(esp, ecx); /* 0x004E1D79: push ecx */
    edx = MEM32(ebp + 0x10); /* 0x004E1D7A: mov edx, dword ptr [ebp + 0x10] */
    PUSH32(esp, edx); /* 0x004E1D7D: push edx */
    PUSH32(esp, 9); /* 0x004E1D7E: push 9 */
    eax = MEM32(ebp + 0x20); /* 0x004E1D80: mov eax, dword ptr [ebp + 0x20] */
    PUSH32(esp, eax); /* 0x004E1D83: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E1D84: call dword ptr [0x8586f0] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E1D8A: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004E1D8D: cmp dword ptr [ebp - 4], 0 */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0)) goto L_004E1D9A; /* 0x004E1D91: jne 0x4e1d9a */

L_004E1D93:
    eax = 0; /* 0x004E1D93: xor eax, eax */
    goto L_004E1E93; /* 0x004E1D95: jmp 0x4e1e93 */

L_004E1D9A:
    PUSH32(esp, 0x18Bu); /* 0x004E1D9A: push 0x18b */
    PUSH32(esp, 0x004F4718u); /* 0x004E1D9F: push 0x4f4718 */
    PUSH32(esp, 2); /* 0x004E1DA4: push 2 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E1DA6: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx << 1; /* 0x004E1DA9: shl ecx, 1 */
    PUSH32(esp, ecx); /* 0x004E1DAB: push ecx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E1DAC: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E1DB1: add esp, 0x10 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E1DB4: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E1DB7: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E1DC4; /* 0x004E1DBB: jne 0x4e1dc4 */

L_004E1DBD:
    eax = 0; /* 0x004E1DBD: xor eax, eax */
    goto L_004E1E93; /* 0x004E1DBF: jmp 0x4e1e93 */

L_004E1DC4:
    edx = MEM32(ebp + (-0x4)); /* 0x004E1DC4: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E1DC7: push edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E1DC8: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E1DCB: push eax */
    ecx = MEM32(ebp + 0x14); /* 0x004E1DCC: mov ecx, dword ptr [ebp + 0x14] */
    PUSH32(esp, ecx); /* 0x004E1DCF: push ecx */
    edx = MEM32(ebp + 0x10); /* 0x004E1DD0: mov edx, dword ptr [ebp + 0x10] */
    PUSH32(esp, edx); /* 0x004E1DD3: push edx */
    PUSH32(esp, 1); /* 0x004E1DD4: push 1 */
    eax = MEM32(ebp + 0x20); /* 0x004E1DD6: mov eax, dword ptr [ebp + 0x20] */
    PUSH32(esp, eax); /* 0x004E1DD9: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E1DDA: call dword ptr [0x8586f0] */
    /* test eax, eax */ /* 0x004E1DE0: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E1DE9; /* 0x004E1DE2: jne 0x4e1de9 */

L_004E1DE4:
    goto L_004E1E74; /* 0x004E1DE4: jmp 0x4e1e74 */

L_004E1DE9:
    PUSH32(esp, 0); /* 0x004E1DE9: push 0 */
    PUSH32(esp, 0); /* 0x004E1DEB: push 0 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E1DED: mov ecx, dword ptr [ebp + 0x1c] */
    PUSH32(esp, ecx); /* 0x004E1DF0: push ecx */
    edx = MEM32(ebp + 0x18); /* 0x004E1DF1: mov edx, dword ptr [ebp + 0x18] */
    PUSH32(esp, edx); /* 0x004E1DF4: push edx */
    PUSH32(esp, 9); /* 0x004E1DF5: push 9 */
    eax = MEM32(ebp + 0x20); /* 0x004E1DF7: mov eax, dword ptr [ebp + 0x20] */
    PUSH32(esp, eax); /* 0x004E1DFA: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E1DFB: call dword ptr [0x8586f0] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E1E01: mov dword ptr [ebp - 8], eax */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E1E04: cmp dword ptr [ebp - 8], 0 */
    if (CMP_NE(MEM32(ebp + (-0x8)), 0)) goto L_004E1E0C; /* 0x004E1E08: jne 0x4e1e0c */

L_004E1E0A:
    goto L_004E1E74; /* 0x004E1E0A: jmp 0x4e1e74 */

L_004E1E0C:
    PUSH32(esp, 0x19Au); /* 0x004E1E0C: push 0x19a */
    PUSH32(esp, 0x004F4718u); /* 0x004E1E11: push 0x4f4718 */
    PUSH32(esp, 2); /* 0x004E1E16: push 2 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E1E18: mov ecx, dword ptr [ebp - 8] */
    ecx = ecx << 1; /* 0x004E1E1B: shl ecx, 1 */
    PUSH32(esp, ecx); /* 0x004E1E1D: push ecx */
    RECOMP_CALL(sub_004D25A0); /* 0x004E1E1E: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E1E23: add esp, 0x10 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E1E26: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E1E29: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0)) goto L_004E1E31; /* 0x004E1E2D: jne 0x4e1e31 */

L_004E1E2F:
    goto L_004E1E74; /* 0x004E1E2F: jmp 0x4e1e74 */

L_004E1E31:
    edx = MEM32(ebp + (-0x8)); /* 0x004E1E31: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004E1E34: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E1E35: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004E1E38: push eax */
    ecx = MEM32(ebp + 0x1C); /* 0x004E1E39: mov ecx, dword ptr [ebp + 0x1c] */
    PUSH32(esp, ecx); /* 0x004E1E3C: push ecx */
    edx = MEM32(ebp + 0x18); /* 0x004E1E3D: mov edx, dword ptr [ebp + 0x18] */
    PUSH32(esp, edx); /* 0x004E1E40: push edx */
    PUSH32(esp, 1); /* 0x004E1E41: push 1 */
    eax = MEM32(ebp + 0x20); /* 0x004E1E43: mov eax, dword ptr [ebp + 0x20] */
    PUSH32(esp, eax); /* 0x004E1E46: push eax */
    RECOMP_ICALL(MEM32(0x8586F0)); /* 0x004E1E47: call dword ptr [0x8586f0] */
    /* test eax, eax */ /* 0x004E1E4D: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E1E53; /* 0x004E1E4F: jne 0x4e1e53 */

L_004E1E51:
    goto L_004E1E74; /* 0x004E1E51: jmp 0x4e1e74 */

L_004E1E53:
    ecx = MEM32(ebp + (-0x8)); /* 0x004E1E53: mov ecx, dword ptr [ebp - 8] */
    PUSH32(esp, ecx); /* 0x004E1E56: push ecx */
    edx = MEM32(ebp + (-0x10)); /* 0x004E1E57: mov edx, dword ptr [ebp - 0x10] */
    PUSH32(esp, edx); /* 0x004E1E5A: push edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E1E5B: mov eax, dword ptr [ebp - 4] */
    PUSH32(esp, eax); /* 0x004E1E5E: push eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E1E5F: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E1E62: push ecx */
    edx = MEM32(ebp + 0xC); /* 0x004E1E63: mov edx, dword ptr [ebp + 0xc] */
    PUSH32(esp, edx); /* 0x004E1E66: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004E1E67: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004E1E6A: push eax */
    RECOMP_ICALL(MEM32(0x8586A8)); /* 0x004E1E6B: call dword ptr [0x8586a8] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E1E71: mov dword ptr [ebp - 0x14], eax */

L_004E1E74:
    PUSH32(esp, 2); /* 0x004E1E74: push 2 */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E1E76: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E1E79: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1E7A: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1E7F: add esp, 8 */
    PUSH32(esp, 2); /* 0x004E1E82: push 2 */
    edx = MEM32(ebp + (-0x10)); /* 0x004E1E84: mov edx, dword ptr [ebp - 0x10] */
    PUSH32(esp, edx); /* 0x004E1E87: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E1E88: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E1E8D: add esp, 8 */
    eax = MEM32(ebp + (-0x14)); /* 0x004E1E90: mov eax, dword ptr [ebp - 0x14] */

L_004E1E93:
    edi = POP32_VAL(esp); /* 0x004E1E93: pop edi */
    esi = POP32_VAL(esp); /* 0x004E1E94: pop esi */
    ebx = POP32_VAL(esp); /* 0x004E1E95: pop ebx */
    esp = ebp; /* 0x004E1E96: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1E98: pop ebp */
    return; /* 0x004E1E99: ret  */

}

void sub_004E1CDA(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E1C9E:
    ecx = MEM32(ebp + (-0x2C)); /* 0x004E1C9E: mov ecx, dword ptr [ebp - 0x2c] */
    ecx = ecx + 2; /* 0x004E1CA1: add ecx, 2 */
    MEM32(ebp + (-0x2C)) = ecx; /* 0x004E1CA4: mov dword ptr [ebp - 0x2c], ecx */
    edx = MEM32(ebp + (-0x2C)); /* 0x004E1CA7: mov edx, dword ptr [ebp - 0x2c] */
    eax = 0; /* 0x004E1CAA: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E1CAC: mov al, byte ptr [edx] */
    /* test eax, eax */ /* 0x004E1CAE: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004E1CEF; /* 0x004E1CB0: je 0x4e1cef */

L_004E1CB2:
    ecx = MEM32(ebp + (-0x2C)); /* 0x004E1CB2: mov ecx, dword ptr [ebp - 0x2c] */
    edx = 0; /* 0x004E1CB5: xor edx, edx */
    SET_LO8(edx, MEM8(ecx + 0x1)); /* 0x004E1CB7: mov dl, byte ptr [ecx + 1] */
    /* test edx, edx */ /* 0x004E1CBA: test edx, edx */
    if (TEST_Z(edx, edx)) goto L_004E1CEF; /* 0x004E1CBC: je 0x4e1cef */

L_004E1CBE:
    eax = MEM32(ebp + 0x10); /* 0x004E1CBE: mov eax, dword ptr [ebp + 0x10] */
    ecx = 0; /* 0x004E1CC1: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E1CC3: mov cl, byte ptr [eax] */
    edx = MEM32(ebp + (-0x2C)); /* 0x004E1CC5: mov edx, dword ptr [ebp - 0x2c] */
    eax = 0; /* 0x004E1CC8: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E1CCA: mov al, byte ptr [edx] */
    /* cmp ecx, eax */ /* 0x004E1CCC: cmp ecx, eax */
    if (CMP_L(ecx, eax)) goto L_004E1CED; /* 0x004E1CCE: jl 0x4e1ced */

L_004E1CD0:
    ecx = MEM32(ebp + 0x10); /* 0x004E1CD0: mov ecx, dword ptr [ebp + 0x10] */
    edx = 0; /* 0x004E1CD3: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004E1CD5: mov dl, byte ptr [ecx] */
    eax = MEM32(ebp + (-0x2C)); /* 0x004E1CD7: mov eax, dword ptr [ebp - 0x2c] */

L_004E1CDA:
    ecx = 0; /* 0x004E1CDA: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax + 0x1)); /* 0x004E1CDC: mov cl, byte ptr [eax + 1] */
    /* cmp edx, ecx */ /* 0x004E1CDF: cmp edx, ecx */
    if (CMP_G(edx, ecx)) goto L_004E1CED; /* 0x004E1CE1: jg 0x4e1ced */

L_004E1CE3:
    eax = 2; /* 0x004E1CE3: mov eax, 2 */
    goto L_004E1E93; /* 0x004E1CE8: jmp 0x4e1e93 */

L_004E1CED:
    goto L_004E1C9E; /* 0x004E1CED: jmp 0x4e1c9e */

L_004E1CEF:
    eax = 3; /* 0x004E1CEF: mov eax, 3 */
    goto L_004E1E93; /* 0x004E1CF4: jmp 0x4e1e93 */

L_004E1E93:
    edi = POP32_VAL(esp); /* 0x004E1E93: pop edi */
    esi = POP32_VAL(esp); /* 0x004E1E94: pop esi */
    ebx = POP32_VAL(esp); /* 0x004E1E95: pop ebx */
    esp = ebp; /* 0x004E1E96: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E1E98: pop ebp */
    return; /* 0x004E1E99: ret  */

}

void sub_004E202A(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E202A:
    MEM8(0x83000001) = (uint8_t)(LO8(eax)); /* 0x004E202A: mov byte ptr [0x83000001], al */
    /* UNIMPLEMENTED: les ecx, ptr [eax] */ /* 0x004E202F: les ecx, ptr [eax] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E2031: mov dword ptr [ebp - 8], eax */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E2034: cmp dword ptr [ebp - 8], 0 */
    if (CMP_L(MEM32(ebp + (-0x8)), 0)) goto L_004E20D1; /* 0x004E2038: jl 0x4e20d1 */

L_004E203E:
    edx = MEM32(ebp + (-0xC)); /* 0x004E203E: mov edx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(edx), 0 */ /* 0x004E2041: cmp dword ptr [edx], 0 */
    if (CMP_EQ(MEM32(edx), 0)) goto L_004E20D1; /* 0x004E2044: je 0x4e20d1 */

L_004E204A:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004E204A: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x14)), 0)) goto L_004E20C3; /* 0x004E204E: je 0x4e20c3 */

L_004E2050:
    PUSH32(esp, 2); /* 0x004E2050: push 2 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E2052: mov eax, dword ptr [ebp - 8] */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E2055: mov ecx, dword ptr [ebp - 0xc] */
    edx = MEM32(ecx + eax * 4); /* 0x004E2058: mov edx, dword ptr [ecx + eax*4] */
    PUSH32(esp, edx); /* 0x004E205B: push edx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E205C: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E2061: add esp, 8 */
    goto L_004E206F; /* 0x004E2064: jmp 0x4e206f */

L_004E2066:
    eax = MEM32(ebp + (-0x8)); /* 0x004E2066: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004E2069: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E206C: mov dword ptr [ebp - 8], eax */

L_004E206F:
    ecx = MEM32(ebp + (-0x8)); /* 0x004E206F: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E2072: mov edx, dword ptr [ebp - 0xc] */
    /* cmp MEM32(edx + ecx * 4), 0 */ /* 0x004E2075: cmp dword ptr [edx + ecx*4], 0 */
    if (CMP_EQ(MEM32(edx + ecx * 4), 0)) goto L_004E2090; /* 0x004E2079: je 0x4e2090 */

L_004E207B:
    eax = MEM32(ebp + (-0x8)); /* 0x004E207B: mov eax, dword ptr [ebp - 8] */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E207E: mov ecx, dword ptr [ebp - 0xc] */
    edx = MEM32(ebp + (-0x8)); /* 0x004E2081: mov edx, dword ptr [ebp - 8] */
    esi = MEM32(ebp + (-0xC)); /* 0x004E2084: mov esi, dword ptr [ebp - 0xc] */
    edx = MEM32(esi + edx * 4 + 0x4); /* 0x004E2087: mov edx, dword ptr [esi + edx*4 + 4] */
    MEM32(ecx + eax * 4) = edx; /* 0x004E208B: mov dword ptr [ecx + eax*4], edx */
    goto L_004E2066; /* 0x004E208E: jmp 0x4e2066 */

L_004E2090:
    PUSH32(esp, 0xB9u); /* 0x004E2090: push 0xb9 */
    PUSH32(esp, 0x004F4764u); /* 0x004E2095: push 0x4f4764 */
    PUSH32(esp, 2); /* 0x004E209A: push 2 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E209C: mov eax, dword ptr [ebp - 8] */
    eax = eax << 2; /* 0x004E209F: shl eax, 2 */
    PUSH32(esp, eax); /* 0x004E20A2: push eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E20A3: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E20A6: push ecx */
    RECOMP_CALL(sub_004D2A20); /* 0x004E20A7: call 0x4d2a20 */
    esp = esp + 0x14u; /* 0x004E20AC: add esp, 0x14 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E20AF: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E20B2: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + (-0xC)), 0)) goto L_004E20C1; /* 0x004E20B6: je 0x4e20c1 */

L_004E20B8:
    edx = MEM32(ebp + (-0xC)); /* 0x004E20B8: mov edx, dword ptr [ebp - 0xc] */
    MEM32(0x84B7D4) = edx; /* 0x004E20BB: mov dword ptr [0x84b7d4], edx */

L_004E20C1:
    goto L_004E20CF; /* 0x004E20C1: jmp 0x4e20cf */

L_004E20C3:
    eax = MEM32(ebp + (-0x8)); /* 0x004E20C3: mov eax, dword ptr [ebp - 8] */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E20C6: mov ecx, dword ptr [ebp - 0xc] */
    edx = MEM32(ebp + 0x8); /* 0x004E20C9: mov edx, dword ptr [ebp + 8] */
    MEM32(ecx + eax * 4) = edx; /* 0x004E20CC: mov dword ptr [ecx + eax*4], edx */

L_004E20CF:
    goto L_004E2144; /* 0x004E20CF: jmp 0x4e2144 */

L_004E20D1:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004E20D1: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_NE(MEM32(ebp + (-0x14)), 0)) goto L_004E213D; /* 0x004E20D5: jne 0x4e213d */

L_004E20D7:
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E20D7: cmp dword ptr [ebp - 8], 0 */
    if (CMP_GE(MEM32(ebp + (-0x8)), 0)) goto L_004E20E5; /* 0x004E20DB: jge 0x4e20e5 */

L_004E20DD:
    eax = MEM32(ebp + (-0x8)); /* 0x004E20DD: mov eax, dword ptr [ebp - 8] */
    eax = (uint32_t)(-(int32_t)eax); /* 0x004E20E0: neg eax */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E20E2: mov dword ptr [ebp - 8], eax */

L_004E20E5:
    PUSH32(esp, 0xCEu); /* 0x004E20E5: push 0xce */
    PUSH32(esp, 0x004F4764u); /* 0x004E20EA: push 0x4f4764 */
    PUSH32(esp, 2); /* 0x004E20EF: push 2 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E20F1: mov ecx, dword ptr [ebp - 8] */
    edx = ecx * 4 + 0x8; /* 0x004E20F4: lea edx, [ecx*4 + 8] */
    PUSH32(esp, edx); /* 0x004E20FB: push edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E20FC: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E20FF: push eax */
    RECOMP_CALL(sub_004D2A20); /* 0x004E2100: call 0x4d2a20 */
    esp = esp + 0x14u; /* 0x004E2105: add esp, 0x14 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E2108: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E210B: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E2119; /* 0x004E210F: jne 0x4e2119 */

L_004E2111:
    eax = eax | 0xFFFFFFFFu; /* 0x004E2111: or eax, 0xffffffff */
    goto L_004E21CB; /* 0x004E2114: jmp 0x4e21cb */

L_004E2119:
    ecx = MEM32(ebp + (-0x8)); /* 0x004E2119: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E211C: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + 0x8); /* 0x004E211F: mov eax, dword ptr [ebp + 8] */
    MEM32(edx + ecx * 4) = eax; /* 0x004E2122: mov dword ptr [edx + ecx*4], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E2125: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E2128: mov edx, dword ptr [ebp - 0xc] */
    MEM32(edx + ecx * 4 + 0x4) = 0; /* 0x004E212B: mov dword ptr [edx + ecx*4 + 4], 0 */
    eax = MEM32(ebp + (-0xC)); /* 0x004E2133: mov eax, dword ptr [ebp - 0xc] */
    MEM32(0x84B7D4) = eax; /* 0x004E2136: mov dword ptr [0x84b7d4], eax */
    goto L_004E2144; /* 0x004E213B: jmp 0x4e2144 */

L_004E213D:
    eax = 0; /* 0x004E213D: xor eax, eax */
    goto L_004E21CB; /* 0x004E213F: jmp 0x4e21cb */

L_004E2144:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004E2144: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + 0xC), 0)) goto L_004E21C9; /* 0x004E2148: je 0x4e21c9 */

L_004E214A:
    PUSH32(esp, 0xE5u); /* 0x004E214A: push 0xe5 */
    PUSH32(esp, 0x004F4764u); /* 0x004E214F: push 0x4f4764 */
    PUSH32(esp, 2); /* 0x004E2154: push 2 */
    ecx = MEM32(ebp + 0x8); /* 0x004E2156: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004E2159: push ecx */
    RECOMP_CALL(sub_004D5870); /* 0x004E215A: call 0x4d5870 */
    esp = esp + 4; /* 0x004E215F: add esp, 4 */
    eax = eax + 2; /* 0x004E2162: add eax, 2 */
    PUSH32(esp, eax); /* 0x004E2165: push eax */
    RECOMP_CALL(sub_004D25A0); /* 0x004E2166: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E216B: add esp, 0x10 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E216E: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E2171: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x10)), 0)) goto L_004E21C9; /* 0x004E2175: je 0x4e21c9 */

L_004E2177:
    edx = MEM32(ebp + 0x8); /* 0x004E2177: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E217A: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E217B: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004E217E: push eax */
    RECOMP_CALL(sub_004DC810); /* 0x004E217F: call 0x4dc810 */
    esp = esp + 8; /* 0x004E2184: add esp, 8 */
    ecx = MEM32(ebp + (-0x18)); /* 0x004E2187: mov ecx, dword ptr [ebp - 0x18] */
    ecx = ecx - MEM32(ebp + 0x8); /* 0x004E218A: sub ecx, dword ptr [ebp + 8] */
    edx = MEM32(ebp + (-0x10)); /* 0x004E218D: mov edx, dword ptr [ebp - 0x10] */
    edx = edx + ecx; /* 0x004E2190: add edx, ecx */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E2192: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E2195: mov eax, dword ptr [ebp - 4] */
    MEM8(eax) = (uint8_t)(0); /* 0x004E2198: mov byte ptr [eax], 0 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E219B: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004E219E: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E21A1: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004E21A4: mov edx, dword ptr [ebp - 0x14] */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004E21A7: neg edx */
    edx = _cf ? 0xFFFFFFFFu : 0; /* 0x004E21A9: sbb edx, edx */
    edx = ~edx; /* 0x004E21AB: not edx */
    edx = edx & MEM32(ebp + (-0x4)); /* 0x004E21AD: and edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E21B0: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E21B1: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004E21B4: push eax */
    RECOMP_ICALL(MEM32(0x8586A4)); /* 0x004E21B5: call dword ptr [0x8586a4] */
    PUSH32(esp, 2); /* 0x004E21BB: push 2 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E21BD: mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(esp, ecx); /* 0x004E21C0: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E21C1: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E21C6: add esp, 8 */

L_004E21C9:
    eax = 0; /* 0x004E21C9: xor eax, eax */

L_004E21CB:
    esi = POP32_VAL(esp); /* 0x004E21CB: pop esi */
    esp = ebp; /* 0x004E21CC: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E21CE: pop ebp */
    return; /* 0x004E21CF: ret  */

}

void sub_004E20DB(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E20DB:
    if (/* no flag state for jge */ _cf) goto L_004E20E5; /* 0x004E20DB: jge 0x4e20e5 */

L_004E20DD:
    eax = MEM32(ebp + (-0x8)); /* 0x004E20DD: mov eax, dword ptr [ebp - 8] */
    eax = (uint32_t)(-(int32_t)eax); /* 0x004E20E0: neg eax */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E20E2: mov dword ptr [ebp - 8], eax */

L_004E20E5:
    PUSH32(esp, 0xCEu); /* 0x004E20E5: push 0xce */
    PUSH32(esp, 0x004F4764u); /* 0x004E20EA: push 0x4f4764 */
    PUSH32(esp, 2); /* 0x004E20EF: push 2 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E20F1: mov ecx, dword ptr [ebp - 8] */
    edx = ecx * 4 + 0x8; /* 0x004E20F4: lea edx, [ecx*4 + 8] */
    PUSH32(esp, edx); /* 0x004E20FB: push edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E20FC: mov eax, dword ptr [ebp - 0xc] */
    PUSH32(esp, eax); /* 0x004E20FF: push eax */
    RECOMP_CALL(sub_004D2A20); /* 0x004E2100: call 0x4d2a20 */
    esp = esp + 0x14u; /* 0x004E2105: add esp, 0x14 */
    MEM32(ebp + (-0xC)) = eax; /* 0x004E2108: mov dword ptr [ebp - 0xc], eax */
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E210B: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E2119; /* 0x004E210F: jne 0x4e2119 */

L_004E2111:
    eax = eax | 0xFFFFFFFFu; /* 0x004E2111: or eax, 0xffffffff */
    goto L_004E21CB; /* 0x004E2114: jmp 0x4e21cb */

L_004E2119:
    ecx = MEM32(ebp + (-0x8)); /* 0x004E2119: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E211C: mov edx, dword ptr [ebp - 0xc] */
    eax = MEM32(ebp + 0x8); /* 0x004E211F: mov eax, dword ptr [ebp + 8] */
    MEM32(edx + ecx * 4) = eax; /* 0x004E2122: mov dword ptr [edx + ecx*4], eax */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E2125: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ebp + (-0xC)); /* 0x004E2128: mov edx, dword ptr [ebp - 0xc] */
    MEM32(edx + ecx * 4 + 0x4) = 0; /* 0x004E212B: mov dword ptr [edx + ecx*4 + 4], 0 */
    eax = MEM32(ebp + (-0xC)); /* 0x004E2133: mov eax, dword ptr [ebp - 0xc] */
    MEM32(0x84B7D4) = eax; /* 0x004E2136: mov dword ptr [0x84b7d4], eax */
    goto L_004E2144; /* 0x004E213B: jmp 0x4e2144 */

L_004E2144:
    /* cmp MEM32(ebp + 0xC), 0 */ /* 0x004E2144: cmp dword ptr [ebp + 0xc], 0 */
    if (CMP_EQ(MEM32(ebp + 0xC), 0)) goto L_004E21C9; /* 0x004E2148: je 0x4e21c9 */

L_004E214A:
    PUSH32(esp, 0xE5u); /* 0x004E214A: push 0xe5 */
    PUSH32(esp, 0x004F4764u); /* 0x004E214F: push 0x4f4764 */
    PUSH32(esp, 2); /* 0x004E2154: push 2 */
    ecx = MEM32(ebp + 0x8); /* 0x004E2156: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004E2159: push ecx */
    RECOMP_CALL(sub_004D5870); /* 0x004E215A: call 0x4d5870 */
    esp = esp + 4; /* 0x004E215F: add esp, 4 */
    eax = eax + 2; /* 0x004E2162: add eax, 2 */
    PUSH32(esp, eax); /* 0x004E2165: push eax */
    RECOMP_CALL(sub_004D25A0); /* 0x004E2166: call 0x4d25a0 */
    esp = esp + 0x10u; /* 0x004E216B: add esp, 0x10 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E216E: mov dword ptr [ebp - 0x10], eax */
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E2171: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x10)), 0)) goto L_004E21C9; /* 0x004E2175: je 0x4e21c9 */

L_004E2177:
    edx = MEM32(ebp + 0x8); /* 0x004E2177: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E217A: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E217B: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004E217E: push eax */
    RECOMP_CALL(sub_004DC810); /* 0x004E217F: call 0x4dc810 */
    esp = esp + 8; /* 0x004E2184: add esp, 8 */
    ecx = MEM32(ebp + (-0x18)); /* 0x004E2187: mov ecx, dword ptr [ebp - 0x18] */
    ecx = ecx - MEM32(ebp + 0x8); /* 0x004E218A: sub ecx, dword ptr [ebp + 8] */
    edx = MEM32(ebp + (-0x10)); /* 0x004E218D: mov edx, dword ptr [ebp - 0x10] */
    edx = edx + ecx; /* 0x004E2190: add edx, ecx */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E2192: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E2195: mov eax, dword ptr [ebp - 4] */
    MEM8(eax) = (uint8_t)(0); /* 0x004E2198: mov byte ptr [eax], 0 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E219B: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004E219E: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E21A1: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + (-0x14)); /* 0x004E21A4: mov edx, dword ptr [ebp - 0x14] */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004E21A7: neg edx */
    edx = _cf ? 0xFFFFFFFFu : 0; /* 0x004E21A9: sbb edx, edx */
    edx = ~edx; /* 0x004E21AB: not edx */
    edx = edx & MEM32(ebp + (-0x4)); /* 0x004E21AD: and edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E21B0: push edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E21B1: mov eax, dword ptr [ebp - 0x10] */
    PUSH32(esp, eax); /* 0x004E21B4: push eax */
    RECOMP_ICALL(MEM32(0x8586A4)); /* 0x004E21B5: call dword ptr [0x8586a4] */
    PUSH32(esp, 2); /* 0x004E21BB: push 2 */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E21BD: mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(esp, ecx); /* 0x004E21C0: push ecx */
    RECOMP_CALL(sub_004D2FE0); /* 0x004E21C1: call 0x4d2fe0 */
    esp = esp + 8; /* 0x004E21C6: add esp, 8 */

L_004E21C9:
    eax = 0; /* 0x004E21C9: xor eax, eax */

L_004E21CB:
    esi = POP32_VAL(esp); /* 0x004E21CB: pop esi */
    esp = ebp; /* 0x004E21CC: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E21CE: pop ebp */
    return; /* 0x004E21CF: ret  */

}

void sub_004E25D0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E25B7:
    eax = MEM32(ebp + 0x10); /* 0x004E25B7: mov eax, dword ptr [ebp + 0x10] */
    /* cmp MEM32(eax + 0x8), 0 */ /* 0x004E25BA: cmp dword ptr [eax + 8], 0 */
    if (CMP_NE(MEM32(eax + 0x8), 0)) goto L_004E2603; /* 0x004E25BE: jne 0x4e2603 */

L_004E25C0:
    ecx = MEM32(ebp + 0x10); /* 0x004E25C0: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ecx + 0x4); /* 0x004E25C3: mov edx, dword ptr [ecx + 4] */
    edx = edx >> 0x10u; /* 0x004E25C6: shr edx, 0x10 */
    eax = MEM32(ebp + 0x10); /* 0x004E25C9: mov eax, dword ptr [ebp + 0x10] */
    MEM32(eax + 0x8) = edx; /* 0x004E25CC: mov dword ptr [eax + 8], edx */
    ecx = MEM32(ebp + 0x10); /* 0x004E25CF: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ecx + 0x4); /* 0x004E25D2: mov edx, dword ptr [ecx + 4] */
    edx = edx << 0x10u; /* 0x004E25D5: shl edx, 0x10 */
    eax = MEM32(ebp + 0x10); /* 0x004E25D8: mov eax, dword ptr [ebp + 0x10] */
    ecx = MEM32(eax); /* 0x004E25DB: mov ecx, dword ptr [eax] */
    ecx = ecx >> 0x10u; /* 0x004E25DD: shr ecx, 0x10 */
    edx = edx | ecx; /* 0x004E25E0: or edx, ecx */
    eax = MEM32(ebp + 0x10); /* 0x004E25E2: mov eax, dword ptr [ebp + 0x10] */
    MEM32(eax + 0x4) = edx; /* 0x004E25E5: mov dword ptr [eax + 4], edx */
    ecx = MEM32(ebp + 0x10); /* 0x004E25E8: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ecx); /* 0x004E25EB: mov edx, dword ptr [ecx] */
    edx = edx << 0x10u; /* 0x004E25ED: shl edx, 0x10 */
    eax = MEM32(ebp + 0x10); /* 0x004E25F0: mov eax, dword ptr [ebp + 0x10] */
    MEM32(eax) = edx; /* 0x004E25F3: mov dword ptr [eax], edx */
    SET_LO16(ecx, MEM16(ebp + (-0x10))); /* 0x004E25F5: mov cx, word ptr [ebp - 0x10] */
    SET_LO16(ecx, LO16(ecx) - 0x10u); /* 0x004E25F9: sub cx, 0x10 */
    MEM16(ebp + (-0x10)) = (uint16_t)(LO16(ecx)); /* 0x004E25FD: mov word ptr [ebp - 0x10], cx */
    goto L_004E25B7; /* 0x004E2601: jmp 0x4e25b7 */

L_004E25D0:
    ebp = ebp - 1; /* 0x004E25D0: dec ebp */
    MEM8(ebx + (-0x1D3EFBAF)) = (uint8_t)(MEM8(ebx + (-0x1D3EFBAF)) + LO8(ecx) + _cf); /* 0x004E25D1: adc byte ptr [ebx - 0x1d3efbaf], cl */
    MEM8(ebx + 0x88B1045) = (uint8_t)(MEM8(ebx + 0x88B1045) + LO8(ecx) + _cf); /* 0x004E25D7: adc byte ptr [ebx + 0x88b1045], cl */
    ecx = ecx >> 0x10u; /* 0x004E25DD: shr ecx, 0x10 */
    edx = edx | ecx; /* 0x004E25E0: or edx, ecx */
    eax = MEM32(ebp + 0x10); /* 0x004E25E2: mov eax, dword ptr [ebp + 0x10] */
    MEM32(eax + 0x4) = edx; /* 0x004E25E5: mov dword ptr [eax + 4], edx */
    ecx = MEM32(ebp + 0x10); /* 0x004E25E8: mov ecx, dword ptr [ebp + 0x10] */
    edx = MEM32(ecx); /* 0x004E25EB: mov edx, dword ptr [ecx] */
    edx = edx << 0x10u; /* 0x004E25ED: shl edx, 0x10 */
    eax = MEM32(ebp + 0x10); /* 0x004E25F0: mov eax, dword ptr [ebp + 0x10] */
    MEM32(eax) = edx; /* 0x004E25F3: mov dword ptr [eax], edx */
    SET_LO16(ecx, MEM16(ebp + (-0x10))); /* 0x004E25F5: mov cx, word ptr [ebp - 0x10] */
    SET_LO16(ecx, LO16(ecx) - 0x10u); /* 0x004E25F9: sub cx, 0x10 */
    MEM16(ebp + (-0x10)) = (uint16_t)(LO16(ecx)); /* 0x004E25FD: mov word ptr [ebp - 0x10], cx */
    goto L_004E25B7; /* 0x004E2601: jmp 0x4e25b7 */

L_004E2603:
    edx = MEM32(ebp + 0x10); /* 0x004E2603: mov edx, dword ptr [ebp + 0x10] */
    eax = MEM32(edx + 0x8); /* 0x004E2606: mov eax, dword ptr [edx + 8] */
    eax = eax & 0x8000u; /* 0x004E2609: and eax, 0x8000 */
    /* test eax, eax */ /* 0x004E260E: test eax, eax */
    if (TEST_NZ(eax, eax)) goto L_004E262C; /* 0x004E2610: jne 0x4e262c */

L_004E2612:
    ecx = MEM32(ebp + 0x10); /* 0x004E2612: mov ecx, dword ptr [ebp + 0x10] */
    PUSH32(esp, ecx); /* 0x004E2615: push ecx */
    RECOMP_CALL(sub_004E2430); /* 0x004E2616: call 0x4e2430 */
    esp = esp + 4; /* 0x004E261B: add esp, 4 */
    SET_LO16(edx, MEM16(ebp + (-0x10))); /* 0x004E261E: mov dx, word ptr [ebp - 0x10] */
    SET_LO16(edx, LO16(edx) - 1); /* 0x004E2622: sub dx, 1 */
    MEM16(ebp + (-0x10)) = (uint16_t)(LO16(edx)); /* 0x004E2626: mov word ptr [ebp - 0x10], dx */
    goto L_004E2603; /* 0x004E262A: jmp 0x4e2603 */

L_004E262C:
    eax = MEM32(ebp + 0x10); /* 0x004E262C: mov eax, dword ptr [ebp + 0x10] */
    SET_LO16(ecx, MEM16(ebp + (-0x10))); /* 0x004E262F: mov cx, word ptr [ebp - 0x10] */
    MEM16(eax + 0xA) = (uint16_t)(LO16(ecx)); /* 0x004E2633: mov word ptr [eax + 0xa], cx */
    esp = ebp; /* 0x004E2637: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E2639: pop ebp */
    return; /* 0x004E263A: ret  */

}

void sub_004E2AF0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E26E7:
    /* cmp MEM32(ebp + (-0x4C)), 0xAu */ /* 0x004E26E7: cmp dword ptr [ebp - 0x4c], 0xa */
    if (CMP_EQ(MEM32(ebp + (-0x4C)), 0xAu)) goto L_004E2E48; /* 0x004E26EB: je 0x4e2e48 */

L_004E26F1:
    eax = MEM32(ebp + (-0x4)); /* 0x004E26F1: mov eax, dword ptr [ebp - 4] */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E26F4: mov cl, byte ptr [eax] */
    MEM8(ebp + (-0x3C)) = (uint8_t)(LO8(ecx)); /* 0x004E26F6: mov byte ptr [ebp - 0x3c], cl */
    edx = MEM32(ebp + (-0x4)); /* 0x004E26F9: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004E26FC: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E26FF: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + (-0x4C)); /* 0x004E2702: mov eax, dword ptr [ebp - 0x4c] */
    MEM32(ebp + (-0x80)) = eax; /* 0x004E2705: mov dword ptr [ebp - 0x80], eax */
    /* cmp MEM32(ebp + (-0x80)), 0xBu */ /* 0x004E2708: cmp dword ptr [ebp - 0x80], 0xb */
    if (CMP_A(MEM32(ebp + (-0x80)), 0xBu)) goto L_004E2E43; /* 0x004E270C: ja 0x4e2e43 */

L_004E2712:
    ecx = MEM32(ebp + (-0x80)); /* 0x004E2712: mov ecx, dword ptr [ebp - 0x80] */
    RECOMP_ITAIL(MEM32(ecx * 4 + 0x4E305A)); return; /* 0x004E2715: jmp dword ptr [ecx*4 + 0x4e305a] */

L_004E2AF0:
    /* test MEM32(ecx + esi), ebp */ /* 0x004E2AF0: test dword ptr [ecx + esi], ebp */
    esi = esi - 1; /* 0x004E2AF3: dec esi */
    SET_HI8(ebx, HI8(ebx) + LO8(eax)); /* 0x004E2AF4: add bh, al */
    ebp = ebp + 1; /* 0x004E2AF6: inc ebp */
    SET_HI8(eax, 6); /* 0x004E2AF7: mov ah, 6 */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E2AF9: add byte ptr [eax], al */
    SET_LO8(ebx, LO8(ebx) + HI8(ecx)); /* 0x004E2AFB: add bl, ch */
    SET_LO8(ecx, LO8(ecx) & MEM8(ebx + (-0x157C03AB))); /* 0x004E2AFD: and cl, byte ptr [ebx - 0x157c03ab] */
    MEM32(ecx + 0x45C7FC55) = MEM32(ecx + 0x45C7FC55) + ecx; /* 0x004E2B03: add dword ptr [ecx + 0x45c7fc55], ecx */
    SET_HI8(eax, 0xBu); /* 0x004E2B09: mov ah, 0xb */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E2B0B: add byte ptr [eax], al */
    SET_LO8(ebx, LO8(ebx) + HI8(ecx)); /* 0x004E2B0D: add bl, ch */
    SET_HI8(ebx, HI8(ebx) + LO8(eax) + _cf); /* 0x004E2B0F: adc bh, al */
    ebp = ebp + 1; /* 0x004E2B11: inc ebp */
    SET_HI8(eax, 0xAu); /* 0x004E2B12: mov ah, 0xa */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E2B14: add byte ptr [eax], al */
    MEM8(ebx + (-0x177C03BB)) = (uint8_t)(MEM8(ebx + (-0x177C03BB)) + LO8(ecx)); /* 0x004E2B16: add byte ptr [ebx - 0x177c03bb], cl */
    MEM32(ecx + 0x1EE9FC45) = MEM32(ecx + 0x1EE9FC45) + ecx; /* 0x004E2B1C: add dword ptr [ecx + 0x1ee9fc45], ecx */
    eax = eax + MEM32(eax); /* 0x004E2B22: add eax, dword ptr [eax] */
    SET_HI8(ebx, HI8(ebx) + LO8(eax)); /* 0x004E2B24: add bh, al */
    ebp = ebp + 1; /* 0x004E2B26: inc ebp */
    /* UNIMPLEMENTED: hlt  */ /* 0x004E2B27: hlt  */
    MEM32(eax) = MEM32(eax) + eax; /* 0x004E2B28: add dword ptr [eax], eax */
    MEM8(eax) = (uint8_t)(MEM8(eax) + LO8(eax)); /* 0x004E2B2A: add byte ptr [eax], al */
    /* cmp MEM32(0x509634), 1 */ /* 0x004E2B2C: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004E2B51; /* 0x004E2B33: jle 0x4e2b51 */

L_004E2B35:
    PUSH32(esp, 4); /* 0x004E2B35: push 4 */
    ecx = MEM32(ebp + (-0x3C)); /* 0x004E2B37: mov ecx, dword ptr [ebp - 0x3c] */
    ecx = ecx & 0xFFu; /* 0x004E2B3A: and ecx, 0xff */
    PUSH32(esp, ecx); /* 0x004E2B40: push ecx */
    RECOMP_CALL(sub_004DA490); /* 0x004E2B41: call 0x4da490 */
    esp = esp + 8; /* 0x004E2B46: add esp, 8 */
    MEM32(ebp + (-0xA0)) = eax; /* 0x004E2B49: mov dword ptr [ebp - 0xa0], eax */
    goto L_004E2B6E; /* 0x004E2B4F: jmp 0x4e2b6e */

L_004E2B51:
    edx = MEM32(ebp + (-0x3C)); /* 0x004E2B51: mov edx, dword ptr [ebp - 0x3c] */
    edx = edx & 0xFFu; /* 0x004E2B54: and edx, 0xff */
    eax = MEM32(0x509428); /* 0x004E2B5A: mov eax, dword ptr [0x509428] */
    ecx = 0; /* 0x004E2B5F: xor ecx, ecx */
    SET_LO16(ecx, MEM16(eax + edx * 2)); /* 0x004E2B61: mov cx, word ptr [eax + edx*2] */
    ecx = ecx & 4; /* 0x004E2B65: and ecx, 4 */
    MEM32(ebp + (-0xA0)) = ecx; /* 0x004E2B68: mov dword ptr [ebp - 0xa0], ecx */

L_004E2B6E:
    /* cmp MEM32(ebp + (-0xA0)), 0 */ /* 0x004E2B6E: cmp dword ptr [ebp - 0xa0], 0 */
    if (CMP_EQ(MEM32(ebp + (-0xA0)), 0)) goto L_004E2B89; /* 0x004E2B75: je 0x4e2b89 */

L_004E2B77:
    MEM32(ebp + (-0x4C)) = 4; /* 0x004E2B77: mov dword ptr [ebp - 0x4c], 4 */
    edx = MEM32(ebp + (-0x4)); /* 0x004E2B7E: mov edx, dword ptr [ebp - 4] */
    edx = edx - 1; /* 0x004E2B81: sub edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E2B84: mov dword ptr [ebp - 4], edx */
    goto L_004E2B96; /* 0x004E2B87: jmp 0x4e2b96 */

L_004E2B89:
    MEM32(ebp + (-0x4C)) = 0xAu; /* 0x004E2B89: mov dword ptr [ebp - 0x4c], 0xa */
    eax = MEM32(ebp + (-0x64)); /* 0x004E2B90: mov eax, dword ptr [ebp - 0x64] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E2B93: mov dword ptr [ebp - 4], eax */

L_004E2B96:
    goto L_004E2E43; /* 0x004E2B96: jmp 0x4e2e43 */

L_004E2E43:
    goto L_004E26E7; /* 0x004E2E43: jmp 0x4e26e7 */

L_004E2E48:
    ecx = MEM32(ebp + 0xC); /* 0x004E2E48: mov ecx, dword ptr [ebp + 0xc] */
    edx = MEM32(ebp + (-0x4)); /* 0x004E2E4B: mov edx, dword ptr [ebp - 4] */
    MEM32(ecx) = edx; /* 0x004E2E4E: mov dword ptr [ecx], edx */
    /* cmp MEM32(ebp + (-0x54)), 0 */ /* 0x004E2E50: cmp dword ptr [ebp - 0x54], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x54)), 0)) goto L_004E2F97; /* 0x004E2E54: je 0x4e2f97 */

L_004E2E5A:
    /* cmp MEM32(ebp + (-0x40)), 0 */ /* 0x004E2E5A: cmp dword ptr [ebp - 0x40], 0 */
    if (CMP_NE(MEM32(ebp + (-0x40)), 0)) goto L_004E2F97; /* 0x004E2E5E: jne 0x4e2f97 */

L_004E2E64:
    /* cmp MEM32(ebp + (-0x78)), 0 */ /* 0x004E2E64: cmp dword ptr [ebp - 0x78], 0 */
    if (CMP_NE(MEM32(ebp + (-0x78)), 0)) goto L_004E2F97; /* 0x004E2E68: jne 0x4e2f97 */

L_004E2E6E:
    /* cmp MEM32(ebp + (-0x70)), 0x18u */ /* 0x004E2E6E: cmp dword ptr [ebp - 0x70], 0x18 */
    if (CMP_BE(MEM32(ebp + (-0x70)), 0x18u)) goto L_004E2E9F; /* 0x004E2E72: jbe 0x4e2e9f */

L_004E2E74:
    eax = (int32_t)(int8_t)MEM8(ebp + (-0x21)); /* 0x004E2E74: movsx eax, byte ptr [ebp - 0x21] */
    /* cmp eax, 5 */ /* 0x004E2E78: cmp eax, 5 */
    if (CMP_L(eax, 5)) goto L_004E2E86; /* 0x004E2E7B: jl 0x4e2e86 */

L_004E2E7D:
    SET_LO8(ecx, MEM8(ebp + (-0x21))); /* 0x004E2E7D: mov cl, byte ptr [ebp - 0x21] */
    SET_LO8(ecx, LO8(ecx) + 1); /* 0x004E2E80: add cl, 1 */
    MEM8(ebp + (-0x21)) = (uint8_t)(LO8(ecx)); /* 0x004E2E83: mov byte ptr [ebp - 0x21], cl */

L_004E2E86:
    MEM32(ebp + (-0x70)) = 0x18u; /* 0x004E2E86: mov dword ptr [ebp - 0x70], 0x18 */
    edx = MEM32(ebp + (-0x68)); /* 0x004E2E8D: mov edx, dword ptr [ebp - 0x68] */
    edx = edx - 1; /* 0x004E2E90: sub edx, 1 */
    MEM32(ebp + (-0x68)) = edx; /* 0x004E2E93: mov dword ptr [ebp - 0x68], edx */
    eax = MEM32(ebp + (-0x6C)); /* 0x004E2E96: mov eax, dword ptr [ebp - 0x6c] */
    eax = eax + 1; /* 0x004E2E99: add eax, 1 */
    MEM32(ebp + (-0x6C)) = eax; /* 0x004E2E9C: mov dword ptr [ebp - 0x6c], eax */

L_004E2E9F:
    /* cmp MEM32(ebp + (-0x70)), 0 */ /* 0x004E2E9F: cmp dword ptr [ebp - 0x70], 0 */
    if (CMP_BE(MEM32(ebp + (-0x70)), 0)) goto L_004E2F7A; /* 0x004E2EA3: jbe 0x4e2f7a */

L_004E2EA9:
    ecx = MEM32(ebp + (-0x68)); /* 0x004E2EA9: mov ecx, dword ptr [ebp - 0x68] */
    ecx = ecx - 1; /* 0x004E2EAC: sub ecx, 1 */
    MEM32(ebp + (-0x68)) = ecx; /* 0x004E2EAF: mov dword ptr [ebp - 0x68], ecx */
    goto L_004E2EBD; /* 0x004E2EB2: jmp 0x4e2ebd */

L_004E2EB4:
    edx = MEM32(ebp + (-0x68)); /* 0x004E2EB4: mov edx, dword ptr [ebp - 0x68] */
    edx = edx - 1; /* 0x004E2EB7: sub edx, 1 */
    MEM32(ebp + (-0x68)) = edx; /* 0x004E2EBA: mov dword ptr [ebp - 0x68], edx */

L_004E2EBD:
    eax = MEM32(ebp + (-0x68)); /* 0x004E2EBD: mov eax, dword ptr [ebp - 0x68] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004E2EC0: movsx ecx, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004E2EC3: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004E2EDB; /* 0x004E2EC5: jne 0x4e2edb */

L_004E2EC7:
    edx = MEM32(ebp + (-0x70)); /* 0x004E2EC7: mov edx, dword ptr [ebp - 0x70] */
    edx = edx - 1; /* 0x004E2ECA: sub edx, 1 */
    MEM32(ebp + (-0x70)) = edx; /* 0x004E2ECD: mov dword ptr [ebp - 0x70], edx */
    eax = MEM32(ebp + (-0x6C)); /* 0x004E2ED0: mov eax, dword ptr [ebp - 0x6c] */
    eax = eax + 1; /* 0x004E2ED3: add eax, 1 */
    MEM32(ebp + (-0x6C)) = eax; /* 0x004E2ED6: mov dword ptr [ebp - 0x6c], eax */
    goto L_004E2EB4; /* 0x004E2ED9: jmp 0x4e2eb4 */

L_004E2EDB:
    ecx = ebp + (-0x60); /* 0x004E2EDB: lea ecx, [ebp - 0x60] */
    PUSH32(esp, ecx); /* 0x004E2EDE: push ecx */
    edx = MEM32(ebp + (-0x70)); /* 0x004E2EDF: mov edx, dword ptr [ebp - 0x70] */
    PUSH32(esp, edx); /* 0x004E2EE2: push edx */
    eax = ebp + (-0x38); /* 0x004E2EE3: lea eax, [ebp - 0x38] */
    PUSH32(esp, eax); /* 0x004E2EE6: push eax */
    RECOMP_CALL(sub_004E2500); /* 0x004E2EE7: call 0x4e2500 */
    esp = esp + 0xCu; /* 0x004E2EEC: add esp, 0xc */
    /* cmp MEM32(ebp + (-0x74)), 0 */ /* 0x004E2EEF: cmp dword ptr [ebp - 0x74], 0 */
    if (CMP_GE(MEM32(ebp + (-0x74)), 0)) goto L_004E2EFD; /* 0x004E2EF3: jge 0x4e2efd */

L_004E2EF5:
    ecx = MEM32(ebp + (-0x14)); /* 0x004E2EF5: mov ecx, dword ptr [ebp - 0x14] */
    ecx = (uint32_t)(-(int32_t)ecx); /* 0x004E2EF8: neg ecx */
    MEM32(ebp + (-0x14)) = ecx; /* 0x004E2EFA: mov dword ptr [ebp - 0x14], ecx */

L_004E2EFD:
    edx = MEM32(ebp + (-0x14)); /* 0x004E2EFD: mov edx, dword ptr [ebp - 0x14] */
    edx = edx + MEM32(ebp + (-0x6C)); /* 0x004E2F00: add edx, dword ptr [ebp - 0x6c] */
    MEM32(ebp + (-0x14)) = edx; /* 0x004E2F03: mov dword ptr [ebp - 0x14], edx */
    /* cmp MEM32(ebp + (-0x18)), 0 */ /* 0x004E2F06: cmp dword ptr [ebp - 0x18], 0 */
    if (CMP_NE(MEM32(ebp + (-0x18)), 0)) goto L_004E2F15; /* 0x004E2F0A: jne 0x4e2f15 */

L_004E2F0C:
    eax = MEM32(ebp + (-0x14)); /* 0x004E2F0C: mov eax, dword ptr [ebp - 0x14] */
    eax = eax + MEM32(ebp + 0x18); /* 0x004E2F0F: add eax, dword ptr [ebp + 0x18] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E2F12: mov dword ptr [ebp - 0x14], eax */

L_004E2F15:
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E2F15: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E2F24; /* 0x004E2F19: jne 0x4e2f24 */

L_004E2F1B:
    ecx = MEM32(ebp + (-0x14)); /* 0x004E2F1B: mov ecx, dword ptr [ebp - 0x14] */
    ecx = ecx - MEM32(ebp + 0x1C); /* 0x004E2F1E: sub ecx, dword ptr [ebp + 0x1c] */
    MEM32(ebp + (-0x14)) = ecx; /* 0x004E2F21: mov dword ptr [ebp - 0x14], ecx */

L_004E2F24:
    /* cmp MEM32(ebp + (-0x14)), 0x1450u */ /* 0x004E2F24: cmp dword ptr [ebp - 0x14], 0x1450 */
    if (CMP_LE(MEM32(ebp + (-0x14)), 0x1450u)) goto L_004E2F36; /* 0x004E2F2B: jle 0x4e2f36 */

L_004E2F2D:
    MEM32(ebp + (-0x40)) = 1; /* 0x004E2F2D: mov dword ptr [ebp - 0x40], 1 */
    goto L_004E2F78; /* 0x004E2F34: jmp 0x4e2f78 */

L_004E2F36:
    /* cmp MEM32(ebp + (-0x14)), 0xFFFFEBB0u */ /* 0x004E2F36: cmp dword ptr [ebp - 0x14], 0xffffebb0 */
    if (CMP_GE(MEM32(ebp + (-0x14)), 0xFFFFEBB0u)) goto L_004E2F48; /* 0x004E2F3D: jge 0x4e2f48 */

L_004E2F3F:
    MEM32(ebp + (-0x78)) = 1; /* 0x004E2F3F: mov dword ptr [ebp - 0x78], 1 */
    goto L_004E2F78; /* 0x004E2F46: jmp 0x4e2f78 */

L_004E2F48:
    edx = MEM32(ebp + 0x14); /* 0x004E2F48: mov edx, dword ptr [ebp + 0x14] */
    PUSH32(esp, edx); /* 0x004E2F4B: push edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004E2F4C: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E2F4F: push eax */
    ecx = ebp + (-0x60); /* 0x004E2F50: lea ecx, [ebp - 0x60] */
    PUSH32(esp, ecx); /* 0x004E2F53: push ecx */
    RECOMP_CALL(sub_004E4850); /* 0x004E2F54: call 0x4e4850 */
    esp = esp + 0xCu; /* 0x004E2F59: add esp, 0xc */
    SET_LO16(edx, MEM16(ebp + (-0x60))); /* 0x004E2F5C: mov dx, word ptr [ebp - 0x60] */
    MEM16(ebp + (-0x48)) = (uint16_t)(LO16(edx)); /* 0x004E2F60: mov word ptr [ebp - 0x48], dx */
    eax = MEM32(ebp + (-0x5E)); /* 0x004E2F64: mov eax, dword ptr [ebp - 0x5e] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E2F67: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x5A)); /* 0x004E2F6A: mov ecx, dword ptr [ebp - 0x5a] */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004E2F6D: mov dword ptr [ebp - 0x10], ecx */
    SET_LO16(edx, MEM16(ebp + (-0x56))); /* 0x004E2F70: mov dx, word ptr [ebp - 0x56] */
    MEM16(ebp + (-0x50)) = (uint16_t)(LO16(edx)); /* 0x004E2F74: mov word ptr [ebp - 0x50], dx */

L_004E2F78:
    goto L_004E2F97; /* 0x004E2F78: jmp 0x4e2f97 */

L_004E2F7A:
    MEM16(ebp + (-0x48)) = (uint16_t)(0); /* 0x004E2F7A: mov word ptr [ebp - 0x48], 0 */
    MEM16(ebp + (-0x50)) = (uint16_t)(0); /* 0x004E2F80: mov word ptr [ebp - 0x50], 0 */
    eax = MEM32(ebp + (-0x50)); /* 0x004E2F86: mov eax, dword ptr [ebp - 0x50] */
    eax = eax & 0xFFFFu; /* 0x004E2F89: and eax, 0xffff */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E2F8E: mov dword ptr [ebp - 0x10], eax */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E2F91: mov ecx, dword ptr [ebp - 0x10] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004E2F94: mov dword ptr [ebp - 8], ecx */

L_004E2F97:
    /* cmp MEM32(ebp + (-0x54)), 0 */ /* 0x004E2F97: cmp dword ptr [ebp - 0x54], 0 */
    if (CMP_NE(MEM32(ebp + (-0x54)), 0)) goto L_004E2FC6; /* 0x004E2F9B: jne 0x4e2fc6 */

L_004E2F9D:
    MEM16(ebp + (-0x48)) = (uint16_t)(0); /* 0x004E2F9D: mov word ptr [ebp - 0x48], 0 */
    MEM16(ebp + (-0x50)) = (uint16_t)(0); /* 0x004E2FA3: mov word ptr [ebp - 0x50], 0 */
    edx = MEM32(ebp + (-0x50)); /* 0x004E2FA9: mov edx, dword ptr [ebp - 0x50] */
    edx = edx & 0xFFFFu; /* 0x004E2FAC: and edx, 0xffff */
    MEM32(ebp + (-0x10)) = edx; /* 0x004E2FB2: mov dword ptr [ebp - 0x10], edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E2FB5: mov eax, dword ptr [ebp - 0x10] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E2FB8: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x44)); /* 0x004E2FBB: mov ecx, dword ptr [ebp - 0x44] */
    ecx = ecx | 4; /* 0x004E2FBE: or ecx, 4 */
    MEM32(ebp + (-0x44)) = ecx; /* 0x004E2FC1: mov dword ptr [ebp - 0x44], ecx */
    goto L_004E301D; /* 0x004E2FC4: jmp 0x4e301d */

L_004E2FC6:
    /* cmp MEM32(ebp + (-0x40)), 0 */ /* 0x004E2FC6: cmp dword ptr [ebp - 0x40], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x40)), 0)) goto L_004E2FF1; /* 0x004E2FCA: je 0x4e2ff1 */

L_004E2FCC:
    MEM16(ebp + (-0x50)) = (uint16_t)(0x7FFFu); /* 0x004E2FCC: mov word ptr [ebp - 0x50], 0x7fff */
    MEM32(ebp + (-0x10)) = 0x80000000u; /* 0x004E2FD2: mov dword ptr [ebp - 0x10], 0x80000000 */
    MEM32(ebp + (-0x8)) = 0; /* 0x004E2FD9: mov dword ptr [ebp - 8], 0 */
    MEM16(ebp + (-0x48)) = (uint16_t)(0); /* 0x004E2FE0: mov word ptr [ebp - 0x48], 0 */
    edx = MEM32(ebp + (-0x44)); /* 0x004E2FE6: mov edx, dword ptr [ebp - 0x44] */
    edx = edx | 2; /* 0x004E2FE9: or edx, 2 */
    MEM32(ebp + (-0x44)) = edx; /* 0x004E2FEC: mov dword ptr [ebp - 0x44], edx */
    goto L_004E301D; /* 0x004E2FEF: jmp 0x4e301d */

L_004E2FF1:
    /* cmp MEM32(ebp + (-0x78)), 0 */ /* 0x004E2FF1: cmp dword ptr [ebp - 0x78], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x78)), 0)) goto L_004E301D; /* 0x004E2FF5: je 0x4e301d */

L_004E2FF7:
    MEM16(ebp + (-0x48)) = (uint16_t)(0); /* 0x004E2FF7: mov word ptr [ebp - 0x48], 0 */
    MEM16(ebp + (-0x50)) = (uint16_t)(0); /* 0x004E2FFD: mov word ptr [ebp - 0x50], 0 */
    eax = MEM32(ebp + (-0x50)); /* 0x004E3003: mov eax, dword ptr [ebp - 0x50] */
    eax = eax & 0xFFFFu; /* 0x004E3006: and eax, 0xffff */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E300B: mov dword ptr [ebp - 0x10], eax */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E300E: mov ecx, dword ptr [ebp - 0x10] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004E3011: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x44)); /* 0x004E3014: mov edx, dword ptr [ebp - 0x44] */
    edx = edx | 1; /* 0x004E3017: or edx, 1 */
    MEM32(ebp + (-0x44)) = edx; /* 0x004E301A: mov dword ptr [ebp - 0x44], edx */

L_004E301D:
    eax = MEM32(ebp + 0x8); /* 0x004E301D: mov eax, dword ptr [ebp + 8] */
    SET_LO16(ecx, MEM16(ebp + (-0x48))); /* 0x004E3020: mov cx, word ptr [ebp - 0x48] */
    MEM16(eax) = (uint16_t)(LO16(ecx)); /* 0x004E3024: mov word ptr [eax], cx */
    edx = MEM32(ebp + 0x8); /* 0x004E3027: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E302A: mov eax, dword ptr [ebp - 8] */
    MEM32(edx + 0x2) = eax; /* 0x004E302D: mov dword ptr [edx + 2], eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E3030: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ebp + (-0x10)); /* 0x004E3033: mov edx, dword ptr [ebp - 0x10] */
    MEM32(ecx + 0x6) = edx; /* 0x004E3036: mov dword ptr [ecx + 6], edx */
    eax = MEM32(ebp + (-0x50)); /* 0x004E3039: mov eax, dword ptr [ebp - 0x50] */
    eax = eax & 0xFFFFu; /* 0x004E303C: and eax, 0xffff */
    ecx = MEM32(ebp + (-0x1C)); /* 0x004E3041: mov ecx, dword ptr [ebp - 0x1c] */
    ecx = ecx & 0xFFFFu; /* 0x004E3044: and ecx, 0xffff */
    eax = eax | ecx; /* 0x004E304A: or eax, ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E304C: mov edx, dword ptr [ebp + 8] */
    MEM16(edx + 0xA) = (uint16_t)(LO16(eax)); /* 0x004E304F: mov word ptr [edx + 0xa], ax */
    eax = MEM32(ebp + (-0x44)); /* 0x004E3053: mov eax, dword ptr [ebp - 0x44] */
    esp = ebp; /* 0x004E3056: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E3058: pop ebp */
    return; /* 0x004E3059: ret  */

}

void sub_004E2D40(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E26E7:
    /* cmp MEM32(ebp + (-0x4C)), 0xAu */ /* 0x004E26E7: cmp dword ptr [ebp - 0x4c], 0xa */
    if (CMP_EQ(MEM32(ebp + (-0x4C)), 0xAu)) goto L_004E2E48; /* 0x004E26EB: je 0x4e2e48 */

L_004E26F1:
    eax = MEM32(ebp + (-0x4)); /* 0x004E26F1: mov eax, dword ptr [ebp - 4] */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E26F4: mov cl, byte ptr [eax] */
    MEM8(ebp + (-0x3C)) = (uint8_t)(LO8(ecx)); /* 0x004E26F6: mov byte ptr [ebp - 0x3c], cl */
    edx = MEM32(ebp + (-0x4)); /* 0x004E26F9: mov edx, dword ptr [ebp - 4] */
    edx = edx + 1; /* 0x004E26FC: add edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E26FF: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + (-0x4C)); /* 0x004E2702: mov eax, dword ptr [ebp - 0x4c] */
    MEM32(ebp + (-0x80)) = eax; /* 0x004E2705: mov dword ptr [ebp - 0x80], eax */
    /* cmp MEM32(ebp + (-0x80)), 0xBu */ /* 0x004E2708: cmp dword ptr [ebp - 0x80], 0xb */
    if (CMP_A(MEM32(ebp + (-0x80)), 0xBu)) goto L_004E2E43; /* 0x004E270C: ja 0x4e2e43 */

L_004E2712:
    ecx = MEM32(ebp + (-0x80)); /* 0x004E2712: mov ecx, dword ptr [ebp - 0x80] */
    RECOMP_ITAIL(MEM32(ecx * 4 + 0x4E305A)); return; /* 0x004E2715: jmp dword ptr [ecx*4 + 0x4e305a] */

L_004E2CE3:
    edx = MEM32(ebp + (-0x4)); /* 0x004E2CE3: mov edx, dword ptr [ebp - 4] */
    SET_LO8(eax, MEM8(edx)); /* 0x004E2CE6: mov al, byte ptr [edx] */
    MEM8(ebp + (-0x3C)) = (uint8_t)(LO8(eax)); /* 0x004E2CE8: mov byte ptr [ebp - 0x3c], al */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E2CEB: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004E2CEE: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E2CF1: mov dword ptr [ebp - 4], ecx */
    /* cmp MEM32(0x509634), 1 */ /* 0x004E2CF4: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004E2D19; /* 0x004E2CFB: jle 0x4e2d19 */

L_004E2CFD:
    PUSH32(esp, 4); /* 0x004E2CFD: push 4 */
    edx = MEM32(ebp + (-0x3C)); /* 0x004E2CFF: mov edx, dword ptr [ebp - 0x3c] */
    edx = edx & 0xFFu; /* 0x004E2D02: and edx, 0xff */
    PUSH32(esp, edx); /* 0x004E2D08: push edx */
    RECOMP_CALL(sub_004DA490); /* 0x004E2D09: call 0x4da490 */
    esp = esp + 8; /* 0x004E2D0E: add esp, 8 */
    MEM32(ebp + (-0xAC)) = eax; /* 0x004E2D11: mov dword ptr [ebp - 0xac], eax */
    goto L_004E2D36; /* 0x004E2D17: jmp 0x4e2d36 */

L_004E2D19:
    eax = MEM32(ebp + (-0x3C)); /* 0x004E2D19: mov eax, dword ptr [ebp - 0x3c] */
    eax = eax & 0xFFu; /* 0x004E2D1C: and eax, 0xff */
    ecx = MEM32(0x509428); /* 0x004E2D21: mov ecx, dword ptr [0x509428] */
    edx = 0; /* 0x004E2D27: xor edx, edx */
    SET_LO16(edx, MEM16(ecx + eax * 2)); /* 0x004E2D29: mov dx, word ptr [ecx + eax*2] */
    edx = edx & 4; /* 0x004E2D2D: and edx, 4 */
    MEM32(ebp + (-0xAC)) = edx; /* 0x004E2D30: mov dword ptr [ebp - 0xac], edx */

L_004E2D36:
    /* cmp MEM32(ebp + (-0xAC)), 0 */ /* 0x004E2D36: cmp dword ptr [ebp - 0xac], 0 */
    if (CMP_EQ(MEM32(ebp + (-0xAC)), 0)) goto L_004E2D67; /* 0x004E2D3D: je 0x4e2d67 */

L_004E2D3F:
    eax = MEM32(ebp + (-0x7C)); /* 0x004E2D3F: mov eax, dword ptr [ebp - 0x7c] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0xAu); /* 0x004E2D42: imul eax, eax, 0xa */
    ecx = (int32_t)(int8_t)MEM8(ebp + (-0x3C)); /* 0x004E2D45: movsx ecx, byte ptr [ebp - 0x3c] */
    edx = eax + ecx + (-0x30); /* 0x004E2D49: lea edx, [eax + ecx - 0x30] */
    MEM32(ebp + (-0x7C)) = edx; /* 0x004E2D4D: mov dword ptr [ebp - 0x7c], edx */
    /* cmp MEM32(ebp + (-0x7C)), 0x1450u */ /* 0x004E2D50: cmp dword ptr [ebp - 0x7c], 0x1450 */
    if (CMP_LE(MEM32(ebp + (-0x7C)), 0x1450u)) goto L_004E2D62; /* 0x004E2D57: jle 0x4e2d62 */

L_004E2D40:
    ebp = ebp + 1; /* 0x004E2D40: inc ebp */
    /* test MEM8(ebx + (-0x40)), HI8(ecx) */ /* 0x004E2D41: test byte ptr [ebx - 0x40], ch */
    SET_LO8(ecx, LO8(ecx) | MEM8(edi)); /* 0x004E2D44: or cl, byte ptr [edi] */
    esi = 0x548DC44Du; /* 0x004E2D46: mov esi, 0x548dc44d */
    SET_LO8(eax, LO8(eax) | LO8(edx)); /* 0x004E2D4B: or al, dl */
    MEM32(ebp + (-0x7C)) = edx; /* 0x004E2D4D: mov dword ptr [ebp - 0x7c], edx */
    /* cmp MEM32(ebp + (-0x7C)), 0x1450u */ /* 0x004E2D50: cmp dword ptr [ebp - 0x7c], 0x1450 */
    if (CMP_LE(MEM32(ebp + (-0x7C)), 0x1450u)) goto L_004E2D62; /* 0x004E2D57: jle 0x4e2d62 */

L_004E2D59:
    MEM32(ebp + (-0x7C)) = 0x1451u; /* 0x004E2D59: mov dword ptr [ebp - 0x7c], 0x1451 */
    goto L_004E2D67; /* 0x004E2D60: jmp 0x4e2d67 */

L_004E2D62:
    goto L_004E2CE3; /* 0x004E2D62: jmp 0x4e2ce3 */

L_004E2D67:
    eax = MEM32(ebp + (-0x7C)); /* 0x004E2D67: mov eax, dword ptr [ebp - 0x7c] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E2D6A: mov dword ptr [ebp - 0x14], eax */
    goto L_004E2D80; /* 0x004E2D6D: jmp 0x4e2d80 */

L_004E2D6F:
    ecx = MEM32(ebp + (-0x4)); /* 0x004E2D6F: mov ecx, dword ptr [ebp - 4] */
    SET_LO8(edx, MEM8(ecx)); /* 0x004E2D72: mov dl, byte ptr [ecx] */
    MEM8(ebp + (-0x3C)) = (uint8_t)(LO8(edx)); /* 0x004E2D74: mov byte ptr [ebp - 0x3c], dl */
    eax = MEM32(ebp + (-0x4)); /* 0x004E2D77: mov eax, dword ptr [ebp - 4] */
    eax = eax + 1; /* 0x004E2D7A: add eax, 1 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E2D7D: mov dword ptr [ebp - 4], eax */

L_004E2D80:
    /* cmp MEM32(0x509634), 1 */ /* 0x004E2D80: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004E2DA5; /* 0x004E2D87: jle 0x4e2da5 */

L_004E2D89:
    PUSH32(esp, 4); /* 0x004E2D89: push 4 */
    ecx = MEM32(ebp + (-0x3C)); /* 0x004E2D8B: mov ecx, dword ptr [ebp - 0x3c] */
    ecx = ecx & 0xFFu; /* 0x004E2D8E: and ecx, 0xff */
    PUSH32(esp, ecx); /* 0x004E2D94: push ecx */
    RECOMP_CALL(sub_004DA490); /* 0x004E2D95: call 0x4da490 */
    esp = esp + 8; /* 0x004E2D9A: add esp, 8 */
    MEM32(ebp + (-0xB0)) = eax; /* 0x004E2D9D: mov dword ptr [ebp - 0xb0], eax */
    goto L_004E2DC2; /* 0x004E2DA3: jmp 0x4e2dc2 */

L_004E2DA5:
    edx = MEM32(ebp + (-0x3C)); /* 0x004E2DA5: mov edx, dword ptr [ebp - 0x3c] */
    edx = edx & 0xFFu; /* 0x004E2DA8: and edx, 0xff */
    eax = MEM32(0x509428); /* 0x004E2DAE: mov eax, dword ptr [0x509428] */
    ecx = 0; /* 0x004E2DB3: xor ecx, ecx */
    SET_LO16(ecx, MEM16(eax + edx * 2)); /* 0x004E2DB5: mov cx, word ptr [eax + edx*2] */
    ecx = ecx & 4; /* 0x004E2DB9: and ecx, 4 */
    MEM32(ebp + (-0xB0)) = ecx; /* 0x004E2DBC: mov dword ptr [ebp - 0xb0], ecx */

L_004E2DC2:
    /* cmp MEM32(ebp + (-0xB0)), 0 */ /* 0x004E2DC2: cmp dword ptr [ebp - 0xb0], 0 */
    if (CMP_EQ(MEM32(ebp + (-0xB0)), 0)) goto L_004E2DCD; /* 0x004E2DC9: je 0x4e2dcd */

L_004E2DCB:
    goto L_004E2D6F; /* 0x004E2DCB: jmp 0x4e2d6f */

L_004E2DCD:
    MEM32(ebp + (-0x4C)) = 0xAu; /* 0x004E2DCD: mov dword ptr [ebp - 0x4c], 0xa */
    edx = MEM32(ebp + (-0x4)); /* 0x004E2DD4: mov edx, dword ptr [ebp - 4] */
    edx = edx - 1; /* 0x004E2DD7: sub edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E2DDA: mov dword ptr [ebp - 4], edx */
    goto L_004E2E43; /* 0x004E2DDD: jmp 0x4e2e43 */

L_004E2E43:
    goto L_004E26E7; /* 0x004E2E43: jmp 0x4e26e7 */

L_004E2E48:
    ecx = MEM32(ebp + 0xC); /* 0x004E2E48: mov ecx, dword ptr [ebp + 0xc] */
    edx = MEM32(ebp + (-0x4)); /* 0x004E2E4B: mov edx, dword ptr [ebp - 4] */
    MEM32(ecx) = edx; /* 0x004E2E4E: mov dword ptr [ecx], edx */
    /* cmp MEM32(ebp + (-0x54)), 0 */ /* 0x004E2E50: cmp dword ptr [ebp - 0x54], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x54)), 0)) goto L_004E2F97; /* 0x004E2E54: je 0x4e2f97 */

L_004E2E5A:
    /* cmp MEM32(ebp + (-0x40)), 0 */ /* 0x004E2E5A: cmp dword ptr [ebp - 0x40], 0 */
    if (CMP_NE(MEM32(ebp + (-0x40)), 0)) goto L_004E2F97; /* 0x004E2E5E: jne 0x4e2f97 */

L_004E2E64:
    /* cmp MEM32(ebp + (-0x78)), 0 */ /* 0x004E2E64: cmp dword ptr [ebp - 0x78], 0 */
    if (CMP_NE(MEM32(ebp + (-0x78)), 0)) goto L_004E2F97; /* 0x004E2E68: jne 0x4e2f97 */

L_004E2E6E:
    /* cmp MEM32(ebp + (-0x70)), 0x18u */ /* 0x004E2E6E: cmp dword ptr [ebp - 0x70], 0x18 */
    if (CMP_BE(MEM32(ebp + (-0x70)), 0x18u)) goto L_004E2E9F; /* 0x004E2E72: jbe 0x4e2e9f */

L_004E2E74:
    eax = (int32_t)(int8_t)MEM8(ebp + (-0x21)); /* 0x004E2E74: movsx eax, byte ptr [ebp - 0x21] */
    /* cmp eax, 5 */ /* 0x004E2E78: cmp eax, 5 */
    if (CMP_L(eax, 5)) goto L_004E2E86; /* 0x004E2E7B: jl 0x4e2e86 */

L_004E2E7D:
    SET_LO8(ecx, MEM8(ebp + (-0x21))); /* 0x004E2E7D: mov cl, byte ptr [ebp - 0x21] */
    SET_LO8(ecx, LO8(ecx) + 1); /* 0x004E2E80: add cl, 1 */
    MEM8(ebp + (-0x21)) = (uint8_t)(LO8(ecx)); /* 0x004E2E83: mov byte ptr [ebp - 0x21], cl */

L_004E2E86:
    MEM32(ebp + (-0x70)) = 0x18u; /* 0x004E2E86: mov dword ptr [ebp - 0x70], 0x18 */
    edx = MEM32(ebp + (-0x68)); /* 0x004E2E8D: mov edx, dword ptr [ebp - 0x68] */
    edx = edx - 1; /* 0x004E2E90: sub edx, 1 */
    MEM32(ebp + (-0x68)) = edx; /* 0x004E2E93: mov dword ptr [ebp - 0x68], edx */
    eax = MEM32(ebp + (-0x6C)); /* 0x004E2E96: mov eax, dword ptr [ebp - 0x6c] */
    eax = eax + 1; /* 0x004E2E99: add eax, 1 */
    MEM32(ebp + (-0x6C)) = eax; /* 0x004E2E9C: mov dword ptr [ebp - 0x6c], eax */

L_004E2E9F:
    /* cmp MEM32(ebp + (-0x70)), 0 */ /* 0x004E2E9F: cmp dword ptr [ebp - 0x70], 0 */
    if (CMP_BE(MEM32(ebp + (-0x70)), 0)) goto L_004E2F7A; /* 0x004E2EA3: jbe 0x4e2f7a */

L_004E2EA9:
    ecx = MEM32(ebp + (-0x68)); /* 0x004E2EA9: mov ecx, dword ptr [ebp - 0x68] */
    ecx = ecx - 1; /* 0x004E2EAC: sub ecx, 1 */
    MEM32(ebp + (-0x68)) = ecx; /* 0x004E2EAF: mov dword ptr [ebp - 0x68], ecx */
    goto L_004E2EBD; /* 0x004E2EB2: jmp 0x4e2ebd */

L_004E2EB4:
    edx = MEM32(ebp + (-0x68)); /* 0x004E2EB4: mov edx, dword ptr [ebp - 0x68] */
    edx = edx - 1; /* 0x004E2EB7: sub edx, 1 */
    MEM32(ebp + (-0x68)) = edx; /* 0x004E2EBA: mov dword ptr [ebp - 0x68], edx */

L_004E2EBD:
    eax = MEM32(ebp + (-0x68)); /* 0x004E2EBD: mov eax, dword ptr [ebp - 0x68] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004E2EC0: movsx ecx, byte ptr [eax] */
    /* test ecx, ecx */ /* 0x004E2EC3: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004E2EDB; /* 0x004E2EC5: jne 0x4e2edb */

L_004E2EC7:
    edx = MEM32(ebp + (-0x70)); /* 0x004E2EC7: mov edx, dword ptr [ebp - 0x70] */
    edx = edx - 1; /* 0x004E2ECA: sub edx, 1 */
    MEM32(ebp + (-0x70)) = edx; /* 0x004E2ECD: mov dword ptr [ebp - 0x70], edx */
    eax = MEM32(ebp + (-0x6C)); /* 0x004E2ED0: mov eax, dword ptr [ebp - 0x6c] */
    eax = eax + 1; /* 0x004E2ED3: add eax, 1 */
    MEM32(ebp + (-0x6C)) = eax; /* 0x004E2ED6: mov dword ptr [ebp - 0x6c], eax */
    goto L_004E2EB4; /* 0x004E2ED9: jmp 0x4e2eb4 */

L_004E2EDB:
    ecx = ebp + (-0x60); /* 0x004E2EDB: lea ecx, [ebp - 0x60] */
    PUSH32(esp, ecx); /* 0x004E2EDE: push ecx */
    edx = MEM32(ebp + (-0x70)); /* 0x004E2EDF: mov edx, dword ptr [ebp - 0x70] */
    PUSH32(esp, edx); /* 0x004E2EE2: push edx */
    eax = ebp + (-0x38); /* 0x004E2EE3: lea eax, [ebp - 0x38] */
    PUSH32(esp, eax); /* 0x004E2EE6: push eax */
    RECOMP_CALL(sub_004E2500); /* 0x004E2EE7: call 0x4e2500 */
    esp = esp + 0xCu; /* 0x004E2EEC: add esp, 0xc */
    /* cmp MEM32(ebp + (-0x74)), 0 */ /* 0x004E2EEF: cmp dword ptr [ebp - 0x74], 0 */
    if (CMP_GE(MEM32(ebp + (-0x74)), 0)) goto L_004E2EFD; /* 0x004E2EF3: jge 0x4e2efd */

L_004E2EF5:
    ecx = MEM32(ebp + (-0x14)); /* 0x004E2EF5: mov ecx, dword ptr [ebp - 0x14] */
    ecx = (uint32_t)(-(int32_t)ecx); /* 0x004E2EF8: neg ecx */
    MEM32(ebp + (-0x14)) = ecx; /* 0x004E2EFA: mov dword ptr [ebp - 0x14], ecx */

L_004E2EFD:
    edx = MEM32(ebp + (-0x14)); /* 0x004E2EFD: mov edx, dword ptr [ebp - 0x14] */
    edx = edx + MEM32(ebp + (-0x6C)); /* 0x004E2F00: add edx, dword ptr [ebp - 0x6c] */
    MEM32(ebp + (-0x14)) = edx; /* 0x004E2F03: mov dword ptr [ebp - 0x14], edx */
    /* cmp MEM32(ebp + (-0x18)), 0 */ /* 0x004E2F06: cmp dword ptr [ebp - 0x18], 0 */
    if (CMP_NE(MEM32(ebp + (-0x18)), 0)) goto L_004E2F15; /* 0x004E2F0A: jne 0x4e2f15 */

L_004E2F0C:
    eax = MEM32(ebp + (-0x14)); /* 0x004E2F0C: mov eax, dword ptr [ebp - 0x14] */
    eax = eax + MEM32(ebp + 0x18); /* 0x004E2F0F: add eax, dword ptr [ebp + 0x18] */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E2F12: mov dword ptr [ebp - 0x14], eax */

L_004E2F15:
    /* cmp MEM32(ebp + (-0xC)), 0 */ /* 0x004E2F15: cmp dword ptr [ebp - 0xc], 0 */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0)) goto L_004E2F24; /* 0x004E2F19: jne 0x4e2f24 */

L_004E2F1B:
    ecx = MEM32(ebp + (-0x14)); /* 0x004E2F1B: mov ecx, dword ptr [ebp - 0x14] */
    ecx = ecx - MEM32(ebp + 0x1C); /* 0x004E2F1E: sub ecx, dword ptr [ebp + 0x1c] */
    MEM32(ebp + (-0x14)) = ecx; /* 0x004E2F21: mov dword ptr [ebp - 0x14], ecx */

L_004E2F24:
    /* cmp MEM32(ebp + (-0x14)), 0x1450u */ /* 0x004E2F24: cmp dword ptr [ebp - 0x14], 0x1450 */
    if (CMP_LE(MEM32(ebp + (-0x14)), 0x1450u)) goto L_004E2F36; /* 0x004E2F2B: jle 0x4e2f36 */

L_004E2F2D:
    MEM32(ebp + (-0x40)) = 1; /* 0x004E2F2D: mov dword ptr [ebp - 0x40], 1 */
    goto L_004E2F78; /* 0x004E2F34: jmp 0x4e2f78 */

L_004E2F36:
    /* cmp MEM32(ebp + (-0x14)), 0xFFFFEBB0u */ /* 0x004E2F36: cmp dword ptr [ebp - 0x14], 0xffffebb0 */
    if (CMP_GE(MEM32(ebp + (-0x14)), 0xFFFFEBB0u)) goto L_004E2F48; /* 0x004E2F3D: jge 0x4e2f48 */

L_004E2F3F:
    MEM32(ebp + (-0x78)) = 1; /* 0x004E2F3F: mov dword ptr [ebp - 0x78], 1 */
    goto L_004E2F78; /* 0x004E2F46: jmp 0x4e2f78 */

L_004E2F48:
    edx = MEM32(ebp + 0x14); /* 0x004E2F48: mov edx, dword ptr [ebp + 0x14] */
    PUSH32(esp, edx); /* 0x004E2F4B: push edx */
    eax = MEM32(ebp + (-0x14)); /* 0x004E2F4C: mov eax, dword ptr [ebp - 0x14] */
    PUSH32(esp, eax); /* 0x004E2F4F: push eax */
    ecx = ebp + (-0x60); /* 0x004E2F50: lea ecx, [ebp - 0x60] */
    PUSH32(esp, ecx); /* 0x004E2F53: push ecx */
    RECOMP_CALL(sub_004E4850); /* 0x004E2F54: call 0x4e4850 */
    esp = esp + 0xCu; /* 0x004E2F59: add esp, 0xc */
    SET_LO16(edx, MEM16(ebp + (-0x60))); /* 0x004E2F5C: mov dx, word ptr [ebp - 0x60] */
    MEM16(ebp + (-0x48)) = (uint16_t)(LO16(edx)); /* 0x004E2F60: mov word ptr [ebp - 0x48], dx */
    eax = MEM32(ebp + (-0x5E)); /* 0x004E2F64: mov eax, dword ptr [ebp - 0x5e] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E2F67: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x5A)); /* 0x004E2F6A: mov ecx, dword ptr [ebp - 0x5a] */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004E2F6D: mov dword ptr [ebp - 0x10], ecx */
    SET_LO16(edx, MEM16(ebp + (-0x56))); /* 0x004E2F70: mov dx, word ptr [ebp - 0x56] */
    MEM16(ebp + (-0x50)) = (uint16_t)(LO16(edx)); /* 0x004E2F74: mov word ptr [ebp - 0x50], dx */

L_004E2F78:
    goto L_004E2F97; /* 0x004E2F78: jmp 0x4e2f97 */

L_004E2F7A:
    MEM16(ebp + (-0x48)) = (uint16_t)(0); /* 0x004E2F7A: mov word ptr [ebp - 0x48], 0 */
    MEM16(ebp + (-0x50)) = (uint16_t)(0); /* 0x004E2F80: mov word ptr [ebp - 0x50], 0 */
    eax = MEM32(ebp + (-0x50)); /* 0x004E2F86: mov eax, dword ptr [ebp - 0x50] */
    eax = eax & 0xFFFFu; /* 0x004E2F89: and eax, 0xffff */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E2F8E: mov dword ptr [ebp - 0x10], eax */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E2F91: mov ecx, dword ptr [ebp - 0x10] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004E2F94: mov dword ptr [ebp - 8], ecx */

L_004E2F97:
    /* cmp MEM32(ebp + (-0x54)), 0 */ /* 0x004E2F97: cmp dword ptr [ebp - 0x54], 0 */
    if (CMP_NE(MEM32(ebp + (-0x54)), 0)) goto L_004E2FC6; /* 0x004E2F9B: jne 0x4e2fc6 */

L_004E2F9D:
    MEM16(ebp + (-0x48)) = (uint16_t)(0); /* 0x004E2F9D: mov word ptr [ebp - 0x48], 0 */
    MEM16(ebp + (-0x50)) = (uint16_t)(0); /* 0x004E2FA3: mov word ptr [ebp - 0x50], 0 */
    edx = MEM32(ebp + (-0x50)); /* 0x004E2FA9: mov edx, dword ptr [ebp - 0x50] */
    edx = edx & 0xFFFFu; /* 0x004E2FAC: and edx, 0xffff */
    MEM32(ebp + (-0x10)) = edx; /* 0x004E2FB2: mov dword ptr [ebp - 0x10], edx */
    eax = MEM32(ebp + (-0x10)); /* 0x004E2FB5: mov eax, dword ptr [ebp - 0x10] */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E2FB8: mov dword ptr [ebp - 8], eax */
    ecx = MEM32(ebp + (-0x44)); /* 0x004E2FBB: mov ecx, dword ptr [ebp - 0x44] */
    ecx = ecx | 4; /* 0x004E2FBE: or ecx, 4 */
    MEM32(ebp + (-0x44)) = ecx; /* 0x004E2FC1: mov dword ptr [ebp - 0x44], ecx */
    goto L_004E301D; /* 0x004E2FC4: jmp 0x4e301d */

L_004E2FC6:
    /* cmp MEM32(ebp + (-0x40)), 0 */ /* 0x004E2FC6: cmp dword ptr [ebp - 0x40], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x40)), 0)) goto L_004E2FF1; /* 0x004E2FCA: je 0x4e2ff1 */

L_004E2FCC:
    MEM16(ebp + (-0x50)) = (uint16_t)(0x7FFFu); /* 0x004E2FCC: mov word ptr [ebp - 0x50], 0x7fff */
    MEM32(ebp + (-0x10)) = 0x80000000u; /* 0x004E2FD2: mov dword ptr [ebp - 0x10], 0x80000000 */
    MEM32(ebp + (-0x8)) = 0; /* 0x004E2FD9: mov dword ptr [ebp - 8], 0 */
    MEM16(ebp + (-0x48)) = (uint16_t)(0); /* 0x004E2FE0: mov word ptr [ebp - 0x48], 0 */
    edx = MEM32(ebp + (-0x44)); /* 0x004E2FE6: mov edx, dword ptr [ebp - 0x44] */
    edx = edx | 2; /* 0x004E2FE9: or edx, 2 */
    MEM32(ebp + (-0x44)) = edx; /* 0x004E2FEC: mov dword ptr [ebp - 0x44], edx */
    goto L_004E301D; /* 0x004E2FEF: jmp 0x4e301d */

L_004E2FF1:
    /* cmp MEM32(ebp + (-0x78)), 0 */ /* 0x004E2FF1: cmp dword ptr [ebp - 0x78], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x78)), 0)) goto L_004E301D; /* 0x004E2FF5: je 0x4e301d */

L_004E2FF7:
    MEM16(ebp + (-0x48)) = (uint16_t)(0); /* 0x004E2FF7: mov word ptr [ebp - 0x48], 0 */
    MEM16(ebp + (-0x50)) = (uint16_t)(0); /* 0x004E2FFD: mov word ptr [ebp - 0x50], 0 */
    eax = MEM32(ebp + (-0x50)); /* 0x004E3003: mov eax, dword ptr [ebp - 0x50] */
    eax = eax & 0xFFFFu; /* 0x004E3006: and eax, 0xffff */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E300B: mov dword ptr [ebp - 0x10], eax */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E300E: mov ecx, dword ptr [ebp - 0x10] */
    MEM32(ebp + (-0x8)) = ecx; /* 0x004E3011: mov dword ptr [ebp - 8], ecx */
    edx = MEM32(ebp + (-0x44)); /* 0x004E3014: mov edx, dword ptr [ebp - 0x44] */
    edx = edx | 1; /* 0x004E3017: or edx, 1 */
    MEM32(ebp + (-0x44)) = edx; /* 0x004E301A: mov dword ptr [ebp - 0x44], edx */

L_004E301D:
    eax = MEM32(ebp + 0x8); /* 0x004E301D: mov eax, dword ptr [ebp + 8] */
    SET_LO16(ecx, MEM16(ebp + (-0x48))); /* 0x004E3020: mov cx, word ptr [ebp - 0x48] */
    MEM16(eax) = (uint16_t)(LO16(ecx)); /* 0x004E3024: mov word ptr [eax], cx */
    edx = MEM32(ebp + 0x8); /* 0x004E3027: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E302A: mov eax, dword ptr [ebp - 8] */
    MEM32(edx + 0x2) = eax; /* 0x004E302D: mov dword ptr [edx + 2], eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E3030: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ebp + (-0x10)); /* 0x004E3033: mov edx, dword ptr [ebp - 0x10] */
    MEM32(ecx + 0x6) = edx; /* 0x004E3036: mov dword ptr [ecx + 6], edx */
    eax = MEM32(ebp + (-0x50)); /* 0x004E3039: mov eax, dword ptr [ebp - 0x50] */
    eax = eax & 0xFFFFu; /* 0x004E303C: and eax, 0xffff */
    ecx = MEM32(ebp + (-0x1C)); /* 0x004E3041: mov ecx, dword ptr [ebp - 0x1c] */
    ecx = ecx & 0xFFFFu; /* 0x004E3044: and ecx, 0xffff */
    eax = eax | ecx; /* 0x004E304A: or eax, ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E304C: mov edx, dword ptr [ebp + 8] */
    MEM16(edx + 0xA) = (uint16_t)(LO16(eax)); /* 0x004E304F: mov word ptr [edx + 0xa], ax */
    eax = MEM32(ebp + (-0x44)); /* 0x004E3053: mov eax, dword ptr [ebp - 0x44] */
    esp = ebp; /* 0x004E3056: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E3058: pop ebp */
    return; /* 0x004E3059: ret  */

}

void sub_004E3020(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3020:
    SET_LO16(ecx, MEM16(ebp + (-0x48))); /* 0x004E3020: mov cx, word ptr [ebp - 0x48] */
    MEM16(eax) = (uint16_t)(LO16(ecx)); /* 0x004E3024: mov word ptr [eax], cx */
    edx = MEM32(ebp + 0x8); /* 0x004E3027: mov edx, dword ptr [ebp + 8] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E302A: mov eax, dword ptr [ebp - 8] */
    MEM32(edx + 0x2) = eax; /* 0x004E302D: mov dword ptr [edx + 2], eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E3030: mov ecx, dword ptr [ebp + 8] */
    edx = MEM32(ebp + (-0x10)); /* 0x004E3033: mov edx, dword ptr [ebp - 0x10] */
    MEM32(ecx + 0x6) = edx; /* 0x004E3036: mov dword ptr [ecx + 6], edx */
    eax = MEM32(ebp + (-0x50)); /* 0x004E3039: mov eax, dword ptr [ebp - 0x50] */
    eax = eax & 0xFFFFu; /* 0x004E303C: and eax, 0xffff */
    ecx = MEM32(ebp + (-0x1C)); /* 0x004E3041: mov ecx, dword ptr [ebp - 0x1c] */
    ecx = ecx & 0xFFFFu; /* 0x004E3044: and ecx, 0xffff */
    eax = eax | ecx; /* 0x004E304A: or eax, ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E304C: mov edx, dword ptr [ebp + 8] */
    MEM16(edx + 0xA) = (uint16_t)(LO16(eax)); /* 0x004E304F: mov word ptr [edx + 0xa], ax */
    eax = MEM32(ebp + (-0x44)); /* 0x004E3053: mov eax, dword ptr [ebp - 0x44] */
    esp = ebp; /* 0x004E3056: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E3058: pop ebp */
    return; /* 0x004E3059: ret  */

}

void sub_004E3090(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3090:
    esi = esi - 1; /* 0x004E3090: dec esi */
    MEM8(edi) = (uint8_t)(MEM8(edi) + HI8(edx)); /* 0x004E3091: add byte ptr [edi], dh */
    MEM8(esi) = (uint8_t)(MEM8(esi) - LO8(ecx)); /* 0x004E3093: sub byte ptr [esi], cl */
    eax = eax + 1; /* 0x004E3096: inc eax */
    MEM8(esi) = (uint8_t)(MEM8(esi) - LO8(ecx)); /* 0x004E3097: sub byte ptr [esi], cl */
    eax = eax + 1; /* 0x004E309A: inc eax */
    MEM8(esi) = (uint8_t)(MEM8(esi) - LO8(ecx)); /* 0x004E309B: sub byte ptr [esi], cl */
    ebx = POP32_VAL(esp); /* 0x004E309E: pop ebx */
    MEM8(esi) = (uint8_t)(MEM8(esi) - LO8(ecx)); /* 0x004E309F: sub byte ptr [esi], cl */
    MEM8(0x2050501) = (uint8_t)(MEM8(0x2050501) + LO8(eax)); /* 0x004E30A2: add byte ptr [0x2050501], al */
    eax = eax + 0x05050505u; /* 0x004E30A8: add eax, 0x5050505 */
    eax = eax + 0x05050505u; /* 0x004E30AD: add eax, 0x5050505 */
    eax = eax + 0x05050505u; /* 0x004E30B2: add eax, 0x5050505 */
    eax = eax + 0x03050505u; /* 0x004E30B7: add eax, 0x3050505 */
    eax = eax + MEM32(0x5050505); /* 0x004E30BC: add eax, dword ptr [0x5050505] */
    eax = eax + 0x05050505u; /* 0x004E30C2: add eax, 0x5050505 */
    eax = eax + 0x05050505u; /* 0x004E30C7: add eax, 0x5050505 */
    eax = eax + 0x05050505u; /* 0x004E30CC: add eax, 0x5050505 */
    eax = eax + 0x05050505u; /* 0x004E30D1: add eax, 0x5050505 */
    eax = eax + 0x05050505u; /* 0x004E30D6: add eax, 0x5050505 */
    SET_LO8(eax, LO8(eax) + 4); /* 0x004E30DB: add al, 4 */
    /* int3 breakpoint */ /* 0x004E30DD: int3  */

}

void sub_004E3260(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3260:
    MEM8(ebp + (-0x74F68B2E)) = (uint8_t)(MEM8(ebp + (-0x74F68B2E)) + LO8(eax)); /* 0x004E3260: add byte ptr [ebp - 0x74f68b2e], al */
    ebp = ebp + 1; /* 0x004E3266: inc ebp */
    SET_LO8(eax, LO8(eax) - 0xC6u - _cf); /* 0x004E3267: sbb al, 0xc6 */
    eax = eax + 1; /* 0x004E3269: inc eax */
    SET_HI8(ecx, HI8(ecx) + MEM8(0x4D8B07EB)); /* 0x004E326A: add ch, byte ptr [0x4d8b07eb] */
    SET_LO8(eax, LO8(eax) - 0xC6u - _cf); /* 0x004E3270: sbb al, 0xc6 */
    ecx = ecx + 1; /* 0x004E3272: inc ecx */
    SET_HI8(eax, HI8(eax) + MEM8(eax)); /* 0x004E3273: add ah, byte ptr [eax] */
    edx = MEM32(ebp + (-0x70)); /* 0x004E3275: mov edx, dword ptr [ebp - 0x70] */
    edx = edx & 0xFFFFu; /* 0x004E3278: and edx, 0xffff */
    /* test edx, edx */ /* 0x004E327E: test edx, edx */
    if (TEST_NZ(edx, edx)) goto L_004E32BC; /* 0x004E3280: jne 0x4e32bc */

L_004E3282:
    /* cmp MEM32(ebp + (-0x24)), 0 */ /* 0x004E3282: cmp dword ptr [ebp - 0x24], 0 */
    if (CMP_NE(MEM32(ebp + (-0x24)), 0)) goto L_004E32BC; /* 0x004E3286: jne 0x4e32bc */

L_004E3288:
    /* cmp MEM32(ebp + (-0x48)), 0 */ /* 0x004E3288: cmp dword ptr [ebp - 0x48], 0 */
    if (CMP_NE(MEM32(ebp + (-0x48)), 0)) goto L_004E32BC; /* 0x004E328C: jne 0x4e32bc */

L_004E328E:
    eax = MEM32(ebp + 0x1C); /* 0x004E328E: mov eax, dword ptr [ebp + 0x1c] */
    MEM16(eax) = (uint16_t)(0); /* 0x004E3291: mov word ptr [eax], 0 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E3296: mov ecx, dword ptr [ebp + 0x1c] */
    MEM8(ecx + 0x2) = (uint8_t)(0x20u); /* 0x004E3299: mov byte ptr [ecx + 2], 0x20 */
    edx = MEM32(ebp + 0x1C); /* 0x004E329D: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + 0x3) = (uint8_t)(1); /* 0x004E32A0: mov byte ptr [edx + 3], 1 */
    eax = MEM32(ebp + 0x1C); /* 0x004E32A4: mov eax, dword ptr [ebp + 0x1c] */
    MEM8(eax + 0x4) = (uint8_t)(0x30u); /* 0x004E32A7: mov byte ptr [eax + 4], 0x30 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E32AB: mov ecx, dword ptr [ebp + 0x1c] */
    MEM8(ecx + 0x5) = (uint8_t)(0); /* 0x004E32AE: mov byte ptr [ecx + 5], 0 */
    eax = 1; /* 0x004E32B2: mov eax, 1 */
    goto L_004E36E2; /* 0x004E32B7: jmp 0x4e36e2 */

L_004E32BC:
    edx = MEM32(ebp + (-0x70)); /* 0x004E32BC: mov edx, dword ptr [ebp - 0x70] */
    edx = edx & 0xFFFFu; /* 0x004E32BF: and edx, 0xffff */
    /* cmp edx, 0x7FFFu */ /* 0x004E32C5: cmp edx, 0x7fff */
    if (CMP_NE(edx, 0x7FFFu)) goto L_004E33B6; /* 0x004E32CB: jne 0x4e33b6 */

L_004E32D1:
    eax = MEM32(ebp + 0x1C); /* 0x004E32D1: mov eax, dword ptr [ebp + 0x1c] */
    MEM16(eax) = (uint16_t)(1); /* 0x004E32D4: mov word ptr [eax], 1 */
    /* cmp MEM32(ebp + (-0x24)), 0x80000000u */ /* 0x004E32D9: cmp dword ptr [ebp - 0x24], 0x80000000 */
    if (CMP_NE(MEM32(ebp + (-0x24)), 0x80000000u)) goto L_004E32E8; /* 0x004E32E0: jne 0x4e32e8 */

L_004E32E2:
    /* cmp MEM32(ebp + (-0x48)), 0 */ /* 0x004E32E2: cmp dword ptr [ebp - 0x48], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x48)), 0)) goto L_004E331C; /* 0x004E32E6: je 0x4e331c */

L_004E32E8:
    ecx = MEM32(ebp + (-0x24)); /* 0x004E32E8: mov ecx, dword ptr [ebp - 0x24] */
    ecx = ecx & 0x40000000u; /* 0x004E32EB: and ecx, 0x40000000 */
    /* test ecx, ecx */ /* 0x004E32F1: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004E331C; /* 0x004E32F3: jne 0x4e331c */

L_004E32F5:
    PUSH32(esp, 0x004F4788u); /* 0x004E32F5: push 0x4f4788 */
    edx = MEM32(ebp + 0x1C); /* 0x004E32FA: mov edx, dword ptr [ebp + 0x1c] */
    edx = edx + 4; /* 0x004E32FD: add edx, 4 */
    PUSH32(esp, edx); /* 0x004E3300: push edx */
    RECOMP_CALL(sub_004DC810); /* 0x004E3301: call 0x4dc810 */
    esp = esp + 8; /* 0x004E3306: add esp, 8 */
    eax = MEM32(ebp + 0x1C); /* 0x004E3309: mov eax, dword ptr [ebp + 0x1c] */
    MEM8(eax + 0x3) = (uint8_t)(6); /* 0x004E330C: mov byte ptr [eax + 3], 6 */
    MEM32(ebp + (-0x58)) = 0; /* 0x004E3310: mov dword ptr [ebp - 0x58], 0 */
    goto L_004E33B1; /* 0x004E3317: jmp 0x4e33b1 */

L_004E331C:
    ecx = MEM32(ebp + (-0x68)); /* 0x004E331C: mov ecx, dword ptr [ebp - 0x68] */
    ecx = ecx & 0xFFFFu; /* 0x004E331F: and ecx, 0xffff */
    /* test ecx, ecx */ /* 0x004E3325: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004E335C; /* 0x004E3327: je 0x4e335c */

L_004E3329:
    /* cmp MEM32(ebp + (-0x24)), 0xC0000000u */ /* 0x004E3329: cmp dword ptr [ebp - 0x24], 0xc0000000 */
    if (CMP_NE(MEM32(ebp + (-0x24)), 0xC0000000u)) goto L_004E335C; /* 0x004E3330: jne 0x4e335c */

L_004E3332:
    /* cmp MEM32(ebp + (-0x48)), 0 */ /* 0x004E3332: cmp dword ptr [ebp - 0x48], 0 */
    if (CMP_NE(MEM32(ebp + (-0x48)), 0)) goto L_004E335C; /* 0x004E3336: jne 0x4e335c */

L_004E3338:
    PUSH32(esp, 0x004F4780u); /* 0x004E3338: push 0x4f4780 */
    edx = MEM32(ebp + 0x1C); /* 0x004E333D: mov edx, dword ptr [ebp + 0x1c] */
    edx = edx + 4; /* 0x004E3340: add edx, 4 */
    PUSH32(esp, edx); /* 0x004E3343: push edx */
    RECOMP_CALL(sub_004DC810); /* 0x004E3344: call 0x4dc810 */
    esp = esp + 8; /* 0x004E3349: add esp, 8 */
    eax = MEM32(ebp + 0x1C); /* 0x004E334C: mov eax, dword ptr [ebp + 0x1c] */
    MEM8(eax + 0x3) = (uint8_t)(5); /* 0x004E334F: mov byte ptr [eax + 3], 5 */
    MEM32(ebp + (-0x58)) = 0; /* 0x004E3353: mov dword ptr [ebp - 0x58], 0 */
    goto L_004E33B1; /* 0x004E335A: jmp 0x4e33b1 */

L_004E335C:
    /* cmp MEM32(ebp + (-0x24)), 0x80000000u */ /* 0x004E335C: cmp dword ptr [ebp - 0x24], 0x80000000 */
    if (CMP_NE(MEM32(ebp + (-0x24)), 0x80000000u)) goto L_004E338F; /* 0x004E3363: jne 0x4e338f */

L_004E3365:
    /* cmp MEM32(ebp + (-0x48)), 0 */ /* 0x004E3365: cmp dword ptr [ebp - 0x48], 0 */
    if (CMP_NE(MEM32(ebp + (-0x48)), 0)) goto L_004E338F; /* 0x004E3369: jne 0x4e338f */

L_004E336B:
    PUSH32(esp, 0x004F4778u); /* 0x004E336B: push 0x4f4778 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E3370: mov ecx, dword ptr [ebp + 0x1c] */
    ecx = ecx + 4; /* 0x004E3373: add ecx, 4 */
    PUSH32(esp, ecx); /* 0x004E3376: push ecx */
    RECOMP_CALL(sub_004DC810); /* 0x004E3377: call 0x4dc810 */
    esp = esp + 8; /* 0x004E337C: add esp, 8 */
    edx = MEM32(ebp + 0x1C); /* 0x004E337F: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + 0x3) = (uint8_t)(5); /* 0x004E3382: mov byte ptr [edx + 3], 5 */
    MEM32(ebp + (-0x58)) = 0; /* 0x004E3386: mov dword ptr [ebp - 0x58], 0 */
    goto L_004E33B1; /* 0x004E338D: jmp 0x4e33b1 */

L_004E338F:
    PUSH32(esp, 0x004F4770u); /* 0x004E338F: push 0x4f4770 */
    eax = MEM32(ebp + 0x1C); /* 0x004E3394: mov eax, dword ptr [ebp + 0x1c] */
    eax = eax + 4; /* 0x004E3397: add eax, 4 */
    PUSH32(esp, eax); /* 0x004E339A: push eax */
    RECOMP_CALL(sub_004DC810); /* 0x004E339B: call 0x4dc810 */
    esp = esp + 8; /* 0x004E33A0: add esp, 8 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E33A3: mov ecx, dword ptr [ebp + 0x1c] */
    MEM8(ecx + 0x3) = (uint8_t)(6); /* 0x004E33A6: mov byte ptr [ecx + 3], 6 */
    MEM32(ebp + (-0x58)) = 0; /* 0x004E33AA: mov dword ptr [ebp - 0x58], 0 */

L_004E33B1:
    goto L_004E36DF; /* 0x004E33B1: jmp 0x4e36df */

L_004E33B6:
    edx = MEM32(ebp + (-0x70)); /* 0x004E33B6: mov edx, dword ptr [ebp - 0x70] */
    edx = edx & 0xFFFFu; /* 0x004E33B9: and edx, 0xffff */
    edx = (uint32_t)((int32_t)edx >> 8); /* 0x004E33BF: sar edx, 8 */
    MEM16(ebp + (-0x6C)) = (uint16_t)(LO16(edx)); /* 0x004E33C2: mov word ptr [ebp - 0x6c], dx */
    eax = MEM32(ebp + (-0x70)); /* 0x004E33C6: mov eax, dword ptr [ebp - 0x70] */
    eax = eax & 0xFFFFu; /* 0x004E33C9: and eax, 0xffff */
    eax = eax & 0xFFu; /* 0x004E33CE: and eax, 0xff */
    MEM16(ebp + (-0xC)) = (uint16_t)(LO16(eax)); /* 0x004E33D3: mov word ptr [ebp - 0xc], ax */
    ecx = MEM32(ebp + (-0x24)); /* 0x004E33D7: mov ecx, dword ptr [ebp - 0x24] */
    ecx = ecx >> 0x18u; /* 0x004E33DA: shr ecx, 0x18 */
    MEM16(ebp + (-0x40)) = (uint16_t)(LO16(ecx)); /* 0x004E33DD: mov word ptr [ebp - 0x40], cx */
    edx = MEM32(ebp + (-0x64)); /* 0x004E33E1: mov edx, dword ptr [ebp - 0x64] */
    edx = edx & 0xFFFFu; /* 0x004E33E4: and edx, 0xffff */
    eax = MEM32(ebp + (-0x70)); /* 0x004E33EA: mov eax, dword ptr [ebp - 0x70] */
    eax = eax & 0xFFFFu; /* 0x004E33ED: and eax, 0xffff */
    edx = (uint32_t)((int32_t)edx * (int32_t)eax); /* 0x004E33F2: imul edx, eax */
    ecx = MEM32(ebp + (-0x3C)); /* 0x004E33F5: mov ecx, dword ptr [ebp - 0x3c] */
    ecx = ecx & 0xFFFFu; /* 0x004E33F8: and ecx, 0xffff */
    eax = MEM32(ebp + (-0x6C)); /* 0x004E33FE: mov eax, dword ptr [ebp - 0x6c] */
    eax = eax & 0xFFFFu; /* 0x004E3401: and eax, 0xffff */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)eax); /* 0x004E3406: imul ecx, eax */
    edx = edx + ecx; /* 0x004E3409: add edx, ecx */
    ecx = MEM32(ebp + (-0x60)); /* 0x004E340B: mov ecx, dword ptr [ebp - 0x60] */
    ecx = ecx & 0xFFFFu; /* 0x004E340E: and ecx, 0xffff */
    eax = MEM32(ebp + (-0x40)); /* 0x004E3414: mov eax, dword ptr [ebp - 0x40] */
    eax = eax & 0xFFFFu; /* 0x004E3417: and eax, 0xffff */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)eax); /* 0x004E341C: imul ecx, eax */
    edx = edx + ecx; /* 0x004E341F: add edx, ecx */
    edx = edx - MEM32(ebp + (-0x20)); /* 0x004E3421: sub edx, dword ptr [ebp - 0x20] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004E3424: mov dword ptr [ebp - 8], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3427: mov ecx, dword ptr [ebp - 8] */
    ecx = (uint32_t)((int32_t)ecx >> 0x10u); /* 0x004E342A: sar ecx, 0x10 */
    MEM16(ebp + (-0x5C)) = (uint16_t)(LO16(ecx)); /* 0x004E342D: mov word ptr [ebp - 0x5c], cx */
    SET_LO16(edx, MEM16(ebp + (-0x70))); /* 0x004E3431: mov dx, word ptr [ebp - 0x70] */
    MEM16(ebp + (-0x2E)) = (uint16_t)(LO16(edx)); /* 0x004E3435: mov word ptr [ebp - 0x2e], dx */
    eax = MEM32(ebp + (-0x24)); /* 0x004E3439: mov eax, dword ptr [ebp - 0x24] */
    MEM32(ebp + (-0x32)) = eax; /* 0x004E343C: mov dword ptr [ebp - 0x32], eax */
    ecx = MEM32(ebp + (-0x48)); /* 0x004E343F: mov ecx, dword ptr [ebp - 0x48] */
    MEM32(ebp + (-0x36)) = ecx; /* 0x004E3442: mov dword ptr [ebp - 0x36], ecx */
    MEM16(ebp + (-0x38)) = (uint16_t)(0); /* 0x004E3445: mov word ptr [ebp - 0x38], 0 */
    PUSH32(esp, 1); /* 0x004E344B: push 1 */
    edx = (int32_t)(int16_t)MEM16(ebp + (-0x5C)); /* 0x004E344D: movsx edx, word ptr [ebp - 0x5c] */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004E3451: neg edx */
    PUSH32(esp, edx); /* 0x004E3453: push edx */
    eax = ebp + (-0x38); /* 0x004E3454: lea eax, [ebp - 0x38] */
    PUSH32(esp, eax); /* 0x004E3457: push eax */
    RECOMP_CALL(sub_004E4850); /* 0x004E3458: call 0x4e4850 */
    esp = esp + 0xCu; /* 0x004E345D: add esp, 0xc */
    ecx = MEM32(ebp + (-0x2E)); /* 0x004E3460: mov ecx, dword ptr [ebp - 0x2e] */
    ecx = ecx & 0xFFFFu; /* 0x004E3463: and ecx, 0xffff */
    /* cmp ecx, 0x3FFFu */ /* 0x004E3469: cmp ecx, 0x3fff */
    if (CMP_L(ecx, 0x3FFFu)) goto L_004E348D; /* 0x004E346F: jl 0x4e348d */

L_004E3471:
    SET_LO16(edx, MEM16(ebp + (-0x5C))); /* 0x004E3471: mov dx, word ptr [ebp - 0x5c] */
    SET_LO16(edx, LO16(edx) + 1); /* 0x004E3475: add dx, 1 */
    MEM16(ebp + (-0x5C)) = (uint16_t)(LO16(edx)); /* 0x004E3479: mov word ptr [ebp - 0x5c], dx */
    eax = ebp + (-0x54); /* 0x004E347D: lea eax, [ebp - 0x54] */
    PUSH32(esp, eax); /* 0x004E3480: push eax */
    ecx = ebp + (-0x38); /* 0x004E3481: lea ecx, [ebp - 0x38] */
    PUSH32(esp, ecx); /* 0x004E3484: push ecx */
    RECOMP_CALL(sub_004E4400); /* 0x004E3485: call 0x4e4400 */
    esp = esp + 8; /* 0x004E348A: add esp, 8 */

L_004E348D:
    edx = MEM32(ebp + 0x1C); /* 0x004E348D: mov edx, dword ptr [ebp + 0x1c] */
    SET_LO16(eax, MEM16(ebp + (-0x5C))); /* 0x004E3490: mov ax, word ptr [ebp - 0x5c] */
    MEM16(edx) = (uint16_t)(LO16(eax)); /* 0x004E3494: mov word ptr [edx], ax */
    ecx = MEM32(ebp + 0x18); /* 0x004E3497: mov ecx, dword ptr [ebp + 0x18] */
    ecx = ecx & 1; /* 0x004E349A: and ecx, 1 */
    /* test ecx, ecx */ /* 0x004E349D: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004E34E1; /* 0x004E349F: je 0x4e34e1 */

L_004E34A1:
    edx = (int32_t)(int16_t)MEM16(ebp + (-0x5C)); /* 0x004E34A1: movsx edx, word ptr [ebp - 0x5c] */
    eax = MEM32(ebp + 0x14); /* 0x004E34A5: mov eax, dword ptr [ebp + 0x14] */
    eax = eax + edx; /* 0x004E34A8: add eax, edx */
    MEM32(ebp + 0x14) = eax; /* 0x004E34AA: mov dword ptr [ebp + 0x14], eax */
    /* cmp MEM32(ebp + 0x14), 0 */ /* 0x004E34AD: cmp dword ptr [ebp + 0x14], 0 */
    if (CMP_G(MEM32(ebp + 0x14), 0)) goto L_004E34E1; /* 0x004E34B1: jg 0x4e34e1 */

L_004E34B3:
    ecx = MEM32(ebp + 0x1C); /* 0x004E34B3: mov ecx, dword ptr [ebp + 0x1c] */
    MEM16(ecx) = (uint16_t)(0); /* 0x004E34B6: mov word ptr [ecx], 0 */
    edx = MEM32(ebp + 0x1C); /* 0x004E34BB: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + 0x2) = (uint8_t)(0x20u); /* 0x004E34BE: mov byte ptr [edx + 2], 0x20 */
    eax = MEM32(ebp + 0x1C); /* 0x004E34C2: mov eax, dword ptr [ebp + 0x1c] */
    MEM8(eax + 0x3) = (uint8_t)(1); /* 0x004E34C5: mov byte ptr [eax + 3], 1 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E34C9: mov ecx, dword ptr [ebp + 0x1c] */
    MEM8(ecx + 0x4) = (uint8_t)(0x30u); /* 0x004E34CC: mov byte ptr [ecx + 4], 0x30 */
    edx = MEM32(ebp + 0x1C); /* 0x004E34D0: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + 0x5) = (uint8_t)(0); /* 0x004E34D3: mov byte ptr [edx + 5], 0 */
    eax = 1; /* 0x004E34D7: mov eax, 1 */
    goto L_004E36E2; /* 0x004E34DC: jmp 0x4e36e2 */

L_004E34E1:
    /* cmp MEM32(ebp + 0x14), 0x15u */ /* 0x004E34E1: cmp dword ptr [ebp + 0x14], 0x15 */
    if (CMP_LE(MEM32(ebp + 0x14), 0x15u)) goto L_004E34EE; /* 0x004E34E5: jle 0x4e34ee */

L_004E34E7:
    MEM32(ebp + 0x14) = 0x15u; /* 0x004E34E7: mov dword ptr [ebp + 0x14], 0x15 */

L_004E34EE:
    eax = MEM32(ebp + (-0x2E)); /* 0x004E34EE: mov eax, dword ptr [ebp - 0x2e] */
    eax = eax & 0xFFFFu; /* 0x004E34F1: and eax, 0xffff */
    eax = eax - 0x3FFEu; /* 0x004E34F6: sub eax, 0x3ffe */
    MEM32(ebp + (-0x2C)) = eax; /* 0x004E34FB: mov dword ptr [ebp - 0x2c], eax */
    MEM16(ebp + (-0x2E)) = (uint16_t)(0); /* 0x004E34FE: mov word ptr [ebp - 0x2e], 0 */
    MEM32(ebp + (-0x44)) = 0; /* 0x004E3504: mov dword ptr [ebp - 0x44], 0 */
    goto L_004E3516; /* 0x004E350B: jmp 0x4e3516 */

L_004E350D:
    ecx = MEM32(ebp + (-0x44)); /* 0x004E350D: mov ecx, dword ptr [ebp - 0x44] */
    ecx = ecx + 1; /* 0x004E3510: add ecx, 1 */
    MEM32(ebp + (-0x44)) = ecx; /* 0x004E3513: mov dword ptr [ebp - 0x44], ecx */

L_004E3516:
    /* cmp MEM32(ebp + (-0x44)), 8 */ /* 0x004E3516: cmp dword ptr [ebp - 0x44], 8 */
    if (CMP_GE(MEM32(ebp + (-0x44)), 8)) goto L_004E352A; /* 0x004E351A: jge 0x4e352a */

L_004E351C:
    edx = ebp + (-0x38); /* 0x004E351C: lea edx, [ebp - 0x38] */
    PUSH32(esp, edx); /* 0x004E351F: push edx */
    RECOMP_CALL(sub_004E2430); /* 0x004E3520: call 0x4e2430 */
    esp = esp + 4; /* 0x004E3525: add esp, 4 */
    goto L_004E350D; /* 0x004E3528: jmp 0x4e350d */

L_004E352A:
    /* cmp MEM32(ebp + (-0x2C)), 0 */ /* 0x004E352A: cmp dword ptr [ebp - 0x2c], 0 */
    if (CMP_GE(MEM32(ebp + (-0x2C)), 0)) goto L_004E355C; /* 0x004E352E: jge 0x4e355c */

L_004E3530:
    eax = MEM32(ebp + (-0x2C)); /* 0x004E3530: mov eax, dword ptr [ebp - 0x2c] */
    eax = (uint32_t)(-(int32_t)eax); /* 0x004E3533: neg eax */
    eax = eax & 0xFFu; /* 0x004E3535: and eax, 0xff */
    MEM32(ebp + (-0x74)) = eax; /* 0x004E353A: mov dword ptr [ebp - 0x74], eax */
    goto L_004E3548; /* 0x004E353D: jmp 0x4e3548 */

L_004E353F:
    ecx = MEM32(ebp + (-0x74)); /* 0x004E353F: mov ecx, dword ptr [ebp - 0x74] */
    ecx = ecx - 1; /* 0x004E3542: sub ecx, 1 */
    MEM32(ebp + (-0x74)) = ecx; /* 0x004E3545: mov dword ptr [ebp - 0x74], ecx */

L_004E3548:
    /* cmp MEM32(ebp + (-0x74)), 0 */ /* 0x004E3548: cmp dword ptr [ebp - 0x74], 0 */
    if (CMP_LE(MEM32(ebp + (-0x74)), 0)) goto L_004E355C; /* 0x004E354C: jle 0x4e355c */

L_004E354E:
    edx = ebp + (-0x38); /* 0x004E354E: lea edx, [ebp - 0x38] */
    PUSH32(esp, edx); /* 0x004E3551: push edx */
    RECOMP_CALL(sub_004E2490); /* 0x004E3552: call 0x4e2490 */
    esp = esp + 4; /* 0x004E3557: add esp, 4 */
    goto L_004E353F; /* 0x004E355A: jmp 0x4e353f */

L_004E355C:
    eax = MEM32(ebp + 0x1C); /* 0x004E355C: mov eax, dword ptr [ebp + 0x1c] */
    eax = eax + 4; /* 0x004E355F: add eax, 4 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E3562: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + 0x14); /* 0x004E3565: mov ecx, dword ptr [ebp + 0x14] */
    ecx = ecx + 1; /* 0x004E3568: add ecx, 1 */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004E356B: mov dword ptr [ebp - 0x10], ecx */
    goto L_004E3579; /* 0x004E356E: jmp 0x4e3579 */

L_004E3570:
    edx = MEM32(ebp + (-0x10)); /* 0x004E3570: mov edx, dword ptr [ebp - 0x10] */
    edx = edx - 1; /* 0x004E3573: sub edx, 1 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004E3576: mov dword ptr [ebp - 0x10], edx */

L_004E3579:
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E3579: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_LE(MEM32(ebp + (-0x10)), 0)) goto L_004E35E5; /* 0x004E357D: jle 0x4e35e5 */

L_004E357F:
    eax = MEM32(ebp + (-0x38)); /* 0x004E357F: mov eax, dword ptr [ebp - 0x38] */
    MEM32(ebp + (-0x1C)) = eax; /* 0x004E3582: mov dword ptr [ebp - 0x1c], eax */
    ecx = MEM32(ebp + (-0x34)); /* 0x004E3585: mov ecx, dword ptr [ebp - 0x34] */
    MEM32(ebp + (-0x18)) = ecx; /* 0x004E3588: mov dword ptr [ebp - 0x18], ecx */
    edx = MEM32(ebp + (-0x30)); /* 0x004E358B: mov edx, dword ptr [ebp - 0x30] */
    MEM32(ebp + (-0x14)) = edx; /* 0x004E358E: mov dword ptr [ebp - 0x14], edx */
    eax = ebp + (-0x38); /* 0x004E3591: lea eax, [ebp - 0x38] */
    PUSH32(esp, eax); /* 0x004E3594: push eax */
    RECOMP_CALL(sub_004E2430); /* 0x004E3595: call 0x4e2430 */
    esp = esp + 4; /* 0x004E359A: add esp, 4 */
    ecx = ebp + (-0x38); /* 0x004E359D: lea ecx, [ebp - 0x38] */
    PUSH32(esp, ecx); /* 0x004E35A0: push ecx */
    RECOMP_CALL(sub_004E2430); /* 0x004E35A1: call 0x4e2430 */
    esp = esp + 4; /* 0x004E35A6: add esp, 4 */
    edx = ebp + (-0x1C); /* 0x004E35A9: lea edx, [ebp - 0x1c] */
    PUSH32(esp, edx); /* 0x004E35AC: push edx */
    eax = ebp + (-0x38); /* 0x004E35AD: lea eax, [ebp - 0x38] */
    PUSH32(esp, eax); /* 0x004E35B0: push eax */
    RECOMP_CALL(sub_004E2380); /* 0x004E35B1: call 0x4e2380 */
    esp = esp + 8; /* 0x004E35B6: add esp, 8 */
    ecx = ebp + (-0x38); /* 0x004E35B9: lea ecx, [ebp - 0x38] */
    PUSH32(esp, ecx); /* 0x004E35BC: push ecx */
    RECOMP_CALL(sub_004E2430); /* 0x004E35BD: call 0x4e2430 */
    esp = esp + 4; /* 0x004E35C2: add esp, 4 */
    edx = MEM32(ebp + (-0x2D)); /* 0x004E35C5: mov edx, dword ptr [ebp - 0x2d] */
    edx = edx & 0xFFu; /* 0x004E35C8: and edx, 0xff */
    edx = edx + 0x30u; /* 0x004E35CE: add edx, 0x30 */
    eax = MEM32(ebp + (-0x4)); /* 0x004E35D1: mov eax, dword ptr [ebp - 4] */
    MEM8(eax) = (uint8_t)(LO8(edx)); /* 0x004E35D4: mov byte ptr [eax], dl */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E35D6: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004E35D9: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E35DC: mov dword ptr [ebp - 4], ecx */
    MEM8(ebp + (-0x2D)) = (uint8_t)(0); /* 0x004E35DF: mov byte ptr [ebp - 0x2d], 0 */
    goto L_004E3570; /* 0x004E35E3: jmp 0x4e3570 */

L_004E35E5:
    edx = MEM32(ebp + (-0x4)); /* 0x004E35E5: mov edx, dword ptr [ebp - 4] */
    edx = edx - 1; /* 0x004E35E8: sub edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E35EB: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E35EE: mov eax, dword ptr [ebp - 4] */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E35F1: mov cl, byte ptr [eax] */
    MEM8(ebp + (-0x28)) = (uint8_t)(LO8(ecx)); /* 0x004E35F3: mov byte ptr [ebp - 0x28], cl */
    edx = MEM32(ebp + (-0x4)); /* 0x004E35F6: mov edx, dword ptr [ebp - 4] */
    edx = edx - 1; /* 0x004E35F9: sub edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E35FC: mov dword ptr [ebp - 4], edx */
    eax = (int32_t)(int8_t)MEM8(ebp + (-0x28)); /* 0x004E35FF: movsx eax, byte ptr [ebp - 0x28] */
    /* cmp eax, 0x35u */ /* 0x004E3603: cmp eax, 0x35 */
    if (CMP_L(eax, 0x35u)) goto L_004E3663; /* 0x004E3606: jl 0x4e3663 */

L_004E3608:
    goto L_004E3613; /* 0x004E3608: jmp 0x4e3613 */

L_004E360A:
    ecx = MEM32(ebp + (-0x4)); /* 0x004E360A: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx - 1; /* 0x004E360D: sub ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3610: mov dword ptr [ebp - 4], ecx */

L_004E3613:
    edx = MEM32(ebp + 0x1C); /* 0x004E3613: mov edx, dword ptr [ebp + 0x1c] */
    edx = edx + 4; /* 0x004E3616: add edx, 4 */
    /* cmp MEM32(ebp + (-0x4)), edx */ /* 0x004E3619: cmp dword ptr [ebp - 4], edx */
    if (CMP_B(MEM32(ebp + (-0x4)), edx)) goto L_004E3631; /* 0x004E361C: jb 0x4e3631 */

L_004E361E:
    eax = MEM32(ebp + (-0x4)); /* 0x004E361E: mov eax, dword ptr [ebp - 4] */
    ecx = (int32_t)(int8_t)MEM8(eax); /* 0x004E3621: movsx ecx, byte ptr [eax] */
    /* cmp ecx, 0x39u */ /* 0x004E3624: cmp ecx, 0x39 */
    if (CMP_NE(ecx, 0x39u)) goto L_004E3631; /* 0x004E3627: jne 0x4e3631 */

L_004E3629:
    edx = MEM32(ebp + (-0x4)); /* 0x004E3629: mov edx, dword ptr [ebp - 4] */
    MEM8(edx) = (uint8_t)(0x30u); /* 0x004E362C: mov byte ptr [edx], 0x30 */
    goto L_004E360A; /* 0x004E362F: jmp 0x4e360a */

L_004E3631:
    eax = MEM32(ebp + 0x1C); /* 0x004E3631: mov eax, dword ptr [ebp + 0x1c] */
    eax = eax + 4; /* 0x004E3634: add eax, 4 */
    /* cmp MEM32(ebp + (-0x4)), eax */ /* 0x004E3637: cmp dword ptr [ebp - 4], eax */
    if (CMP_AE(MEM32(ebp + (-0x4)), eax)) goto L_004E3655; /* 0x004E363A: jae 0x4e3655 */

L_004E363C:
    ecx = MEM32(ebp + (-0x4)); /* 0x004E363C: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx + 1; /* 0x004E363F: add ecx, 1 */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3642: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + 0x1C); /* 0x004E3645: mov edx, dword ptr [ebp + 0x1c] */
    SET_LO16(eax, MEM16(edx)); /* 0x004E3648: mov ax, word ptr [edx] */
    SET_LO16(eax, LO16(eax) + 1); /* 0x004E364B: add ax, 1 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E364F: mov ecx, dword ptr [ebp + 0x1c] */
    MEM16(ecx) = (uint16_t)(LO16(eax)); /* 0x004E3652: mov word ptr [ecx], ax */

L_004E3655:
    edx = MEM32(ebp + (-0x4)); /* 0x004E3655: mov edx, dword ptr [ebp - 4] */
    SET_LO8(eax, MEM8(edx)); /* 0x004E3658: mov al, byte ptr [edx] */
    SET_LO8(eax, LO8(eax) + 1); /* 0x004E365A: add al, 1 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E365C: mov ecx, dword ptr [ebp - 4] */
    MEM8(ecx) = (uint8_t)(LO8(eax)); /* 0x004E365F: mov byte ptr [ecx], al */
    goto L_004E36BC; /* 0x004E3661: jmp 0x4e36bc */

L_004E3663:
    goto L_004E366E; /* 0x004E3663: jmp 0x4e366e */

L_004E3665:
    edx = MEM32(ebp + (-0x4)); /* 0x004E3665: mov edx, dword ptr [ebp - 4] */
    edx = edx - 1; /* 0x004E3668: sub edx, 1 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E366B: mov dword ptr [ebp - 4], edx */

L_004E366E:
    eax = MEM32(ebp + 0x1C); /* 0x004E366E: mov eax, dword ptr [ebp + 0x1c] */
    eax = eax + 4; /* 0x004E3671: add eax, 4 */
    /* cmp MEM32(ebp + (-0x4)), eax */ /* 0x004E3674: cmp dword ptr [ebp - 4], eax */
    if (CMP_B(MEM32(ebp + (-0x4)), eax)) goto L_004E3686; /* 0x004E3677: jb 0x4e3686 */

L_004E3679:
    ecx = MEM32(ebp + (-0x4)); /* 0x004E3679: mov ecx, dword ptr [ebp - 4] */
    edx = (int32_t)(int8_t)MEM8(ecx); /* 0x004E367C: movsx edx, byte ptr [ecx] */
    /* cmp edx, 0x30u */ /* 0x004E367F: cmp edx, 0x30 */
    if (CMP_NE(edx, 0x30u)) goto L_004E3686; /* 0x004E3682: jne 0x4e3686 */

L_004E3684:
    goto L_004E3665; /* 0x004E3684: jmp 0x4e3665 */

L_004E3686:
    eax = MEM32(ebp + 0x1C); /* 0x004E3686: mov eax, dword ptr [ebp + 0x1c] */
    eax = eax + 4; /* 0x004E3689: add eax, 4 */
    /* cmp MEM32(ebp + (-0x4)), eax */ /* 0x004E368C: cmp dword ptr [ebp - 4], eax */
    if (CMP_AE(MEM32(ebp + (-0x4)), eax)) goto L_004E36BC; /* 0x004E368F: jae 0x4e36bc */

L_004E3691:
    ecx = MEM32(ebp + 0x1C); /* 0x004E3691: mov ecx, dword ptr [ebp + 0x1c] */
    MEM16(ecx) = (uint16_t)(0); /* 0x004E3694: mov word ptr [ecx], 0 */
    edx = MEM32(ebp + 0x1C); /* 0x004E3699: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + 0x2) = (uint8_t)(0x20u); /* 0x004E369C: mov byte ptr [edx + 2], 0x20 */
    eax = MEM32(ebp + 0x1C); /* 0x004E36A0: mov eax, dword ptr [ebp + 0x1c] */
    MEM8(eax + 0x3) = (uint8_t)(1); /* 0x004E36A3: mov byte ptr [eax + 3], 1 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E36A7: mov ecx, dword ptr [ebp + 0x1c] */
    MEM8(ecx + 0x4) = (uint8_t)(0x30u); /* 0x004E36AA: mov byte ptr [ecx + 4], 0x30 */
    edx = MEM32(ebp + 0x1C); /* 0x004E36AE: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + 0x5) = (uint8_t)(0); /* 0x004E36B1: mov byte ptr [edx + 5], 0 */
    eax = 1; /* 0x004E36B5: mov eax, 1 */
    goto L_004E36E2; /* 0x004E36BA: jmp 0x4e36e2 */

L_004E36BC:
    eax = MEM32(ebp + 0x1C); /* 0x004E36BC: mov eax, dword ptr [ebp + 0x1c] */
    eax = eax + 4; /* 0x004E36BF: add eax, 4 */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E36C2: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx - eax; /* 0x004E36C5: sub ecx, eax */
    ecx = ecx + 1; /* 0x004E36C7: add ecx, 1 */
    edx = MEM32(ebp + 0x1C); /* 0x004E36CA: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + 0x3) = (uint8_t)(LO8(ecx)); /* 0x004E36CD: mov byte ptr [edx + 3], cl */
    eax = MEM32(ebp + 0x1C); /* 0x004E36D0: mov eax, dword ptr [ebp + 0x1c] */
    ecx = (int32_t)(int8_t)MEM8(eax + 0x3); /* 0x004E36D3: movsx ecx, byte ptr [eax + 3] */
    edx = MEM32(ebp + 0x1C); /* 0x004E36D7: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + ecx + 0x4) = (uint8_t)(0); /* 0x004E36DA: mov byte ptr [edx + ecx + 4], 0 */

L_004E36DF:
    eax = MEM32(ebp + (-0x58)); /* 0x004E36DF: mov eax, dword ptr [ebp - 0x58] */

L_004E36E2:
    esp = ebp; /* 0x004E36E2: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E36E4: pop ebp */
    return; /* 0x004E36E5: ret  */

}

void sub_004E34C0(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E34C0:
    SET_HI8(eax, HI8(eax) + MEM8(eax)); /* 0x004E34C0: add ah, byte ptr [eax] */
    eax = MEM32(ebp + 0x1C); /* 0x004E34C2: mov eax, dword ptr [ebp + 0x1c] */
    MEM8(eax + 0x3) = (uint8_t)(1); /* 0x004E34C5: mov byte ptr [eax + 3], 1 */
    ecx = MEM32(ebp + 0x1C); /* 0x004E34C9: mov ecx, dword ptr [ebp + 0x1c] */
    MEM8(ecx + 0x4) = (uint8_t)(0x30u); /* 0x004E34CC: mov byte ptr [ecx + 4], 0x30 */
    edx = MEM32(ebp + 0x1C); /* 0x004E34D0: mov edx, dword ptr [ebp + 0x1c] */
    MEM8(edx + 0x5) = (uint8_t)(0); /* 0x004E34D3: mov byte ptr [edx + 5], 0 */
    eax = 1; /* 0x004E34D7: mov eax, 1 */
    goto L_004E36E2; /* 0x004E34DC: jmp 0x4e36e2 */

L_004E36E2:
    esp = ebp; /* 0x004E36E2: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E36E4: pop ebp */
    return; /* 0x004E36E5: ret  */

}

void sub_004E3730(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E36F6:
    /* cmp MEM32(0x509634), 1 */ /* 0x004E36F6: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004E3716; /* 0x004E36FD: jle 0x4e3716 */

L_004E36FF:
    PUSH32(esp, 8); /* 0x004E36FF: push 8 */
    eax = MEM32(ebp + 0x8); /* 0x004E3701: mov eax, dword ptr [ebp + 8] */
    ecx = 0; /* 0x004E3704: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E3706: mov cl, byte ptr [eax] */
    PUSH32(esp, ecx); /* 0x004E3708: push ecx */
    RECOMP_CALL(sub_004DA490); /* 0x004E3709: call 0x4da490 */
    esp = esp + 8; /* 0x004E370E: add esp, 8 */
    MEM32(ebp + (-0x10)) = eax; /* 0x004E3711: mov dword ptr [ebp - 0x10], eax */
    goto L_004E372F; /* 0x004E3714: jmp 0x4e372f */

L_004E3716:
    edx = MEM32(ebp + 0x8); /* 0x004E3716: mov edx, dword ptr [ebp + 8] */
    eax = 0; /* 0x004E3719: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E371B: mov al, byte ptr [edx] */
    ecx = MEM32(0x509428); /* 0x004E371D: mov ecx, dword ptr [0x509428] */
    edx = 0; /* 0x004E3723: xor edx, edx */
    SET_LO16(edx, MEM16(ecx + eax * 2)); /* 0x004E3725: mov dx, word ptr [ecx + eax*2] */
    edx = edx & 8; /* 0x004E3729: and edx, 8 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004E372C: mov dword ptr [ebp - 0x10], edx */

L_004E3722:
    MEM8(ebx) = (uint8_t)(MEM8(ebx) + HI8(edx)); /* 0x004E3722: add byte ptr [ebx], dh */
    MEM8(esi + (-0x75)) = (uint8_t)(MEM8(esi + (-0x75)) << LO8(ecx)); /* 0x004E3724: shl byte ptr [esi - 0x75], cl */
    SET_LO8(eax, LO8(eax) + 0x41u + _cf); /* 0x004E3727: adc al, 0x41 */
    edx = edx & 8; /* 0x004E3729: and edx, 8 */
    MEM32(ebp + (-0x10)) = edx; /* 0x004E372C: mov dword ptr [ebp - 0x10], edx */

L_004E372F:
    /* cmp MEM32(ebp + (-0x10)), 0 */ /* 0x004E372F: cmp dword ptr [ebp - 0x10], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x10)), 0)) goto L_004E3740; /* 0x004E3733: je 0x4e3740 */

L_004E3730:
    if (/* no flag state for jge */ _cf) goto L_004E3722; /* 0x004E3730: jge 0x4e3722 */

L_004E3732:
    MEM8(ebx + ecx + (-0x75)) = (uint8_t)(MEM8(ebx + ecx + (-0x75)) + HI8(edx)); /* 0x004E3732: add byte ptr [ebx + ecx - 0x75], dh */
    ebp = ebp + 1; /* 0x004E3736: inc ebp */
    MEM8(ebx + 0x458901C0) = (uint8_t)(MEM8(ebx + 0x458901C0) | LO8(eax)); /* 0x004E3737: or byte ptr [ebx + 0x458901c0], al */
    SET_LO8(ebx, LO8(ebx) | HI8(ecx)); /* 0x004E373D: or bl, ch */
    SET_HI8(edx, 0x8Bu); /* 0x004E373F: mov dh, 0x8b */
    ebp = ebp - 1; /* 0x004E3741: dec ebp */
    MEM8(ebx) = (uint8_t)(MEM8(ebx) | HI8(edx)); /* 0x004E3742: or byte ptr [ebx], dh */
    MEM8(edx + (-0x3AA76EF)) = (uint8_t)(ROR32(MEM8(edx + (-0x3AA76EF)), LO8(ecx))); /* 0x004E3744: ror byte ptr [edx - 0x3aa76ef], cl */
    eax = MEM32(ebp + 0x8); /* 0x004E374A: mov eax, dword ptr [ebp + 8] */
    eax = eax + 1; /* 0x004E374D: add eax, 1 */
    MEM32(ebp + 0x8) = eax; /* 0x004E3750: mov dword ptr [ebp + 8], eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E3753: mov ecx, dword ptr [ebp - 4] */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004E3756: mov dword ptr [ebp - 0xc], ecx */
    /* cmp MEM32(ebp + (-0x4)), 0x2Du */ /* 0x004E3759: cmp dword ptr [ebp - 4], 0x2d */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0x2Du)) goto L_004E3765; /* 0x004E375D: je 0x4e3765 */

L_004E3735:
    eax = MEM32(ebp + 0x8); /* 0x004E3735: mov eax, dword ptr [ebp + 8] */
    eax = eax + 1; /* 0x004E3738: add eax, 1 */
    MEM32(ebp + 0x8) = eax; /* 0x004E373B: mov dword ptr [ebp + 8], eax */
    goto L_004E36F6; /* 0x004E373E: jmp 0x4e36f6 */

L_004E3740:
    ecx = MEM32(ebp + 0x8); /* 0x004E3740: mov ecx, dword ptr [ebp + 8] */
    edx = 0; /* 0x004E3743: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004E3745: mov dl, byte ptr [ecx] */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3747: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + 0x8); /* 0x004E374A: mov eax, dword ptr [ebp + 8] */
    eax = eax + 1; /* 0x004E374D: add eax, 1 */
    MEM32(ebp + 0x8) = eax; /* 0x004E3750: mov dword ptr [ebp + 8], eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E3753: mov ecx, dword ptr [ebp - 4] */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004E3756: mov dword ptr [ebp - 0xc], ecx */
    /* cmp MEM32(ebp + (-0x4)), 0x2Du */ /* 0x004E3759: cmp dword ptr [ebp - 4], 0x2d */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0x2Du)) goto L_004E3765; /* 0x004E375D: je 0x4e3765 */

L_004E375F:
    /* cmp MEM32(ebp + (-0x4)), 0x2Bu */ /* 0x004E375F: cmp dword ptr [ebp - 4], 0x2b */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0x2Bu)) goto L_004E3778; /* 0x004E3763: jne 0x4e3778 */

L_004E3765:
    edx = MEM32(ebp + 0x8); /* 0x004E3765: mov edx, dword ptr [ebp + 8] */
    eax = 0; /* 0x004E3768: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E376A: mov al, byte ptr [edx] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E376C: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E376F: mov ecx, dword ptr [ebp + 8] */
    ecx = ecx + 1; /* 0x004E3772: add ecx, 1 */
    MEM32(ebp + 0x8) = ecx; /* 0x004E3775: mov dword ptr [ebp + 8], ecx */

L_004E3778:
    MEM32(ebp + (-0x8)) = 0; /* 0x004E3778: mov dword ptr [ebp - 8], 0 */

L_004E377F:
    /* cmp MEM32(0x509634), 1 */ /* 0x004E377F: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004E379B; /* 0x004E3786: jle 0x4e379b */

L_004E3788:
    PUSH32(esp, 4); /* 0x004E3788: push 4 */
    edx = MEM32(ebp + (-0x4)); /* 0x004E378A: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E378D: push edx */
    RECOMP_CALL(sub_004DA490); /* 0x004E378E: call 0x4da490 */
    esp = esp + 8; /* 0x004E3793: add esp, 8 */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E3796: mov dword ptr [ebp - 0x14], eax */
    goto L_004E37B0; /* 0x004E3799: jmp 0x4e37b0 */

L_004E379B:
    eax = MEM32(ebp + (-0x4)); /* 0x004E379B: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(0x509428); /* 0x004E379E: mov ecx, dword ptr [0x509428] */
    edx = 0; /* 0x004E37A4: xor edx, edx */
    SET_LO16(edx, MEM16(ecx + eax * 2)); /* 0x004E37A6: mov dx, word ptr [ecx + eax*2] */
    edx = edx & 4; /* 0x004E37AA: and edx, 4 */
    MEM32(ebp + (-0x14)) = edx; /* 0x004E37AD: mov dword ptr [ebp - 0x14], edx */

L_004E37B0:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004E37B0: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x14)), 0)) goto L_004E37DB; /* 0x004E37B4: je 0x4e37db */

L_004E37B6:
    eax = MEM32(ebp + (-0x8)); /* 0x004E37B6: mov eax, dword ptr [ebp - 8] */
    eax = (uint32_t)((int32_t)eax * (int32_t)0xAu); /* 0x004E37B9: imul eax, eax, 0xa */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E37BC: mov ecx, dword ptr [ebp - 4] */
    edx = eax + ecx + (-0x30); /* 0x004E37BF: lea edx, [eax + ecx - 0x30] */
    MEM32(ebp + (-0x8)) = edx; /* 0x004E37C3: mov dword ptr [ebp - 8], edx */
    eax = MEM32(ebp + 0x8); /* 0x004E37C6: mov eax, dword ptr [ebp + 8] */
    ecx = 0; /* 0x004E37C9: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E37CB: mov cl, byte ptr [eax] */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E37CD: mov dword ptr [ebp - 4], ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E37D0: mov edx, dword ptr [ebp + 8] */
    edx = edx + 1; /* 0x004E37D3: add edx, 1 */
    MEM32(ebp + 0x8) = edx; /* 0x004E37D6: mov dword ptr [ebp + 8], edx */
    goto L_004E377F; /* 0x004E37D9: jmp 0x4e377f */

L_004E37DB:
    /* cmp MEM32(ebp + (-0xC)), 0x2Du */ /* 0x004E37DB: cmp dword ptr [ebp - 0xc], 0x2d */
    if (CMP_NE(MEM32(ebp + (-0xC)), 0x2Du)) goto L_004E37E8; /* 0x004E37DF: jne 0x4e37e8 */

L_004E37E1:
    eax = MEM32(ebp + (-0x8)); /* 0x004E37E1: mov eax, dword ptr [ebp - 8] */
    eax = (uint32_t)(-(int32_t)eax); /* 0x004E37E4: neg eax */
    goto L_004E37EB; /* 0x004E37E6: jmp 0x4e37eb */

L_004E37E8:
    eax = MEM32(ebp + (-0x8)); /* 0x004E37E8: mov eax, dword ptr [ebp - 8] */

L_004E37EB:
    esp = ebp; /* 0x004E37EB: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E37ED: pop ebp */
    return; /* 0x004E37EE: ret  */

}

void sub_004E3800(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3800:
    return; /* 0x004E3800: ret  */

}

void sub_004E3820(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3817:
    /* cmp MEM32(0x509634), 1 */ /* 0x004E3817: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004E3837; /* 0x004E381E: jle 0x4e3837 */

L_004E3820:
    PUSH32(esp, 8); /* 0x004E3820: push 8 */
    eax = MEM32(ebp + 0x8); /* 0x004E3822: mov eax, dword ptr [ebp + 8] */
    ecx = 0; /* 0x004E3825: xor ecx, ecx */
    SET_LO8(ecx, MEM8(eax)); /* 0x004E3827: mov cl, byte ptr [eax] */
    PUSH32(esp, ecx); /* 0x004E3829: push ecx */
    RECOMP_CALL(sub_004DA490); /* 0x004E382A: call 0x4da490 */
    esp = esp + 8; /* 0x004E382F: add esp, 8 */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E3832: mov dword ptr [ebp - 0x14], eax */
    goto L_004E3850; /* 0x004E3835: jmp 0x4e3850 */

L_004E3837:
    edx = MEM32(ebp + 0x8); /* 0x004E3837: mov edx, dword ptr [ebp + 8] */
    eax = 0; /* 0x004E383A: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E383C: mov al, byte ptr [edx] */
    ecx = MEM32(0x509428); /* 0x004E383E: mov ecx, dword ptr [0x509428] */
    edx = 0; /* 0x004E3844: xor edx, edx */
    SET_LO16(edx, MEM16(ecx + eax * 2)); /* 0x004E3846: mov dx, word ptr [ecx + eax*2] */
    edx = edx & 8; /* 0x004E384A: and edx, 8 */
    MEM32(ebp + (-0x14)) = edx; /* 0x004E384D: mov dword ptr [ebp - 0x14], edx */

L_004E3850:
    /* cmp MEM32(ebp + (-0x14)), 0 */ /* 0x004E3850: cmp dword ptr [ebp - 0x14], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x14)), 0)) goto L_004E3861; /* 0x004E3854: je 0x4e3861 */

L_004E3856:
    eax = MEM32(ebp + 0x8); /* 0x004E3856: mov eax, dword ptr [ebp + 8] */
    eax = eax + 1; /* 0x004E3859: add eax, 1 */
    MEM32(ebp + 0x8) = eax; /* 0x004E385C: mov dword ptr [ebp + 8], eax */
    goto L_004E3817; /* 0x004E385F: jmp 0x4e3817 */

L_004E3861:
    ecx = MEM32(ebp + 0x8); /* 0x004E3861: mov ecx, dword ptr [ebp + 8] */
    edx = 0; /* 0x004E3864: xor edx, edx */
    SET_LO8(edx, MEM8(ecx)); /* 0x004E3866: mov dl, byte ptr [ecx] */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3868: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + 0x8); /* 0x004E386B: mov eax, dword ptr [ebp + 8] */
    eax = eax + 1; /* 0x004E386E: add eax, 1 */
    MEM32(ebp + 0x8) = eax; /* 0x004E3871: mov dword ptr [ebp + 8], eax */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E3874: mov ecx, dword ptr [ebp - 4] */
    MEM32(ebp + (-0x10)) = ecx; /* 0x004E3877: mov dword ptr [ebp - 0x10], ecx */
    /* cmp MEM32(ebp + (-0x4)), 0x2Du */ /* 0x004E387A: cmp dword ptr [ebp - 4], 0x2d */
    if (CMP_EQ(MEM32(ebp + (-0x4)), 0x2Du)) goto L_004E3886; /* 0x004E387E: je 0x4e3886 */

L_004E3880:
    /* cmp MEM32(ebp + (-0x4)), 0x2Bu */ /* 0x004E3880: cmp dword ptr [ebp - 4], 0x2b */
    if (CMP_NE(MEM32(ebp + (-0x4)), 0x2Bu)) goto L_004E3899; /* 0x004E3884: jne 0x4e3899 */

L_004E3886:
    edx = MEM32(ebp + 0x8); /* 0x004E3886: mov edx, dword ptr [ebp + 8] */
    eax = 0; /* 0x004E3889: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E388B: mov al, byte ptr [edx] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E388D: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E3890: mov ecx, dword ptr [ebp + 8] */
    ecx = ecx + 1; /* 0x004E3893: add ecx, 1 */
    MEM32(ebp + 0x8) = ecx; /* 0x004E3896: mov dword ptr [ebp + 8], ecx */

L_004E3899:
    MEM32(ebp + (-0xC)) = 0; /* 0x004E3899: mov dword ptr [ebp - 0xc], 0 */
    MEM32(ebp + (-0x8)) = 0; /* 0x004E38A0: mov dword ptr [ebp - 8], 0 */

L_004E38A7:
    /* cmp MEM32(0x509634), 1 */ /* 0x004E38A7: cmp dword ptr [0x509634], 1 */
    if (CMP_LE(MEM32(0x509634), 1)) goto L_004E38C3; /* 0x004E38AE: jle 0x4e38c3 */

L_004E38B0:
    PUSH32(esp, 4); /* 0x004E38B0: push 4 */
    edx = MEM32(ebp + (-0x4)); /* 0x004E38B2: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E38B5: push edx */
    RECOMP_CALL(sub_004DA490); /* 0x004E38B6: call 0x4da490 */
    esp = esp + 8; /* 0x004E38BB: add esp, 8 */
    MEM32(ebp + (-0x18)) = eax; /* 0x004E38BE: mov dword ptr [ebp - 0x18], eax */
    goto L_004E38D8; /* 0x004E38C1: jmp 0x4e38d8 */

L_004E38C3:
    eax = MEM32(ebp + (-0x4)); /* 0x004E38C3: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(0x509428); /* 0x004E38C6: mov ecx, dword ptr [0x509428] */
    edx = 0; /* 0x004E38CC: xor edx, edx */
    SET_LO16(edx, MEM16(ecx + eax * 2)); /* 0x004E38CE: mov dx, word ptr [ecx + eax*2] */
    edx = edx & 4; /* 0x004E38D2: and edx, 4 */
    MEM32(ebp + (-0x18)) = edx; /* 0x004E38D5: mov dword ptr [ebp - 0x18], edx */

L_004E38D8:
    /* cmp MEM32(ebp + (-0x18)), 0 */ /* 0x004E38D8: cmp dword ptr [ebp - 0x18], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x18)), 0)) goto L_004E3919; /* 0x004E38DC: je 0x4e3919 */

L_004E38DE:
    PUSH32(esp, 0); /* 0x004E38DE: push 0 */
    PUSH32(esp, 0xAu); /* 0x004E38E0: push 0xa */
    eax = MEM32(ebp + (-0x8)); /* 0x004E38E2: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E38E5: push eax */
    ecx = MEM32(ebp + (-0xC)); /* 0x004E38E6: mov ecx, dword ptr [ebp - 0xc] */
    PUSH32(esp, ecx); /* 0x004E38E9: push ecx */
    RECOMP_CALL(sub_004E4920); /* 0x004E38EA: call 0x4e4920 */
    ecx = eax; /* 0x004E38EF: mov ecx, eax */
    esi = edx; /* 0x004E38F1: mov esi, edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E38F3: mov eax, dword ptr [ebp - 4] */
    eax = eax - 0x30u; /* 0x004E38F6: sub eax, 0x30 */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E38F9: cdq  */
    ecx = ecx + eax; /* 0x004E38FA: add ecx, eax */
    esi = esi + edx + _cf; /* 0x004E38FC: adc esi, edx */
    MEM32(ebp + (-0xC)) = ecx; /* 0x004E38FE: mov dword ptr [ebp - 0xc], ecx */
    MEM32(ebp + (-0x8)) = esi; /* 0x004E3901: mov dword ptr [ebp - 8], esi */
    edx = MEM32(ebp + 0x8); /* 0x004E3904: mov edx, dword ptr [ebp + 8] */
    eax = 0; /* 0x004E3907: xor eax, eax */
    SET_LO8(eax, MEM8(edx)); /* 0x004E3909: mov al, byte ptr [edx] */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E390B: mov dword ptr [ebp - 4], eax */
    ecx = MEM32(ebp + 0x8); /* 0x004E390E: mov ecx, dword ptr [ebp + 8] */
    ecx = ecx + 1; /* 0x004E3911: add ecx, 1 */
    MEM32(ebp + 0x8) = ecx; /* 0x004E3914: mov dword ptr [ebp + 8], ecx */
    goto L_004E38A7; /* 0x004E3917: jmp 0x4e38a7 */

L_004E3919:
    /* cmp MEM32(ebp + (-0x10)), 0x2Du */ /* 0x004E3919: cmp dword ptr [ebp - 0x10], 0x2d */
    if (CMP_NE(MEM32(ebp + (-0x10)), 0x2Du)) goto L_004E392E; /* 0x004E391D: jne 0x4e392e */

L_004E391F:
    eax = MEM32(ebp + (-0xC)); /* 0x004E391F: mov eax, dword ptr [ebp - 0xc] */
    eax = (uint32_t)(-(int32_t)eax); /* 0x004E3922: neg eax */
    edx = MEM32(ebp + (-0x8)); /* 0x004E3924: mov edx, dword ptr [ebp - 8] */
    edx = edx + 0 + _cf; /* 0x004E3927: adc edx, 0 */
    edx = (uint32_t)(-(int32_t)edx); /* 0x004E392A: neg edx */
    goto L_004E3934; /* 0x004E392C: jmp 0x4e3934 */

L_004E392E:
    eax = MEM32(ebp + (-0xC)); /* 0x004E392E: mov eax, dword ptr [ebp - 0xc] */
    edx = MEM32(ebp + (-0x8)); /* 0x004E3931: mov edx, dword ptr [ebp - 8] */

L_004E3934:
    esi = POP32_VAL(esp); /* 0x004E3934: pop esi */
    esp = ebp; /* 0x004E3935: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E3937: pop ebp */
    return; /* 0x004E3938: ret  */

}

void sub_004E3C50(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3C35:
    edx = MEM32(ebp + (-0x8)); /* 0x004E3C35: mov edx, dword ptr [ebp - 8] */
    edx = edx - 1; /* 0x004E3C38: sub edx, 1 */
    MEM32(ebp + (-0x8)) = edx; /* 0x004E3C3B: mov dword ptr [ebp - 8], edx */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E3C3E: cmp dword ptr [ebp - 8], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x8)), 0)) goto L_004E3C5B; /* 0x004E3C42: je 0x4e3c5b */

L_004E3C44:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3C44: mov eax, dword ptr [ebp - 4] */
    ecx = 0; /* 0x004E3C47: xor ecx, ecx */
    SET_LO16(ecx, MEM16(eax)); /* 0x004E3C49: mov cx, word ptr [eax] */
    /* test ecx, ecx */ /* 0x004E3C4C: test ecx, ecx */
    if (TEST_Z(ecx, ecx)) goto L_004E3C5B; /* 0x004E3C4E: je 0x4e3c5b */

L_004E3C50:
    edx = MEM32(ebp + (-0x4)); /* 0x004E3C50: mov edx, dword ptr [ebp - 4] */
    edx = edx + 2; /* 0x004E3C53: add edx, 2 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3C56: mov dword ptr [ebp - 4], edx */
    goto L_004E3C35; /* 0x004E3C59: jmp 0x4e3c35 */

L_004E3C5B:
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E3C5B: cmp dword ptr [ebp - 8], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x8)), 0)) goto L_004E3C7A; /* 0x004E3C5F: je 0x4e3c7a */

L_004E3C61:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3C61: mov eax, dword ptr [ebp - 4] */
    ecx = 0; /* 0x004E3C64: xor ecx, ecx */
    SET_LO16(ecx, MEM16(eax)); /* 0x004E3C66: mov cx, word ptr [eax] */
    /* test ecx, ecx */ /* 0x004E3C69: test ecx, ecx */
    if (TEST_NZ(ecx, ecx)) goto L_004E3C7A; /* 0x004E3C6B: jne 0x4e3c7a */

L_004E3C6D:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3C6D: mov eax, dword ptr [ebp - 4] */
    eax = eax - MEM32(ebp + 0x8); /* 0x004E3C70: sub eax, dword ptr [ebp + 8] */
    eax = (uint32_t)((int32_t)eax >> 1); /* 0x004E3C73: sar eax, 1 */
    eax = eax + 1; /* 0x004E3C75: add eax, 1 */
    goto L_004E3C7D; /* 0x004E3C78: jmp 0x4e3c7d */

L_004E3C7A:
    eax = MEM32(ebp + 0xC); /* 0x004E3C7A: mov eax, dword ptr [ebp + 0xc] */

L_004E3C7D:
    esp = ebp; /* 0x004E3C7D: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E3C7F: pop ebp */
    return; /* 0x004E3C80: ret  */

}

void sub_004E3D20(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3D20:
    /* cmp MEM32(ebp + (-0xC)), 0x01E28500u */ /* 0x004E3D20: cmp dword ptr [ebp - 0xc], 0x1e28500 */
    if (CMP_L(MEM32(ebp + (-0xC)), 0x01E28500u)) goto L_004E3D40; /* 0x004E3D27: jl 0x4e3d40 */

L_004E3D29:
    ecx = MEM32(ebp + (-0x14)); /* 0x004E3D29: mov ecx, dword ptr [ebp - 0x14] */
    ecx = ecx + 1; /* 0x004E3D2C: add ecx, 1 */
    MEM32(ebp + (-0x14)) = ecx; /* 0x004E3D2F: mov dword ptr [ebp - 0x14], ecx */
    edx = MEM32(ebp + (-0xC)); /* 0x004E3D32: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - 0x01E28500u; /* 0x004E3D35: sub edx, 0x1e28500 */
    MEM32(ebp + (-0xC)) = edx; /* 0x004E3D3B: mov dword ptr [ebp - 0xc], edx */
    goto L_004E3D49; /* 0x004E3D3E: jmp 0x4e3d49 */

L_004E3D40:
    eax = MEM32(ebp + (-0x8)); /* 0x004E3D40: mov eax, dword ptr [ebp - 8] */
    eax = eax + 1; /* 0x004E3D43: add eax, 1 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E3D46: mov dword ptr [ebp - 8], eax */

L_004E3D49:
    ecx = MEM32(ebp + (-0x4)); /* 0x004E3D49: mov ecx, dword ptr [ebp - 4] */
    edx = MEM32(ebp + (-0x14)); /* 0x004E3D4C: mov edx, dword ptr [ebp - 0x14] */
    MEM32(ecx + 0x14) = edx; /* 0x004E3D4F: mov dword ptr [ecx + 0x14], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E3D52: mov eax, dword ptr [ebp - 0xc] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3D55: cdq  */
    ecx = 0x00015180u; /* 0x004E3D56: mov ecx, 0x15180 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3D5B: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x4)); /* 0x004E3D5D: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0x1C) = eax; /* 0x004E3D60: mov dword ptr [edx + 0x1c], eax */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3D63: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(eax + 0x1C); /* 0x004E3D66: mov ecx, dword ptr [eax + 0x1c] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x00015180u); /* 0x004E3D69: imul ecx, ecx, 0x15180 */
    edx = MEM32(ebp + (-0xC)); /* 0x004E3D6F: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - ecx; /* 0x004E3D72: sub edx, ecx */
    MEM32(ebp + (-0xC)) = edx; /* 0x004E3D74: mov dword ptr [ebp - 0xc], edx */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E3D77: cmp dword ptr [ebp - 8], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x8)), 0)) goto L_004E3D86; /* 0x004E3D7B: je 0x4e3d86 */

L_004E3D7D:
    MEM32(ebp + (-0x10)) = 0x0050B978u; /* 0x004E3D7D: mov dword ptr [ebp - 0x10], 0x50b978 */
    goto L_004E3D8D; /* 0x004E3D84: jmp 0x4e3d8d */

L_004E3D86:
    MEM32(ebp + (-0x10)) = 0x0050B9B0u; /* 0x004E3D86: mov dword ptr [ebp - 0x10], 0x50b9b0 */

L_004E3D8D:
    MEM32(ebp + (-0x14)) = 1; /* 0x004E3D8D: mov dword ptr [ebp - 0x14], 1 */
    goto L_004E3D9F; /* 0x004E3D94: jmp 0x4e3d9f */

L_004E3D96:
    eax = MEM32(ebp + (-0x14)); /* 0x004E3D96: mov eax, dword ptr [ebp - 0x14] */
    eax = eax + 1; /* 0x004E3D99: add eax, 1 */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E3D9C: mov dword ptr [ebp - 0x14], eax */

L_004E3D9F:
    ecx = MEM32(ebp + (-0x14)); /* 0x004E3D9F: mov ecx, dword ptr [ebp - 0x14] */
    edx = MEM32(ebp + (-0x10)); /* 0x004E3DA2: mov edx, dword ptr [ebp - 0x10] */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3DA5: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(edx + ecx * 4); /* 0x004E3DA8: mov ecx, dword ptr [edx + ecx*4] */
    /* cmp ecx, MEM32(eax + 0x1C) */ /* 0x004E3DAB: cmp ecx, dword ptr [eax + 0x1c] */
    if (CMP_GE(ecx, MEM32(eax + 0x1C))) goto L_004E3DB2; /* 0x004E3DAE: jge 0x4e3db2 */

L_004E3DB0:
    goto L_004E3D96; /* 0x004E3DB0: jmp 0x4e3d96 */

L_004E3DB2:
    edx = MEM32(ebp + (-0x14)); /* 0x004E3DB2: mov edx, dword ptr [ebp - 0x14] */
    edx = edx - 1; /* 0x004E3DB5: sub edx, 1 */
    MEM32(ebp + (-0x14)) = edx; /* 0x004E3DB8: mov dword ptr [ebp - 0x14], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3DBB: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E3DBE: mov ecx, dword ptr [ebp - 0x14] */
    MEM32(eax + 0x10) = ecx; /* 0x004E3DC1: mov dword ptr [eax + 0x10], ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004E3DC4: mov edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x14)); /* 0x004E3DC7: mov eax, dword ptr [ebp - 0x14] */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E3DCA: mov ecx, dword ptr [ebp - 0x10] */
    edx = MEM32(edx + 0x1C); /* 0x004E3DCD: mov edx, dword ptr [edx + 0x1c] */
    edx = edx - MEM32(ecx + eax * 4); /* 0x004E3DD0: sub edx, dword ptr [ecx + eax*4] */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3DD3: mov eax, dword ptr [ebp - 4] */
    MEM32(eax + 0xC) = edx; /* 0x004E3DD6: mov dword ptr [eax + 0xc], edx */
    ecx = MEM32(ebp + 0x8); /* 0x004E3DD9: mov ecx, dword ptr [ebp + 8] */
    eax = MEM32(ecx); /* 0x004E3DDC: mov eax, dword ptr [ecx] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3DDE: cdq  */
    ecx = 0x00015180u; /* 0x004E3DDF: mov ecx, 0x15180 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3DE4: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = eax + 4; /* 0x004E3DE6: add eax, 4 */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3DE9: cdq  */
    ecx = 7; /* 0x004E3DEA: mov ecx, 7 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3DEF: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x4)); /* 0x004E3DF1: mov eax, dword ptr [ebp - 4] */
    MEM32(eax + 0x18) = edx; /* 0x004E3DF4: mov dword ptr [eax + 0x18], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E3DF7: mov eax, dword ptr [ebp - 0xc] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3DFA: cdq  */
    ecx = 0xE10u; /* 0x004E3DFB: mov ecx, 0xe10 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3E00: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x4)); /* 0x004E3E02: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0x8) = eax; /* 0x004E3E05: mov dword ptr [edx + 8], eax */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3E08: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(eax + 0x8); /* 0x004E3E0B: mov ecx, dword ptr [eax + 8] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0xE10u); /* 0x004E3E0E: imul ecx, ecx, 0xe10 */
    edx = MEM32(ebp + (-0xC)); /* 0x004E3E14: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - ecx; /* 0x004E3E17: sub edx, ecx */
    MEM32(ebp + (-0xC)) = edx; /* 0x004E3E19: mov dword ptr [ebp - 0xc], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E3E1C: mov eax, dword ptr [ebp - 0xc] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3E1F: cdq  */
    ecx = 0x3Cu; /* 0x004E3E20: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3E25: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x4)); /* 0x004E3E27: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0x4) = eax; /* 0x004E3E2A: mov dword ptr [edx + 4], eax */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3E2D: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(eax + 0x4); /* 0x004E3E30: mov ecx, dword ptr [eax + 4] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004E3E33: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + (-0xC)); /* 0x004E3E36: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - ecx; /* 0x004E3E39: sub edx, ecx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3E3B: mov eax, dword ptr [ebp - 4] */
    MEM32(eax) = edx; /* 0x004E3E3E: mov dword ptr [eax], edx */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E3E40: mov ecx, dword ptr [ebp - 4] */
    MEM32(ecx + 0x20) = 0; /* 0x004E3E43: mov dword ptr [ecx + 0x20], 0 */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3E4A: mov eax, dword ptr [ebp - 4] */
    esp = ebp; /* 0x004E3E4D: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E3E4F: pop ebp */
    return; /* 0x004E3E50: ret  */

}

void sub_004E3D60(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3D60:
    MEM32(edx + 0x1C) = eax; /* 0x004E3D60: mov dword ptr [edx + 0x1c], eax */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3D63: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(eax + 0x1C); /* 0x004E3D66: mov ecx, dword ptr [eax + 0x1c] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x00015180u); /* 0x004E3D69: imul ecx, ecx, 0x15180 */
    edx = MEM32(ebp + (-0xC)); /* 0x004E3D6F: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - ecx; /* 0x004E3D72: sub edx, ecx */
    MEM32(ebp + (-0xC)) = edx; /* 0x004E3D74: mov dword ptr [ebp - 0xc], edx */
    /* cmp MEM32(ebp + (-0x8)), 0 */ /* 0x004E3D77: cmp dword ptr [ebp - 8], 0 */
    if (CMP_EQ(MEM32(ebp + (-0x8)), 0)) goto L_004E3D86; /* 0x004E3D7B: je 0x4e3d86 */

L_004E3D7D:
    MEM32(ebp + (-0x10)) = 0x0050B978u; /* 0x004E3D7D: mov dword ptr [ebp - 0x10], 0x50b978 */
    goto L_004E3D8D; /* 0x004E3D84: jmp 0x4e3d8d */

L_004E3D86:
    MEM32(ebp + (-0x10)) = 0x0050B9B0u; /* 0x004E3D86: mov dword ptr [ebp - 0x10], 0x50b9b0 */

L_004E3D8D:
    MEM32(ebp + (-0x14)) = 1; /* 0x004E3D8D: mov dword ptr [ebp - 0x14], 1 */
    goto L_004E3D9F; /* 0x004E3D94: jmp 0x4e3d9f */

L_004E3D96:
    eax = MEM32(ebp + (-0x14)); /* 0x004E3D96: mov eax, dword ptr [ebp - 0x14] */
    eax = eax + 1; /* 0x004E3D99: add eax, 1 */
    MEM32(ebp + (-0x14)) = eax; /* 0x004E3D9C: mov dword ptr [ebp - 0x14], eax */

L_004E3D9F:
    ecx = MEM32(ebp + (-0x14)); /* 0x004E3D9F: mov ecx, dword ptr [ebp - 0x14] */
    edx = MEM32(ebp + (-0x10)); /* 0x004E3DA2: mov edx, dword ptr [ebp - 0x10] */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3DA5: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(edx + ecx * 4); /* 0x004E3DA8: mov ecx, dword ptr [edx + ecx*4] */
    /* cmp ecx, MEM32(eax + 0x1C) */ /* 0x004E3DAB: cmp ecx, dword ptr [eax + 0x1c] */
    if (CMP_GE(ecx, MEM32(eax + 0x1C))) goto L_004E3DB2; /* 0x004E3DAE: jge 0x4e3db2 */

L_004E3DB0:
    goto L_004E3D96; /* 0x004E3DB0: jmp 0x4e3d96 */

L_004E3DB2:
    edx = MEM32(ebp + (-0x14)); /* 0x004E3DB2: mov edx, dword ptr [ebp - 0x14] */
    edx = edx - 1; /* 0x004E3DB5: sub edx, 1 */
    MEM32(ebp + (-0x14)) = edx; /* 0x004E3DB8: mov dword ptr [ebp - 0x14], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3DBB: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(ebp + (-0x14)); /* 0x004E3DBE: mov ecx, dword ptr [ebp - 0x14] */
    MEM32(eax + 0x10) = ecx; /* 0x004E3DC1: mov dword ptr [eax + 0x10], ecx */
    edx = MEM32(ebp + (-0x4)); /* 0x004E3DC4: mov edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x14)); /* 0x004E3DC7: mov eax, dword ptr [ebp - 0x14] */
    ecx = MEM32(ebp + (-0x10)); /* 0x004E3DCA: mov ecx, dword ptr [ebp - 0x10] */
    edx = MEM32(edx + 0x1C); /* 0x004E3DCD: mov edx, dword ptr [edx + 0x1c] */
    edx = edx - MEM32(ecx + eax * 4); /* 0x004E3DD0: sub edx, dword ptr [ecx + eax*4] */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3DD3: mov eax, dword ptr [ebp - 4] */
    MEM32(eax + 0xC) = edx; /* 0x004E3DD6: mov dword ptr [eax + 0xc], edx */
    ecx = MEM32(ebp + 0x8); /* 0x004E3DD9: mov ecx, dword ptr [ebp + 8] */
    eax = MEM32(ecx); /* 0x004E3DDC: mov eax, dword ptr [ecx] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3DDE: cdq  */
    ecx = 0x00015180u; /* 0x004E3DDF: mov ecx, 0x15180 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3DE4: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = eax + 4; /* 0x004E3DE6: add eax, 4 */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3DE9: cdq  */
    ecx = 7; /* 0x004E3DEA: mov ecx, 7 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3DEF: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x4)); /* 0x004E3DF1: mov eax, dword ptr [ebp - 4] */
    MEM32(eax + 0x18) = edx; /* 0x004E3DF4: mov dword ptr [eax + 0x18], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E3DF7: mov eax, dword ptr [ebp - 0xc] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3DFA: cdq  */
    ecx = 0xE10u; /* 0x004E3DFB: mov ecx, 0xe10 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3E00: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x4)); /* 0x004E3E02: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0x8) = eax; /* 0x004E3E05: mov dword ptr [edx + 8], eax */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3E08: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(eax + 0x8); /* 0x004E3E0B: mov ecx, dword ptr [eax + 8] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0xE10u); /* 0x004E3E0E: imul ecx, ecx, 0xe10 */
    edx = MEM32(ebp + (-0xC)); /* 0x004E3E14: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - ecx; /* 0x004E3E17: sub edx, ecx */
    MEM32(ebp + (-0xC)) = edx; /* 0x004E3E19: mov dword ptr [ebp - 0xc], edx */
    eax = MEM32(ebp + (-0xC)); /* 0x004E3E1C: mov eax, dword ptr [ebp - 0xc] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3E1F: cdq  */
    ecx = 0x3Cu; /* 0x004E3E20: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3E25: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x4)); /* 0x004E3E27: mov edx, dword ptr [ebp - 4] */
    MEM32(edx + 0x4) = eax; /* 0x004E3E2A: mov dword ptr [edx + 4], eax */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3E2D: mov eax, dword ptr [ebp - 4] */
    ecx = MEM32(eax + 0x4); /* 0x004E3E30: mov ecx, dword ptr [eax + 4] */
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x3Cu); /* 0x004E3E33: imul ecx, ecx, 0x3c */
    edx = MEM32(ebp + (-0xC)); /* 0x004E3E36: mov edx, dword ptr [ebp - 0xc] */
    edx = edx - ecx; /* 0x004E3E39: sub edx, ecx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3E3B: mov eax, dword ptr [ebp - 4] */
    MEM32(eax) = edx; /* 0x004E3E3E: mov dword ptr [eax], edx */
    ecx = MEM32(ebp + (-0x4)); /* 0x004E3E40: mov ecx, dword ptr [ebp - 4] */
    MEM32(ecx + 0x20) = 0; /* 0x004E3E43: mov dword ptr [ecx + 0x20], 0 */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3E4A: mov eax, dword ptr [ebp - 4] */
    esp = ebp; /* 0x004E3E4D: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E3E4F: pop ebp */
    return; /* 0x004E3E50: ret  */

}

void sub_004E3E60(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3E60:
    PUSH32(esp, ebp); /* 0x004E3E60: push ebp */
    ebp = esp; /* 0x004E3E61: mov ebp, esp */
    esp = esp - 8; /* 0x004E3E63: sub esp, 8 */
    eax = MEM32(ebp + 0x8); /* 0x004E3E66: mov eax, dword ptr [ebp + 8] */
    /* cmp MEM32(eax), 0 */ /* 0x004E3E69: cmp dword ptr [eax], 0 */
    if (CMP_GE(MEM32(eax), 0)) goto L_004E3E75; /* 0x004E3E6C: jge 0x4e3e75 */

L_004E3E6E:
    eax = 0; /* 0x004E3E6E: xor eax, eax */
    goto L_004E40BC; /* 0x004E3E70: jmp 0x4e40bc */

L_004E3E75:
    RECOMP_CALL(sub_004DF750); /* 0x004E3E75: call 0x4df750 */
    ecx = MEM32(ebp + 0x8); /* 0x004E3E7A: mov ecx, dword ptr [ebp + 8] */
    /* cmp MEM32(ecx), 0x0003F480u */ /* 0x004E3E7D: cmp dword ptr [ecx], 0x3f480 */
    if (CMP_LE(MEM32(ecx), 0x0003F480u)) goto L_004E3EF0; /* 0x004E3E83: jle 0x4e3ef0 */

L_004E3E85:
    edx = MEM32(ebp + 0x8); /* 0x004E3E85: mov edx, dword ptr [ebp + 8] */
    /* cmp MEM32(edx), 0x7FFC0B7Fu */ /* 0x004E3E88: cmp dword ptr [edx], 0x7ffc0b7f */
    if (CMP_GE(MEM32(edx), 0x7FFC0B7Fu)) goto L_004E3EF0; /* 0x004E3E8E: jge 0x4e3ef0 */

L_004E3E90:
    eax = MEM32(ebp + 0x8); /* 0x004E3E90: mov eax, dword ptr [ebp + 8] */
    ecx = MEM32(eax); /* 0x004E3E93: mov ecx, dword ptr [eax] */
    ecx = ecx - MEM32(0x50B8C0); /* 0x004E3E95: sub ecx, dword ptr [0x50b8c0] */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3E9B: mov dword ptr [ebp - 4], ecx */
    edx = ebp + (-0x4); /* 0x004E3E9E: lea edx, [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E3EA1: push edx */
    RECOMP_CALL(sub_004E3C90); /* 0x004E3EA2: call 0x4e3c90 */
    esp = esp + 4; /* 0x004E3EA7: add esp, 4 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E3EAA: mov dword ptr [ebp - 8], eax */
    /* cmp MEM32(0x50B8C4), 0 */ /* 0x004E3EAD: cmp dword ptr [0x50b8c4], 0 */
    if (CMP_EQ(MEM32(0x50B8C4), 0)) goto L_004E3EEB; /* 0x004E3EB4: je 0x4e3eeb */

L_004E3EB6:
    eax = MEM32(ebp + (-0x8)); /* 0x004E3EB6: mov eax, dword ptr [ebp - 8] */
    PUSH32(esp, eax); /* 0x004E3EB9: push eax */
    RECOMP_CALL(sub_004DFAB0); /* 0x004E3EBA: call 0x4dfab0 */
    esp = esp + 4; /* 0x004E3EBF: add esp, 4 */
    /* test eax, eax */ /* 0x004E3EC2: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004E3EEB; /* 0x004E3EC4: je 0x4e3eeb */

L_004E3EC6:
    ecx = MEM32(ebp + (-0x4)); /* 0x004E3EC6: mov ecx, dword ptr [ebp - 4] */
    ecx = ecx - MEM32(0x50B8C8); /* 0x004E3EC9: sub ecx, dword ptr [0x50b8c8] */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3ECF: mov dword ptr [ebp - 4], ecx */
    edx = ebp + (-0x4); /* 0x004E3ED2: lea edx, [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E3ED5: push edx */
    RECOMP_CALL(sub_004E3C90); /* 0x004E3ED6: call 0x4e3c90 */
    esp = esp + 4; /* 0x004E3EDB: add esp, 4 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E3EDE: mov dword ptr [ebp - 8], eax */
    eax = MEM32(ebp + (-0x8)); /* 0x004E3EE1: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x20) = 1; /* 0x004E3EE4: mov dword ptr [eax + 0x20], 1 */

L_004E3EEB:
    goto L_004E40B9; /* 0x004E3EEB: jmp 0x4e40b9 */

L_004E3EF0:
    ecx = MEM32(ebp + 0x8); /* 0x004E3EF0: mov ecx, dword ptr [ebp + 8] */
    PUSH32(esp, ecx); /* 0x004E3EF3: push ecx */
    RECOMP_CALL(sub_004E3C90); /* 0x004E3EF4: call 0x4e3c90 */
    esp = esp + 4; /* 0x004E3EF9: add esp, 4 */
    MEM32(ebp + (-0x8)) = eax; /* 0x004E3EFC: mov dword ptr [ebp - 8], eax */
    edx = MEM32(ebp + (-0x8)); /* 0x004E3EFF: mov edx, dword ptr [ebp - 8] */
    PUSH32(esp, edx); /* 0x004E3F02: push edx */
    RECOMP_CALL(sub_004DFAB0); /* 0x004E3F03: call 0x4dfab0 */
    esp = esp + 4; /* 0x004E3F08: add esp, 4 */
    /* test eax, eax */ /* 0x004E3F0B: test eax, eax */
    if (TEST_Z(eax, eax)) goto L_004E3F26; /* 0x004E3F0D: je 0x4e3f26 */

L_004E3F0F:
    eax = MEM32(0x50B8C0); /* 0x004E3F0F: mov eax, dword ptr [0x50b8c0] */
    eax = eax + MEM32(0x50B8C8); /* 0x004E3F14: add eax, dword ptr [0x50b8c8] */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3F1A: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx); /* 0x004E3F1D: mov edx, dword ptr [ecx] */
    edx = edx - eax; /* 0x004E3F1F: sub edx, eax */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3F21: mov dword ptr [ebp - 4], edx */
    goto L_004E3F34; /* 0x004E3F24: jmp 0x4e3f34 */

L_004E3F26:
    eax = MEM32(ebp + (-0x8)); /* 0x004E3F26: mov eax, dword ptr [ebp - 8] */
    ecx = MEM32(eax); /* 0x004E3F29: mov ecx, dword ptr [eax] */
    ecx = ecx - MEM32(0x50B8C0); /* 0x004E3F2B: sub ecx, dword ptr [0x50b8c0] */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3F31: mov dword ptr [ebp - 4], ecx */

L_004E3F34:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3F34: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3F37: cdq  */
    ecx = 0x3Cu; /* 0x004E3F38: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3F3D: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E3F3F: mov eax, dword ptr [ebp - 8] */
    MEM32(eax) = edx; /* 0x004E3F42: mov dword ptr [eax], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3F44: mov ecx, dword ptr [ebp - 8] */
    /* cmp MEM32(ecx), 0 */ /* 0x004E3F47: cmp dword ptr [ecx], 0 */
    if (CMP_GE(MEM32(ecx), 0)) goto L_004E3F62; /* 0x004E3F4A: jge 0x4e3f62 */

L_004E3F4C:
    edx = MEM32(ebp + (-0x8)); /* 0x004E3F4C: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx); /* 0x004E3F4F: mov eax, dword ptr [edx] */
    eax = eax + 0x3Cu; /* 0x004E3F51: add eax, 0x3c */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3F54: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx) = eax; /* 0x004E3F57: mov dword ptr [ecx], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004E3F59: mov edx, dword ptr [ebp - 4] */
    edx = edx - 0x3Cu; /* 0x004E3F5C: sub edx, 0x3c */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3F5F: mov dword ptr [ebp - 4], edx */

L_004E3F62:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3F62: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3F65: cdq  */
    ecx = 0x3Cu; /* 0x004E3F66: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3F6B: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x8)); /* 0x004E3F6D: mov edx, dword ptr [ebp - 8] */
    ecx = MEM32(edx + 0x4); /* 0x004E3F70: mov ecx, dword ptr [edx + 4] */
    ecx = ecx + eax; /* 0x004E3F73: add ecx, eax */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3F75: mov dword ptr [ebp - 4], ecx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3F78: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3F7B: cdq  */
    ecx = 0x3Cu; /* 0x004E3F7C: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3F81: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E3F83: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x4) = edx; /* 0x004E3F86: mov dword ptr [eax + 4], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3F89: mov ecx, dword ptr [ebp - 8] */
    /* cmp MEM32(ecx + 0x4), 0 */ /* 0x004E3F8C: cmp dword ptr [ecx + 4], 0 */
    if (CMP_GE(MEM32(ecx + 0x4), 0)) goto L_004E3FAA; /* 0x004E3F90: jge 0x4e3faa */

L_004E3F92:
    edx = MEM32(ebp + (-0x8)); /* 0x004E3F92: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0x4); /* 0x004E3F95: mov eax, dword ptr [edx + 4] */
    eax = eax + 0x3Cu; /* 0x004E3F98: add eax, 0x3c */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3F9B: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx + 0x4) = eax; /* 0x004E3F9E: mov dword ptr [ecx + 4], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004E3FA1: mov edx, dword ptr [ebp - 4] */
    edx = edx - 0x3Cu; /* 0x004E3FA4: sub edx, 0x3c */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3FA7: mov dword ptr [ebp - 4], edx */

L_004E3FAA:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3FAA: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3FAD: cdq  */
    ecx = 0x3Cu; /* 0x004E3FAE: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3FB3: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x8)); /* 0x004E3FB5: mov edx, dword ptr [ebp - 8] */
    ecx = MEM32(edx + 0x8); /* 0x004E3FB8: mov ecx, dword ptr [edx + 8] */
    ecx = ecx + eax; /* 0x004E3FBB: add ecx, eax */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3FBD: mov dword ptr [ebp - 4], ecx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3FC0: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3FC3: cdq  */
    ecx = 0x18u; /* 0x004E3FC4: mov ecx, 0x18 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3FC9: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E3FCB: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x8) = edx; /* 0x004E3FCE: mov dword ptr [eax + 8], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3FD1: mov ecx, dword ptr [ebp - 8] */
    /* cmp MEM32(ecx + 0x8), 0 */ /* 0x004E3FD4: cmp dword ptr [ecx + 8], 0 */
    if (CMP_GE(MEM32(ecx + 0x8), 0)) goto L_004E3FF2; /* 0x004E3FD8: jge 0x4e3ff2 */

L_004E3FDA:
    edx = MEM32(ebp + (-0x8)); /* 0x004E3FDA: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0x8); /* 0x004E3FDD: mov eax, dword ptr [edx + 8] */
    eax = eax + 0x18u; /* 0x004E3FE0: add eax, 0x18 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3FE3: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx + 0x8) = eax; /* 0x004E3FE6: mov dword ptr [ecx + 8], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004E3FE9: mov edx, dword ptr [ebp - 4] */
    edx = edx - 0x18u; /* 0x004E3FEC: sub edx, 0x18 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3FEF: mov dword ptr [ebp - 4], edx */

L_004E3FF2:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3FF2: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3FF5: cdq  */
    ecx = 0x18u; /* 0x004E3FF6: mov ecx, 0x18 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3FFB: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    MEM32(ebp + (-0x4)) = eax; /* 0x004E3FFD: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004E4000: cmp dword ptr [ebp - 4], 0 */
    if (CMP_LE(MEM32(ebp + (-0x4)), 0)) goto L_004E403D; /* 0x004E4004: jle 0x4e403d */

L_004E4006:
    edx = MEM32(ebp + (-0x8)); /* 0x004E4006: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0x18); /* 0x004E4009: mov eax, dword ptr [edx + 0x18] */
    eax = eax + MEM32(ebp + (-0x4)); /* 0x004E400C: add eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E400F: cdq  */
    ecx = 7; /* 0x004E4010: mov ecx, 7 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E4015: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E4017: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x18) = edx; /* 0x004E401A: mov dword ptr [eax + 0x18], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E401D: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0xC); /* 0x004E4020: mov edx, dword ptr [ecx + 0xc] */
    edx = edx + MEM32(ebp + (-0x4)); /* 0x004E4023: add edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E4026: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0xC) = edx; /* 0x004E4029: mov dword ptr [eax + 0xc], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E402C: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004E402F: mov edx, dword ptr [ecx + 0x1c] */
    edx = edx + MEM32(ebp + (-0x4)); /* 0x004E4032: add edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E4035: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x1C) = edx; /* 0x004E4038: mov dword ptr [eax + 0x1c], edx */
    goto L_004E40B9; /* 0x004E403B: jmp 0x4e40b9 */

L_004E403D:
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004E403D: cmp dword ptr [ebp - 4], 0 */
    if (CMP_GE(MEM32(ebp + (-0x4)), 0)) goto L_004E40B9; /* 0x004E4041: jge 0x4e40b9 */

L_004E4043:
    ecx = MEM32(ebp + (-0x8)); /* 0x004E4043: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0x18); /* 0x004E4046: mov edx, dword ptr [ecx + 0x18] */
    eax = MEM32(ebp + (-0x4)); /* 0x004E4049: mov eax, dword ptr [ebp - 4] */
    eax = edx + eax + 0x7; /* 0x004E404C: lea eax, [edx + eax + 7] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E4050: cdq  */
    ecx = 7; /* 0x004E4051: mov ecx, 7 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E4056: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E4058: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x18) = edx; /* 0x004E405B: mov dword ptr [eax + 0x18], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E405E: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0xC); /* 0x004E4061: mov edx, dword ptr [ecx + 0xc] */
    edx = edx + MEM32(ebp + (-0x4)); /* 0x004E4064: add edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E4067: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0xC) = edx; /* 0x004E406A: mov dword ptr [eax + 0xc], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E406D: mov ecx, dword ptr [ebp - 8] */
    /* cmp MEM32(ecx + 0xC), 0 */ /* 0x004E4070: cmp dword ptr [ecx + 0xc], 0 */
    if (CMP_G(MEM32(ecx + 0xC), 0)) goto L_004E40AA; /* 0x004E4074: jg 0x4e40aa */

L_004E4076:
    edx = MEM32(ebp + (-0x8)); /* 0x004E4076: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0xC); /* 0x004E4079: mov eax, dword ptr [edx + 0xc] */
    eax = eax + 0x1Fu; /* 0x004E407C: add eax, 0x1f */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E407F: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx + 0xC) = eax; /* 0x004E4082: mov dword ptr [ecx + 0xc], eax */
    edx = MEM32(ebp + (-0x8)); /* 0x004E4085: mov edx, dword ptr [ebp - 8] */
    MEM32(edx + 0x1C) = 0x16Cu; /* 0x004E4088: mov dword ptr [edx + 0x1c], 0x16c */
    eax = MEM32(ebp + (-0x8)); /* 0x004E408F: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x10) = 0xBu; /* 0x004E4092: mov dword ptr [eax + 0x10], 0xb */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E4099: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0x14); /* 0x004E409C: mov edx, dword ptr [ecx + 0x14] */
    edx = edx - 1; /* 0x004E409F: sub edx, 1 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E40A2: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x14) = edx; /* 0x004E40A5: mov dword ptr [eax + 0x14], edx */
    goto L_004E40B9; /* 0x004E40A8: jmp 0x4e40b9 */

L_004E40AA:
    ecx = MEM32(ebp + (-0x8)); /* 0x004E40AA: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004E40AD: mov edx, dword ptr [ecx + 0x1c] */
    edx = edx + MEM32(ebp + (-0x4)); /* 0x004E40B0: add edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E40B3: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x1C) = edx; /* 0x004E40B6: mov dword ptr [eax + 0x1c], edx */

L_004E40B9:
    eax = MEM32(ebp + (-0x8)); /* 0x004E40B9: mov eax, dword ptr [ebp - 8] */

L_004E40BC:
    esp = ebp; /* 0x004E40BC: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E40BE: pop ebp */
    return; /* 0x004E40BF: ret  */

}

void sub_004E3F56(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E3F56:
    _cf = 0; /* 0x004E3F56: clc  */
    MEM32(ecx) = eax; /* 0x004E3F57: mov dword ptr [ecx], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004E3F59: mov edx, dword ptr [ebp - 4] */
    edx = edx - 0x3Cu; /* 0x004E3F5C: sub edx, 0x3c */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3F5F: mov dword ptr [ebp - 4], edx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3F62: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3F65: cdq  */
    ecx = 0x3Cu; /* 0x004E3F66: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3F6B: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x8)); /* 0x004E3F6D: mov edx, dword ptr [ebp - 8] */
    ecx = MEM32(edx + 0x4); /* 0x004E3F70: mov ecx, dword ptr [edx + 4] */
    ecx = ecx + eax; /* 0x004E3F73: add ecx, eax */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3F75: mov dword ptr [ebp - 4], ecx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3F78: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3F7B: cdq  */
    ecx = 0x3Cu; /* 0x004E3F7C: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3F81: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E3F83: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x4) = edx; /* 0x004E3F86: mov dword ptr [eax + 4], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3F89: mov ecx, dword ptr [ebp - 8] */
    /* cmp MEM32(ecx + 0x4), 0 */ /* 0x004E3F8C: cmp dword ptr [ecx + 4], 0 */
    if (CMP_GE(MEM32(ecx + 0x4), 0)) goto L_004E3FAA; /* 0x004E3F90: jge 0x4e3faa */

L_004E3F92:
    edx = MEM32(ebp + (-0x8)); /* 0x004E3F92: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0x4); /* 0x004E3F95: mov eax, dword ptr [edx + 4] */
    eax = eax + 0x3Cu; /* 0x004E3F98: add eax, 0x3c */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3F9B: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx + 0x4) = eax; /* 0x004E3F9E: mov dword ptr [ecx + 4], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004E3FA1: mov edx, dword ptr [ebp - 4] */
    edx = edx - 0x3Cu; /* 0x004E3FA4: sub edx, 0x3c */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3FA7: mov dword ptr [ebp - 4], edx */

L_004E3FAA:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3FAA: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3FAD: cdq  */
    ecx = 0x3Cu; /* 0x004E3FAE: mov ecx, 0x3c */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3FB3: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    edx = MEM32(ebp + (-0x8)); /* 0x004E3FB5: mov edx, dword ptr [ebp - 8] */
    ecx = MEM32(edx + 0x8); /* 0x004E3FB8: mov ecx, dword ptr [edx + 8] */
    ecx = ecx + eax; /* 0x004E3FBB: add ecx, eax */
    MEM32(ebp + (-0x4)) = ecx; /* 0x004E3FBD: mov dword ptr [ebp - 4], ecx */
    eax = MEM32(ebp + (-0x4)); /* 0x004E3FC0: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3FC3: cdq  */
    ecx = 0x18u; /* 0x004E3FC4: mov ecx, 0x18 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3FC9: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E3FCB: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x8) = edx; /* 0x004E3FCE: mov dword ptr [eax + 8], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3FD1: mov ecx, dword ptr [ebp - 8] */
    /* cmp MEM32(ecx + 0x8), 0 */ /* 0x004E3FD4: cmp dword ptr [ecx + 8], 0 */
    if (CMP_GE(MEM32(ecx + 0x8), 0)) goto L_004E3FF2; /* 0x004E3FD8: jge 0x4e3ff2 */

L_004E3FDA:
    edx = MEM32(ebp + (-0x8)); /* 0x004E3FDA: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0x8); /* 0x004E3FDD: mov eax, dword ptr [edx + 8] */
    eax = eax + 0x18u; /* 0x004E3FE0: add eax, 0x18 */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E3FE3: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx + 0x8) = eax; /* 0x004E3FE6: mov dword ptr [ecx + 8], eax */
    edx = MEM32(ebp + (-0x4)); /* 0x004E3FE9: mov edx, dword ptr [ebp - 4] */
    edx = edx - 0x18u; /* 0x004E3FEC: sub edx, 0x18 */
    MEM32(ebp + (-0x4)) = edx; /* 0x004E3FEF: mov dword ptr [ebp - 4], edx */

L_004E3FF2:
    eax = MEM32(ebp + (-0x4)); /* 0x004E3FF2: mov eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E3FF5: cdq  */
    ecx = 0x18u; /* 0x004E3FF6: mov ecx, 0x18 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E3FFB: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    MEM32(ebp + (-0x4)) = eax; /* 0x004E3FFD: mov dword ptr [ebp - 4], eax */
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004E4000: cmp dword ptr [ebp - 4], 0 */
    if (CMP_LE(MEM32(ebp + (-0x4)), 0)) goto L_004E403D; /* 0x004E4004: jle 0x4e403d */

L_004E4006:
    edx = MEM32(ebp + (-0x8)); /* 0x004E4006: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0x18); /* 0x004E4009: mov eax, dword ptr [edx + 0x18] */
    eax = eax + MEM32(ebp + (-0x4)); /* 0x004E400C: add eax, dword ptr [ebp - 4] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E400F: cdq  */
    ecx = 7; /* 0x004E4010: mov ecx, 7 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E4015: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E4017: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x18) = edx; /* 0x004E401A: mov dword ptr [eax + 0x18], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E401D: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0xC); /* 0x004E4020: mov edx, dword ptr [ecx + 0xc] */
    edx = edx + MEM32(ebp + (-0x4)); /* 0x004E4023: add edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E4026: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0xC) = edx; /* 0x004E4029: mov dword ptr [eax + 0xc], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E402C: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004E402F: mov edx, dword ptr [ecx + 0x1c] */
    edx = edx + MEM32(ebp + (-0x4)); /* 0x004E4032: add edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E4035: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x1C) = edx; /* 0x004E4038: mov dword ptr [eax + 0x1c], edx */
    goto L_004E40B9; /* 0x004E403B: jmp 0x4e40b9 */

L_004E403D:
    /* cmp MEM32(ebp + (-0x4)), 0 */ /* 0x004E403D: cmp dword ptr [ebp - 4], 0 */
    if (CMP_GE(MEM32(ebp + (-0x4)), 0)) goto L_004E40B9; /* 0x004E4041: jge 0x4e40b9 */

L_004E4043:
    ecx = MEM32(ebp + (-0x8)); /* 0x004E4043: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0x18); /* 0x004E4046: mov edx, dword ptr [ecx + 0x18] */
    eax = MEM32(ebp + (-0x4)); /* 0x004E4049: mov eax, dword ptr [ebp - 4] */
    eax = edx + eax + 0x7; /* 0x004E404C: lea eax, [edx + eax + 7] */
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFFu : 0; /* 0x004E4050: cdq  */
    ecx = 7; /* 0x004E4051: mov ecx, 7 */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax; /* 0x004E4056: idiv ecx */
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = MEM32(ebp + (-0x8)); /* 0x004E4058: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x18) = edx; /* 0x004E405B: mov dword ptr [eax + 0x18], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E405E: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0xC); /* 0x004E4061: mov edx, dword ptr [ecx + 0xc] */
    edx = edx + MEM32(ebp + (-0x4)); /* 0x004E4064: add edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E4067: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0xC) = edx; /* 0x004E406A: mov dword ptr [eax + 0xc], edx */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E406D: mov ecx, dword ptr [ebp - 8] */
    /* cmp MEM32(ecx + 0xC), 0 */ /* 0x004E4070: cmp dword ptr [ecx + 0xc], 0 */
    if (CMP_G(MEM32(ecx + 0xC), 0)) goto L_004E40AA; /* 0x004E4074: jg 0x4e40aa */

L_004E4076:
    edx = MEM32(ebp + (-0x8)); /* 0x004E4076: mov edx, dword ptr [ebp - 8] */
    eax = MEM32(edx + 0xC); /* 0x004E4079: mov eax, dword ptr [edx + 0xc] */
    eax = eax + 0x1Fu; /* 0x004E407C: add eax, 0x1f */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E407F: mov ecx, dword ptr [ebp - 8] */
    MEM32(ecx + 0xC) = eax; /* 0x004E4082: mov dword ptr [ecx + 0xc], eax */
    edx = MEM32(ebp + (-0x8)); /* 0x004E4085: mov edx, dword ptr [ebp - 8] */
    MEM32(edx + 0x1C) = 0x16Cu; /* 0x004E4088: mov dword ptr [edx + 0x1c], 0x16c */
    eax = MEM32(ebp + (-0x8)); /* 0x004E408F: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x10) = 0xBu; /* 0x004E4092: mov dword ptr [eax + 0x10], 0xb */
    ecx = MEM32(ebp + (-0x8)); /* 0x004E4099: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0x14); /* 0x004E409C: mov edx, dword ptr [ecx + 0x14] */
    edx = edx - 1; /* 0x004E409F: sub edx, 1 */
    eax = MEM32(ebp + (-0x8)); /* 0x004E40A2: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x14) = edx; /* 0x004E40A5: mov dword ptr [eax + 0x14], edx */
    goto L_004E40B9; /* 0x004E40A8: jmp 0x4e40b9 */

L_004E40AA:
    ecx = MEM32(ebp + (-0x8)); /* 0x004E40AA: mov ecx, dword ptr [ebp - 8] */
    edx = MEM32(ecx + 0x1C); /* 0x004E40AD: mov edx, dword ptr [ecx + 0x1c] */
    edx = edx + MEM32(ebp + (-0x4)); /* 0x004E40B0: add edx, dword ptr [ebp - 4] */
    eax = MEM32(ebp + (-0x8)); /* 0x004E40B3: mov eax, dword ptr [ebp - 8] */
    MEM32(eax + 0x1C) = edx; /* 0x004E40B6: mov dword ptr [eax + 0x1c], edx */

L_004E40B9:
    eax = MEM32(ebp + (-0x8)); /* 0x004E40B9: mov eax, dword ptr [ebp - 8] */
    esp = ebp; /* 0x004E40BC: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E40BE: pop ebp */
    return; /* 0x004E40BF: ret  */

}

void sub_004E415C(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E415C:
    esp = esp + 0xCu; /* 0x004E415C: add esp, 0xc */
    MEM32(ebp + (-0x100C)) = eax; /* 0x004E415F: mov dword ptr [ebp - 0x100c], eax */
    /* cmp MEM32(ebp + (-0x100C)), 0xFFFFFFFFu */ /* 0x004E4165: cmp dword ptr [ebp - 0x100c], -1 */
    if (CMP_EQ(MEM32(ebp + (-0x100C)), 0xFFFFFFFFu)) goto L_004E418D; /* 0x004E416C: je 0x4e418d */

L_004E416E:
    PUSH32(esp, 2); /* 0x004E416E: push 2 */
    PUSH32(esp, 0); /* 0x004E4170: push 0 */
    edx = MEM32(ebp + 0x8); /* 0x004E4172: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E4175: push edx */
    RECOMP_CALL(sub_004DB9C0); /* 0x004E4176: call 0x4db9c0 */
    esp = esp + 0xCu; /* 0x004E417B: add esp, 0xc */
    MEM32(ebp + (-0x1010)) = eax; /* 0x004E417E: mov dword ptr [ebp - 0x1010], eax */
    /* cmp MEM32(ebp + (-0x1010)), 0xFFFFFFFFu */ /* 0x004E4184: cmp dword ptr [ebp - 0x1010], -1 */
    if (CMP_NE(MEM32(ebp + (-0x1010)), 0xFFFFFFFFu)) goto L_004E4195; /* 0x004E418B: jne 0x4e4195 */

L_004E418D:
    eax = eax | 0xFFFFFFFFu; /* 0x004E418D: or eax, 0xffffffff */
    goto L_004E431E; /* 0x004E4190: jmp 0x4e431e */

L_004E4195:
    eax = MEM32(ebp + 0xC); /* 0x004E4195: mov eax, dword ptr [ebp + 0xc] */
    eax = eax - MEM32(ebp + (-0x1010)); /* 0x004E4198: sub eax, dword ptr [ebp - 0x1010] */
    MEM32(ebp + (-0x1018)) = eax; /* 0x004E419E: mov dword ptr [ebp - 0x1018], eax */
    /* cmp MEM32(ebp + (-0x1018)), 0 */ /* 0x004E41A4: cmp dword ptr [ebp - 0x1018], 0 */
    if (CMP_LE(MEM32(ebp + (-0x1018)), 0)) goto L_004E42AA; /* 0x004E41AB: jle 0x4e42aa */

L_004E41B1:
    PUSH32(esp, 0x1000u); /* 0x004E41B1: push 0x1000 */
    PUSH32(esp, 0); /* 0x004E41B6: push 0 */
    ecx = MEM32(ebp + (-0x1014)); /* 0x004E41B8: mov ecx, dword ptr [ebp - 0x1014] */
    PUSH32(esp, ecx); /* 0x004E41BE: push ecx */
    RECOMP_CALL(sub_004DA550); /* 0x004E41BF: call 0x4da550 */
    esp = esp + 0xCu; /* 0x004E41C4: add esp, 0xc */
    PUSH32(esp, 0x8000u); /* 0x004E41C7: push 0x8000 */
    edx = MEM32(ebp + 0x8); /* 0x004E41CC: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E41CF: push edx */
    RECOMP_CALL(sub_004E4960); /* 0x004E41D0: call 0x4e4960 */
    esp = esp + 8; /* 0x004E41D5: add esp, 8 */
    MEM32(ebp + (-0x4)) = eax; /* 0x004E41D8: mov dword ptr [ebp - 4], eax */

L_004E41DB:
    /* cmp MEM32(ebp + (-0x1018)), 0x1000u */ /* 0x004E41DB: cmp dword ptr [ebp - 0x1018], 0x1000 */
    if (CMP_L(MEM32(ebp + (-0x1018)), 0x1000u)) goto L_004E41F3; /* 0x004E41E5: jl 0x4e41f3 */

L_004E41E7:
    MEM32(ebp + (-0x1020)) = 0x1000u; /* 0x004E41E7: mov dword ptr [ebp - 0x1020], 0x1000 */
    goto L_004E41FF; /* 0x004E41F1: jmp 0x4e41ff */

L_004E41F3:
    eax = MEM32(ebp + (-0x1018)); /* 0x004E41F3: mov eax, dword ptr [ebp - 0x1018] */
    MEM32(ebp + (-0x1020)) = eax; /* 0x004E41F9: mov dword ptr [ebp - 0x1020], eax */

L_004E41FF:
    ecx = MEM32(ebp + (-0x1020)); /* 0x004E41FF: mov ecx, dword ptr [ebp - 0x1020] */
    MEM32(ebp + (-0x1008)) = ecx; /* 0x004E4205: mov dword ptr [ebp - 0x1008], ecx */
    /* cmp MEM32(ebp + (-0x1018)), 0x1000u */ /* 0x004E420B: cmp dword ptr [ebp - 0x1018], 0x1000 */
    if (CMP_L(MEM32(ebp + (-0x1018)), 0x1000u)) goto L_004E4223; /* 0x004E4215: jl 0x4e4223 */

L_004E4217:
    MEM32(ebp + (-0x1024)) = 0x1000u; /* 0x004E4217: mov dword ptr [ebp - 0x1024], 0x1000 */
    goto L_004E422F; /* 0x004E4221: jmp 0x4e422f */

L_004E4223:
    edx = MEM32(ebp + (-0x1018)); /* 0x004E4223: mov edx, dword ptr [ebp - 0x1018] */
    MEM32(ebp + (-0x1024)) = edx; /* 0x004E4229: mov dword ptr [ebp - 0x1024], edx */

L_004E422F:
    eax = MEM32(ebp + (-0x1024)); /* 0x004E422F: mov eax, dword ptr [ebp - 0x1024] */
    PUSH32(esp, eax); /* 0x004E4235: push eax */
    ecx = MEM32(ebp + (-0x1014)); /* 0x004E4236: mov ecx, dword ptr [ebp - 0x1014] */
    PUSH32(esp, ecx); /* 0x004E423C: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E423D: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E4240: push edx */
    RECOMP_CALL(sub_004DA1E0); /* 0x004E4241: call 0x4da1e0 */
    esp = esp + 0xCu; /* 0x004E4246: add esp, 0xc */
    MEM32(ebp + (-0x1008)) = eax; /* 0x004E4249: mov dword ptr [ebp - 0x1008], eax */
    /* cmp MEM32(ebp + (-0x1008)), 0xFFFFFFFFu */ /* 0x004E424F: cmp dword ptr [ebp - 0x1008], -1 */
    if (CMP_NE(MEM32(ebp + (-0x1008)), 0xFFFFFFFFu)) goto L_004E4279; /* 0x004E4256: jne 0x4e4279 */

L_004E4258:
    /* cmp MEM32(0x84B7B0), 5 */ /* 0x004E4258: cmp dword ptr [0x84b7b0], 5 */
    if (CMP_NE(MEM32(0x84B7B0), 5)) goto L_004E426B; /* 0x004E425F: jne 0x4e426b */

L_004E4261:
    MEM32(0x84B7AC) = 0xDu; /* 0x004E4261: mov dword ptr [0x84b7ac], 0xd */

L_004E426B:
    eax = MEM32(ebp + (-0x1008)); /* 0x004E426B: mov eax, dword ptr [ebp - 0x1008] */
    MEM32(ebp + (-0x101C)) = eax; /* 0x004E4271: mov dword ptr [ebp - 0x101c], eax */
    goto L_004E4298; /* 0x004E4277: jmp 0x4e4298 */

L_004E4279:
    ecx = MEM32(ebp + (-0x1018)); /* 0x004E4279: mov ecx, dword ptr [ebp - 0x1018] */
    ecx = ecx - MEM32(ebp + (-0x1008)); /* 0x004E427F: sub ecx, dword ptr [ebp - 0x1008] */
    MEM32(ebp + (-0x1018)) = ecx; /* 0x004E4285: mov dword ptr [ebp - 0x1018], ecx */
    /* cmp MEM32(ebp + (-0x1018)), 0 */ /* 0x004E428B: cmp dword ptr [ebp - 0x1018], 0 */
    if (CMP_G(MEM32(ebp + (-0x1018)), 0)) goto L_004E41DB; /* 0x004E4292: jg 0x4e41db */

L_004E4298:
    edx = MEM32(ebp + (-0x4)); /* 0x004E4298: mov edx, dword ptr [ebp - 4] */
    PUSH32(esp, edx); /* 0x004E429B: push edx */
    eax = MEM32(ebp + 0x8); /* 0x004E429C: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004E429F: push eax */
    RECOMP_CALL(sub_004E4960); /* 0x004E42A0: call 0x4e4960 */
    esp = esp + 8; /* 0x004E42A5: add esp, 8 */
    goto L_004E4303; /* 0x004E42A8: jmp 0x4e4303 */

L_004E42AA:
    /* cmp MEM32(ebp + (-0x1018)), 0 */ /* 0x004E42AA: cmp dword ptr [ebp - 0x1018], 0 */
    if (CMP_GE(MEM32(ebp + (-0x1018)), 0)) goto L_004E4303; /* 0x004E42B1: jge 0x4e4303 */

L_004E42B3:
    PUSH32(esp, 0); /* 0x004E42B3: push 0 */
    ecx = MEM32(ebp + 0xC); /* 0x004E42B5: mov ecx, dword ptr [ebp + 0xc] */
    PUSH32(esp, ecx); /* 0x004E42B8: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E42B9: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E42BC: push edx */
    RECOMP_CALL(sub_004DB9C0); /* 0x004E42BD: call 0x4db9c0 */
    esp = esp + 0xCu; /* 0x004E42C2: add esp, 0xc */
    eax = MEM32(ebp + 0x8); /* 0x004E42C5: mov eax, dword ptr [ebp + 8] */
    PUSH32(esp, eax); /* 0x004E42C8: push eax */
    RECOMP_CALL(sub_004E0780); /* 0x004E42C9: call 0x4e0780 */
    esp = esp + 4; /* 0x004E42CE: add esp, 4 */
    PUSH32(esp, eax); /* 0x004E42D1: push eax */
    RECOMP_ICALL(MEM32(0x8586A0)); /* 0x004E42D2: call dword ptr [0x8586a0] */
    eax = (uint32_t)(-(int32_t)eax); /* 0x004E42D8: neg eax */
    eax = _cf ? 0xFFFFFFFFu : 0; /* 0x004E42DA: sbb eax, eax */
    eax = (uint32_t)(-(int32_t)eax); /* 0x004E42DC: neg eax */
    eax = eax - 1; /* 0x004E42DE: dec eax */
    MEM32(ebp + (-0x101C)) = eax; /* 0x004E42DF: mov dword ptr [ebp - 0x101c], eax */
    /* cmp MEM32(ebp + (-0x101C)), 0xFFFFFFFFu */ /* 0x004E42E5: cmp dword ptr [ebp - 0x101c], -1 */
    if (CMP_NE(MEM32(ebp + (-0x101C)), 0xFFFFFFFFu)) goto L_004E4303; /* 0x004E42EC: jne 0x4e4303 */

L_004E42EE:
    MEM32(0x84B7AC) = 0xDu; /* 0x004E42EE: mov dword ptr [0x84b7ac], 0xd */
    RECOMP_ICALL(MEM32(0x85867C)); /* 0x004E42F8: call dword ptr [0x85867c] */
    MEM32(0x84B7B0) = eax; /* 0x004E42FE: mov dword ptr [0x84b7b0], eax */

L_004E4303:
    PUSH32(esp, 0); /* 0x004E4303: push 0 */
    ecx = MEM32(ebp + (-0x100C)); /* 0x004E4305: mov ecx, dword ptr [ebp - 0x100c] */
    PUSH32(esp, ecx); /* 0x004E430B: push ecx */
    edx = MEM32(ebp + 0x8); /* 0x004E430C: mov edx, dword ptr [ebp + 8] */
    PUSH32(esp, edx); /* 0x004E430F: push edx */
    RECOMP_CALL(sub_004DB9C0); /* 0x004E4310: call 0x4db9c0 */
    esp = esp + 0xCu; /* 0x004E4315: add esp, 0xc */
    eax = MEM32(ebp + (-0x101C)); /* 0x004E4318: mov eax, dword ptr [ebp - 0x101c] */

L_004E431E:
    edi = POP32_VAL(esp); /* 0x004E431E: pop edi */
    esi = POP32_VAL(esp); /* 0x004E431F: pop esi */
    ebx = POP32_VAL(esp); /* 0x004E4320: pop ebx */
    esp = ebp; /* 0x004E4321: mov esp, ebp */
    ebp = POP32_VAL(esp); /* 0x004E4323: pop ebp */
    return; /* 0x004E4324: ret  */

}

void sub_004E704F(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E704F:
    /* int3 breakpoint */ /* 0x004E704F: int3  */

}

void sub_004E73A6(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E73A6:
    /* int3 breakpoint */ /* 0x004E73A6: int3  */

}

void sub_004E8469(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E8469:
    /* int3 breakpoint */ /* 0x004E8469: int3  */

}

void sub_004E8B61(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004E8B61:
    /* int3 breakpoint */ /* 0x004E8B61: int3  */

}

void sub_004EDBC1(void) {
    uint32_t ebp = 0;  /* local frame pointer */
    double _st[8] = {0};  /* FPU stack */
    int _fp_top = 0;
    int _fpu_cmp = 0;
    uint32_t _cf = 0;  /* carry flag */
    int _df = 1;  /* direction flag (1=forward, -1=backward) */
    uint16_t _fpu_cw = 0x037F;  /* FPU control word */

L_004EDBC1:
    /* int3 breakpoint */ /* 0x004EDBC1: int3  */

}

