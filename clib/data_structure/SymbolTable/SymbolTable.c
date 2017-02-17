#ifndef __CLIB_DATA_STRUCTURE_SYMBOLTABLE_SYMBOLTABLE_C__
#define __CLIB_DATA_STRUCTURE_SYMBOLTABLE_SYMBOLTABLE_C__

// class Eq Key
// typedef char Key;
// typedef int Value;
// #define equal(a,b) ((a)==(b))

#include <malloc.h>
#include "../../types/Status.h"
typedef struct {
    Key *key;
    Value *val;
    int size;
    int capacity;
}_StructST_,*SymbolTable;

SymbolTable newSymbolTable(int n)
{
    SymbolTable h = (SymbolTable)malloc(sizeof(_StructST_));
    h->key = (Key *)malloc(sizeof(Key)*n);
    h->val = (Value *)malloc(sizeof(Value)*n);
    h->size = 0;
    h->capacity = n;
    return h;
}
void freeSymbolTable(SymbolTable h) { free(h->key); free(h->val); free(h); }

int SymbolTable_put(SymbolTable st,Key key,Value val)
{
    int n = st->size,i=0;
    while(i<n && !equal(key,st->key[i])) { i++; }
    if(i==n) { 
        if(n == st->capacity){
            st->key = (Key *)realloc(st->key,sizeof(Key)*2*n);
            st->val = (Value *)realloc(st->val,sizeof(Value)*2*n);
            st->capacity *=2; 
        }
        st->size++;
        st->key[i] = key;
        st->val[i] = val;
        return 1;
    }
    st->val[i] = val;
    return 0;
}
Status SymbolTable_get(SymbolTable st,Key key,Value *val){
    int n = st->size,i=0;
    while(i<n && !equal(key,st->key[i])) { i++; }
    if(i>=n) { return ERROR; }
    *val = st->val[i];
    return OK;
}
Status SymbolTable_delete(SymbolTable st,Key key)
{
    int n = st->size,i=0;
    while(i<n && !equal(key,st->key[i])) { i++; }
    if(i>=n) { return ERROR; }
    n = --st->size;
    for(;i<n;i++){
        st->key[i] = st->key[i+1];
        st->val[i] = st->val[i+1];
    }
    return OK;
}


#endif
