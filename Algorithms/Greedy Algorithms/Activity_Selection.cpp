/* Activity Selection is one of the most elementary greedy algorithms.

   Here , you are given n no. of tasks with their start and finish times. The algorithm should
   find out the maximunm no. of tasks a person can execute, assuming that a single person can work
   on a single activity at a particular time.

    Example 1 : Consider the following 3 activities sorted by
    by finish time.
     	start[]  =  {10, 12, 20};
     	finish[] =  {20, 25, 30};
	A person can perform at most two activities. The 
	maximum set of activities that can be executed 
	is {0, 2} [ These are indexes in start[] and 
	finish[] ]

	Example 2 : Consider the following 6 activities 
	sorted by by finish time.
     	start[]  =  {1, 3, 0, 5, 8, 5};
     	finish[] =  {2, 4, 6, 7, 9, 9};
	A person can perform at most four activities. The 
	maximum set of activities that can be executed 
	is {0, 1, 3, 4} [ These are indexes in start[] and 
	finish[] ]

	Here we are assuming that the "finish time array is already sorted".

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void print_activity(int s[], int f[], int n)
{
	
}