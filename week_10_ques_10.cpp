#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Vehicle
{
protected:
    string make;
    string color;
    int year;
    double fuelTankVolume;

public:
    Vehicle(string make, string color, int year, double fuelTankVolume): make(make), color(color), year(year), fuelTankVolume(fuelTankVolume)
    {
    }

    virtual void drive() = 0;
};

class Sedan : public Vehicle
{
private:
    int numPassengers;
    double engineSize;

public:
    Sedan(string make, string color, int year, double fuelTankVolume, int numPassengers, double engineSize): Vehicle(make, color, year, fuelTankVolume), numPassengers(numPassengers), engineSize(engineSize)
    {
    }

    void drive() 
    {
        cout << "Driving sedan" << endl;
    }
};

class Truck : public Vehicle
{
protected:
    double loadingCapacity;
    double range;

public:
    Truck(string make, string color, int year, double fuelTankVolume, double loadingCapacity, double range): Vehicle(make, color, year, fuelTankVolume), loadingCapacity(loadingCapacity), range(range)
    {
    }

    void drive() 
    {
        cout << "Driving truck" << endl;
    }
};

class Bus : public Vehicle
{
private:
    int capacity;
    bool wheelchairAccessibility;
    int numFloors;

public:
    Bus(string make, string color, int year, double fuelTankVolume, int capacity, bool wheelchairAccessibility, int numFloors): Vehicle(make, color, year, fuelTankVolume), capacity(capacity), wheelchairAccessibility(wheelchairAccessibility), numFloors(numFloors)
    {
    }

    void drive() 
    {
        cout << "Driving bus" << endl;
    }
};

class Trailer : public Truck
{
private:
    int numWheels;

public:
    Trailer(string make, string color, int year, double fuelTankVolume, double loadingCapacity, double range, int numWheels): Truck(make, color, year, fuelTankVolume, loadingCapacity, range), numWheels(numWheels)
    {
    }

    void drive() 
    {
        cout << "Driving truck with trailer" << endl;
    }
};

int main()
{
    Sedan mySedan("Honda", "blue", 2022, 10.0, 4, 2.0);
    mySedan.drive();

    Truck myTruck("Ford", "red", 2022, 30.0, 1000.0, 500.0);
    myTruck.drive();

    Bus myBus("Mercedes", "green", 2022, 50.0, 50, true, 2);
    myBus.drive();

    Trailer myTrailer("Volvo", "yellow", 2022, 40.0, 2000.0, 400.0, 8);
    myTrailer.drive();

	system("Pause");
    return 0;
}



