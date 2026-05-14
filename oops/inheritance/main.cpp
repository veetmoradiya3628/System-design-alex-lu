#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(const string &make, const string &model, int year)
        : make(make), model(model), year(year) {}

    void startEngine()
    {
        cout << "Engine started" << endl;
    }

    void stopEngine()
    {
        cout << "Engine stopped" << endl;
    }

    void displayInfo()
    {
        cout << year << " " << make << " " << model << endl;
    }
};

class ElectricCar : public Vehicle
{
private:
    int batteryCapacity;

public:
    ElectricCar(const string &make, const string &model,
                int year, int batteryCapacity)
        : Vehicle(make, model, year), batteryCapacity(batteryCapacity) {}

    void chargeBattery()
    {
        cout << "Charging " << batteryCapacity << "kWh battery" << endl;
    }
};

class GasCar : public Vehicle
{
private:
    double fuelTankSize;

public:
    GasCar(const string &make, const string &model,
           int year, double fuelTankSize)
        : Vehicle(make, model, year), fuelTankSize(fuelTankSize) {}

    void fillTank()
    {
        cout << "Filling " << fuelTankSize << "L fuel tank" << endl;
    }
};

int main()
{

    return 0;
}