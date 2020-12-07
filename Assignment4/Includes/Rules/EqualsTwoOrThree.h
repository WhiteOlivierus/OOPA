#pragma once

#include "Includes/Rules/BaseRule.h"

class EqualsTwoOrThree : public BaseRule
{
public:
    bool Apply(Grid *grid, int index)
    {
        BaseRule::Apply(grid, index);

        //Do something
        if ((neighborsAlive == 2 || neighborsAlive == 3) && (*current) == alive)
            return true;
        else
            return false;
    }
};
