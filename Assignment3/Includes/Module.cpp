#include "Includes/Module.h"

Module::Module() {}

Module::Module(std::string name, Person teacher, std::vector<Person> students) : name(name), teacher(teacher), students(students)
{
}
Module::~Module()
{
}

std::ostream &operator<<(std::ostream &outStream, const Module &module)
{
    outStream << module.name << " taught by " << module.teacher << std::endl;

    outStream << "Attended by:" << std::endl;

    for (auto student : module.students)
        outStream << "  " << student << std::endl;

    return outStream;
}