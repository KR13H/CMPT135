//5. Given a text file named Numbers.txt saved on the desktop and that contains 15 integers with each number
//on its own line, write a C++ program that will modify the file so that the numbers in the file are reversed.
//For example, if the file originally contains the numbers 1, 2, 3 ,…, 15 in that order; then after executing
//your program the file must be modified so that it contains the numbers 15, 14, 13, …., 1 in that order.

//6. Repeat Question #5 above but this time assume we don't know how many numbers are stored in the file.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int size(const string& s)
{
	ifstream fin(s);
	int read;
	int count = 0;
	while(fin >> read)
	{
		count++;
	}
	fin.close();
	return count;
}


void reverse_num_in_file(const string& s)
{
	//find the size of the doc
	int si = size(s);
	//declare a dynamic array
	int* A = new int[si];
	//open the file for reading the inputs into an array
	ifstream fin(s);
	if(fin.fail())
	{
		cout << "ERROR....." << endl;
		abort();
	}
	else
	{
		for(int i = 0; i < si; i++)
		{
			int read;
			fin >> read;
			A[i] = read;
		}
		fin.close();
	}
	
	//now open the same file for printing 
	ofstream fout(s);
	if(fout.fail())
	{
		cout << "ERROR....." << endl;
		abort();
	}
	else
	{
		for(int i = si-1; i >= 0; i--)
		{ 
			fout << A[i] << endl;
		}
		fout.close();
	}
	return;
}

int main()
{
	cout <<"Reversing numbers in file" << endl;
	reverse_num_in_file("Numbers.txt");

	system("Pause");
	return 0;
}
