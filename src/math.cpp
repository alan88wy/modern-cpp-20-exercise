#include <iostream>
// #include <cmath>
#include <iomanip>
#include <numbers>

using namespace std;

int main() {

    double a = exp(3);

    cout << "exp(3) : " << a << endl;

    double b = log(54.59);

    cout << "log(54.59) : " << b << endl;

    double c = log10(10000);

    cout << "log10(10000) : " << c << endl;

    cout << fixed << setprecision(30);
    cout << "pi : " << numbers::pi << endl;
    cout << "ln10 : " << numbers::ln10 << endl;
    cout << "log2e : " << numbers::log2e << endl;
    cout << "e : " << numbers::e << endl;
    cout << "egamma : " << numbers::egamma << endl;
    cout << setprecision(0);
    cout << "pow(3,2) : " << pow(3,2) << endl;

    return 0;
}