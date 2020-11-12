#pragma once
#include "../NPC/NPCJobDecorator.h"

class Soldier : public NPCJobDecorator
{
public:
    Soldier(INPC *component) : NPCJobDecorator(component) {}

    std::string GetName() const override
    {
        return "Soldier(" + NPCJobDecorator::GetName() + ")";
    }
};
