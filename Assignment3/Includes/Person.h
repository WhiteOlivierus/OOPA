#include <iostream>
#include <string>

#include "Includes/nlohmann/json.hpp"

class Person
{
private:
    std::string Firstname;
    std::string Lastname;
    int Age;

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Person, Firstname, Lastname, Age);

    Person();
    ~Person();

    std::string GetFullName() const;

    friend std::ostream &operator<<(std::ostream &outStream, const Person &person);
};