/* ========================================================================= **
**                                         ____                              **
**                       ____  _________ _/ __/_______                       **
**                      / __ \/ ___/ __ `/ /_/ ___/ _ \                      **
**                     / /_/ / /  / /_/ / __/ /__/  __/                      **
**                     \____/_/   \__,_/_/  \___/\___/                       **
**                                                                           **
** ========================================================================= **
**                              KEYWORD ACCESS                               **
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

#include "postgres.h"

#include "parse_keyword.h"

#include "parser/gramparse.h"

#if PG_VERSION_NUM >= 90600

#include "common/keywords.h"

#else

#include "parser/keywords.h"

#endif

#if PG_VERSION_NUM >= 120000

#define PG_KEYWORD(kwname, value, category)    value,

const uint16 ScanKeywordTokens[] =
{
#include "parser/kwlist.h"
};

#undef PG_KEYWORD

const char *
orafce_scan_keyword (
  const char *text,
  int        *keycode
) {
  int kwnum;

  kwnum = ScanKeywordLookup(text, &ScanKeywords);
  if (kwnum >= 0) {
    *keycode = ScanKeywordTokens[kwnum];
    return (GetScanKeyword(kwnum, &ScanKeywords));
  }

  return (NULL);
} /* orafce_scan_keyword() */

/* ------------------------------------------------------------------------- */

#else

const char *
orafce_scan_keyword (
  const char *text,
  int        *keycode
) {
  const ScanKeyword *keyword;

  keyword = ScanKeywordLookup(text, ScanKeywords, NumScanKeywords);
  if (keyword) {
    *keycode = keyword->value;
    return (keyword->name);
  }

  return (NULL);
} /* orafce_scan_keyword() */

#endif

/* :vi set ts=2 et sw=2: */

