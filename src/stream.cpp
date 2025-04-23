#include <iostream>

using namespace std;

int main()
{

    const char* my_str { "Hello World!" };

    cout.write(my_str, strlen(my_str));
    cout << endl; // Hello World!
   
    // cout.flush()

    cout << "abc"; 
    cout.flush();   // abc is written to the console. 
    cout << "def"; 
    cout << endl;   // def is written to the console.

    // Handling output error
    // Important to know is that both good() and fail() return false if the end-of-file is reached. 
    // The relation is as follows: good() == (!fail() && !eof()).

    if (cout.good()) {
        cout << "All good" << endl; 
    }

    cout.flush(); 

    if (cout.fail()) {
        cerr << "Unable to flush to standard out" << endl; 
    }

    // Can also write it this way

    cout.flush(); if (!cout) {
        cerr << "Unable to flush to standard out" << endl; 
    }

    // Can also throw an exception
    cout.exceptions(ios::failbit | ios::badbit | ios::eofbit); 

    try {
        cout << "Hello World." << endl; 
    } catch (const ios_base::failure& ex) { 
        cerr << "Caught exception: " << ex.what() << ", error code = " << ex.code() << endl;
    }

    // To reset the error state of a stream, use clear(): 
    cout.clear();

    return 0;
}