/*
 * class Ord a where
 *    compare :: (a,a) -> Ordering
 *    lt,gt,le,ge :: (a,a) -> Boolean
 * */
#ifndef __CLIC_TYPES_ORD_H__
#define __CLIC_TYPES_ORD_H__

#include "../Boolean.h"
#define lt(a,b) (compare((a),(b))<0?True:False)
#define le(a,b) (compare((a),(b))<=0?True:False)
#define ge(a,b) (compare((a),(b))>=0?True:False)
#define gt(a,b) (compare((a),(b))>0?True:False)

#endif

