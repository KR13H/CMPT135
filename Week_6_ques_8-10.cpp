//8. Do Question #7 above again but this time making sure to read from an input text file named ClassList.txt
//and write the output to the same file ClassList.txt. In other words your program is required to read from a
//file and write on to the same file. Assume that there are exactly five students listed in the input file.
//HINT:- Use C++ struct or C++ class to store the students' information in an organized form.
//9. Do Question #8 above again but this time assume we do not know how many students are stored in the
//input file.
//HINT:- Use C++ struct or C++ class to store the students' information in an organized form.
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
	//open the ClassList.txt for reading
	fstream fin("ClassList.txt");
	vector<ClassList> v;
	if(fin.fail())
	{
		cout << "Input file not found" << endl;
		abort();
	}
	else
	{
		ClassList temp;
		while(fin >> temp.fname >> temp.lname >> temp.test >> temp.mid >> temp.final)
		{
			v.push_back(temp);
		}
		for(int i = 0; i < v.size(); i++)
		{
			v[i].grade = get_grade(v[i].test, v[i].mid, v[i].final);
		}
		fin.close();
	}

	//open the same file for writing 
	ofstream fout("ClassList.txt");
	if(fout.fail())
	{
		cout << "Output file not found " << endl;
		abort();
	}
	else
	{
		for(int i = 0; i < v.size(); i++)
		{
			fout << v[i].fname << " " << v[i].lname << "\t\t" << v[i].test << "\t" << v[i].mid << "\t" << v[i].final << "\t" << v[i].grade << endl;
		}

		fout.close();
	}

	cout << "ClassList file sucessfully modified" << endl;

	

	//10. Consider the ClassList.txt file you manually created in Q7 above. Write a C++ program that reads the file
	//and prints the top student (i.e. maximum total marks). Your program must print the full name, the marks,
	//and the letter grade of the top student only. You are not allowed to use any array to answer this question.
	//HINT:- Use C++ struct or C++ class to store the students' information in an organized form.

	int max = v[0].test + v[0].mid + v[0].final;
	int index = 0;
	for(int i = 1; i < v.size(); i++)
	{
		int m = v[i].test + v[i].mid + v[i].final;
		if(m > max)
		{
			max = m;
			index = i;
		}
	}

	cout << "The top student is " << v[index].fname << " " << v[index].lname << "\t\t " << v[index].test << "\t" << v[index].test << "\t" << v[index].mid << "\t" << v[index].final << "\t" << v[index].grade << endl;


	system("Pause");
	return 0;
}

