#include <iostream>
#include <conio.h>

#include "Includes/Grid.cpp"

#include "Includes/Rules/MoreThanThree.h"
#include "Includes/Rules/EqualsTwoOrThree.h"
#include "Includes/Rules/Die.h"

int main(int, char **)
{
    Grid *grid = new Grid(50, 50);

    std::vector<BaseRule *> rules;

    rules.push_back(new EqualsTwoOrThree);
    rules.push_back(new MoreThanThree);
    rules.push_back(new Die);

    // grid->FlipCell(2, 2);
    // grid->FlipCell(2, 3);
    // grid->FlipCell(3, 3);
    grid->FlipCell(30, 20);
    grid->FlipCell(31, 20);
    grid->FlipCell(32, 20);
    grid->FlipCell(33, 20);
    grid->FlipCell(34, 20);
    grid->FlipCell(35, 20);

    grid->Update();

    grid->Render();

    std::cout << std::endl;
    std::cout << "Press any button to continue or x to quit...";

    char escapeChar = ' ';

    // escapeChar = getchar();

    do
    {
        if (escapeChar == 'x')
            break;

        for (int i = 0; i < grid->size; i++)
            for (auto &&rule : rules)
                if (rule->Apply(grid, i))
                    continue;

        grid->Update();

        grid->Render();

        std::cout << std::endl;
        std::cout << "Press any button to continue or x to quit...";

        escapeChar = getchar();
    } while (escapeChar != 'x');

    delete grid;
}
