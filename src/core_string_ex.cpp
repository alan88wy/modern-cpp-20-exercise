#include <iostream>
#include <string>

int main()
{

    std::string a {"Hello World!"};

    std::cout << a << "\n";

    // String Input
    std::string inp {};

    std::cout << "Please input a string : ";

    /*
    We use the std::getline because our string can contain white spaces. 
    And if we used the std::cin function alone, it would accept only a part of the string.
    */
    std::getline(std::cin, inp);

    // std::cin >> inp;

    std::cout << inp << "\n";

    std::cout << inp.c_str() << "\n";  // c_str() - pointer to first element

    std::cout << "Substring from 2-6 : " << inp.substr(2,6) << "\n";

    // Find in string
    std::string s1 = "The fox jumping over the fence";
    std::string::size_type found = s1.find("fox");

    std::cout << "npos : " << std::string::npos << "\n";
    
    if (found != std::string::npos) {
        std::cout << "Foung fox at position " << found << " - " << s1.substr(found, s1.size()) << "\n";
    } else{
        std::cout << "Cannot find string - fox\n";
    }



    return 0;
}