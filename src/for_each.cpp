#include <iostream>
#include <vector>
#include <algorithm>

void print(const int s) { std::cout << s << ' '; }

struct Accum
{
    void operator()(int n) { sum += n; };
    int sum {0};
};

int main()
{
    std::vector<int> l = {1,2,3,4,5,6,7,8};

    std::for_each(l.cbegin(), l.cend(), print);
    std::cout << "\n";

    // in place n*2
    std::for_each(l.begin(), l.end(), [](int &n) { n*=2;});

    std::for_each(l.cbegin(), l.cend(), print);

    std::cout << "\n";

    Accum s = std::for_each(l.cbegin(), l.cend(), Accum());
    std::cout << "Total : " << s.sum << '\n';

    return 0;
}