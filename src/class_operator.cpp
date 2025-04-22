#include <iostream>

class Base
{
    public:
        void operator()()
        {
            std::cout << "Object Called!\n";
        }

        void operator()(int x)
        {
            std::cout << "Object Called with integer -> " << x << "\n";
        }
};

int main()
{
    Base c;
    c();
    c(5);

    return 0;
}