#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//non-member function(it computes the grade)
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

class Course
{
private:
	string name;
	float test, midterm, final;
	char letterGrade;
public:
	Course();
	Course(string n);
	Course(string n, float t, float m, float f);
	//getters
	string getName();
	float getTest();
	float getMidterm();
	float getFinal();
	char getLetterGrade();
	//setters
	void setName(string NewName);
	void setTest(float NewTest);
	void setMidterm(float Newmidterm);
	void setFinal(float NewFinal);
	//other member functions
	void print();
};

Course::Course()
{
	name = "";
	test = 0;
	midterm = 0;
	final = 0;
	letterGrade = 'F';
}
Course::Course(string n)
{
	n = name;
}
Course::Course(string n, float t, float m, float f)
{
	n = name;
	t = test;
	m = midterm;
	f = final;
	letterGrade = grade(t,m,f);
}
//getters
string Course::getName()
{
	return name;
}
float Course::getTest()
{
	return test;
}
float Course::getMidterm()
{
	return midterm;
}
float Course::getFinal()
{
	return final;
}
char Course::getLetterGrade()
{
	return letterGrade;
}
//setters
void Course::setName(string NewName)
{
	name = NewName;
	letterGrade = grade(test,midterm,final);
}
void Course::setTest(float NewTest)
{
	test = NewTest;
	letterGrade = grade(test,midterm,final);
}
void Course::setMidterm(float NewMidterm)
{
	midterm = NewMidterm;
	letterGrade = grade(test,midterm,final);
}
void Course::setFinal(float NewFinal)
{
	final = NewFinal;
	letterGrade = grade(test,midterm,final);
}
//other member functions
void Course::print()
{
	cout << "Name: " << name << endl;
	cout << "Test: " << test << endl;
	cout << "Midterm: " << midterm << endl;
	cout << "Final: " << final << endl;
	cout << "Letter Grade: " << letterGrade << endl;
}

int main()
{
	Course first1;
	string name1;
	cout << "Please enter the name of the student: ";
	cin >> name1;
	first1.setName(name1);
	float test, midterm, final;
	cout << "Please enter the marks in the test: ";
	cin >> test;
	first1.setTest(test);
	cout << "Please enter the marks in the midterm: ";
	cin >> midterm;
	first1.setMidterm(midterm);
	cout << "Please enter the marks in the final: ";
	cin >> final;
	first1.setFinal(final);

	first1.print();
	system("Pause");
	return 0;
}











