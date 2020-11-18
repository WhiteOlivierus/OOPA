#include <vector>
#include <algorithm>
#include <string>

template <class T>
class MyArray
{
private:
    std::vector<T> storedElements;

public:
    MyArray();
    ~MyArray();

    void Put(T element);
    void Put(std::vector<T> elements);

    T Get();

    int Size();
};