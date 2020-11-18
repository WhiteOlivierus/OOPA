#include <iostream>

#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <locale>

void SortAndSplit(std::string filter, std::vector<std::string> &left, std::vector<std::string> &right, std::vector<std::string> &input)
{
    std::sort(input.begin(), input.end());

    std::vector<std::string>::iterator it = std::find(input.begin(), input.end(), filter);

    int index = std::distance(input.begin(), it);

    for (int i = 0; i < index; i++)
        left.push_back(input[i]);

    for (int i = index; i < input.size(); i++)
        right.push_back(input[i]);
}

void ToUpper(std::vector<std::string> &input)
{
    std::locale loc;
    for (auto &&str : input)
        for (std::string::size_type i = 0; i < str.length(); ++i)
            str[i] = std::toupper(str[i], loc);
}

void RemoveDoubles(std::vector<std::string> &input)
{
    std::set<std::string> set(input.begin(), input.end());
    input.assign(set.begin(), set.end());
}

void RemoveNegatives(std::vector<double> &input)
{
    auto it = remove_if(input.begin(), input.end(), [](const double i) { return i < 0; });
    input.erase(it, input.end());
}

void RemoveOdd(std::vector<double> &input)
{
    auto it = remove_if(input.begin(), input.end(), [](const double i) { return ((int)i) % 2 != 0; });
    input.erase(it, input.end());
}

double Sum(std::vector<double> &input)
{
    double sum = 0.0;
    for (auto &n : input)
        sum += n;
    return sum / input.size();
}

template <typename T>
void PrintVector(std::string &title, std::vector<T> vector)
{
    std::cout << title << std::endl;

    for (auto element : vector)
        std::cout << element << std::endl;

    std::cout << "--------------------------------" << std::endl;
}