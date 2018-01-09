/* This program evaluates the given postfix expression using stacks.

   Algorithms :

   1) Create a stack to store operands (or values).

   2) Scan the given expression and do following for every scanned element.
        a) If the element is a number, push it into the stack.
        b) If the element is a operator, pop operands for the operator from stack.
           Evaluate the operator and push the result back to the stack.

	3) When the expression is ended, the number in the stack is the final answer.

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

class Postfix
{
	
}