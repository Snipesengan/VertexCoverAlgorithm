#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define MAX_KEY_LENGTH 129
#define FALSE 0
#define TRUE !FALSE

typedef struct
{
    char* key;
    LinkedList* adjList;
    void* data;
    int numIncidence;
} GraphNode;

GraphNode* newGraphNode(char*, void*);
void addIncidence(GraphNode*,GraphNode*);
int isAdj(GraphNode*, GraphNode*);
void printAdj(GraphNode*);

#endif
