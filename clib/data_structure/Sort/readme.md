排序算法
=================

基本使用方法(仅供交流，切勿用于实际生产环境)

1. 选择排序
-------
首先从数组中找出最小的元素，将其放到数组的第一个位置，然后在其余的元素中找出最小的元素，然后将其放到数组的第二位置。依次往复，直到将整个数组排序。

2. 插入排序
-------
首先假设数组中只有第一个元素，含有一个元素的数组可以认为是有序的。然后将第二个元素插入到合适的位置，这样就可以把前两个元素排序了。然后将第三个元素插入到已经排序的前两个元素中，这样前三个元素的排序完成。依次往复，直到将整个数组排序。

3. 希尔排序
-------
插入排序每次比较只会将一个元素往前移动一个距离，所以对大规模的乱序数组进行插入排序会很慢。希尔排序的思想是使得数组中任意间隔为`h`的元素是有序的。如果`h`很大，一个元素就可以移动比较远的位置。当`h=1`的时候就是插入排序。排序刚开始的是我们会选择一个较大的`h`，然后逐渐将其减小为1，完成排序。

4. 归并排序
-------
归并的意思是将两个有序的数组合成一个更大的有序的数组，因此可以将数组分成两部分，然后将每一部分进行排序(归并排序)，然后将两部分排序的数据归并到一起就完成了排序。

5. 快速排序
------
选出数组中的一个元素称作切分元素，，将小于这个元素的值放在数组的左边，大于该元素的的值放在右边，切分元素放在他们之间。这样，切分元素就已经在合适的位置了，并且其左边的元素都小于等于该元素，其右边的元素都大于等于该元素。然后在递归的将左边的那些元素和右边的那些元素排序就可以了。

6. 堆排序
-----
这种方式类似于选择排序。只不过，[堆](../Heap)是一种特殊的数据结构，可以在堆中很快的找到其最大（最小）的元素。因此可以使用要排序的数组创建一个堆，然后从堆中快的找到最大的元素，将其放到数组的最后。然后找到剩余元素中最大的元素，放到倒数第二个位置。依次往复，完成排序。

7. 三向切分快速排序
---- 
如果在元素中要排序的元素中有很多相等的元素，快速排序可以做的更好。同样是，选择一个元素，将小于该元素的放到数组的左边，等于的放到中间，大于的放到右边，然后在递归的排序左边和右边的元素就可以了。与快速排序不同的是，在快速排序中左边和右边有可能会有跟此元素相同的元素，所以在排序左边（右边）的时候依旧需要重新处理这部分元素。但是在当前排序的时候我们已经可以确定这些与切分元素相等元素排序后的位置了（与切分元素排序后的位置相邻），故没有必要再处理一次。

8. 使用示例
-------
```C
int SORTFUNC(Ord *a,int length); // 排序算法原型
// a 要排序的数组
// length 数组长度
```
排序中使用函数`lt`比较两个元素的大小对`Ord`类型的数组进行升序排列。如果要降序排序，改变一下`lt`的返回值就可以了。
```C
#define Ord int
#define lt(a,b) ((a)<(b)?1:0)
#include "clib/data_structure/Sort/quickSort.h"
// ...
Ord a[MAXLEN];
quickSort(a,length);  // 升序
#undef lt
#undef Ord

#define Ord char
#define lt(a,b) ((a)>(b)?1:0)
#include "clib/data_structure/Sort/heapSort.h"
Ord b[MAXLEN];
// ...
heapSort(b,length); // 降序
```

#### 具体代码

1. [选择排序](selectionSort.c)
1. [插入排序](insectionSort.c)
1. [希尔排序](shellSort.c)
1. [归并排序](mergeSort.c)
1. [快速排序](quickSort.c)
1. [三向切分快速排序](quick3waySort.c)
1. [堆排序](heapSort.c)




