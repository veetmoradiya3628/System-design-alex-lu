#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double getArea() const override
    {
        return width * height;
    }
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double side) : side(side) {}

    double getArea() const override
    {
        return side * side;
    }
};

int main()
{
    Rectangle rectangle(5, 10);
    Square square(5);

    cout << "Rectangle area: " << static_cast<int>(rectangle.getArea()) << endl;
    cout << "Square area: " << static_cast<int>(square.getArea()) << endl;

    return 0;
}