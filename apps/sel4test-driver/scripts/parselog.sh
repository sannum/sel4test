#!/bin/sh
#
# Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
#
# SPDX-License-Identifier: BSD-2-Clause
#

exec ./clean-log.sh "$@" | ./match-data.pl | ./generate-spread.pl
