#include <iostream>

using namespace std;

int main() {
    double i {24.9};

    int j = static_cast<int>(i);

    cout << i << " " << j << endl;

    return 0;
}