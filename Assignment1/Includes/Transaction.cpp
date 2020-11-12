#include "Transaction.h"

std::ostream &operator<<(std::ostream &stream, const Transaction &transaction)
{
    std::string action = transaction.wasCredited ? "added." : "removed.";
    stream << "A transaction was made " << transaction.GetDate() << " and a amount of " << std::setprecision(2) << std::fixed << transaction.amountCredited << " euro was " << action;
    return stream;
}

std::string Transaction::GetDate() const
{
    struct tm buf;
    char str[26];
    errno_t t = localtime_s(&buf, &dateTime);
    asctime_s(str, sizeof str, &buf);
    std::string out = std::string(str);
    out.erase(std::remove(out.begin(), out.end(), '\n'), out.end());
    return out;
}