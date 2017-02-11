# 堆(heap)

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
