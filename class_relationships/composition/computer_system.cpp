#include <iostream>
#include <string>
using namespace std;

class CPU
{
private:
    string model;
    int cores;

public:
    CPU(const string &model, int cores) : model(model), cores(cores) {}

    void describe() const
    {
        cout << "  CPU: " << model << " (" << cores << " cores)" << endl;
    }
};

class RAM
{
private:
    int sizeGB;

public:
    RAM(int sizeGB) : sizeGB(sizeGB) {}

    void describe() const
    {
        cout << "  RAM: " << sizeGB << " GB" << endl;
    }

    int getSizeGB() const { return sizeGB; }
};

class HardDrive
{
private:
    int capacityGB;

public:
    HardDrive(int capacityGB) : capacityGB(capacityGB) {}

    void describe() const
    {
        cout << "  Storage: " << capacityGB << " GB" << endl;
    }
};

class Computer
{
private:
    string name;
    CPU cpu;
    RAM ram;
    HardDrive hardDrive;

public:
    Computer(const string &name, const string &cpuModel, int cpuCores,
             int ramGB, int storageGB)
        : name(name),
          cpu(cpuModel, cpuCores),
          ram(ramGB),
          hardDrive(storageGB) {}

    void describeSpecs() const
    {
        cout << "Computer: " << name << endl;
        cpu.describe();
        ram.describe();
        hardDrive.describe();
    }

    void upgradeRAM(int newSizeGB)
    {
        ram = RAM(newSizeGB);
    }
};

int main()
{
    Computer pc("Dev Workstation", "Intel i7-13700K", 16, 32, 1000);

    pc.describeSpecs();

    pc.upgradeRAM(64);
    cout << "\nAfter RAM upgrade:" << endl;
    pc.describeSpecs();

    return 0;
}