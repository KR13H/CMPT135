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

	//operators
	RationalNumber operator+(const RationalNumber& r) const;
	RationalNumber operator+(const int& r) const;
	friend RationalNumber operator+(const int& x, const RationalNumber& r);
	//Binary subtraction operator that performs r1 - r2
	RationalNumber operator-(const RationalNumber& r) const;
	//Binary subtraction operator that performs r1 - integer
	RationalNumber operator-(const int& x) const;
	// Binary subtraction operator that performs integer - r2
	friend RationalNumber operator-(const int& x, const RationalNumber& r);
	// Binary multiplication operator that performs r1 * r2
	RationalNumber operator*(const RationalNumber& r);
	//Binary multiplication operator that performs r1 * integer
	RationalNumber operator*(const int& r);
	//Binary multiplication operator that performs integer * r2
	friend RationalNumber operator*(const RationalNumber& r, const int& x);
    //Binary division operator that performs r1 / r2
	RationalNumber operator/(const RationalNumber& r);
    //Binary division operator that performs r1 / intege
	RationalNumber& operator/(const int& x);
	// Binary division operator that performs integer / r2
	friend RationalNumber operator/(const RationalNumber& r, const int& x);
	//Binary compound addition operator that performs r1 += r2 ......i.e. r1.operator+=(r2), will return a rational number (r1+r2) and assign it to r1
	RationalNumber& operator+=(const RationalNumber& r);
	//Binary compound addition operator that performs r1 += integer
	RationalNumber& operator+=(const int& r);
	// Binary compound subtraction operator that performs r1 -= r2
	RationalNumber& operator-=(const RationalNumber& r);
	// Binary compound subtraction operator that performs r1 -= integer
	RationalNumber& operator-=(const int& r);
	// Binary compound multiplication operator that performs r1 *= r2
	RationalNumber& operator*=(const RationalNumber& r);
	// Binary compound multiplication operator that performs r1 *= integer
	RationalNumber& operator*=(const int& r);
	// Binary compound division operator that performs r1 /= r2
	RationalNumber& operator/=(const RationalNumber& r);
	// Binary compound division operator that performs r1 /= integer
	RationalNumber& operator/=(const int& r);
	// Binary equal operator that performs r1 == r2
	bool operator==(const RationalNumber& r);
	// Binary equal operator that performs r1 == integer
	bool operator==(const int& r);
	// Binary equal operator that performs integer == r2
	friend bool operator==(const int& x, const RationalNumber& r1);
	// Binary notequal operator that performs r1 != r2
	bool operator!=(const RationalNumber& r);
	// Binary notequal operator that performs r1 != integer
	bool operator!=(const int& x);
	// Binary notequal operator that performs integer != r2
	friend bool operator!=(const int& x, const RationalNumber& r1);
	//Binary > operator (r1 > r1)
	bool operator>(const RationalNumber& r)
	{
		if(this->a*r.b > r.a*this->b) return true;
		return false;
	}
	/*
	// Binary greaterthan operator that performs r1 > r2
	bool operator>(const RationalNumber& r);
	// Binary greaterthan operator that performs r1 >integer
	bool operator>(const int& x);
	// Binary greaterthan operator that performs integer> r2
	friend bool operator>(const int& x, const RationalNumber& r1);
	// Binary lessthan operator that performs r1 < r2
	bool operator<(const RationalNumber& r);
	// Binary lessthan operator that performs r1 <integer
	bool operator<(const int& x);
	// Binary lessthan operator that performs integer< r2
	friend bool operator<(const int& x, const RationalNumber& r1);
	// Binary greaterorequal operator that performs r1 >= r2
	bool operator>=(const RationalNumber& r);
	// Binary greaterorequal operator that performs r1 >= integer
	bool operator>=(const int& x);
	// Binary greaterorequal operator that performs integer>= r2
	friend bool operator<(const int& x, const RationalNumber& r1);
	// Binary lessorequal operator that performs r1 <= r2
	bool operator<=(const RationalNumber& r);
	// Binary lessorequal operator that performs r1 <= integer
	bool operator<=(const int& x);
	// Binary lessorequal operator that performs integer<= r2
	friend bool operator<(const int& x, const RationalNumber& r1);
	*/
	 //Unary operator pre decrement- - as in --r
	RationalNumber& operator--();
	// Unary operator post decrement -- as in r--
	RationalNumber operator--(int DUMMY);


	//SORTING
	friend void sortArray(RationalNumber* &A, int size);
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

