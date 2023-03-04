//12. Write a function named insertIncreasing that takes a vector of integers whose elements are sorted
//in increasing order and an integer value as arguments and inserts the integer argument in the vector such
//that after the insertion operation, the elements of the modified vector are also in increasing order. Here is
//a very simple test code for you. Insert as many integers as possible for rigorous test.

#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &x)
{
	for (int i = 0; i < x.size(); i++)
		cout << x[i] << " ";
	cout << endl;
}

//12. Write a function named insertIncreasing that takes a vector of integers whose elements are sorted
//in increasing order and an integer value as arguments and inserts the integer argument in the vector such
//that after the insertion operation, the elements of the modified vector are also in increasing order. Here is
//a very simple test code for you. Insert as many integers as possible for rigorous test.
void insertIncreasing(vector<int>& v, const int& x)
{
	int i = 0;
	for(; i < v.size(); i++)
	{
		if(v[i] >= x)
			break;
	}
	v.insert(v.begin()+i,x);
}

int main()
{
	vector<int> a;
	for (int i = 0; i < 5; i++)
	{
		int num = rand() % 11 -5;
		cout << "Inserting " << num << endl;
		insertIncreasing(a, num);
		printVector(a);
	}
	system("Pause");
	return 0;
}
