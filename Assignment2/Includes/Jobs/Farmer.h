#pragma once
#include "../NPC/NPCJobDecorator.h"

class Farmer : public NPCJobDecorator
{
public:
    Farmer(INPC *component) : NPCJobDecorator(component) {}

    std::string GetName() const override
    {
        return "Farmer(" + NPCJobDecorator::GetName() + ")";
    }
};
