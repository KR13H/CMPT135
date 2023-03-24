#include <iostream>
#include <string>
#include <ctime>

using namespace std;


//searches the array for a given value
template <class T>
int sequentialSerach(const T* A, const int& size, const T& searchValue)
{
	for(int i = 0; i < size; i++)
	{
		if(A[i] == searchValue)
			return i;
	}
	return -1;
}

// returns the maximum value in the array
template <typename T>
T getMaxValue(const T* A, const int& size)
{
	T m = A[0];
	for(int i = 1; i < size; i++)
		if(A[i] > m) m = A[i];
	return m;
}

// returns the sum of the two elements 
template <typename T1, class T2>
T1 sumUp(const T1 x, const T2 y)
{
	T1 result = x + static_cast<T1>(y);
	return result;
}

//ques 2. Write a function template named maximum. The function takes two values of the same type as its 
//arguments and returns the larger of the two arguments (or either value if they are equal).
template <class T>
T maximum(const T& x, const T& y)
{
	if(x == y)
		return x;
	else
	{
		if(x > y) return x;
		else return y;
	}
}

//3. Define a function template named absValue that taken one argument and returns the absolute value of 
//the argument. ???????????????????Give some data types for the argument with which the function can be called. //it can not be pointer , or string  
template <class T>
T absValue(const T& x)
{
	if(x >= 0)
		return x;
	else
		return -x;
}

