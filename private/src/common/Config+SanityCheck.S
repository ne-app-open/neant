/*
 SPDX-License-Identifier: Apache-2.0
 Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
 Licensed under the Apache License, Version 2.0 (see LICENSE file)
 Official repository: https://github.com/ne-app-eu/src
*/

.text

.extern ddk_sanity_check_init
.extern ddk_exit_driver_cleanup
.extern KDriverMain

.globl _kstart

#ifdef __x86_64__
.intel_syntax noprefix

_kstart:
    push rcx
    call ddk_sanity_check_init
    pop rcx
    xor rcx, rcx

    call KDriverMain
    call ddk_exit_driver_cleanup

_khang_ddk_runtime:
    cli
    jmp _khang_ddk_runtime

#endif
