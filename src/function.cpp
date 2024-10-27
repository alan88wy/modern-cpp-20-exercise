#include <iostream>

void func1(std::string message); // pass by value
void func2(std::string& message); // pass by reference

int main()
{
    std::string message = "I love c++";

    func1(message);

    func2(message);

    return 0;
}

void func1(std::string message)
{
    std::cout << message << "\n";
}

void func2(std::string& message)
{
    std::cout << message << "\n";
}