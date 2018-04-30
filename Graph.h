#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "GraphNode.h"

typedef struct
{
    LinkedList* nodeList;
    int numNode;
}Graph;

Graph* newGraph(void);
void addGraphNode(Graph*, char*, void*);
int hasKey(Graph*, char*);
GraphNode* getGraphNode(Graph*, char*);
void makeAdj(Graph*, char*, char*);
void printAdjList(Graph*);
void printVertexList(Graph*);
void freeGraph(Graph*);

#endif
