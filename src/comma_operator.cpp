#include <iostream>

using namespace std;

int main() {
    int increment {5};
    int number1 {10};
    int number2 {20};
    int number3 {25};

    int result = (number1 *= ++increment, number2 - (++increment), number3 += ++increment);

    cout << "Number 1 : " << number1 << endl;  // 60
    cout << "Number 2 : " << number2 << endl;  // 20; no change since the result is not store back to number2
    cout << "Number 3 : " << number3 << endl;  // 33
    cout << "Result : " << result << endl;     // 33

  

    return 0;
}