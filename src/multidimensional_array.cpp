#include <iostream>
#include <vector>
#include <array>

// An alias template for a two-dimensional std::array
template <typename T, std::size_t Row, std::size_t Col>
using MultiArray = std::array<std::array<T, Col>, Row>;


int main()
{
    std::array<std::array<int, 3>, 100> m = {{1,2,3}};

    std::cout << "[" << m[0][0] << "," << m[0][1] << "," << m[0][2] << "]\n";

    MultiArray<int, 3, 10> n = {{4,5,6}};

    std::cout << "[" << n[0][0] << "," << n[0][1] << "," << n[0][2] << "]\n";

    MultiArray<int, 4, 200> n2;
    
    n2[0] = {1,2,3,4};
    n2[1] = {2,3,4,5};

    // Problem with this is we cannot restrict no of columns

    std::vector<std::vector<int>> mArray = {{1,2,3,4}, {2,3,4,5}};

    std::cout << "[" << mArray[0][0] << "," << mArray[0][1] << "," << mArray[0][2] << "," << mArray[0][3] << "]\n";
    std::cout << "[" << mArray[1][0] << "," << mArray[1][1] << "," << mArray[1][2] << "," << mArray[1][3] << "]\n";

    return 0;
}