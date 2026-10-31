// Global Module Fragment is used to include headers when 
// importing the headers is not possible.
//
// to compile:
//
// g++ -std=c++20 -c .\SpreadsheetCell.cpp -fmodules-ts -o spreadsheetcell.o
//
// Example:
// g++ -std=c++20 -c module_tmpl.cpp -fmodules-ts -o module_tmpl.o
// g++ -std=c++20 -c main.cpp -fmodules-ts -o main.o
//  g++ -std=c++20 main.o module_tmpl.o -o program
// ./program

import spreadsheetcell;

#include <iostream>

int main()
{

    SpreadsheetCell sp;

    sp.setValue(3.24);

    std::cout << "Hello World! -> " << sp.getValue() << "\n";
    return 0;
}
