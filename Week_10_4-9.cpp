#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Shape
{
private:
	string colour;
public:
	Shape() { colour = "None"; }
	Shape(const string& c) { colour = c; }
	virtual ~Shape() {} 
	string getColour() { return colour; }

	void setColour(const string& c) { colour = c;}

	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual string getType() const = 0;

	virtual void readInfo(istream& in)
	{
		cout << "\tEnter colour: ";
		in >> this->colour;
	}
	virtual void printInfo(ostream& out) const
	{
		cout << "\tColour = " << this->colour << ", Area = " << this->getArea() << ", Perimeter = " << this->getPerimeter() << endl;
	}

	friend istream& operator>>(istream& in, Shape& s) { s.readInfo(in); return in;}
	friend ostream& operator<<(ostream& out, const Shape& s) { s.printInfo(out); return out; }
};

typedef Shape* ShapePtr;




class Rectangle : public Shape
{
private:
	double length, width;
public:
	Rectangle();
	Rectangle(const double&, const double&, const string&);

	double getLength() const;
	double getWidth() const;
	virtual string getType() const { return "Rectangle"; }

	virtual void setLength(const double&);
	virtual void setWidth(const double&);

	//void setColour(const string&);

	double getArea() const;
	double getPerimeter() const;
	//virtual string getType() const;

	virtual void readInfo(istream&);
	virtual void printInfo(ostream&) const;
	//friend istream& operator>>(istream&, Rectangle&);
	//friend ostream& operator<<(ostream&, const Rectangle&);
};
Rectangle::Rectangle() : Shape()
{
	length = 0;
	width = 0;
}
Rectangle::Rectangle(const double& len, const double& wid, const string& c): Shape(c)
{
	length = len;
	width = wid;
}
double Rectangle::getLength() const { return length;}
double Rectangle::getWidth() const { return width; }
//string getType() const { return "Rectangle"; }

void Rectangle::setLength(const double& len) { length = len; }
void Rectangle::setWidth(const double& wid) { width = wid; }

//void setColour(const string&);

double Rectangle::getArea() const { return length*width; }
double Rectangle::getPerimeter() const { return 2*(length + width); }
//virtual string getType() const;

void Rectangle::readInfo(istream& in)
{
	cout << "\t Enter length ";
	in >> length;
	cout << " \t Enter width ";
	in >> width;
	this->Shape::readInfo(in);
}
void Rectangle::printInfo(ostream& out) const
{
	out << endl;
	out << "\t" << getType() << endl;
	out << "\t\tLength = " << length << ", Width = " << width << endl;
	this->Shape::printInfo(out);
}





class Square: public Rectangle
{
public:
	Square();
	Square(const double&, const string&);

	double getSide() const;

	virtual void setLength(const double&);
	virtual void setWidth(const double&);
	void setSide(const double&);

	virtual string getType() const { return "Square"; }

	virtual void readInfo(istream&);
	virtual void printInfo(ostream&) const;
};
Square::Square() : Rectangle() {}
Square::Square(const double& side, const string& c) : Rectangle(side, side, c) {}

double Square::getSide() const
{
	return getLength();
}

void Square::setLength(const double& len)
{
	setSide(len);
}
void Square::setWidth(const double& wid)
{
	setSide(wid);
}
void Square::setSide(const double& side)
{
	this->Rectangle::setLength(side);
	this->Rectangle::setWidth(side);
}

//virtual string getType() const;

void Square::readInfo(istream& in)
{
	double temp;
	cout << "\tEnter side ";
	in >> temp;
	this->setSide(temp);
	this->Shape::readInfo(in);
}
void Square::printInfo(ostream& out) const
{
	out << endl;
	out << "\t" << getType() << endl;
	out << "\t\tSide = " << getSide() << endl;
	this->Shape::printInfo(out);
}

class Triangle : public Shape
{
private:
	double base, height;
public:
	Triangle();
	Triangle(const double&, const double&, const string&);

	double getBase() const;
	double getHeight() const;

	void setBase(const double&);
	void setHeight(const double&);

	double getArea() const;
	double getPerimeter() const;
	string getType() const { return "Triangle"; }

