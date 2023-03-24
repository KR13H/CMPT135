#include <iostream>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

template <class T>
class SmarterArray
{
private:
	T* A;
	int size;
public:
	//Constructors
	SmarterArray();
	SmarterArray(const T* A, const int& size);
	SmarterArray(const SmarterArray<T> &L); //Copy constructor
	//Assignment operator
	SmarterArray<T>& operator = (const SmarterArray<T> &L);
	//Destructor
	~SmarterArray();
	//Getters, Setters, operators and other functions
	int getSize() const;
	T& operator[](const int& index) const;
	int find(const T& e) const;
	void append(const T& e);
	bool remove(const T& e);
	SmarterArray<T> operator-(const SmarterArray<T> &L) const;
	//ques8
	void insert(const T& value, const int& index);
	//ques9
	bool operator==(const SmarterArray<T> &L) const;
	//ques 10
	SmarterArray<T> operator+(const SmarterArray<T> &L);

	template <class T1>
	friend ostream& operator << (ostream& cout, const SmarterArray<T1> &L);

};

//Constructors
template<class T>
SmarterArray<T>::SmarterArray()
{
	this->size = 0;
	this->A = nullptr;
}

template<class T>
SmarterArray<T>::SmarterArray(const T* A, const int& size)
{
	this-> size = size;
	if(this->getSize() > 0)
	{
		this-> A = new T[this->getSize()];
		for(int i = 0; i < this->getSize(); i++)
		{
			this->A[i] = A[i];
		}
	}

}

template<class T>
SmarterArray<T>::SmarterArray(const SmarterArray<T> &L) //Copy constructor
{
	this->size = L.getSize();
	if(this->getSize() > 0)
	{
		this->A = new T[this->getSize()];
		for(int i = 0; i < this->getSize(); i++)
			this->A[i] = L[i];
	}
}

//Assignment operator
template<class T>
SmarterArray<T>& SmarterArray<T>::operator = (const SmarterArray<T> &L)
{
	//Check for self assignment. If so do nothing
	if (this == &L)
		return *this;
	//Delete the left hand side object's memory 
	this->~SmarterArray();
	//Now copy the right hand side to left
	this->size = L.getSize();
	if(this->size > 0)
	{
		this-> A = new T[this->getSize()];
		for(int i = 0; i < this->getSize(); i++)
			this->A[i] = L[i];
	}
	return *this;
}

//Destructor
template<class T>
SmarterArray<T>::~SmarterArray()
{
	if(this->getSize() > 0)
	{
		delete[] this->A;
		this->size = 0;
	}
}

//Getters, Setters, operators and other functions
template <class T>
int SmarterArray<T>::getSize() const
{
	return this->size;
}

template <class T>
T& SmarterArray<T>::operator[](const int& index) const
{
	if(index < 0 || index >= this->getSize())
	{
		cout << "Error! Index out of bounds." << endl;
		abort();
	}
	return this->A[index];
}

template <class T>
int SmarterArray<T>::find(const T& e) const
{
	for(int i = 0; i < this->getSize(); i++)
		if(this->A[i] == e)
			return i;  //return index if found
	return -1; //return -1 to mean not found
}

template <class T>
void SmarterArray<T>::append(const T& e)
{
	//First create a temporary array whose size is this->size+1
	T* temp = new T[this->getSize()+1];

	//Copy the elements of this->A to temp
	for(int i = 0; i < this->getSize(); i++)
		temp[i] = this->A[i];
	
	//Copy the element to be appended to temp
	temp[this->getSize()] = e;

	//Delete the existing array this->A
	if(this->getSize() > 0)
		delete[] this->A;

	//Make the array this->A to point to temp and increment the size
	this->A = temp;
	this->size += 1;
}

