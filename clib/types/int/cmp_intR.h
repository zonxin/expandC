#ifndef __CLIB_TYPES_INT_CMP_INTR_H__
#define __CLIB_TYPES_INT_CMP_INTR_H__

int cmp_intR(const void *a,const void *b) { return (*(int *)b) - (*(int *)a); }

#endif
