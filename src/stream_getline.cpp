#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Please enter your name and then type @ to end: ";
    string name;
    
    getline(cin, name, '@');
    
    // Check if we got a valid name (i.e., not empty)
    if (!name.empty()) {
        cout << "Your name is: " << name << endl;
    } else {
        cout << "No name provided. Please enter your name followed by @." << endl;
    }
    
    return 0;
}