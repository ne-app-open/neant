// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-open/neant

#include <Ne/System/LWAS.h>

/// @brief Is Virtual Key Down?
IMPORT_C SInt32 UsrGetVKeyDown(const SInt32)
{
    return kErrorInvalidData;
}

/// @brief Is Virtual Key?
IMPORT_C Bool UsrIsVKey(const SInt32)
{
    return NO;
}
