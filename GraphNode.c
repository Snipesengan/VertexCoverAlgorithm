#include "GraphNode.h"

GraphNode* newGraphNode(char key[], void* data)
{
    GraphNode* newNode = (GraphNode*) malloc(sizeof(GraphNode));
    newNode->adjList = newLinkedList();
    newNode->key = key;
    newNode->data = data;
    newNode->numIncidence = 0;

    return newNode;
}

void addIncidence(GraphNode* origin, GraphNode* node)
{
    if(isAdj(origin,node) == FALSE)
    {
        insertLast(origin->adjList,(void*) node);
        origin->numIncidence ++;
    }
}

int isAdj(GraphNode* origin, GraphNode* node)
{
    char* key = NULL;
    LinkedList* adjList = origin->adjList;
    int isAdj = FALSE;

    LinkedListNode* curr = adjList->head;
    while(curr != NULL && isAdj == FALSE)
    {
        key = ((GraphNode*) curr->data)->key;
        if(strncmp(key, node->key,MAX_KEY_LENGTH) == 0)
        {
            isAdj = TRUE;
        }
        curr = curr->next;
    }

    return isAdj;
}

void printAdj(GraphNode* node)
{
    LinkedList* adjList = node->adjList;
    LinkedListNode* curr = adjList->head;

    printf("%s (%d)| ", node->key, node->numIncidence);
    while(curr != NULL)
    {
        printf("%s ", ((GraphNode*) curr->data)->key);
        curr = curr->next;
    }
    printf("\n");
}
