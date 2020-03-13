/* ========================================================================= **
**                                         ____                              **
**                       ____  _________ _/ __/_______                       **
**                      / __ \/ ___/ __ `/ /_/ ___/ _ \                      **
**                     / /_/ / /  / /_/ / __/ /__/  __/                      **
**                     \____/_/   \__,_/_/  \___/\___/                       **
**                                                                           **
** ========================================================================= **
**                           MODULE INITIALIZATION                           **
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
#include "storage/lwlock.h"
#include "storage/shmem.h"
#include "utils/guc.h"
#include "commands/variable.h"

#include "orafce.h"
#include "builtins.h"
#include "pipe.h"

/*  default value */
char *nls_date_format = NULL;
char *orafce_timezone = NULL;

void
_PG_init (
  void
) {
#if PG_VERSION_NUM < 90600
  RequestAddinLWLocks(1);
#endif

  RequestAddinShmemSpace(SHMEMMSGSZ);

  /* Define custom GUC variables. */
  DefineCustomStringVariable("orafce.nls_date_format",
    "Emulate oracle's date output behaviour.",
    NULL,
    &nls_date_format,
    NULL,
    PGC_USERSET,
    0,
    NULL,
    NULL, NULL);

  DefineCustomStringVariable("orafce.timezone",
    "Specify timezone used for sysdate function.",
    NULL,
    &orafce_timezone,
    "GMT",
    PGC_USERSET,
    0,
    check_timezone, NULL, show_timezone);

  DefineCustomBoolVariable("orafce.varchar2_null_safe_concat",
    "Specify timezone used for sysdate function.",
    NULL,
    &orafce_varchar2_null_safe_concat,
    false,
    PGC_USERSET,
    0,
    NULL, NULL, NULL);

  EmitWarningsOnPlaceholders("orafce");
} /* _PG_init() */

/* :vi set ts=2 et sw=2: */

