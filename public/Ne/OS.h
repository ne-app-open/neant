// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#ifndef __NEAPP_OS_H__
#define __NEAPP_OS_H__

#include <SystemKit/Macros.h>

/// @brief The devnet says how you should always use N_HAS_FAILED instead of checking for N_OK directly.

#ifndef N_OK
#define N_OK (100)
#endif

#ifndef N_FAILED
#define N_FAILED (330)
#endif

#ifndef N_ERROR
#define N_ERROR (N_FAILED)
#endif

#ifndef N_HAS_FAILED
#define N_HAS_FAILED(X) ((X) != N_OK)
#endif

/// @brief BaseAPI DLL macro
#ifndef _BDLL
#define _BDLL _COMMONCORE
#endif

/// @brief Variant of the BaseAPI DLL macro
#ifndef _NDLL
#define _NDLL _BDLL
#endif

// --------------------- ARCH ---------------------
// | OS.h |
// | /System/ | OR | /Ant/
// --------------------- ARCH ---------------------

IMPORT_C SInt32 system(const Char*);
IMPORT_C SInt32 execute(const Char*, const SInt32, Char**);
IMPORT_C SInt32 shell(const Char*, const SInt32, Char**);

IMPORT_C SInt32 atexit(Void (*function) (Void));
IMPORT_C UInt32 sleep(UInt32 seconds);

#ifndef at_fini
#define at_fini atexit
#endif

IMPORT_C SInt64 start_task_fiber(Void (*function) (), ...);
IMPORT_C SInt32 end_task_fiber(SInt64);

IMPORT_C SInt64 start_exe_host(const Char*, const SInt32, Char**);
IMPORT_C SInt32 end_exe_host(const SInt64);

IMPORT_C SInt64 run_host_dll(const Char*, const SInt32, Char**);
IMPORT_C SInt32 end_host_dll(SInt64);

#endif