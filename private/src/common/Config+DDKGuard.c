// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <stdbool.h>
#include <Ne/Drivers/DDS.h>

/// @note This file was designed to compile with Ant as well.

/// @brief This variable shall not be non-zeo.
DDK_EXTERN int32_t ddk_kernel_canary__;

/// @brief Does a sanity check.
DDK_EXTERN void ddk_sanity_check_init(void) {
    ddk_kernel_canary__ = 0;
}

DDK_EXTERN bool ddk_sanity_check(void) {
    return ddk_kernel_canary__ == 0;
}

/// @brief Does enable the DDK guard when calling in a stack frame.
DDK_EXTERN void ddk_guard_zone(struct ddk_guard_type* g) {
#ifdef __NEOSKRNL__
    if (!g) ke_call_dispatch("KeRuntimeCheck", 1, g, sizeof(struct ddk_guard_type));
#else
    if (!g) ke_call_dispatch("RtlKeRuntimeCheck", 1, g, sizeof(struct ddk_guard_type));
#endif

    while (g->e_ != NULL && *g->e_);

    int32_t* e ATTRIBUTE(cleanup(ddk_cleanup_zone)) = (int32_t*)kalloc(sizeof(int32_t));
    
    g->e_ = e;
    *g->e_ = YES;
}

DDK_EXTERN void ddk_cleanup_zone(int32_t** e) {
    if (!e || !*e) return;
    **e = NO;

    kfree(*e);
    *e = NULL;
}
