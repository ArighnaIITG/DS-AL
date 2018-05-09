// A union find algorithm to detect cycle in a graph

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent the edge in an unweighted graph
struct Edge
{
	int src, dest;
};

// A structure to represent a graph
struct Graph
{
	int V, E;

	// The graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph of V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
	return graph;
}

// An utitity function to find the subset of an element i
int find(int parent[], int i)
{
	if(parent[i] == -1)
		return i;

	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
	int xset = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
}

int isCycle(struct Graph* graph)
{
	int *parent = (int*) malloc(graph->V * sizeof(int));

	// Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);

    for(int i=0; i< graph->E; i++)
    {
    	int x = find(parent, graph->edge[i].src);
    	int y = find(parent, graph->edge[i].dest);

    	if (x == y)
    		return 1;

    	Union(parent, x, y);
    }
    return 0;
}

// Driver program to test above functions
int main()
{   
    int V = 3, E = 3;
    struct Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf("Graph contains cycle.");
    else
        printf("Graph doesn't contain cycle.");
 
    return 0;
}

