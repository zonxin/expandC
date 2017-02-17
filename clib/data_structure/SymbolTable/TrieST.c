#ifndef __CLIB_DATA_STRUCTURE_SYMBOLTABLE_TRIEST_C__
#define __CLIB_DATA_STRUCTURE_SYMBOLTABLE_TRIEST_C__

// class Enum Key
// #define Key char  // JUST for String
// #define Value int
// #define ENUM_MAX 256
// #define toInt(a) ((int)(a))


#include "../../types/Boolean.h"
#include "../../types/Status.h"
#include <malloc.h>
#include <string.h>
typedef struct _TrieNode_ {
    Value val;
    int valid; 
    struct _TrieNode_ *next[ENUM_MAX];
}*_TrieNode_,**TrieST;

_TrieNode_ _newTrieNode_()
{
    _TrieNode_ node =  (_TrieNode_)malloc(sizeof(struct _TrieNode_));
    memset(node,0,sizeof(struct _TrieNode_));
    return node;
}

TrieST newTrieST()
{
    TrieST st = (TrieST)malloc(sizeof(_TrieNode_));
    (*st) = NULL;
    return st;
}
void _freeSubTrieST_(TrieST st)
{
    int i;
    if(*st == NULL) { return; }
    for(i=0;i<ENUM_MAX;i++) {
        _freeSubTrieST_(&((*st)->next[i]));
    }
}
void freeTrieST(TrieST st)
{
    _freeSubTrieST_(st);
    free(st);
}

Status TrieST_get(TrieST st,char *key,Value *val)
{
    char c;int i;
    i=0;c=key[i];
    while(c && *st){
        st = &((*st)->next[toInt(c)]);
        c =key[++i];
    }
    if(*st == NULL) { 
        printf("null\n");
        return ERROR; }
    if((*st)->valid) { 
        *val = (*st)->val;
        return OK;
    }
    return ERROR;
}
int TrieST_put(TrieST st,char *key,Value val)
{
    char c;int i;Value v;
    i=0;c=key[i];
    while(c && *st){
        st = &((*st)->next[toInt(c)]);
        c =key[++i];
    }
    if(*st == NULL) { 
        c=key[i];
        while(c){
            (*st) = _newTrieNode_();
            st = &((*st)->next[toInt(c)]);
            c = key[++i];
        }
        (*st) = _newTrieNode_();
        (*st)->val = val;
        (*st)->valid = True;
        return 1;
    }
    (*st)->val = val;
    if((*st)->valid) { return 0; }
    (*st)->valid = True;
    return 1;
}

#endif
