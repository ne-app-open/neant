// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <stdbool.h>
#include <Ne/Drivers/DDS.h>
#include <Ne/Drivers/Detail/Config.h>

#ifndef kKernelVersion
#define kKernelVersion kNeKernelVersion
#endif

IMPORT_C const _PRIVATE SInt32 kDDSVersion    = _DDS;
IMPORT_C const _PRIVATE SInt32 kDDKVersion    = _DDS;
IMPORT_C const _PRIVATE SInt32 kNeKernelVersion = _NEKERNEL;
IMPORT_C const _PRIVATE SInt32 kCommonCoreVersion = _COMMONCORE;

/// @note This function shall be called when the DDS launches

IMPORT_C _PRIVATE Void ddsi_must_pass_init(Void) {
    MUST_PASS(kDDSVersion == _DDS);
    MUST_PASS(kDDKVersion == _DDS);
    MUST_PASS(kNeKernelVersion == _NEKERNEL);
    MUST_PASS(kCommonCoreVersion == _COMMONCORE);
}
