#include <iostream>
#include <optional>
#include <type_traits>
#include <string>
#include <concepts>

using namespace std;

// Constraint to only allow types that support operator+
// c++ 20 only - chatgpt
// template <typename T>
// requires requires(T a, T b) { a + b; }
// optional<T> sum(const T& a, const T& b)
// {
//     return a + b;
// }

// DeepSeek - C++ 20
// C++20 concept to check if T supports operator+
template <typename T>
concept Addable = requires(const T& a, const T& b) {
    { a + b } -> convertible_to<T>;
};

template <typename T>
optional<T> sum(const T& a, const T& b) {
    if constexpr (Addable<T>) {
        return a + b;
    } else {
        return nullopt;
    }
}

// // Helper type trait to check if T has operator+
// // deepseek R1 - Before C++ 20

// template <typename T, typename = void>
// struct has_plus_operator : std::false_type {};

// template <typename T>
// struct has_plus_operator<T, void_t<decltype(declval<T>() + declval<T>())>> : std::true_type {};

// template <typename T>
// inline constexpr bool has_plus_operator_v = has_plus_operator<T>::value;

// template <typename T>
// optional<T> sum(const T& a, const T& b) {
//     if constexpr (has_plus_operator_v<T>) {
//         return a + b;
//     } else {
//         return nullopt;
//     }
// }

// // Not C++ 20 - ChatGPT

// template <typename T>
// auto sum(const T& a, const T& b) -> std::enable_if_t<
//     std::is_same_v<decltype(a + b), T>, optional<T>>
// {
//     return a + b;
// }

// template <typename T>
// auto sum(...) -> optional<T>
// {
//     return nullopt;
// }

int main()
{
    int i { 1 }, j { 2 };

    auto a = sum(i, j);

    if (a) {
        cout << "Sum: " << *a << endl;
    } else {
        cout << "Invalid operation" << endl;
    }

    float x { 2.3f }, y { 3.1f };

    auto b = sum(x, y);

    if (b) {
        cout << "Sum: " << *b << endl;
    } else {
        cout << "Invalid operation" << endl;
    }

    string s1 { "Hello " }, s2 { "World" };

    auto c = sum(s1, s2);

    if (c) {
        cout << "Sum: " << *c << endl;
    } else {
        cout << "Invalid operation" << endl;
    }


    return 0;
}