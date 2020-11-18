#include <iostream>
#include <vector>

class Grid
{
private:
    std::vector<std::vector<char>> *grid;

public:
    Grid(int x, int y);
    ~Grid();

    void RenderGrid();
    void InnitGrid(char cellGraphic);
};
