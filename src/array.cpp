#include <iostream>

using namespace std;

int main() {
    int scores[] {10, 12, 15, 11, 18, 17, 29};

    std::cout << "Size of array : " << size(scores) << std::endl; // size is available in C++17 & C++20
    // Old way (before C++17) : sizeof(scores) / sizeof(scores[0]) to get size of array
    
}