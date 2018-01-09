/* This program implements stack using linked lists.
   
   It's better than array implementation in the sense that the stack can grow and shrink during runtime.
   But it does require more memory due to usage of pointers

*/

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct StackNode
{
	int data;
	struct StackNode* next;
}

class Stack_LL()
{
	public :
		StackNode* new_Node(int data);
		int isEmpty(StackNode *head);
		void push(StackNode **head, int data);
		int pop(StackNode **head);
		int peek(StackNode **head);
};

StackNode* Stack_LL::new_Node(int data)
{
	StackNode *new_node = new StackNode;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

int Stack_LL::isEmpty(StackNode *head)
{
	return !head;
}

void Stack_LL::push(StackNode **head, int data)
{
	StackNode *new_node = new_Node(data);
	new_node->next = *head;
	*head = new_node;
	cout << data << " is pushed to the stack." << endl 
}

