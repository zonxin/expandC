#ifndef __CLIB_DATA_STRUCTURE_SORT_MERGESORT_C__
#define __CLIB_DATA_STRUCTURE_SORT_MERGESORT_C__

#include <malloc.h>
#include <string.h>

// 将 a[lo..mid] a[mid+1..hi] 归并
int _merge_(Ord *a,Ord *aux,int lo,int mid,int hi)
{
    int i=lo,j=mid+1,k;
    memcpy(aux+lo,a+lo,sizeof(Ord)*(hi-lo+1));
    for(k=lo;i<=mid && j<=hi;k++) {
        if(lt(aux[i],aux[j])) { a[k] = aux[i++]; }
        else( a[k] = aux[j++] );
    }
    while(i<=mid){ a[k++] = aux[i++]; }
    while(j<=hi ){ a[k++] = aux[j++]; }
    return 0;
}
// 使用临时空间 aux 归并排序 a[lo..hi]
int _mergeSort_(Ord *a,Ord *aux,int lo,int hi)
{
    if(lo>=hi) { return 0; }
    int mid=(lo+hi)/2;
    _mergeSort_(a,aux,lo,mid);
    _mergeSort_(a,aux,mid+1,hi);
    _merge_(a,aux,lo,mid,hi);
    return 0;
}

int mergeSort(Ord *a,int n)
{
    Ord * aux;
    aux = (Ord *)malloc(sizeof(Ord)*n);
    _mergeSort_(a,aux,0,n-1);
    free(aux);
    return 0;
}

#endif
