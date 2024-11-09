#include <iostream>

class Base
{
    public:
        Base() = default; // default member function
        Base(const Base& the_other) // copy constructor
        {
            std::cout << "Copy Constructor activated\n";
        };
        Base& operator=(Base const& the_other) = delete; // deleted assignment operator

};

int main()
{
    Base a;
    Base b;
    
    // b = a;  - This will fail because we have deleted the assignment operator

    Base c = a; // This is ok as it only invoke copy constructor

    return 0;
}