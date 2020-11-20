#include "Includes/Rules/BaseRule.h"

#pragma once

class LessThanTwo : public BaseRule
{
public:
    void Apply(Grid *grid)
    {
        std::vector<Cell *> neighbors;
        Cell *current;

        //Get neighbors
        for (int i = 0; i < grid->size; i++)
            (*grid).GetNeighbors(250, current, neighbors);

        //Count alive cells
        int neighborsAlive = 0;
        for (auto &&neighbour : neighbors)
            (*neighbour) == alive ? neighborsAlive++ : 0;

        //Do something
        if (neighborsAlive < 2 && (*current) == alive)
            current->FlipCell();
    }
};
