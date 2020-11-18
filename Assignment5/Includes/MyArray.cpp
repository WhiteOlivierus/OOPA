#include "Includes/MyArray.h"

template <class T>
MyArray<T>::MyArray() {}

template <class T>
MyArray<T>::~MyArray() {}

template <class T>
void MyArray<T>::Put(std::vector<T> elements)
{
    for (auto &&element : elements)
        Put(element);
}

template <class T>
void MyArray<T>::Put(T element)
{
    storedElements.push_back(element);
    std::sort(storedElements.begin(), storedElements.end());
}

template <class T>
T MyArray<T>::Get()
{
    T element = storedElements[0];
    std::vector<T>::iterator it;
    it = storedElements.begin();
    storedElements.erase(it);
    return element;
}

template <class T>
int MyArray<T>::Size()
{
    return (int)storedElements.size();
}