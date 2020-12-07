#pragma once

#include "Includes/Grid.cpp"

class BaseRule
{
protected:
    Cell *current;
    std::vector<Cell *> neighbors;
    int neighborsAlive = 0;

public:
    virtual bool Apply(Grid *grid, int index)
    {
        //Get current
        (*grid).GetCurrent(index, current);

        //Get neighbors
        (*grid).GetNeighbors(index, neighbors);

        //Count alive cells
        for (auto &&neighbour : neighbors)
            (*neighbour) == alive ? neighborsAlive++ : 0;

        return true;
    }
};
