// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#define __KT_TEST_MAIN AntMain

#include <KernelTest/headers/Foundation.h>
#include <KernelTest/headers/TestCase.h>

KT_DECL_TEST(MainDbgHost, []{
  return YES;  
})

Void KT_TEST_MAIN() KT_RUN_TEST(MainDbgHost)
