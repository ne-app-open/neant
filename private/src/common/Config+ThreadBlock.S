/*
 SPDX-License-Identifier: Apache-2.0
 Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
 Licensed under the Apache License, Version 2.0 (see LICENSE file)
 Official repository: https://github.com/ne-app-eu/src
*/

/* AUTHOR: Amlal El Mahrouss */

.text

.extern ddk_exit_driver_cleanup

.data

.global kThreadBlk

#ifndef TB_VERSION
#define TB_VERSION 0x001
#endif

#ifndef TB_IDENT
#define TB_IDENT 0x34546484
#endif

#ifdef __x86_64__
.intel_syntax noprefix
kThreadBlkCanary:
    push rcx
    call ddk_exit_driver_cleanup /* The exit routine if one program tries to runs the TB. */
    pop rcx
#endif
kThreadBlkStart:
kThreadBlk:
    .word TB_IDENT
    .word TB_VERSION /* version */
    .word 0x0 /* pad */
    .word 0x0 /* pad */
kThreadBlkEnd:
    