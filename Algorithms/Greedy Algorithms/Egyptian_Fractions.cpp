/*
	Egyptian Fractions :

	Every positive fraction can be represented as sum of unique unit fractions.
	A fraction is unit fraction if numerator is 1 and denominator is a positive integer,
	for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction
	as it was used by ancient Egyptians.

	Egyptian Fraction Representation of 2/3 is 1/2 + 1/6.
	Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231.

	We can generate Egyptian Fractions using Greedy Algorithm. For a given number of the
	form ‘nr/dr’ where dr > nr, first find the greatest possible unit fraction, then recur
	for the remaining part. For example, consider 6/14, we first find ceiling of 14/6, i.e., 3.
	So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42.

*/

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

void printEgyptianFraction(int nr, int dr)
{
	if(dr == 0 || nr == 0)
		return;

	if((dr % nr) == 0)
	{
		cout << "1/" << dr/nr;
		return;
	}

	if((nr % dr) == 0)
	{
		cout << nr/dr;
		return;
	}

	if((nr > dr))
	{
		cout << nr/dr << ", ";
		printEgyptianFraction((nr % dr), dr);
		return;
	}

	// If it has reached till here, it means that dr > nr is True, and that dr % nr != 0.
	int n = 1 + (dr/nr);
	cout << "1/" << n << " + ";
	printEgyptianFraction(n*nr - dr, dr*n);
}

int main()
{
    int nr = 6, dr = 14;
    cout << "Egyptian Fraction Representation of "
         << nr << "/" << dr << " is - " << endl;

    printEgyptianFraction(nr, dr);
    return 0;
}
