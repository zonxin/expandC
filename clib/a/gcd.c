/* 球两个数的最大公约数 */

#ifndef __CLIB_A_GCD_C__
#define __CLIB_A_GCD_C__

#include "Math_max.h"
#include "Math_min.h"
typedef int GCDTYPE;
GCDTYPE GCD(GCDTYPE a,GCDTYPE b)
{
    GCDTYPE imax,imin,t;
    imax = max(a,b);
    imin = min(a,b);
    while(t = imax%imin) {
        imax = imin;
        imin = t;
    }
    return imin;
}

#endif
