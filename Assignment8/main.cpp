#include <iostream>
#include <thread>

#include "Includes/ThreadSafeVector.cpp"

ThreadSafeVector<int> *vector;

void AddLotsOfInts()
{
    for (int i = 0; i < 100; i++)
    {
        vector->push_back(i);
    }
}

int main(int, char **)
{
    vector = new ThreadSafeVector<int>();

    std::thread t1(AddLotsOfInts);
    std::thread t2(AddLotsOfInts);

    t1.join();
    t2.join();

    vector->Check();

    system("pause");
}