//5. Define a function template for bubble sort algorithm that can be used to sort an array of elements of any 
//type. Also define two more functions for selection sort and insertion sort algorithms.
template <class T>
void bubbleSort(T* A, const int& size)
{
	for(int i = 0; i < size; i++)
	{

		for(int j = 0; j < size - 1 - i; j++)
		{
			if(A[j] > A[j+1])
			{
				T temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

template <class T>
void selectionSort(T* A, const int& size)
{
	for(int i = 0; i < size; i++)
	{
		int index = i;
		for(int j = i+1; j < size; j++)
		{
			if(A[j] < A[index])
				index = j;
		}
		int temp = A[i];
		A[i] = A[index];
		A[index] = temp;
	}
}

template <class T>
void insertionSort(T* A, const int& size)
{
	for(int i = 1; i < size; i++)
	{
		int temp = A[i];
		int j;
		for(j = i-1; j>= 0; j--)
		{
			if(A[j] > temp)
				A[j+1] = A[j];
			else
				break;
		}
		A[j+1] = temp;
	}
}


//4. Define a function template for binary search algorithm that can be used to search an array of elements of 
//any type.
template <class T>
int binarySearch(T* A, const int size, const T& searchValue)
{
	//sort the array in increasing order using bubble sort
	bubbleSort(A, size);
	// now search using binary search
	int startIndex = 0, lastIndex = size-1;
	while(startIndex <= lastIndex)
	{
		int middleIndex = (startIndex + lastIndex)/2;
		if(A[middleIndex] == searchValue)
			return middleIndex;
		else if(A[middleIndex] > searchValue)
			lastIndex = middleIndex - 1;
		else
			startIndex = middleIndex + 1;
	}
	return -1;

}



//6. Define a function template named isIncreasing that tests if the elements of an array are in increasing 
//order
template <class T>
bool isIncreasing(const T* A, const int& size)
{
	for(int i = 0; i < size -1; i++)
	{
		if(A[i] > A[i+1])
			return false;
	}
	return true;
}
	

//7. Define a function template named countElements that returns how many times a given value is found in 
//a given array. 
template <class T>
int countElements(const T* A, const int& size, const T& sValue)
{
	int count = 0; 
	for(int i = 0; i < size; i++)
	{
		if(A[i] == sValue)
			count++;
	}
	return count;
}

//CountdistinctElemenets in a sorted array 
template <class T>
int countSortedArrayDistinctElements(const T* A, const int&size)
{
	int count  = 1; //The element at index 0 is counted as distinct
	for(int i = 1; i < size; i++)
	{
		if(A[i] != A[i-1]) //Count A[i] as distinct only if it is different from A[i-1]
			count++;
		else
			continue;
	}
	return count;
}

int main()
{
	//Construct several arrays of different data types
	const int size = 10;
	int* A1 = new int[size];
	double* A2 = new double[size];
	string* A3 = new string[size];

	srand(time(0));

	//Populate the arrays
	for(int i = 0; i < size; i++)
	{
		A1[i] = rand() % 21 + 5;
		A2[i] = ((1.0*rand())/RAND_MAX)* 15.0 + 5.0;
		int random = rand()%5;
		A3[i] = (random == 0 ? "Paul" :
				(random == 1 ? "Jannet" :
				(random == 2 ? "Kevin" :
				(random == 3 ? "Sara" : "CMPT"))));
	}

	//Print the arrays
	cout << "Here are the arrays created...." << endl << endl;
	cout << "Array A1 \t Array A2 \t Array A3" << endl;
	cout << "======== \t ======== \t ========" << endl;
	for(int i = 0; i < size; i++)
		cout << A1[i] << "\t\t" << A2[i] << "\t\t" << A3[i] << endl;
	cout << endl;

	//Perform some searches using sequential search algorithm
	int s1 = rand() % 21 + 5;
	double s2 = A2[rand() % size];
	string s3 = "Sara" ;

	int ans1 = sequentialSerach(A1, size, s1);
	int ans2 = sequentialSerach(A2, size, s2);
	int ans3 = sequentialSerach(A3, size, s3);

	//Display search results 
	if(ans1 == -1)
		cout << s1 << " is not found in the array A1" << endl;
	else
		cout << s1 << " is found in the array A1 at index " << ans1 << endl;
	if(ans2 == -1)
		cout << s2 << "is not found in the array A2" << endl;
	else
		cout << s2 << " is found in the array A2 at index " << ans2 << endl;
	if(ans3 == -1)
		cout << s3 << "is not found in the array A3" << endl;
	else
		cout << s3 << " is found in the array A3 at index " << ans3 << endl;


	//Compute the maximum elemets of the array
	int m1 = getMaxValue(A1, size);
	double m2 = getMaxValue(A2, size);
	string m3 = getMaxValue(A3, size);


	cout << "Maximum element of A1 = " << m1 << endl;
	cout << "Maximum element of A2 = " << m2 << endl;
	cout << "Maximum element of A3 = " << m3 << endl;

	int a = 5;
	float b = 2.7;
	cout << "sumUp(" << a << ", " << b << ") = " << sumUp(a,b) << endl;
	cout << "sumUp(" << b << ", " << a << ") =" << sumUp(b,a) << endl;

	int x = rand() % 21 + 5;
	int y = rand() % 21 + 5;
	cout << "The maximum element of the two "<< "x: " << x << ", y: " << y  << " is " << maximum(x,y) << endl;

	cout << "Abs value of -12 is " << absValue(-12) << endl;
	cout << "Abs value of 12.0 is " << absValue(12.0) << endl;
	cout << "Abs value of 0 is " << absValue(0) << endl;


	//Testing the sorting alogrithms 
	bubbleSort(A1,size);
	cout << "Array A1 after sorting " << endl;
	for(int i = 0; i < size; i++)
		cout << A1[i] << endl;

	//Testing the binary search 
	int sValue = 12;
	if(binarySearch(A1,size,sValue) != -1)
		cout << "12 is found in the array at index " << binarySearch(A1,size,sValue) << endl;
	else
		cout << "12 is not found in the array" << endl;

	//checking isincreasing funciton 
	if(isIncreasing(A1,size))
		cout << "The elements in the array A1 are in increasing order. " << endl;
	else
		cout << "The elements in the array A1 are not in increaing order." << endl;

	if(isIncreasing(A2,size))
		cout << "The elements in the array A2 are in increasing order. " << endl;
	else
		cout << "The elements in the array A2 are not in increaing order." << endl;

	cout << "Sorting A3 " << endl;
	bubbleSort(A3, size);


	//checking countSortedArrayDistinctElements 
	cout << "The number of distinct elements in the array A1 are " << countSortedArrayDistinctElements(A1, size) << endl;
	cout << "The number of distinct elements in the array A3 are " << countSortedArrayDistinctElements(A3, size) << endl;


	system("Pause");
	return 0;
}


