#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main()
{

    std::vector<int> v = { 5,2,6,19,3,66,3,2};

    std::cout << "v : ";

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    std::cout << "Sort : ";

    std::sort(v.begin(), v.end());

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    /*
     * To sort a container in descending order, we pass in an additional argument called a comparator. 
     * There is a built-in comparator called std::greater, which does the comparisons using the operator > and 
     * allows the std::sort function to sort the data in ascending order.
    */

    v = { 5,2,6,19,3,66,3,2};

    std::sort(v.begin(), v.end(), std::greater());

    std::cout << "Sort (Reverse): ";

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    // std::find - find the first occurrence of the comparator

    std::cout << "Find first occurrence of 3 in v : ";

    auto f = std::find(v.begin(), v.end(), 3);

    if (f != v.end())
    {
        std::cout << "Found 3 -> " << *f << "\n";
    } else {
        std::cout << "3 Not Found!\n";
    }
    
    // std::copy
    std::vector<int> dest(8);

    std::copy(v.begin(), v.end(), dest.begin());

    std::cout << "Copy from v to dest : ";

    for (auto i : dest)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    std::vector<int> dest4(4);

    std::copy(v.begin(), v.begin() + 4, dest4.begin());

    std::cout << "Copy first 4 elements : ";

    for (auto i : dest4)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    auto it = std::max_element(v.begin(), v.end());

    std::cout << "Maximum : " << *it << "\n";

    it = std::min_element(v.begin(), v.end());

    std::cout << "Minimum : " << *it << "\n";

    // std::count_if

    auto getEven = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0;});

    std::cout << "Number of even elements : " << getEven << "\n";

    auto it2 = std::find(v.begin(), v.end(), 2);

    while (it2 != v.end())
    {
        v.erase(it);

        it2 = std::find(v.begin(), v.end(), 2);
    }

    std::cout << "v after deleting no 2 from the list : ";

    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

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


    return 0;
}