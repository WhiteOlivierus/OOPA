#pragma once
#include "../NPC/NPCJobDecorator.h"

class Shaman : public NPCJobDecorator
{
public:
    Shaman(INPC *component) : NPCJobDecorator(component) {}

    std::string GetName() const override
    {
        return "Shaman(" + NPCJobDecorator::GetName() + ")";
    }
};
