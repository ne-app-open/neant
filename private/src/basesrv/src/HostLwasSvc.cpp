// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss and Ne.app (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <CHSKit/Console.h>
#include <Ne/System/LWAS.h>
#include <SystemKit/Syscall.h>

IMPORT_C struct LHANDLE* UsrCreateWindow(VoidPtr, SizeT*);

IMPORT_C Void UsrDestroyWindow(struct LHANDLE* handle) {
  if (handle && handle->fHandle) CasDestroyHeap(handle->fHandle, 0);
  if (handle) CasDestroyHeap(handle, 0);
}

/// @brief Is Virtual Key Up?
IMPORT_C SInt32 UsrGetVKeyUp(const SInt32 key) {
  auto             r  = nesys_syscall_arg_2(nesys_hash_64("_UsrGetVKeyUp"), (VoidPtr) &key);
  volatile SInt32* ri = (volatile SInt32*) r;

  if (ri) return *ri;

  return LWAS_VKEY_COUNT;
}

/// @brief Is Virtual Key Down?
IMPORT_C SInt32 UsrGetVKeyDown(const SInt32 key) {
  auto             r  = nesys_syscall_arg_2(nesys_hash_64("_UsrGetVKeyDown"), (VoidPtr) &key);
  volatile SInt32* ri = (volatile SInt32*) r;

  if (ri) return *ri;

  return LWAS_VKEY_COUNT;
}

/// @brief Is Virtual Key?
IMPORT_C Bool UsrIsVKey(const SInt32 key) {
  auto             r  = nesys_syscall_arg_2(nesys_hash_64("_UsrIsVKey"), (VoidPtr) &key);
  volatile Bool* ri = (volatile Bool*) r;

  if (ri) return *ri;

  return LWAS_VKEY_COUNT;
}
