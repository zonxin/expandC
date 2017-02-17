# 优先队列

**优先队列**是支持访问其中的最大元素或是最小元素的可数据类型。

## 堆(heap)

> 如果一棵二叉树其中的每个结点都大于等于它的两个子节点的时，它被称为堆有序的。

因此，树顶是其中最大的元素。当需要获取最大的元素的时候可以直接返回树顶的元素。
当删除或是插入元素的时候需要重新调整树中的数据，使其仍旧可以满足堆的定义。幸运的是无论是插入还是删除，其时间复杂度都是`Log(N)`


### 基本接口
```C
/* 小顶堆 */
// #define char Ord
// #define gt(a,b) ((a)>(b)?1:0)
MinPQ newMinPQ(int n);
Ord MinPQ_delMin(MinPQ pq);
int MinPQ_insert(MinPQ pq,Ord v);

/* 大顶堆 */
// #define char Ord
// #define lt(a,b) ((a)<(b)?1:0)
MaxPQ newMaxPQ(int n);
Ord MaxPQ_delMax(MaxPQ pq);
int MaxPQ_insert(MaxPQ pq,Ord v);

/* 小顶堆索引堆 */
// #define char Ord
// #define gt(a,b) ((a)>(b)?1:0)
IndexMinPQ newIndexMinPQ(int n)
void freeIndexMinPQ(IndexMinPQ p)
int  IndexMinPQ_insert(IndexMinPQ p,int k,Ord v);
Ord  IndexMinPQ_min(IndexMinPQ p);
int  IndexMinPQ_delMin(IndexMinPQ p);
Bool IndexMinPQ_contains(IndexMaxPQ p,int k);
int  IndexMinPQ_minIndex(IndexMaxPQ p);
int  IndexMinPQ_change(IndexMinPQ p,int k,Ord v);

/* 大顶堆索引堆 */
// #define char Ord
// #define lt(a,b) ((a)<(b)?1:0)
IndexMaxPQ newIndexMaxPQ(int n)
void freeIndexMaxPQ(IndexMaxPQ p)
int  IndexMaxPQ_insert(IndexMaxPQ p,int k,Ord v);
Ord  IndexMaxPQ_max(IndexMaxPQ p);
int  IndexMaxPQ_delMax(IndexMaxPQ p);
Bool IndexMaxPQ_contains(IndexMaxPQ p,int k);
int  IndexMaxPQ_maxIndex(IndexMaxPQ p);
int  IndexMaxPQ_change(IndexMaxPQ p,int k,Ord v);
```
