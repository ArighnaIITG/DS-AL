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
		void 
}