template <class T>
bool SmarterArray<T>::remove(const T& e)
{
	int index = this->find(e);
	if(index == -1)
		return false;
	else if(this->getSize() == 1)
	{
		this->~SmarterArray();
		return true;
	}
	else
	{
		//First create a temporary array whose size is this->size-1
		T* temp = new T[this->getSize()-1]

		//Copy the elements of this->A to temp except the element at index
		for(int i = 0; i < index; i++)
			temp[i] = this->A[i];
		for(int i = index+1; i < this->size; i++)
			temp[i-1] = this->A[i];

		//Delete the existing array 
		delete[] this->A;

		//Make the array this->A to point to temp and decrement the size
		this->A = temp;
		this->size -= 1;
		return true;
	}
}

template <class T>
SmarterArray<T> SmarterArray<T>::operator-(const SmarterArray<T> &L) const
{
	//Returns the eleements of this that are not found in L
	SmarterArray<T> A;
	for(int i = 0; i < this->getSize(); i++)
	{
		int index = L.find(this->A[i]);
		if(index == -1)
			A.append(this->A[i]);
	}
	return A;
}

template <class T1>
ostream& operator << (ostream& cout, const SmarterArray<T1> &L)
{
	cout << "[";
	for(int i = 0; i < L.getSize() -1; i++)
		cout << L[i] << ", ";
	if(L.getSize() > 0)
		cout << L[L.getSize() -1];
	cout <<"]";
	return cout;
}

//8. Given the SmarterArray class template, add a member function named insert that takes an index and a 
//value arguments so that the function first asserts the index argument is such that index >= 0 &&index 
//<= size and then inserts the value at the required index in the calling object. If the index argument is 
//equal to size, then this function should append the value to the calling object
template <class T>
void SmarterArray<T>::insert(const T& value, const int& index)
{
	if(index < 0 || index > this->size)
	{
		cout << "Index out of bound error."<< endl;
		abort();
	}
	else
	{
		if(index == this->size)
			this->append(value);
		else
		{
			//use append 
			T* temp = new T[this->size + 1];
			for(int i = 0; i < index; i++)
				temp[i] = this->A[i];
			temp[index] = value;
			for(int i = index + 1; i < this->size + 1; i++)
				temp[i] = this->A[i-1];

			delete[] this->A;
			this->A = temp;
			this->size += 1;
		}
	}
}


//9. Given the SmarterArray class template we have implemented during lecture, add an operator member 
//function == that returns true if the right hand side operand has the same number of elements as the left 
//hand side operand and elements at corresponding indexes are identical. Otherwise returns false
template <class T>
bool SmarterArray<T>::operator==(const SmarterArray<T> &L) const
{
	if(this->size != L.size)
		return false;
	else
	{
		for(int i = 0; i < this->size; i++)
		{
			if(this->A[i] != L.A[i])
				return false;
		}
		return true;
	}
}

//10. Given the SmarterArray class template we have implemented during lecture, add an operator member 
//function + that returns a new SmarterArray object that is the concatenation of the operands.
template <class T>
SmarterArray<T> SmarterArray<T>::operator+(const SmarterArray<T> &L) 
{
	SmarterArray<T> A1;
	A1.size = this->size + L.size;
	A1.A = new T[A1.size];
	for(int i = 0; i < this->size; i++)
		A1.A[i] = this->A[i];
	for(int i = this->size; i < A1.size; i++)
		A1.A[i] = L.A[i-this->size];
	return A1;
}


//11. Given the Map class template, add a member function named insert that takes an index and a key-value 
//pair arguments so that the function first asserts the index argument is such that index >= 0 && index 
//<= size and then inserts the key-value pair at the required index in the calling object. If the index 
//argument is equal to size, then this function should append the key-value pair to the calling object

template <class K, class V>
class Map
{
private:
	SmarterArray<K> A1; //input value(domain) or the keys of the map
	SmarterArray<V> A2; //output value(range) or the values of the map
public:
	//Constructors
	Map();
	Map(const Map<K, V>&); //Copy constructor

	//Assignment operator
	Map<K,V>& operator=(const Map<K, V>&);

	//Destructor
	~Map();

