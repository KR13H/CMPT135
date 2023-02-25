#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)
	cout << v[i] << " ";
	cout << endl;
} 

int max_running_length(const vector<int>& v, const int& e)
{
	int current_count = 0;
	int max_count = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == e)
			current_count++;
		else
			current_count = 0;

		if(current_count > max_count)
			max_count = current_count;
	}

	return max_count;
}

//find the number that has the longest running length 
int num_with_max_running_length(const vector<int>& v)
{
	int max_len = max_running_length(v,0);
	int running_length = max_running_length(v,1);
	int ans = 0;
	for(int i = 2; i <= 9; i++)
	{
		running_length = max_running_length(v,i);
		if(max_len < running_length)
		{
			max_len = running_length;
			ans = i;
		}
	}
	return ans;
}



int main()
{
	vector<int> v;
	v.push_back(5);v.push_back(2);v.push_back(2);v.push_back(3);v.push_back(5);v.push_back(2);v.push_back(5);v.push_back(5);v.push_back(1);v.push_back(5);v.push_back(5);v.push_back(5);v.push_back(5);v.push_back(5);v.push_back(5); 
	print_vector(v);
	cout << "Finding the longest running length of 5 in the vector v"<< endl;

	int j = 0;
	vector<int> count;
	while(j < v.size())
	{
		int c = 1;
		for(; j < v.size() - 1; j++)
		{
			if(v[j] == 5 && v[j] == v[j+1]) 
				c++;
			else
			{ 
				count.push_back(c);
				break;
			}
		}
		count.push_back(c);
		j++;
	}

	sort(count.begin(), count.end());
	//print_vector(count);

	cout << "//The longest running length of 5's is " << count[count.size()-1] << endl;

	cout << "Finding the running length of 5's using the new function " << max_running_length(v,5) << endl;
	cout << "Finding the running length of 2's using the new function " << max_running_length(v,2) << endl;
	cout << "Finding the running length of 3's using the new function " << max_running_length(v,3) << endl;
	cout << "Finding the running length of 7's using the new function " << max_running_length(v,7) << endl;


	cout << "//Finding the number that has the longest running length" << endl;
	cout << "The number with the longest running length is " << num_with_max_running_length(v) << endl;

	system("Pause");
	return 0;
}

	
