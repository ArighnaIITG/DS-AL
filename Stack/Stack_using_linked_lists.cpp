/* This program implements stack using linked lists.
   
   It's better than array implementation in the sense that the stack can grow and shrink during runtime.
   But it does require more memory due to usage of pointers

*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>

using namespace std;

struct StackNode
{
	int data;
	struct StackNode* next;
};

class Stack_LL
{
	public :
		StackNode* new_Node(int data);
		int isEmpty(StackNode *head);
		void push(StackNode **head, int data);
		int pop(StackNode **head);
		int peek(StackNode *head);
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
	return head == NULL;
}

void Stack_LL::push(StackNode** head, int data)
{
	StackNode *new_node = new_Node(data);
	new_node->next = *head;
	*head = new_node;
	cout << data << " is pushed to the stack." << endl;
}

int Stack_LL::pop(StackNode** head)
{
	if (isEmpty(*head))
	{
		return INT_MIN;
	}
	StackNode *temp = *head;
	*head = (*head)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int Stack_LL::peek(StackNode *head)
{
	if (isEmpty(head))
	{
		return INT_MIN;
	}
	return head->data;
}

int main()
{
	StackNode *head = NULL;
	Stack_LL stack;
	stack.push(&head, 10);
	stack.push(&head, 20);
	stack.push(&head, 30);
	cout << stack.pop(&head) << " popped from stack" << endl;
 
    cout << "Top element is " << stack.peek(head) << endl;
 
    return 0;
}