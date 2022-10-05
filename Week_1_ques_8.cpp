/* Consider the struct declaration
struct StringStat
{
string s;
int lower, upper, digit;
};
Our aim is to write a program that creates an array of StringStat of size 5 and reads the string member 
variable of each element of the array from the user input.Then compute the values of the three 
member variables lower, upper and digit for each element of the array by counting how many lower case
characters, how many upper case characters and how many digit characters the string member variable 
contains. Finally print each element of the array and the counts in a nicely formatted output.  */
//We assume the user will input strings made up lower case alphabets, upper case alphabets, and digits only.


#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

struct StringStat
{
	string s;
	int lower, upper, digit;
};
//computing length of the string strlen()

//counting number of lower case in a string
int lower(string s)
{
	int l = s.length(), L(0);
	for(int i = 0; i < l; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			L++;
	}
	return L;
}

//counting upper
int upper(string s)
{
	int l = s.length(), U(0);
	for(int i = 0; i < l; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			U++;
	}
	return U;
}

//counting digits
int digit(string s)
{
	int l = s.length(), D(0);
	for(int i = 0; i < l; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			D++;
	}
	return D;
}

//printing the  StringStat
void printStringStat(StringStat* a)
{
	for(int i = 0; i < 5; i++)
	{
		cout << "For the string " << a[i].s << endl;
		cout << "Number of lower case char " << a[i].lower << endl;
		cout << "Number of upper case char " << a[i].upper << endl;
		cout << "Number of digits " << a[i].digit << endl;
	}
	return;
}



int main()
{
	StringStat a[5];

	//reading input for string for arr[0]
	for(int i = 0; i < 5; i++)
	{
		cout << "Please enter a string for arr[" << i << "]: ";
		cin >> a[i].s;
	}

	//counting
	for(int i = 0; i < 5; i++)
	{
		a[i].lower = lower(a[i].s);
		a[i].upper = upper(a[i].s);
		a[i].digit = digit(a[i].s);
	}
	
	printStringStat(a);

	system("Pause");
	return 0;
}


	
