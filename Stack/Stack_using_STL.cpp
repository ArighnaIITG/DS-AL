/* Stack is a LIFO data structure, that is the last element to enter the stack
   is the first one to be popped from the stack.

   We can implement a stack using C++ STL.

   The functions associated with stack are:

		empty() – Returns whether the stack is empty.
		size() – Returns the size of the stack.
		top() – Returns a reference to the top most element of the stack.
		push(g) – Adds the element ‘g’ at the top of the stack.
		pop() – Deletes the top most element of the stack.

	This program will show all elements of a stack declared by STL.

*/

#include <iostream>
#include <stack>              // stack class from C++ Standard Template Library (STL).

using namespace std;

void showStack(stack <int> q)
{
	stack <int> g = q;
	while(!g.empty())
	{
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main ()
{
    stack <int> list;
    list.push(10);
    list.push(30);
    list.push(20);
    list.push(5);
    list.push(1);
 
    cout << "The stack list is : ";
    showStack(list);
 
    cout << "\nlist.size() : " << list.size();
    cout << "\nlist.top() : " << list.top();
 
 
    cout << "\nlist.pop() : ";
    list.pop();
    showStack(list);
 
    return 0;
}
