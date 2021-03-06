/* EWL
 * Copyright � 1995-2007 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2013/04/15 14:14:19 $
 * $Revision: 1.1.2.1 $
 */

/*
 *	Routines
 *	--------
 *		wmemset
 */

#include <ansi_parms.h>
_MISRA_EXCEPTION_RULE_19_6()
#ifdef __STDC_WANT_LIB_EXT1__
/* enforce __STDC_WANT_LIB_EXT1__ support */
#undef __STDC_WANT_LIB_EXT1__
#endif
_MISRA_RESTORE()
#define __STDC_WANT_LIB_EXT1__ 1

#if _EWL_WIDE_CHAR

#include <ewl_misra_types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
wchar_t * _EWL_CDECL (wmemset)(wchar_t * dst, wchar_t val, size_t n)
{
	wchar_t *save = dst;

	while (n) {
		*dst++ = val;
		n--;
	}

	return(save);
}

#endif /* #if _EWL_WIDE_CHAR */

