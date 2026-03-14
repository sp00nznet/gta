/* Import bridge stubs for Grand Theft Auto.exe */
/* Auto-generated -- manual implementation needed */

#include "../../engine/recomp_runtime.h"
#include <stdio.h>

#define STUB(name) fprintf(stderr, "STUB: %s
", name)


/* ===== ADVAPI32.dll (4 functions) ===== */

/* 0x004A7000 */ void bridge_RegCloseKey(void) {
    STUB("ADVAPI32.dll::RegCloseKey");
}

/* 0x004A7004 */ void bridge_RegQueryValueExA(void) {
    STUB("ADVAPI32.dll::RegQueryValueExA");
}

/* 0x004A7008 */ void bridge_RegOpenKeyExA(void) {
    STUB("ADVAPI32.dll::RegOpenKeyExA");
}

/* 0x004A700C */ void bridge_RegSetValueExA(void) {
    STUB("ADVAPI32.dll::RegSetValueExA");
}


/* ===== DPLAYX.dll (2 functions) ===== */

/* 0x004A7014 */ void bridge_ordinal_1(void) {
    STUB("DPLAYX.dll::ordinal_1");
}

/* 0x004A7018 */ void bridge_ordinal_2(void) {
    STUB("DPLAYX.dll::ordinal_2");
}


/* ===== GDI32.dll (20 functions) ===== */

/* 0x004A7020 */ void bridge_SetSystemPaletteUse(void) {
    STUB("GDI32.dll::SetSystemPaletteUse");
}

/* 0x004A7024 */ void bridge_GetDeviceCaps(void) {
    STUB("GDI32.dll::GetDeviceCaps");
}

/* 0x004A7028 */ void bridge_SelectPalette(void) {
    STUB("GDI32.dll::SelectPalette");
}

/* 0x004A702C */ void bridge_RealizePalette(void) {
    STUB("GDI32.dll::RealizePalette");
}

/* 0x004A7030 */ void bridge_SelectObject(void) {
    STUB("GDI32.dll::SelectObject");
}

/* 0x004A7034 */ void bridge_DeleteDC(void) {
    STUB("GDI32.dll::DeleteDC");
}

/* 0x004A7038 */ void bridge_CreateCompatibleDC(void) {
    STUB("GDI32.dll::CreateCompatibleDC");
}

/* 0x004A703C */ void bridge_DeleteObject(void) {
    STUB("GDI32.dll::DeleteObject");
}

/* 0x004A7040 */ void bridge_CreatePalette(void) {
    STUB("GDI32.dll::CreatePalette");
}

/* 0x004A7044 */ void bridge_GetSystemPaletteUse(void) {
    STUB("GDI32.dll::GetSystemPaletteUse");
}

/* 0x004A7048 */ void bridge_GetSystemPaletteEntries(void) {
    STUB("GDI32.dll::GetSystemPaletteEntries");
}

/* 0x004A704C */ void bridge_CreateDCA(void) {
    STUB("GDI32.dll::CreateDCA");
}

/* 0x004A7050 */ void bridge_Escape(void) {
    STUB("GDI32.dll::Escape");
}

/* 0x004A7054 */ void bridge_GetDIBits(void) {
    STUB("GDI32.dll::GetDIBits");
}

/* 0x004A7058 */ void bridge_CreateCompatibleBitmap(void) {
    STUB("GDI32.dll::CreateCompatibleBitmap");
}

/* 0x004A705C */ void bridge_AnimatePalette(void) {
    STUB("GDI32.dll::AnimatePalette");
}

/* 0x004A7060 */ void bridge_BitBlt(void) {
    STUB("GDI32.dll::BitBlt");
}

/* 0x004A7064 */ void bridge_StretchBlt(void) {
    STUB("GDI32.dll::StretchBlt");
}

/* 0x004A7068 */ void bridge_SetStretchBltMode(void) {
    STUB("GDI32.dll::SetStretchBltMode");
}

/* 0x004A706C */ void bridge_GetStockObject(void) {
    STUB("GDI32.dll::GetStockObject");
}


/* ===== KERNEL32.dll (63 functions) ===== */

