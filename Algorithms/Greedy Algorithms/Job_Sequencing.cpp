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

*/

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

