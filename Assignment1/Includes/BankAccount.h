#include "Transaction.cpp"

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

class BankAccount
{
private:
    double balance = 0;
    std::vector<Transaction *> transactionHistory;

    bool RegisterTransaction(bool credited, double amount);
    BankAccount HandleTransaction(bool add, const double &value);

public:
    BankAccount();
    BankAccount(double);

    ~BankAccount();

    BankAccount operator+(double const &value);
    BankAccount operator-(double const &value);

    BankAccount operator+=(double const &value);
    BankAccount operator-=(double const &value);

    friend std::ostream &operator<<(std::ostream &stream, const BankAccount &account);
};

BankAccount::BankAccount() {}

BankAccount::BankAccount(double startBalance)
{
    balance = startBalance;
}

BankAccount::~BankAccount() {}
