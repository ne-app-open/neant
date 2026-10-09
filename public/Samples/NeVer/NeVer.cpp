// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#define NE_CLRSCR_SUPPORT
#include <Ne/ConIO.h>

int main(int, char**) {
  clrscr();
  _ROOT_NS execute("/mnt/c/commonver", 0LL, nullptr);
  
  return EXIT_SUCCESS;
}
