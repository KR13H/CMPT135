/* Declare a struct called RationalNumber that has two integer member variables. Call the member variables 
a (to mean the numerator) and b (to mean the denominator). Then write a function named toDouble that 
takes one RationalNumber argument and returns the rational number as double. Write a main program to 
test your function.  */


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct RationalNumber
{
	int a; int b;
};

struct RationalNumberD
{
	double a; double b;
};

RationalNumberD to_Double (const RationalNumber r)
{
	RationalNumberD d;
	d.a = r.a;
	d.b = r.b;
	return d;
}

int main()



