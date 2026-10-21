// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app.
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-open/neant

#include <Ne/System/PAS.h>
#include <SystemKit/Syscall.h>

/// @param sz size of block.
/// @param flags flags of block.
IMPORT_C VoidPtr PasSbrk(SizeT sz, SInt32 flags)
{ 
    if (!sz) ++sz;
    return MmCreateHeap(sz, flags); 
}

/// @param zero_out shall we zero-out the block after it being freed?
IMPORT_C Void PasSbrkDestroy(VoidPtr ptr, SInt32 zero_out)
{
    if (!ptr) return;
    
    if (ptr) MmFillMemory(ptr, zero_out, sizeof(ptr));
    MmDestroyHeap(ptr);

    ptr = nullptr;
}

//// EOF
