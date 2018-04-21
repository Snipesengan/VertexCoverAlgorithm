CC=gcc
CFLAGS= -Wall -ansi -pedantic
OBJ=LinkedList.o GraphNode.o Graph.o GraphReader.o
EXEC=VertexCoverAlgorithm

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

UnitTestGraph: $(OBJ) UnitTestGraph.o
	$(CC) $(CFLAGS) $(OBJ) UnitTestGraph.o -o UnitTestGraph

UnitTestGraph.o: UnitTestGraph.c GraphReader.h Graph.h GraphNode.h LinkedList.h
	$(CC) $(CFLAGS) -c UnitTestGraph.c

GraphReader.o: GraphReader.c GraphReader.h Graph.h GraphNode.h LinkedList.h
	$(CC) $(CFLAGS) -c GraphReader.c

Graph.o: Graph.c Graph.h GraphNode.h LinkedList.h
	$(CC) $(CFLAGS) -c Graph.c

GraphNode.o: GraphNode.c GraphNode.h LinkedList.h
	$(CC) $(CFLAGS) -c GraphNode.c

LinkedList.o: LinkedList.c LinkedList.h
		$(CC) $(CFLAGS) -c LinkedList.c

clean:
	rm -f $(OBJ) $(EXEC) UnitTestGraph
