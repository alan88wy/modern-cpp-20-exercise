#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

int main()
{
    std::vector<int> v = { 5,2,6,19,3,66,3,2};
    
    std::set<int> s2;

    for (auto i : v)
    {
        s2.insert(i);
    }

    std::cout << "set s2 : ";

    for (auto i : s2)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    auto it3 = s2.find(19);

    if (it3 != s2.end())
    {
        std::cout << "deleting : " << *it3 << "\n";
        s2.erase(it3);
    } else {
        std::cout << "Cannot find -> " << 19 << "\n";
    }
        
    std::cout << "set s2 : ";

    for (auto i : s2)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    std::unordered_set<int> us { 5,2,6,19,3,66,3,2};

    std::cout << "Unordered set us { 5,2,6,19,3,66,3,2} : ";

    for (auto i : us)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";


    return 0;
}