/* 0x004A7074 */ void bridge_HeapReAlloc(void) {
    STUB("KERNEL32.dll::HeapReAlloc");
}

/* 0x004A7078 */ void bridge_VirtualAlloc(void) {
    STUB("KERNEL32.dll::VirtualAlloc");
}

/* 0x004A707C */ void bridge_VirtualFree(void) {
    STUB("KERNEL32.dll::VirtualFree");
}

/* 0x004A7080 */ void bridge_HeapCreate(void) {
    STUB("KERNEL32.dll::HeapCreate");
}

/* 0x004A7084 */ void bridge_HeapDestroy(void) {
    STUB("KERNEL32.dll::HeapDestroy");
}

/* 0x004A7088 */ void bridge_GetVersionExA(void) {
    STUB("KERNEL32.dll::GetVersionExA");
}

/* 0x004A708C */ void bridge_IsBadWritePtr(void) {
    STUB("KERNEL32.dll::IsBadWritePtr");
}

/* 0x004A7090 */ void bridge_GetEnvironmentVariableA(void) {
    STUB("KERNEL32.dll::GetEnvironmentVariableA");
}

/* 0x004A7094 */ void bridge_GetModuleFileNameA(void) {
    STUB("KERNEL32.dll::GetModuleFileNameA");
}

/* 0x004A7098 */ void bridge_ReadFile(void) {
    STUB("KERNEL32.dll::ReadFile");
}

/* 0x004A709C */ void bridge_WriteFile(void) {
    STUB("KERNEL32.dll::WriteFile");
}

/* 0x004A70A0 */ void bridge_CloseHandle(void) {
    STUB("KERNEL32.dll::CloseHandle");
}

/* 0x004A70A4 */ void bridge_GetCommandLineA(void) {
    STUB("KERNEL32.dll::GetCommandLineA");
}

/* 0x004A70A8 */ void bridge_GetStartupInfoA(void) {
    STUB("KERNEL32.dll::GetStartupInfoA");
}

/* 0x004A70AC */ void bridge_HeapAlloc(void) {
    STUB("KERNEL32.dll::HeapAlloc");
}

/* 0x004A70B0 */ void bridge_HeapFree(void) {
    STUB("KERNEL32.dll::HeapFree");
}

/* 0x004A70B4 */ void bridge_GetStdHandle(void) {
    STUB("KERNEL32.dll::GetStdHandle");
}

/* 0x004A70B8 */ void bridge_TerminateProcess(void) {
    STUB("KERNEL32.dll::TerminateProcess");
}

/* 0x004A70BC */ void bridge_GetOEMCP(void) {
    STUB("KERNEL32.dll::GetOEMCP");
}

/* 0x004A70C0 */ void bridge_SetHandleCount(void) {
    STUB("KERNEL32.dll::SetHandleCount");
}

/* 0x004A70C4 */ void bridge_SetFilePointer(void) {
    STUB("KERNEL32.dll::SetFilePointer");
}

/* 0x004A70C8 */ void bridge_ReleaseMutex(void) {
    STUB("KERNEL32.dll::ReleaseMutex");
}

/* 0x004A70CC */ void bridge_Sleep(void) {
    STUB("KERNEL32.dll::Sleep");
}

/* 0x004A70D0 */ void bridge_GetLastError(void) {
    STUB("KERNEL32.dll::GetLastError");
}

/* 0x004A70D4 */ void bridge_CreateMutexA(void) {
    STUB("KERNEL32.dll::CreateMutexA");
}

/* 0x004A70D8 */ void bridge_LoadLibraryA(void) {
    STUB("KERNEL32.dll::LoadLibraryA");
}

/* 0x004A70DC */ void bridge_GetProcAddress(void) {
    STUB("KERNEL32.dll::GetProcAddress");
}

/* 0x004A70E0 */ void bridge_GetVersion(void) {
    STUB("KERNEL32.dll::GetVersion");
}

/* 0x004A70E4 */ void bridge_FindClose(void) {
    STUB("KERNEL32.dll::FindClose");
}

