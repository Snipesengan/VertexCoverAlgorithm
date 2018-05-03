#include "VertexCover.h"

int getNodeKey(void* node)
{
    return ((GraphNodeData*)(((GraphNode*) node)->data))->currentDegree;
}

int main(void)
{
    Graph* graph = readGraph("Graph1.txt");
    printf("-------------Performing vertex approximation--------------\n");
    approxMinVertexCover(graph);
}

void approxMinVertexCover(Graph* graph)
{
    GraphNodeData* nodeData = NULL;
    LinkedListNode* curr = NULL;
    GraphNode* currNode = NULL;
    Heap* vertexHeap = NULL;

    vertexHeap = createEmptyHeap(MAX, graph->numNode, &getNodeKey);
    /*
     * First update all node in the graph, setting it to unvisited,
     * and the current number of degree is the number of incidence
     */
    printf("Updating vertex's {visited, currDegree}:\n");
    curr = graph->nodeList->head;
    while(curr != NULL)
    {
        currNode = (GraphNode*) curr->data;
        nodeData = (GraphNodeData*) malloc(sizeof(GraphNodeData));
        nodeData->visited = FALSE;
        nodeData->currentDegree = currNode->numIncidence;
        currNode->data = nodeData;
        printf("(key = %s ,{visisted = %d,  currentDegree = %d})\n"
                , currNode->key, nodeData->visited, nodeData->currentDegree);

        /*add the node to the heap, it will be sorted based on degree*/
        heapInsert(vertexHeap, currNode);

        curr = curr->next;
    }

    while(vertexHeap->heap_size > 0)
    {
        currNode = (GraphNode*) heapExtractRoot(vertexHeap);
        nodeData = (GraphNodeData*) currNode->data;
        printf("(key = %s ,{visisted = %d,  currentDegree = %d})\n"
                , currNode->key, nodeData->visited, nodeData->currentDegree);
    }



}
