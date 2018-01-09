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
		int isEmpty(StackNode **head);
		
}