#include <iostream>

template <typename T, typename U>
void func(T t, U u)
{
    std::cout << "First : " << t << "\n";
    std::cout << "Second : " << u << "\n";
}

int main()
{
    int f {3};
    double u {3.345};

    func<int, double>(f, u);

    return 0;
}