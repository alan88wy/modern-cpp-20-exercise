#include <iostream>

using namespace std;

int main() {
    int increment {5};
    int number1 {10};
    int number2 {20};
    int number3 {25};

    int result = (number1 *= ++increment, number2 - (++increment), number3 += ++increment);

    cout << "Number 1 : " << number1 << endl;  // 60
    cout << "Number 2 : " << number2 << endl;  // 20; no change since the result is not store back to number2
    cout << "Number 3 : " << number3 << endl;  // 33
    cout << "Result : " << result << endl;     // 33

    unsigned char a{0};

    --a;  // This will underflow and gives you 255

    // The exact behavior on overflow/underflow is only specified for unsigned types.
    // Unsigned integers shall obey the laws of arithmetic modulo 2^n where n is the number of bits in the value
    // representation of that particular size of integer.
    //
    // This implies that unsigned arithmetic does not overflow because a result that cannot be represented by the 
    // resulting unsigned integer type is reduced modulo the number that is one greater than the largest value that 
    // can be represented by the resulting unsigned integer type.

    // For normal signed integer types instead the C++ standard simply says than anything can happen.

    // If during the evaluation of an expression, the result is not mathematically defined or not in the range of 
    // representable values for its type, the behavior is undefined

    cout << "a : " << static_cast<unsigned int>(a) << endl;

    return 0;
}