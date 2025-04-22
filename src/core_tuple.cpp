#include <iostream>
#include <tuple>
#include <string>

int main()
{

    std::tuple<int, std::string, int> tp (1, "fox", 2);

    std::cout << "Tuple -> " << std::get<0>(tp) << " - " << std::get<1>(tp) << " - " << std::get<2>(tp) << "\n";

    return 0;
}