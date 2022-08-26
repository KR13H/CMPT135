/*10. Consider a StudentRecord struct declared as follows:
struct StudentRecord
{
string name;
float test, midterm, final; //test (20%), midterm (30%) and final (50%)
char letterGrade;
};
Write a program that declares a StudentRecord variable, reads the values for its members (name, test, 
midterm and final) from the user; and then calculates the letter grade. Use this assignment of letter grades 
[0, 50) = F, [50, 60) = D, [60, 75) = C, [75, 90) = B, and [90, 100] = A). Also write a function named 
viewRecord that takes a StudentRecord argument and prints the argument (its name, test, midterm, final 
and letter grade) in a nice format. Finally call the function viewRecord from the main program in order to 
print the student record. */

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

struct StudentRecord
{
string name;
float test, midterm, final; //test (20%), midterm (30%) and final (50%)
char letterGrade;
};

//this function takes in the input from the user for Student Record
void input(StudentRecord& r)
{
	cout << "Please enter your full name: ";
	cin >> r.name;
	cout << "Please enter your marks in Test: ";
	cin >> r.test;
	cout << "Please enter your marks in Midterm: ";
	cin >> r.midterm;
	cout << "Please enter you marks in Final: ";
	cin >> r.final;
}

//this function computes the grade 
char grade(const float test, const float midterm, float final)
{
	//calculating the total
	int total = test*0.2 + midterm*0.3 + final*0.5;
	//assign letter grade
	if(total >= 0 && total < 50)
	{
		return 'F';
	}
	else if(total >= 50 && total < 60)
	{
		return 'D';
	}
	else if(total >= 60 && total < 75)
	{
		return 'C';
	}
	else if(total >= 75 && total < 90)
	{
		return 'B';
	}
	else 
	{
		return 'A';
	}

}

//Printing the final 
void viewRecord(const StudentRecord r)
{
	cout << "The name of the student is " << r.name << endl;
	cout << "Test: " << r.test << endl;
	cout << "Midterm: " << r.midterm << endl;
	cout << "Final: " << r.final << endl;
	cout << "Letter grade: " << r.letterGrade << endl;
}


int main()
{
	StudentRecord* a;
	int size;
	cout << "Please enter the number of students in the class: ";
	cin >> size;
	a = new StudentRecord[size];

	//take in the input and compute the grade
	for(int i = 0; i < size; i++)
	{
		input(a[i]);
		a[i].letterGrade = grade(a[i].test, a[i].midterm, a[i].final);
	}

	//viewing the record
	for(int i = 0; i < size; i++)
	{
		viewRecord(a[i]);
	}

	system("Pause");
	return 0;
}
