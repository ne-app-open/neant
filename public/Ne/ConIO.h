// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#ifndef __NEAPP_CONIO_H__
#define __NEAPP_CONIO_H__

#include <Ne/Types.h>

#ifndef _CONIO
#define _CONIO (202610)
#endif

IMPORT_C SInt32 printf(const Char*, ...);
IMPORT_C SInt32 scanf(const Char*, ...);

#ifdef NE_CONIO_COMPAT
#define N_CONIO_COMPAT NE_CONIO_COMPAT

IMPORT_C SInt32 cscanf(Char* fmt, ...);
IMPORT_C SInt32 getch(Void);
IMPORT_C SInt32 getche(Void);
IMPORT_C Char* cgets(Char* s);
IMPORT_C Void clrscr(Void);
IMPORT_C SInt32 cputs(const Char* s);
#endif

#ifdef NE_CLRSCR_SUPPORT
#define N_CLRSCR_SUPPORT NE_CLRSCR_SUPPORT

#undef clrscr
#define clrscr() _ROOT_NS printf("\e[1;1H\e[2J");
#endif

#endif
