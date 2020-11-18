#include <iostream>

#include "Includes/Grid.cpp"

int main(int, char **)
{
    Grid *grid = new Grid(25, 75);

    grid->InnitGrid('O');

    grid->RenderGrid();
}
