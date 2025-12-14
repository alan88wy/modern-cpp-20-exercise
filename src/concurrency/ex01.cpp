#include <iostream>
#include <thread>

void foo()
{
    printf("Hello from foo() - %d \n", std::this_thread::get_id());
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
}

class callable__class
{
    public:
        void operator()()
        {
            printf("Hello from class with function call operator () - %d \n", std::this_thread::get_id());
            std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
        }
};

void run()
{
    
    std::thread thread1(foo);
    thread1.join(); // Calling this here will ensure foo is executed first. 
   
    callable__class f;
    std::thread thread2(f);
    thread2.join();

    std::thread thread3([]
    {
        printf("Hello from lambda function - %d \n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    });

    // Result will be unpredictable if we run all 3 join here. By doing what we do now, 
    // it ensure sequential execution. Join will block any execution until it finished.
    // If we detach any of the thread, then it will not be executing sequentially. 

    thread3.join();

    if (thread1.joinable())
        printf("thread1 is joinable \n");
    else
        printf("thread1 is not joinable \n");

    printf("Hello from run() : %d \n", std::this_thread::get_id());
}

int main()
{
    run();
    printf("Hello from main() - %d \n", std::this_thread::get_id());
    return 0;
}

/*
In C++, an std::thread begins execution immediately upon its creation (construction), 
not when you call join(). The join() method serves a different purpose: it blocks the 
calling thread until the thread it's called on has finished its execution. 

Here is a breakdown of the key concepts:

Thread creation and start
-------------------------

* When you create an std::thread object and pass a function (or another callable object) 
  to its constructor, the new thread is launched immediately.
* The C++ runtime and operating system scheduler then determine when the new thread gets a 
  turn to run on a CPU core.
* While the new thread is running, the original thread of execution (e.g., your main() function) 
  continues to run concurrently. 

The role of join()
------------------

The join() method is a synchronization mechanism.

* Blocks execution: When you call my_thread.join(), the thread that made the call will pause 
  and wait. It will not continue until my_thread has completely finished executing its task.
* Ensures completion: join() is typically used to ensure that a child thread has finished its 
  work before the parent thread (like main()) exits. If the main thread exits before a joinable 
  thread has completed, the program will terminate abruptly by calling std::terminate().
* Releases resources: After a thread has been successfully joined, the system resources associated 
  with it are released. A thread can only be joined once. 


Synchronization and Shared Resources:
-------------------------------------

When multiple threads access and modify shared resources (like global variables or objects), 
you need synchronization mechanisms to prevent data races and ensure correct behavior.

Common synchronization tools include:

std::mutex: Provides exclusive access to a critical section of code, 
            ensuring only one thread can execute it at a time.
std::lock_guard and std::unique_lock: RAII (Resource Acquisition Is Initialization) wrappers 
            for mutexes, automatically acquiring and releasing locks.
std::atomic: Provides atomic operations on variables, ensuring operations are indivisible 
            and thread-safe without explicit locking for simple types.

Detaching Threads:
------------------

Alternatively to join(), you can detach() a thread. A detached thread becomes independent of 
the std::thread object that created it and continues execution even if the creating thread 
finishes.

Detaching requires careful consideration, as the detached thread's resources will not be 
automatically cleaned up if the main program exits before it completes.

thread.joinable() - check if the thread is joinable (i.e., it has not been joined or detached yet).

*/
