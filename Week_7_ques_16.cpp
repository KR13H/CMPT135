#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

 int main()
 {
	 vector<Vehicle> inventory = readVehicleInventory("inventory.txt");

	 //print the inventory 
	 for(int i = 0; i < inventory.size(); i++)
	 {
		 cout << inventory[i].make << "\t\t" << inventory[i].year << "\t\t" << inventory[i].hp << endl;
	 }

	 system("Pause");
	 return 0;
 }
