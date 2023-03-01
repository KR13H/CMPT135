//11.Write a C++ program that reads a positive integer n from the keyboard and then creates a new file named
//multiplicationTable.txt that contains the following information
//1 2 3 .... n
//2 4 6 .... 2n
//3 6 9 .... 3n
//.
//.
//.
//n 2n 3n ... n
//2
//Note that you are not allowed to declare any array here
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int n;
	cout << "Please enter a number: ";
	cin >> n;

	ofstream fout("multiplicationTable.txt");
	if(fout.fail())
	{
		cout << "Output file not found" << endl;
		abort();
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				fout << j*(i+1) << "\t";
			}
			fout << endl;
		}
		fout.close();
	}


	system("Pause");
	return 0;
}
