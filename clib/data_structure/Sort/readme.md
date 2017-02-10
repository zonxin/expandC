### 排序算法

1. [选择排序](selectionSort.c)
1. [插入排序](insectionSort.c)
1. [希尔排序](shellSort.c)
1. [归并排序](mergeSort.c)
1. [快速排序](quickSort.c)
1. [三向切分快速排序](quick3waySort.c)
1. [堆排序](heapSort.c)

基本使用方法(仅供交流，切勿用于实际生产环境)

    typedef int Ord;
    #define lt(a,b) ((a)<(b)?1:0)
    #include "clib/data_structure/Sort/quickSort.h"
    // ...
    Ord a[MAXLEN];
    quickSort(a,length);

    // OR
    typedef int Ord;
    #define compare(a,b) ((a)-(b))
    #include "clib/type/Ord.h"
    #include "clib/data_structure/Sort/quikcSort.h"
    // ...
    Ord a[MAXLEN];
    quickSort(a,length);


####参考资料
1. 数据结构(c语言版)，严蔚敏，吴伟民
1. 算法(第四版),Robert Sedgewick,Kevin Wayne
