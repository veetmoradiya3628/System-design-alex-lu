#include <iostream>
using namespace std;

class Bird
{
public:
    virtual void eat() = 0;
    virtual ~Bird() = default;
};

class FlyingBird : public Bird
{
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird
{
public:
    void eat() override
    {
        cout << "Sparrow is eating" << endl;
    }

    void fly() override
    {
        cout << "Sparrow is flying" << endl;
    }
};

class Penguin : public Bird
{
public:
    void eat() override
    {
        cout << "Penguin is eating" << endl;
    }
};

int main()
{
    Sparrow sparrow;
    sparrow.eat();
    sparrow.fly();

    Penguin penguin;
    penguin.eat();

    return 0;
}