/* 0x004A70E8 */ void bridge_FindFirstFileA(void) {
    STUB("KERNEL32.dll::FindFirstFileA");
}

/* 0x004A70EC */ void bridge_GetSystemDirectoryA(void) {
    STUB("KERNEL32.dll::GetSystemDirectoryA");
}

/* 0x004A70F0 */ void bridge_GetModuleHandleA(void) {
    STUB("KERNEL32.dll::GetModuleHandleA");
}

/* 0x004A70F4 */ void bridge_GetLocalTime(void) {
    STUB("KERNEL32.dll::GetLocalTime");
}

/* 0x004A70F8 */ void bridge_GetTimeZoneInformation(void) {
    STUB("KERNEL32.dll::GetTimeZoneInformation");
}

/* 0x004A70FC */ void bridge_SetEnvironmentVariableA(void) {
    STUB("KERNEL32.dll::SetEnvironmentVariableA");
}

/* 0x004A7100 */ void bridge_LCMapStringA(void) {
    STUB("KERNEL32.dll::LCMapStringA");
}

/* 0x004A7104 */ void bridge_LCMapStringW(void) {
    STUB("KERNEL32.dll::LCMapStringW");
}

/* 0x004A7108 */ void bridge_SetEndOfFile(void) {
    STUB("KERNEL32.dll::SetEndOfFile");
}

/* 0x004A710C */ void bridge_GetFileType(void) {
    STUB("KERNEL32.dll::GetFileType");
}

/* 0x004A7110 */ void bridge_WideCharToMultiByte(void) {
    STUB("KERNEL32.dll::WideCharToMultiByte");
}

/* 0x004A7114 */ void bridge_UnhandledExceptionFilter(void) {
    STUB("KERNEL32.dll::UnhandledExceptionFilter");
}

/* 0x004A7118 */ void bridge_FreeEnvironmentStringsA(void) {
    STUB("KERNEL32.dll::FreeEnvironmentStringsA");
}

/* 0x004A711C */ void bridge_FreeEnvironmentStringsW(void) {
    STUB("KERNEL32.dll::FreeEnvironmentStringsW");
}

/* 0x004A7120 */ void bridge_GetEnvironmentStrings(void) {
    STUB("KERNEL32.dll::GetEnvironmentStrings");
}

/* 0x004A7124 */ void bridge_GetEnvironmentStringsW(void) {
    STUB("KERNEL32.dll::GetEnvironmentStringsW");
}

/* 0x004A7128 */ void bridge_FlushFileBuffers(void) {
    STUB("KERNEL32.dll::FlushFileBuffers");
}

/* 0x004A712C */ void bridge_SetUnhandledExceptionFilter(void) {
    STUB("KERNEL32.dll::SetUnhandledExceptionFilter");
}

/* 0x004A7130 */ void bridge_IsBadReadPtr(void) {
    STUB("KERNEL32.dll::IsBadReadPtr");
}

/* 0x004A7134 */ void bridge_IsBadCodePtr(void) {
    STUB("KERNEL32.dll::IsBadCodePtr");
}

/* 0x004A7138 */ void bridge_SetStdHandle(void) {
    STUB("KERNEL32.dll::SetStdHandle");
}

/* 0x004A713C */ void bridge_CreateFileA(void) {
    STUB("KERNEL32.dll::CreateFileA");
}

/* 0x004A7140 */ void bridge_MultiByteToWideChar(void) {
    STUB("KERNEL32.dll::MultiByteToWideChar");
}

/* 0x004A7144 */ void bridge_GetStringTypeA(void) {
    STUB("KERNEL32.dll::GetStringTypeA");
}

/* 0x004A7148 */ void bridge_GetStringTypeW(void) {
    STUB("KERNEL32.dll::GetStringTypeW");
}

/* 0x004A714C */ void bridge_GetCPInfo(void) {
    STUB("KERNEL32.dll::GetCPInfo");
}

/* 0x004A7150 */ void bridge_GetACP(void) {
    STUB("KERNEL32.dll::GetACP");
}

/* 0x004A7154 */ void bridge_CompareStringA(void) {
    STUB("KERNEL32.dll::CompareStringA");
}

