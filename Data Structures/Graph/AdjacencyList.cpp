#include <iostream>
#include <cstdlib>

using namespace std;

// Adjacency List Node

struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

//Adjacency List

struct AdjList
{
	struct AdjListNode *head; //pointer ot the head node of the list
};

//class Graph

class Graph
{
	private :
		int V; //Size of the Adjacent List Array
		struct AdjList* array; //Graph is an array of adjacency lists.

	public :

		Graph(int V)
		{
			this->V = V; //reference the Constructor
			array = new AdjList[V]; // Creates an array of V vertices , which form to make the adjacency list.
			for(int i=0;i<V;i++){
				array[i].head = NULL;			
			}

		}
		AdjListNode* newAdjListNode (int dest)
		{
			AdjListNode* newNode = new AdjListNode;
			newNode->dest = dest;
			newNode->next = NULL;
			return newNode;
		}

		//Adds an undirected edge to the graph
		void addEdge (int src, int dest)
		{
			//Adds an edge from src to dest. A new node is being created and 
			//node is being added at the beginning.

			AdjListNode* newNode = newAdjListNode(dest); //creation of new node, no need of malloc as in C.
			newNode->next = array[src].head;
			array[src].head = newNode;

			//Since the graph is undirected, we add another edge from dest to src.
			newNode = newAdjListNode(src);
			newNode->next = array[dest].head;
			array[dest].head = newNode;
		}

		//The arrays of the list are being printed.
		void printGraph ()
		{
			int v;
			for(v=0;v<V;v++){
				AdjListNode* pCrawl = array[v].head; // The head node of each array
				cout << "\n Adjacency list of vertex " <<v<< "\n head";
				while(pCrawl){
					cout << "->" << pCrawl->dest;
					pCrawl = pCrawl->next;
				}
				cout << endl;
			}
		}
};

int main()
{
	Graph gh(5);
	gh.addEdge(0, 1); // Various vertices and the edges.
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

 	// print the adjacency list representation of the above graph
    gh.printGraph();

    return 0;

}
