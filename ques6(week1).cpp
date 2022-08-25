/*Write a function named standardize that takes one RationalNumber argument by reference and then 
makes sure that denominator is always kept positive and the numerator modified accordingly. Example if 
the argument contains a=2, b=-5 then the function must modify a and b so that a = -2 and b = 5 which is 
the same rational number as the original but written in a standard way. Discuss with your colleagues what 
the function should return and what the function should do if 
 Both a and b are positive,
 Both a and b are negative,
 a is negative and b is positive, and
 a is positive and b is negative.
Write a main program to test your function.      */


#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

struct RationalNumber
{
	int a; int b;
};

//Pre-condition: takes a Rational number
//Post-condition: returns a rational number in standard form
RationalNumber standardize(RationalNumber r)
{
	RationalNumber R;
	if(r.a > 0 && r.b < 0)
	{
		R.a = -1*(r.a);
		R.b = abs(r.b);
		return R;
	}
	else if(r.a < 0 && r.b < 0)
	{
		R.a = abs(r.a);
		R.b = abs(r.b);
		return R;
	}
	else
	{
		R = r;
		return R;
	}
}

//converting rational number to a string

string toString(RationalNumber r)
{
	stringstream ss;
	ss << "Numerator = " << r.a << ", " << "Denomenator = " << r.b;
	string s = ss.str();
	return s;
}

int main()
{
	RationalNumber r;
	cout << "Please enter the numerator: ";
	cin >> r.a;

	cout << "Please enter the denomenator: ";
	cin >> r.b;

	RationalNumber inS = standardize(r);

	cout << "The rational number in standard form is: " << toString(inS) << endl;


	system("Pause");
	return 0;
}






