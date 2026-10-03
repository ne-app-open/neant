// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss and Ne.app (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <CHSKit/Console.h>
#include <Ne/System/LWAS.h>

/// TODO: LWAS frame to render the VT compliant text.

/// AMLALE: The ConsoleHost UI should have an options button and several shortcuts as well.

#ifndef kWindowBaseId
#define kWindowBaseId (33)
#endif

const UInt8 _PRIVATE kWindowFrame[] = {};
const SizeT _PRIVATE kWindowFrameSz = sizeof(kWindowFrame);

const SInt32 _PRIVATE kWindowPasteId = kWindowBaseId + 1;
const SInt32 _PRIVATE kWindowCopyId = kWindowBaseId + 2;
const SInt32 _PRIVATE kWindowSettingsId = kWindowBaseId + 3;
