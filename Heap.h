#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int (*Get_Key_Fnc)(void* data);
typedef struct
{
    enum {MAX, MIN} heap_type;
    void** data_array;
    int heap_size;
    size_t MAX_SIZE;
    Get_Key_Fnc keyFunc;
} Heap;

Heap* createEmptyHeap(int, size_t, Get_Key_Fnc);
void buildHeap(Heap*, void**, size_t);
void heapify(Heap*, int);


#endif
