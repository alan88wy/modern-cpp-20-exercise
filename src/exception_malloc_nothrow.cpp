
#include <limits>
import std;

using namespace std;

int main() {
    // Your code here

    // Not recommend to use no throw in production.
    // Use the default behaviour instead
    size_t integerCount { numeric_limits<size_t>::max() };

    println("Trying to allocate memory for {} integers for ptr2.", integerCount);

    int* ptr1 { new(nothrow) int[integerCount]};
    
    if (ptr1 == nullptr) 
    {
        auto location { source_location::current() };
        println(cerr, "{}({}): Unable to allocate memory!",
        location.file_name(),
                location.line());
        return 1;
    }

    return 0;
}