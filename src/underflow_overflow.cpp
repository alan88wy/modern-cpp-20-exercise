#include <iostream>

using namespace std;

int main() {
      

    // Integers in C++ are allocated with a certain number of bits. If an integer value, takes more bits than the 
    // allocated number of bits, then we may encounter an overflow or underflow.
    //
    // The integer overflow occurs when a number is greater than the maximum value the data type can hold.
    // The integer underflow occurs when a number is smaller than the minimum value the data type can hold. 
    // We deal mainly with these data types to store integers in C++. These are:
    //
    // signed int: The signed int data type ranges between -2,147,483,648 to 2,147,483,647 (-109 to 109).
    // unsigned int: The unsigned int data type ranges between 0 to 4,294,967,295.
    // long long: The long long data type ranges between -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (-1018 to 1018).
    //
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

    unsigned char a{0};

    cout << "char a : " << static_cast<unsigned int>(a) << "; ";
    --a;
    cout << "--a : " << static_cast<unsigned int>(a) << endl; // This will underflow and gives you 255

    unsigned int b{0};
    cout << "b : " << static_cast<unsigned int>(b) << "; "; 
    b--;
    cout << "b-- : " << static_cast<unsigned int>(b) << endl; // returns 4,294,967,295

    unsigned int c{4294967295};
    cout << "c : " << static_cast<unsigned int>(c) << "; ";
    c++;
    cout << "c++ : " << static_cast<unsigned int>(c) << endl;  // returns 0

    return 0;

}