#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

#include "Includes/nlohmann/json.hpp"
#include "Includes/Module.cpp"

using json = nlohmann::json;

int main(int, char **)
{
    const int amountOfModules = 3;
    const int studentsPerModule = 10;

    //Load all data
    std::ifstream modulesInput("Input/notModules.json");
    std::ifstream teachersInput("Input/notTeachers.json");
    std::ifstream studentsInput("Input/notStudents.json");

    json json;

    //Load modules from json
    modulesInput >> json;
    std::vector<std::string> modulesNames = json.get<std::vector<std::string>>();

    //Load teachers from json
    teachersInput >> json;
    std::vector<Person> teachers;
    for (auto i : json)
    {
        Person teacher;
        from_json(i, teacher);
        teachers.push_back(teacher);
    }

    //Load students from json
    studentsInput >> json;
    std::vector<Person> students;
    for (auto i : json)
    {
        Person student;
        from_json(i, student);
        students.push_back(student);
    }

    //Set random seed
    srand((unsigned)time(0));

    std::vector<Module> modules;

    //Loop for creating modules
    for (int i = 0; i < amountOfModules; i++)
    {

        //Get 1 referenced random module
        int randomIndex = 1 + (rand() % modulesNames.size());
        std::string randomModule = modulesNames[randomIndex];

        //Get 1 referenced random teacher
        randomIndex = 1 + (rand() % teachers.size());
        Person &randomTeacher = teachers[randomIndex];

        //Get 10 referenced random students
        std::vector<Person> randomStudents;
        for (int i = 0; i < studentsPerModule; i++)
        {
            randomIndex = 1 + (rand() % studentsPerModule);
            randomStudents.push_back(students[randomIndex]);
        }

        //Create module
        modules.push_back(Module(randomModule, randomTeacher, randomStudents));
    }
    //End loop

    //Show in console
    for (auto &module : modules)
        std::cout << module << std::endl;

    //Dump modules to json
    json = modules;

    std::ofstream output("Output/noFinalModules.json");

    output << std::setw(4) << json << std::endl;
}
