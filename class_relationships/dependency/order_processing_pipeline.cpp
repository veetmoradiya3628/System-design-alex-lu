#include <iostream>
#include <string>
using namespace std;

class InventoryChecker
{
public:
    bool checkStock(const string &itemName, int quantity)
    {
        cout << "Checking stock for " << itemName << " (x" << quantity << ")" << endl;
        cout << "Stock available: true" << endl;
        return true;
    }
};

class PriceCalculator
{
public:
    double calculate(const string &itemName, int quantity)
    {
        double unitPrice = 1249.99;
        double total = unitPrice * quantity;
        printf("Calculating price: %s x %d = $%.2f\n", itemName.c_str(), quantity, total);
        return total;
    }
};

class InvoiceGenerator
{
public:
    string generate(const string &itemName, int quantity, double total)
    {
        cout << "Generating invoice..." << endl;
        char buffer[256];
        snprintf(buffer, sizeof(buffer),
                 "--- INVOICE ---\nItem: %s\nQuantity: %d\nTotal: $%.2f\n--- END ---",
                 itemName.c_str(), quantity, total);
        return string(buffer);
    }
};

class OrderProcessor
{
public:
    string processOrder(const string &itemName, int quantity,
                        InventoryChecker &checker, PriceCalculator &calculator,
                        InvoiceGenerator &generator)
    {
        bool inStock = checker.checkStock(itemName, quantity);
        if (!inStock)
        {
            return "Order rejected: " + itemName + " is out of stock.";
        }
        double total = calculator.calculate(itemName, quantity);
        return generator.generate(itemName, quantity, total);
    }
};

int main()
{
    OrderProcessor processor;

    InventoryChecker checker;
    PriceCalculator calculator;
    InvoiceGenerator generator;

    string invoice = processor.processOrder("Laptop", 2,
                                            checker, calculator, generator);
    cout << invoice << endl;

    return 0;
}