#include <iostream>
#include <print>
#include <iomanip>  

/*

Examples:

➤ boolalpha and noboolalpha: Tells the stream to output bool values as true and false (boolalpha) 
   or 1 and 0 (noboolalpha). The default is noboolalpha.
➤ hex, oct, and dec: Outputs numbers in hexadecimal, octal, and base 10, respectively. 
➤ fixed, scientific, and defaultfloat: Outputs fractional numbers using fixed, scientific, 
   or default formatting, respectively.
➤ setprecision: Sets the number of decimal places that are output for fractional numbers 
   using fixed or scientific formatting, or else the total number of digits to output. 
   This is a parameterized manipulator (meaning that it takes an argument).
➤ setw: Sets the field width for outputting data. This is a parameterized manipulator. 
➤ setfill: Sets a character as the new fill character for the stream. The fill character 
   pads output according to the width set by setw. This is a parameterized manipulator.
➤ showpoint and noshowpoint: Forces the stream to always or never show the decimal point for 
   floating-point numbers with no fractional part.
➤ put_money: A parameterized manipulator that writes a formatted monetary value to a stream.
➤ put_time: A parameterized manipulator that writes a formatted time to a stream. 
➤ quoted: A parameterized manipulator that encloses a given string with quotes and escapes 
   embedded quotes.
*/

using namespace std;

int main() {
    
    bool my_bool { true };
    cout << "This is the default -> " << my_bool << endl; // 1
    cout << "This is true -> " << boolalpha << my_bool << endl; // true
    cout << "This should be 1 -> " << noboolalpha << my_bool << endl; // 1

    // Simulate println-style "{:6}" with streams 
    int i { 123 };
    println("This should be ' 123': {:6}", i); 
    cout << "This should be ' 123': " << setw(6) << i << endl;

    // Simulate println-style "{:0>6}" with streams 
    println("This should be '000123': {:0>6}", i);
    cout << "This should be '000123': " << setfill('0') << setw(6) << i << endl; 
    
    // Fill with *
    cout << "This should be '***123': " << setfill('*') << setw(6) << i << endl; 
    
    // Reset fill character 
    cout << setfill(' ');

    // Floating-point values 
    double dbl { 1.452 }; 
    double dbl2 { 5 };
    cout << "This should be ' 5': " << setw(2) << noshowpoint << dbl2 << endl; 
    cout << "This should be @@1.452: " << setw(7) << setfill('@') << dbl << endl; 
    
    // Reset fill character 
    cout << setfill(' ');

    // Instructs cout to start formatting numbers according to your location. 
    cout.imbue(locale { "" });

    // Format numbers according to your location
    cout << "This is 1234567 formatted according to your location: " << 1234567 << endl;

    // Monetary value. What exactly a monetary value means depends on your 
    // location. For example, in the USA, a monetary value of 120000 means 120000 
    // dollar cents, which is 1200.00 dollars. 
    cout << "This should be a monetary value of 120000, " 
        << "formatted according to your location: " 
        << put_money("120000") << endl;
        
    // Date and time
    time_t t_t { time(nullptr) };     // Get current system time.
    tm t { *localtime(&t_t) };        // Convert to local time.

    cout << "This should be the current date and time " 
         << "formatted according to your location: " 
         << put_time(&t, "%c") << endl;

    // Quoted string
    cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": " 
         << quoted("Quoted string with \"embedded quotes\".") << endl;

    // Instead of doing the above, we can also use this:

    cout << "This should be '1.2346': " << setprecision(5) << 1.23456789 << endl;

    return 0;
}