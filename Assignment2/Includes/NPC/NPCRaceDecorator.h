#pragma once
#include "INPC.h"

class NPCRaceDecorator : public INPC
{
protected:
    INPC *component_;

public:
    NPCRaceDecorator(INPC *component) : component_(component) {}

    std::string Render() const override
    {
        return this->component_->Render();
    }
};