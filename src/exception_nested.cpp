import std;

using namespace std;

class MyException: public exception
{
    public:
        explicit MyException(string message): m_message { move(message) } {}
        const char* what() const noexcept override { return m_message.c_str(); }
    private:
        string m_message;
};

void doSomething()
{
    try {
        throw runtime_error { "A runtime_error exception" };
    } catch (const runtime_error& e) 
    {
        println("doSomething() caught {}", e.what());
        println("doSomething() throwing MyException");
        throw_with_nested<MyException>(
            MyException {"MyException with nested runtime_error"}
        );
    }
    
}

int main()
{
    try
    {
        doSomething();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    };;
}