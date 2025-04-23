#include <iostream>

using namespace std;

// Custom manipulator to print a message
auto tab1 = [](ostream& os) -> ostream& {
    os << "<-\t ->";
    return os;
};

ostream& tab2(ostream& stream) { return stream << '\t'; }

int main() {
    

    // Use the custom manipulator with cout
    cout << "Test1" << tab1 << "!" << endl;
    cout << "Test2" << tab2 << "!" << endl;

    return 0;
    
}