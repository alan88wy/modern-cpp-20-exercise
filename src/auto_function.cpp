#include <iostream>
#include <vector>

auto intFunc() // auto function. Type depends on what is being return
{
    return 123.45;
}

auto vecFunc()
{

    return std::vector<int> {1,2,3,4,5};
}

int main(int argc, char* argv[])
{

    auto intF = intFunc();
    auto v = vecFunc();

    std::cout << "inf -> " << intF << "\n";

    std::cout << "vecFUnc -> ";

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";


    return 0;
}