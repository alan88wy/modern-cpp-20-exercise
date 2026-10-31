/*
 * A span does not own a vector or an array it references. However, it can change the value of the elements.
*/

#include <iostream>
#include <vector>
#include <span>

int main()
{

    std::vector<int> v {1,5,3,2,6,7};
    std::span<int> s = v;

    std::cout << "Original -> ";

    for (auto i: v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    std::cout << "Change s[1] = 10 -> ";

    s[1] = 10;

    for (auto i: v)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    int arr[5] = {1,2,3,4,5};

    std::cout << "Original arr -> ";
    
    for (auto i: arr)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    std::cout << "After s2[2] = 20 -> ";

    std::span<int, 5> s2 = arr;

    s2[2] = 20;

    for (auto i: arr)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    return 0;
}