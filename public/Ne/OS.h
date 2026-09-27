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

// --------------------- ARCH ---------------------
// | OS.h |
// | /System/ | OR | /Ant/
// --------------------- ARCH ---------------------

IMPORT_C int system(const char*);
IMPORT_C int execute(const char*, const int, char**);
IMPORT_C int shell(const char*, const int, char**);

IMPORT_C int atexit(void (*function) (void));
IMPORT_C unsigned int sleep(unsigned int seconds);

#ifndef at_fini
#define at_fini atexit
#endif

IMPORT_C long start_task_fiber(void (*function) (), ...);
IMPORT_C int end_task_fiber(long);

IMPORT_C long start_exe_host(const char*, const int, char**);
IMPORT_C int end_exe_host(const long);

IMPORT_C long run_host_dll(const char*, const int, char**);
IMPORT_C int end_host_dll(long);

#endif