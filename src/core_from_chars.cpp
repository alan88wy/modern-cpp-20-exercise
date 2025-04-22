#include <cassert>
#include <charconv>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string_view>
#include <system_error>
 
int main()
{
    for (std::string_view const str : {"1234.00", "15 foo", "bar", " 42", "5000000000"})
    {
        std::cout << "String: " << std::quoted(str) << ". ";
        int result{};

        // ptr & ec is the return type for from_chars called std::from_chars_result
        // ptr - a pointer of type const char*
        // ec - an error code of type std::errc
        // std::from_chars(str.data(), str.data() + str.size(), result, base);
        // where base = 2-36

        auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result, 10);
 
        if (ec == std::errc())
        {
            std::cout << "Result: " << result << ", ptr -> " << std::quoted(ptr) << '\n';
        }
        else if (ec == std::errc::invalid_argument)
            std::cout << "This is not a number.\n";
        else if (ec == std::errc::result_out_of_range)
            std::cout << "This number is larger than an int.\n";
    }
 
    // C++23's constexpr from_char demo / C++26's operator bool() demo:
    auto to_int = [](std::string_view s) -> std::optional<int>
    {
        int value{};
#if __cpp_lib_to_chars >= 202306L
        if (std::from_chars(s.data(), s.data() + s.size(), value))
#else
        if (std::from_chars(s.data(), s.data() + s.size(), value).ec == std::errc{})
#endif
            return value;
        else
            return std::nullopt;
    };
 
    assert(to_int("42") == 42);
    assert(to_int("foo") == std::nullopt);
#if __cpp_lib_constexpr_charconv and __cpp_lib_optional >= 202106
    static_assert(to_int("42") == 42);
    static_assert(to_int("foo") == std::nullopt);
#endif
}