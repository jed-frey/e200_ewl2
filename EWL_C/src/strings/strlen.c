/* EWL
 * Copyright � 1995-2007 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2013/04/15 14:13:41 $
 * $Revision: 1.1.2.1 $
 */

/*
 *	Routines
 *	--------
 *		strlen
 */

#include <ansi_parms.h>
_MISRA_EXCEPTION_RULE_19_6()
#ifdef __STDC_WANT_LIB_EXT1__
/* enforce __STDC_WANT_LIB_EXT1__ support */
#undef __STDC_WANT_LIB_EXT1__
#endif
_MISRA_RESTORE()
#define __STDC_WANT_LIB_EXT1__ 1

#include <ewl_misra_types.h>
#include <string.h>

MISRA_ALLOW_POINTER_CASTS()

#pragma warn_possunwant off

size_t (strlen)(const char_t * str)
{
	uchar_t * p = (uchar_t *) str - 1;

	while (*++p);

	return(p-(uchar_t *)str);
}

#pragma warn_possunwant reset
