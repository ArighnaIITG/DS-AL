// This program lists out all the functionalities of Map in C++ STL.

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	map <int, int> m;

	m.insert(pair <int, int> (1, 40));
	m.insert(pair <int, int> (4, 80));
	m.insert(pair <int, int> (3, 50));
	m.insert(pair <int, int> (2, 70));
	m.insert(pair <int, int> (6, 40));
	m.insert(pair <int, int> (5, 80));

	map <int, int> :: iterator it, it1;
	cout << "The map is : " << endl;

	for(it=m.begin(); it!=m.end(); it++)
		cout << '\t' << it->first << '\t' << it->second << endl;

	cout << endl;
	/* The map is :

		1	40
		2	70
		3	50
		4	80
		5	80
		6	40

		The keys are always in sorted order, in an increasing fashion.
	*/

	// assigning values to m2.
	map <int, int> m2(m.begin(), m.end());

	it1 = m2.find(3);
	m2.erase(m2.begin(), it1);

	for(it=m2.begin(); it!=m2.end(); it++)
		cout << "\t" << it->first << "\t" << it->second << endl;
	cout<<endl;

	// Same functionality as set functions.
	cout << m2.lower_bound(5)->first << '\t' << m2.lower_bound(5)->second << endl;
	cout << m2.upper_bound(5)->first << '\t' << m2.upper_bound(5)->second << endl;

	return 0;
}