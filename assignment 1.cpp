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
//5.
CMPT135_String::CMPT135_String(const CMPT135_String &s)
{
	/*
	This function constructs a CMPT135_String object which is a copy of the argument s
	*/
	if(s.length() == 0)
		this->buffer = nullptr;
	else
	{
		this->buffer = new char[s.length()+1];
		for(int i = 0; i < this->length(); i++)
			this->buffer[i] = s.buffer[i];
		this->buffer[s.length()] = '\0';
	}
}
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
//7.
CMPT135_String& CMPT135_String::operator = (const CMPT135_String &s)
{
	/*
	This function assigns a copy of the value of the argument s to the calling object
	*/
	
	//check for self assignment. If so do nothing 
	if(this == &s)
		return *this;
	//else delete the left hand side object's memory 
	if(this->buffer != nullptr)
		this->~CMPT135_String();
	//Now copy the right hand side to the left 
	int len = s.length();
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
	//convert char to CMPT 135_String
	CMPT135_String temp(c);
	//then use the assignment operator declared above 
	*this = temp;
	return *this;
}
//9.
CMPT135_String& CMPT135_String::operator = (const char *cStr) //*cStr is a null terminated char array
{
	/*
	This function assigns a copy of a CMPT135_string object constructed from the null terminated 
	character array argumentto the calling object
	*/
	CMPT135_String temp(cStr);
	*this = temp;
	return *this;
}
//10.
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
	if(index >= 0 && index < this->length())
	{
		return this->buffer[index];
	}
	else
	{
		cout << "ERROR! Index out of bounds. Exiting Program..." << endl;
		abort();
	}
}
//12.
void CMPT135_String::append(const CMPT135_String &s)
{
	/*
	This function appends all the printable characters of the argument s to the calling object.
	*/
	//First create a temp array of chars whose size is this->length() + s.lenght()
	char* temp = new char[this->length() + s.length() + 1];
	//copy the chars of the calling object into temp
	for(int i = 0; i < this->length(); i++)
		temp[i] = this->buffer[i];
	//copy the chars of s into temp
	for(int i = this->length(), j = 0; i < this->length() + s.length(); i++, j++)
		temp[i] = s.buffer[j];
	temp[this->length() + s.length()] = '\0';

	//delete the existing array
	this->~CMPT135_String();
	*this = temp;
}
//13.
void CMPT135_String::append(const char &c)
{
	/*
	This function appends the character argument to the calling object
	*/
	CMPT135_String temp(c);
	this->append(temp);
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
//15.
CMPT135_String CMPT135_String::operator + (const CMPT135_String &s) const
{
	/*
	This function returns a CMPT135_String object constructed from all the characters of the
	calling object followed by the characters of the argument s
	*/
	CMPT135_String ans;
	ans.append(*this);
	ans.append(s);
	
	return ans;
}
//16.
CMPT135_String CMPT135_String::operator + (const char &c) const
{
	/*
	This function returns a CMPT135_String object constructed from all the characters of the
	calling object followed by the character argument c
	*/
	CMPT135_String ans(*this);
	ans.append(c);
	return ans;
}
//17.
CMPT135_String CMPT135_String::operator + (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function returns a CMPT135_String object constructed from all the characters of the
	calling object followed by the characters of the null terminated character array argument cStr
	*/
	CMPT135_String ans(*this);
	ans.append(cStr);
	return ans;
}
//18.
CMPT135_String& CMPT135_String::operator += (const CMPT135_String &s)
{
	/*
	This function appends the characters of s to the calling object and then
	returns the calling object
	*/
	this->append(s);
	return* this;
}
//19.
CMPT135_String& CMPT135_String::operator += (const char &c)
{
	/*
	This function appends the character c to the calling object and then
	returns the calling object
	*/
	this->append(c);
	return* this;
}
//20.
CMPT135_String& CMPT135_String::operator += (const char *cStr) //*cStr is a null terminated char array
{
	/*
	This function appends the characters of the null terminated character array cStr
	to the calling object and then returns the calling object
	*/
	this->append(cStr);
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
	return *this == temp;
}
//23.
bool CMPT135_String::operator != (const CMPT135_String &s) const
{
	/*
	This function tests if the calling object is not equal to the argument s
	*/
	if(*this == s)
		return false;
	else
		return true;
}
//24.
bool CMPT135_String::operator != (const char *cStr) const//*cStr is a null terminated char array
{
	/*
	This function tests if the calling object is not equal to the null terminated character array 
	cStr
	*/

	if(*this == cStr)
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

	
	//find the length of both the calling object and the argument; and loop around the smaller          //Step-1
	int length_calling_object = this->length();
	int length_argument = s.length();
	int length = length_calling_object < length_argument ? length_calling_object : length_argument;
	int index = -1;
	for(int i = 0; i < length; i++)
	{
		if(this->buffer[i] != s.buffer[i])
		{
			index = i;
			break;
		}
	}
	
	if(index >= 0 && index <= (length-1))                            //Step-2 
	{
		if(this->buffer[index] < s.buffer[index])
			return true;
		else
			return false;
	}
	else
	{
		if(length_calling_object < length_argument)					//Step-3
			return true;
		else														//here either the length_calling_object > length_argument or length_calling_object == length_argument
			return false;
	}

}
//26.
bool CMPT135_String::operator < (const char *cStr) const	//*cStr is a null terminated char array
{
	/*
	This function tests if the calling object is less than the null terminated character array cStr
	*/
	CMPT135_String temp(cStr);
	return *this < temp;
}
//27.
bool CMPT135_String::operator > (const CMPT135_String &s) const
{
	/*
	This function tests if the calling object is greater than the argument s
	*/
	//check for equality 
	if(*this == s)
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
	if(*this < s || *this == s)
		return true;
	return false;
}
//30.
bool CMPT135_String::operator <= (const char *cStr) const //*cStr is a null terminated char array
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

	if(*this > s || *this == s)
		return true;
	return false;
}
//32.
bool CMPT135_String::operator >= (const char *cStr) const //*cStr is a null terminated char array
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
	This function returns a CMPT135_String object constructed from the characters of the null
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

