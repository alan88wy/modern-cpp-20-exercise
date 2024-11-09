#include <iostream>

namespace nameSpace1
{
    int x { 10 };
    int y { 20 };
} // namespace nameSpace1

namespace nameSpace2
{
    double i { 10.34};
}

// Nested namespace
namespace A
{
    namespace B
    {
        void func();
    };
};

void A::B::func()
{
    std::cout << "Yoo Hoo! Nested Namespace" << std::endl;
};

int main()
{

    std::cout << "nameSpace1::x > " << nameSpace1::x << std::endl;

    using namespace nameSpace2;

    std::cout << "nameSpace2::i > " << i << std::endl;

    using namespace nameSpace1;
    std::cout << "nameSpace1::y > " << y << std::endl;

    A::B::func();

    return 0;
}