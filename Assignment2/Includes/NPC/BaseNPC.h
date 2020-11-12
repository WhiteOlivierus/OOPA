#pragma once
#include "INPC.h"

class BaseNPC : public INPC
{
public:
    std::string Render() const override
    {
        return "Base NPC";
    }
};