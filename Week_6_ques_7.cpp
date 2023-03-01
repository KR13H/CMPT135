//7. Create a text file named ClassList.txt manually using notepad and edit it as follows
//John Walter 20 19 45
//Sara Gill 16 15 35
//Mark Black 23 24 50
//Jess Paul 10 20 25
//Joe Nash 14 18 44
//⁞
//Think of these as students' full names and their assessment marks for exercises, projects and final exam.
//List as many students' details as you wish; it does not matter how many students are listed in the file.
//Write a C++ program that reads this file (ClassList.txt) and creates a new output file named Report.txt with
//the same content together with the letter grades of the students on the same line for each student. For
//the letter grades, use the settings [90, 100] = A, [75, 90) = B, [65, 75) = C, [50, 65) = D and [0, 50) = F.
//This means when our program finishes execution, then the Report.txt file should contain the following
//data:
//John Walter 20 19 45 B
//Sara Gill 16 15 35 C
//Mark Black 23 24 50 A
//Jess Paul 10 20 25 D
//Joe Nash 14 18 44 B
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct ClassList
{
	string fname, lname;
	int test, mid, final;
	char grade;
};

char get_grade(const int& test, const int& mid, const int& final)
{
	int total = test + mid + final;
	if(total >= 90)
		return 'A';
	else if(total >= 75)
		return 'B';
	else if(total >= 65)
		return 'C';
	else if(total >= 50)
		return 'D'; 
	else
		return 'F';
}

int main()
{
	ifstream fin("ClassList.txt");
	ofstream fout("Report.txt");

	if(fin.fail())
	{
		cout << "Opening input file failed" << endl;
		abort();
	}
	else if(fout.fail())
	{
		cout << "Opening output file failed" << endl;
		abort();
	}
	else
	{
		vector <ClassList> c;
		ClassList temp;
		while(fin >> temp.fname >> temp.lname >> temp.test >> temp.mid >> temp.final)
		{
			c.push_back(temp);
		}

		for(int i = 0; i < c.size(); i++)
		{
			c[i].grade = get_grade(c[i].test, c[i].mid, c[i].final);
		}

		//now print it to the report file
		for(int i = 0; i < c.size(); i++)
		{
			fout << c[i].fname << " " << c[i].lname << "\t\t" << c[i].test << "\t" << c[i].mid << "\t" << c[i].final << "\t" << c[i].grade << endl;
		}

		//close the classList and report files
		fin.close();
		fout.close();
	}

	system("Pause");
	return 0;
}
