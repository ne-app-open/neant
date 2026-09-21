// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#pragma once

#include <Ne/System/CAS.h>
#include <SystemKit/Err.h>
#include <Ne/System/LWAS.h>

/***********************************************************************************/
/// @brief NeAnt Console API.
/***********************************************************************************/

#ifndef kNeConsoleMaxTitleSz
#define kNeConsoleMaxTitleSz 128
#endif

struct _SHARED CHS_CONSOLE _FINAL {
  PHLWAS  fHandle;       // LWAS window handle for this console
  VoidPtr fWindowPtr;    // opaque window backing pointer (passed to UsrCreateWindow)
  SizeT   fWindowSz;     // size of fWindowPtr region

  SInt32  fFlags;        // runtime state flags (open, fullscreen, etc.)
  SInt32  fHostID;       // ties back to the host service instance
  SInt32  fKind;         // console kind (e.g. system vs user console)

  Char    fTitle[kNeConsoleMaxTitleSz];   // display title, e.g. "Ne.app Console"
  SizeT   fTitleSz;
};

#ifndef kCHSStartupBanner
#define kCHSStartupBanner
#endif

IMPORT_C SInt32 CHSOpenConsole(Void);
IMPORT_C SInt32 CHSCloseConsole(Void);
IMPORT_C SInt32 CHSHandleListenII(Void);
IMPORT_C SInt32 CHSHandleListen(Void);
IMPORT_C SInt32 CHSWriteConsole(_Input const Char* buf, _Input SizeT buf_sz);
IMPORT_C SInt32 CHSReadConsole(_Output Char* buf, _Input SizeT buf_sz);
