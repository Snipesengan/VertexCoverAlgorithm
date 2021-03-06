#include <stdio.h>
#include "GraphReader.h"

int main(void)
{
    Graph* graph = NULL;
    printf("Creating a Graph...\n");

    graph = readGraph("Graph1.txt");
    printAdjList(graph);
    printVertexList(graph);
    freeGraph(graph);

    return 0;
}
