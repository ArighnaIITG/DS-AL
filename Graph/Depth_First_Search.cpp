// This program performs the depth-first traversal of a graph.
// The recursive approach has been given here.

#include <iostream>   
#include <list>
#include <iterator>

using namespace std;

class Graph
{
	int V; //no. of vertices

	list<int> *adj; // Pointer to an array of adjacent lists

	void DFSutil(int v ,bool visited[]); // Recursive function which will be called
										 // by function DFS.

	public:
		Graph(int V); // Constructor
		void addEdge(int v, int w); // Adds an edge from v to w

		void DFS(int s); // This function performs Depth-First Traversal of a graph.
						 // And also calls DFSutil function.
};

Graph::Graph(int V)
{
	this->V = V;    // References the constructor
	adj = new list<int>[V];  // Creates an array of adjacent lists.
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);    // Adds w to the end of v.
}
void Graph::DFSutil(int v ,bool visited[])
{
	// Mark the current node and print it.
	visited[v] = true;
	cout << v << " ";

	// Create an iterator it.
	list<int> :: iterator it;

	//Recur for all the vertices adjacent to tjhis vertex.
	for(it=adj[v].begin() ;it!=adj[v].end(); i++){
		if(!visited(*it))
			DFSutil(*it ,visited); // recursively calls the function here. Recursive implementation of stack.
	}
}

void Graph::DFS(int s)
{
	//Create a boolean visited array
	bool *visited = new bool[V];
	for(int i=0; i<V; i++){
		visited = false;
	}

	DFSutil(s,visited); // calls once the DFSutil function using the source vertex,
						// and then the DFSutil function calls itself recursively.
}

// Driver program to run DFS
int main()
{
	Graph gh(4);
	gh.addEdge(0,1);
	gh.addEdge(0,2);
	gh.addEdge(1,2);
	gh.addEdge(2,0);
	gh.addEdge(2,3);
	gh.addEdge(3,3);

	gh.DFS(2); // 2 is the source vertex
} 