// Djikstra's Algorithm - Given a graph and its source vertex, this algorithm finds the shortest path
//						  from the source vertex to all the vertices in the graph.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9

// Returns the vertex with the minimum distance value, from the
// set of vertices not yet included in the SPT (Shortest Path Tree).
int min_distance(int dist[], bool sptSet[])
{
	int min = INT_MAX;
	int min_index = 0;

	for(int v=0; v<V; v++)
	{
		if((dist[v] <= min) && sptSet[v] == false)
			min = dist[v];
			min_index = v;
	}
	return min_index;
}

void printSolution(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");

    for (int i = 0; i < V; i++)
    	printf("%d tt %d\n", i, dist[i]);
}

// Implements the Djikstra's algorithm for shortest path in a graph,
// represented by adjacency matrix.
void djikstra(int graph[V][V], int src)
{
	int dist [V];   // The output array. dist[i] will hold the shortest
                    // distance from src to i
	bool sptSet[V]; // A boolean array, stating if vertex V is in the SPT.
 
	// Initializing the vertices.
	for(int v=0; v<V; v++)
	{
		dist[v] = INT_MAX;
		sptSet[v] = false;
	}

	dist[src] = 0;

	for(int count=0; count<V-1; count++)
	{
		int u = min_distance(dist, sptSet);
		sptSet[u] = true;

		// Iterate through adjacent vertices to update the distance values.
		for(int v=0; v<V; v++)
		{
			if(!sptSet[v] && graph[u][v] && dist[u]!= INT_MAX && (dist[u] + graph[u][v] < dist[v]))
				dist[v] = dist[u] + graph[u][v];
		}
	}
	printSolution(dist, V);
}

int main()
{
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                      };
  
    dijkstra(graph, 0);
  
    return 0;
}
