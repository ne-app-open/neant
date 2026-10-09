// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#ifndef _NE_CORE_SUBSYSTEM_H_
#define _NE_CORE_SUBSYSTEM_H_

#ifndef _CAS
#define _CAS (202608L)
#endif

#include <Ne/System/Detail/Config.h>

/// *******************************************************
/// @brief Common Application Subsystem.
/// @note The CAS is a user subsystem abstracting away system calls as well for performance reasons.
/// *******************************************************

#ifndef CasCreateEvent
#define CasCreateEvent(event_name, listener) EvtAddListener(event_name, listener)
#endif

#ifndef CasRemoveEvent
#define CasRemoveEvent(event_name, listener) EvtRemoveListener(event_name, listener)
#endif

#ifndef CasDispatchEvent
#define CasDispatchEvent(event_name, event_data) EvtDispatchEvent(event_name, event_data)
#endif

/// @param sz size of block.
/// @param flags flags of block.
IMPORT_C VoidPtr CasAllocateHeap(SizeT sz, SInt32 flags);

/// @brief Allocate heap block with additional parameter.
IMPORT_C VoidPtr CasAllocateHeapII(SizeT sz, SInt32 flags, SInt32);

/// @brief Destroy heap block.
IMPORT_C Void CasDestroyHeap(_InOut VoidPtr, SInt32 zero_out);

/// @param zero_out shall we zero-out the block after it being freed?
IMPORT_C Void CasDestroyHeapII(_InOut VoidPtr, SInt32 zero_out, SizeT zero_out_len);

#endif // _NE_CORE_SUBSYSTEM_H_
