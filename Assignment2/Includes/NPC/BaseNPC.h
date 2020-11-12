#pragma once
#include "INPC.h"

class BaseNPC : public INPC
{
public:
    std::string Operation() const override
    {
        return "Base NPC";
    }
};