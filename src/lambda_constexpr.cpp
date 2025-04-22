#include <iostream>

int main(int argc, char* argv[])
{

    constexpr auto lambda = [](int x, int y) { return x + y;};

    auto a = lambda(2,3);

    std::cout << "a -> " << a << "\n";


    return 0;
}