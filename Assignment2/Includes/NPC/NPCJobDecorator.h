#pragma once
#include "INPC.h"

class NPCJobDecorator : public INPC
{
protected:
    INPC *component_;

public:
    NPCJobDecorator(INPC *component) : component_(component) {}

    std::string Render() const override
    {
        return this->component_->Render();
    }
};