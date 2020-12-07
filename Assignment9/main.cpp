#include <queue>
#include <thread>
#include <iostream>
#include <mutex>

int c = 0;
bool done = false;
std::queue<int> goods;

std::mutex mutex;

void producer()
{
    for (int i = 0; i < 500; ++i)
    {
        mutex.lock();
        goods.push(i);
        mutex.unlock();
        c++;
    }

    done = true;
}

void consumer()
{
    while (!done)
    {
        while (!goods.empty())
        {
            mutex.lock();
            goods.pop();
            mutex.unlock();
            c--;
        }
    }
}

int main()
{
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << c << std::endl;
}
