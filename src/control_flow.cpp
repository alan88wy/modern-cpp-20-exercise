#include <iostream>
#include <string>

using namespace std;

int main() {
    switch (1) {
        case 1: {
            cout << "1" << endl;
            
            }
            break;
        default:
            cout << "default" << endl;
            

    }

    int a { 1};
    int b {2};

    string max = (a <b) ? "less than" : "greater than";

    cout << max << endl;

    // use constexpr to increase runtime performance as variable is assigned at compile time
    constexpr int i {3};

    if (constexpr(i)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // if initializer
    bool go {false};

    if (int speed { 20 }; go) {
        if (speed > 5) {
            cout << "Slow Down!" << endl;
        } else {
            cout << "All good!" << endl;
        }
    } else {
        cout << "Speed : " << speed << endl;
        cout << "Stop" << endl;
    }

    // Switch with initializer

    short int ready = 1;
    switch (string name {"James"}; ready) 
    {
        case 1: {
                cout << "Let's go " << name << endl;
                break;
            }
        default: {
            cout << "Let's wait for a while " << name << endl;
            break;
        }

    }

    
}