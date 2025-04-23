#include <iostream>
#include <print>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string readName(istream& stream);
void getNameAndAge();
std::string trim(const std::string& s);
string readNamev2(istream& stream);

int main() {

    std::print("Please enter your name : ");

    string myname = readName(cin); // Read name from standard input.

    std::print("Hello, {}!\n", myname); // Correct use of std::print (C++23)

    std::print("Please enter your name : ");

    myname = readNamev2(cin); // Read name from standard input.

    std::print("Hello, {}!\n", myname); // Correct use of std::print (C++23)

    getNameAndAge();

    return 0;
}

string readName(istream& stream) {
    string name;
    
    while (stream) {
        int next = stream.get();
        if (!stream || next == std::char_traits<char>::eof())
            break;
        name += static_cast<char>(next);
    }

    // Remove trailing newline if present
    if (!name.empty() && name.back() == '\n') {
        name.pop_back();
    }

    stream.clear();
    
    return name;
}

void getNameAndAge()
{
    print("Please enter your name and age: ");

    string name;
    int age;

    char ch;

    cin >> noskipws; // Ignore whitespace

    while (cin >> ch) {
        if (isdigit(ch))
        {
            cin.unget();
            if (cin.fail()) {
                println(cerr, "unget() failed.");
            }
            break;
        }

        name += ch;
    }

    // Get Age

    if (cin) { cin >> age; }

    if (!cin) {
        println(cerr, "Error getting age.");
    }

    name = trim(name);

    println("Thank you {}. You are {} years old.", name, age); // Correct use of std::print (C++23)

    cin.clear(); // Clear the error state of cin
}

std::string trim(const std::string& s) {
    auto start = std::find_if_not(s.begin(), s.end(), ::isspace);
    auto end   = std::find_if_not(s.rbegin(), s.rend(), ::isspace).base();

    if (start >= end) return ""; // string was all whitespace
    return std::string(start, end);
}

string readNamev2(istream& stream)
{
    string name;

    while (true) { // Infinite loop to handle all input
        if (!stream) {
            break; // Check for end of stream explicitly
        }

        int next = stream.get();

        if (next == -1) { // EOF condition
            break;
        }
        
        name += static_cast<char>(next); // Append each character
    }

    // Remove trailing newline if present
    if (!name.empty() && name.back() == '\n') {
        name.pop_back();
    }

    stream.clear();

    return name;
}