#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Heap.h"


int getKey(void* data)
{
    return *((int*)data);
}

int main(void)
{
    int i;
    Heap* heap;
    int sampleArr[] = {4,1,3,2,9,11,10,14,8,7};

    void** intArr = (void**) malloc(10 * sizeof(void*));
    for(i = 0; i < 10; i++)
    {
        intArr[i] = (void*) malloc(sizeof(int));
        *((int*) intArr[i]) = sampleArr[i];
    }

    heap = createEmptyHeap(MAX, 20);
    buildHeap(heap, intArr, 10, &getKey);

    for(i = 0; i < 10; i++)
    {
        printf("%d\n", *((int*)heapExtractRoot(heap, &getKey)));
    }

    return 0;
}
