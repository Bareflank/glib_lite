# GLib Lite

[![GitHub version](https://badge.fury.io/gh/bareflank%2Fglib_lite.svg)](https://badge.fury.io/gh/bareflank%2Fglib_lite)
[![Build Status](https://travis-ci.org/Bareflank/glib_lite.svg?branch=master)](https://travis-ci.org/Bareflank/glib_lite)
[![Join the chat at https://gitter.im/Bareflank-hypervisor/Lobby](https://badges.gitter.im/Bareflank-hypervisor/Lobby.svg)](https://gitter.im/Bareflank-hypervisor/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## Description

This repo contains a lite version of glib that only contains ghash, glist,
gslist, gqueue and gmem. This was created to support [LibVMI](http://libvmi.com/)
on systems that cannot support a full GLib including the
[Bareflank Hypervisor](http://bareflank.github.io/hypervisor/), and Unikernels
like [IncludeOS](http://www.includeos.org/).

## Compilation / Usage

To compile, run make as usual. If you are cross compiling (as is the case
with both Bareflank and IncludeOS), you will need to set CC and AR.

```
make CC=<> AR=<>
make install prefix=<>
```

To clean

```
make clean
```

## License

This repo is licensed under the GNU Lesser General Public License
v2.1 (LGPL).
