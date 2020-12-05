#include <queue>
#include <thread>
#include <iostream>

int c = 0;
bool done = false;
std::queue<int> goods;

void producer()
{
    for (int i = 0; i < 500; ++i)
    {
        goods.push(i);
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
            goods.pop();
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
