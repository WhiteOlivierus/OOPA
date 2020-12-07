#include <vector>
#include <iostream>
#include <mutex>
#include <thread>
#include <algorithm>

template <typename T>
class ThreadSafeVector
{
private:
    std::vector<T> *elements;
    std::mutex lock;

public:
    ThreadSafeVector<T>();
    ~ThreadSafeVector();

    friend std::ostream &operator<<(std::ostream &os, const ThreadSafeVector<T> &dt);

    void push_back(T element);
    void Check();
};
