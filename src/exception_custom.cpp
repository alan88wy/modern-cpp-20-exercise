#include <iostream>

class MyCustomException : public std::exception
{
    public:
        const char * message() 
        {
            return "My custom exception!";
        }
};

class MyCustomExceptionWithMessage : public std::exception
{
    private:
        const char * msg;
    public:

        MyCustomExceptionWithMessage(const char * msg):msg(msg) {};

        const char * message() 
        {
            return msg;
        }
};

int main()
{

    try
    {
        throw MyCustomException();
    }
    catch(MyCustomException e)
    {
        std::cout << e.message() << '\n';
    }

    try
    {
        throw MyCustomExceptionWithMessage("My custom exception with message!");
    }
    catch(MyCustomExceptionWithMessage e)
    {
        std::cout << e.message() << '\n';
    }
    
    

    return 0;
}