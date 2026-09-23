// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://git.nekernel.org/src

#ifndef _NE_DDK_SHIMS_H_
#define _NE_DDK_SHIMS_H_

#include <Ne/System/CAS.h>

#ifndef _SHIMS
#define _SHIMS (202605L)
#endif

struct SHANDLE;

typedef Ref     ShmsRef;
typedef VoidPtr ShmsBlob;

struct _SHARED SHANDLE _FINAL {
  ShmsRef  fHandle;  /// @brief Mandatory for NeAnt handles.
  ShmsBlob fPrivate;
};

IMPORT_C SInt32 ShmInstallProc(_InOut SHANDLE* handle, _Input VoidPtr proc);

IMPORT_C SInt32 ShmInstallProcII(_InOut SHANDLE* handle, _Input VoidPtr proc, _Input SInt32 flags);

IMPORT_C SInt32 ShmInstallProcIII(_InOut SHANDLE* handle, _Input VoidPtr proc, _Input SInt32 flags, _Input SInt32 type);

IMPORT_C Void ShmDestroyProc(_InOut SHANDLE* handle);

IMPORT_C Void ShmDestroyProcII(_InOut SHANDLE* handle, _Input SInt32 flags);

IMPORT_C Void ShmDestroyProcIII(_InOut SHANDLE* handle, _Input SInt32 flags, _Input Bool zero_out);

#endif