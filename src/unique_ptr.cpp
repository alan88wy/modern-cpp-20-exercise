#include <iostream>
#include <memory>

class Base
{
    public:
        Base(int xx): x{xx}
        { 
            std::cout << "Initialized -> " << x << "\n";
        };
        virtual void printMessage(){};
        int x;
};

class DerivedClass: public Base
{
    public:
        DerivedClass(int x): Base(x) {};

        void printMessage() {
            std::cout << "Derived Class : " << x << "\n";
        }
};

int main()
{

    std::unique_ptr<int> m (new int { 10 });

    std::unique_ptr<int> n = std::make_unique<int>(10);  // or a better way

    std::cout << "m Data = " << *m << "\n";

    std::cout << "n Data = " << *n << "\n";

    std::unique_ptr<Base> p = std::make_unique<Base>(123);

    std::cout << "Value of x = " << p->x << "\n";

    std::unique_ptr<Base> q = std::make_unique<DerivedClass>(234);

    q->printMessage();

    // Unique Pointer cannot be copy
    // std::unique_ptr<Base> r = q;


    return 1;
}