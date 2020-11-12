#pragma once
#include "../NPC/NPCJobDecorator.h"

class Farmer : public NPCJobDecorator
{
public:
    Farmer(INPC *component) : NPCJobDecorator(component) {}

    std::string Render() const override
    {
        return "Farmer(" + NPCJobDecorator::Render() + ")";
    }
};
