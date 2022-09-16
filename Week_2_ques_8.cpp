#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Point
{
private:
	double x, y;

public:
	Point();
	Point(double newX, double newY);

	//getters: takes an argument
	void getX(double newX);
	void getY(double newY);

	//setters: returns an argument
	double getX();
	double getY();

	//other functions
	void print();
	int getQuadrant();   
	//gives the distance of the point form the origin
	double getDistance();
	//converts the given point to string
	string toString();
};

Point::Point()
{
	x = 0.0;
	y = 0.0;
}
Point::Point(double newX, double newY)
	:x(newX)
{
	y = newY;
}
void Point::getX(double newX)
{ 
	x = newX;
}
void Point::getY(double newY)
{
	y = newY;
}

//setters: returns an argument
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}

//other functions
void Point::print()
{
	cout << "(" << x << ", " << y <<")" << endl;
}
int Point::getQuadrant()
{
	if(x == 0.0 || y == 0.0)
		return 0;
	else if(x > 0 && y > 0)
		return 1;
	else if(x < 0 && y > 0)
		return 2;
	else if(x < 0 && y < 0)
		return 3;
	else
		return 4;
}
double Point::getDistance()
{
	double d = sqrt(pow(x,2) + pow(y,2));
	return d;
}

string Point::toString()
{
	stringstream ss;
	ss << "(" << x << ", " << y << ")";
	string s = ss.str();
	return s;
}


int main()
{
	Point p1(1, 1), p2(-9, -7.4);
	cout << "The point p1 is " ;
	p1.print();
	cout << "The point p2 is ";
	p2.print();
	cout << "p1 is in quadrant: " << p1.getQuadrant() << endl;
	cout << "p2 is in quadrant: " << p2.getQuadrant() << endl;
	cout << "Distance from the origin is " << p1.getDistance() << endl;
	/////////

	Point p(1,2);
	cout << "Point p is " << p.toString() << endl;

	system("Pause");
	return 0;
}




