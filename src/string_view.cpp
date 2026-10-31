/*
* Copying data can be an expensive operation in terms of CPU usage. Passing substrings as function parameters 
* would require making a copy of substrings. This is a costly operation. The string_view class template is an 
* attempt to rectify that.
*/

#include <iostream>
#include <string>
#include <string_view>

int main(int argc, char* argv[])
{
    std::string s {"The fox jumping over the fence!"};
    std::string_view s_view(s);
    std::string_view the(s.c_str(), 3);

    std::cout << "s_view(s) -> " << s_view << "\n";
    std::cout << "the(s.c_str(), 3) -> " << the << "\n";
    std::cout << "s_view.substr(0, 3) -> " << s_view.substr(0, 3) << "\n";




    return 0;
}