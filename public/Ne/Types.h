// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#ifndef __NEAPP_OSTYPE_H__
#define __NEAPP_OSTYPE_H__

#include <Ne/OS.h>
#include <SystemKit/Macros.h>

/// @brief This file is useful for a set of standaridzed types for NeAnt/Ant distros.

typedef __UINT32_TYPE__   DWord;
typedef __UINT16_TYPE__ Word;

typedef __INT32_TYPE__   SDWord;
typedef __INT16_TYPE__ SWord;

typedef __PTRDIFF_TYPE__ PtrDiff;
typedef __PTRDIFF_TYPE__ Offset;

typedef DWord Status;

/// @brief a type code is used by a server to explain its status.
typedef DWord TypeCode;

typedef DWord status_type;
typedef DWord type_code_type;

typedef __UINTPTR_TYPE__ PhysAddr;
typedef __UINTPTR_TYPE__ VirtAddr;

#ifndef N_EMPTY_TEXT
#define N_EMPTY_TEXT ""
#endif

#endif