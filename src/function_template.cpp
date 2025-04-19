#include <iostream>
#include <optional>
#include <type_traits>

using namespace std;

template <typename T>
optional<T> sum(const T& a, const T& b)
{
    if constexpr (std::is_arithmetic_v<T>) {
        return a + b;
    } else {
        return nullopt;
    }
}

int main()
{
    int i { 1 }, j { 2 };

    optional<int> a = sum(i, j);

    if (a) {
        cout << "Sum: " << *a << endl;
    } else {
        cout << "Invalid operation" << endl;
    }

    float x { 2.3f }, y { 3.1f };

    optional<float> b = sum(x, y);

    if (b) {
        cout << "Sum: " << *b << endl;
    } else {
        cout << "Invalid operation" << endl;
    }

    return 0;
}