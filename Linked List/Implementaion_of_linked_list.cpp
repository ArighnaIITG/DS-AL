/* This program will implement the various operations possible in a linked list,
   like inserting a node at various positions, or deleting a node, or reversing 
   the linked list, etc
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

// A Linked List Node
struct Node
{
	int data;  // Data fields of the nodes
	struct Node *next;   // Pointer to the next node
};

struct Node* head;       // Head Node of the Linked List

class LinkedList()
{
	public :
		Node* create Node(int value);       // Creating a node with a given value
		void insert_begin();				// Inserting a node at the beginning of the linked list
        void insert_pos();					// Inserting a node at a specific position in the linked list
        void insert_last(); 				// Inserting a node at the end of the linked list
        void delete_pos();					// Deleting a node at a specific position in the linked list
        void sort();
        void search();
        void update();
        void reverse();
        void display();

        LinkedList() 
        {
            head = NULL;
        }
};