	void readInfo(istream&);
	void printInfo(ostream&) const;
};

Triangle::Triangle(): Shape()
{
	base = 0; 
	height = 0;
}

Triangle::Triangle(const double& b, const double& h, const string& c): Shape(c)
{
	base = b;
	height = h;
}

double Triangle::getBase() const
{
	return base;
}

double Triangle::getHeight() const
{
	return height;
}

void Triangle::setBase(const double& b)
{
	base = b;
}
void Triangle::setHeight(const double& h)
{
	height = h;
}

double Triangle::getArea() const
{
	return 0.5*base*height;
}
double Triangle::getPerimeter() const
{
	return base+height+sqrt(base*base + height*height);
}

void Triangle::readInfo(istream& in)
{
	cout << "\tEnter base ";
	in >> base;
	cout << "\tEnter height ";
	in >> height;
	this->Shape::readInfo(in);
}
void Triangle::printInfo(ostream& out) const
{
	out << getType() << endl;
	out << "\tBase = " << base << ", Height = " << height << endl;
	this->Shape::printInfo(out);
}



class Circle : public Shape
{
private:
	double radius;
	//string colour;
public:
	Circle();
	Circle(const double&, const string&);

	double getRadius() const;
	//string getColour() const;

	void setRadius(const double&);
	

	virtual string getType() const { return "Circle";}

	virtual double getArea() const;
	virtual double getPerimeter() const;

	virtual void readInfo(istream&);
	virtual void printInfo(ostream&) const;
	//friend istream& operator>>(istream&, Circle&);
	//friend ostream& operator<<(ostream&, const Circle&);
};

Circle::Circle() : Shape()
{
	radius = 0;
}

Circle::Circle(const double& r, const string& c) : Shape(c)
{
	radius = r;
}

double Circle::getRadius() const
{
	return radius;
}

void Circle::setRadius(const double& r)
{
	radius = r;
}

double Circle::getArea() const
{
	return 3.14*radius*radius;
}

double Circle::getPerimeter() const
{
	return 2*3.14*radius;
}

void Circle::readInfo(istream& in)
{
	cout << "\Enter radius ";
	in >> radius;
	this->Shape::readInfo(in);
}
void Circle::printInfo(ostream& out) const
{
	out << getType() << endl;
	out << "\tRadius = " << radius << endl;
	this->Shape::printInfo(out);
}

ShapePtr getRandomShapePtr()
{
	string color[] = {"Red", "Blue", "Yellow", "Purple", "Green", "Cyan"};
	switch(rand() % 4)
	{
	case 0:
		cout << "Constructing a Rectangle object" << endl;
		return new Rectangle(rand()%11+5, rand()%11+5, color[rand()%6]);
	case 1:
		cout << "Constructing a Square object" << endl;
		return new Square(rand()%11+5, color[rand()%6]);
	case 2:
		cout << "Constructing a Triangle object" << endl;
		return new Triangle(rand()%11+5, rand()%11+5, color[rand()%6]);
	default:
		cout << "Constructing a Circle object" << endl;
		return new Circle(rand()%11+5, color[rand()%6]);
	}
}

//Write a C++ function named insertGrouped that takes a vector of Shape pointers (whose elements are
//already grouped according to the type of the underlying objects) and a Shape pointer as arguments and
//that inserts the pointer in the vector such that the underlying objects will also be grouped afterwards.
//Your algorithm must be linear. Below is a test main program with supporting functions that you can use to
//test your function. Please make sure to have typedef Shape* ShapePtr just below the Shape class code.
void insertGrouped(vector<ShapePtr>& v, ShapePtr p)
{
	int i = 0;
	for(; i < v.size(); i++)
	{
		if(v[i]->getType() == p->getType())
			break;
	}
	v.insert(v.begin()+i,p);
}