	//Getters, Setters, operators and other functions
	int getSize() const;  //Return the size of the map
	int findKey(const K&) const; //Return the index of the first element of the Keys array == the argument. Return -1 if not found.
	int findValue(const V&) const; //Return the index of the first element of the Values array == the argument. Return -1 if not found.
	K getKey(const V&) const; //Asserts the argument is found in the Values array and then returns the first key with the given value
	V getValue(const K&) const; //Asserts the argument is found in the Keys array and then return the first value with the given key
	K getKeyAtIndex(const int&) const;
	V getValueAtIndex(const int&) const;
	void setKeyAtIndex(const int&, const K&);
	void setValueAtIndex(const int&, const V&);
	void append(const K&, const V&);
	//ques 11
	void insert(const K& key, const V& value, const int& index);


	template <class K1, class V1>
	friend ostream& operator << (ostream&, const Map<K1, V1>&);
};

//Default constructor
template <class K, class V>
Map<K,V>::Map()
{
	//No code needed
	//memeber variables will be automatically initialized as default objects
}

template <class K, class V>
Map<K,V>::Map(const Map<K, V>& M)
{
	this->A1 = M.A1;
	this->A2 = M.A2;
}

template <class K, class V>
Map<K, V>& Map<K,V>::operator=(const Map<K,V>& M)
{
	this->A1 = M.A1;
	this->A2 = M.A2;
	return *this;
}

template <class K, class V>
Map<K, V>::~Map()
{
	A1.~SmarterArray();
	A2.~SmarterArray();
}

template <class K, class V>
int Map<K, V>::getSize() const
{
	return A1.getSize();  //we can return the size of any one of them bcs by design their size will be the same
}

template <class K, class V>
int Map<K, V>::findKey(const K& key) const
{
	return A1.find(key);
}

template <class K, class V>
int Map<K, V>::findValue(const V& value) const
{
	return A2.find(value);
}

template <class K, class V>
K Map<K,V>::getKey(const V& value) const
{
	int index = A2.find(value);
	assert(index != -1);
	return A1[index];
}

template <class K, class V>
V Map<K,V>::getValue(const K& key) const
{
	int index = A1.find(key);
	assert(index != -1);
	return A2[index];
}

template <class K, class V>
K Map<K, V>::getKeyAtIndex(const int& index) const
{
	assert(index >= 0 && index < A1.getSize());
	return A1[index];
}

template <class K, class V>
V Map<K, V>::getValueAtIndex(const int& index) const
{
	assert(index >= 0 && index < A1.getSize());
	return A2[index];
}

template <class K, class V>
void Map<K, V>::setKeyAtIndex(const int& index, const K& key)
{
	assert(index >= 0 && index < A1.getSize());
	A1[index] = key;
}

template <class K, class V>
void Map<K, V>::setValueAtIndex(const int& index, const V& value)
{
	assert(index >= 0 && index < A1.getSize());
	A2[index] = value;
}

template <class K, class V>
void Map<K, V>::append(const K& key, const V& value)
{
	A1.append(key);
	A2.append(value);
}

template <class K1, class V1>
ostream& operator << (ostream& cout, const Map<K1, V1>& m)
{
	if(m.getSize() == 0)
		cout << "[Empty Map]" << endl;
	else
	{
		cout << endl;
		cout << "Keys \t\t Values" << endl;
		cout << "==== \t\t ======" << endl;
		for(int i = 0; i < m.getSize(); i++)
			cout << m.A1[i] << "\t\t" << m.A2[i] << endl;
	}
	return cout;
}


//11. Given the Map class template, add a member function named insert that takes an index and a key-value 
//pair arguments so that the function first asserts the index argument is such that index >= 0 && index 
//<= size and then inserts the key-value pair at the required index in the calling object. If the index 
//argument is equal to size, then this function should append the key-value pair to the calling object
template <class K, class V>	
void Map<K, V>::insert(const K& key, const V& value, const int& index)
{
		this->A1.insert(key, index);
		this->A2.insert(value, index);
}



