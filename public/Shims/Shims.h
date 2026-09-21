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

struct _SHARED SHANDLE _FINAL {
  Ref fHandle;  /// @brief Mandatory for NeAnt handles.
  VoidPtr fPrivate;
};

#endif