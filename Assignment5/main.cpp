#include <iostream>
#include <string>

#include "Includes/MyArray.cpp"

int main(int, char **)
{
    MyArray<float> numbers;
    MyArray<std::string> text;

    std::vector<float> floatValues = {1.00f, 5.30f, 234.70f};
    std::vector<std::string> stringValues = {"bas", "john", "abraham"};

    numbers.Put(floatValues);
    text.Put(stringValues);

    std::cout << "Count is: " << numbers.Size() << std::endl;
    std::cout << "Count is: " << text.Size() << std::endl;

    numbers.Put(3.0f);
    text.Put("laila");

    std::cout << "Count is: " << numbers.Size() << std::endl;
    std::cout << "Count is: " << text.Size() << std::endl;

    int size = numbers.Size();
    for (int i = 0; i < size; i++)
        std::cout << numbers.Get() << std::endl;

    size = text.Size();
    for (int i = 0; i < size; i++)
        std::cout << text.Get() << std::endl;
}
