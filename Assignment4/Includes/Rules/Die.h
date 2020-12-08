#pragma once

#include "Includes/Rules/BaseRule.h"

class Die : public BaseRule
{
public:
    bool Apply(Grid *grid, int index)
    {
        BaseRule::Apply(grid, index);

        //Do something
        if ((*current) == alive)
            current->FlipCell();

        return true;
    }
};
