/* 
	This program implements activity selection when the "finish time array is not sorted".
	We sort the array using sort() in C++ STL.

	The input in this program is an array of structures.
*/

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct Activity
{
	int start;
	int finish;
};

class ActivitySelection
{
	public :
		bool compareActivity(Activity a1, Activity a2);
		void printActivity(Activity arr[], int n);
};

bool ActivitySelection::compareActivity(Activity a1, Activity a2)
{
	return (a1.finish < a2.finish);
}

void ActivitySelection::printActivity(Activity arr90, int n)
{
	//Sort tasks according to the increasing finish time.
	sort(arr, arr+n, compareActivity);

	int i, j;
	
}