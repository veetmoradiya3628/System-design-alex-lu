#include <bits/stdc++.h>
using namespace std;
class Exportable
{
public:
    virtual ~Exportable() {}
    virtual string exportData() = 0;
};

class CSVExporter : public Exportable
{
public:
    string exportData() override
    {
        return "name,email,age\nAlice,alice@example.com,30";
    }
};

class JSONExporter : public Exportable
{
public:
    string exportData() override
    {
        return "{\"name\": \"Alice\", \"email\": \"alice@example.com\"}";
    }
};
int main()
{
    return 0;
}