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
RationalNumber::RationalNumber() 
{
	int r = rand()%11 - 5;
	 a = rand()%11 - 5; 
	 b = r != 0 ? r: 1;
	 reduce();
	 standardize();
}
RationalNumber::RationalNumber(const int& a, const int& b)
{
	this->a = a;
	this->b = b != 0 ? b: 1;
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

//Other functions 
//Pre-condition: takes an array of rational numbers as an inpiut and computes the max
//Post-condition: returns the rational number that is max
RationalNumber Max(RationalNumber* r, int size)
{
	double max = r[0].toDouble();
	int index = 0;
	for(int i = 1; i < size; i++)
	{
		if(max < r[i].toDouble()){
			max = r[i].toDouble();
			index = i; }
	}
	return r[index];
}

RationalNumber Min(RationalNumber* r, int size)
{
	double min = r[0].toDouble();
	int index = 0;
	for(int i = 1; i < size; i++)
	{
		if(min > r[i].toDouble()){
			min = r[i].toDouble();
			index = i; }
	}
	return r[index];
}
//this function will check whether the array created has any positive rational number
bool isPositive(RationalNumber* r, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(r[i].getNum() >= 0 && r[i].getDen() >= 0)
			return true;
		return false;
	}
}


int main()
{
	int size;
	cout << "Please enter the size of the array: ";
	cin >> size;
	RationalNumber* A = new RationalNumber[size];
	cout << "Elements of the array are: " << endl;
	//Printing elements of the array
	for(int i = 0; i < size; i++)
	{
		A[i].print(); cout << endl;
	}
	
	if(isPositive(A,size) == false)
	{
		cout << "No minimum or maximum elements" << endl;
		system("Pause");
		return 0;
	}

	RationalNumber M = Max(A,size);
	cout << "Maximum number is "; M.print(); cout << endl; 
	RationalNumber m = Min(A,size);
	cout << "Minimum number is "; m.print(); cout << endl;
	

	system("Pause");
	return 0;
	}




