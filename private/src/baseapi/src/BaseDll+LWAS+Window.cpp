// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-open/neant

#include <Ne/System/LWAS.h>

/// @brief Create window function.
IMPORT_C struct LHANDLE* UsrCreateWindow(VoidPtr, SizeT*) { return nullptr; }

/// @brief Destroy window function.
IMPORT_C Void UsrDestroyWindow(struct LHANDLE*) {}

/// @brief Is Virtual Key Up?
IMPORT_C SInt32 UsrGetVKeyUp(const SInt32) { return kErrorInvalidData; }
