#include <iostream>
using namespace std;

class CMPT135_String
{
private:
	char *buffer;	//This will be the dynamic array to hold the characters
public:
	//static member function to compute the length of null terminated char arrays
	static int cstrlen(const char *cStr); 

	//Default Constructor
	CMPT135_String();

	//Non-default Constructors
	CMPT135_String(const char &c);
	CMPT135_String(const char *cStr); //*cStr is a null terminated char array

	//Copy Constructor
	CMPT135_String(const CMPT135_String &s);

	//Destructor
	~CMPT135_String();

	//Assignment operators
	CMPT135_String& operator = (const CMPT135_String &s);
	CMPT135_String& operator = (const char &c);
	CMPT135_String& operator = (const char *cStr); //*cStr is a null terminated char array

	//Getter member functions
	int length() const;
	char& operator[](const int &index) const;

	//Setter member functions
	void append(const CMPT135_String &s);
	void append(const char &c);
	void append(const char *cStr); //*cStr is a null terminated char array

	//Operator member functions
	CMPT135_String operator + (const CMPT135_String &s) const;
	CMPT135_String operator + (const char &c) const;
	CMPT135_String operator + (const char *cStr) const; //*cStr is a null terminated char array
	CMPT135_String& operator += (const CMPT135_String &s);
	CMPT135_String& operator += (const char &c);
	CMPT135_String& operator += (const char *cStr); //*cStr is a null terminated char array
	bool operator == (const CMPT135_String &s) const;
	bool operator == (const char *cStr) const; //*cStr is a null terminated char array
	bool operator != (const CMPT135_String &s) const;
	bool operator != (const char *cStr) const; //*cStr is a null terminated char array
	bool operator < (const CMPT135_String &s) const;
	bool operator < (const char *cStr) const; //*cStr is a null terminated char array
	bool operator > (const CMPT135_String &s) const;
	bool operator > (const char *cStr) const; //*cStr is a null terminated char array
	bool operator <= (const CMPT135_String &s) const;
	bool operator <= (const char *cStr) const; //*cStr is a null terminated char array
	bool operator >= (const CMPT135_String &s) const;
	bool operator >= (const char *cStr) const; //*cStr is a null terminated char array
	
