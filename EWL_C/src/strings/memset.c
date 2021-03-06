/* EWL
 * Copyright � 1995-2007 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2013/04/15 14:13:40 $
 * $Revision: 1.1.2.1 $
 */

/*
 *	Routines
 *	--------
 *		memset
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
#include <mem_funcs.h>


void * memset(void * dst, int_t val, size_t n)
{
	__fill_mem(dst, val, (uint32_t)n);

	return(dst);
}


