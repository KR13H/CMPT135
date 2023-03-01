//12.Write a C++ program that does the following:
//a. Create an output file stream and connect it to a file "RandomFloats.txt"
//b. Generates a random integer n in the range [900, 1000]
//c. Print in the file n random floats in the range [0.0, 100.0) on to the file and close the output stream
//d. Create an input stream and connect it to your file "RandomFloats.txt"
//e. Read all the n floats in the file into an array and close the input file stream
//f. Sort your array with a bubble or selection or insertion sort algorithm
//g. Create an output stream and connect it to a file "SortedRandomFloats.txt"
//h. Write the sorted array of floats into the output file stream and close the output file stream
//i. Check your file " SortedRandomFloats.txt" in Notepad to see indeed it is sorted.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void bubbleSort(vector<double>& v)
{
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v.size()-1-i; j++)
		{
			if(v[j] > v[j+1])
			{
				double temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
}


int main()
{
	vector<double> v;
	//a.
	ofstream fout("RandomFloats.txt");
	if(fout.fail())
	{
		cout << "Output file not found" << endl;
		abort();
	}
	else
	{
		//b.
		int n = rand() % 101 + 900;
		//c.
		for(int i = 0; i < n; i++)
			fout << (1.0*rand()/RAND_MAX)*100 << endl;
		fout.close();
	}
	//d. 
	ifstream fin("RandomFloats.txt");
	if(fin.fail())
	{
		cout << "Input file not found" << endl;
		abort();
	}
	else
	{
		//e.
		double temp;
		while(fin >> temp)
		{
			v.push_back(temp);
		}
		fin.close();
	}

	//f.
	bubbleSort(v);

	//g.
	ofstream ffout("SortedRandomFloats.txt");
	if(ffout.fail())
	{
		cout << "Output file not found" << endl;
		abort();
	}
	else
	{
		//h.
		for(int i = 0; i < v.size(); i++)
		{
			ffout << v[i] << endl;
		}
		ffout.close();
	}

	system("Pause");
	return 0;
}