	//Friend Functions (for operators)
	friend CMPT135_String operator + (const char &c, const CMPT135_String &s);
	friend CMPT135_String operator + (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator == (const char *cStr, const CMPT135_String &s); //*cStr a null terminated char array
	friend bool operator != (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator < (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator > (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator <= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator >= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend ostream& operator << (ostream& outputStream, const CMPT135_String &s);
	friend istream& operator >> (istream& inputStream, CMPT135_String &s);
};



//STATIC MEMBER FUNCTION
//Explanation of the member and friend functions
//1.
int CMPT135_String::cstrlen(const char *cStr)
{
	/*
	This function returns the number of printable characters in the null terminated
	character array cStr. That is, it returns the number of characters in the 
	array excluding the terminating null character.

	If the pointer cStr does not have any allocated memory but instead it is
	a nullptr, then this function returns 0.

	This means there are two different cases for which this function returns 0.
	The first case is if the cStr pointer has a nullptr value and the second case
	is when cStr is a dynamic array of size 1 with cStr[0] = '\0'

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	if (cStr == nullptr)
		return 0;
	else
	{
		int len = 0;
		while (cStr[len] != '\0')
			len++;
		return len;
	}
}



//DEFAULT CONSTRUCTOR
//2.
CMPT135_String::CMPT135_String()
{
	/*
	This function constructs a default CMPT135_String object whose pointer member 
	variable is initialized to nullptr. 

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	buffer = nullptr;
}



//NON-DEFAULT CONSTRUCTORS
//3.
CMPT135_String::CMPT135_String(const char &c)
{
	/*
	This function constructs a non-default CMPT135_String that contains one printable
	character (which is the argument) and a null character at the end.

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	buffer = new char[2];
	buffer[0] = c;
	buffer[1] = '\0';

}
//4.
CMPT135_String::CMPT135_String(const char *cStr) //*cStr is a null terminated char array
{
	/*
	This function constructs a non-default CMPT135_String that contains all the printable
	characters of the argument and a null character at the end.

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	int len = CMPT135_String::cstrlen(cStr);                 
	if (len == 0)
		buffer = nullptr;
	else
	{
		buffer = new char[len+1];
		for (int i = 0; i < len; i++)
			buffer[i] = cStr[i];
		buffer[len] = '\0';
	}

}


//COPY CONSTRUCTORS
//5.
CMPT135_String::CMPT135_String(const CMPT135_String &s)
{
	/*
	This function constructs a CMPT135_String object which is a copy of the argument s
	*/
	int len = CMPT135_String::cstrlen(s.buffer);
	if(len > 0)
	{
		this->buffer = new char[len+1];
		for(int i = 0; i < len; i++)
			this->buffer[i] = s[i];
		this->buffer[len] = '\0';
	}
	else
	this->buffer = nullptr;
}


//DESTRUCTOR
//6.
CMPT135_String::~CMPT135_String()
{
	/*
	This function destructs a CMPT135_String object. That is it deletes its buffer and 
	assigns the buffer a nullptr value

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	if (buffer != nullptr)
	{
		delete[] buffer;
		buffer = nullptr;
	}
}


//ASSIGNMENT OPERATORS
//7.
CMPT135_String& CMPT135_String::operator = (const CMPT135_String &s)
{
	/*
	This function assigns a copy of the value of the argument s to the calling object
	*/
	//Check for self assignment
	if(this == &s)
		return *this;
	//Delete the LHS object's memory
	this->~CMPT135_String();
	//Now copy the RHS to LHS
	int len = CMPT135_String::cstrlen(s.buffer);
	if(len > 0)
	{
		this->buffer = new char[len+1];
		for(int i = 0; i < len; i++)
			this->buffer[i] = s.buffer[i];
		this->buffer[len] = '\0';
	}
	else
	this->buffer = nullptr;

	return *this;
}
//8.
CMPT135_String& CMPT135_String::operator = (const char &c)
{
	/*
	This function assigns a copy of a CMPT135_string object constructed from the character argument
	to the calling object
	*/

	//Delete the LHS object's memory
	this->~CMPT135_String();
	//Then assign the memory
	this->buffer = new char[2];
	this->buffer[0] = c;          
	this->buffer[1] = '\0';
	return *this;
}
//9.
CMPT135_String& CMPT135_String::operator = (const char *cStr) //*cStr is a null terminated char array
{
	/*
	This function assigns a copy of a CMPT135_string object constructed from the null terminated 
	character array argumentto the calling object
	*/
	//Delete the LHS object's memory
	this->~CMPT135_String();
	CMPT135_String temp(cStr);
	this->operator=(temp);  //same as *this = temp;
	return *this;
}


//GETTER MEMBER FUNCTIONS
//10. (GETTING THE LENGTH FOR THE STATIC MEMBER FUNCTION
int CMPT135_String::length() const
{
	/*
	This function returns the length of the buffer of the calling objects as computed by the static
	member function CMPT135_String::cstrlen

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	return CMPT135_String::cstrlen(buffer);
}
//11.
char& CMPT135_String::operator[](const int &index) const
{
	/*
	This function returns the PRINTABLE character at the given index of the calling object.
	If the index is out of the valid bounds, then error message should be printed.
	This function must crash the application using the abort built-in function
	if index out of bound error occurs.
	The valid bounds of the index are in the range [0,this->length()-1]
	*/

	if(index >= 0 && index <= this->length()-1)
		return this->buffer[index];
	else 
		cout << "ERROR....... Index out of bound." << endl;
		abort();
}


//SETTER MEMBER FUNCTIONS
//12.
void CMPT135_String::append(const CMPT135_String &s)
{
	/*
	This function appends all the printable characters of the argument s to the calling object.
	*/
	int len = s.length(); //length of the argument to be appended 
	int len1 = this->length(); //length of the calling object

	char* temp = new char[len1 + len + 1];

	//copying the elements of the calling object to temp
	for(int i = 0; i < len1; i++)
		temp[i] = this->buffer[i];
	for(int j = len1,i=0; j < (len1+len); j++,i++)
		temp[j] = s.buffer[i];
	temp[len1 + len] = '\0';

	//delete the existing array of characters named buffer
	if(len1 > 0)
	delete[] this->buffer;

	//make the array point to temp
	this->buffer = temp;
	
}
//13.
void CMPT135_String::append(const char &c)
{
	/*
	This function appends the character argument to the calling object
	*/
	//finding the length of the calling object
	int len = CMPT135_String::cstrlen(this->buffer);
	char* temp = new char[len + 1 + 1];//one plus one for the null character and one for the char to be appended
	//copying the elements of the calling object to temp
	for(int i = 0; i < len; i++)
		temp[i] = this->buffer[i];
	temp[len] = c;
	temp[len + 1] = '\0';
	//delete the existing array of character i.e. buffer
	if(len > 0)
	delete[] this->buffer;
	//make the array point to temp
	this->buffer = temp;

}
//14.
void CMPT135_String::append(const char *cStr) //*cStr is a null terminated char array
{
	/*
	This function appends all the printable characters of the argument cStr to the calling object.
	*/
	CMPT135_String temp(cStr);
	this->append(temp);
}

//OPERATOR MEMBER FUNCTIONS
//15.
CMPT135_String CMPT135_String::operator + (const CMPT135_String &s) const
{
	/*
	This function returns a CMPT135_String object constructed from all the characters of the
	calling object followed by the characters of the argument s
	*/
	//length of calling object
	int lenC = CMPT135_String::cstrlen(this->buffer);
	//length of the argument of the function
	int lenA = s.length();

	//create a CMPT135_String with size lenC + lenA + 1
	CMPT135_String sum = new char[lenC + lenA + 1];
	//copy all the char of the calling object into sum
	for(int i = 0; i < lenC; i++)
		sum.buffer[i] = this->buffer[i];
	//copy all the char of the string argument into sum
	for(int j = lenC, i = 0; j < lenC + lenA; j++,i++)
		sum.buffer[j] = s[i];
	sum.buffer[lenC + lenA] = '\0';
	return sum;

}
//16.
CMPT135_String CMPT135_String::operator + (const char &c) const
{
	/*
	This function returns a CMPT135_String object constructed from all the characters of the
	calling object followed by the character argument c
	*/
	//length of calling object
	int lenC = CMPT135_String::cstrlen(this->buffer);

	//Create a CMPT135_String with size lenC + 1 + 1
	CMPT135_String sum = new char[lenC + 1 + 1];
	//copy all the char of the calling object into sum
	for(int i = 0; i < lenC; i++)
		sum.buffer[i] = this->buffer[i];
	//copy the char argument at the end
	sum.buffer[lenC] = c;
	sum.buffer[lenC + 1] = '\0';
	return sum;

}
//17.
CMPT135_String CMPT135_String::operator + (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function returns a CMPT135_String object constructed from all the characters of the
	calling object followed by the characters of the null terminated character array argument cStr
	*/
	CMPT135_String temp(cStr);
	return this->operator+(temp);  //same as *this + temp

}
//18.
CMPT135_String& CMPT135_String::operator += (const CMPT135_String &s)
{
	/*
	This function appends the characters of s to the calling object and then
	returns the calling object
	*/
	this->append(s);
	return *this;
}
//19.
CMPT135_String& CMPT135_String::operator += (const char &c)
{
	/*
	This function appends the character c to the calling object and then
	returns the calling object
	*/
	this->append(c);
	return *this;
}
//20.
CMPT135_String& CMPT135_String::operator += (const char *cStr) //*cStr is a null terminated char array
{
	/*
	This function appends the characters of the null terminated character array cStr
	to the calling object and then returns the calling object
	*/
	CMPT135_String temp(cStr);
	this->append(temp);
	return *this;
}
//21.
bool CMPT135_String::operator == (const CMPT135_String &s) const
{
	/*
	This function tests if the calling object is equal to the argument s
	NOTE:- Two CMPT135_String are equal if they have the same length and characters of the
	calling object are equal to the characters of the argument s at corresponding indexes.

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	int len = this->length();
	if (len != s.length())
		return false;
	else
	{
		for (int i = 0; i<len; i++)
		{
			if (buffer[i] != s[i])
				return false;
		}
		return true;
	}
}
//22.
bool CMPT135_String::operator == (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function tests if the calling object is equal to the null terminated character array cStr.
	In other words, this function tests if the calling object is equal to a CMPT135_String object 
	constructed from the null terminated character array argument
	*/
	CMPT135_String temp(cStr);
	if(*this == temp)
		return true;
	return false;
	
}
//23.
bool CMPT135_String::operator != (const CMPT135_String &s) const
{
	/*
	This function tests if the calling object is not equal to the argument s
	*/
	if(*this == s)
		return false;
	return true;
}
//24.
bool CMPT135_String::operator != (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function tests if the calling object is not equal to the null terminated character array 
	cStr
	*/
	CMPT135_String temp(cStr);
	if(*this == temp)
		return false;
	return true;
}
//25.
bool CMPT135_String::operator < (const CMPT135_String &s) const
{
	/*
	This function tests if the calling object is less than the argument s
	NOTE:- Given two CMPT135_String objects s1 and s2, we compare them as follows:
		Step 1. Find the smallest valid index k such that s1[k] IS NOT EQUAL TO s2[k]
		Step 2. If such an index k is found, then
			2.1 We say s1 < s2 if s1[k] < s2[k]
			2.2 Otherwise s1 > s2
		Step 3. If such an index k is not found, then
			3.1 We say s1 < s2 if the length of s1 is less than the length of s2
			3.2 We say s1 > s2 if the length of s1 is greater than the length of s2
			3.3 We say s1 == s2 if the length of s1 is equal to the length of s2.
	*/

	                                              
	//length of the calling object               //Step-1 
	int lenC = this->length();
	//length of the argument
	int lenA = s.length();
	//now loop about the samller length 
	int l = lenC < lenA ? lenC : lenA;
	int index = -1;
	for(int i = 0; i < l; i++)
	{
		if(this->buffer[i] != s.buffer[i])  
		{
			index = i;
			break;
		}
		
	}

	
	if(index >= 0 && index <= (l-1))                //Step 2
	{
		if(this->buffer[index] < s.buffer[index])
			return true;
		else
			return false;
	}
	else                                             //Step 3
	{
		if(lenC < lenA)
			return true;
		else                                        // here either the lenC > lenA or lenC == lenA
			return false;
	}





}
//26.
bool CMPT135_String::operator < (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function tests if the calling object is less than the null terminated character array cStr
	*/
	CMPT135_String temp(cStr);
	return *this < temp; //same as this->operator<(temp);

}
//27.
bool CMPT135_String::operator > (const CMPT135_String &s) const
{
	/*
	This function tests if the calling object is greater than the argument s
	*/
	//check for equality first
	if(this->operator==(s))
		return false;
	else
	{
		if(*this < s)
			return false;
		return true;
	}
}
//28.
bool CMPT135_String::operator > (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function tests if the calling object is greater than the null terminated character array 
	cStr
	*/
	CMPT135_String temp(cStr);
	return *this > temp;
}
//29.
bool CMPT135_String::operator <= (const CMPT135_String &s) const
{
	/*
	This function tests if the calling object is less than or equal to the argument s
	*/
	if(*this > s)
		return false;
	return true;
}
//30.
bool CMPT135_String::operator <= (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function tests if the calling object is less than or equal to the null terminated character 
	array cStr
	*/
	CMPT135_String temp(cStr);
	return *this <= temp;
}
//31.
bool CMPT135_String::operator >= (const CMPT135_String &s) const
{
	/*
	This function tests if the calling object is greater than or equal to the argument s
	*/
	if(*this < s)
		return false;
	return true;
}
//32.
bool CMPT135_String::operator >= (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function tests if the calling object is greater than or equal to the null terminated 
	character array cStr
	*/
	CMPT135_String temp(cStr);
	return *this >= temp;
}
//33.
CMPT135_String operator + (const char &c, const CMPT135_String &s)
{
	/*
	This function returns a CMPT135_String object constructed from the character argument c followed 
	by the characters of s
	*/
	CMPT135_String temp(c);
	temp.append(s);
	return temp;
}
//34.
CMPT135_String operator + (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
	/*
	This function returns a CMPT135_String object constructed from thecharacters of the null
	terminated character array argument cStr followed by the characters of s
	*/
	CMPT135_String temp(cStr);
	temp.append(s);
	return temp;
}
//35.
bool operator == (const char *cStr, const CMPT135_String &s) //*cStr a null terminated char array
{
	/*
	This function tests if the null terminated character array argument cStr is equal to s
	*/
	CMPT135_String temp(cStr);
	return temp == s;
}
//36.
bool operator != (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
	/*
	This function tests if the null terminated character array argument cStr is not equal to s
	*/
	CMPT135_String temp(cStr);
	return temp != s;
}
//37.
bool operator < (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
	/*
	This function tests if the null terminated character array argument cStr is less than s
	*/
	CMPT135_String temp(cStr);
	return temp < s;
}
//38.
bool operator > (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
	/*
	This function tests if the null terminated character array argument cStr is greater than s
	*/
	CMPT135_String temp(cStr);
	return temp > s;
}
//39.
bool operator <= (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
	/*
	This function tests if the null terminated character array argument cStr is less than or equal 
	to s
	*/
	CMPT135_String temp(cStr);
	return temp <= s;
}
//40.
bool operator >= (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
	/*
	This function tests if the null terminated character array argument cStr is greater than or 
	equal to s
	*/
	CMPT135_String temp(cStr);
	return temp >= s;
}

//41.
ostream& operator << (ostream& out, const CMPT135_String &s)
{
	/*
	This function prints the printable characters in the dynamic array member variable buffer.
	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	for (int i = 0; i < s.length(); i++)
		out << s.buffer[i];
	return out;
}
//42.
istream& operator >> (istream& in, CMPT135_String &s)
{
	/*
	This function is designed to read ANY number of characters from the user.Reading will stop 
	when the user presses the Enter Key. In order to achieve this, we will read one character at a 
	time until end of line character ('\n') is read.
	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	s.~CMPT135_String();
	char c;
	while (true)
	{
		in.get(c);
		if (c == '\n')
			break;
		else
			s.append(c);
	}
	return in;
}

int findCharIndex(const CMPT135_String& s, const char& c) 
{
	/*
	This function takes a CMPT135_String and a character arguments and returns the smallest valid
	index of the CMPT135_String argument such that the character of the CMPT135_String argument at 
	that index is equal to the character argument. If no such an index is found, then this function 
	must return -1.
	*/
	int len = s.length();
	int index = -1;
	for(int i = 0; i < len; i++)
	{
		if(s[i] == c)
		{
			index = i;
			return index;
		}
	}
	return index;
}
	
int reverseFindCharIndex(const CMPT135_String& s, const char& c)
{
	/*
	This function takes a CMPT135_String and a character arguments and returns the largest valid
	index of the CMPT135_String argument such that the character of the CMPT135_String argument at 
	that index is equal to the character argument. If no such an index is found, then this function 
	must return -1.
	*/
	//now we just have to loop from the very end till [0], i.e. [len-1, 0]
	int len = s.length();
	int index = -1;
	for(int i = (len - 1); i >= 0; i--)
	{
		if(s[i] == c)
		{
			index = i;
			return index;
		}
	}
	return index;
	
}

int countChar(const CMPT135_String& s, const char& c)
{
	/*
	This function takes a CMPT135_String and a character arguments and returns the number of times the
	character argument is found in the CMPT135_String argument.
	*/
	int count = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == c)
			count++;
	}
	return count;
}


CMPT135_String getSubString(const CMPT135_String& s, const int& sIndex, const int& len)
{
	/*
	This function takes a CMPT135_String, a start index, and a length arguments and returns a
	CMPT135_String object with as many as length characters constructed from the characters of the
	CMPT135_String argument starting from the given start index. If there are no enough characters
	to copy as many as length characters from the CMPT135_String argument, then ONLY the available
	characters up to the end of the CMPT135_String argument are copied and a CMPT135_String with a
	shorter length is returned.
	The returned object is known as a substring of the CMPT135_String argument.
	*/
	int len_s = s.length();  //length of s
	if(sIndex >= len_s || sIndex < 0) //bcs the index should only be b/w [0, len_s - 1]
	{
		cout << "ERROR......... Index out of bound" << endl;
		abort();
	}

	int size = (len_s - sIndex) + 1;
	char* cStr = new char[size];    
	for(int i = 0, j = sIndex; i < size - 1; i++, j++)
		cStr[i] = s[j];
	cStr[size - 1] = '\0';

	CMPT135_String temp;
	if(len >= (size-1)) temp = cStr;
	else
	{
		cStr[len] = '\0';
	    temp = cStr;
	}


	delete[] cStr;
	return temp;
}

bool isSubString(const CMPT135_String& s1, CMPT135_String s2)
{
	/*
	This function takes two CMPT135_String objects s1 and s2 as arguments and returns true if there
	exists a substring of s2 that is equal to s1; otherwise it returns false.
	*/
	// here s2 will be the bigger one
	for(int i = 0;i < (s2.length()); i++)
	{
		if(s2[i] == s1[0])
		{
			CMPT135_String temp = getSubString(s2, i, s1.length());
			if(s1 == temp) return true;
		}
	}
	return false;
}


CMPT135_String getReversedString(const CMPT135_String& s)
{
	/*
	This function takes a CMPT135_String argument and returns a CMPT135_String object constructed from
	the characters of the CMPT135_String argument in reverse order.
	*/
	CMPT135_String temp = s;

	for(int i = (s.length()-1), j = 0; i >= 0; i--, j++)
	{
		temp[i] = s[j];
	}
	return temp;
}


CMPT135_String removeChar(const CMPT135_String& s,const char& c)
{
	/*
	This function takes a CMPT135_String and a character arguments and removes each character of the
	CMPT135_String argument that is equal to the character argument from the CMPT135_String argument.
	*/
	int count = countChar(s,c);
	int sizeOfNew = (s.length() - count)+ 1;
	char* temp = new char[sizeOfNew];
	for(int i = 0, j = 0; i < sizeOfNew-1; i++,j++)
	{
		if(s[i] == c) temp[i] = s[++j];
		else
		temp[i] = s[j];
	}
	temp[sizeOfNew-1] = '\0';
	CMPT135_String r(temp);

	delete[] temp;
	return r;
}


CMPT135_String replaceChar(const CMPT135_String& s, const char& ch1, const char& ch2)
{
	/*
	This function takes a CMPT135_String and two characters named ch1 and ch2 (in that order) as
	arguments and replaces every character in the CMPT135_String argument that is equal to ch1 by
	the character ch2.
	*/
	char* temp = new char[s.length() + 1];
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ch1) temp[i] = ch2;
		else temp[i] = s[i];
	}
	temp[s.length()] = '\0';
	CMPT135_String r(temp);

