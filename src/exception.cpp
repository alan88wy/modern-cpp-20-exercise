#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    // Throw and catch integer exception. If string exception, it will go to string exception below
    try
    {
        std::cout << "Trying and then throw exception 124\n";
        throw 124;
    }
    catch (int e)
    {
        std::cout << "Integer exception raised with a value of " << e << "\n";
    }
    catch (std::string &e)
    {
        std::cout << "String exception raised with a value of " << e << "\n";
    };

    // Throw and catch string exception
    try
    {
        std::cout << "Trying and then throw exception 124\n";
        throw std::string("Alamak");
    }
    catch (std::string &e)
    {
        std::cout << "String exception raised with a value of " << e << "\n";
    };

    return 1;
}