//Non-member functions 
//1. findCharIndex
/*
This function takes a CMPT135_String and a character arguments and returns the smallest valid
index of the CMPT135_String argument such that the character of the CMPT135_String argument at 
that index is equal to the character argument. If no such an index is found, then this function 
must return -1.
*/
int findCharIndex(const CMPT135_String& s, const char& c)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == c)
			return i;
	}
	return -1;
}

//2. reverseFindCharIndex
/*
This function takes a CMPT135_String and a character arguments and returns the largest valid
index of the CMPT135_String argument such that the character of the CMPT135_String argument at 
that index is equal to the character argument. If no such an index is found, then this function 
must return -1.
*/
int reverseFindCharIndex(const CMPT135_String& s, const char& c)
{
	for(int i = s.length()-1; i > -1; i--)
	{
		if(s[i] == c)
			return i;
	}
	return -1;
}


//3. countChar
/*
This function takes a CMPT135_String and a character arguments and returns the number of times the
character argument is found in the CMPT135_String argument.
*/
int countChar(const CMPT135_String& s, const char& c)
{
	int count = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == c)
			count++;
	}
	return count;
}


//4. getSubString
/*
This function takes a CMPT135_String, a start index, and a length arguments and returns a
CMPT135_String object with as many as length characters constructed from the characters of the
CMPT135_String argument starting from the given start index. If there are no enough characters
to copy as many as length characters from the CMPT135_String argument, then ONLY the available
characters up to the end of the CMPT135_String argument are copied and a CMPT135_String with a
shorter length is returned.
The returned object is known as a substring of the CMPT135_String argument.
*/
CMPT135_String getSubString(const CMPT135_String& s, const int& start_index, const int& length_of_string)
{
	CMPT135_String ans;
	int len = s.length() - start_index;  //if length_of_string is 5 then we want to choose 3
	int l = length_of_string < len ? length_of_string : len;
	for(int j = start_index, i = 0 ; i < l;  j++, i++)
		ans.append(s[j]);
	ans.append('\0');
	return ans;
}
	
//5. isSubString
/*
This function takes two CMPT135_String objects s1 and s2 as arguments and returns true if there
exists a substring of s2 that is equal to s1; otherwise it returns false.
*/

