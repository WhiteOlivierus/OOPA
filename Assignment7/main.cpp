#include <iostream>
#include "Includes/Parent.cpp"

int main()
{
    std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
    std::cout << p1.use_count() << std::endl;

    std::shared_ptr<Parent> p2 = p1;
    std::cout << p1.use_count() << std::endl;

    std::shared_ptr<Parent> p3 = p1;
    std::cout << p1.use_count() << std::endl;

    std::cout << (*p1.get()->GetChild()) << std::endl;

    p2.get()->DeleteChild();

    std::cout << (*p1.get()->GetChild()) << std::endl;

    std::cout << p1.use_count() << std::endl;

    Parent p4("Parent4");
    Parent p5("Parent5");

    p4 = p5;

    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;

    return 0;
}