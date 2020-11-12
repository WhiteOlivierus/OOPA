#pragma once
#include "../NPC/NPCJobDecorator.h"

class Shaman : public NPCJobDecorator
{
public:
    Shaman(INPC *component) : NPCJobDecorator(component) {}

    std::string Render() const override
    {
        return "Shaman(" + NPCJobDecorator::Render() + ")";
    }
};
