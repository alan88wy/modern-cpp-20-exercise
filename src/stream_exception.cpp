#include <fstream>
#include <iostream>

import std;

using namespace std;
 
int main()
{
    cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
	
    try {
		cout << "Hello World." << endl;
	} catch (const ios_base::failure& ex) {
		cerr << "Caught exception: " << ex.what()
			<< ", error code = " << ex.code() << endl;
	}

    std::ifstream f("doesn't exist");
 
    try
    {
        f.exceptions(f.failbit);
    }
    catch (const std::ios_base::failure& e)
    {
        std::cout << "Caught an ios_base::failure.\n"
                  << "Explanatory string: " << e.what() << '\n'
                  << "Error code: " << e.code() << '\n';
    }
}