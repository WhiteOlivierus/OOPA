#include <iostream>
#include "Includes/Parent.h"

Parent::Parent(std::string name)
{
    this->name = name;
    std::string childName = "ChildOf" + name;
    this->child = std::make_unique<Child>(childName);
}

Parent::Parent(const Parent &other)
{
    std::cout << "Parent cctor" << std::endl;
    this->name = other.name;
    this->child = std::make_unique<Child>(*other.child);
}

Parent::~Parent()
{
    std::cout << "Parent dtor : " << this->name << std::endl;
}

Parent &Parent::operator=(const Parent &other)
{
    std::cout << "Parent assignment" << std::endl;

    if (this == &other)
        return *this;

    this->name = other.name;
    this->child = std::make_unique<Child>(*other.child);

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Parent &parent)
{
    os << "parent name: " << parent.name << "," << *parent.child;
    return os;
}

Child *Parent::GetChild()
{
    return this->child.get();
}

void Parent::DeleteChild()
{
    this->child.reset();
}

// move-constructor
Parent::Parent(Parent &&other) noexcept
{
    std::cout << "MCTOR from Block '" << other.name << "' @" << &other << " to Block @" << this << std::endl;
}

//TODO: move-assignment operator
Parent Parent::operator=(Parent &&parent)
{
    return *this;
}