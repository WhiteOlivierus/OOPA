#include "ThreadSafeVector.h"

template <typename T>
ThreadSafeVector<T>::ThreadSafeVector()
{
    elements = new std::vector<T>();
}

template <typename T>
ThreadSafeVector<T>::~ThreadSafeVector() {}

template <typename T>
std::ostream &operator<<(std::ostream &os, const ThreadSafeVector<T> &dt)
{
    for (auto &&i : dt.elements)
        os << i << std::endl;

    return os;
}

template <typename T>
void ThreadSafeVector<T>::push_back(T element)
{
    lock.lock();
    elements->push_back(element);
    lock.unlock();
}

template <typename T>
void ThreadSafeVector<T>::Check()
{
    std::sort(elements->begin(), elements->end());

    bool repeated = false;
    for (int j = 0; j < elements->size() - 1; j++)
        repeated |= (elements[j] == elements[j + 1]);

    std::cout << (repeated ? "repeat" : "no repeat") << std::endl;
}