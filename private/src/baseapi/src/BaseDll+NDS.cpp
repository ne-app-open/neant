// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app.
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-open/neant

#include <Ne/System/NDS.h>
#include <SystemKit/Syscall.h>

static VoidPtr _PRIVATE kCurrentDriveMnted = nullptr;

IMPORT_C Void NdsMapDrive(Void)
{
    if (kCurrentDriveMnted) return;
    kCurrentDriveMnted = nesys_syscall_arg_2(nesys_hash_64("_NdsMapDrive"), nullptr);
}

IMPORT_C Void NdsUnmapDrive(Void)
{
    nesys_syscall_arg_2(nesys_hash_64("_NdsUnmapDrive"), nullptr);
}

//// EOF
