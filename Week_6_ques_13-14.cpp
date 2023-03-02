//13.Discuss the pre and post conditions for the following functions
// A function that takes an integer argument n and returns the sum 1+2+3+...+n
// A function that takes an integer argument n and returns true if n is a composite number.
// A function that takes an array of float data type and its size as arguments and returns the sum of
//the elements of the array.
// A function that takes an array of double data types and its size as arguments and returns the
//minimum element of the array.
// A function that takes two arrays of string data type and their sizes as arguments and returns true if
//all the elements of the first array are found in the second array.
/*//1.A function that takes an integer argument n and returns the sum 1+2+3+...+n
Precondition: The input n must be a positive integer.
Postcondition: The function returns the sum of integers from 1 to n.
//2.A function that takes an integer argument n and returns true if n is a composite number.
Precondition: The input n must be a positive integer greater than 1.
Postcondition: The function returns true if n is a composite number; otherwise, it returns false.
//3.A function that takes an array of float data type and its size as arguments and returns the sum of the elements of the array.
Precondition: The input array must be a valid array of float data type, and the size argument must be a positive integer indicating the size of the array.
Postcondition: The function returns the sum of all the elements of the input array.
//4.A function that takes an array of double data types and its size as arguments and returns the minimum element of the array.
Precondition: The input array must be a valid array of double data type, and the size argument must be a positive integer indicating the size of the array.
Postcondition: The function returns the minimum element of the input array.
//5.A function that takes two arrays of string data type and their sizes as arguments and returns true if all the elements of the first array are found in the second array.
Precondition: The input arrays must be valid arrays of string data type, and their sizes must be positive integers indicating the sizes of the arrays.
Postcondition: The function returns true if all the elements of the first array are found in the second array; otherwise, it returns false. */

//
//14. Implement the functions described in Question #13 above with appropriate exception handling 
//techniques. You may use abort or assert functions or try-catch blocks as you see fit. If you think there is no 
//a runtime error that you can handle with exception handling then you may write your functions without 
//any exception handling techniques.

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

//1.A function that takes an integer argument n and returns the sum 1+2+3+...+n
//Precondition: The input n must be a positive integer.
//Postcondition: The function returns the sum of integers from 1 to n.
int sum_of_int(const int& n)
{
	if(n < 0)
	{
		throw(n);
	}
	if(n==0)
		return 0;
	int sum = 0;
	for(int i = 1; i < n+1; i++)
	{
		sum = sum + i;
	}
	return sum;
}

//2.A function that takes an integer argument n and returns true if n is a composite number.
//Precondition: The input n must be a positive integer greater than 1.
//Postcondition: The function returns true if n is a composite number; otherwise, it returns false.
bool isComposite(const int& x)
{
	if(x < 2)
	{
		throw(2);
	}
	for(int i = 2; i < x; i++)
	{
		if(x % i == 0)
			return true;
	}
	return false;
}

//3.A function that takes an array of float data type and its size as arguments and returns the sum of the elements of the array.
//Precondition: The input array must be a valid array of float data type, and the size argument must be a positive integer indicating the size of the array.
//Postcondition: The function returns the sum of all the elements of the input array.
int sum_array(int* A, const int& size)
{
	assert(size >= 0);
	int sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum =  sum + A[i];
	}
	return sum;
}





int main()
{
	cout << "checking 1st "<< endl;
	int n; cout << "Please enter an int: "; cin >> n;
	try
	{
		cout << "the sum of n integers is " << sum_of_int(n) << endl;
	}
	catch(...)
	{
		cout << "The input n must be a positive integer." << endl;
	}
	try
	{
		cout << "checking whether or not n is a composite number " << isComposite(n) << endl;
	}
	catch(int n)
	{
		cout << "The input n must be a positive integer greater than 1." << endl;
	}

	int A[] = {2,3,4};
	cout << "The sum of the numbers in the array is " << sum_array(A, 3) << endl;

	system("Pause");
	return 0;
}