/* 0x004A7158 */ void bridge_CompareStringW(void) {
    STUB("KERNEL32.dll::CompareStringW");
}

/* 0x004A715C */ void bridge_ExitProcess(void) {
    STUB("KERNEL32.dll::ExitProcess");
}

/* 0x004A7160 */ void bridge_GetCurrentProcess(void) {
    STUB("KERNEL32.dll::GetCurrentProcess");
}

/* 0x004A7164 */ void bridge_GetSystemTime(void) {
    STUB("KERNEL32.dll::GetSystemTime");
}

/* 0x004A7168 */ void bridge_GetSystemTimeAsFileTime(void) {
    STUB("KERNEL32.dll::GetSystemTimeAsFileTime");
}

/* 0x004A716C */ void bridge_RtlUnwind(void) {
    STUB("KERNEL32.dll::RtlUnwind");
}


/* ===== USER32.dll (29 functions) ===== */

/* 0x004A7174 */ void bridge_LoadStringA(void) {
    STUB("USER32.dll::LoadStringA");
}

/* 0x004A7178 */ void bridge_MessageBoxA(void) {
    STUB("USER32.dll::MessageBoxA");
}

/* 0x004A717C */ void bridge_DestroyWindow(void) {
    STUB("USER32.dll::DestroyWindow");
}

/* 0x004A7180 */ void bridge_EnableWindow(void) {
    STUB("USER32.dll::EnableWindow");
}

/* 0x004A7184 */ void bridge_SetActiveWindow(void) {
    STUB("USER32.dll::SetActiveWindow");
}

/* 0x004A7188 */ void bridge_SetForegroundWindow(void) {
    STUB("USER32.dll::SetForegroundWindow");
}

/* 0x004A718C */ void bridge_SetCursor(void) {
    STUB("USER32.dll::SetCursor");
}

/* 0x004A7190 */ void bridge_LoadCursorA(void) {
    STUB("USER32.dll::LoadCursorA");
}

/* 0x004A7194 */ void bridge_LoadIconA(void) {
    STUB("USER32.dll::LoadIconA");
}

/* 0x004A7198 */ void bridge_RegisterClassA(void) {
    STUB("USER32.dll::RegisterClassA");
}

/* 0x004A719C */ void bridge_SetFocus(void) {
    STUB("USER32.dll::SetFocus");
}

/* 0x004A71A0 */ void bridge_CreateWindowExA(void) {
    STUB("USER32.dll::CreateWindowExA");
}

/* 0x004A71A4 */ void bridge_GetWindowPlacement(void) {
    STUB("USER32.dll::GetWindowPlacement");
}

/* 0x004A71A8 */ void bridge_ShowWindow(void) {
    STUB("USER32.dll::ShowWindow");
}

/* 0x004A71AC */ void bridge_SetWindowPos(void) {
    STUB("USER32.dll::SetWindowPos");
}

/* 0x004A71B0 */ void bridge_SetWindowLongA(void) {
    STUB("USER32.dll::SetWindowLongA");
}

/* 0x004A71B4 */ void bridge_PostMessageA(void) {
    STUB("USER32.dll::PostMessageA");
}

/* 0x004A71B8 */ void bridge_GetActiveWindow(void) {
    STUB("USER32.dll::GetActiveWindow");
}

/* 0x004A71BC */ void bridge_GetDC(void) {
    STUB("USER32.dll::GetDC");
}

/* 0x004A71C0 */ void bridge_ReleaseDC(void) {
    STUB("USER32.dll::ReleaseDC");
}

/* 0x004A71C4 */ void bridge_GetKeyState(void) {
    STUB("USER32.dll::GetKeyState");
}

/* 0x004A71C8 */ void bridge_ShowCursor(void) {
    STUB("USER32.dll::ShowCursor");
}

/* 0x004A71CC */ void bridge_PeekMessageA(void) {
    STUB("USER32.dll::PeekMessageA");
}

/* 0x004A71D0 */ void bridge_TranslateMessage(void) {
    STUB("USER32.dll::TranslateMessage");
}

