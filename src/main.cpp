#include <string>
#include <iostream>

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

	int i {20};
	int j {30};
	int k { i + j };

	cout << i << " + " << j << " = " << k << endl;

	return 0;
}
