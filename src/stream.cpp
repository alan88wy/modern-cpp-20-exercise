#include <iostream>

int main()
{

    const char* my_str { "Hello World!" };

    std::cout.write(my_str, strlen(my_str));
   

    return 0;
}