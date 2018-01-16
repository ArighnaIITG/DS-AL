// Destructor is a member function of the class used to destruct or delete an object.

// Called automatically when the object gos out of scope.
// or when the function or the program ends.

#include <iostream>
using namespace std;

class String
{
	private :
		char *s;
		int size;

	public :
		String(char *);   //constructor
		~String();		  //destructor
};

String::String(char *c)
{
	size = strlen(c);
	s = new char[size+1];
	strcpy(s,c);
}

String::~String()
{
	delete []s;
}

//Write the main function, taking c as user input