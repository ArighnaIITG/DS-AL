/*
	Stable Marriage Problem :

	The Stable Marriage Problem states that given N men and N women, where each person
	has ranked all members of the opposite sex in order of preference, marry the men and 
	women together such that there are no two people of opposite sex who would both rather 
	have each other than their current partners. If there are no such people, all the 
	marriages are “stable” .

	Consider the following example.

	Let there be two men m1 and m2 and two women w1 and w2.

	Let m1‘s list of preferences be {w1, w2}
	Let m2‘s list of preferences be {w1, w2}
	Let w1‘s list of preferences be {m1, m2}
	Let w2‘s list of preferences be {m1, m2}

	The matching { {m1, w2}, {w1, m2} } is not stable because m1 and w1 would prefer each 
	other over their assigned partners. The matching {m1, w1} and {m2, w2} is stable because 
	there are no two people of opposite sex that would prefer each other over their 
	assigned partners.

	We have the Gale-Shapley Algorithm dedicated towards solving this problem :

	Algorithm :
	=========

	Initialize all men and women to free
	while there exist a free man m who still has a woman w to propose to 
	{
    	w = m's highest ranked such woman to whom he has not yet proposed
	    if w is free
	       (m, w) become engaged
	    else some pair (m', w) already exists
	       if w prefers m to m'
	          (m, w) become engaged
	           m' becomes free
	       else
	          (m', w) remain engaged    
	}

	Input :
	=====

	Input is a 2D matrix of size (2*N)*N where N is number of women or men. Rows from 
	0 to N-1 represent preference lists of men and rows from N to 2*N – 1 represent 
	preference lists of women. So men are numbered from 0 to N-1 and women are numbered 
	from N to 2*N – 1. The output is list of married pairs.

	Output :
	======

	The list of matching pairs.

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

//No. of men or women

#define N 4

// Returns true if woman 'w' prefers a man 'm1' over another man 'm'.
bool man_preference(int prefer[2*N][N], int w, int m1, int m)
{
	for(int i=0; i<N; i++)
	{
		// If m1 comes before m in list of w, then w prefers her
        // current engagement, don't do anything.
		if(prefer[w][i] == m1)
			return true;

		// If m comes before m1 in w's list, then free her current
        // engagement and engage her with m.
		if(prefer[w][i] == m)
			return false;
	}
}

