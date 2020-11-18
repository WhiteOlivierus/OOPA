#include "Includes/Grid.h"
#include "Includes/Screen.cpp"

Grid::Grid(int x, int y)
{
    grid = new std::vector<std::vector<char>>(x, std::vector<char>(y));
}

Grid::~Grid() {}

void Grid::RenderGrid()
{
    ClearScreen();

    for (auto &&row : *grid)
    {
        for (auto &&cell : row)
            std::cout << cell;

        std::cout << std::endl;
    }
}

void Grid::InnitGrid(char cellGraphic)
{
    for (auto &&row : *grid)
        for (auto &&cell : row)
            cell = cellGraphic;
}