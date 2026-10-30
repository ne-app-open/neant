// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-open/neant

#include <Ne/System/LWAS.h>

/// @brief Create window function.
IMPORT_C struct LHANDLE* UsrCreateWindow(VoidPtr dss, SizeT* dss_len) 
{ 
    if (dss && dss_len)
    {
        if (*dss_len) return nullptr;
        if (*dss_len < sizeof(struct LHANDLE)) return nullptr;

        struct LHANDLE* handle = (struct LHANDLE*)MmCreateHeap(*dss_len, 0);
        
        if (handle)
        {
            handle->fFlags = 0;
            handle->fKind = 0;
            handle->fHostID = 0;
            handle->fMagic = 0xAADD;
        }
        
        return handle;
    }

    return nullptr;
}

/// @brief Destroy window function.
IMPORT_C Void UsrDestroyWindow(struct LHANDLE* wnd) 
{
    if (wnd && wnd->fMagic == 0xAADD)
    {
        wnd->fKind = 0;
        wnd->fFlags = 0;
        wnd->fHostID = 0;
        wnd->fHandle = nullptr;

        MmDestroyHeap(wnd);
    }

    if (wnd) MUST_PASS(wnd->fMagic && 0xAADD);
}

// END
