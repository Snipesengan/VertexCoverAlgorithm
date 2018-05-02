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
    int sampleArr[] = {4,1,3,2,9,16,10,14,8,7};

    void** intArr = (void**) malloc(10 * sizeof(void*));
    for(i = 0; i < 10; i++)
    {
        intArr[i] = (void*) malloc(sizeof(int));
        *((int*) intArr[i]) = sampleArr[i];
    }

    printf("----------------------------------------");
    printf("\nHEAP TEST HARNESS \n");
    printf("----------------------------------------\n");
    /*--------------------------TEST CREATEEMPTYHEAP------------------------------*/
    printf("Testing createEmptyHeap: ");
    heap = createEmptyHeap(MAX, 20, &getKey);
    if(heap != NULL)
    {
        printf(" PASSED\n\n");
    }
    else
    {
        printf(" FAILED\n\n");
    }

    /*--------------------------TEST BUILDHEAP------------------------------*/
    printf("Testing buildHeap: \n");
    printf("Input array : {");
    for(i = 0; i < 9; i++)
    {
        printf("%d,", *(int*)intArr[i]);
    }
    printf("%d}\n",  *(int*)intArr[9]);

    buildHeap(heap, intArr, 10);

    printf("Output Heap : {");
    while(heap->heap_size > 1)
    {
        printf("%d,", *((int*)heapExtractRoot(heap)));
    }
    printf("%d}\n\n", *((int*)heapExtractRoot(heap)));

    /*--------------------------TEST HEAPINSERT------------------------------*/
    printf("Testing heapInsert: \n");
    heap->heap_type = MIN;
    printf("Input array : {");
    for(i = 0; i < 9; i++)
    {
        printf("%d,", *(int*)intArr[i]);
        heapInsert(heap, intArr[i]);
    }
    heapInsert(heap, intArr[9]);
    printf("%d}\n",  *(int*)intArr[9]);

    printf("Output Heap : {");
    while(heap->heap_size > 1)
    {
        printf("%d,", *((int*)heapExtractIndex(heap, 0)));
    }
    printf("%d}\n\n", *((int*)heapExtractIndex(heap, 0)));

    return 0;
}
