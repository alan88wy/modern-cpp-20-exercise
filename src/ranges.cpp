#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{

    std::vector<int> v {4,2,6,4,1,2,4,3, 8,9,6,10,4,30,7,9};

    std::cout << "Before sort : ";

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";
    
    std::ranges::sort(v);

    std::cout << "After sort : ";

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    std::ranges::reverse(v);

    std::cout << "Reverse : ";

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    auto filtered_v = v | std::views::filter([](int x) { return x % 2 == 0; });

    std::cout << "After filter for even no : ";

    for (auto i : filtered_v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    auto f2 = v | std::views::filter([](int x) { return x % 2 == 1; }) | std::views::filter([](int x ){ return x > 2;});

    std::cout << "After filter for odd no and for no > 2 : ";

    for (auto i : f2)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";


    return 0;
}