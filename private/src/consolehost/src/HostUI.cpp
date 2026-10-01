// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss and Ne.app (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <CHSKit/Console.h>
#include <Ne/System/LWAS.h>

const UInt8 kWindowFrame[] = {};
const SizeT kWindowFrameSz = sizeof(kWindowFrame);

/// TODO: LWAS frame to render the VT compliant text.

/// AMLALE: The ConsoleHost UI should have an options button and several shortcuts as well.

#ifndef kWindowBaseId
#define kWindowBaseId (33)
#endif

const SInt32 kWindowPasteId = kWindowBaseId + 1;
const SInt32 kWindowCopyId = kWindowBaseId + 2;
const SInt32 kWindowSettingsId = kWindowBaseId + 3;