//operators
RationalNumber  RationalNumber::operator+(const RationalNumber& r) const
{
	int a1 = this->a;
	int b1 = this->b;
	int a2 = r.a;
	int b2 = r.b;
	RationalNumber sum(a1*b2 + a2*b1, b1*b2);
	return sum;
}
RationalNumber  RationalNumber::operator+(const int& r) const
{
	RationalNumber temp(r,1);
	RationalNumber sum = *this + temp;
	return sum;
}
RationalNumber operator+(const int& x, const RationalNumber& r)
{
	return r.operator+(x);
}
// Binary subtraction operator that performs r1 - r2
RationalNumber RationalNumber::operator-(const RationalNumber& r) const
{
	int a1 = this->a;
	int b1 = this->b;
	int a2 = r.a;
	int b2 = r.b;
	RationalNumber diff(a1*b2 - a2*b1, b1*b2);
	return diff;
}
//Binary subtraction operator that performs r1 - integer
RationalNumber RationalNumber::operator-(const int& x) const
{
	RationalNumber temp(x,1);
	return *this - temp;
}
// Binary subtraction operator that performs integer - r2
RationalNumber operator-(const int& x, const RationalNumber& r)
{
	RationalNumber sub(x,1);
	return sub - r;
}
//Binary multiplication operator that performs r1 * r2
RationalNumber RationalNumber::operator*(const RationalNumber& r)
{
	int a1 = this->a;
	int b1 = this-> b;
	int a2 = r.a;
	int b2 = r.b;
	RationalNumber m(a1*a2, b1*b2);
	return m;
}
//Binary multiplication operator that performs r1 * integer
RationalNumber RationalNumber::operator*(const int& r)
{
	RationalNumber temp(r,1);
	return (*this) * temp;
}
//integer*r1
RationalNumber operator*(const RationalNumber& r, const int& x)
{
	return r*x;
}

//Binary division operator that performs r1 / r2
RationalNumber RationalNumber::operator/(const RationalNumber& r){
	int a1 = this-> a;
	int b1 = this-> b;
	int a2 = r.a;
	int b2 = r.b;
	RationalNumber d(a1*b2, b1*a2);
	return d;}
//Binary division operator that performs r1 / intege
RationalNumber& RationalNumber::operator/(const int& x){
	RationalNumber temp(x,1);
		return *this / temp;}
// Binary division operator that performs integer / r2
RationalNumber operator/(const RationalNumber& r, const int& x){
	RationalNumber temp(x,1);
	return temp/r;}

//Binary compound addition operator that performs r1 += r2 ......i.e. r1.operator+=(r2), will return a rational number (r1+r2) and assign it to r1
RationalNumber& RationalNumber::operator+=(const RationalNumber& r){
	*this = *this + r;
	return *this;}
//Binary compound addition operator that performs r1 += integer
RationalNumber& RationalNumber::operator+=(const int& r){
	RationalNumber temp(r,1);
	*this = *this + r;
	return *this;}
// Binary compound subtraction operator that performs r1 -= r2
RationalNumber& RationalNumber::operator-=(const RationalNumber& r){
	*this = *this - r;
	return *this;}

// Binary compound subtraction RationalNumber::operator that performs r1 -= integer
RationalNumber& RationalNumber::operator-=(const int& r){
	RationalNumber temp(r,1);
	*this = *this - r;
	return *this;}

// Binary compound multiplication operator that performs r1 *= r2
RationalNumber& RationalNumber::operator*=(const RationalNumber& r){
	*this = *this * r;
	return *this;}
// Binary compound multiplication operator that performs r1 *= integer
RationalNumber& RationalNumber::operator*=(const int& r){
	RationalNumber temp(r,1);
	*this = *this * r;
	return *this;}
