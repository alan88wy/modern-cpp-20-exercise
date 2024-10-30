#include <iostream>

class Base{
    public:
        virtual void doSomething()
        {
            std::cout << "I am doing Something!\n";
        };
};

// This cannot be instantiate
class PureBase
{
    public:

        virtual void purelyDoSomething() = 0;  // Pure virtual function = interface
        virtual ~PureBase() {};
};

class Ipolymorphic: public Base, public PureBase
{
    public:
        void doSomething()
        {
            std::cout << "I had polymorphic into something else!\n";
        };

        void purelyDoSomething()
        {
            std::cout << "I am build from interface!\n";
        };
};

int main()
{
    Ipolymorphic me;

    me.doSomething();

    me.purelyDoSomething();

    Base myBase;

    myBase.doSomething();

    // PureBase myPureBase;  // This will fail with this error: cannot declare variable 'myPureBase' to be of abstract type 'PureBase'

    return 1;
}

