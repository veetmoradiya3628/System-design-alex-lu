#include <iostream>
using namespace std;

class Car
{
private:
    // Attributes
    string brand;
    string model;
    int speed;

public:
    Car(const string &brand, const string &model)
        : brand(brand), model(model), speed(0) {}

    void accelerate(int increment)
    {
        speed += increment;
    }

    void displayStatus() const
    {
        cout << brand << " is running at " << speed << "km/h." << endl;
    }
};

int main()
{
    Car corolla("Toyota", "Corolla");
    Car mustang("Ford", "Mustang");

    corolla.accelerate(20);
    mustang.accelerate(40);

    corolla.displayStatus();
    cout << "-----------------" <<endl;
    mustang.displayStatus();
    return 0;
}