// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-open/neant

#include <Ne/System/LWAS.h>
#include <SystemKit/Syscall.h>

/// @note UI system calls are required for LWAS support. Check lwas-* branches in nekrnl.

/// @brief Is Virtual Key Down?
IMPORT_C SInt32 UsrGetVKeyDown(const SInt32 key)
{    
    if (key == 0) return -1;
    return *(SInt32*)nesys_syscall_arg_2(nesys_hash_64("_UsrGetVKeyDown"), (VoidPtr)&key);
}

/// @brief Is Virtual Key?
IMPORT_C Bool UsrIsVKey(const SInt32 key)
{
    if (key == 0) return NO;
    return nesys_syscall_arg_2(nesys_hash_64("_UsrIsVKey"), (VoidPtr)&key);
}

/// @brief Is Virtual Key Up?
IMPORT_C SInt32 UsrGetVKeyUp(const SInt32 key)
{    
    if (key == 0) return -1;
    return *(SInt32*)nesys_syscall_arg_2(nesys_hash_64("_UsrGetVKeyUp"), (VoidPtr)&key);
}
