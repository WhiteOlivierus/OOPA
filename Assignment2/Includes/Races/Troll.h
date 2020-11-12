#pragma once
#include "../NPC/NPCRaceDecorator.h"

class Troll : public NPCRaceDecorator
{
public:
    Troll(INPC *component) : NPCRaceDecorator(component) {}

    std::string Render() const override
    {
        return "Troll(" + NPCRaceDecorator::Render() + ")";
    }
};
