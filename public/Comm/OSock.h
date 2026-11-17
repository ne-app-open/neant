// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app.
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#pragma once

#ifndef _OPENSOCKET_API
#define _OPENSOCKET_API 202611
#endif

/// @author Amlal El Mahrouss
/// @brief OpenSocket Specification Implementation.

#include <Ne/OS.h>
#include <Ne/System/CAS.h>

///////////////////////////////////////////////////////////////////////////////////////////

/// @brief A socket in OpenSocket is capable of handling a single connection request.
typedef VoidPtr OpenSocketT;

/// @brief A multiplexer is capable of handling multiple connection requests at once.
typedef VoidPtr MultiplexerT;

///////////////////////////////////////////////////////////////////////////////////////////

// EOF
