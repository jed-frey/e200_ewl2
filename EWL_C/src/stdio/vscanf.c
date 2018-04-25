/* EWL
 * Copyright � 1995-2007 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2013/04/15 14:12:42 $
 * $Revision: 1.1.2.1 $
 */

/*	Routines
 *	--------
 *		vscanf
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
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>
#include <critical_regions.h>

int_t _EWL_CDECL vscanf(const char_t * _EWL_RESTRICT format, va_list arg)
{
	int_t retval;

#if _EWL_C99_PRINTF_SCANF
#if _EWL_WIDE_CHAR
	if (fwide(stdin, -1) >= 0) {
		MISRA_EXCEPTION_RULE_14_7()
		return(EOF);
	}
#endif /* _EWL_WIDE_CHAR */
#endif /* _EWL_C99_PRINTF_SCANF */

  	__begin_critical_region(stdin_access);
	retval = __sformatter(__FileRead, (void *)stdin, format,  arg, 0);
  	__end_critical_region(stdin_access);

	return(retval);
}

