/* Topological sorting is valid only in a Directed Acyclic Graph (DAG).
   This algorithm returns a linear ordering of vertices such that if there is an edge from (u,v)
   vertex u will come before vertex v.

   It is basically modified DFS, which uses an extra empty stack as an argument
   in the recursive DFS function.
  */

#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	int V ; // No. of vertices

	list<int> *adj ; // Pointer to an array of adjacent lists

	// Recursive topological Sort function
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 

	public :
		Graph(int V);  // Constructor
		void addEdge(int v, int w);   // Adds an edge from v to w

		// Main logic implementation of topological sorting
		void topologicalSort();  
};

Graph::Graph(int V)
{
	this->V = V;   // References the constructor
	adj = new list<int>[V];   // Creates an array of adjacency lists
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);      // Adds an edge from v to w.
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	// Mark the current node as visited.
	visited[v] = true;

	// Create an iterator it.
	list<int> :: iterator it;

	//Recur for all the vertices adjacent to this vertex
	for(it=adj[v].begin(); it!=adj[v].end(); it++){
		if(!visited[*it])
			topologicalSortUtil(*it, visited, Stack);
	}
	Stack.push(v);  // Push the contents onto the stack
}

void Graph::topologicalSort()
{
	//Declare the temporary stack.
	stack<int> Stack;

	// Create a boolean visited array
	bool *visited = new bool[V];
	for(int i=0; i<V; i++){
		visited[i] = false;
	}

	// Call the recursive helper function to put the listed vertices in stack.
	for(int i=0; i<V; i++){
		if(!visited[i])
			topologicalSortUtil(i, visited, Stack);
	}

	// Print the contents of the stack.
	while(Stack.empty() == false){
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph : \n";
    g.topologicalSort();
 
    return 0;
}

/* Time Complexity :
	O(V+E)  , where V is no. of vertices and E is no. of edges
	*/