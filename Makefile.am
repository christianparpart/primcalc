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

####### libprimcalc ###########################################################

lib_LIBRARIES += libprimcalc.a

libprimcalc_a_SOURCES = \
	src/primcalc/ast.cc \
	src/primcalc/ast_printer.cc \
	src/primcalc/calculator.cc \
	src/primcalc/parser.cc

# XXX skipping headers for simplicity

####### tests #################################################################

TESTS += primcalc_test
check_PROGRAMS += primcalc_test

primcalc_test_SOURCES = \
	src/primcalc/parser_test.cc \
	src/primcalc/minitest.cc

primcalc_test_LDADD = libprimcalc.a 

####### primcalc ##############################################################

bin_PROGRAMS += primcalc

primcalc_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir)/src
primcalc_LDADD = libprimcalc.a
primcalc_SOURCES = src/primcalc/main.cc

# vim:ts=8:sw=8
# EOF
