/* 7. Write a function named reduce that takes one RationalNumber argument by reference and reduces the 
rational number. Reduction of rational number means to write the rational number in the simplest form 
possible. Example 7/21 is reduced to 1/3; 2/4 is reduced to 1/2; 15/5 is reduced to 3/1 and so on so forth. 
Don't jump to write program. Instead think carefully how do we do reduction by hand. Hint:- What is the 
definition of GCD? What does it have to do with reduction of rational numbers? What does the function 
return? Write a main program to test your function */

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

struct RationalNumber
{
	int a; int b;
};

//this function returns the gcd of two numbers
//Pre-condtion: b is different from 0 

int gcd(const RationalNumber r)
{
	//what if n = 0 and d = some non zero number 
	int gcd;
	if(r.a == 0) 
	gcd = r.b;
	
	for(int i = 1; i <= r.a && i <= r.b; i++)
	{
		if(r.a %i == 0 && r.b % i == 0)
			gcd = i;
	}
	return gcd;
}

void reduce(RationalNumber& r)
{
	int g = gcd(r);
	r.a = r.a / g;
	r.b = r.b / g;
}

string toString(RationalNumber r)
{
	stringstream ss;
	ss << "N = " << r.a << ", " << "D = " << r.b ;
	string s = ss.str();
	return s;
}


int main()
{
  RationalNumber r;
  cout << "Please enter numerator: " ;
  cin >> r.a;

  cout << "Please enter demonenator: ";
  cin >> r.b;

  reduce(r);

  cout << "The rational number in reduced form is " << toString(r) << endl;

  system("Pause");
  return 0;
}




