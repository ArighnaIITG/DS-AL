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
		bool isDigit(char c);
		int evaluatePostfix(string s);
};

bool Postfix::isDigit(char c)
{
	string temp = "0123456789";
	bool b = false;
	for(int i=0; i<temp.length(); i++)
	{
		if (c == temp[i])
		{
			b = true;
			break;
		}
	}
	return b;
}

int Postfix::evaluatePostfix(string s)
{
	stack <char> st;
	int l = s.length();

	for(int i=0; i<l; i++)
	{
		if(isDigit(s[i]))
		{
			st.push(s[i] - '0');   // Note this important step.
		}

		else
		{
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();

			switch(s[i])
			{
				case '+' : st.push(val2 + val1);  break;
				case '-' : st.push(val2 - val1);  break;
				case '*' : st.push(val2 * val1);  break;
				case '/' : st.push(val2 / val1);  break;
				case '^' : st.push(val2 ^ val1);  break;
				default : cout << "Wrong choice entered..!" << endl;
			}
		}
	}
	return st.top();
}

int main()
{
	Postfix p;
	string str ;
	cout << "Enter the postfix expression : ";
	cin >> str;
	cout << "Value of the postfix expression is " << p.evaluatePostfix(str) << "." << endl;
	return 0;
}
