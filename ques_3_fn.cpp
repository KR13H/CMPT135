#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//3. Write a function named pop_front that takes a vector of type int and removes the first element in the
//vector.
void pop_front(vector<int>& v)
{
	v.erase(v.begin());
}
void print_vector(const vector<int>& v)
{
	if(v.size() == 0)
	{
		cout << "[]" << endl;
		return;
	}
	
	cout << "[";
	for(int i = 0; i < v.size() -1; i++)
		cout << v[i] << ", ";
	cout << v[v.size()-1] << "]" << endl;
}

//4. Write a binary operator function + that adds two vectors of double data type. Your operator should not
//modify the operands and it must return a new vector of double data type that contains the elements of
//the left hand side operand followed by the elements of the right hand side operand.
vector<int> operator+(const vector<int>& lhs, const vector<int>& rhs)
{
	vector<int> ans;
	for(int i = 0; i < lhs.size(); i++)
		ans.push_back(lhs[i]);
	for(int i = 0; i < rhs.size(); i++)
		ans.push_back(rhs[i]);
	return ans;
}
void print_vector(const vector<double>& v)
{
	if(v.size() == 0)
	{
		cout << "[]" << endl;
		return;
	}
	
	cout << "[";
	for(int i = 0; i < v.size() -1; i++)
		cout << v[i] << ", ";
	cout << v[v.size()-1] << "]" << endl;
}

//5. Write a binary operator function * that multiplies a vector of int data type left hand side operand with an
//integer right hand side operand. Define multiplication as duplicating the vector as many as the integer
//value times. For example, given the vector a = [1, 2, 3], then a*5 should give [1,2,3,1,2,3,1,2,3,1,2,3,1,2,3].
//Your function should not modify its operands but rather return a new vector result.
//Think
// What should a*0 return?
// What should an empty vector * some integer value return?
// What will happen if the right hand side operand is negative integer?
vector<int> operator*(const vector<int>& v, const int& a)
{
	int a_new = abs(a);
	if(a_new == 0 || a_new == 1 || v.size() == 0)
		return v;
	else
	{
		vector<int> ans;
		for(int i = 0; i < a; i++)
			ans = operator+(ans, v);
		return ans;
	}
}

//6. Write a function named swap that takes two vectors of char data type as arguments and that swaps the
//arguments.
void swap(vector<char>& v1, vector<char>& v2)
{
	vector<char> temp;
	//copy v1 to temp
	for(int i = 0; i < v1.size(); i++)
		temp.push_back(v1[i]);
	v1 = v2;
	v2 = temp;
}
void print_vector(vector<char> v)
{
	if(v.size() == 0)
	{
		cout << "[]" << endl;
		return;
	}
	
	cout << "[";
	for(int i = 0; i < v.size() -1; i++)
		cout << v[i] << ", ";
	cout << v[v.size()-1] << "]" << endl;
}

//7. Write a binary operator function - that will subtract the right hand side vector from the left hand side
//vector. Assume int data type vectors. Your operator should not modify the operands and it must return a
//new vector that contains the elements of the left hand side operand but are not found on the right hand
//side operand

vector<int> operator-(const vector<int>& lhs, const vector<int>& rhs)
{
    vector<int> ans;
    bool found;

    for (int i = 0; i < lhs.size(); ++i) 
	{
        found = false;
        for (int j = 0; j < rhs.size(); ++j) 
		{
            if (lhs[i] == rhs[j])
			{
                found = true;
                break;
            }
        }
        if (found == false) 
		{
            ans.push_back(lhs[i]);
        }
    }

    return ans;
}

//8. Write a function named isDistinct that takes a vector of int data type and returns true if the vector
//contains distinct elements; otherwise returns false. Note that the elements of a vector are said to be
//distinct if each element of the array is different from every other element
bool is_found(vector<int>& v, const int& n)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == n)
			return true;
	}
	return false;
}
bool isDistinct(const vector<int>& v)
{
	int i = 0;
	while(i < v.size())
	{
		for(int j = i + 1; j < v.size(); j++)
		{
			if(v[i] == v[j])
				return false;
		}
		i++;
	}
	return true;
}

//9. Write a function named distinctElements that takes a vector of int data type and returns a new vector
//containing the distinct elements of the argument. Your function should not modify the argument. For
//example if the vector argument contains the elements [2, 4, 2, 6, 3, 6] then your function must return a
//new vector containing [2, 4, 6, 3].

//vector<int> distinctElements(const vector<int>& v)
//{
//	vector<int> ans;
//
//	for(int i = 0, j = i + 1; j < v.size() ;j++, i++)
//	{
//		ans.push_back(v[i++]);
//		ans.push_back(v[j]);
//		if(isDistinct(ans) == false)
//			ans.pop_back();
//		
//	}
//	return ans;
//}
vector<int> distinctElements(const vector<int>& v)
{
	vector<int> ans;
	vector<int> sorted_v = v;
	sort(sorted_v.begin(), sorted_v.end());
	for(int i = 0; i < sorted_v.size(); i++)
	{
		if(i == 0 || sorted_v[i] != sorted_v[i-1])
			ans.push_back(sorted_v[i]);
	}
	return ans;
}

//10.Write a function named removeDuplicates that takes a vector of int data type and modifies the
//argument so that only the distinct elements of the vector are kept while any duplicate is removed. For
//example if the vector argument contains the elements [2, 4, 2, 6, 3, 6] then your function must modify the
//argument vector so that it will have only the elements [2. 4, 6, 3].
void removeDuplicates(vector<int>& v)
{
	v = distinctElements(v);
	return;
}

