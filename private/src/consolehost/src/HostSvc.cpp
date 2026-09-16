// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss and Ne.app (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <CHSKit/Console.h>
#include <Ne/System/LWAS.h>

IMPORT_C SInt32 CHSOpenConsole(Void);
IMPORT_C SInt32 CHSHandleListen(Void);

SInt32 main(SInt32 argc, Char** argv) {
  LIBSYS_UNUSED(argc);
  LIBSYS_UNUSED(argv);

  auto ret = CHSOpenConsole();

  if (ret != kErrorSuccess) return ret;

  while (ret == kErrorSuccess) {
    ret = CHSHandleListen();

    SInt32 vkey = UsrGetVKeyDown(0);

    if (vkey == LWAS_VKEY_ESCAPE) break;
    if (vkey == (LWAS_VKEY_TAB & LWAS_VKEY_C)) break;
  }

  CHSCloseConsole();

  return ret;
}