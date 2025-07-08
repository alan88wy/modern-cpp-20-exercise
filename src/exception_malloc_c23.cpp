
#include <limits>
import std;

using namespace std;

int main() {
    // Your code here
    size_t integerCount { numeric_limits<size_t>::max() };

    // c++23
    int* ptr1 { nullptr };

    println("Trying to allocate memory for {} integers for ptr1.", integerCount);

    try {
        ptr1 = new int[integerCount];
    } catch (const bad_alloc& e) {
        auto location { source_location::current() };
        println(cerr, "{}({}): Unable to allocate memory: {}",
                location.file_name(),
                location.line(),
                e.what());
        return 1;
    }
    

    return 0;
}