//11.Write a C++ program that declares a default vector of int, pushes back five random integers in the range
//[0, 5] onto the vector, and then duplicates each element of the vector as many times as the value of the
//element itself. For example if the vector is initially [2, 1, 4, 0, 5] then at the end the element 2 should be
//duplicated twice, 1 should be duplicated once, 4 should be duplicated 4 times, 0 should be duplicated 0
//times and 5 should be duplicated 5 times; which means we should get the vector [2, 2, 1, 4, 4, 4, 4, 5, 5, 5,
//5, 5] at the end
void duplicate_the_array(vector<int>& v)
{
	vector<int> ans;
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v[i]; j++)
			ans.push_back(v[i]);
	}
	v = ans;
}



int main()
{
	vector<int> v;
	for(int i = 0; i < 5; i++)
		v.push_back(i* 2);
	cout << "v: " << endl;
	print_vector(v);
	//delete the first element in the vector using pop_front
	pop_front(v);
	cout << "v after using pop_front()" << endl;
	print_vector(v); cout << endl;

	//checking operator+
	cout << "//checking operator+" << endl;
	vector<int> d1, d2, ans;
	for(int i = 0; i < 5; i++)
		d1.push_back(i* 2);
	for(int i = 0; i < 5; i++)
		d2.push_back(i* 2);
	cout << "d1: " << endl;
	print_vector(d1);
	cout << endl;
	cout << "d2: " << endl;
	print_vector(d2);
	cout << endl;
	ans = operator+(d1,d2);
	cout << "ans: " << endl;
	print_vector(ans);

	//checking operator*
	cout << "//checking operator*" << endl;
	vector<int> m = operator*(d1,4);
	cout << "m: " << endl;
	print_vector(m);

	//testing swap
	cout << "//Testing swap" << endl;
	vector<char> c1, c2;
	for(int i = 0; i < 5; i++)
	{
		c1.push_back(97 + i);
		c2.push_back(107 + i);
	}
	cout << "c1: " << endl;
	print_vector(c1);
	cout << "c2: " << endl;
	print_vector(c2);
	swap(c1, c2);
	cout << "After swaping: " <<endl;
	cout << "c1: " << endl;
	print_vector(c1);
	cout << "c2: " << endl;
	print_vector(c2);


	//checking operator-
	vector<int> vv1;
	vv1.push_back(1);vv1.push_back(2);vv1.push_back(3);vv1.push_back(4);vv1.push_back(5);
    vector<int> vv2;
	vv2.push_back(3);vv2.push_back(4); 
    vector<int> vv3;
	vv3.push_back(6);vv3.push_back(7);vv3.push_back(8);
    vector<int> vv4;
	vv4.push_back(1);vv4.push_back(2);vv4.push_back(3);vv4.push_back(3);vv4.push_back(4);

    std::vector<int> result1 = vv1 - vv2;
    std::vector<int> result2 = vv1 - vv3;
    std::vector<int> result3 = vv1 - vv4;

    cout << "vv1 - vv2 = ";
	print_vector(result1);
    cout << endl;

    cout << "vv1 - vv3 = ";
    print_vector(result2);
    cout << endl;

    cout << "vv1 - vv4 = ";
    print_vector(result3);
    cout << endl;


	//checking isDistinct
	cout << "//checking isDistinct" << endl;
	vector<int> v1;
    v1.push_back(1);v1.push_back(2);v1.push_back(3);v1.push_back(4);v1.push_back(5);
  
    vector<int> v2;
    v2.push_back(1);v2.push_back(2);v2.push_back(3);v2.push_back(4);v2.push_back(4);
  
    vector<int> v3;
    v3.push_back(1);v3.push_back(2);v3.push_back(3);v3.push_back(3);v3.push_back(3);
    
    cout << "v1 is distinct: " << isDistinct(v1) << endl; // true
    cout << "v2 is distinct: " << isDistinct(v2) << endl; // false
    cout << "v3 is distinct: " << isDistinct(v3) << endl; // false


	//checking distinctElements
	cout << "//checking distinctElements" << endl;
	vector<int> dv1;
	for(int i = 0; i < 5; i++)
		dv1.push_back(i);
	for(int i = 0; i < 5; i++)
		dv1.push_back(i);
	cout << "dv1: "; print_vector(dv1); cout << endl;
	vector<int> ansD = distinctElements(dv1);
	cout << "The distinct elements in dv1 are: "; print_vector(ansD); cout << endl;

	//checking removeDuplicates 
	cout << "// checking removeDuplicates" << endl;
	cout << "dv1: "; print_vector(dv1); cout << endl;
	removeDuplicates(dv1);
	cout << "After removing the duplicates dv1 is "; print_vector(dv1); cout << endl;


	//11.Write a C++ program that declares a default vector of int, pushes back five random integers in the range
	//[0, 5] onto the vector, and then duplicates each element of the vector as many times as the value of the
	//element itself. For example if the vector is initially [2, 1, 4, 0, 5] then at the end the element 2 should be
	//duplicated twice, 1 should be duplicated once, 4 should be duplicated 4 times, 0 should be duplicated 0
	//times and 5 should be duplicated 5 times; which means we should get the vector [2, 2, 1, 4, 4, 4, 4, 5, 5, 5,
	//5, 5] at the end
	//checking duplicate_the_array
	cout << "//checking duplicate_the_array" << endl;
	vector<int> eleven;
	for(int i = 0; i < 5; i++)
		eleven.push_back(rand()%6);
	cout << "The elements in eleven are "; print_vector(eleven); cout << endl;
	duplicate_the_array(eleven);
	cout << "After calling the function eleven: "; print_vector(eleven); cout << endl;
		

  

	system("Pause");
	return 0;
}