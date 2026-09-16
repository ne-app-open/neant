// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss and Ne.app (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <CHSKit/Console.h>
#include <Ne/System/LWAS.h>

static struct LHANDLE* kConsoleWnd{};
static VoidPtr         kConsoleWindowPtr{};
static SizeT           kConsoleWindowSz{};

IMPORT_C SInt32 CHSCloseConsole(Void) {
  if (!kConsoleWindowSz || !kConsoleWindowPtr) return kErrorInvalidData;

  UsrDestroyWindow(kConsoleWnd);
  kConsoleWnd = nullptr;

  return kErrorSuccess;
}

IMPORT_C SInt32 CHSOpenConsole(Void) {
  if (!kConsoleWindowSz || !kConsoleWindowPtr) return kErrorInvalidData;

  if (auto ret = UsrCreateWindow(kConsoleWindowPtr, &kConsoleWindowSz); ret) {
    kConsoleWnd = ret;
    return kErrorSuccess;
  }

  return kErrorInvalidData;
}

IMPORT_C SInt32 CHSHandleListen(Void) {
  if (!kConsoleWnd) return kErrorInvalidData;

  while (kConsoleWnd);

  return kErrorSuccess;
}
