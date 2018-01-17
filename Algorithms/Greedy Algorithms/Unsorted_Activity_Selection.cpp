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

void ActivitySelection::printActivity(Activity arr[], int n)
{
	//Sort tasks according to the increasing finish time.
	sort(arr, arr+n, compareActivity);

	int i, j;
	cout << "Following activities are selected : " << endl;

	// The first activity always gets selected.
	i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

	for(j=1; j<n; j++)
	{
		//Same logic as previos function
		if(arr[j].start >= arr[i].finish)
		{
			cout << "(" << arr[j].start << ", " << arr[j].finish << "), ";
			i = j;
		}
	}
}

// Driver program
int main()
{
	ActivitySelection act;
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                                       {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);

    act.printActivity(arr, n);
    return 0;
}
