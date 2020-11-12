#pragma once
#include "../NPC/NPCRaceDecorator.h"

class Elf : public NPCRaceDecorator
{
public:
    Elf(INPC *component) : NPCRaceDecorator(component) {}

    std::string GetName() const override
    {
        return "Elf(" + NPCRaceDecorator::GetName() + ")";
    }
};