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


