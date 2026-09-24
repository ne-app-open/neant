# SPDX-License-Identifier: Apache-2.0
# Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
# Licensed under the Apache License, Version 2.0 (see LICENSE file)
# Official repository: https://github.com/ne-app-eu/src

.PHONY: all
all: clean
	g++ -I../../ -I../../../../nekrnl/private/libSystem -I../../../../nekrnl/private/ \
	-fPIE -std=c++20 Printf.cpp

.PHONY: clean
clean:
	rm a.out