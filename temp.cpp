/* 12. Write a function named viewRecord (remember function overloading) that takes three arguments: a 
dynamic array of structs of type StudentRecord, its size, and a character and prints the elements of the 
array whose letter grade matches the character argument. */

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
	cout << "Full name: ";
	cin >> r.name;
	cout << "Marks in Test: ";
	cin >> r.test;
	cout << "Marks in Midterm: ";
	cin >> r.midterm;
	cout << "Marks in Final: ";
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

// prints the elements of the array whose letter grade matches the character argument
void viewRecord(const StudentRecord* r, const int size, const char c)
{
	cout << "Info of students with letter grade " << c << endl;
	for(int i = 0; i < size; i++)
	{
		if(r[i].letterGrade == c)
			viewRecord(r[i]);
	}
}



int main()
{
	StudentRecord* a;
	int size;
	cout << "Please enter the number of students in the class: ";
	cin >> size;
	a = new StudentRecord[size];

	//take in the input and compute the grade
	for(int i = 0, j = 1; i < size ; i++, j++)
	{
		cout << "Record for student " << j << endl;
		input(a[i]);
		a[i].letterGrade = grade(a[i].test, a[i].midterm, a[i].final);
	}

	//viewing the record
	for(int i = 0; i < size; i++)
	{
		viewRecord(a[i]);
	}

	//asking the user which letter grade students they want to find
	char c;
	cout << "Please enter the grade range of which you want to view the students: ";
	cin >> c;
	//printing the students with letter grade c
	viewRecord(a, size, c);


	system("Pause");
	return 0;
}
