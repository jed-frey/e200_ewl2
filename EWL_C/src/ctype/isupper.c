/* EWL
 * Copyright � 2011 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2012/06/01 15:47:27 $
 * $Revision: 1.1 $
 */

/*
 *	Routines
 *	--------
 *		isupper
 */
#include <ansi_parms.h>

#include <ewl_misra_types.h>

/* prevent inlining of ctype routines */
#ifdef _EWL_USE_INLINE
#undef _EWL_USE_INLINE
#endif
#define _EWL_USE_INLINE 0
#include <ctype.h>

/** The isupper function tests for any character that is an uppercase letter or is one of a
 *	locale-specific set of characters for which none of iscntrl, isdigit, ispunct, or
 *	isspace is true.
 *	In the "C" locale (or if _EMBEDDED_WARRIOR_CTYPE is on), isupper returns true only for
 *	the uppercase letters
 */

#if _EMBEDDED_WARRIOR_CTYPE

int_t _EWL_CDECL _EWL_CANT_THROW isupper(int_t c) {
int_t res;
	if ((uint_t)c > _MXC_) {
		c = -1;
	}
	res = (int_t)_EWL_CMAP_ACCESS[c+1] & _UC_;
	return res;
}

#else

int_t _EWL_CDECL _EWL_CANT_THROW isupper(int_t c) {
int_t res = 0;
	if ((uint_t)c < (uint_t)__ewl_cmap_size) {
		res = (int_t) (_EWL_CMAP_ACCESS[c] & __ewl_upper);
	}
	return res;
}

#endif /* _EMBEDDED_WARRIOR_CTYPE */