// Binary compound division operator that performs r1 /= r2
RationalNumber& RationalNumber::operator/=(const RationalNumber& r){
	*this = *this / r;
	return *this;}

// Binary compound division operator that performs r1 /= integer
RationalNumber& RationalNumber::operator/=(const int& r){
	RationalNumber temp(r,1);
	*this = *this / r;
	return *this;}
// Binary equal operator that performs r1 == r2
bool RationalNumber::operator==(const RationalNumber& r){
	if(this->isEqual(r))
		return true;
	return false;
}
// Binary equal operator that performs r1 == integer
bool RationalNumber::operator==(const int& x){
	RationalNumber temp(x,1);
	return *this==temp;
}
// Binary equal operator that performs integer == r2
bool operator==(const int& x, const RationalNumber& r1){
RationalNumber temp(x,1);
bool b = (temp.operator==(r1));
return b;                                     //****************why cann't we do r1 == temp
}
// Binary notequal operator that performs r1 != r2
bool RationalNumber::operator!=(const RationalNumber& r){
if(*this == r)return false;
return true;}
// Binary notequal operator that performs r1 != integer
bool RationalNumber::operator!=(const int& x){
if(*this==x)return false;
return true;}
// Binary notequal operator that performs integer != r2
bool operator!=(const int& x, const RationalNumber& r1){ //******************why is it giving a error here
	RationalNumber temp(x,1);
	if(temp != r1) return true;
	return false;
}
//// Binary greaterthan operator that performs r1 > r2
//bool RationalNumber::operator>(const RationalNumber& r1, const RationalNumber& r2){}
//// Binary greaterthan operator that performs r1 >integer
//friend bool RationalNumber::operator>(const RationalNumber& r1, const int& x){}
//// Binary greaterthan operator that performs integer> r2
//friend bool RationalNumber::operator>(const int& x, const RationalNumber& r1){}
//// Binary lessthan operator that performs r1 < r2
//friend bool RationalNumber::operator<(const RationalNumber& r1, const RationalNumber& r2){}
//// Binary lessthan operator that performs r1 <integer
//friend bool RationalNumber::operator<(const RationalNumber& r1, const int& x){}
//// Binary lessthan operator that performs integer< r2
//friend bool RationalNumber::operator<(const int& x, const RationalNumber& r1){}
//// Binary greaterorequal operator that performs r1 >= r2
//friend bool RationalNumber::operator>=(const RationalNumber& r1, const RationalNumber& r2){}
//// Binary greaterorequal operator that performs r1 >= integer
//friend bool RationalNumber::operator>=(const RationalNumber& r1, const int& x){}
//// Binary greaterorequal operator that performs integer>= r2
//friend bool RationalNumber::operator<(const int& x, const RationalNumber& r1){}
//// Binary lessorequal operator that performs r1 <= r2
//friend bool RationalNumber::operator<=(const RationalNumber& r1, const RationalNumber& r2){}
//// Binary lessorequal operator that performs r1 <= integer
//friend bool RationalNumber::operator>=(const RationalNumber& r1, const int& x){}
//// Binary lessorequal operator that performs integer<= r2
//friend bool RationalNumber::operator<(const int& x, const RationalNumber& r1){}

// Unary operator pre decrement- - as in --r
RationalNumber& RationalNumber::operator--(){
	*this = *this + 1;
	return *this;
}
// Unary operator post decrement -- as in r--
RationalNumber RationalNumber::operator--(int DUMMY){
	RationalNumber temp = *this;
	*this = *this + 1;
	return temp;
}

//Sorting 
void sortArray(RationalNumber* &A, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - 1 - i; j++)
		{
			if(A[j].a * A[j+1].b > A[j+1].a * A[j].b)
			{
				RationalNumber temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
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
	
	sortArray(A, size);
	cout << "Elements of the array after sorting: " << endl;
	for(int i = 0; i < size; i++)
	{
		A[i].print(); cout << endl;
	}
	
	system("Pause");
	return 0;
	}


