#include <iostream>

using namespace std;

consteval int get_value()
{
    return 5;
}

int main() {
	cout << "Hello World!" << endl;

	constexpr int value = get_value();

	cout << "Value : " << value << endl;

	return 0;
}
