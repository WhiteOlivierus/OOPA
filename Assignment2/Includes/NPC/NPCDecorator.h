#pragma once
#include "INPC.h"

class NPCDecorator : public INPC
{
protected:
    INPC *component_;

public:
    NPCDecorator(INPC *component) : component_(component) {}

    std::string Operation() const override
    {
        return this->component_->Operation();
    }
};