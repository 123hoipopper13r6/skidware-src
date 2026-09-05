#pragma once

// ─────────────────────────────────────────────────────────────
// VMProtect SDK bridge.
//
// Two modes:
//   1. Default (no macros): compiles to no-ops so the project builds
//      without the commercial VMProtect SDK. Markers below still map to
//      the real API names, so protected regions are ready for processing.
//   2. SKIDWARE_REAL_VMPROTECT: define this in the Release build config
//      AND add the VMProtect SDK include path + lib to link the real SDK.
//      After building, run the VMProtect tool on the produced .exe to
//      virtualize the marked regions. See build instructions below.
//
// Post-build steps (Release x64):
//   1. Install VMProtect (commercial) and note its SDK path.
//   2. Project > Properties > C/C++ > Preprocessor: add SKIDWARE_REAL_VMPROTECT.
//   3. C/C++ > General > Additional Include Directories: <VMProtect>\Include.
//   4. Linker > General > Additional Library Directories: <VMProtect>\Lib\Win64.
//   5. Open the built .exe in VMProtect, add the markers' regions, and
//      choose "Ultra" mutation/virtualization before saving the result.
// ─────────────────────────────────────────────────────────────

#if defined(SKIDWARE_REAL_VMPROTECT)
#include <VMProtectSDK.h>
#else

#if defined(__APPLE__) || defined(__unix__)
#define VMP_IMPORT 
#define VMP_API
#define VMP_WCHAR unsigned short
#else
#define VMP_IMPORT __declspec(dllimport)
#define VMP_API __stdcall
#define VMP_WCHAR wchar_t
#endif // __APPLE__ || __unix__

#ifdef __cplusplus
extern "C" {
#endif

// protection
inline void VMP_API VMProtectBegin(const char *) {}
inline void VMP_API VMProtectBeginVirtualization(const char *) {}
inline void VMP_API VMProtectBeginMutation(const char *) {}
inline void VMP_API VMProtectBeginUltra(const char *) {}
inline void VMP_API VMProtectBeginVirtualizationLockByKey(const char *) {}
inline void VMP_API VMProtectBeginUltraLockByKey(const char *) {}
inline void VMP_API VMProtectEnd(void) {}

// utils
inline bool VMP_API VMProtectIsProtected() { return false; }
inline bool VMP_API VMProtectIsDebuggerPresent(bool) { return false; }
inline bool VMP_API VMProtectIsVirtualMachinePresent(void) { return false; }
inline bool VMP_API VMProtectIsValidImageCRC(void) { return true; }
inline const char * VMP_API VMProtectDecryptStringA(const char *value) { return value; }
inline const VMP_WCHAR * VMP_API VMProtectDecryptStringW(const VMP_WCHAR *value) { return value; }
inline bool VMP_API VMProtectFreeString(const void *value) { return true; }

// licensing
enum VMProtectSerialStateFlags
{
	SERIAL_STATE_SUCCESS				= 0,
	SERIAL_STATE_FLAG_CORRUPTED			= 0x00000001,
	SERIAL_STATE_FLAG_INVALID			= 0x00000002,
	SERIAL_STATE_FLAG_BLACKLISTED		= 0x00000004,
	SERIAL_STATE_FLAG_DATE_EXPIRED		= 0x00000008,
	SERIAL_STATE_FLAG_RUNNING_TIME_OVER	= 0x00000010,
	SERIAL_STATE_FLAG_BAD_HWID			= 0x00000020,
	SERIAL_STATE_FLAG_MAX_BUILD_EXPIRED	= 0x00000040,
};

#pragma pack(push, 1)
typedef struct
{
	unsigned short	wYear;
	unsigned char	bMonth;
	unsigned char	bDay;
} VMProtectDate;

typedef struct
{
	int				nState;				// VMProtectSerialStateFlags
	VMP_WCHAR		wUserName[256];		// user name
	VMP_WCHAR		wEMail[256];		// email
	VMProtectDate	dtExpire;			// date of serial number expiration
	VMProtectDate	dtMaxBuild;			// max date of build, that will accept this key
	int				bRunningTime;		// running time in minutes
	unsigned char	nUserDataLength;	// length of user data in bUserData
	unsigned char	bUserData[255];		// up to 255 bytes of user data
} VMProtectSerialNumberData;
#pragma pack(pop)

inline int VMP_API VMProtectSetSerialNumber(const char *serial) { return SERIAL_STATE_FLAG_INVALID; }
inline int VMP_API VMProtectGetSerialNumberState() { return SERIAL_STATE_FLAG_INVALID; }
inline bool VMP_API VMProtectGetSerialNumberData(VMProtectSerialNumberData *data, int size) { return false; }
inline int VMP_API VMProtectGetCurrentHWID(char *hwid, int size) { return 0; }

// activation
enum VMProtectActivationFlags
{
	ACTIVATION_OK = 0,
	ACTIVATION_SMALL_BUFFER,
	ACTIVATION_NO_CONNECTION,
	ACTIVATION_BAD_REPLY,
	ACTIVATION_BANNED,
	ACTIVATION_CORRUPTED,
	ACTIVATION_BAD_CODE,
	ACTIVATION_ALREADY_USED,
	ACTIVATION_SERIAL_UNKNOWN,
	ACTIVATION_EXPIRED,
	ACTIVATION_NOT_AVAILABLE
};

inline int VMP_API VMProtectActivateLicense(const char *code, char *serial, int size) { return ACTIVATION_NOT_AVAILABLE; }
inline int VMP_API VMProtectDeactivateLicense(const char *serial) { return ACTIVATION_NOT_AVAILABLE; }
inline int VMP_API VMProtectGetOfflineActivationString(const char *code, char *buf, int size) { return ACTIVATION_NOT_AVAILABLE; }
inline int VMP_API VMProtectGetOfflineDeactivationString(const char *serial, char *buf, int size) { return ACTIVATION_NOT_AVAILABLE; }

#ifdef __cplusplus
}
#endif

#endif // SKIDWARE_REAL_VMPROTECT
