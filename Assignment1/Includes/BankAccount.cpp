#include "BankAccount.h"

BankAccount BankAccount::operator+(double const &value)
{
    return HandleTransaction(true, value);
}

BankAccount BankAccount::operator+=(double const &value)
{
    return HandleTransaction(true, value);
}

BankAccount BankAccount::operator-(double const &value)
{
    return HandleTransaction(false, value);
}

BankAccount BankAccount::operator-=(double const &value)
{
    return HandleTransaction(false, value);
}

BankAccount BankAccount::HandleTransaction(bool credit, const double &amount)
{
    bool positiveAmount = amount >= 0 ? true : false;
    bool positiveBalance = this->balance >= 0 ? true : false;

    bool creditedToBalance;

    if (credit)
    {
        this->balance += std::abs(amount);

        positiveBalance &!positiveAmount ? creditedToBalance = false : creditedToBalance = true;
    }
    else
    {
        this->balance -= std::abs(amount);

        positiveBalance &!positiveAmount ? creditedToBalance = true : creditedToBalance = false;
    }

    RegisterTransaction(creditedToBalance, std::abs(amount));

    return *this;
}

std::ostream &
operator<<(std::ostream &stream, const BankAccount &account)
{
    stream << "Current ballance is " << std::setprecision(2) << std::fixed << account.balance << " euro." << std::endl;

    stream << std::endl;

    stream << "Transaction history:" << std::endl;

    for (auto &&transaction : account.transactionHistory)
    {
        stream << *transaction << std::endl;
    }

    return stream;
}

bool BankAccount::RegisterTransaction(bool credited, double amount)
{
    Transaction *transaction = new Transaction(credited, amount);
    transactionHistory.push_back(transaction);
    return true;
}