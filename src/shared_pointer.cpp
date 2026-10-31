#include <iostream>
#include <memory>

class Base
{
    public:
        Base() { std::cout << "Base Initialize \n"; };
        virtual ~Base() { std::cout << "Base Destroyed!\n"; };
        virtual void show_message() { std::cout << "Showing Base class \n"; };
};

class Derived : public Base
{
    public:
        //Derived() override { std::cout << "Derived Initialize! \n"; };
        void show_message() override { std::cout << "Showing Derived class \n"; };
        ~Derived() override { std::cout << "Derived Destroyed\n"; };
};

int main()
{
    std::cout << "Initialize a \n";

    std::shared_ptr<Base> a = std::make_shared<Derived>();
    a->show_message();

    std::cout << "Initialize b and assign a to b \n";
    std::shared_ptr<Base> b = a;
    b->show_message();

    std::cout << "Reset b to Derived class \n";
    // Reset b to Derived
    b.reset(new Derived);

    std::cout << "End of Demo \n";

    return 0;
}