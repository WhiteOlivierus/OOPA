#pragma once

#include <string>
#include <ostream>
#include "Includes/Child.cpp"

class Parent
{
public:
    Parent(std::string name);
    Parent(const Parent &other);
    virtual ~Parent();
    Parent &operator=(const Parent &other);

    friend std::ostream &operator<<(std::ostream &os, const Parent &parent);

private:
    std::string name;
    Child *child;
};
