#include <string>
#include <iostream>
#include <iomanip>

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
	// std::setw - set width
	// right/left - justification
	// showpos - show positive sign
	// uppercase/nouppercase - Enables the use of uppercase characters in floating-point and hexadecimal integer output.
	// hex/dec/oct - shows hexadecimal, decimal and octal representation
	// internal - internal justification. Sign is left justified, data is right justified
	// cout << internal;  // Result : -      1234567890123
	// cout <<  std::setw(20) << -1234567890123 << endl;
	// cout <<  std::setw(20) << -1234567823 << endl;

	// Results
	// -      1234567890123
	// -         1234567823

	cout << std::hex << std::showbase;
	cout << uppercase << 0x2a << endl; 	// output : 0X2A

	return 0;
}
