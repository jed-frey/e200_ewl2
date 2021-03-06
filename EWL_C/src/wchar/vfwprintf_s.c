/* EWL
 * Copyright � 1995-2007 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2013/04/15 14:14:16 $
 * $Revision: 1.1.2.1 $
 */

/*
 *	Routines
 *	--------
 *		fwprintf
 *		fwprintf_s
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
#if _EWL_C99

#include <ewl_misra_types.h>
#include <critical_regions.h>
#include <wctype.h>
#include <stdarg.h>
#include <stddef.h>
MISRA_EXCEPTION_RULE_20_9()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#if _EWL_C99_PRINTF_SCANF
#if _EWL_FLOATING_POINT_PRINTF_SCANF
	#include <ansi_fp.h>
	#include <float.h>
	#include <lconv.h>
	#include <limits.h>
	#include <locale.h>
#endif /* _EWL_FLOATING_POINT_PRINTF_SCANF */
#endif /* _EWL_C99_PRINTF_SCANF */

MISRA_ALLOW_POINTER_CASTS()

#ifndef __CWCC__
	#define _EWL_COMPILE_FOR_SPEED 1
#else
	#if __option(optimize_for_size)
		#define _EWL_COMPILE_FOR_SPEED 0
	#else
		#define _EWL_COMPILE_FOR_SPEED 1
	#endif
#endif /* __CWCC__ */

int_t __wpformatter(
			void *(_EWL_CDECL *wWriteProc)(void *a, const wchar_t *b, size_t c),
			void * WriteProcArg,
			const wchar_t * format_str,
			va_list arg,
			int_t is_secure);
void * _EWL_CDECL __wFileWrite(void *File, const wchar_t * Buffer, size_t NumChars);

int_t _EWL_CDECL vfwprintf_s(FILE * _EWL_RESTRICT file, const wchar_t * _EWL_RESTRICT format, va_list arg)
{
	int_t retval;
	MISRA_QUIET_UNUSED_SYMBOL()
	critical_regions crtrgn;

	if ((file == NULL) || (format == NULL))
	{
		__ewl_runtime_constraint_violation_s(NULL, NULL, -1);
		MISRA_EXCEPTION_RULE_14_7()
		return -1;
	}
	if (fwide(file, 1) <= 0) {
		MISRA_EXCEPTION_RULE_14_7()
		return(-1);
    }
	if (file == stdout) {
		crtrgn = stdout_access;
	} else if (file == stderr) {
		crtrgn = stderr_access;
	} else {
		crtrgn = files_access;
	}
  	__begin_critical_region(crtrgn);
	retval = __wpformatter(__wFileWrite, (void *)file, format, arg, 1);
  	__end_critical_region(crtrgn);
	return(retval);
}


#endif /* _EWL_C99 */
#endif /* _EWL_WIDE_CHAR */

