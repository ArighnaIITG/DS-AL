// Program to print BFS of a graph, given the source vertex.
// For simplicity, it is assumed that all vertices are reachable from the source vertex.

#include <iostream>
#include <list>     // List Class of STL
#include <iterator>

using namespace std;

// The following class represents a directed graph using adjacency list representation.\

class Graph
{
	int V; // no. of vertices
    // Pointer to an array of adjacent lists
	list<int> *adj;

	Graph(int V);  //Constructor

	void addEdge(int v, int w); // Adds an edge from v to w

	void BFS(int s);  // Finds the BFS of the directed graph, given source vertex s.
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V]; // Creates a new array of adjacent lists with unconnected nodes
							// From the STL Library.
}

void addEdge(int v, int w)
{
	adj[v].push_back(w);    // Adds an edge from v to w.
							// push_back(w) adds an element(w) to the end of the list.
}

void BFS(int s)             // s --> source vertex
{
	// Create a boolean visited array. Mark all vertices initially as not visited.
	bool *visited = new bool[V];
	for(int i=0; i<V; i++){
		visited[i] = false;
	}

	//Create a queue, which will control the search.
	list<int> queue;

	//Mark current node as visited s, and push it to the queue. 
	//Queue --> LIFO DS.
	visited[s] = true;
	queue.push_back(s);

	//Create an iterator
	list<int> :: iterator it;

	//Main Logic
	while(!queue.empty())
	{
		//Dequeue the queue. Print the first element of the queue, and then pop it.
		s = queue.front();
		cout << s << ",";
		queue.pop_front();

		//Run through the adjacency list of that vertex. 
		for(it=adj[s].begin(); it!=adj[s].end(); ++it)
		{
			if(!visited[*it]){
				visited[*it]=true;
				queue.push_back(*it);
			}
		}
	}
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}