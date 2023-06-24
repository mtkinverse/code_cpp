#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
	friend void SwapPoints(Point&, Point&);
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	int getX()const { return x; }
	int getY()const { return y; }
};
void SwapPoints(Point& p1, Point& p2) {
	int temp = p1.x;
	p1.x = p2.x;
	p2.x = temp;

	temp = p1.y;
	p1.y = p2.y;
	p2.y = temp;
 }

int main()
{
	Point p1(2,3);
	Point p2(5,6);

	cout << "The current values of first point\n X = " << p1.getX() << "\tY = " << p1.getY() << "\n\nThe current values of Second point\n X = " << p2.getX() << "\tY = " << p2.getY() << endl;
	SwapPoints(p1, p2);
	cout << "\n* The Values after swapping *\nThe current values of first point\n X = " << p1.getX() << "\tY = " << p1.getY() << "\n\nThe current values of Second point\n X = " << p2.getX() << "\tY = " << p2.getY() << endl;
}