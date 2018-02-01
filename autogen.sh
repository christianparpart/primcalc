#! /bin/sh
# This file is part of the "primcalc" project, http://github.com/christianparpart/primcalc>
#   (c) 2009-2017 Christian Parpart <christian@parpart.family>
#
# Licensed under the MIT License (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of
# the License at: http://opensource.org/licenses/MIT

set -e

BUILDDIR=`pwd`
ROOT=`dirname $0`

FILES="
  /ar-lib
  /aclocal.m4
  /compile
  /autom4te.cache
  /configure
  /install-sh
  /missing
  /depcomp
"

if test "$1" = "clean"; then
  find $ROOT -name Makefile.in -exec rm {} \;
  for file in $FILES; do rm -vrf "$ROOT$file"; done
  exit 0
fi

findexe() {
  for exe in $@; do
    if which $exe 2>/dev/null; then
      return
    fi
  done
  echo $1
}

# Mac OSX has a special location for more recent LLVM/clang installations
#   $ brew tap homebrew/versions
#   $ brew install llvm
if [ -d "/usr/local/opt/llvm/bin" ]; then
  export PATH="/usr/local/opt/llvm/bin:$PATH"
  export CXXFLAGS="$CXXFLAGS -nostdinc++ -I/usr/local/opt/llvm/include/c++/v1"
  export LDFLAGS="$LDFLAGS -L/usr/local/opt/llvm/lib"
fi

autoreconf --verbose --force --install $ROOT

exec $ROOT/configure --prefix="$HOME/usr" "$@"
