#include <source_location>

import std;

using namespace std;

void logMessage(string_view message, const source_location& location = source_location::current())
{
    println("{}({}): {}: {}", location.file_name(), location.line(), location.function_name(), message); 
}

void foo()
{
    logMessage("Starting execution of foo().");
}

int main() {
   
    const std::source_location& location = std::source_location::current();

    cout << "File name (__FILE__): " <<  __FILE__ << endl;
    cout << "File name (location.filename()): " <<  location.file_name() << endl;
    cout << "File name (location.function_name()): " <<  location.function_name() << endl;
    cout << "Line number (__LINE__): " <<  __LINE__ << endl;
    // cout << "Line number (location.line()): " <<  location.line() << endl;
    cout << "Column number (location.column()): " <<  location.column() << endl
    << "Line number (location.line()): " <<  location.line() << endl;

    foo();\
    
    return 0;
}