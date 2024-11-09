#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

/*
 * To compile this program, do this
 *
 * g++ -std=c++23 -Wall -pthread thread.cpp
*/

void func1()
{
    for (int i = 0; i < 10; i++)
    {
        m.lock();
        std::cout << "Executing -> " << i << std::endl;
        m.unlock();
    }
}

void func2()
{
    for (int i = 0; i < 10; i++)
    {
        // m.lock();
        //
        // Since we can forget to unlock the mutex manually, a better approach is to use the
        // std::lock_guard function instead. It locks the mutex, and once it goes out of scope, 
        // it automatically unlocks the mutex.

        std::lock_guard<std::mutex> lg(m);

        std::cout << "Executing -> " << i + 10 << std::endl;
        // m.unlock();
    } // lock_guard goes out of scope here and unlocks the mutex
}

int main()
{
    std::thread t1 {func1};
    std::thread t2 {func2};

    t1.join();
    t2.join();

    return 0;
}