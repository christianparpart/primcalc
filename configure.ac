# This file is part of the "primcalc" project, http://github.com/christianparpart/primcalc>
#   (c) 2009-2017 Christian Parpart <christian@parpart.family>
#
# Licensed under the MIT License (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of
# the License at: http://opensource.org/licenses/MIT

AC_PREREQ([2.69])
AC_INIT([primcalc], [0.0.1], [christian@parpart.family], [], [https://github.com/christianparpart/primcalc])
dnl AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([configure.ac])
dnl AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([foreign subdir-objects serial-tests])
AM_MAINTAINER_MODE([enable])
AM_SILENT_RULES([yes])

AC_LANG_CPLUSPLUS
AC_PROG_RANLIB
AC_PROG_CC
AC_PROG_CXX
#AC_PROG_CXX_FOR_BUILD
#AC_PROC_LIBTOOL
AM_PROG_AR
AM_PROG_AS
#LT_INIT
PKG_PROG_PKG_CONFIG([0.25])

AC_HEADER_STDC

AC_CHECK_HEADERS([unistd.h])
AC_CHECK_FUNCS([backtrace])

####### OUTPUT ################################################################

BASE_CXXFLAGS="-DXOPEN_SOURCE=600 -D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE \
 -D_LARGEFILE_SOURCE -D_LARGE_FILES -Wall -Wextra -std=c++1y \
 -Wno-unused-variable -Wno-unused-parameter"
AC_SUBST([BASE_CXXFLAGS])

AC_CONFIG_HEADERS(src/primcalc/sysconfig.h)
AC_CONFIG_FILES(Makefile)
AC_OUTPUT
