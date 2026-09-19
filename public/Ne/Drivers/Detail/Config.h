// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#ifndef _NE_DDK_CONFIG_H_
#define _NE_DDK_CONFIG_H_

#include <DriverKit/DriverKit.h>
#include <SystemKit/Macros.h>

#define _ARCH __ne_arch

#define _SUBSYSTEM_NET 0x1000
#define _SUBSYSTEM_DDK 0x1000
#define _SUBSYSTEM_SYS 0x1000

#ifndef _NEKERNEL
#define _NEKERNEL 202609L
#endif

#ifndef _COMMONCORE
#define _COMMONCORE 202609L
#endif

#ifndef CLEANUP
#define CLEANUP __cleanup__
#endif

#ifndef __cleanup
#define __cleanup(x) unused
#endif

struct ddk_guard_type _FINAL {
    int32_t* e_;
};

DDK_EXTERN void ddk_cleanup_zone(int32_t**);

/// @brief Does enable the DDK guard when calling in a stack frame.
DDK_EXTERN void ddk_guard_zone(struct ddk_guard_type*);

/// @brief Does a sanity check for the DDK driver.
DDK_EXTERN bool ddk_sanity_check(void);

/// @brief Initializes the sanity check variable.
DDK_EXTERN void ddk_sanity_check_init(void);

#endif
