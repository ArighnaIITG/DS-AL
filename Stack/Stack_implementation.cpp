/* This program implements and lists out the basic operations which are possible on a stack.

Mainly the following three basic operations are performed in the stack:

    1. Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
    2. Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed.
            If the stack is empty, then it is said to be an Underflow condition.

    3. Peek or Top: Returns top element of stack.
    4. isEmpty: Returns true if stack is empty, else false.

*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
	int top;    // Stack pointer

	public :
		int a[MAX];  // Maximum size of the stack 
		Stack()      // Constructor
		{
			top = -1;     // The stack pointer is at first initialized to the bottom of the stack.
		}
		bool push(int x);
		int pop();
		bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= MAX)
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}
 
int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
 
bool Stack::isEmpty()
{
    return (top < 0);
}
 
// Driver program to test above functions
int main()
{
    struct Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
 
    cout << s.pop() << " Popped from stack\n";
 
    return 0;
}

