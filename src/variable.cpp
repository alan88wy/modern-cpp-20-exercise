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
	int i {20};
	int j {30};
	int k { i + j };

	cout << i << " + " << j << " = " << k << endl;

	char a {'a'};
	char b {'b'};

	cout << a << " " << b << endl;

	// signed vs unsigned char
	unsigned char ab { 0 };
	ab--;
	cout << "ab : " << static_cast<int>(ab) << endl;  // return 255 (char has value between 0 - 255)

	signed char ac { 0 };
	ac--;
	cout << "ac : " << static_cast<int>(ac) << endl;  // return -1 since it is signed.

	// Using auto to create variables

	auto c {'c'};
	auto d {13.2};
	auto e {14.5f};

    c = 'd';

	cout << c << " " << d << " " << e << endl;

	// Data Operations

	// Modulus operator
	cout << 33 % 10 << endl;

	// Logical Operators

	bool f { true };
	bool g { false };
	int h { 5 };
	char l {'d'};

	cout << boolalpha;   // Output true or false instead of 1 or 0
	cout << f << "  && " << g << " = " << (f && g) << endl;
	cout << f << "  ||  " << g << " = " << (f || g) << endl;
	cout << f << "  && " << h << " = " << (f && h) << endl;
	cout << f << "  ||  " << h << " = " << (f || h) << endl;
	cout << h << "  && " << l << " = " << (h && l) << endl;
	cout << h << "  || " << l << " = " << (h || l) << endl;
    cout << h << "  || " << g << " = " << (h || g) << endl;

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





	return 0;
}
