#include "Includes/Person.h"

#pragma once

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

bool Person::operator==(const Person &other) const
{
    return other.Firstname == this->Firstname && other.Lastname == this->Lastname && other.Age == this->Age;
}