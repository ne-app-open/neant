// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss and Ne.app (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <CHSKit/Console.h>
#include <Ne/System/LWAS.h>

SInt32 main(SInt32 argc, Char** argv) {
  LIBSYS_UNUSED(argc);
  LIBSYS_UNUSED(argv);

  auto ret = CHSOpenConsole();

  if (ret != kErrorSuccess) return ret;

  while (ret == kErrorSuccess) {
    ret = CHSHandleListenII();

    SInt32 vkey = UsrGetVKeyDown(LWAS_VKEY_ESCAPE);
    if (vkey == LWAS_VKEY_ESCAPE) break;
  }

  CHSCloseConsole();

  return ret;
}