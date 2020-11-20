#include <iostream>
#include <vector>
#include <cmath>

#include "Includes/Screen.cpp"
#include "Includes/Cell.cpp"

#pragma once

class Grid
{
private:
    std::vector<Cell *> *grid;
    std::vector<Cell *> *nextIteration;

    int width;
    int height;

public:
    Grid(int x, int y);
    ~Grid();

    int size;

    void Init();
    void Render();
    void Update();
    void FlipCell(int x, int y);
    void GetNeighbors(int index, Cell *&current, std::vector<Cell *> &neighbors);
};
