/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __G_MISC_H__
#define __G_MISC_H__

#include <assert.h>
#include <stdlib.h>

#include <glib/gtypes.h>
#include <glib/gmacros.h>
#include <glib/gversionmacros.h>

#if defined(__GNUC__)
# define _g_alignof(type) (__alignof__ (type))
#else
# define _g_alignof(type) (G_STRUCT_OFFSET (struct { char a; type b; }, b))
#endif

GLIB_AVAILABLE_IN_ALL
gchar*   g_strdup (const gchar *str) G_GNUC_MALLOC;

GLIB_AVAILABLE_IN_ALL
gpointer g_memdup (gconstpointer mem,
                   guint         byte_size) G_GNUC_MALLOC G_GNUC_ALLOC_SIZE(2);

#define g_assert_cmpint(n1, cmp, n2)
#define g_assert(expr)

#define g_return_if_fail(expr)
#define g_return_val_if_fail(expr,val)

#define g_error(...) abort()
#define g_message(...)
#define g_critical(...)
#define g_warning(...)
#define g_info(...)
#define g_debug(...)

#endif
