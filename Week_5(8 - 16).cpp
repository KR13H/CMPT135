#include <iostream>
using namespace std;

class SmartArray
{
private:
	int *A;
	int size;
public:
	//Constructors
	SmartArray();
	SmartArray(const int* A, const int& size);
	SmartArray(const SmartArray &L); //Copy constructor
	//Destructor
	~SmartArray();
	//getters
	int getSize() const;
	int& operator[](const int& index) const;
	void append(const int& e);
	SmartArray& operator = (const SmartArray& L);
	friend ostream& operator<<(ostream& out, const SmartArray& L);
	int findElement(const int& integer) const;
	void remove(const int& r);
	void removeAll(const int& r);
	SmartArray operator+(const SmartArray& s) const;
	bool operator==(const SmartArray& s) const;
	bool operator!=(const SmartArray& s) const;
	SmartArray& operator++(); //preincrement same as i++
	SmartArray operator++(int DUMMY); //postincrement same as ++i
	SmartArray& operator--(); //predecrement same as i--
	SmartArray operator--(int DUMMY); //postdecrement same as --i
	SmartArray operator-() const; //returns all the elements in the smart array by multipliying them by -1
	SmartArray operator-(const SmartArray& s) const; //same as A - B
};
SmartArray::SmartArray()
{
	this->size = 0;
}
SmartArray::SmartArray(const int* A, const int& size)
{
	this->size = size;
	if(this->size > 0)
	{
		this->A = new int[this->size];
		for(int i = 0; i < this->size; i++)
			this->A[i] = A[i];
	}
}
SmartArray::SmartArray(const SmartArray &L) //Copy constructor
{
	this->size = L.getSize();
	if(this->getSize() > 0)
	{
		this->A = new int[this->getSize()];
		for(int i = 0; i < this->getSize(); i++)
			this->A[i] = L[i];
	}
}
SmartArray::~SmartArray()
{
	if(this->getSize() > 0)
	{
		delete[] this->A;
		this->size = 0;
	}
}
SmartArray& SmartArray::operator = (const SmartArray& L)
{
	//Checck for self assignment. If so, do nothing.
	if(this == &L)
		return *this;
	//Delete the left hand side object's memory 
	this->~SmartArray();
	//Now copy the right hand side to the left
	this->size = L.getSize();
	if(this->size > 0)
	{
		this->A = new int[this->size];
		for(int i = 0; i < size; i++)
			this->A[i] = L[i];
	}
	return *this;
}

//getters
int SmartArray::getSize() const
{
	return size;
}
int& SmartArray::operator[](const int& index) const
{
	if(index < 0 || index >= this->size)
	{
		cout << "ERROR! Index out of bounds. Exiting Program...." << endl;
		abort();
	}
	return this->A[index];
}
void SmartArray::append(const int& e)
{
	//Create a temp Array whose size is this->size + 1
	int* temp = new int[this->size + 1];

	//Copy the elements of this->A to temp
	for(int i = 0; i < size; i++)
	{
		temp[i] = A[i];
	}
	//Copy the element to be appended to temp
	temp[size] = e;

	//Delete the existing array this-> A
	if(this->size > 0)
		delete[] this->A;
	//Make the array point to temp and increment the size by 1
	this->A = temp;
	this->size += 1;
}
//8. Consider the SmartArray class we implemented during the lecture. Add a member function named 
//findElement that takes an integer argument and returns the index of the first element of the calling object 
//that is equal to the argument if the integer argument is found in the calling object and returns -1
//otherwise.
int SmartArray::findElement(const int& integer) const
{
	for(int i = 0; i < size; i++)
	{
		if(A[i] == integer)
			return i;
	}
	return -1;
}

//9. Consider the SmartArray class we implemented during the lecture. Add a member function named 
//remove that takes an integer argument and removes the first element of the calling object that is equal to 
//the integer argument; if such an element is found in the calling object. Design this function to return true if 
//an element is removed from the calling object and return false otherwise.
//For example if the calling object is L = [1, 2, 3, 2, 5] then
//L.remove(2) must modify L to L = [1, 3, 2, 5] and return true, and
//L.remove(4) must not modify L and return false
void SmartArray::remove(const int& r)
{
	if(findElement(r) == -1)
		return;
	else
	{
		if(size > 1)
		{
			int* temp = new int[size - 1];
			//copy till 1-index
			for(int i = 0; i < findElement(r); i++)
			{
				temp[i] = A[i];
			}
			//Copy the remaining stuff now
			for(int i = findElement(r); i < size -1; i++)
			{
				temp[i] = A[i+1];
			}
			this->A = temp;
			this->size = size - 1;
		}
		else
		{
			int* temp = nullptr;
			this->size = 0;
		}
	}
}

