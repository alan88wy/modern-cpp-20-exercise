#include <iostream>

using namespace std;

int main() {
    double i {24.9};

    int j = static_cast<int>(i);

    cout << i << " " << j << endl;

    unsigned char char_var {55};

    ++char_var;

    cout << "char_var : " << static_cast<int>(char_var) << endl;  // return 55

    

    // Below will not work. It will gives:
    // conversion from 'int' to 'unsigned char' requires a narrowing conversion
    //
    // unsigned char c4 {-1};

    // cout << "c4 : " << static_cast<int>(c4) << endl; 
    //
    // unsigned char c1 {3};
    // unsigned char c2 {4};

    // unsigned char c3 { c1 + c2 }; 

    // cout  << "c3 : " << static_cast<int>(c3) << endl;

    return 0;
}