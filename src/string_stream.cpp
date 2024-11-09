/*
* There is a stream that allows us to read from and write to a string. 
* It is defined inside the <sstream> header, and there are three different string streams: 
* 
* 1. std::istringstream – The stream to read from a string 
* 2. std::ostringstream – The stream to write to a string 
* 3. std::stringstream – The stream to both read from and write to a string
*/

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string s = "Hello";

    std::stringstream ss;

    ss << s << " James! Welcome";

    std::cout << ss.str() << "\n";

    std::stringstream so {"1 ABC 985"};

    int i, j;
    std::string k;

    so >> i >> k >> j;

    std::cout << "i = " << i << " j = " << j << " k = " << k << "\n";

    return 0;
}