bool isSubString(const CMPT135_String& s1, const CMPT135_String& s2)
{
	//s2 is the bigger one and s1 is the substring 
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

//6. getReversedString
/*
This function takes a CMPT135_String argument and returns a CMPT135_String object constructed from
the characters of the CMPT135_String argument in reverse order.
*/

CMPT135_String getReversedString(const CMPT135_String& s)
{
	CMPT135_String temp = s;

	for(int i = (s.length()-1), j = 0; i >= 0; i--, j++)
	{
		temp[i] = s[j];
	}
	return temp;
}

//7. removeChar
/*
This function takes a CMPT135_String and a character arguments and removes each character of the
CMPT135_String argument that is equal to the character argument from the CMPT135_String argument.
*/
void removeChar(CMPT135_String& s,const char& c)
{
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
	s = temp;
	delete[] temp;
}



//8. replaceChar
/*
This function takes a CMPT135_String and two characters named ch1 and ch2 (in that order) as
arguments and replaces every character in the CMPT135_String argument that is equal to ch1 by
the character ch2.
*/
void replaceChar(CMPT135_String& s, const char& ch1, const char& ch2)
{
	char* temp = new char[s.length() + 1];
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ch1) temp[i] = ch2;
		else temp[i] = s[i];
	}
	temp[s.length()] = '\0';
	CMPT135_String r(temp);
	s = temp;
	delete[] temp;
	
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
	removeChar(s1, ch);
	cout << "\"" << s1 << "\"" << endl;
	s3 = "11111111111";
	cout << "After removing all the '" << ch << "' characters from \"" << s3 << "\", we get ";
	removeChar(s3, ch);
	cout << "\"" << s3 << "\"" << endl;

	//Test replaceChar non-member function
	cout << "After replacing 1 by 5 from \"" << s2 << "\", we get ";
	replaceChar(s2, '1', '5');
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

//Sample Run Output
//The length of "Yonas" is 5
//	The length of "" is 0
//	The length of nullptr is 0
//	s1 is "" and its length is 0
//	s2 is "Y" and its length is 1
//	s3 is "CMPT 135" and its length is 8
//	s4 is "CMPT 135" and its length is 8
//	s4 is "" and its length is 0
//	s4 is "Y" and its length is 1
//	s4 is "A" and its length is 1
//	s4 is "This is cool" and its length is 12
//	s4[2] is i
//	s4[2] is a
//	s4 is "That is cool" and its length is 12
//	s1 is "That is cool" and its length is 12
//	s3 is "CMPT 135 " and its length is 9
//	s3 is "CMPT 135 201901" and its length is 15
//	The first index of '1' in "CMPT 135 201901" is 5
//	The first index of 'm' in "CMPT 135 201901" is -1
//	The last index of '1' in "CMPT 135 201901" is 14
//	The last index of 'm' in "CMPT 135 201901" is -1
//	'1' appears 0 times in "That is cool"
//	s1 is "019" and its length is 3
//	s1 is "01901" and its length is 5
//	s1 is "01901" and its length is 5
//	"01901" is a substring of "CMPT 135 201901"
//	"01901" is not a substring of "01902029010190"
//	"01901" is a substring of "01902019010190"
//	s1 is "01901" and its length is 5
//	The reverse of "01901" is "10910"
//	After removing all the '1' characters from "01901", we get "090"
//	After removing all the '1' characters from "11111111111", we get ""
//	After replacing 1 by 5 from "01902029010190", we get 05902029050590
//	s1 is "090", s3 is "" and s1 + s3 is "090"
//	s1 is "090 and s1 + "yonas" is "090yonas
//	s1 is "090 and s1 + 'Y' is "090Y
//	s1 is "090", s2 is "Test", and s3 is ""
//	After s3 = s1 += s2, we get s1 is 090Test, s2 is Test, and s3 is 090Test
//	s2 is "Test". After s2 += "FIC", we get "TestFIC"
//	s2 is "TestFIC". After s2 += '!', we get "TestFIC!"
//	s1 is "Test1", s2 is "" and s1 == s2 is 0
//	s1 is "Test1", s2 is "" and s1 != s2 is 1
//	s1 is "Test1", s2 is "" and s1 > s2 is 1
//	s1 is "Test1", s2 is "" and s1 < s2 is 0
//	s1 is "Test1", s2 is "" and s1 >= s2 is 1
//	s1 is "Test1", s2 is "" and s1 <= s2 is 0
//	"Yonas" + "Test1" is "YonasTest1"
//	'y' + "Test1" is "yTest1"
//	s1 is "Test1" and "Test2" == s1 is 0
//	s1 is "Test1" and "Test2" != s1 is 1
//	s1 is "Test1" and "Test2" < s1 is 0
//	s1 is "Test1" and "Test2" > s1 is 1
//	s1 is "Test1" and "Test2" <= s1 is 0
//	s1 is "Test1" and "Test2" >= s1 is 1
//	Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): This is great !
//	You entered "This is great !"
//	Press any key to continue . . .
//
//