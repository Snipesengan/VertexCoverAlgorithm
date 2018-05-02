#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*GET_KEY_CALLBACK)(void*);
typedef struct
{
    enum {MAX, MIN} heap_type;
    void** data_array;
    int heap_size;
    size_t MAX_SIZE;
} Heap;

Heap* createEmptyHeap(int, size_t);
void* heapExtractRoot(Heap*,GET_KEY_CALLBACK funcptr);
void* heapExtractIndex(Heap*,int,GET_KEY_CALLBACK funcptr);
int heapUpdate(Heap*,int,GET_KEY_CALLBACK funcptr);
void buildHeap(Heap*, void**, size_t, GET_KEY_CALLBACK);
int heapInsertRoot(Heap*,void*,GET_KEY_CALLBACK funcptr);

#endif