//5. Write a C++ function named insertIncreasing that takes a vector of Shape pointers (whose elements 
//are already sorted in increasing order according to the area of the underlying objects) and a Shape pointer 
//as arguments and that inserts the pointer in the vector such that the underlying objects will also be sorted 
//in increasing order according to their areas afterwards. Please note that grouping together of the same 
//type objects is not needed here.
//Your algorithm must be linear.
//In order to test your function, use the same main program as in Question 4 above with the 
//insertGrouped function call in the main program modified to call the insertIncreasing function 
//cal
void insertIncreasing(vector<ShapePtr>& v, ShapePtr p)
{
	int i = 0;
	for(; i < v.size(); i++)
	{
		if(v[i]->getArea() >= p->getArea())
			break;
	}
	v.insert(v.begin()+i,p);
}

//6. Write a C++ function named insertGroupedSorted that takes a vector of Shape pointers (whose 
//elements are already grouped according to the type of the underlying objects and such that they are 
//sorted in increasing order of their areas) and a Shape pointer as arguments and that inserts the pointer in 
//the vector such that the underlying objects will also be grouped and sorted afterwards.
//Your algorithm must be linear.
//In order to test your function, use the same main program as in Question 4 above with the 
//insertGrouped function call in the main program modified to call the insertGroupedSorted function 
//call.
void insertGroupedSorted(vector<ShapePtr>& v, ShapePtr p)
{
	int i = 0;
	for(; i < v.size(); i++)
	{
		if(v[i]->getType() == p->getType())
			break;
	}
	for(int j = i; j < v.size(); j++)
	{
		if(v[i]->getType() != p->getType())
			break;
		else if(v[i]->getArea() >= p->getArea())
			break;
		i = j + 1;
	}
	v.insert(v.begin()+i,p);
}

//7. Write a C++ function named groupElements that takes a vector of Shape pointers and groups the 
//elements of the vector so that elements of same type will be grouped together. Can you do this in a linear 
//algorithm?
//Hint:- Use your insertGrouped function together with the overloaded assignment operator of the vector 
//class. In order to test your function use the getRandomShapePtr function to push_back several different 
//kinds of objects onto a vector and then call the function groupElements to group the elements and then 
//print your elements to see if they are grouped
void groupElements(vector<ShapePtr>& v)
{
    vector<ShapePtr> grouped;
    for (int i = 0; i < v.size(); i++)
    {
        ShapePtr p = v[i];
        insertGroupedSorted(grouped, p);
    }
    v = grouped;
}

//8.Define a function named sortVector that takes a vector of Shape pointers and sorts the elements of the 
//vector according to the area of the underlying objects. Hint:- Use your insertIncreasing function together with 
//the overloaded assignment operator of the 
//vector class. In order to test your function use the getRandomShapePtr function to push_back several 
//different kinds of objects onto a vector and then call the function sortVector to group the elements and 
//then print your elements to see if they are sorted.
void sortVector(vector<ShapePtr>& v)
{
	vector<ShapePtr> sorted;
	for(int i = 0; i < v.size(); i++)
	{
		ShapePtr p = v[i];
		insertIncreasing(sorted, p);
	}
	v = sorted;
}

//9.Write a C++ function named groupSortElements that takes a vector of Shape pointers and groups the 
//elements of the vector so that elements of same type will be grouped together and within the same group 
//will be sorted in increasing order of their areas. Can you do this in a linear algorithm?
//Hint:- Use your insertGroupedSorted function together with the overloaded assignment operator of 
//the vector class. In order to test your function use the getRandomShapePtr function to push_back 
//several different kinds of objects onto a vector and then call the function insertGroupedSorted to 
//group and sort the elements and then print your elements to see if they are grouped and sorted.
void groupSortElements(vector<ShapePtr>& v)
{
	vector<ShapePtr> groupSorted;
	for(int i = 0; i < v.size(); i++)
	{
		ShapePtr p = v[i];
		insertGroupedSorted(groupSorted, p);
	}
	v = groupSorted;
}




int main()
{
	vector<ShapePtr> v;
	int size;
	cout << "How many objects would you like to insert? ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		ShapePtr p = getRandomShapePtr();
		//insertGrouped(v, p);
		//insertIncreasing(v, p);
		insertGroupedSorted(v, p);
	}
	//Print the objects
	for (int i = 0; i < size; i++)
		cout << *(v[i]) << endl;
	//Destruct the objects
	for (int i = 0; i < size; i++)
		delete v[i];

	system("Pause");
	return 0;
}





