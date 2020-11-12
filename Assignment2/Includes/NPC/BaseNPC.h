#pragma once
#include "INPC.h"

class BaseNPC : public INPC
{
public:
    std::string GetName() const override
    {
        return "Base NPC";
    }
};