#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main(int argc, char **argv) {


	// Output Formatting
	// need to add - #include <iomanip>
	//
	// precision(n) - set the precision of the output
	// std::setw - set width
	// right/left - justification
	// showpos - show positive sign
	// showpoint - Always show decimal point
	// fixed - fix the output format (depending on the precision setting)
	// unsetf(ios::scientific | ios::fixed), example :
    std::cout.setf ( std::ios::hex, std::ios::basefield );  // set hex as the basefield
    std::cout.setf ( std::ios::showbase );                  // activate showbase
    std::cout << 100 << '\n';
    std::cout.unsetf ( std::ios::showbase );                // deactivate showbase

	// ios::scientific - use scientific notation eg 3.14159e+000
	// uppercase/nouppercase - Enables the use of uppercase characters in floating-point and hexadecimal integer output.
	// hex/dec/oct - shows hexadecimal, decimal and octal representation
	// internal - internal justification. Sign is left justified, data is right justified
	//
	cout << internal;  // Result : -      1234567890123
	cout <<  std::setw(20) << -1234567890123 << endl;
	cout <<  std::setw(20) << -1234567823 << endl;

	// Results
	// -      1234567890123
	// -         1234567823

	cout << std::hex << std::showbase;  // Show the output in hexadecimal representation
	cout << uppercase << 0x2a << endl; 	// output : 0X2A


	return 0;
}
