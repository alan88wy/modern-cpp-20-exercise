#include <sstream>
#include <iostream>
#include <print>

using namespace std;

int main() {
    // Create an ostringstream object
    ostringstream oss;
    bool firstLoop { true };

    println("Please enter tokens : ");

    while (cin)
    {
        string nextToken;
        print("Enter token: ");
        cin >> nextToken;

        if (!cin || nextToken == "done") { break; }
        if (!firstLoop) { oss << ", "; } // Add a comma before the next token if it's not the first one
        oss << '"' << nextToken << '"';
        firstLoop = false;
    }

    println("The results is : {}", oss.str());

    return 0;
}