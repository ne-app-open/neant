// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-open/neant

#include <Ne/System/CAS.h>

/// @param sz size of block.
/// @param flags flags of block.
IMPORT_C VoidPtr CasAllocateHeap(SizeT sz, SInt32 flags) 
{ 
    if (!sz) ++sz;
    return MmCreateHeap(sz, flags); 
}

/// @brief Allocate heap block with additional parameter.
IMPORT_C VoidPtr CasAllocateHeapII(SizeT sz, SInt32 flags, SInt32 init) 
{
    if (!sz) ++sz;
    VoidPtr ptr = (VoidPtr)MmCreateHeap(sz, flags);
    
    if (ptr) MmFillMemory(ptr, init, sz);

    return ptr;
}

/// @brief Destroy heap block.
IMPORT_C Void CasDestroyHeap(_InOut VoidPtr ptr, SInt32 zero_out) 
{
    if (!ptr) return;
    MmDestroyHeap(ptr);
}

/// @param zero_out shall we zero-out the block after it being freed?
IMPORT_C Void CasDestroyHeapII(_InOut VoidPtr ptr, SInt32 zero_out, SizeT zero_out_len) 
{
    if (!ptr) return;
    
    if (ptr) MmFillMemory(ptr, zero_out, zero_out_len);
    MmDestroyHeap(ptr);
}
