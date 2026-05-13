#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace std;

class TemperatureSensor
{
private:
    vector<double> readings;

public:
    void addReading(double value)
    {
        // Only add if value is between -50 and 150 (inclusive)
        if (value >= -50 && value <= 150)
        {
            readings.push_back(value);
        }
    }

    double getAverage() const
    {
        // Return the average of all readings, or 0.0 if no readings exist
        if (readings.empty())
            return 0.0;
        double sum = 0;
        for (auto reading : readings)
            sum += reading;
        double avg = sum / (double)readings.size();
        return round(avg * 100.0) / 100.0;
    }

    int getReadingCount() const
    {
        // Return how many readings have been recorded
        return readings.size();
    }

    vector<double> getReadings() const
    {
        // Return a copy of the readings vector (not the original)
        vector<double> copy(readings);
        return copy;
    }
};

int main()
{
    TemperatureSensor sensor;
    sensor.addReading(22.5);
    sensor.addReading(23.1);
    sensor.addReading(200.0); // Should be rejected
    sensor.addReading(-10.0);

    cout << "Count: " << sensor.getReadingCount() << endl; // 3
    cout << "Average: " << sensor.getAverage() << endl;    // 11.87
    return 0;
}