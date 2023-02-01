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


	//Overloaded operators 
	bool operator<(const RationalNumber& r) const;
	bool operator>(const RationalNumber& r) const;
	friend istream& operator>>(istream& in, RationalNumber& r);
	friend ostream& operator<<(ostream& out, const RationalNumber& r);
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
istream& operator>>(istream& in, RationalNumber& r)
{
	cout << endl;
	cout << "\t Please enter the numerator: ";
	in >> r.a;
	cout << "\t Please enter the denominator: ";
	in >> r.b;
	//In case the input value for the denominator is zero, read it again 
	while(r.b == 0)
	{
		cout << "Denominator can not be zero. Please enter a non-zero denominator ";
		in >> r.b;
	}
	r.standardize();
	r.reduce();
	return in;
}

ostream& operator<<(ostream& out, const RationalNumber& r)
{
	out << r.a << "/ " << r.b << endl;
	return out;
}

bool RationalNumber::operator<(const RationalNumber& r) const
{
	return this->a*r.b < r.a*this->b;
}
bool RationalNumber::operator>(const RationalNumber& r) const
{
	return this->a*r.b > r.a*this->b;
}

int main()
{
	int size;
	cout << "Please enter the size of the array: ";
	cin >> size;
	
	//Declare a dynamic array
	RationalNumber* Arr = new RationalNumber[size];
	//set the num and dem to a rand number in the range[-5, 5]
	for(int i = 0; i < size; i++)
	{
		Arr[i].setNum(rand()%11 - 5);
		Arr[i].setDen(rand()%11 - 5);
	}


	//Print all the elements of the array
	cout << "All the elements of the array are: " << endl;
	for(int i = 0; i < size; i++)
	{
		cout << Arr[i] << endl;
	}

	//let the first element of the array to be the max and min
	RationalNumber max = Arr[0];
	RationalNumber min = Arr[0];

	for(int i = 1; i < size; i++)
	{
		if(Arr[i] < min)
			min = Arr[i];
		if(Arr[i] > max)
			max = Arr[i];
	}

	//Print the max and min element in the array
	cout << "The max element in the array is " << max << endl;
	cout << "The min element in the array is " << min << endl;
	
	delete[] Arr;

	system("Pause");
	return 0;
}



ques 8

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

	//Overloaded operators 
	bool operator<(const RationalNumber& r) const;
	bool operator<(const int& x) const;
	bool operator>(const RationalNumber& r) const;
	bool operator>(const int& x) const;
	bool operator>=(const RationalNumber& r) const;
	bool operator>=(const int& x) const;
	friend istream& operator>>(istream& in, RationalNumber& r);
	friend ostream& operator<<(ostream& out, const RationalNumber& r);
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
istream& operator>>(istream& in, RationalNumber& r)
{
	cout << endl;
	cout << "\t Please enter the numerator: ";
	in >> r.a;
	cout << "\t Please enter the denominator: ";
	in >> r.b;
	//In case the input value for the denominator is zero, read it again 
	while(r.b == 0)
	{
		cout << "Denominator can not be zero. Please enter a non-zero denominator ";
		in >> r.b;
	}
	r.standardize();
	r.reduce();
	return in;
}

ostream& operator<<(ostream& out, const RationalNumber& r)
{
	out << r.a << "/ " << r.b << endl;
	return out;
}

bool RationalNumber::operator<(const RationalNumber& r) const
{
	return this->a*r.b < r.a*this->b;
}
bool RationalNumber::operator>(const RationalNumber& r) const
{
	return this->a*r.b > r.a*this->b;
}
bool RationalNumber::operator<(const int& x) const
{
	RationalNumber temp(x,1);
	return *this < temp;
}
bool RationalNumber::operator>(const int& x) const
{
	RationalNumber temp(x,1);
	return *this > temp;
}
bool RationalNumber::operator>=(const RationalNumber& r) const
{
	if(this->a*r.b == this->b*r.a)
		return true;
	else if(*this > r)
		return true;
	else
		return false;
}
bool RationalNumber::operator>=(const int& x) const
{
	RationalNumber temp(x,1);
	if(*this >= temp)
		return true;
	return false;
}

//Returns false if there is no positive rational number in the array
bool checkPositive(const RationalNumber* Arr, int size) 
{
	for(int i = 0; i < size; i++)
	{
		if(Arr[i] > 0)
			return true;
	}
	return false;
}


int main()
{
	int size;
	cout << "Please enter the size of the array: ";
	cin >> size;
	
	//Declare a dynamic array
	RationalNumber* Arr = new RationalNumber[size];
	//set the num and dem to a rand number in the range[-5, 5]
	for(int i = 0; i < size; i++)
	{
		Arr[i].setNum(rand()%11 - 5);
		Arr[i].setDen(rand()%11 - 5);
	}

	//Printing the elements in the array
	cout << "The elements in the array are: " << endl;
	for(int i = 0; i < size; i++)
	{
		cout << Arr[i] << endl;
	}


	if(checkPositive(Arr,size))
	{
		RationalNumber Positive_min, Positive_max;
		bool Positive_min_set = false, Positive_max_set = false;
		for(int i = 0; i < size;i++)
		{
			if(Arr[i] >= 0)
			{

				if(!Positive_min_set||Arr[i] < Positive_min)
				{
					Positive_min = Arr[i];
					Positive_min_set = true;
				}
				if(!Positive_max_set||Arr[i] > Positive_max)
				{
					Positive_max = Arr[i];
					Positive_max_set = true;
				}
			}
		}
		cout << "Positive max element is " << Positive_max << endl;
		cout << "Positive min element is " << Positive_min << endl;
	}
	else
	{
		cout << "There is no positive min or max element in the array of the RationalNumbers" << endl;
		system("Pause");
		return 0;
	}

		


	system("Pause");
	return 0;
}

