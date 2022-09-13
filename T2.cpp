#include <iostream>

using namespace std;

class Rectangle
{
private:
	//declare member variables
	double length, width;

public:
	//defining member functions
	//default constructor
	Rectangle();

	//non-default constructor
	Rectangle(double l, double w);

	//getter: they return the member variables
	double getLength();
	double getWidth();
	//setters: assign the member variables some values
	void setLength(double l);
	void setWidth(double w);
	//additional functions:
	double getArea();
	double getPerimeter();
	void print();

};


//defining member functions

//default constructor
Rectangle::Rectangle()
{
	length = 1.0;
	width = 1.0;
}

//non-default constructor
Rectangle::Rectangle(double l, double w)
{
	length = l;
	width = w;
}

//getter: they return the member variables
double Rectangle::getLength()
{
	return length;
}
double Rectangle::getWidth()
{
	return width;
}

//setters: assign the member variables some values
void Rectangle::setLength(double l)
{
	length = l;
}
void Rectangle::setWidth(double w)
{
	width = w;
}
//additional functions:
double Rectangle::getArea()
{
	return length*width;
}
double Rectangle::getPerimeter()
{
	return 2*length + 2*width;
}

void Rectangle::print()
{
	cout << "The length of the rectangle is " << getLength() << endl;
	cout << "The width of the rectangle is " << getWidth() << endl;
	cout << "The area of the rectangle is " << getArea() << endl;
	cout << "The perimeter of the rectangle is " << getPerimeter() << endl;
}


int main()
{

	//Testing the default and non-default constructors
	Rectangle r1, r2(3,4), r3(1,2);
	Rectangle r4 = r2;

	//testing getters and other member functions
	cout << "r1 length = " << r1.getLength() << endl;
	cout << "r2 width = " << r2.getWidth() << endl;
	cout << "r3 area = " << r3.getArea() << endl;
	cout << "r4 perimeter = " << r4.getPerimeter() << endl;

	//testing the print member function
	cout << "Rectangle r1 is ";
	r1.print();
	cout << endl;
	cout << "Rectangle r2 is ";
	r2.print();
	cout << endl;

	//testing setters
	r1.setLength(5);
	r1.setWidth(9);
	cout << "After modifying its length and width, r1 is now ";
	r1.print();
	cout << endl;

	system("Pause");
	return 0;
}


