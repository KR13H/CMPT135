#include <iostream>
#include <fstream>

using namespace std;

//1. Write a C++ program that generates a random integer n in the range [50, 100] and that writes n random
//integers in the range [0, 999] to an output text file named RandomNumbers.txt.

int random_num_generator(const int& a, const int& b)
{
	int r = rand() % (b-a+1) + a;
	return r;
}

//2. Write a C++ program that reads the file RandomNumbers.txt you created in Q1 above and prints the
//minimum and maximum integers in the file. Your output should be printed to the console output screen.
//Remark: You are not allowed to declare any array. Moreover remember that you don't know how many
//numbers are on the input file which means you must read until the end of file is reached.
int max(const string& s)
{
	ifstream fin(s);
	int max;
	fin >> max;
	int m;
	while(fin >> m)
	{
		if(m > max)
			max = m;
	}
	fin.close();
	return max;
}
int min(const string& s)
{
	ifstream fin(s);
	int min;
	fin >> min;
	int m;
	while(fin >> m)
	{
		if(m < min)
			min = m;
	}
	fin.close();
	return min;
}
int size(const string& s)
{
	ifstream fin(s);
	int size = 0;
	int x;
	while(fin >> x)
	{
		size++;
	}
	fin.close();
	return size;
}
//3. Write a C++ program that reads the RandomNumbers.txt file you created in Q1 above and that prints the
//data in the file to the console output screen in reverse order; that is the first integer read will be printed
//last and the last integer read will be printed first. Remark: You may use an array (or better a SmartArray
//object) when you answer this question. Moreover remember that you don't know how many numbers are
//on the input file which means you must read until the end of file is reached.
void print_reverse(const string& s)
{
	int size_s = size(s);
	int* A = new int[size_s];
	fstream fin(s);
	if(fin.fail())
	{
		cout << "Input file opening failed" << endl;
		abort();
	}
	else
	{
		//read the elements in the dynamic array
		for(int i = 0; i < size_s; i++)
		{
			int read;
			fin >> read;
			A[i] = read;
		}
	}
	//now print in reverse to the console screen
	for(int i = size_s - 1; i >= 0; i--)
		cout << A[i] << endl;
	return;
}

//4. [Optional Interesting Question] Write a C++ program that reads the RandomNumbers.txt file you created
//in Q1 above and that prints the data in the file to the console output screen in reverse order; that is the
//first integer read will be printed last and the last integer read will be printed first. Remark: You are NOT
//allowed to use any array or SmartArray when you answer this question. Moreover remember that you
//don't know how many numbers are on the input file which means you must read until the end of file is
//reached.
//Hint:- You must write a recursive function that takes an input file streaming object argument and that
//prints the data read by the input streaming object in reverse order.
void printReverse(ifstream& fin)
{
	int x;
	if(fin>>x)
	{
		printReverse(fin);
		cout << x << endl;
	}
}
int main()
{
	int n =  rand()%1000;
	cout << "Printing " << n << " random number in the output file named RandomNumbers.txt." << endl;

	//open the file for printing 
	ofstream fout("RandomNumbers.txt");
	//check if it is opened correctly 
	if(fout.fail())
	{
		cout << "Output file opening failed" <<endl;
		abort();
	}
	else
	{
		for(int i = 0; i < n ; i++)
		{
			fout << random_num_generator(50, 100) << endl;
		}
	}
	fout.close();

	cout << "The max int in the file is " << max("RandomNumbers.txt") << endl;
	cout << "The min int in the file is " << min("RandomNumbers.txt") << endl;
	cout << "The size of the file is " << size("RandomNumbers.txt") << endl;

	cout <<"Printing the elements of the array in reverse order" << endl;
	print_reverse("RandomNumbers.txt");
	cout << endl;

	cout << "Print reverse using recursive" << endl;
	ifstream fin("RandomNumbers.txt");
	if(fin.fail())
	{
		cout << "Input file opening failed" << endl;
		abort();
	}
	printReverse(fin);
	fin.close();


	system("Pause");
	return 0;
}

