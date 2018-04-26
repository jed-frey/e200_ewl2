/* EWL
 * Copyright � 1995-2009 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2012/06/01 15:39:38 $
 * $Revision: 1.1 $
 */

#ifndef _EWL_CPP_STD_MATH_H
#define _EWL_CPP_STD_MATH_H

#if defined(__cplusplus) && defined(_EWL_CMATH_DEFINED_MATH_ITEMS)

namespace std {

using ::acos;
using ::asin;
using ::atan;
using ::atan2;
using ::ceil;
using ::cos;
using ::cosh;
using ::exp;
using ::fabs;
using ::floor;
using ::fmod;
using ::frexp;
using ::ldexp;
using ::log;
using ::log10;
using ::modf;
using ::pow;
using ::sin;
using ::sinh;
using ::sqrt;
using ::tan;
using ::tanh;

#if _EWL_C99 || _EWL_C_HAS_CPP_EXTENSIONS
using ::acosf;
using ::acosl;
using ::asinf;
using ::asinl;
using ::atan2f;
using ::atan2l;
using ::atanf;
using ::atanl;
using ::ceilf;
using ::ceill;
using ::cosf;
using ::coshf;
using ::coshl;
using ::cosl;
using ::expf;
using ::expl;
using ::fabsf;
using ::fabsl;
using ::floorf;
using ::floorl;
using ::fmodf;
using ::fmodl;
using ::frexpf;
using ::frexpl;
using ::ldexpf;
using ::ldexpl;
using ::log10f;
using ::log10l;
using ::logf;
using ::logl;
using ::modff;
using ::modfl;
using ::powf;
using ::powl;
using ::sinf;
using ::sinhf;
using ::sinhl;
using ::sinl;
using ::sqrtf;
using ::sqrtl;
using ::tanf;
using ::tanhf;
using ::tanhl;
using ::tanl;
#endif /* _EWL_C99 || _EWL_C_HAS_CPP_EXTENSIONS */

#if _EWL_C99 || _EWL_USES_SUN_MATH_LIB
using ::copysign;
using ::expm1;
using ::rint;
using ::scalbn;
#endif /* _EWL_C99 || _EWL_USES_SUN_MATH_LIB */

#if _EWL_C99
using ::acosh;
using ::acoshf;
using ::acoshl;
using ::asinh;
using ::asinhf;
using ::asinhl;
using ::atanh;
using ::atanhf;
using ::atanhl;
using ::cbrt;
using ::cbrtf;
using ::cbrtl;
using ::copysignf;
using ::copysignl;
using ::erf;
using ::erfc;
using ::erfcf;
using ::erfcl;
using ::erff;
using ::erfl;
using ::exp2;
using ::exp2f;
using ::exp2l;
using ::expm1f;
using ::expm1l;
using ::fdim;
using ::fdimf;
using ::fdiml;
using ::fma;
using ::fmaf;
using ::fmal;
using ::fmax;
using ::fmaxf;
using ::fmaxl;
using ::fmin;
using ::fminf;
using ::fminl;
using ::hypot;
using ::hypotf;
using ::hypotl;
using ::ilogb;
using ::ilogbf;
using ::ilogbl;
using ::lgamma;
using ::lgammaf;
using ::lgammal;
#if _EWL_LONGLONG
using ::llrint;
using ::llrintf;
using ::llrintl;
using ::llround;
using ::llroundf;
using ::llroundl;
#endif /* _EWL_LONGLONG */
using ::log1p;
using ::log1pf;
using ::log1pl;
using ::log2;
using ::log2f;
using ::log2l;
using ::logb;
using ::logbf;
using ::logbl;
using ::lrint;
using ::lrintf;
using ::lrintl;
using ::lround;
using ::lroundf;
using ::lroundl;
using ::nan;
using ::nanf;
using ::nanl;
using ::nearbyint;
using ::nearbyintf;
using ::nearbyintl;
using ::nextafter;
using ::nextafterf;
using ::nextafterl;
using ::nexttoward;
using ::nexttowardf;
using ::nexttowardl;
using ::remainder;
using ::remainderf;
using ::remainderl;
using ::remquo;
using ::remquof;
using ::remquol;
using ::rintf;
using ::rintl;
using ::round;
using ::roundf;
using ::roundl;
using ::scalbln;
using ::scalblnf;
using ::scalblnl;
using ::scalbnf;
using ::scalbnl;
using ::tgamma;
using ::tgammaf;
using ::tgammal;
using ::trunc;
using ::truncf;
using ::truncl;

#if __dest_os != __mac_os_x
using ::abs;
using ::double_t;
using ::float_t;
#endif /* __dest_os != __mac_os_x */

#endif /* _EWL_C99 */

} /* namespace std */

#endif /* __cplusplus && _EWL_CMATH_DEFINED_MATH_ITEMS */

#endif /* _EWL_CPP_STD_MATH_H */