/* 0x004A71D4 */ void bridge_SetCursorPos(void) {
    STUB("USER32.dll::SetCursorPos");
}

/* 0x004A71D8 */ void bridge_SetWindowPlacement(void) {
    STUB("USER32.dll::SetWindowPlacement");
}

/* 0x004A71DC */ void bridge_DefWindowProcA(void) {
    STUB("USER32.dll::DefWindowProcA");
}

/* 0x004A71E0 */ void bridge_DispatchMessageA(void) {
    STUB("USER32.dll::DispatchMessageA");
}

/* 0x004A71E4 */ void bridge_GetClientRect(void) {
    STUB("USER32.dll::GetClientRect");
}


/* ===== WINMM.dll (2 functions) ===== */

/* 0x004A71EC */ void bridge_joyGetPosEx(void) {
    STUB("WINMM.dll::joyGetPosEx");
}

/* 0x004A71F0 */ void bridge_joyGetDevCapsA(void) {
    STUB("WINMM.dll::joyGetDevCapsA");
}


/* ===== mss32.dll (38 functions) ===== */

/* 0x004A71F8 */ void bridge__AIL_stream_position@4(void) {
    STUB("mss32.dll::_AIL_stream_position@4");
}

/* 0x004A71FC */ void bridge__AIL_set_digital_master_volume@8(void) {
    STUB("mss32.dll::_AIL_set_digital_master_volume@8");
}

/* 0x004A7200 */ void bridge__AIL_shutdown@0(void) {
    STUB("mss32.dll::_AIL_shutdown@0");
}

/* 0x004A7204 */ void bridge__AIL_release_sample_handle@4(void) {
    STUB("mss32.dll::_AIL_release_sample_handle@4");
}

/* 0x004A7208 */ void bridge__AIL_close_stream@4(void) {
    STUB("mss32.dll::_AIL_close_stream@4");
}

/* 0x004A720C */ void bridge__AIL_stream_info@20(void) {
    STUB("mss32.dll::_AIL_stream_info@20");
}

/* 0x004A7210 */ void bridge__AIL_open_stream@12(void) {
    STUB("mss32.dll::_AIL_open_stream@12");
}

/* 0x004A7214 */ void bridge__AIL_pause_stream@8(void) {
    STUB("mss32.dll::_AIL_pause_stream@8");
}

/* 0x004A7218 */ void bridge__AIL_startup@0(void) {
    STUB("mss32.dll::_AIL_startup@0");
}

/* 0x004A721C */ void bridge__AIL_set_stream_loop_count@8(void) {
    STUB("mss32.dll::_AIL_set_stream_loop_count@8");
}

/* 0x004A7220 */ void bridge__AIL_stop_timer@4(void) {
    STUB("mss32.dll::_AIL_stop_timer@4");
}

/* 0x004A7224 */ void bridge__AIL_release_timer_handle@4(void) {
    STUB("mss32.dll::_AIL_release_timer_handle@4");
}

/* 0x004A7228 */ void bridge__AIL_register_timer@4(void) {
    STUB("mss32.dll::_AIL_register_timer@4");
}

/* 0x004A722C */ void bridge__AIL_set_timer_frequency@8(void) {
    STUB("mss32.dll::_AIL_set_timer_frequency@8");
}

/* 0x004A7230 */ void bridge__AIL_start_timer@4(void) {
    STUB("mss32.dll::_AIL_start_timer@4");
}

/* 0x004A7234 */ void bridge__AIL_sample_status@4(void) {
    STUB("mss32.dll::_AIL_sample_status@4");
}

/* 0x004A7238 */ void bridge__AIL_end_sample@4(void) {
    STUB("mss32.dll::_AIL_end_sample@4");
}

/* 0x004A723C */ void bridge__AIL_start_sample@4(void) {
    STUB("mss32.dll::_AIL_start_sample@4");
}

/* 0x004A7240 */ void bridge__AIL_set_sample_address@12(void) {
    STUB("mss32.dll::_AIL_set_sample_address@12");
}

