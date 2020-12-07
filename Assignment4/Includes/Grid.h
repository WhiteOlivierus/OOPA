#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include "Includes/Screen.cpp"
#include "Includes/Cell.cpp"

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
    void GetNeighbors(int index, std::vector<Cell *> &neighbors);
    void GetCurrent(int index, Cell *&current);
};
