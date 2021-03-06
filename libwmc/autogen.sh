#!/bin/sh
# Run this to generate all the initial makefiles, etc.
# NOTE
# This autogen.sh is only used when building libwmc separately from ModemManager

srcdir=`dirname $0`
test -z "$srcdir" && srcdir=.
REQUIRED_AUTOMAKE_VERSION=1.7
PKG_NAME=libwmc

(test -f $srcdir/configure.ac \
  && test -f $srcdir/src/com.c) || {
    echo -n "**Error**: Directory "\`$srcdir\'" does not look like the"
    echo " top-level $PKG_NAME directory"
    exit 1
}

(cd $srcdir;
    autoreconf --install --symlink &&
    autoreconf &&
    ./configure --enable-maintainer-mode $@
)
