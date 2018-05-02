#include "Heap.h"
static void heapify(Heap*, int, GET_KEY_CALLBACK);

Heap* createEmptyHeap(int heap_type, size_t max_size)
{
    Heap* heap = NULL;

    if(heap_type == 0 || heap_type == 1)
    {
        heap = (Heap*) malloc(sizeof(heap));
        heap->data_array = (void**) malloc(max_size * sizeof(void*));
        heap->heap_size = 0;
        heap->heap_type = heap_type;
        heap->MAX_SIZE = max_size;
    }

    return heap;
}

void buildHeap(Heap* heap, void** data_array, size_t array_len, GET_KEY_CALLBACK funcptr)
{
    int i;

    if(heap != NULL)
    {
        /* Shallow copy things in data_array into heap's data_array */
        heap->heap_size = array_len;
        for(i = 0; i < heap->MAX_SIZE; i++)
        {
            if(i < heap->heap_size)
            {
                heap->data_array[i] = data_array[i];
            }
            else
            {
                heap->data_array[i] = NULL;
            }

        }

        for(i = ((heap->heap_size) - 1)/2; i >=0; i--)
        {
            heapify(heap, i, funcptr);
        }
    }
}

void* heapExtractRoot(Heap* heap, GET_KEY_CALLBACK funcptr)
{
    void* data = NULL;

    if(heap->heap_size >= 1)
    {
        data = heap->data_array[0];
        heap->data_array[0] = heap->data_array[heap->heap_size - 1];
        heap->data_array[heap->heap_size - 1] = NULL;
        heap->heap_size --;
        heapify(heap,0,funcptr);
    }

    return data;
}

void* heapExtractIndex(Heap* heap, int i,GET_KEY_CALLBACK funcptr)
{
    void* data = NULL;

    if(i >= 0 && i < heap->heap_size)
    {
        data = heap->data_array[i];
        heap->data_array[i] = heap->data_array[heap->heap_size - 1];
        heap->data_array[heap->heap_size - 1] = NULL;
        heap->heap_size --;
        heapify(heap,i,funcptr);
    }

    return data;
}

int heapInsert(Heap* heap, void* data, GET_KEY_CALLBACK funcptr)
{
    int success = 0;
    int i = 0;
    int parentKey, key;

    if(heap->heap_size < heap->MAX_SIZE)
    {
        heap->heap_size ++;
        i = heap->heap_size - 1;

        key = (*funcptr)(data);
        parentKey = (*funcptr)(heap->data_array[i/2]);
        if(heap->heap_type == MAX)
        {
            while(i >= 1 && parentKey < key)
            {
                heap->data_array[i] = heap->data_array[i/2];
                i = i/2;
                parentKey = (*funcptr)(heap->data_array[i/2]);
            }
        }
        else
        {
            while(i >= 1 && parentKey > key)
            {
                heap->data_array[i] = heap->data_array[i/2];
                i = i/2;
                parentKey = (*funcptr)(heap->data_array[i/2]);
            }
        }
        heap->data_array[i] = data;

        success = 1;
    }

    return success;
}

int heapUpdate(Heap* heap, int i, GET_KEY_CALLBACK funcptr)
{
    int success = 0;
    int parentKey, key;
    void* tmpData;
    int orgIdx = i;

    if(i >= 0 && i < heap->heap_size)
    {
        key = (*funcptr)(heap->data_array[i]);
        parentKey = (*funcptr)(heap->data_array[i/2]);
        if(heap->heap_type == MAX)
        {
            while(i >= 1 && parentKey < key)
            {
                tmpData = heap->data_array[i];
                heap->data_array[i] = heap->data_array[i/2];
                heap->data_array[i/2] = tmpData;
                i = i/2;
                parentKey = (*funcptr)(heap->data_array[i/2]);
            }
        }
        else
        {
            while(i >= 1 && parentKey > key)
            {
                tmpData = heap->data_array[i];
                heap->data_array[i] = heap->data_array[i/2];
                heap->data_array[i/2] = tmpData;
                i = i/2;
                parentKey = (*funcptr)(heap->data_array[i/2]);
            }
        }

        if(orgIdx == i)
        {
            heapify(heap, i, funcptr);
        }

        success = 1;
    }

    return success;
}

static void heapify(Heap* heap, int i, GET_KEY_CALLBACK funcptr)
{
    void* tmp;
    int left = i * 2 + 1;
    int right = left + 1;
    int swapIdx = i;
    int key1, key2;

    if(left < heap->heap_size - 1)
    {
        key1 = (*funcptr)(heap->data_array[left]);
        key2 = (*funcptr)(heap->data_array[swapIdx]);

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
        key1 = (*funcptr)(heap->data_array[right]);
        key2 = (*funcptr)(heap->data_array[swapIdx]);
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
        heapify(heap, swapIdx, funcptr);
    }
}
