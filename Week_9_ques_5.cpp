#include <iostream>
using namespace std;
class MyRectangle
{
protected:
	double length, width;
public:
	//Constructors
	MyRectangle();
	MyRectangle(const double &len, const double &wid);
	MyRectangle(const MyRectangle &r);
	//Getters
	double getLength() const;
	double getWidth() const;
	//Setters
	void setLength(const double &len);
	void setWidth(const double &wid);
	//Other member functions
	double getArea() const;
	double getPerimeter() const;
	friend ostream& operator << (ostream &out, const MyRectangle &r);
	friend istream& operator >> (istream &in, MyRectangle &r);
};

// Default constructor
MyRectangle::MyRectangle() 
{
    length = 0.0;
    width = 0.0;
}

// non-default constructor
MyRectangle::MyRectangle(const double &len, const double &wid) 
{
    length = len;
    width = wid;
}

//Copy constructor
MyRectangle::MyRectangle(const MyRectangle &r) 
{
    length = r.length;
    width = r.width;
}

// Getter for length
double MyRectangle::getLength() const 
{
    return length;
}

// Getter for width
double MyRectangle::getWidth() const 
{
    return width;
}

// Setter for length
void MyRectangle::setLength(const double &len) 
{
    length = len;
}

// Setter for width
void MyRectangle::setWidth(const double &wid) 
{
    width = wid;
}

// Calculate and return the area of the rectangle
double MyRectangle::getArea() const 
{
    return length * width;
}

// Calculate and return the perimeter of the rectangle
double MyRectangle::getPerimeter() const 
{
    return 2 * (length + width);
}

// Overloading the << operator to output a MyRectangle object to a stream
ostream& operator << (ostream &out, const MyRectangle &r) 
{
	out << "Rectangle object: ";
	out << "Length: " << r.length << ", Width: " << r.width << ", Area: " << r.getArea() << ", Perimeter: " << r.getPerimeter() << endl;
    return out;
}

// Overloading the >> operator to input a MyRectangle object from a stream
istream& operator >> (istream &in, MyRectangle &r) 
{
	cout << "Reading Reactangle object: " << endl;
    cout << "Enter length: ";
    in >> r.length;
    cout << "Enter width: ";
    in >> r.width;
    return in;
}

class MySquare : public MyRectangle
{
public:
	//Constructors
	MySquare();
	MySquare(const double &side);
	MySquare(const MySquare &s);
	//Getters
	double getSide() const;
	//Setters
	void setLength(const double &len);
	void setWidth(const double &wid);
	void setSide(const double &side);
	//Other member functions
	friend ostream& operator << (ostream &out, const MySquare &s);
	friend istream& operator >> (istream &in, MySquare &s);
};

MySquare::MySquare() : MyRectangle() {}
MySquare::MySquare(const double &side) : MyRectangle(side, side) {}
MySquare::MySquare(const MySquare &s) : MyRectangle(s) {}

double MySquare::getSide() const
{
	return length;
}

void MySquare::setLength(const double &side) 
{
	MyRectangle::setLength(side);
	MyRectangle::setWidth(side);
}

void MySquare::setWidth(const double &side) 
{
	MyRectangle::setLength(side);
	MyRectangle::setWidth(side);
}
void MySquare::setSide(const double &side)
{
	MyRectangle::setLength(side);
	MyRectangle::setWidth(side);
}

ostream& operator << (ostream &out, const MySquare &s)
{
	out << "Square object: ";
	out << "Side: " << s.getSide() << ", Area: " << s.getArea() << ", Perimeter: " << s.getPerimeter() << endl;
	return out;
}

istream& operator >> (istream &in, MySquare &s)
{
	cout << "Reading square object: " << endl;
	cout << "Enter side: "; in >> s.length;
	s.setSide(s.length); //*********
	return in;
}

int main()
{
	//Test Constructors, getters and output streaming operator
	MyRectangle r1;
	MyRectangle r2(2, 3);
	MyRectangle r3 = r2;
	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;

	MySquare s1;
	MySquare s2(3);
	MySquare s3 = s2;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;

	//Test setters
	r2.setLength(5);
	r3.setWidth(6);
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;
	s1.setLength(8);
	s2.setWidth(4);
	s3.setSide(6);
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;

	//Test input stream operators
	cin >> r1;
	cin >> s1;
	cout << "r1: " << r1 << endl;
	cout << "s1: " << s1 << endl;

	//Test type casting
	MyRectangle r4 = s1;
	cout << "r4: " << r4 << endl;
	cout << "s2 casted to rectangle: " << static_cast<MyRectangle>(s2) << endl;

	system("Pause");
	return 0;
}
