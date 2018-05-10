// Implementation of the Djikstra's algorithm using the adjacency list representation of graphs.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdlib.h>

// A structure to represent a node in adjacency list.
struct AdjListNode
{
	int dest, weight;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode *head; // head pointer to the adjacency list
}

struct Graph
{
	int V; 
	struct AdjList* array;
};

struct AdjListNode* createNewNode(int dest, int weight)
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

	for(int v=0; v<V; v++)
	{
		graph->array[v].head = NULL;
	}
	return graph;
}

// Adds an edge in an undirected graph.
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
	// Adds an edge from src to dest. A new node is added to the adjacency list of src.
	// The node is added at the beginning.
	struct AdjListNode* newNode = createNewNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src] = newNode;

	// Since the graph is undirected, an edge is also added from dest to src.
	struct AdjListNode* newNode = createNewNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest] = newNode;
}

// Structure to represent a min heap node
struct MinHeapNode
{
	int v;
	int dist;
};

struct MinHeap
{
	int size;   // Number of nodes in the heap.
	int capacity;  // Capacity of the heap.
	int *pos;   // Needed for decreaseKey() function.
	struct MinHeapNode **array;
};

struct MinHeapNode* newMinHeapNode(int v, int dist)
{
	struct MinHeapNode* newNode = (struct MinHeapNode*) malloc(sizeof(MinHeapNode));
	newNode->v = v;
	newNode->dist = dist;
	return newNode;
}

