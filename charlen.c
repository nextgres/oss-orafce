/* ========================================================================= **
**                                         ____                              **
**                       ____  _________ _/ __/_______                       **
**                      / __ \/ ___/ __ `/ /_/ ___/ _ \                      **
**                     / /_/ / /  / /_/ / __/ /__/  __/                      **
**                     \____/_/   \__,_/_/  \___/\___/                       **
**                                                                           **
** ========================================================================= **
**    OPEN-SOURCE IMPLEMENTATION OF ORACLE DATABASE TEXT LENGTH FUNCTIONS    **
** ========================================================================= **
** Copyright (C) 2008-2020 by Pavel Stehule <pavel.stehule@gmail.com>        **
** Portions Copyright (C) 1999-2014 Jonah H. Harris <jonah.harris@gmail.com> **
** Portions Copyright (C) 2014-2020 NEXTGRES, LLC. <oss@nextgres.com>        **
**                                                                           **
** Permission to use, copy, modify, and/or distribute this software for any  **
** purpose with or without fee is hereby granted.                            **
**                                                                           **
** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  **
** WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF          **
** MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR   **
** ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    **
** WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN     **
** ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF   **
** OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.            **
** ========================================================================= */

/*
 * charlen.c
 *
 * provides a modified version of bpcharlen() that does not
 * ignore trailing spaces of CHAR arguments to provide an
 * Oracle compatible length() function
 */

#include "postgres.h"

#include "utils/builtins.h"
#include "access/hash.h"
#include "libpq/pqformat.h"
#include "nodes/nodeFuncs.h"
#include "utils/array.h"
#include "utils/formatting.h"
#include "mb/pg_wchar.h"
#include "fmgr.h"

#include "orafce.h"
#include "builtins.h"

PG_FUNCTION_INFO_V1(orafce_bpcharlen);

Datum
orafce_bpcharlen (
  PG_FUNCTION_ARGS
) {
  BpChar *arg = PG_GETARG_BPCHAR_PP(0);
  int len;

  /* byte-length of the argument (trailing spaces not ignored) */
  len = VARSIZE_ANY_EXHDR(arg);

  /* in multibyte encoding, convert to number of characters */
  if (pg_database_encoding_max_length() != 1) {
    len = pg_mbstrlen_with_len(VARDATA_ANY(arg), len);
  }

  PG_RETURN_INT32(len);
} /* orafce_bpcharlen() */

/* :vi set ts=2 et sw=2: */

