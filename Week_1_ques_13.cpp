/* 13. Write a function named searchName that takes three arguments: a dynamic array of structs of type 
StudentRecord, its size, and a string argument and returns the first element of the array you find whose 
name matches the string argument. If there is no element whose name matches the string argument, 
please return a StudentRecord value whose name = "Not Found", test = -1, midterm = -1, final = -1, and 
letterGrade = 'N' */

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

//searching the students
StudentRecord searchName(const StudentRecord* r, const int size, string name)
{
	StudentRecord sRecord;
	if
	{
		for(int i = 0; i < size; i++)
	{
		if(r[i].name == name)
		{
			sRecord = r[i];
			return sRecord;
		}

	}
	}
	else
	{
	// If there is no element whose name matches the string argument, 
	//please return a StudentRecord value whose name = "Not Found", test = -1, midterm = -1, final = -1, and 
	//letterGrade = 'N'
		sRecord.name = "Not Found";
	        sRecord.test = -1;
	        sRecord.midterm = -1;
	        sRecord.final = -1;
	        sRecord.letterGrade = 'N';
	        return sRecord;
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

	//asking the user for the name of the student whose record he want to view
	string name;
	cout << "Please enter the name of the student whose record you would like to view: ";
	cin >> name;

	StudentRecord foundRecord = searchName(a, size, name);
	//Printing that student's record
	cout << "The record of " << name << "is given below: " << endl;
	viewRecord(foundRecord);



	system("Pause");
	return 0;
}
