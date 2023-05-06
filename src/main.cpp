#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

consteval int get_value()
{
    return 5;
}

int main(int argc, char **argv) {

	// cout << "Hello World!" << endl;

	// constexpr int value = get_value();

	// cout << "Value : " << value << endl;

	// string name;
	// int age;
	// cout << "What is your name ? ";
	// getline(cin, name);
	// cout << "What is your age ? ";
	// cin >> age;
	// cout << "Hello " << name << ". You are " << age << " years old!" << endl;

	// Create variables and initialize variables
	// int i {20};
	// int j {30};
	// int k { i + j };

	// cout << i << " + " << j << " = " << k << endl;

	// char a { 'a'};
	// char b {'b'};

	// cout << a << " " << b << endl;

	// Using auto to create variables

	// auto c {'c'};
	// auto d {13.2};
	// auto e {14.5f};

    // c = 'd';

	// cout << c << " " << d << " " << e << endl;

	// Data Operations

	// Modulus operator
	// cout << 33 % 10 << endl;

	// Logical Operators

	// bool a { true };
	// bool b { false };
	// int c { 5 };
	// char d {'d'};

	// cout << boolalpha;   // Output true or false instead of 1 or 0
	// cout << a << " (true) && " << b << "(false) = " << (a && b) << endl;
	// cout << a << " (true) ||  " << b << "(false) = " << (a|| b) << endl;
	// cout << a << " (true) && " << c << "(5) = " << (a && c) << endl;
	// cout << a << " (true) ||  " << c << "(5) = " << (a|| c) << endl;
	// cout << c << " (5) && " << d << "('hello') = " << (c && d) << endl;
	// cout << c << " (5) || " << d << "('hello') = " << (c || d) << endl;

	// Results if boolapha is not set
	// ==============================
	// 1 (true) && 0(false) = 0
	// 1 (true) ||  0(false) = 1
	// 1 (true) && 5(5) = 1
	// 1 (true) ||  5(5) = 1
	// 5 (5) && d('hello') = 1
	// 5 (5) || d('hello') = 1

	// Result if cout << boolalpha is called
	// =====================================
	// true (true) && false(false) = false
	// true (true) ||  false(false) = true
	// true (true) && 5(5) = true
	// true (true) ||  5(5) = true
	// 5 (5) && d('hello') = true
	// 5 (5) || d('hello') = true

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
	// 		std::cout.setf ( std::ios::hex, std::ios::basefield );  // set hex as the basefield
	// 		std::cout.setf ( std::ios::showbase );                  // activate showbase
	// 		std::cout << 100 << '\n';
	// 		std::cout.unsetf ( std::ios::showbase );                // deactivate showbase
	//
	// ios::scientific - use scientific notation eg 3.14159e+000
	// uppercase/nouppercase - Enables the use of uppercase characters in floating-point and hexadecimal integer output.
	// hex/dec/oct - shows hexadecimal, decimal and octal representation
	// internal - internal justification. Sign is left justified, data is right justified
	//
	// cout << internal;  // Result : -      1234567890123
	// cout <<  std::setw(20) << -1234567890123 << endl;
	// cout <<  std::setw(20) << -1234567823 << endl;

	// Results
	// -      1234567890123
	// -         1234567823

	// cout << std::hex << std::showbase;  // Show the output in hexadecimal representation
	// cout << uppercase << 0x2a << endl; 	// output : 0X2A

	// Numeric Limits
	// name		expresses																possible value*
	// ==========  =================================================================       ===============
	// CHAR_BIT	Number of bits in a char object (byte)									8 or greater*
	// SCHAR_MIN	Minimum value for an object of type signed char							-127 (-27+1) or less*
	// SCHAR_MAX	Maximum value for an object of type signed char							127 (27-1) or greater*
	// UCHAR_MAX	Maximum value for an object of type unsigned char						255 (28-1) or greater*
	// CHAR_MIN	Minimum value for an object of type char								either SCHAR_MIN or 0
	// CHAR_MAX	Maximum value for an object of type char								either SCHAR_MAX or UCHAR_MAX
	// MB_LEN_MAX	Maximum number of bytes in a multibyte character, for any locale		1 or greater*
	// SHRT_MIN	Minimum value for an object of type short int							-32767 (-215+1) or less*
	// SHRT_MAX	Maximum value for an object of type short int							32767 (215-1) or greater*
	// USHRT_MAX	Maximum value for an object of type unsigned short int					65535 (216-1) or greater*
	// INT_MIN		Minimum value for an object of type int									-32767 (-215+1) or less*
	// INT_MAX		Maximum value for an object of type int									32767 (215-1) or greater*
	// UINT_MAX	Maximum value for an object of type unsigned int						65535 (216-1) or greater*
	// LONG_MIN	Minimum value for an object of type long int							-2147483647 (-231+1) or less*
	// LONG_MAX	Maximum value for an object of type long int							2147483647 (231-1) or greater*
	// ULONG_MAX	Maximum value for an object of type unsigned long int					4294967295 (232-1) or greater*
	// LLONG_MIN	Minimum value for an object of type long long int						-9223372036854775807 (-263+1) or less*
	// LLONG_MAX	Maximum value for an object of type long long int						9223372036854775807 (263-1) or greater*
	// ULLONG_MAX	Maximum value for an object of type unsigned long long int				18446744073709551615 (264-1) or greater*

	// cout << INT_MAX << endl;



	return 0;
}
