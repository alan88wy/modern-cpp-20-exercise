#include <iostream>
#include <string>
#include <vector>

// Defining type alias
using myInt = int;
using myIntVector = std::vector<int>;
using myString = std::string;

typedef int otherInt; // Old way of doing thing - before C++11

int main(int argc, char* argv[])
{

    myInt a = 20;
    myString b = "Fox";
    myIntVector c = {1,2,3,4,5};
    otherInt i { 200 };

    std::cout << "myInt -> " << a << "\n";
    std::cout << "otherInt -> " << i << "\n";
    std::cout << "MyString -> " << b << "\n";
    std::cout << "myIntVector -> ";

    for (auto i : c) {
        std::cout << i << " ";
    }

    std::cout << "\n";

    return 0;
}