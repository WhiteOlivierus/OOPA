#include <iostream>
#include <conio.h>

#include "Includes/Rules/MoreThanThree.h"
#include "Includes/Rules/EqualsTwoOrThree.h"
#include "Includes/Rules/Revive.h"
#include "Includes/Rules/LessThanTwo.h"

int main(int, char **)
{
    Grid *grid = new Grid(75, 25);

    std::vector<BaseRule *> rules;

    rules.push_back(new LessThanTwo);
    rules.push_back(new EqualsTwoOrThree);
    rules.push_back(new MoreThanThree);

    grid->FlipCell(0, 0);
    grid->FlipCell(30, 20);
    grid->FlipCell(31, 20);
    grid->FlipCell(32, 20);

    grid->Render();

    std::cout << std::endl;
    std::cout << "Press any button to continue or x to quit...";

    char escapeChar;

    escapeChar = getchar();

    do
    {
        if (escapeChar == 'x')
            break;

        for (auto &&i : rules)
            i->Apply(grid);

        grid->Update();

        grid->Render();

        std::cout << std::endl;
        std::cout << "Press any button to continue or x to quit...";

        escapeChar = getchar();
    } while (escapeChar != 'x');

    delete grid;
}
