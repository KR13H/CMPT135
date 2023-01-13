#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Date
{
	int day; int month; int year;
};

int getDays(const Date d1, const Date d2)
{
	int diff1;
	diff1 = (d2.year - d1.year)*360 + (d2.month - d1.month)*30 + (d2.day - d1.day);
	return diff1;
}

int getDaysBetween(const Date d1, const Date d2)
{
	return abs(getDays(d1,d2));
}

Date getDateBetween(const Date d1, const Date d2)
{
	int x;
	date d;
	d.year = x/ 360;
	x = x % 360;
	return d;
}


int main()
{

	//Create two Date objects
	Date d1, d2;
	//Read input values for d1 and d2. Assume user inputs are valid inputs
	cout << "Please enter the day, month and year of the first Date ";
	cin >> d1.day >> d1.month >> d1.year;

	cout << "Please enter the day, month and year of the second Date ";
	cin >> d2.day >> d2.month >> d2.year;

	//Compute the number of days from d1 to d2. The result can be negative, positive or zero
	int diff1 = getDays(d1, d2);
	cout << "There are " << diff1 << " days from d1 to d2." << endl;
	//Compute the number of days between the two Dates. The result must be non-negative integer
	int diff2 = getDaysBetween(d1, d2);
	cout << "There are " << diff2 << " days between the two dates." << endl;

	//Compute the number of days, month and years between the two Dates. 
	//The result must contain a day in the range [0, 29], month in the range [0, 11] and 
	//any non negative integer for the year
	Date diff3 = getDateBetween(d1, d2);
	cout << "There are " << diff3.day << " days, " << diff3.month << " months, and " << diff3.year << " years between the two dates" << endl;

system("Pause");
return 0;
}
