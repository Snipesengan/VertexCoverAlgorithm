CC=gcc
CFLAGS= -Wall -ansi -pedantic
OBJ=LinkedList.o GraphNode.o Graph.o GraphReader.o Heap.o VertexCover.o
EXEC=VertexCoverAlgorithm

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

VertexCover.o: VertexCover.c VertexCover.h GraphReader.h Graph.h GraphNode.h LinkedList.h Heap.h
	$(CC) $(CFLAGS) -c VertexCover.c

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

UnitTestHeap: UnitTestHeap.o Heap.o
	$(CC) $(CLAGS) UnitTestHeap.o Heap.o -o UnitTestHeap

UnitTestHeap.o: UnitTestHeap.c Heap.h
	$(CC) $(CFLAGS) -c UnitTestHeap.c

Heap.o: Heap.c Heap.h
	$(CC) $(CFLAGS) -c Heap.c

clean:
	rm -f $(OBJ) UnitTestGraph.o UnitTestHeap.o $(EXEC) UnitTestGraph UnitTestHeap
