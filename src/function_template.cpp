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
// optional<T> add(const T& a, const T& b)
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
optional<T> add(const T& a, const T& b) {
    if constexpr (Addable<T>) {
        return a + b;
    } else {
        return nullopt;
    }
}

template <typename T>
concept Deletable = requires(const T& a, const T& b) {
    { a - b } -> convertible_to<T>;
};

template <typename T>
optional<T> del(const T& a, const T& b) {
    if constexpr (Deletable<T>) {
        return a - b;
    } else {
        return nullopt;
    }
}

template <typename T>
concept Multiplyable = requires(const T& a, const T& b) {
    { a * b } -> convertible_to<T>;
};

template <typename T>
optional<T> mul(const T& a, const T& b) {
    if constexpr (Multiplyable<T>) {
        return a * b;
    } else {
        return nullopt;
    }
}

template <typename T>
concept Divisable = requires(const T& a, const T& b) {
    { a / b } -> convertible_to<T>;
};

template <typename T>
optional<T> div(const T& a, const T& b) {
    if constexpr (Divisable<T>) {
        return a / b;
    } else {
        return nullopt;
    }
}

template <typename T>
concept Modsable = requires(const T& a, const T& b) {
    { a % b } -> convertible_to<T>;
};

template <typename T>
optional<T> mod(const T& a, const T& b) {
    if constexpr (Modsable<T>) {
        return a % b;
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
// optional<T> add(const T& a, const T& b) {
//     if constexpr (has_plus_operator_v<T>) {
//         return a + b;
//     } else {
//         return nullopt;
//     }
// }

// // Not C++ 20 - ChatGPT

// template <typename T>
// auto add(const T& a, const T& b) -> std::enable_if_t<
//     std::is_same_v<decltype(a + b), T>, optional<T>>
// {
//     return a + b;
// }

// template <typename T>
// auto add(...) -> optional<T>
// {
//     return nullopt;
// }

int main()
{
    int i { 1 }, j { 2 };

    auto a = add(i, j);

    if (a) {
        cout << "add: " << *a << endl;
    } else {
        cout << "add: Invalid operation" << endl;
    }

    a = mod(i, j);

    if (a) {
        cout << "Modulus: " << *a << endl;
    } else {
        cout << "Modulus: Invalid operation" << endl;
    }

    float x { 2.3f }, y { 3.1f };

    auto b = add(x, y);

    if (b) {
        cout << "add: " << *b << endl;
    } else {
        cout << "add: Invalid operation" << endl;
    }

    auto d = del(x, y);

    if (d) {
        cout << "del: " << *d << endl;
    } else {
        cout << "del: Invalid operation" << endl;
    }

    d = mul(x, y);

    if (d) {
        cout << "mul: " << *d << endl;
    } else {
        cout << "mul: Invalid operation" << endl;
    }

    d = div(x, y);

    if (d) {
        cout << "div: " << *d << endl;
    } else {
        cout << "div: Invalid operation" << endl;
    }

    d = mod(x, y);

    if (d) {
        cout << "mod : " << *d << endl;
    } else {
        cout << "mod: Invalid operation" << endl;
    }

    string s1 { "Hello " }, s2 { "World" };

    auto c = add(s1, s2);

    if (c) {
        cout << "add: " << *c << endl;
    } else {
        cout << "add: Invalid operation" << endl;
    }

    c = del(s1, s2);

    if (c) {
        cout << "del: " << *c << endl;
    } else {
        cout << "del: Invalid operation" << endl;
    }

    return 0;
}