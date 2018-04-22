#include "Graph.h"

Graph* newGraph(void)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->nodeList = newLinkedList();
    graph->numNode = 0;

    return graph;
}

void addGraphNode(Graph* graph, char key[], void* data)
{
    if(hasKey(graph,key) == FALSE)
    {
        GraphNode* newNode = newGraphNode(key, data);
        insertLast(graph->nodeList, (void*) newNode);
        graph->numNode ++;
        printf("New vertex = %s\n",key);
    }
}

int hasKey(Graph* graph, char key[])
{
    int hasKey = FALSE;
    char* thisKey = NULL;
    LinkedList* nodeList = graph->nodeList;
    LinkedListNode* curr = nodeList->head;

    while(curr != NULL && hasKey == FALSE)
    {
        thisKey = ((GraphNode*) curr->data)->key;
        if(strncmp(key, thisKey,MAX_KEY_LENGTH) == 0)
        {
            hasKey = TRUE;
        }
        curr = curr->next;
    }

    return hasKey;
}

GraphNode* getGraphNode(Graph* graph, char key[])
{
    GraphNode* node = NULL;
    char* thisKey = NULL;
    LinkedList* nodeList = graph->nodeList;
    LinkedListNode* curr = nodeList->head;

    while(curr != NULL && node == NULL)
    {
        thisKey = ((GraphNode*) curr->data)->key;
        if(strncmp(key, thisKey,MAX_KEY_LENGTH) == 0)
        {
            node = (GraphNode*) curr->data;
        }
        curr = curr->next;
    }

    return node;
}

void makeAdj(Graph* graph, char key1[], char key2[])
{
    GraphNode* node1 = getGraphNode(graph,key1);
    GraphNode* node2 = getGraphNode(graph,key2);

    if(node1 != NULL && node2 != NULL)
    {
        if(isAdj(node1,node2) == FALSE)
        {
            addIncidence(node1, node2);
            printf("New Edge = %s -> %s\n", key1, key2);
        }
    }
}

void printAdjList(Graph* graph)
{
    LinkedList* nodeList = graph->nodeList;
    LinkedListNode* curr = nodeList->head;

    printf("Graph has %d vertex\n", graph->numNode);
    while(curr != NULL)
    {
        printAdj((GraphNode*) curr->data);
        curr = curr->next;
    }
}

void printVertexList(Graph* graph)
{
    LinkedList* nodeList = graph->nodeList;
    LinkedListNode* curr = nodeList->head;

    printf("Vertex: ");
    while(curr != NULL)
    {
        printf("%s ", ((GraphNode*) curr->data)->key);
        curr = curr->next;
    }
    printf("\n");
}

void freeGraph(Graph* graph)
{
    LinkedList* nodeList = graph->nodeList;
    LinkedListNode* curr = nodeList->head;

    while(curr != NULL)
    {
        softFreeList(((GraphNode*) curr->data)->adjList);
        curr = curr->next;
    }
    softFreeList(nodeList);
    graph = NULL;
}
