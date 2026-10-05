// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-open/neant

.text

.extern ThrExitMainThread

.data

.global kThreadBlk

#ifndef BDLL_TB_VERSION
#define BDLL_TB_VERSION 0x003
#endif

#ifndef BDLL_TB_IDENT
#define BDLL_TB_IDENT 0x3445
#endif

#ifdef __x86_64__
.intel_syntax noprefix
kThreadBlkCanary:
    push rcx
    mov rcx, 0x0
    call ThrExitMainThread /* The exit routine if one program tries to runs the TB. */
    pop rcx
#endif
kThreadBlkStart:
kThreadBlk:
    .word BDLL_TB_IDENT
    .word BDLL_TB_VERSION /* version */
    .word 0x0 /* pad */
    .word 0x0 /* pad */
kThreadBlkEnd:
