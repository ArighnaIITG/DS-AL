// This program lists out the various functionalities of 'Set' in C++ STL.

#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	set < int, greater <int> > s; 
	// greater <int> is an internal comparison object of type Compare.
	// More about greater int - http://www.cplusplus.com/reference/set/set/ ('Compare' section)

	//Inserts elements in random order
	s.insert(60);
	s.insert(10);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	s.insert(30);   // Will occur in set only once.
	s.insert(50);

	set < int, greater <int> > :: iterator it;

	cout << "The set is : ";
	for(it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;

	// assigning elements into a new set.
	set < int > s2(s.begin(), s.end());
	// set < int , greater <int> > s2(s.begin(), s.end()); -- Here 's2' will be in a decressing fashion.

	cout << "The new set is : ";
	for(it = s2.begin(); it != s2.end(); it++)
		cout << *it << " ";
	cout << endl;

	// Removing elements upto 30.
	cout << "s2 after removal of elements less than 30 : ";
    s2.erase(s2.begin(), s2.find(30));
    for (it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Remove element with value 50 in s2.
    int num;
    num = s2.erase (50);  // num = 1.
    cout << "s2.erase(50) : ";
    cout << num << " removed : " ;
    for (it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

	return 0;
}