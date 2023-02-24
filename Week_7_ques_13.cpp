//13. Write a function named insertGrouped that takes a vector of integers whose elements are grouped (i.e.
//its even integer elements are grouped together and its odd integer elements are also grouped together)
//and an integer value as arguments and inserts the integer argument in the vector such that after the
//insertion operation, the elements of the modified vector are also grouped. Use a similar test code as Q12
//above.

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void insertGrouped(vector<int>& v, const int x)
{
	//if the vector if empty then just push_back
	if(v.size() == 0)
	{
		v.push_back(x);
		return;
	}
	//check x is even
	if(x % 2 == 0)
	{
		if(v.back() % 2 == 0)
			v.push_back(x);
		else
		{
			//find the first odd number;
			int i = 0;
			for(; i < v.size(); i++)
			{
				if(v[i] % 2 != 0)
					break;
			}
			//insert in there 
			v.insert(v.begin() + i, x);
		}
	}
	else
	{
		if(v.back() % 2 != 0)
			v.push_back(x);
		else
		{
			//find first even number
			int i = 0; 
			for(; i < v.size(); i++)
			{
				if(v[i] % 2 == 0)
					break;
			}
			//insert in there
			v.insert(v.begin() + i, x);
		}
	}
}

void printVector(const vector<int> &x)
{
	for (int i = 0; i < x.size(); i++)
		cout << x[i] << " ";
	cout << endl;
}


int main()
{
	vector<int> a;
	for (int i = 0; i < 5; i++)
	{
		int num = rand() % 11 -5;
		cout << "Inserting " << num << endl;
		insertGrouped(a, num);
		printVector(a);
	}
	system("Pause");
	return 0;
}
