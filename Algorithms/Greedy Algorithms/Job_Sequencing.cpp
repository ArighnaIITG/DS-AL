/* 
	Job Sequencing Problem :

	Given an array of jobs where every job has a deadline and associated profit
	if the job is finished before the deadline. It is also given that every job takes
	single unit of time, so the minimum possible deadline for any job is 1.
	How to maximize total profit if only one job can be scheduled at a time.

	Example 
	=======

	Input:  Five Jobs with following deadlines and profits--

   		JobID     Deadline     Profit
     	  a         2           100
     	  b         1           19
     	  c         2           27
     	  d         1           25
     	  e         3           15
	
	Output: Following is maximum profit sequence of jobs --
        	c, a, e

    We can solve it using "Greedy Algorithm" :
    
    1) Sort all jobs in decreasing order of profit.
	2) Initialize the result sequence as first job in sorted jobs.

	3) Do following for remaining n-1 jobs
.			a)  If the current job can fit in the current result sequence 
          		without missing the deadline, add current job to the result.
          		Else ignore the current job.

    Input to this program will be an array of structures.

*/

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Job
{
	char id;
	int dead;
	int profit;
};

bool compareJobs(Job a, Job b)
{
	return (a.profit > b.profit);     // We have to sort jobs in descending order.
}

void printJobSequence(Job arr[], int n)
{
	//Sort jobs according to the descending order of profit.
	sort(arr, arr+n, compareJobs);

	int result[n];    // Result sequence
	bool slot[n];     // Queries about whether slots are free or not

	// Initializing all slots to false now.
	for(int i=0; i<n; i++)
		slot[i] = false;

	// Iterating through all the given jobs
	for(int i=0; i<n; i++)
	{
		// Important - "We are starting from the last possible slot."
		for(int j = min(n, arr[i].dead) -1; j>=0; j--)
		{
			// Find free slots
			if(slot[j] == false)
			{
				result[j] = i;   // Add this job to the result sequence
				slot[j] = true;  // Make this slot occupied.
				break;
			}
		}
	}

	// Print the result sequence
	for(int i=0; i<n; i++)
	{
		if(slot[i] == true)
			cout << arr[result[i]].id << " - ";
	}
}

int main()
{
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Following is maximum profit sequence of jobs -- " << endl;
    printJobSequence(arr, n);
    return 0;
}
