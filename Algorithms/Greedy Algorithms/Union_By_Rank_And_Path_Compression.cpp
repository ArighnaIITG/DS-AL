// An Union Find Algorithm by Rank and Path Compression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
	int src, dest;
};

struct Graph
{
	int V, E;
	struct Edge* edge;
};

struct Subset
{
	int parent;
	int rank;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];
	return graph;
}

// Uses the path compression technique to return the root, and make it the parent of x.
int find(struct Subset subsets[], int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;

	else if(subsets[yroot].rank < subsets[xroot].rank)
		subsets[yroot].parent = xroot;

	// If both the ranks are the same, make anyone as root, and increment it's rank by one.
	else{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int isCycle(struct Graph* graph)
{
	int V = graph->V;
	int E = graph->E;

	struct Subset* subsets = (struct Subset*) malloc(V * sizeof(struct Subset));

	for(int v=0; v<V; v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	for(int e=0; e<E; e++)
	{
		int x = find(subsets, graph->edge[e].src);
		int y = find(subsets, graph->edge[e].dest);

		if(x == y)
			return 1;

		Union(subsets, x, y);
	}
	return 0;
}

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
