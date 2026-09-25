// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#ifndef __NEAPP_CONIO_H__
#define __NEAPP_CONIO_H__

#include <Ne/Types.h>
#include <SystemKit/Macros.h>

#ifndef _CONIO
#define _CONIO (202610)
#endif

IMPORT_C int printf(const char*, ...);
IMPORT_C int scanf(const char*, ...);

#ifdef NE_CONIO_COMPAT
IMPORT_C int cscanf(char* fmt, ...);
IMPORT_C int getch(void);
IMPORT_C int getche(void);
IMPORT_C char* cgets(char* s);
IMPORT_C void clrscr(void);
IMPORT_C int cputs(const char* s);
#endif

#ifdef NE_CLRSCR_SUPPORT
#undef clrscr
#define clrscr() printf("\e[1;1H\e[2J");
#endif

#endif
