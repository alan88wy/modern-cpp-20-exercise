#include <iostream>

using namespace std;

int main() {
    int val { 20 };

    int &ref_to_val { val };

    cout << "Reference to val (20) : " << ref_to_val << endl;

    ref_to_val = 25;

    cout << "Reference to val (after changing to 25) : " << ref_to_val << endl;

    const int& ref = { val};

    cout << "Reference to val (25): " << ref << endl;

    val = 30;

    cout << "Reference to val (30): " << ref << endl;

    return 0;
}