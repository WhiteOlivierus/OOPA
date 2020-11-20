#pragma once

static const char dead = '.';
static const char alive = 'O';

class Cell
{
private:
    char state = dead;

public:
    Cell();
    ~Cell();

    char &Render();
    void FlipCell();

    friend bool operator==(const Cell &lhs, const Cell &rhs);
    friend bool operator==(const Cell &lhs, const char &rhs);
};
