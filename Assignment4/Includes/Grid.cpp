#include "Includes/Grid.h"

#pragma once

Grid::Grid(int x, int y) : width(x), height(y), size(x * y)
{
    grid = new std::vector<Cell *>(x * y);
    nextIteration = new std::vector<Cell *>(x * y);

    Init();
}

Grid::~Grid()
{
    size_t gridSize = grid->size();

    for (int i = 0; i < gridSize; i++)
        delete (*grid)[i];

    delete grid;
}

void Grid::Init()
{
    for (int i = 0; i < grid->size(); i++)
    {
        (*grid)[i] = new Cell();
        (*nextIteration)[i] = new Cell();
    }
}

void Grid::Render()
{
    ClearScreen();

    std::string output;

    int lastRow = 0;
    for (int i = 0; i < grid->size(); i++)
    {
        int currentRow = i / width;
        if (lastRow != currentRow)
        {
            output += "\n";
            lastRow = currentRow;
        }

        output += (*grid)[i]->Render();
    }

    std::cout << output;
}

void Grid::Update()
{
    for (int i = 0; i < nextIteration->size(); i++)
        (*(*grid)[i]) = (*(*nextIteration)[i]);
}

void Grid::FlipCell(int x, int y)
{
    (*grid)[x + width * y]->FlipCell();
    (*nextIteration)[x + width * y]->FlipCell();
}

void Grid::GetNeighbors(int index, Cell *&current, std::vector<Cell *> &neighbors)
{
    neighbors.clear();

    current = (*nextIteration)[index];

    int x = index % width;
    int y = index / width;

    int indexes[8] = {
        (x - 1) + width * y,         //Left of current
        (x + 1) + width * y,         //Right of current
        x + width * (y + 1),         //Top of current
        x + width * (y - 1),         //Bottom of current
        (x - 1) + width * ((y + 1)), //Top Left of current
        (x + 1) + width * (y + 1),   //Top Right of current
        (x + 1) + width * (y - 1),   //Bottom Right of current
        (x - 1) + width * (y - 1)};  //Bottom Left of current

    for (auto &&i : indexes)
        if (i <= size && i >= 0)
            neighbors.push_back((*grid)[i]);
}