/* 0x004A7244 */ void bridge__AIL_set_sample_pan@8(void) {
    STUB("mss32.dll::_AIL_set_sample_pan@8");
}

/* 0x004A7248 */ void bridge__AIL_set_sample_playback_rate@8(void) {
    STUB("mss32.dll::_AIL_set_sample_playback_rate@8");
}

/* 0x004A724C */ void bridge__AIL_init_sample@4(void) {
    STUB("mss32.dll::_AIL_init_sample@4");
}

/* 0x004A7250 */ void bridge__AIL_ms_count@0(void) {
    STUB("mss32.dll::_AIL_ms_count@0");
}

/* 0x004A7254 */ void bridge__AIL_start_stream@4(void) {
    STUB("mss32.dll::_AIL_start_stream@4");
}

/* 0x004A7258 */ void bridge__AIL_set_stream_position@8(void) {
    STUB("mss32.dll::_AIL_set_stream_position@8");
}

/* 0x004A725C */ void bridge__AIL_set_preference@8(void) {
    STUB("mss32.dll::_AIL_set_preference@8");
}

/* 0x004A7260 */ void bridge__AIL_waveOutOpen@16(void) {
    STUB("mss32.dll::_AIL_waveOutOpen@16");
}

/* 0x004A7264 */ void bridge__AIL_digital_configuration@16(void) {
    STUB("mss32.dll::_AIL_digital_configuration@16");
}

/* 0x004A7268 */ void bridge__AIL_waveOutClose@4(void) {
    STUB("mss32.dll::_AIL_waveOutClose@4");
}

/* 0x004A726C */ void bridge__AIL_allocate_sample_handle@4(void) {
    STUB("mss32.dll::_AIL_allocate_sample_handle@4");
}

/* 0x004A7270 */ void bridge__AIL_mem_free_lock@4(void) {
    STUB("mss32.dll::_AIL_mem_free_lock@4");
}

/* 0x004A7274 */ void bridge__AIL_set_sample_type@12(void) {
    STUB("mss32.dll::_AIL_set_sample_type@12");
}

/* 0x004A7278 */ void bridge__AIL_set_sample_volume@8(void) {
    STUB("mss32.dll::_AIL_set_sample_volume@8");
}

/* 0x004A727C */ void bridge__AIL_set_sample_loop_count@8(void) {
    STUB("mss32.dll::_AIL_set_sample_loop_count@8");
}

/* 0x004A7280 */ void bridge__AIL_mem_alloc_lock@4(void) {
    STUB("mss32.dll::_AIL_mem_alloc_lock@4");
}

/* 0x004A7284 */ void bridge__AIL_service_stream@8(void) {
    STUB("mss32.dll::_AIL_service_stream@8");
}

/* 0x004A7288 */ void bridge__AIL_stream_status@4(void) {
    STUB("mss32.dll::_AIL_stream_status@4");
}

/* 0x004A728C */ void bridge__AIL_set_stream_volume@8(void) {
    STUB("mss32.dll::_AIL_set_stream_volume@8");
}


/* ===== smackw32.DLL (8 functions) ===== */

/* 0x004A7294 */ void bridge_ordinal_21(void) {
    STUB("smackw32.DLL::ordinal_21");
}

/* 0x004A7298 */ void bridge_ordinal_19(void) {
    STUB("smackw32.DLL::ordinal_19");
}

/* 0x004A729C */ void bridge_ordinal_32(void) {
    STUB("smackw32.DLL::ordinal_32");
}

/* 0x004A72A0 */ void bridge_ordinal_28(void) {
    STUB("smackw32.DLL::ordinal_28");
}

/* 0x004A72A4 */ void bridge_ordinal_23(void) {
    STUB("smackw32.DLL::ordinal_23");
}

/* 0x004A72A8 */ void bridge_ordinal_18(void) {
    STUB("smackw32.DLL::ordinal_18");
}

/* 0x004A72AC */ void bridge_ordinal_14(void) {
    STUB("smackw32.DLL::ordinal_14");
}

/* 0x004A72B0 */ void bridge_ordinal_33(void) {
    STUB("smackw32.DLL::ordinal_33");
}

