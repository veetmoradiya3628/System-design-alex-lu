#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class BankAccount
{
protected:
    string ownerName;
    string accountNumber;
    double balance;

public:
    BankAccount(const string &ownerName, const string &accountNumber,
                double balance)
    {
        // TODO: initialize this->ownerName, this->accountNumber, and this->balance
        this->ownerName = ownerName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    virtual ~BankAccount() {}

    bool deposit(double amount)
    {
        // TODO: add amount to balance if amount > 0, return true if successful
        if (amount > 0)
        {
            this->balance += amount;
            return true;
        }
        return false;
    }

    virtual bool withdraw(double amount)
    {
        // TODO: subtract amount from balance if balance >= amount, return true
        if (this->balance >= amount)
        {
            this->balance -= amount;
            return true;
        }
        return false;
    }

    void displayAccount()
    {
        // TODO: print "ownerName (accountNumber) | Balance: $balance"
        // Hint: use printf("$%.2f", balance) for formatting
        // Correct C-style printing
        printf("%s (%s) | Balance: $%.2f\n",
               this->ownerName.c_str(),
               this->accountNumber.c_str(),
               this->balance);
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(const string &ownerName, const string &accountNumber,
                   double balance, double interestRate)
        : BankAccount(ownerName, accountNumber, balance)
    {
        // TODO: initialize this->interestRate
        this->interestRate = interestRate;
    }

    bool withdraw(double amount) override
    {
        // TODO: only allow if (balance - amount) >= 100
        if (this->balance - amount >= 100)
        {
            this->balance -= amount;
            return true;
        }
        return false;
    }

    void applyInterest()
    {
        // TODO: add (balance * interestRate / 100) to balance
        this->balance += (this->balance * interestRate / 100);
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(const string &ownerName, const string &accountNumber,
                    double balance, double overdraftLimit)
        : BankAccount(ownerName, accountNumber, balance)
    {
        // TODO: initialize this->overdraftLimit
        this->overdraftLimit = overdraftLimit;
    }

    bool withdraw(double amount) override
    {
        // TODO: allow if (balance + overdraftLimit) >= amount
        if (balance + overdraftLimit >= amount)
        {
            this->balance -= amount;
            return true;
        }
        return false;
    }
};

int main()
{
    SavingsAccount savings("Alice", "SAV-001", 1000, 2.0);
    savings.displayAccount();
    cout << "Withdraw $950: " << (savings.withdraw(950) ? "true" : "false") << endl;
    savings.applyInterest();
    savings.displayAccount();

    cout << endl;

    CheckingAccount checking("Bob", "CHK-002", 500, 300);
    checking.displayAccount();
    cout << "Withdraw $700: " << (checking.withdraw(700) ? "true" : "false") << endl;
    checking.displayAccount();

    return 0;
}