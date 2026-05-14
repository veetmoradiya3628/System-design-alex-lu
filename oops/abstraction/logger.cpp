#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Logger
{
protected:
    string level;

    string formatMessage(const string &message)
    {
        time_t now = time(nullptr);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
        return "[" + string(timestamp) + "] [" + level + "] " + message;
    }

public:
    Logger(const string &level) : level(level) {}
    virtual ~Logger() {}

    // Abstract method: subclasses decide HOW to deliver the message
    virtual void log(const string &message) = 0;
};

class ConsoleLogger : public Logger
{
public:
    ConsoleLogger(const string &level) : Logger(level) {}

    void log(const string &message) override
    {
        cout << formatMessage(message) << endl;
    }
};

class FileLogger : public Logger
{
private:
    string filePath;

public:
    FileLogger(const string &level, const string &filePath)
        : Logger(level), filePath(filePath) {}

    void log(const string &message) override
    {
        cout << "Writing to " << filePath << ": "
             << formatMessage(message) << endl;
    }
};

int main()
{

    return 0;
}