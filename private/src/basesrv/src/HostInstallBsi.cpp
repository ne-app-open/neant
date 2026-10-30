// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss and Ne.app (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <SystemKit/Err.h>
#include <SystemKit/System.h>
#include <SystemKit/Syscall.h>

IMPORT_C SInt32 BsiInstallHost(SInt32 argc, Char** argv)
{
    if (!argc || !argv) return kErrorExecutable;

    if (nesys_syscall_arg_1(nesys_hash_64("RtlBsiInstallHostBeginSection")) != nullptr) {
        nesys_syscall_arg_3(nesys_hash_64("RtlBsiInstallHostPushArgs"), &argc, argv);
        if (nesys_syscall_arg_1(nesys_hash_64("RtlBsiInstallHostEndSection")) != nullptr) {
            return kErrorSuccess;
        }

        RtlExitProcess(0, kErrorExecutable);
    }

    return kErrorExecutable;
}

// END
