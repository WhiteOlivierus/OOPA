#include <iostream>
#include "Includes/BankAccount.cpp"

int main(int, char **)
{
    BankAccount account(10.00);

    //Testing all values with positive balance
    account += 5;          //added
    account = account + 5; //added

    account = account - 5; //removed
    account -= 5;          //removed

    account += 5.50;          //added
    account = account + 5.50; //added

    account = account - 5.50; //removed
    account -= 5.50;          //removed

    account += -5;          //removed
    account = account + -5; //removed

    account = account - -5; //added
    account -= -5;          //added

    account += -5.50;          //removed
    account = account + -5.50; //removde

    account = account - -5.50; //added
    account -= -5.50;          //added

    std::cout << account << std::endl;
}
