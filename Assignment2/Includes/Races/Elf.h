#pragma once
#include "../NPC/NPCDecorator.h"

class Elf : public NPCDecorator
{
public:
    Elf(INPC *component) : NPCDecorator(component) {}

    std::string Operation() const override
    {
        return "Elf(" + NPCDecorator::Operation() + ")";
    }
};