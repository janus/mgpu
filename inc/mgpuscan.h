#pragma once

#ifdef _WIN32
#ifndef NOMINMAX
	#define NOMINMAX
#endif
#include <windows.h>
#define SCANAPI WINAPI
#else
#define SCANAPI
#endif

#include <cuda.h>

struct scanEngine_d;
typedef struct scanEngine_d* scanEngine_t;

typedef enum {
	SCAN_STATUS_SUCCESS = 0,
	SCAN_STATUS_NOT_INITIALIZED,
	SCAN_STATUS_DEVICE_ALLOC_FAILED,
	SCAN_STATUS_INVALID_CONTEXT,
	SCAN_STATUS_KERNEL_NOT_FOUND,
	SCAN_STATUS_KERNEL_ERROR,
	SCAN_STATUS_LAUNCH_ERROR,
	SCAN_STATUS_INVALID_VALUE,
	SCAN_STATUS_DEVICE_ERROR,
	SCAN_STATUS_UNSUPPORTED_DEVICE
} scanStatus_t;

#ifdef __cplusplus
extern "C" {
#endif

scanStatus_t scanCreateEngine(const char* cubin, scanEngine_t* engine);
scanStatus_t scanDestroyEngine(scanEngine_t engine);

scanStatus_t scanArray(scanEngine_t engine, CUdeviceptr data, int count,
	unsigned int* scanTotal, bool inclusive); 


#ifdef __cplusplus
} // extern "C"
#endif
