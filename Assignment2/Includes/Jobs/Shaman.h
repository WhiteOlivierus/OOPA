#pragma once
#include "../NPC/NPCJobDecorator.h"

class Shaman : public NPCJobDecorator
{
public:
    Shaman(`` *component) : NPCJobDecorator(component) {}

    std::string Render() const override
    {
        return "Shaman(" + NPCJobDecorator::Render() + ")";
    }
};
