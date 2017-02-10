### 一些排序算法

基本使用方法(仅供交流，切勿用于实际生产环境)

    typedef int Ord;
    #define lt(a,b) ((a)<(b)?1:0)
    #include "clib/data_structure/Sort/quikSort.h"
    // ...
    Ord a[MAXLEN];
    quickSort(a,length);

    // OR
    typedef int Ord;
    #define compare(a,b) ((a)-(b))
    #include "clib/type/Ord.h"
    #include "clib/data_structure/Sort/quikSort.h"
    // ...
    Ord a[MAXLEN];
    quickSort(a,length);


####参考资料
1. 数据结构(c语言版)，严蔚敏，吴伟民
1. 算法(第四版),Robert Sedgewick,Kevin Wayne
