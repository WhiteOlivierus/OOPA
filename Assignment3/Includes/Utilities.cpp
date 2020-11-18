#include <fstream>
#include <iomanip>
#include <vector>

#include "Includes/Person.h"
#include "Includes/Module.cpp"

#include "Includes/nlohmann/json.hpp"
using json = nlohmann::json;

json outputJson;

void LoadPersons(json &json, std::ifstream &input, std::vector<Person> &persons)
{
    input >> json;
    for (auto jsonObject : json)
    {
        Person person;
        from_json(jsonObject, person);
        persons.push_back(person);
    }
}

void DumpJSON(json &json, char path[])
{
    std::ofstream output(path);

    output << std::setw(4) << outputJson << std::endl;
}

void DumpModules(std::vector<Module *> &modules, char path[])
{
    outputJson.clear();

    for (auto &module : modules)
    {
        //Show in console
        std::cout << *module << std::endl;

        //Dump modules to json
        outputJson += *module;
    }

    DumpJSON(outputJson, path);
}

void DumpECS(std::vector<Module *> &modules, std::vector<Person> &studentsClass, char path[])
{
    outputJson.clear();

    for (auto &&student : studentsClass)
    {
        int ECS = 0;

        for (auto &&module : modules)
            if (module->Contains(student))
                ECS += module->EC;

        std::cout << "ECS    student" << std::endl;
        std::cout << ECS << "    " << student << std::endl;

        outputJson += ECS;
        outputJson += student;
    }

    DumpJSON(outputJson, path);
}