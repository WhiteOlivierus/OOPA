#include "Includes/Grid.cpp"

#pragma once

class BaseRule
{
public:
    virtual void Apply(Grid *grid) = 0;
};
