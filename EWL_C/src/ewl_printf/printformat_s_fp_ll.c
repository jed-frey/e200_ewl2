#define __pformatter __pformatter_sFPLL

#if !defined(__m56800E__) || __option(slld)
#define _EWL_FLOATING_POINT_PRINTF_SCANF 1
#define _EWL_C99 0
#define _EWL_LONGLONG_PRINTF_SCANF 1
#define _EWL_FLOATING_POINT 1

#include <stdio/__printformat.c>
#endif
