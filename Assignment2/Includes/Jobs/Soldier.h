#pragma once
#include "../NPC/NPCJobDecorator.h"

class Soldier : public NPCJobDecorator
{
public:
    Soldier(INPC *component) : NPCJobDecorator(component) {}

    std::string Render() const override
    {
        return "Soldier(" + NPCJobDecorator::Render() + ")";
    }
};
