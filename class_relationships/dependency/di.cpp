#include <bits/stdc++.h>
using namespace std;
class Sender
{
public:
    virtual void send(const string &message) = 0;
    virtual ~Sender() = default;
};

class EmailSender : public Sender
{
public:
    void send(const string &message) override
    {
        cout << "Email: " << message << endl;
    }
};

class SmsSender : public Sender
{
public:
    void send(const string &message) override
    {
        cout << "SMS: " << message << endl;
    }
};

class NotificationService
{
private:
    Sender *sender;

public:
    NotificationService(Sender *sender) : sender(sender) {} // Injected

    void notifyUser(const string &message)
    {
        sender->send(message);
    }
};
int main()
{
    return 0;
}