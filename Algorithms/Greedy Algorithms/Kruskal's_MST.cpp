// Kruskal's algorithm to find the Minimum Spanning Tree of a weighted graph.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];
	// graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));

	return graph;
}

struct Subset
{
	int parent;
	int rank;
};

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

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int comp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	struct Edge result[V];
	int e = 0; // A variable used for result[]
	int i = 0; // A variable used for sorting edges

	// Sorts the edges in non-decreasing order of weights.
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), comp);
	// More about qsort can be found from this reference : "http://www.cplusplus.com/reference/cstdlib/qsort/"

	struct Subset* subsets = (struct Subset*) malloc(V * sizeof(struct Subset));

	for(int v=0; v<V; v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while(e < V-1)
	{
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		if(x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}
	printf("Following are the edges in the constructed MST\n");

    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                 result[i].weight);
    return;
}

int main()
{
    int V = 4, E = 5;
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);
 
    return 0;
}