#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*GET_KEY_CALLBACK)(void*);
typedef struct
{
    enum {MAX, MIN} heap_type;
    GET_KEY_CALLBACK funcptr;
    void** data_array;
    int heap_size;
    int MAX_SIZE;


} Heap;

Heap* createEmptyHeap(int, int, GET_KEY_CALLBACK);
void* heapExtractRoot(Heap*);
void* heapExtractIndex(Heap*,int);
int heapUpdate(Heap*,int);
void buildHeap(Heap*, void**, int);
int heapInsert(Heap*,void*);

#endif
