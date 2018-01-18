/*
	Memoization 
	===========

	It is also called Top-Down Approach.  The memoized program for a problem
	is similar to the recursive version with a small modification that it looks 
	into a lookup table before computing solutions. We initialize a lookup array
	with all initial values as NIL. Whenever we need solution to a subproblem, we
	first look into the lookup table. If the precomputed value is there then we 
	return that value, otherwise we calculate the value and put the result in lookup
	table so that it can be reused later.

	In this program, we will implement the Fibonacci program using memoized approach.

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define MAX 100

int lookup[MAX];

void initialize()
{
	for(int i=0; i<MAX; i++)
		lookup[i] = NIL;
}

int fib(int n)
{
	if(lookup[n] == NIL)
	{
		if (n <= 1)
			lookup[n] = n;

		else
			lookup[n] = fib(n-1) + fib(n-2);
	}
	return lookup[n];
}

int main()
{
	int n = 40;
  	initialize();

  	cout << "Fibonacci number is " << fib(n) << endl;
  	return 0;
}
