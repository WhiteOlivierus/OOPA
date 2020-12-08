#include <iostream>
#include <conio.h>

#include "Includes/Grid.cpp"

#include "Includes/Rules/MoreThanThree.h"
#include "Includes/Rules/EqualsTwoOrThree.h"
#include "Includes/Rules/Die.h"

bool ApplyRules(std::vector<BaseRule *> rules, Grid *&grid, int i)
{
    for (auto &&rule : rules)
    {
        bool state = rule->Apply(grid, i);

        if (state)
            return true;
    }
    return false;
}

int main(int, char **)
{
    Grid *grid = new Grid(50, 50);
    // Grid *grid = new Grid(4, 4);

    std::vector<BaseRule *> rules;

    rules.push_back(new EqualsTwoOrThree);
    rules.push_back(new MoreThanThree);
    rules.push_back(new Die);

    //Block
    grid->FlipCell(1, 1);
    grid->FlipCell(2, 1);
    grid->FlipCell(1, 2);
    grid->FlipCell(2, 2);

    //Block
    grid->FlipCell(30, 20);
    grid->FlipCell(31, 20);
    grid->FlipCell(30, 21);
    grid->FlipCell(31, 21);

    //Blinker
    grid->FlipCell(40, 20);
    grid->FlipCell(41, 20);
    grid->FlipCell(42, 20);

    grid->Update();

    grid->Render();

    std::cout << std::endl;
    std::cout << "Press any button to continue or x to quit...";

    char escapeChar = ' ';

    escapeChar = getchar();

    do
    {
        if (escapeChar == 'x')
            break;

        for (int i = 0; i < grid->size; i++)
            if (ApplyRules(rules, grid, i))
                continue;

        grid->Update();

        grid->Render();

        std::cout << std::endl;
        std::cout << "Press any button to continue or x to quit...";

        escapeChar = getchar();
    } while (escapeChar != 'x');

    delete grid;
}
