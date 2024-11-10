#include <iostream>

int main(int argc, char* argv[])
{

    auto lambda = []<typename T>(T param) { 
        std::cout << param << "\n";
    };


    lambda(3.12); // float
    lambda(23); //integer
    lambda("Hello World!"); // string


    return 0;
}