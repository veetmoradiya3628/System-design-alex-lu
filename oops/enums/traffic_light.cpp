#include <iostream>
#include <string>

using namespace std;

enum class TrafficLight
{
    RED,
    YELLOW,
    GREEN
};

int getDuration(TrafficLight light)
{
    // Return duration: RED=30, YELLOW=5, GREEN=25
    switch (light)
    {
    case TrafficLight::RED:
        return 30;
    case TrafficLight::YELLOW:
        return 5;
    case TrafficLight::GREEN:
        return 25;
    default:
        break;
    }
    return 0;
}

string getColor(TrafficLight light){
    switch (light)
    {
    case TrafficLight::RED:
        return "RED";
    case TrafficLight::YELLOW:
        return "YELLOW";
    case TrafficLight::GREEN:
        return "GREEN";
    default:
        break;
    }
    return "UNKNOWN";
}

TrafficLight next(TrafficLight light)
{
    // Return next light: RED->GREEN, GREEN->YELLOW, YELLOW->RED
    switch (light)
    {
    case TrafficLight::RED:
        return TrafficLight::GREEN;
    case TrafficLight::GREEN:
        return TrafficLight::YELLOW;
    case TrafficLight::YELLOW:
        return TrafficLight::RED;
    default:
        break;
    }
    return light;
}

void display(TrafficLight light)
{
    // Print: "COLOR (Xs)" e.g. "RED (30s)"
    cout << getColor(light) << " (" << getDuration(light) << "s)" << endl;
}

int main()
{
    TrafficLight light = TrafficLight::RED;
    for (int i = 0; i < 6; i++)
    {
        display(light);
        light = next(light);
    }
    return 0;
}