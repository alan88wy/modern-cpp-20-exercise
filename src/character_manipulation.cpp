#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char c { 'C' };

    /*
        https://en.cppreference.com/w/cpp/header/cctype
    */
    cout << boolalpha << endl;
    cout << "c        : " << c << endl;
    cout << "isalnum  : " << (bool) isalnum(c) << endl;  // checks if a character is alphanumeric
    cout << "isalpha  : " << (bool) isalpha(c) << endl;  // checks if a character is alphabetic
    cout << "isblank  : " << (bool) isblank(c) << endl;  // checks if a character is a blank character
    cout << "iscntrl  : " << (bool) iscntrl(c) << endl;  // checks if a character is a control character
    cout << "isdigit  : " << (bool) isdigit(c) << endl;  // checks if a character is a digit
    cout << "isgraph  : " << (bool) isgraph(c) << endl;  // checks if a character is a graphical character
    cout << "islower  : " << (bool) islower(c) << endl;  // checks if a character is lowercase
    cout << "isprint  : " << (bool) isprint(c) << endl;  // checks if a character is a printing character
    cout << "ispunct  : " << (bool) ispunct(c) << endl;  // checks if a character is a punctuation character
    cout << "isspace  : " << (bool) isspace(c) << endl;  // checks if a character is a space character
    cout << "isupper  : " << (bool) isupper(c) << endl;  // checks if a character is an uppercase character
    cout << "isxdigit : " << (bool) isxdigit(c) << endl; // checks if a character is a hexadecimal character
    cout << "tolower  : " << (char) tolower(c) << endl;  // converts a character to lowercase
    cout << "toupper  : " << (char) toupper(c) << endl;  // converts a character to uppercase

    /*
        String manipulation functions

        https://cplusplus.com/reference/cstring/?kw=cstring

    */

   

    return 0;
}