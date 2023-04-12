#include <iostream>

using namespace std;

// constinit - specify that a variable should be initialized at compile time. New to C++ 20
//           - Must be initialized with const or literals
//           - Note: The variable does not need to be a constant
//           - Must be declare before the main function.
//           - If declare here, it will cause error.
//           - constinit' only allowed on a variable declaration with static or thread storage duration

constinit int age {30};
constexpr int minimum_age {18};

constinit int legal_age { minimum_age }; // This is ok. Minimum_age must be declared as constexpr

const constinit double weight {33.35};

const int val1 {35};  // Run-time constant
// const constinit int age1 { val1 };  // This will fail because val1 is not a compile-time constant

int main() {

    const auto at { 40 };
    cout << at << endl;

    // constexpr - compile time constant.
    constexpr int MAX_DATA = 1000;

    // constexpr int MAX_DAT2 {MAX_DATA + 2} - this will not work because MAX_DATA is not known during compile time.

    cout << MAX_DATA << endl;

    static_assert(MAX_DATA == 1000);   // To check during compile time whether the value is 1000. Compilation will fail if it is not. This is for constant only.
    


    // constinit int age = 30; - this will fail during compile time. Must declare outside.


    cout << "You are " << age << " years old!" << endl;
    cout << "Legal age is " << legal_age << endl;

    legal_age = 16;

    cout << "Legal age is now " << legal_age << endl;

}