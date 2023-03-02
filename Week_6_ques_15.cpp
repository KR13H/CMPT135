//Consider the following program that makes use if, else-if, and else statements. Convert it to an equivalent 
//program that makes use of only switch-case statements but not any if, else-if, else, or ternary (conditional 
//operator) statements.
//int main()
//{
//srand(time(0));
//int x = rand() % 100;
//int y = rand() % 100;
//cout<<"The value of x is "<< x <<" and that of y is "<< y <<endl;
//if (x % 2 == 0 && y % 2 == 0)
//cout<<"Both even."<<endl;
//elseif (x % 2 == 0 && y % 2 != 0)
//cout<<"x is even but y is odd."<<endl;
//elseif (x % 2 != 0 && y % 2 == 0)
//cout<<"x is odd but y is even."<<endl;
//else
//cout<<"Both odd."<<endl;
//system("Pause");
//return 0;
//}

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int x = rand() % 100;
	int y = rand() % 100;
	cout<<"The value of x is "<< x <<" and that of y is "<< y <<endl;
	switch(2*(x % 2 == 0) + (y % 2 == 0))
	{
		case 3:
			cout << "Both x and y are even" << endl;
			break;
		case 2:
			cout << "x is even but y is odd" << endl;
			break;
		case 1:
			cout << "x is odd but y is even" << endl;
			break;
		default:
			cout << "Both odd" << endl;
	}
	system("Pause");
	return 0;
}

