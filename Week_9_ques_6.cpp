#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Ellipse
{
protected:
	double minorAxis, majorAxis;
public:
	//constructor
	Ellipse();
	Ellipse(const double& min, const double& maj);
	Ellipse(const Ellipse& e);

	//Assignment operator
	Ellipse& operator=(const Ellipse& e);
	//getters
	double get_minor_axis() const;
	double get_major_axis() const;
	//setters
	void set_minor_axis(const double& m);
	void set_major_axis(const double& m);
	//other member functions
	double get_area();
	double get_circumfrence();

	//overloaded input and output streaming operator
	void readInfo(istream& in);
	void printInfo(ostream& out);
	friend istream& operator>>(istream& in, Ellipse& e);
	friend ostream& operator<<(ostream& out, const Ellipse e);
};

//constructor
Ellipse::Ellipse()
{
	majorAxis = 0; minorAxis = 0;
}
Ellipse::Ellipse(const double& min, const double& maj)
{
	majorAxis = maj; minorAxis = min;
}
Ellipse::Ellipse(const Ellipse& e)
{
	this->minorAxis = e.get_minor_axis();
	this->majorAxis = e.get_major_axis();
}

//Assignment operator
Ellipse& Ellipse::operator=(const Ellipse& e)
{
	this->majorAxis = e.majorAxis;
	this->minorAxis = e.minorAxis;
	return *this;
}
//getters
double Ellipse::get_minor_axis() const
{
	return minorAxis;
}
double Ellipse::get_major_axis() const
{
	return majorAxis;
}

//setters
void Ellipse::set_minor_axis(const double& m)
{
	this->minorAxis = m;
}

void Ellipse::set_major_axis(const double& m)
{
	this->majorAxis = m;
}
//other member functions
double Ellipse::get_area()
{
	return 3.14 * minorAxis * majorAxis;
}
double Ellipse::get_circumfrence()
{
	double a_sq = pow(minorAxis, 2);
	double b_sq = pow(majorAxis, 2);
	return 2*3.14*pow(((a_sq + b_sq)/2.0), 1/2);
}

//overloaded input and output streaming operator
void Ellipse::readInfo(istream& in)
{
	cout << endl;
	cout << "Reading Ellipse: "<< endl;
	cout << "MinorAxis: "; in >> minorAxis;
	cout << "MajorAxis: "; in >> majorAxis;
}


void Ellipse::printInfo(ostream& out) 
{
	out << "Printing Ellipse: " << endl;
	out << "MinorAxis: "<< minorAxis;
	out << "MajorAxis: " << majorAxis;
	out << "Area: " << get_area() << ", Circumfrence: " << get_circumfrence() << endl;
}

istream& operator>>(istream& in, Ellipse& e)
{
	e.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out, Ellipse e)
{
	e.printInfo(out);
	return out;
}

int main() 
{
    Ellipse e1(3.0, 4.0); // create an Ellipse object with minor axis 3 and major axis 4
    cout << e1 << endl; // print the information of the ellipse using overloaded output stream operator
    cout << "Setting new values: " << endl;
    cin >> e1; // read new values for minor and major axis from user using overloaded input stream operator
    cout << e1 << endl; // print the updated information of the ellipse
	  system("Pause");
    return 0;
}
