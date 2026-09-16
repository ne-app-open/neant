// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss and Ne.app (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <DbgKit/Dbg.h>

#ifndef kDbgHostServiceLoopName
#define kDbgHostServiceLoopName "_DbgHostServiceLoop"
#endif

#ifndef kDbgHostTrapOffset
#define kDbgHostTrapOffset 8
#endif

#ifdef __x86_64__
_SHARED ATTRIBUTE(naked)
Void    dbgi_trap_hang(Void) {
  asm __volatile("__dbgi_trap_hang_loop: jmp __dbgi_trap_hang_loop;");
}
_SHARED ATTRIBUTE(naked)
SInt32  dbgi_trap_break(Void) {
  asm __volatile("ret");
}
#else
#warning !! Trap breaks are undefined !!
#endif

enum {
  DBG_VKEY_BREAK,
  DBG_VKEY_HANG,
};

SInt32 main(SInt32 argc, Char** argv) {
  LIBSYS_UNUSED(argc);
  LIBSYS_UNUSED(argv);

  PrintOut(nullptr, "%s",
           "Ne.app Debug Host Service, Copyright 2026 Ne.app, all rights reserved.\r");

  kDbgHost = (struct DBG_HOST*) MmCreateHeap(sizeof(struct DBG_HOST), 0);

#ifdef _DEBUG
  MUST_PASS(kDbgHost);
#endif

  if (!kDbgHost) return kDbgSignal;

  while (kDbgHostEnabled) {
    if (kDbgHost && kDbgHost->fDbgSocket == kNeInvalidDbgSocket) break;
    volatile UInt64* ret = (volatile UInt64*) nesys_syscall_arg_1(nesys_hash_64(kDbgHostServiceLoopName));

    if (ret && *ret > 0) {
      if (*ret == DBG_VKEY_BREAK) {
        *(ret + kDbgHostTrapOffset) = (UInt64) dbgi_trap_hang;
      } else if (*ret == DBG_VKEY_BREAK) {
        *(ret + kDbgHostTrapOffset) = (UInt64) dbgi_trap_break;
      }
    }
  }

  if (kDbgHost != nullptr) {
    MmDestroyHeap(kDbgHost);
    kDbgHost = nullptr;
  }

  return kDbgSignal;
}
