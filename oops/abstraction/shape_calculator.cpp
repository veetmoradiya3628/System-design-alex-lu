#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Shape
{
protected:
    string name;

public:
    Shape(const string &name) : name(name) {}
    virtual ~Shape() {}

    virtual double area() = 0;
    virtual double perimeter() = 0;

    void describe()
    {
        cout << fixed << setprecision(2);
        cout << "Shape: " << name
             << ", Area: " << area()
             << ", Perimeter: " << perimeter()
             << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;
    static constexpr double PI = 3.141592653589793;

public:
    Circle(double radius) : Shape("Circle"), radius(radius) {}

    double area() override
    {
        return PI * radius * radius;
    }

    double perimeter() override
    {
        return 2 * PI * radius;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double width, double height)
        : Shape("Rectangle"), width(width), height(height) {}

    double area() override
    {
        return width * height;
    }

    double perimeter() override
    {
        return 2 * (width + height);
    }
};

int main()
{
    Circle circle(5.0);
    circle.describe();

    Rectangle rectangle(4.0, 6.0);
    rectangle.describe();

    return 0;
}