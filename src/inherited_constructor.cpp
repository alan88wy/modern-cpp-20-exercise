#include <iostream>

class Base {
    public: 
        virtual ~Base() = default;
        Base() = default; 
        explicit Base(int i) {}
};
class Derived : public Base {
    public: 
        explicit Derived(int i) : Base(i) {} 
};

class DerivedV2 : public Base {
    public: 
        using Base::Base; 
        explicit DerivedV2(int i) : Base(i) {} 
};

int main()
{

    Base base { 1 };        // OK, calls integer Base constructor.
    Derived derived1 { 2 }; // OK, calls integer Derived constructor. 
// Derived derived2;        // Error, Derived does not have a default constructor.

    DerivedV2 derived2;       // OK, calls inherited default Base constructor.

    return 0;
}