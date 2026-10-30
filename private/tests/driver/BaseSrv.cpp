// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#ifndef __KT_TEST_MAIN
#define __KT_TEST_MAIN AntMain
#endif

#include <KernelTest/headers/Foundation.h>
#include <KernelTest/headers/TestCase.h>

KT_DECL_TEST(MainBaseSrv, []{
  return YES;  
})

Void KT_TEST_MAIN() KT_RUN_TEST(MainBaseSrv)

// END
