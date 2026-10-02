// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <stdbool.h>
#include <Ne/Drivers/DDS.h>

#ifndef kKernelVersion
#define kKernelVersion kNeKernelVersion
#endif

IMPORT_C const SInt32 kDDSVersion    = _DDS;
IMPORT_C const SInt32 kNeKernelVersion = _NEKERNEL;
IMPORT_C const SInt32 kCommonCoreVersion = _COMMONCORE;

/// @note This function shall be called when the DDS launches

IMPORT_C Void ddsi_must_pass_init(Void) {
    MUST_PASS(kDDSVersion == _DDS);
    MUST_PASS(kNeKernelVersion == _NEKERNEL);
    MUST_PASS(kCommonCoreVersion == _COMMONCORE);
}
