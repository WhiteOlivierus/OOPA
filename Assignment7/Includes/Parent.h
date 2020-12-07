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

    Child *GetChild();
    void DeleteChild();

private:
    std::string name;
    std::unique_ptr<Child> child;
};
