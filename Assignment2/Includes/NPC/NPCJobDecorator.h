#pragma once
#include "INPC.h"

class NPCJobDecorator : public INPC
{
protected:
    INPC *component_;

public:
    NPCJobDecorator(INPC *component) : component_(component) {}

    std::string GetName() const override
    {
        return this->component_->GetName();
    }
};