#ifndef __CLIB_DATA_STRUCTURE_SWP_C__
#define __CLIB_DATA_STRUCTURE_SWP_C__

#include <stddef.h>
void swp(void *a,void *b,size_t width)
{
    char *ca = (char *)a;
    char *cb = (char *)b;
    char tmp;
    if( a!=b ){
        while(width--) {
            tmp = *ca;
            *ca++ = *cb;
            *cb++ = tmp;
        }
    }
}

#endif
