#include "Includes/Person.h"

Person::Person() {}
Person::~Person() {}

std::ostream &operator<<(std::ostream &outStream, const Person &person)
{
    outStream << person.GetFullName();

    return outStream;
}

std::string Person::GetFullName() const
{
    return Firstname + " " + Lastname;
}