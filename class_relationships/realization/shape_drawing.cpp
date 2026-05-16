#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;

class Drawable {
public:
    virtual void draw() = 0;
    virtual double getArea() = 0;
    virtual ~Drawable() = default;
};

class Circle : public Drawable {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    void draw() override {
        printf("Drawing circle with radius %.1f\n", radius);
    }

    double getArea() override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Drawable {
private:
    double width, height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    void draw() override {
        printf("Drawing rectangle %.1fx%.1f\n", width, height);
    }

    double getArea() override {
        return width * height;
    }
};

class Triangle : public Drawable {
private:
    double base, height;
public:
    Triangle(double base, double height) : base(base), height(height) {}

    void draw() override {
        printf("Drawing triangle with base %.1f and height %.1f\n", base, height);
    }

    double getArea() override {
        return 0.5 * base * height;
    }
};

class Canvas {
public:
    void drawAll(vector<unique_ptr<Drawable>>& shapes) {
        for (auto& shape : shapes) {
            shape->draw();
            printf("  Area: %.2f\n\n", shape->getArea());
        }
    }
};

int main() {
    Canvas canvas;

    vector<unique_ptr<Drawable>> shapes;
    shapes.push_back(make_unique<Circle>(5.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(make_unique<Triangle>(3.0, 8.0));

    canvas.drawAll(shapes);

    return 0;
}