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

#include <string.h>

#include <glib/gmem.h>
#include <glib/gmisc.h>

/**
 * g_strdup:
 * @str: (nullable): the string to duplicate
 *
 * Duplicates a string. If @str is %NULL it returns %NULL.
 * The returned string should be freed with g_free()
 * when no longer needed.
 *
 * Returns: a newly-allocated copy of @str
 */
gchar*
g_strdup (const gchar *str)
{
  gchar *new_str;
  gsize length;

  if (str)
    {
      length = strlen (str) + 1;
      new_str = g_new (char, length);
      memcpy (new_str, str, length);
    }
  else
    new_str = NULL;

  return new_str;
}

/**
 * g_memdup:
 * @mem: the memory to copy.
 * @byte_size: the number of bytes to copy.
 *
 * Allocates @byte_size bytes of memory, and copies @byte_size bytes into it
 * from @mem. If @mem is %NULL it returns %NULL.
 *
 * Returns: a pointer to the newly-allocated copy of the memory, or %NULL if @mem
 *  is %NULL.
 */
gpointer
g_memdup (gconstpointer mem,
          guint         byte_size)
{
  gpointer new_mem;

  if (mem)
    {
      new_mem = g_malloc (byte_size);
      memcpy (new_mem, mem, byte_size);
    }
  else
    new_mem = NULL;

  return new_mem;
}
