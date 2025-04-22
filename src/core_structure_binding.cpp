#include <iostream>

int main(int argc, char* argv[])
{

    int a[] {1,2,3};

    std::cout << "a -> ";

    for (auto i : a)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    auto [a1, a2, a3] = a;  // Assign value to a1, a2, a3

    std::cout << "Changing a1 = 20, a2 = 30, a3 = 40\n";  

    a1 = 20;
    a2 = 30;
    a3 = 40;

    std::cout << "a after -> ";

    for (auto i : a)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    int b[] {1,2,3};

    std::cout << "b -> ";

    for (auto i : b)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    auto& [b1, b2, b3] = b;  // assigning address of each element instead of calue

    std::cout << "Changing b1 = 20, b2 = 30, b3 = 40\n";

    b1 = 20;
    b2 = 30;
    b3 = 40;

    std::cout << "b after -> ";

    for (auto i : b)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    return 0;
}