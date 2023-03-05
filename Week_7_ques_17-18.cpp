#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Vehicle
{
	string make;
	int year;
	double hp; //horse power of the vehicle
};

 vector<Vehicle> readVehicleInventory(const string& s)
 {
	 vector<Vehicle> v;
	 Vehicle temp;
	 ifstream fin(s);
	 if(fin.fail())
	 {
		 cout << "Input file not found." << endl;
		 abort();
	 }
	 else
	 {
		 //read vehicle inventory to 
		 while(fin >> temp.make >> temp.year >> temp.hp)
		 {
			 v.push_back(temp);
		 }

	 }
	 fin.close();
	 return v;
 }

 bool is_found(const vector <Vehicle>& v, const Vehicle& veh)
 {
	 if(v.size() == 0)
		 return false;
	 for(int i = 0; i < v.size(); i++)
	 {
		 if(v[i].make == veh.make && v[i].hp == veh.hp && v[i].year == veh.year)
			 return true;
	 }
	 return false;
 }

void reOrderObjects(vector<Vehicle>& v)
 {
	//vector<Vehicle> in = readVehicleInventory("inventory.txt");
	vector<Vehicle> ans;
	Vehicle temp;
	for(int i = 0; i < v.size(); i++)
	{
		if(is_found(ans,v[i]))
		{
			i++;
		}
		else
		{
			temp = v[i];
			for(int j = 0; j < v.size(); j++)
			{
				if(v[j].make == temp.make)
					ans.push_back(v[j]);
			}
		}
	}
	v = ans;
 }

//18. Write a function named mostPowerful that takes a vector of Vehicle structs and a string
//representing the make of a vehicle arguments and that returns the element of the vector with the highest 
//power among all elements of the same make as the string argument. Assume the vector contains at least 
//one element with the same make as the string argument
Vehicle mostPowerful(const vector<Vehicle>& v, const string& s)
{
	vector<Vehicle> ans;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].make == s)
			ans.push_back(v[i]);
	}
	double max_hp = ans[0].hp;
	int index = 0;
	for(int i = 1; i < ans.size(); i++)
	{
		double max_check = ans[i].hp;
		if(max_hp < max_check)
		{
			max_hp = max_check;
			index = i;
		}
	}

	return ans[index];
}

 int main()
 {
	 vector<Vehicle> inventory = readVehicleInventory("inventory.txt");

	 //print the inventory 
	 for(int i = 0; i < inventory.size(); i++)
	 {
		 cout << inventory[i].make << "\t\t" << inventory[i].year << "\t\t" << inventory[i].hp << endl;
	 }
	 cout << endl;
	 cout << endl;

	 //reorder the elements of inventory 
	 reOrderObjects(inventory);
	 cout << "//reorder the elements of inventory " << endl;
	 for(int i = 0; i < inventory.size(); i++)
	 {
		 cout << inventory[i].make << "\t\t" << inventory[i].year << "\t\t" << inventory[i].hp << endl;
	 }

	 //return the most powerful element from Jeep
	 cout << "//return the most powerful element from Jeep" << endl;
	 Vehicle most_powerful = mostPowerful(inventory, "Jeep");
	 cout << "The most powerful jeep is " << most_powerful.make << "\t\t" << most_powerful.year << "\t\t" << most_powerful.hp << endl;
	 system("Pause");
	 return 0;
 }
