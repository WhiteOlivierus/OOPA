#include <iostream>

#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <locale>

#include "Includes/Solutions.cpp"

int main()
{
    {
        std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
        // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
        // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na

        std::vector<std::string> left;
        std::vector<std::string> right;

        SortAndSplit("purple", left, right, colours);

        PrintVector("Sort and split \nFirst part:", left);

        PrintVector("Second part:", right);
    }

    {
        std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
        // 2) alle elementen UPPERCASE te maken.
        ToUpper(colours);

        PrintVector("ToUpper:", colours);
    }

    {
        std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
        // 3) alle dubbele te verwijderen
        RemoveDoubles(colours);

        PrintVector("Remove doubles:", colours);
    }

    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    {
        std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
        // 1) alle negatieve elementen te verwijderen
        RemoveNegatives(numbers);

        PrintVector("Remove negatives:", numbers);
    }

    {
        std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
        // 2) voor alle elementen te bepalen of ze even of oneven zijn
        RemoveOdd(numbers);

        PrintVector("Remove odd:", numbers);
    }

    {
        std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
        // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
        double sum = Sum(numbers);

        std::cout << "Sum:" << std::endl;

        std::cout << sum << std::endl;

        std::cout << "--------------------------------" << std::endl;
    }

    return 0;
}