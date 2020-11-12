#pragma once
#include "INPC.h"

class NPCRaceDecorator : public INPC
{
protected:
    INPC *component_;

public:
    NPCRaceDecorator(INPC *component) : component_(component) {}

    std::string GetName() const override
    {
        return this->component_->GetName();
    }
};