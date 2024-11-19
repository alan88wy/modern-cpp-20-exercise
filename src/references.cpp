#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

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

    int a = 19;
    int b = 18;

    cout << "before swap : a = " << a << " b = " << b << "\n";
    swap(a, b);
    cout << "after swap : a = " << a << " b = " << b << "\n";

    vector<int> v {1,2,3,4};

    // Modify vector

    cout << "Before multiple by 2 -> ";

    for (auto i : v) {
        cout << i <<  " ";
    }

    cout << "\n";

    for (auto& i : v)
    {
        i *= 2;
    }

    cout << "After multiple by 2 -> ";
    
    for (auto i : v) {
        cout << i <<  " ";
    }

    return 0;
}