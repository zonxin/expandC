#ifndef __CLIB_DATA_STRUCTURE_TREE_BINARYSEARCHTREE_C__
#define __CLIB_DATA_STRUCTURE_TREE_BINARYSEARCHTREE_C__

// class Ord Key
// #define Key  char
// #define Value int
// #define compare(a,b) ((a)-(b))

#include <malloc.h>

typedef struct _BSTNODEST_ {
    Key key;
    Value val;
    struct _BSTNODEST_ *left,*right;
}*_BSTNode_,**BinarySearchTree;
/* 后者可看作:
typedef struct _BSTree_ {
    _BSTNode_ root;  // root 指向树根节点
}*BinarySearchTree;
 * 于是 
        BinarySearchTree p;
        *p  // 相当与 p->root;
*/
_BSTNode_ _newBSTNode_(Key key,Value val)
{
    _BSTNode_ p = (_BSTNode_) malloc(sizeof(struct _BSTNODEST_));
    p->key = key;
    p->val = val;
}
/* 只画出左子树的数据结构
 *                                ┌──────┐     ┌──────┐     ┌──────┐
 *                        ┌────>  │ data │  ┌─>│ data │  ┌─>│ data │
 *              ┌──────┐  │       ├──────┤  │  ├──────┤  │  ├──────┤
 *           ┌─>│ root │ ─┘  ┌─>  │ left │ ─┘  │ left │ ─┘  │ left │
 *           │  └──────┘     │    └──────┘     └──────┘     └──────┘
 *  ┌──────┐ │               │ 
 *  │ head │─┘               │
 *  └──────┘                 │
 *  ┌─────────┐              │
 *  │ subTree │ ─────────────┘  
 *  └─────────┘      
 * 如图，head 和 subTree 是相同的类型， root 和 left 是相同的类型。
 */
BinarySearchTree newBinarySearchTree()
{
    BinarySearchTree head = (BinarySearchTree)malloc(sizeof(_BSTNode_));
    *head = NULL;  //  head -> root = NULL
}
void _freeSubTree_(BinarySearchTree head)
{
    BinarySearchTree subTree;
    if(*head == NULL) { return; } //  head->root == NULL ?
    subTree = &(*head)->left; _freeSubTree_(subTree);
    subTree = &(*head)->right; _freeSubTree_(subTree);
    free(*head); // free(head->root);
}
void freeBinarySearchTree(BinarySearchTree head){
   _freeSubTree_(head);
  free(head); 
}

// 获取一个键值,返回结果在pv中,若不存在返回 0
int BST_get(BinarySearchTree head,Key key,Value *pv)
{
    if(*head==NULL) { return 0; } 
    int cmp = compare(key,(*head)->key); 
    if     (cmp < 0) {return BST_get(&(*head)->left,key,pv);}
    else if(cmp > 0) { return BST_get(&(*head)->right,key,pv); }
    if(cmp == 0) { *pv = (*head)->val; return 1; }
}

int BST_put(BinarySearchTree head,Key key,Value val)
{
    if((*head)==NULL) {
        (*head) = _newBSTNode_(key,val);
        return 1;
    }
    int cmp = compare(key,(*head)->key);
    if     (cmp < 0) { return BST_put(&(*head)->left,key,val); }
    else if(cmp > 0) { return BST_put(&(*head)->right,key,val); } 
    else  { (*head)->val = val; return 0; }
}

_BSTNode_ _BST_delMin_(BinarySearchTree head)
{
    _BSTNode_ ret;
    while((*head)->left != NULL ){
        head = &(*head)->left;
    }
    ret = *head;
    *head = ret->right;
    return ret;
}
// 删除成功返回 1 否则返回 0
int BST_delete(BinarySearchTree head,Key key)
{
    BinarySearchTree subTree;
    _BSTNode_ node;
    if(*head == NULL) { return 0;} 
    int cmp = compare(key,(*head)->key);
    if(cmp == 0) {
        if((*head)->left==NULL) { *head = (*head)->right; return 1; }
        if((*head)->right==NULL) { *head = (*head)->left; return 1; }
        subTree = &(*head)->right;
        node = _BST_delMin_(subTree);
        node->left = (*head)->left;
        node->right = (*head)->right;
        free(*head);
        (*head) = node;
        return 1;
    }
    else if(cmp < 0) { subTree = &(*head)->left; }  // LT
    else{ subTree = &(*head)->right; } // GT
    return BST_delete(subTree,key);
}

#endif
