#include <string_view>

class Base {
    public:
        virtual ~Base() = default; 
        Base() = default;
        explicit Base(std::string_view str) {} 
        explicit Base(float f) {}
};
class Derived : public Base {
    public: 
        using Base::Base; 
        explicit Derived(float f) {}     // Hides inherited float Base constructor Base(float f) {}.
};

int main()
{

    Derived derived1 { "Hello" };   // OK, calls inherited string_view Base constructor. 
    Derived derived2 { 1.23f };     // OK, calls float Derived constructor. 
    Derived derived3;               // OK, calls inherited default Base constructor.

    return 0;
}