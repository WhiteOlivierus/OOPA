#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Includes/Module.cpp"
#include "Includes/Utilities.cpp"
#include "Includes/Random.cpp"

#include "Includes/nlohmann/json.hpp"
using json = nlohmann::json;

int main(int, char **)
{
    const int amountOfModules = 3;
    const int studentsPerModule = 10;
    const int studentsPerClass = 15;

    //Load all data
    std::ifstream modulesInput("Input/notModules.json");
    std::ifstream teachersInput("Input/notTeachers.json");
    std::ifstream studentsInput("Input/notStudents.json");

    json json;

    //Load modules from json
    modulesInput >> json;
    std::vector<std::string> modulesNames = json.get<std::vector<std::string>>();

    //Load teachers from json
    std::vector<Person> teachers;
    LoadPersons(json, teachersInput, teachers);

    //Load students from json
    std::vector<Person> students;
    LoadPersons(json, studentsInput, students);

    //Set random seed
    srand((unsigned)time(0));

    //Create class of students
    std::vector<Person> studentsClass;
    for (int i = 0; i < studentsPerClass; i++)
        studentsClass.push_back(*select_randomly(students.begin(), students.end()));

    std::vector<Module *> modules;

    //Loop for creating modules
    for (int i = 0; i < amountOfModules; i++)
    {
        //Get 1 referenced random module
        std::string randomModule = *select_randomly(modulesNames.begin(), modulesNames.end());

        //Get 1 referenced random teacher
        Person randomTeacher = *select_randomly(teachers.begin(), teachers.end());

        //Get 10 referenced random students
        std::vector<Person> randomStudents;
        for (int i = 0; i < studentsPerModule; i++)
            randomStudents.push_back(*select_randomly(studentsClass.begin(), studentsClass.end()));

        //Create module
        modules.push_back(new Module(randomModule, randomTeacher, randomStudents));
    }
    //End loop

    //Dump json
    DumpModules(modules, "Output/noFinalModules.json");

    //Start assignment
    //Show ECS per student
    DumpECS(modules, studentsClass, "Output/ecsOriginal.json");

    //Change EC for one module
    modules[0]->EC = 10;

    //Show ECS per student again
    DumpECS(modules, studentsClass, "Output/ecsChanged.json");

    //Clear students from module
    modules[0]->ClearStudents();

    //Show ECS per student again
    DumpECS(modules, studentsClass, "Output/ecsStudentsRemoved.json");

    //Clean up
    for (auto &&module : modules)
        delete module;
}