//10. Consider the SmartArray class we implemented during the lecture. Add a member function named 
//removeAll that takes an integer argument and removes all the occurrences of the argument in the calling 
//object. Hint:- Use your remove function.
void SmartArray::removeAll(const int& r)
{
	for(int i = 0; i < size; i++)
	{
		//check if A[i] == r
		//if yes then remove
		if(this->findElement(r) != -1) this->remove(r);
	}
}

//11. Consider the SmartArray class we implemented during the lecture. Add a binary operator +member 
//function that has a SmartArray operand on the left hand side and a SmartArray operand on the right hand 
//side; and that returns a SmartArray made up of the concatenation of the SmartArrays.
//Example L1 = [1, 2, 3] and L2=[2, 5]. Then L3 = L1 + L2; should result to L3 = [1, 2, 3, 2, 5]
SmartArray SmartArray::operator+(const SmartArray& s) const
{
	if(this->size + s.getSize() > 0)
	{
		SmartArray sum;
		sum.A = new int[this->size + s.getSize()];
		sum.size = this->size + s.getSize();
		//cout << "*******" << sum.size << endl;
		//Copy L1 in sum
		for(int i = 0; i < this->size; i++)
		{
			sum.A[i] = this->A[i];
		}
		//Copy L2 in sum
		for(int i = this->size, j = 0; i < sum.size; i++,j++)
		{
			sum.A[i] = s.A[j];
		}
		return sum;
	}
	else
	{
		SmartArray sum;
		return sum;
	}
}
//12. Consider the SmartArray class we implemented during the lecture. Add a binary operator ==member 
//function that has a SmartArray operand on the left hand side and a SmartArray operand on the right hand 
//side; and that returns true if both the operands have the same size and identical corresponding elements 
//and returns false otherwise.
//Example L1 = [1,2,3] and L2=[1,2,3]. Then L1 == L2; should return true
//Example L1 = [1,2,3] and L2=[1,4,3]. Then L1 == L2; should return false
bool SmartArray::operator==(const SmartArray& s) const
{
	if(this->size != s.getSize())
		return false;
	else
	{
		for(int i = 0; i < this->size; i++)
		{
			if(this->A[i] != s.A[i])
				return false;
		}
		return true;
	}
}

//13. Consider the SmartArray class we implemented during the lecture. Add a binaryoperator != member 
//function that has a SmartArray operand on the left hand side and a SmartArray operand on the right 
//hand side; and that returns the negation of the == operator described above.
//Example L1 = [1,2,3] and L2=[1,2,3]. Then L1 != L2; should return false
//Example L1 = [1,2, 3] and L2=[1, 3]. Then L1 != L2; should return true
bool SmartArray::operator!=(const SmartArray& s) const
{
	if(*this == s)
		return false;
	else
		return true;
}

//14. Add the unary operators ++ and -- to the SmartArray class that will have the following functionalities:
// Pre-increment operator that increments all the elements in the dynamic array by 1
// Pre-decrement operator that decrements all the elements in the dynamic array by 1
// Post-increment operator that increments all the elements in the dynamic array by 1
// Post-decrement operator that decrements all the elements in the dynamic array by 1
SmartArray& SmartArray::operator++() //preincrement same as i++
{
	for(int i = 0; i < this->size; i++)
	{
		this->A[i] += 1;
	}
	return *this;
}

SmartArray SmartArray::operator++(int DUMMY) //postincrement same as ++i
{
	SmartArray temp = *this;
	for(int i = 0; i < this->size; i++)
	{
		this->A[i] += 1;
	}
	return temp;
}
SmartArray& SmartArray::operator--() //predecrement same as i--
{
	for(int i = 0; i < this->size; i++)
	{
		this->A[i] -= 1;
	}
	return *this;
}
SmartArray SmartArray::operator--(int DUMMY) //postdecrement same as --i
{
	SmartArray temp = *this;
	for(int i = 0; i < this->size; i++)
	{
		this->A[i] -= 1;
	}
	return temp;
}

//15. Add the unary operator – to the SmartArray class. This operator must not modify the calling object; 
//instead it returns a new SmartArray object whose elements are the elements of the calling object 
//multiplied by -1.
SmartArray SmartArray::operator-() const
{	
	SmartArray negative = *this;
	for(int i = 0; i < this->size;i++)
	{
		negative[i] *= -1;
	}
	return negative;
}

//16. Add a binary operator–member function to the SmartArray class. This operator has SmartArray object as 
//its left hand side operand and a SmartArray object as its right hand side operand (for example A – B) and it 
//must returna SmartArray object containing the distinctelements that are in A but not in Btogether with 
//those in B but not in A. For example if A = [5,1, 3, 2, 1, 4, 2] and B = [3, 9, 5, 8, 9] then A – B must return [1, 
//2, 4, 9, 8].
SmartArray SmartArray::operator-(const SmartArray& s) const
{
	SmartArray ans;
	for(int i = 0; i < this->size; i++)
	{
		if(s.findElement(A[i]) == -1)
			ans.append(A[i]);
	}
	return ans;
}

