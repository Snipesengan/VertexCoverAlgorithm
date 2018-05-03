#ifndef VERTEX_COVER_H
#define VERTEX_COVER_H

#include "Graph.h"
#include "GraphNode.h"
#include "GraphReader.h"
#include "Heap.h"

typedef struct
{
    int visited;
    int currentDegree;

} GraphNodeData;

void approxMinVertexCover(Graph* graph);
#endif
