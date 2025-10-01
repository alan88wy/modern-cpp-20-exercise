#include <iostream>
#include <print>

using namespace std;

class Squarer
{
public:
    int operator()(int value) const; // Overloaded function call operator. 
    int doSquare(int value) const; // Normal member function.
};
// Implementation of overloaded function call operator. 
int Squarer::operator()(int value) const { return doSquare(value); } 
// Implementation of normal member function.
int Squarer::doSquare(int value) const { return value * value; }

int main()
{
    Squarer squarer;
    int number = 3;

    // Using the overloaded function call operator
    int result1 = squarer(number);
    cout << "Using overloaded operator(): " << result1 << endl;

    // Using the normal member function
    int result2 = squarer.doSquare(number);
    cout << "Using normal member function doSquare(): " << result2 << endl;

    // Call the function call operator.
    int xSquared { squarer(number) };
    int xSquaredAgain { squarer.doSquare(xSquared) };
    // Call the normal member function. 
    std::println("{} squared is {}, and squared again is {}.", number, xSquared, xSquaredAgain);

    return 0;
}