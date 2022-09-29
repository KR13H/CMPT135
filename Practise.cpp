#include <iostream>
using namespace std;

class Complex
{
private:
	double real, img;
	static int count;
public:
	//Consturctors
	Complex();
	Complex(const double& r, const double& i);

	//getters
	double getR() const;
	double getI() const;
	static int getCount();

	//setters
	void setR(const double& r);
	void setI(const double& i);

	//operators
	Complex operator+(const Complex& c) const;// C + C
	Complex operator+(const int& x) const;    //C + int
	Complex operator-() ;                // -C
	Complex& operator++() ;              //C++
	Complex operator++(int DUMMY) ;      //++C

	friend Complex operator+(const int& x, const Complex& c); // int + C
	

	//input streaming 
	friend istream& operator>>(istream& in, Complex& c);
	//output streaming 
	friend ostream& operator<<(ostream& out, const Complex& c);
};
int Complex::count = 0;

//Consturctors
Complex::Complex(): real(0), img(0){count++;}
Complex::Complex(const double& r, const double& i)
{
	real = r;
	img = i;
	count++;
}

//getters
double Complex::getR() const{return real;}
double Complex::getI() const{return img;}
int Complex::getCount(){return count;}

//setters
void Complex::setR(const double& r){real = r;}
void Complex::setI(const double& i){real = i;}

//operators
//C+C
Complex Complex::operator+(const Complex& c) const{
	double r1 = this->real;
	double i1 = this-> img;
	double r2 = c.real;
	double i2 = c.img;
	Complex cn(r1+r2, i1+i2);
	return cn;}
//C + int
Complex Complex::operator+(const int& x) const{ 
	Complex temp(x,0);
	return *this + temp;}
//-C
Complex Complex::operator-() {
	this->real *= -1;
	this->img *= -1;
	return *this;
}
//C++
Complex& Complex::operator++() {
	*this = *this + 1;
	return *this;
}
//++C
Complex Complex::operator++(int DUMMY) {
	Complex temp = *this;
	*this = *this + 1;
	return temp;}
// int + C
Complex operator+(const int& x, const Complex& c){
	return c + x;}
//input streaming 
istream& operator>>(istream& in, Complex& c){
	cout << endl;
	cout << "\tPlease enter the real part of your complex number: ";
	in >> c.real;
	cout << "\tPlease enter the imaginary part of you complex number: ";
	in >> c.img;
	return in;
}
//output streaming 
ostream& operator<<(ostream& out, const Complex& c){
	if(c.img >= 0) out << c.real << "+" << c.img << "i";
	else out << c.real << c.img << "i";
	return out;
}

int main()
{
	Complex c1, c2(5,6);
	cout << c1 << endl;
	cout << c2 << endl;
	Complex c3 = -c1 + c2;
	cout << c3 << endl;
	c3 = -c3;
	cout << c3 << endl;
	c3++++;
	cout << c3 << endl;
	Complex c4 = ++c3;
	cout << c4 << endl;
	c4 = c4 + 5;
	cout << c4 << endl;
	c4 = 3 + c4;
	cout << c4 << endl;
	Complex c5;
	cout << "Please enter a complex number: ";
	cin >> c5;
	cout << "The new complex number you entered is: " << c5 << endl;
	system("Pause");
	return 0;
}
