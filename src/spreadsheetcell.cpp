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

export class SpreadsheetCell {
    public:
        inline void setValue(double value); 
        inline double getValue() const;
        // void setString(std::string_view value); 
        // std::string getString() const;

    private: 
        // std::string doubleToString(double value) const; 
        // double stringToDouble(std::string_view value) const;
        double m_value { 0.00 }; 
};

inline void SpreadsheetCell::setValue(double value) 
{ 
     m_value = value;
};

inline double SpreadsheetCell::getValue() const 
{ 
    return m_value; 
};

// void SpreadsheetCell::setString(std::string_view value)
// {
//     m_value = doubleToString(value);
// }

// string SpreadsheetCell::getString() const
// {
//     return doubleToString(m_value);
// }

// string SpreadsheetCell::doubleToString(double value) const
// {
//     return to_string(value);
// }
// double SpreadsheetCell::stringToDouble(std::string_view value) const
// {
//     double number { 0 };
//     from_chars(value.data(), value.date() + value.size(), number);
//     return number;
// }
