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

export module spreadsheetcell;

import string;
import string_view;

export class SpreadsheetCell {
    public:
        void setValue(double value); 
        double getValue() const;
        void setString(std::string_view value); 
        std::string getString() const;

    private: 
        std::string doubleToString(double value) const; 
        double stringToDouble(std::string_view value) const;
        double m_value { 0.00 }; 
};
