#pragma once

#include "Includes/Rules/BaseRule.h"

class MoreThanThree : public BaseRule
{
public:
    bool Apply(Grid *grid, int index)
    {
        BaseRule::Apply(grid, index);

        //Do something
        if (neighborsAlive == 3 && (*current) == dead)
        {
            current->FlipCell();
            return true;
        }
        else
        {
            return false;
        }
    }
};
