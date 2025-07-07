import std;

using namespace std;

class MyException: public exception
{
    public:
        explicit MyException(string message, source_location location=source_location::current()): 
        m_message { move(message) }, m_location { location }, m_stackTrace { stacktrace::current(1) } // 1 mean skip top frame
        {}
        const char* what() const noexcept override { return m_message.c_str(); }
        virtual const source_location& where() const noexcept { return m_location; }
        virtual const stacktrace& how() const noexcept { return m_stackTrace; }
    private:
        string m_message;
        source_location m_location;
        stacktrace m_stackTrace;
};

void doSomething()
{
    throw MyException("An error occurred in doSomething()");
}

int main()
{
    println(cout, "Starting exception handling example...");

    try
    {
        doSomething();
    }
    catch (const MyException& e)
    {
        // Print exception descrion + location where exception was raised.
        const auto& location { e.where() };
        println(cerr, "Caught: '{}' at line {} in {}.",
        e.what(),
        location.line(),
        location.function_name());

        // Print the stack trace at point where exception was thrown.
        println(cerr, "Stack trace:");
        for (unsigned index { 0 }; auto&& frame: e.how())
        {
            const string& filename { frame.source_file() };
            println(cerr, "    {}> {}, {}({})", index++, frame.description(),
            filename.empty() ? "unknown" : filename, frame.source_line());
        }
    }
    return 0;
}