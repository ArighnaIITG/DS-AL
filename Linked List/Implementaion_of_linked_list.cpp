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

struct Node *head;       // Head Node of the Linked List

class LinkedList()
{
	public :
		Node* create_Node(int value);       // Creating a node with a given value
		void insert_begin();				// Inserting a node at the beginning of the linked list
        void insert_pos();					// Inserting a node at a specific position in the linked list
        void insert_last(); 				// Inserting a node at the end of the linked list
        void delete_pos();					// Deleting a node at a specific position in the linked list
        void sort();						// Sorting the linked list
        void search();						// Searching """"
        void update();						// Updating  """"
        void reverse();						// Reversing """"
        void display();						// Displaying """"

        LinkedList() 
        {
            head = NULL;					// Initialized the Head Node as NULL
        }
};

// Main menu

main()
{
    int choice, nodes, element, position, i;
    LinkedList sl;
    head = NULL;

    // Performing a switch-case operation for the various operations.

    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Delete a Particular Node"<<endl;
        cout<<"6.Update Node Value"<<endl;
        cout<<"7.Search Element"<<endl;
        cout<<"8.Display Linked List"<<endl;
        cout<<"9.Reverse Linked List "<<endl;
        cout<<"10.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            sl.insert_begin();
            cout<<endl;
            break;

        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            sl.insert_last();
            cout<<endl;
            break;

        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            sl.insert_pos();
            cout<<endl;
            break;

        case 4:
            cout<<"Sort Link List: "<<endl;
            sl.sort();
            cout<<endl;
            break;

        case 5:
            cout<<"Delete a particular node: "<<endl;
            sl.delete_pos();
            break;

        case 6:
            cout<<"Update Node Value:"<<endl;  
            sl.update();
            cout<<endl;
            break;

        case 7:
            cout<<"Search element in Link List: "<<endl;
            sl.search();
            cout<<endl;
            break;

        case 8:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;

        case 9:
            cout<<"Reverse elements of Link List"<<endl;
            sl.reverse();
            cout<<endl;
            break;

        case 10:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  

        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}

Node* LinkedList::create_Node(int value)
{
	Node *temp, *s;
	Node *temp = new Node;
	if(temp == NULL)
		cout << "Memory not allocated" << endl;

	else{
		temp->data = value;
		temp->next = NULL;
		return temp;
	}
}

void LinkedList::insert_begin()
{
	int value;
	cout << "Enter the value to be inserted : " << endl
	cin >> value;

	struct Node *temp. *p;
	temp = create_Node(value);

	if(head == NULL){
		head = temp;
		head->next = NULL;
	}

	else{
		p = head;
		head = temp;
		head->next = p;
	}
}
