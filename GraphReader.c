#include "GraphReader.h"

Graph* readGraph(char* path)
{
    Graph* graph = NULL;
    FILE* f;
    char str[MAX_STRING_SIZE];
    char* tok;
    char* origin;

    f = fopen(path, "r");

    if(f == NULL)
    {
        graph = NULL;
        perror("Could not open the file\n");
    }
    else
    {
        graph = newGraph();

        while(fgets(str, MAX_STRING_SIZE, f) != NULL)
        {
            strtok(str,"\n");
            origin = strtok(str, ",");
            printf("Proccessing token : %s\n",origin);
            addGraphNode(graph, origin, NULL);

            do
            {
                tok = strtok(NULL, ",");
                if(tok != NULL)
                {
                    printf("Proccessing token : %s\n",tok);
                    addGraphNode(graph,tok,NULL);
                    makeAdj(graph,origin,tok);
                }
            } while(tok != NULL);
        }
    }

    if(ferror(f))
    {
        printf("An error has occured\n");
    }

    if(fclose(f) != 0)
    {
        perror("There was an error closing the file");
    }

    return graph;
}
