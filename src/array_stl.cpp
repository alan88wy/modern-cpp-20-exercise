#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <string_view>

void print_array(const std::array<int, 5>& arr, std::string message) 
{
    std::cout << message << " : ";

    for (int i: arr)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";
};

void print(const int s) { std::cout << s << ' '; }

int main()
{
    std::array<int, 5> arr {1, 7, 3, 6,2};

    print_array(arr, "Initial arr");

    std::cout << "arr size: " << arr.size() << "\n";
    std::cout << "arr.max_size: " << arr.max_size() << "\n";
    std::cout << "total sizeof(arr): " << sizeof(arr) << "\n";

    std::cout << "arr[2] " << arr[2] << " = arr.at(2) " << arr.at(2) << "\n";

    std::sort(arr.begin(), arr.end());

    print_array(arr, "Sorted arr");

    std::array<int, 5> arr1;

    std::copy(arr.cbegin(), arr.cend(), arr1.begin());
 
    std::cout << "Print 'arr1' in direct order using [cbegin, cend):\n";
    std::for_each(arr1.cbegin(), arr1.cend(), print);
 
    std::cout << "\n\nPrint 'arr1' in reverse order using [crbegin, crend):\n";
    std::for_each(arr1.crbegin(), arr1.crend(), print);


    arr.fill(8);

    print_array(arr, "Fill with 8 arr");

    std::array<int, 5> arr2;

    arr2.fill(1);

    print_array(arr2, "Initial arr2");

    arr2.swap(arr);

    print_array(arr, "arr swap with arr2");
    print_array(arr2, "arr2 swap with arr");

    std::cout << "arr empty ? " << ((arr.empty()) ? "True":"False") << "\n";

    return 0;
}