int main()
{
	//Declare several SmarterArray objects
	SmarterArray<int> A; 
	SmarterArray<int> A1;    //default array of integers
	double x[3] = {2.4, 1.2, 5.8};
	SmarterArray<double> A2(x,3);   //Non-defaulty array of doubles
	SmarterArray<string> A3;        //Default array of strings

	//Populate the SmarterArray objects
	srand(time(0));
	for(int i = 0; i < 10; i++)
	{
		if(rand() % 2 == 0)
		{
			A1.append(rand() % 21 + 5);
			A.append(rand() % 21 + 5);
		}
		else
		{
			int random = rand() % 5;
			A3.append(random == 0 ? "Paul" :
					(random == 1 ? "Jannet" :
					(random == 2 ? "Kevin" :
					(random == 3 ? "Sara" : "CMPT"))));
		}
	}

	//Print the objects 
	cout << "The SmarterArray object A is " << A << endl;
	cout << "The SmarterArray object A1 is " << A1 << endl;
	cout << "The SmarterArray object A2 is " << A2 << endl;
	cout << "The SmarterArray object A3 is " << A3 << endl;

	//testing insert
	A1.insert(9,4);
	cout << "After inserting 9 at index 4 A1 is " << A1 << endl;

	//testing operator ==
	if(A1.operator==(A1)) cout << "A1 is equal to A1" << endl;
	else cout << "A1 is not equal to A1" << endl;

	if(A1.operator==(A)) cout << "A1 is equal to A" << endl;
	else cout << "A1 is not equal to A" << endl;

	//testing concatenation
	cout << "Adding strings A1 and A to Sum" << endl;
	SmarterArray<int> Sum = A1.operator+(A);
	cout << "Sum = " << Sum << endl;

	//Testing the map class
	cout << "****Testing the map class****" << endl;
	Map<string, double> m1;
	cout << "m1 is " << m1 << endl;

	//Test append and getSize member functions
	const int size = 5;
	string city[size] = {"Burnaby", "Surrey", "New West", "Delta", "Coquitlam"};
	double distance[size] = {10.8, 20.5, 15.4, 21.8, 18.1};
	for(int i = 0; i < size; i++)
		m1.append(city[i], distance[i]);
	cout << "Now m1 is " << m1 << endl;
	cout << "m1 has " << m1.getSize() << " key-value pair elements in it." << endl;

	//Test copy constructor
	Map<string, double> m2(m1);
	cout << "m2 is " << m2 << endl;

	//Test destructor
	m1.~Map();
	cout << "Now m1 is " << m1 << endl;
	cout << "m2 is still " << m2 << endl;

	//Test assignement operator
	m1 = m2;
	cout << "Now m1 is " << m1 << endl;
	m2.~Map();
	cout << "m2 is destructed. m2 is now " << m2 << endl;

	//Testing other memeber functions
	cout << "The city Delta is found in the keys array at index " << m1.findKey("Delta") << endl;
	cout << "A city whose distance from Vancouver is 18.1 is found at index " << m1.findValue(18.1) << endl;
	cout << "A city whose distance from Vancouver is 18.1 is " << m1.getKey(18.1) << endl;
	cout << "The distance of New West from Vancouver is " << m1.getValue("New West") << endl;
	cout << "The city at index 2 of the keys array is  " << m1.getKeyAtIndex(2) << endl;
	cout << "The distance at index 4 in the Values array at index " << m1.getValueAtIndex(4) << endl;

	m1.setKeyAtIndex(0, "North Vancouver");
	cout << "The city at index 0 of the Keys array is " << m1.getKeyAtIndex(0) << endl;
	m1.setValueAtIndex(0, 17.7);
	cout << "The distance at index 0 in the Values array at index " << m1.getValueAtIndex(0) << endl;
	cout << "At last m1 is " << m1 << endl;

	//Testing insert in Map
	m1.insert("Port Moody", 14.3,3);
	cout << "After inserting m1 is now " << m1 << endl;


	system("Pause");
	return 0;
}




