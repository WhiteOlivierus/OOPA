#pragma once

#include "Includes/Grid.h"

Grid::Grid(int x, int y) : width(x), height(y), size((x * y) - 1)
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

// void Grid::GetNeighbors(int index, std::vector<Cell *> &neighbors)
// {
//     neighbors.clear();

//     int x = index % width;
//     int y = index / width;

//     int indexes[8] = {
//         (x - 1) + width * (y - 1),   //Bottom Left
//         x + width * (y - 1),         //Bottom
//         (x + 1) + width * (y - 1),   //Bottom Right
//         (x - 1) + width * y,         //Left
//         (x + 1) + width * y,         //Right
//         (x - 1) + width * ((y + 1)), //Top Left
//         x + width * (y + 1),         //Top
//         (x + 1) + width * (y + 1)};  //Top Right

//     for (auto &&i : indexes)
//         if (i <= size && i >= 0)
//             neighbors.push_back((*grid)[i]);
// }

void Grid::GetCurrent(int index, Cell *&current)
{
    current = (*nextIteration)[index];
}

int Grid::GetNeighbors(int index)
{
    int xx = index % width;
    int yy = index / width;

    int n = 0, nx, ny;
    for (int y = -1; y < 2; y++)
    {
        for (int x = -1; x < 2; x++)
        {
            if (!x && !y)
                continue;
            nx = (width + xx + x) % width;
            ny = (height + yy + y) % width;
            n += (*(*grid)[nx + ny * width]) == alive ? 1 : 0;
        }
    }
    return n;
}