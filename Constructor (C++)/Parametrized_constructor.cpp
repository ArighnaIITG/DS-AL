#include <iostream.h>
using namespace std;
class Point
{
	private :
		int x,y;
	public :
		Point(int x1, int y1)
		{
			x = x1;
			y = y1;
		}
		int getX() { return x; }
		int getY() { return y; }
};

int main()
{
	Point p1(10,15);  // Implicit call
	cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY() << endl;
	return 0;
}

// Default constructor is used when the parameters aren't explicitly required.
// 
// Example --

/*
class Construct
{
	public :
		int a,b;
		Construct()
		{ a=10 , b=20 ; }
}
....
*/
