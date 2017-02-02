#!/bin/bash -e
#
# Bareflank Hypervisor
#
# Copyright (C) 2015 Assured Information Security, Inc.
# Author: Rian Quinn        <quinnr@ainfosec.com>
# Author: Brendan Kerrigan  <kerriganb@ainfosec.com>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

rm -Rf libglib_lite.a
rm -Rf *.o

$CC $CFLAGS -fpic -D__GLIB_H_INSIDE__ -c -I../ -I. gmisc.c
$CC $CFLAGS -fpic -D__GLIB_H_INSIDE__ -c -I../ -I. ghash.c
$CC $CFLAGS -fpic -D__GLIB_H_INSIDE__ -c -I../ -I. glist.c
$CC $CFLAGS -fpic -D__GLIB_H_INSIDE__ -c -I../ -I. gslist.c
$CC $CFLAGS -fpic -D__GLIB_H_INSIDE__ -c -I../ -I. gqueue.c
$CC $CFLAGS -fpic -D__GLIB_H_INSIDE__ -c -I../ -I. gmem.c
$CC $CFLAGS -fpic -D__GLIB_H_INSIDE__ -c -I../ -I. gnode.c
$CC $CFLAGS -fpic -D__GLIB_H_INSIDE__ -c -I../ -I. -Wno-int-conversion gatomic.c
$AR rcs libglib_lite.a gmisc.o ghash.o glist.o gslist.o gqueue.o gmem.o gnode.o gatomic.o

mkdir -p ~/hypervisor/sysroot_vmapp/x86_64-elf/include/glib/

cp ../glib.h ~/hypervisor/sysroot_vmapp/x86_64-elf/include/
cp *.h ~/hypervisor/sysroot_vmapp/x86_64-elf/include/glib/
cp libglib_lite.a ~/hypervisor/sysroot_vmapp/x86_64-elf/lib/
