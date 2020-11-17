#include <iostream>
#include <string>
#include <vector>

#include "Includes/Person.cpp"
#include "Includes/nlohmann/json.hpp"

class Module
{
private:
    std::string name;
    Person teacher;
    std::vector<Person> students;

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Module, name, teacher, students)

    Module();
    Module(std::string name, Person teacher, std::vector<Person> students);

    ~Module();

    friend std::ostream &operator<<(std::ostream &outStream, const Module &module);
};
