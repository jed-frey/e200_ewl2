
/* @(#)k_cos.c 1.2 95/01/04 */
/* $Id: k_cos.c,v 1.1 2012/06/01 15:48:41 b11883 Exp $ */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
 * __kernel_cos( x,  y )
 * kernel cos function on [-pi/4, pi/4], pi/4 ~ 0.785398164
 * Input x is assumed to be bounded by ~pi/4 in magnitude.
 * Input y is the tail of x.
 *
 * Algorithm
 *	1. Since cos(-x) = cos(x), we need only to consider positive x.
 *	2. if x < 2^-27 (hx<0x3e400000 0), return 1 with inexact if x!=0.
 *	3. cos(x) is approximated by a polynomial of degree 14 on
 *	   [0,pi/4]
 *		  	                 4            14
 *	   	cos(x) ~ 1 - x*x/2 + C1*x + ... + C6*x
 *	   where the remez error is
 *
 * 	|              2     4     6     8     10    12     14 |     -58
 * 	|cos(x)-(1-.5*x +C1*x +C2*x +C3*x +C4*x +C5*x  +C6*x  )| <= 2
 * 	|    					               |
 *
 * 	               4     6     8     10    12     14
 *	4. let r = C1*x +C2*x +C3*x +C4*x +C5*x  +C6*x  , then
 *	       cos(x) = 1 - x*x/2 + r
 *	   since cos(x+y) ~ cos(x) - sin(x)*y
 *			  ~ cos(x) - x*y,
 *	   a correction term is necessary in cos(x) and hence
 *		cos(x+y) = 1 - (x*x/2 - (r - x*y))
 *	   For better accuracy when x > 0.3, let qx = |x|/4 with
 *	   the last 32 bits mask off, and if x > 0.78125, let qx = 0.28125.
 *	   Then
 *		cos(x+y) = (1-qx) - ((x*x/2-qx) - (r-x*y)).
 *	   Note that 1-qx and (x*x/2-qx) is EXACT here, and the
 *	   magnitude of the latter is at least a quarter of x*x/2,
 *	   thus, reducing the rounding error in the subtraction.
 */

#include <ansi_parms.h>

#if _EWL_FLOATING_POINT && _EWL_USES_SUN_DP_MATH_LIB

#include <fdlibm.h>

#ifdef __STDC__
static const f64_t
#else
static f64_t
#endif
one =  1.00000000000000000000e+00, /* 0x3FF00000, 0x00000000 */
C1  =  4.16666666666666019037e-02, /* 0x3FA55555, 0x5555554C */
C2  = -1.38888888888741095749e-03, /* 0xBF56C16C, 0x16C15177 */
C3  =  2.48015872894767294178e-05, /* 0x3EFA01A0, 0x19CB1590 */
C4  = -2.75573143513906633035e-07, /* 0xBE927E4F, 0x809C52AD */
C5  =  2.08757232129817482790e-09, /* 0x3E21EE9E, 0xBDB4B1C4 */
C6  = -1.13596475577881948265e-11; /* 0xBDA8FAE9, 0xBE8838D4 */

#ifdef __STDC__
	f64_t _EWL_MATH_CDECL __kernel_cos(f64_t x, f64_t y)
#else
	f64_t __kernel_cos(x, y)
	f64_t x,y;
#endif
{
	f64_t a,hz,z,r,qx;
	uint32_t ix;
	ix = GET_DOUBLE_UHI_WORD(x)&0x7fffffffUL;	/* ix = |x|'s high word*/
	if(ix<0x3e400000UL) {			/* if x < 2**27 */
	    if(((int32_t)x)==0L) {		/* generate inexact */
			MISRA_EXCEPTION_RULE_14_7()
			return one;
		}	
	}
	z  = x*x;
	r  = z*(C1+(z*(C2+(z*(C3+(z*(C4+(z*(C5+(z*C6))))))))));
	if(ix < 0x3FD33333UL) {			/* if |x| < 0.3 */
		MISRA_EXCEPTION_RULE_14_7()
	    return one - ((0.5*z) - ((z*r) - (x*y)));
	} else {
	    if(ix > 0x3fe90000UL) {		/* x > 0.78125 */
			qx = 0.28125;
	    } else {
	        GET_DOUBLE_UHI_WORD(qx) = ix-0x00200000UL;	/* x/4 */
	        GET_DOUBLE_LO_WORD(qx)  = 0L;
	    }
	    hz = (0.5*z)-qx;
	    a  = one-qx;
		MISRA_EXCEPTION_RULE_14_7()
	    return a - (hz - ((z*r)-(x*y)));
	}
}
#endif /* _EWL_FLOATING_POINT  */
