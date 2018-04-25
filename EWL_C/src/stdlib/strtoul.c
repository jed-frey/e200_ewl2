/* EWL
 * Copyright � 1995-2007 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2013/04/15 14:13:24 $
 * $Revision: 1.1.2.1 $
 */

/*
 *	Routines
 *	--------
 *
 *
 */

#include <ansi_parms.h>

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <ewl_misra_types.h>
MISRA_EXCEPTION_RULE_20_9()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <strtoul_api.h>

uint32_t _EWL_CDECL strtoul(const char_t * _EWL_RESTRICT str, char_t ** _EWL_RESTRICT end, int_t base)
{
	uint32_t	value;
	int_t		count, negative, overflow;
	__InStrCtrl isc;

	isc.NextChar         = (char_t *)str;
	isc.NullCharDetected = 0;

	value = __strtoul(base, INT_MAX, __StringRead, (void *)&isc, &count, &negative, &overflow);

	if (end) {
		*end = (char_t *) str + count;
	}

	if (overflow) {
#if _EWL_LONGLONG
		value = (uint64_t)ULONG_MAX;
#else
		value = ULONG_MAX;
#endif
		MISRA_EXCEPTION_RULE_20_5()
		errno = ERANGE;
	} else {
		if (negative) {
			MISRA_EXCEPTION_RULE_10_3()			
			if (value != 0x80000000UL) {
#if _EWL_LONGLONG
				value = (uint64_t)-(int64_t)value;
#else
				value = -value;
#endif
			} 
		}
	}

	return(value);
}
