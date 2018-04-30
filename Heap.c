#include "Heap.h"

Heap* createEmptyHeap(int heap_type, size_t max_size, Get_Key_Fnc funcPtr)
{
    Heap* heap = NULL;

    if(heap_type == 0 || heap_type == 1)
    {
        heap = (Heap*) malloc(sizeof(heap));
        heap->data_array = (void**) malloc(max_size * sizeof(void*));
        heap->heap_size = 0;
        heap->heap_type = heap_type;
        heap->MAX_SIZE = max_size;
        heap->keyFunc = funcPtr;
    }

    return heap;
}

void buildHeap(Heap* heap, void** data_array, size_t array_len)
{
    int i;

    if(heap != NULL)
    {
        /* Shallow copy things in data_array into heap's data_array */
        heap->heap_size = array_len;
        for(i = 0; i < heap->MAX_SIZE; i++)
        {
            if(i < array_len)
            {
                heap->data_array[i] = data_array[i];
            }
            else
            {
                heap->data_array[i] = NULL;
            }
        }

        for(i = heap->heap_size - 1; i >=0; i--)
        {
            heapify(heap, i);
        }
    }
}

void* heapExtract(Heap* heap)
{
    void* data = NULL;

    if(heap->heap_size >= 1)
    {
        data = heap->data_array[0];
        heap->data_array[0] = heap->data_array[heap->heap_size - 1];
        heap->data_array[heap->heap_size - 1] = NULL;
        heap->heap_size --;
        heapify(heap,0);
    }

    return data;
}

void heapify(Heap* heap, int i)
{
    void* tmp;
    int left = i * 2;
    int right = left + 1;
    int swapIdx = i;
    int key1, key2;

    if(left < heap->heap_size - 1)
    {
        key1 = (*heap->keyFunc)(heap->data_array[left]);
        key2 = (*heap->keyFunc)(heap->data_array[swapIdx]);
        if(heap->heap_type == MAX)
        {
            if(key1 > key2)
            {
                swapIdx = left;
            }
        }
        else
        {
            if(key1 < key2)
            {
                swapIdx = left;
            }
        }

    }

    if(right < heap->heap_size - 1)
    {
        key1 = (*heap->keyFunc)(heap->data_array[right]);
        key2 = (*heap->keyFunc)(heap->data_array[swapIdx]);
        if(heap->heap_type == MAX)
        {
            if(key1 > key2)
            {
                swapIdx = right;
            }
        }
        else
        {
            if(key1 < key2)
            {
                swapIdx = right;
            }
        }

    }

    if(swapIdx != i)
    {
        tmp = heap->data_array[i];
        heap->data_array[i] = heap->data_array[swapIdx];
        heap->data_array[swapIdx] = tmp;
        heapify(heap, swapIdx);
    }
}
