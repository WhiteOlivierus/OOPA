#pragma once

#include "Includes/Cell.h"

Cell::Cell() {}

Cell::~Cell() {}

char &Cell::Render()
{
    return state;
}

void Cell::FlipCell()
{
    state == dead ? state = alive : state = dead;
}

bool operator==(const Cell &lhs, const Cell &rhs)
{
    return lhs.state == rhs.state;
}

bool operator==(const Cell &lhs, const char &rhs)
{
    return lhs.state == rhs;
}
