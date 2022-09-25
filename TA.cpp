#include <iostream>
using namespace std;

class RationalNumber
{
private:
	int a, b;
public:
	//Constructors
	RationalNumber();
	RationalNumber(const int& a, const int& b);
	//setters
	void setNum(const int& a);
	void setDen(const int& b);
	//getters
	int getNum() const;
	int getDen() const;
	//Additional member functions
	double toDouble() const;
	void standardize();
	void reduce();
	void print() const;
	bool isEqual(const RationalNumber& r) const;
	bool isNotEqual(const RationalNumber& r) const;
	bool isGreaterThan(const RationalNumber& r) const;
	bool isGreaterThanOrEqual(const RationalNumber& r) const;
	bool isLessThan(const RationalNumber& r) const;
	bool isLessThanOrEqual(const RationalNumber& r) const;
};

//Constructors
RationalNumber::RationalNumber(): a(0), b(1){}
RationalNumber::RationalNumber(const int& a, const int& b)
{
	this->a = a;
	this->b = b;
	standardize();
	reduce();
}
//setters
void RationalNumber::setNum(const int& a)
{
	this->a = a;
	standardize();
	reduce();
}
void RationalNumber::setDen(const int& b)
{
	this->b = b != 0 ? b : 1;
	standardize();
	reduce();
}
//getters
int RationalNumber::getNum() const
{
	return this->a;
}
int RationalNumber::getDen() const
{
	return this->b;
}
//Additional member functions
double RationalNumber::toDouble() const
{
	return static_cast<double>(a)/b;
}
void RationalNumber::standardize()
{
	if(this-> b < 0)
	{
		this->a *= -1;
		this->b *= -1;
	}
}
void RationalNumber::reduce()
{
	if(this->a == 0)
	{
		this->b = 1;
		return;
	}
	else
	{
		int n = abs(this->a);
		int m = abs(this->b);
		int gcd = n < m ? n : m;
		while(gcd > 0)
		{
			if(n % gcd == 0 && m % gcd == 0)
				break;
			gcd--;
		}
		//cout << "gcd = " << gcd << endl;
		this->a /= gcd;
		this->b /= gcd;
	}
}
void RationalNumber::print() const
{
	cout << a << "/" << b;
}
bool RationalNumber::isEqual(const RationalNumber& r) const
{
	if(this->a* r.b == this->b* r.a)
		return true;
	return false;
}
bool RationalNumber::isNotEqual(const RationalNumber& r) const
{
	if(isEqual(r))
		return false;
	return true;
}
bool RationalNumber::isGreaterThan(const RationalNumber& r) const
{
	if(this->a * r.b > r.a* this->b)
		return true;
	return false;
}
bool RationalNumber::isGreaterThanOrEqual(const RationalNumber& r) const
{
	if(this->a * r.b >= r.a * this->b)
		return true;
	return false;
}
bool RationalNumber::isLessThan(const RationalNumber& r) const
{
	if(isEqual(r))
		return false;
	return true;
}
bool RationalNumber::isLessThanOrEqual(const RationalNumber& r) const
{
	if(isGreaterThanOrEqual(r))
		return false;
	return true;
}

int main()
{
	//Test constructors
	RationalNumber r1, r2(5,6);
	const RationalNumber* r3 = new RationalNumber();  //we can not give a varaible on the heap as a const 
	const RationalNumber* r4;
	r4 = new RationalNumber(4, -6);

	/*
	//Test getters
	cout << "r1 numerator is " << r1.getNum() << endl;
	cout << "r3 denominator is " << r3->getDen() << endl;

	//Test setters, standardize, reduce and print member functions
	r2.setDen(-10);
	cout << "r2 is now "; r2.print(); cout << endl;

	//Print all the objects
	cout << "r1 = "; r1.print(); cout << endl;
	cout << "r2 = "; r2.print(); cout << endl;
	cout << "r3 = "; r3->print(); cout << endl;
	cout << "r4 = "; r4->print(); cout << endl;

	//Test toDouble member function
    cout << "In double format, r4 = " << r4->toDouble() << endl;
	*/
	if(r1.isNotEqual(r2))
		cout << "r1 and r2 are not equal" << endl;
	else
		cout << "r1 and r2 are equal" << endl;

	if(r4->isNotEqual(r2))
		cout << "r4 and r2 are not equal" << endl;
	else
		cout << "r2 and r4 are equal" << endl;

	if(r4->isGreaterThan(r1))
		cout << "Yes r2 is greater than r1" << endl;
	else
		cout << "No r2 is not greater than r1" << endl;



	//Delete objects created on the heap
	delete r3;
	delete r4;

	system("Pause");
	return 0;
	}




