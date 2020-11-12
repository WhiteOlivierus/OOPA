#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>

class Transaction
{
private:
    bool wasCredited;
    double amountCredited;
    time_t dateTime;

    std::string GetDate() const;

public:
    Transaction(bool credited, double amount);
    ~Transaction();

    friend std::ostream &operator<<(std::ostream &stream, const Transaction &transaction);
};

Transaction::Transaction(bool credited, double amount)
{
    wasCredited = credited;
    amountCredited = amount;
    dateTime = time(0);
}

Transaction::~Transaction() {}
