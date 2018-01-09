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
	public :
		int evaluatePostfix(string s);
};

int Postfix::evaluatePostfix(string s)
{
	stack <char> st;
	int l = s.length();

	for(int i=0; i<l; i++)
	{
		if(isDigit(s[i]))
		{
			s.push(s[i]);
		}

		else
		{
			int val1 = st.pop();
			int val2 = st.pop();
			switch(s[i])
			{
				case '+' : st.push(val1 + val2);  break;
				case '-' : st.push(val1 - val2);  break;
				case '*' : st.push(val1 * val2);  break;
				case '/' : st.push(val1 / val2);  break;
				case '^' : st.push(val1 ^ val2);  break;
				default : cout << "Wrong choice entered..!" << endl;
			}
		}
	}
	return st.pop();
}

int main()
{
	Postfix p;
	string str = "231+*9-";
	cout << "Value of the postfix expression is " << p.evaluatePostfix(str) << "." << endl;
	return 0;
}
