# This file is part of the "primcalc" project, http://github.com/christianparpart/primcalc>
#   (c) 2009-2017 Christian Parpart <christian@parpart.family>
#
# Licensed under the MIT License (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of
# the License at: http://opensource.org/licenses/MIT

EXTRA_DIST = autogen.sh
bin_PROGRAMS =
lib_LIBRARIES =
noinst_LIBRARIES =
check_PROGRAMS =
TESTS =

####### compile opts ##########################################################

AM_CXXFLAGS = \
	$(BASE_CXXFLAGS) \
	-I$(top_builddir)/src \
	-I$(top_srcdir)/src

AM_LDFLAGS = \
	-lpthread

# ####### libXzeroTesting_main.a ################################################
# 
# lib_LIBRARIES += libXzeroTesting_main.a
# libXzeroTesting_main_a_SOURCES = src/xzero/testing_main.cc

####### primcalc ###################################################################

bin_PROGRAMS += primcalc

primcalc_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	-I$(top_srcdir)/src

primcalc_LDADD = \
	$(AM_LDFLAGS)

# primcalc_LDFLAGS += -static -static-libgcc -static-libstdc++

primcalc_SOURCES = \
	src/primcalc/ast.cc \
	src/primcalc/ast_printer.cc \
	src/primcalc/calculator.cc \
	src/primcalc/parser.cc \
	src/primcalc/main.cc

# vim:ts=8
# EOF
