#include <iostream>
#include <print>
#include <vector>
#include <tuple>

int main()
{

    std::cout << std::format("There are {} ways I can kick your butt!\n", 100);

    std::println("Go ahead, make my day");

    std::print("{},你好！\n\n", "世界");

    /*
     * Format Specifier
     *
     * [[fill]align][sign][#][0][width][.precision][L][type]
     * 
     * The type specifies the type a given value must be formatted in. There are several options:
     *
     * ➤ Integer types: b (binary), B (binary, but with 0B instead of 0b if # is specified), d (decimal), o (octal), 
     *    x (hexadecimal with lowercase a, b, c, d, e, f), X (hexadecimal with uppercase A, B, C, D, E, F, and if # is specified, 
     *    with 0X instead of 0x). If type is unspecified, d is used for integer types.
     * ➤ Floating-­point types: The following floating-­point formats are supported. The result of scientific, fixed, general, 
     *    and hexadecimal formatting is the same as discussed earlier in this chapter for std::chars_format::scientific, 
     *    fixed, general, and hex. ➤ e, E: Scientific notation with either small e or capital E as the representation of the 
     *    exponent, formatted with either a given precision or 6 if no precision is specified.
     *      ➤ f, F: Fixed notation formatted with either a given precision or 6 if no precision is specified.
     *      ➤ g, G: General notation automatically chooses a representation without an exponent (fixed format) or with 
     *         an exponent (small e or capital E), formatted with either a given precision or 6 if no precision is specified.
     *      ➤ a, A: Hexadecimal notation with either lowercase letters (a) or uppercase letters (A) ➤ If type is unspecified, 
     *         g is used for floating-­point types. 
     * ➤ Booleans: s (outputs true or false in textual form), b, B, c, d, o, x, X (outputs 1 or 0 in integer form). If type is 
     *    unspecified, s is used for Boolean types.
     * ➤ Characters: c (character is copied to output), ? (escaped character is copied to output; see section 
     *    “Formatting Escaped Characters and Strings”), b, B, d, o, x, X (integer representation). If type is unspecified, 
     *    c is used for character types.
     * ➤ String: s (string is copied to output), ? (escaped string is copied to output; see section “Formatting Escaped 
     *    Characters and Strings”). If type is unspecified, s is used for string types.
     * ➤ Pointers: p (hexadecimal notation of the pointer prefixed with 0x). If type is unspecified, p is used for 
     *    pointer types. Only pointers of type void* can be formatted. Other pointer types must first be converted to 
     *    type void*, for example using static_cast<void*>(myPointer).
    */


    int i { 42 };

    // Width
    std::println("Width: ");
    std::println("|{:5}|", i);
    std::println("|{:{}}|", i, 7);     // print i, space = 7
    std::println("|{1:{0}}|", 7, i);

    // [fill]align
    std::println("\n[fill]align: ");
    std::println("|{:8}|", i);
    std::println("|{:<8}|", i);     // Left Align
    std::println("|{:_>8}|", i);    // Right Align
    std::println("|{:_^8}|", i);    // Center
    std::println();

    std::println("Output * by 16 times : ");
    std::println("|{:*>16}|", "");    // Center
    std::println();

    std::println("Sign: ");
    std::println("|{:8}|", i);
    std::println("|{:<8}|", i);     // Left Align
    std::println("|{:<+8}|", i);     // Left Align
    std::println("|{:< 8}|", i);     // Left Align
    std::println("|{:< 8}|", -i);    
    std::println();


    std::println("Type: ");
    std::println("|{:10d}|", i);
    std::println("|{:10b}|", i);     // Left Align
    std::println("|{:#10b}|", i);     // Left Align
    std::println("|{:10X}|", i);     // Left Align
    std::println("|{:#10X}|", i);    
    std::println();

    // Precision
    double j {3.14159 / 2.3 };
    std::println("Precision: ");
    std::println("|{:12g}|", j);
    std::println("|{:12.2}|", j);     // Left Align
    std::println("|{:12e}|", j);     // Left Align

    // Precision using parameters
    int width { 12 };
    int precision { 3 };
    std::println("Precision with parameter: ");
    std::println("|{2: {0}.{1}f}|", width, precision, j);
    std::println("|{2: {0}.{1}}|", width, precision, j);

    // insert zero
    std::println("Insert Zero: ");
    std::println("|{:06d}|", width);
    std::println("|{:+06X}|", width); // with Sign
    std::println("|{:+#06X}|", width); // with Sign

    // Local - L
    std::println("Locale: ");
    float f { 1.2f };
    std::cout << std::format(std::locale{ "nl" }, "|{:Lg}|\n", f); // |1,2|

    /*
     * Formatting Ranges
     *
     * [[fill]align][width][n][range-­type][:range-­underlying-­spec]
     * 
     * m  - Available only for pairs and tuples with two elements. By default, these are surrounded by parentheses 
     *      and separated by commas. If m is specified, they are not surrounded by any type of brackets, and the two 
     *      elements are separated by ": ".
     * s  - Formats the range as a string (cannot be combined with n or a range-­underlying-­spec).
     * ?s - Formats the range as an escaped string (cannot be combined with n or a range-­underlying-­spec).
    */

    std::vector<int> v { 1,3,4,5};
    std::println("Print vector : ");
    // std::println("{}", v);
    // std::println("{:n}", v);
    // std::println("{{{:n}}}", v);

    std::vector chars { 'W', 'o', 'r', 'l', 'd', '\t', '!' }; 
    // std::println("{}", chars);
    // ['W', 'o', 'r', 'l', 'd', '\t', '!']
    // std::println("{::#x}", chars); 
    // std::println("{:s}", chars); 
    // std::println("{:?s}", chars);
    // [0x57, 0x6f, 0x72, 0x6c, 0x64, 0x9, 0x21] // World ! // "World\t!"

    return 0;
}