	delete[] temp;
	return r;
}

//Test Program
int main()
{
	//Test the cstrlen static member function'
	cout << "The length of \"Yonas\" is " << CMPT135_String::cstrlen("Yonas") << endl;
	cout << "The length of \"\" is " << CMPT135_String::cstrlen("") << endl;
	cout << "The length of nullptr is " << CMPT135_String::cstrlen(nullptr) << endl;

	//Test default constructor and length member functions
	CMPT135_String s1;
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;

	//Test non-default constructor and length member functions
	CMPT135_String s2 = 'Y';
	cout << "s2 is \"" << s2 << "\" and its length is " << s2.length() << endl;

	//Test non-default constructor and length member functions
	CMPT135_String s3 = "CMPT 135";
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;

	//Test copy constructor and length member functions
	CMPT135_String s4 = s3;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;
	
	//Test destructor and length member functions
	s4.~CMPT135_String();
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = s2;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = 'A';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = "This is cool";
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test indexing operator member function
	cout << "s4[2] is " << s4[2] << endl;
	s4[2] = 'a';
	cout << "s4[2] is " << s4[2] << endl;
	s4[3] = 't';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test append and length member functions
	s1.append(s4);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;

	//Test append and length member functions
	s3.append(' ');
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;

	//Test append and length member functions
	s3.append("201901");
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;
	
	//Test findCharIndex non-member function
	char ch = '1';
	int k = findCharIndex(s3, ch);
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = findCharIndex(s3, 'm');
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;

	//Test reverseFindCharIndex non-member function
	ch = '1';
	k = reverseFindCharIndex(s3, ch);
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = reverseFindCharIndex(s3, 'm');
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	
	//Test countChar non-member function
	ch = '1';
	k = countChar(s1, ch);
	cout <<  "'" << ch << "' appears " << k << " times in \"" << s1 << "\"" << endl;

	//Test getSubString non-member function
	s1 = getSubString(s3, 10, 3);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	s1 = getSubString(s3, 10, 5);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	s1 = getSubString(s3, 10, 8);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	
	//Test isSubString non-member function
	if (isSubString(s1, s3) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s3 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s3 << "\"" << endl;
	s2 = "01902029010190";
	if (isSubString(s1, s2) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s2 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s2 << "\"" << endl;
	char x[] = "01902019010190";
	if (isSubString(s1, x) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << x << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << x << "\"" << endl;
	
	//Test getReversedString non-member function
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	CMPT135_String rev = getReversedString(s1);
	cout << "The reverse of \"" << s1 << "\" is \"" << rev << "\"" << endl;
	
	//Test removeChar non-member function
	cout << "After removing all the '" << ch << "' characters from \"" << s1 << "\", we get ";
	s1 = removeChar(s1, ch);
	cout << "\"" << s1 << "\"" << endl;

	s3 = "11111111111";
	cout << "After removing all the '" << ch << "' characters from \"" << s3 << "\", we get ";
	s3 = removeChar(s3, ch);
	cout << "\"" << s3 << "\"" << endl;
	
	//Test replaceChar non-member function
	cout << "After replacing 1 by 5 from \"" << s2 << "\", we get " ;
	s2 = replaceChar(s2, '1', '5');
	cout << s2 << endl;

	//Test + operator member function
	cout << "s1 is \"" << s1 << "\", s3 is \"" << s3 << "\" and s1 + s3 is \"" << s1 + s3 << "\"" << endl;
	cout << "s1 is \"" << s1 << " and s1 + \"yonas\" is \"" << s1 + "yonas" << endl;
	cout << "s1 is \"" << s1 << " and s1 + 'Y' is \"" << s1 + 'Y' << endl;

	//Test += operatror member function
	s2 = "Test";
	cout << "s1 is \"" << s1 <<"\", s2 is \"" << s2 << "\", and s3 is \"" << s3 << "\"" << endl;
	s3 = s1 += s2;
	cout << "After s3 = s1 += s2, we get s1 is " << s1 <<", s2 is " << s2 << ", and s3 is " << s3 << endl;

	cout << "s2 is \"" << s2 << "\". ";
	s2 += "FIC";
	cout << "After s2 += \"FIC\", we get \"" << s2 << "\"" << endl; 
	cout << "s2 is \"" << s2 << "\". ";
	s2 += '!';
	cout << "After s2 += '!', we get \"" << s2 << "\"" << endl;

	//Test relational operators member functions
	s1 = "Test1";
	s2 = "";
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 == s2 is " << (s1 == s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 != s2 is " << (s1 != s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 > s2 is " << (s1 > s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 < s2 is " << (s1 < s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 >= s2 is " << (s1 >= s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 <= s2 is " << (s1 <= s2) << endl;

	//Test + friend functions
	cout << "\"Yonas\" + \"" << s1 << "\" is \"" << "Yonas" + s1 << "\"" << endl;
	cout << "'y' + \"" << s1 << "\" is \"" << 'y' + s1 << "\"" << endl;

	//Test friend relational operators
	cout << "s1 is \"" << s1 << "\" and \"Test2\" == s1 is " << ("Test2" == s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" != s1 is " << ("Test2" != s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" < s1 is " << ("Test2" < s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" > s1 is " << ("Test2" > s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" <= s1 is " << ("Test2" <= s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" >= s1 is " << ("Test2" >= s1) << endl;

	//Test input streaming operator
	cout << "Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): ";
	cin >> s1;
	cout << "You entered \"" << s1 << "\"" << endl;
	
	system("pause");
	return 0;
}

////Sample Run Output
//The length of "Yonas" is 5
//The length of "" is 0
//The length of nullptr is 0
//s1 is "" and its length is 0
//s2 is "Y" and its length is 1
//s3 is "CMPT 135" and its length is 8
//s4 is "CMPT 135" and its length is 8
//s4 is "" and its length is 0
//s4 is "Y" and its length is 1
//s4 is "A" and its length is 1
//s4 is "This is cool" and its length is 12
//s4[2] is i
//s4[2] is a
//s4 is "That is cool" and its length is 12
//s1 is "That is cool" and its length is 12
//s3 is "CMPT 135 " and its length is 9
//s3 is "CMPT 135 201901" and its length is 15
//The first index of '1' in "CMPT 135 201901" is 5
//The first index of 'm' in "CMPT 135 201901" is -1
//The last index of '1' in "CMPT 135 201901" is 14
//The last index of 'm' in "CMPT 135 201901" is -1
//'1' appears 0 times in "That is cool"
//s1 is "019" and its length is 3
//s1 is "01901" and its length is 5
//s1 is "01901" and its length is 5
//"01901" is a substring of "CMPT 135 201901"
//"01901" is not a substring of "01902029010190"
//"01901" is a substring of "01902019010190"
//s1 is "01901" and its length is 5
//The reverse of "01901" is "10910"
//After removing all the '1' characters from "01901", we get "090"
//After removing all the '1' characters from "11111111111", we get ""
//After replacing 1 by 5 from "01902029010190", we get 05902029050590
//s1 is "090", s3 is "" and s1 + s3 is "090"
//s1 is "090 and s1 + "yonas" is "090yonas
//s1 is "090 and s1 + 'Y' is "090Y
//s1 is "090", s2 is "Test", and s3 is ""
//After s3 = s1 += s2, we get s1 is 090Test, s2 is Test, and s3 is 090Test
//s2 is "Test". After s2 += "FIC", we get "TestFIC"
//s2 is "TestFIC". After s2 += '!', we get "TestFIC!"
//s1 is "Test1", s2 is "" and s1 == s2 is 0
//s1 is "Test1", s2 is "" and s1 != s2 is 1
//s1 is "Test1", s2 is "" and s1 > s2 is 1
//s1 is "Test1", s2 is "" and s1 < s2 is 0
//s1 is "Test1", s2 is "" and s1 >= s2 is 1
//s1 is "Test1", s2 is "" and s1 <= s2 is 0
//"Yonas" + "Test1" is "YonasTest1"
//'y' + "Test1" is "yTest1"
//s1 is "Test1" and "Test2" == s1 is 0
//s1 is "Test1" and "Test2" != s1 is 1
//s1 is "Test1" and "Test2" < s1 is 0
//s1 is "Test1" and "Test2" > s1 is 1
//s1 is "Test1" and "Test2" <= s1 is 0
//s1 is "Test1" and "Test2" >= s1 is 1
//Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): This is great !
//You entered "This is great !"
//Press any key to continue . . .
