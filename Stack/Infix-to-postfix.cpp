/* This program implements the idea of stacks to convert an infix expression to a postfix expression.

   Algorithm

	1. Scan the infix expression from left to right.
	2. If the scanned character is an operand, output it.
	3. Else,
		…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator 
				in the stack(or the stack is empty), push it.
		…..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator is 
				less-equal to the precedence of the operator residing on the top of the stack.
				Push the scanned operator to the stack.

	4. If the scanned character is an ‘(‘, push it to the stack.
	5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
	6. Repeat steps 2-6 until infix expression is scanned.
	7. Pop and output from the stack until it is not empty.

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

class Infix_to_Postfix
{
	public :
		int prec(char c);
		void infixToPostfix(string s);
};

int Infix_to_Postfix::prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void Infix_to_Postfix::infixToPostfix(string s)
{
	stack <char> st;
	st.push('~');
	string temp;
	int l = s.length();

	for(int i=0; i<l; i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			temp += s[i];

		else if (s[i] == '(')
			st.push('(');

		else if (s[i] == ')')
		{
			while(st.top() != '~' && st.top() != '(')
			{
				char c = st.top();
				st.pop();
				temp += c;
			}
			if (st.top() == '(')
			{
				char c = st.top();
				st.pop();
			}
		}

		else 
		{
			while(st.top() != '~' && (prec(s[i]) <= prec(st.top())))
			{
				char c = st.top();
				st.pop();
				temp += c;
			}
			st.push(s[i]);
		}
	}

	while (st.top() != '~')
	{
		char c = st.top();
		st.pop();
		temp += c;
	}
	cout << temp << endl;
}

int main()
{
	Infix_to_Postfix stack_expr;

	string str = "a+b*(c^d-e)^(f+g*h)-i";
	stack_expr.infixToPostfix(str);
	return 0;
}

/*
	Output :

		abcd^e-fgh*+^*+i-

        [Finished in 0.7s]
*/