ostream& operator<<(ostream& out, const SmartArray& L)
{
	out << "[";
	for(int i = 0; i < L.getSize()- 1; i++)
		out << L[i] << ", ";
	if(L.getSize() > 0)
		out << L[L.getSize() - 1];
	out << "]";
	return out;
}


int main()
{
	//Test default constructors
	SmartArray L1;
	cout << "Default SmartArray: " << L1 << endl;

	//Test Non-Default constructors
	int x[] = {7, 2, 5, 5};
	SmartArray L2(x,4);
	cout << "Non-Default SmartArray: " << L2 << endl;

	//test getSize and operator[]
	cout << "Printing the SmartArray L2 elements: ";
	for(int i = 0; i < L2.getSize(); i++)
		cout << L2[i] << " ";
	cout << endl;

	//Test index out of bound case
	//cout << "The element of L1 at index 0 is " << L1[0] << endl;

	//Test append memeber function
	L1.append(54);
	cout << "After appending one element to it, L1 is now" << L1 << endl;

	//Make a default copy of one SmartArray object to another
	SmartArray L3 = L2;
	cout << "L3 which is a copy of L2 is " << L3 << endl;

	//Modify an element of L3
	L3[1] = 33;
	cout << "After modifying an element of L3, now L3 is " << L3 << endl;
	cout << "Interestingly L2 is also modified and is " << L2 << endl;

	//Testing findElement function
	int integer;
	cout << "Please enter an element which you want to find in L1: ";
	cin >> integer;
	if(L1.findElement(integer) != -1)
		cout << "The element you entered is found at index " << L1.findElement(integer) << endl;
	else
		cout << "The element you entered is not found in the array L1 " << endl;
	
	//Testing the remove function on L1
	cout << "//Testing the remove function on L1" << endl;
	int re;
	cout << "Please the integer to be removed from the array: ";
	cin >> re;
	L1.remove(re);
	cout << "The array after removing the integer: " << endl;
	cout << L1 << endl;

	//Testing the remove function on L2
	cout << "//Testing the remove function on L2 " << endl;
	cout << "Please enter the integer to be removed: ";
	cin >> re;
	L2.remove(re);
	cout << "The array after removing the integer: " << endl;
	cout << L2 << endl;

	//Testing the remove all func in L2
	cout << "Testing the remove all func in L2" << endl;
	cout << "Please enter the integer to be removed: ";
	cin >> re;
	L2.removeAll(re);
	cout << "The array after remvoing all the integers: " << endl;
	cout << L2 << endl;

	//Testing operator+ on L1 and L2
	cout << "After adding L2 and L1 we get: " << endl;
	cout << L1 + L2 << endl;

	// Testing operator+ on two empty arrays
	cout << "Testing operator+ on two empty arrays" << endl;
	SmartArray t1, t2;
	cout << t1 + t2 << endl;

	//Testing operator== on L1 and L2
	cout << "Testing operator== on L1 and L2" << endl;
	if(L1 == L2)
		cout << "L1 is equal to L2" << endl;
	else
		cout << "L1 is not equal to L2" << endl;

	//Testing operator== on t1 and L2
	t1 = L2;
	if(t1 == L2)
		cout << "t1 is equal to L2" << endl;
	else
		cout << "t1 is not equal to L2" << endl;
		t1 = t2;

	//Testing ++L2 
	cout << "//Testing ++L2" << endl;
	++L2;
	cout << "After ++L2 value of L2 is " << endl;
	cout << L2 << endl;

	//Testing  t1 and ++L2
	cout << "//Testing  t1 and L2++" << endl;
	t1 = L2++;
	cout << "After L2++ the values of t1 and L2 are " << endl;
	cout << "t1 = " << t1 << endl;
	cout << "L2 = " << L2 << endl;

	//Testing --L2
	cout << "//Testing --L2" << endl;
	--L2;
	cout << "After --L2 the value of L2 is " << endl;
	cout << L2 << endl;

	//Testing  t1 and L2--
	cout << "//Testing  t1 and L2--" << endl;
	t1 = L2--;
	cout << "After L2-- the values of t1 and L2 are " << endl;
	cout << "t1 = " << t1 << endl;
	cout << "L2 = " << L2 << endl;

	//Testing  the operator - on t1 and L2
	cout << "//Testing  the operator -" << endl;
	t1 = -L2;
	cout << "After t1 = -L2 it's value is " << endl;
	cout << "t1 = " << t1 << endl;
	cout << "L2 = " << L2 << endl;

	//Testing the operator - (A-B) on (L2 - L1)
	cout << "//Testing the operator - (A-B)" << endl;
	t2 = L2;
	t1 = L2 - t2;
	cout << " (L2 - L1) " << t1 << endl;

	system("Pause");
	return 0;
}

