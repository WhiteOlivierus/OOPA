#pragma once
#include "../NPC/NPCDecorator.h"

class Troll : public NPCDecorator
{
public:
    Troll(INPC *component) : NPCDecorator(component) {}

    std::string Operation() const override
    {
        return "Troll(" + NPCDecorator::Operation() + ")";
    }
};
