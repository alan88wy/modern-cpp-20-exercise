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

        Functions
            Copying:
                memcpy	Copy block of memory (function)
                memmove	Move block of memory (function)
                strcpy	Copy string (function)
                strncpy	Copy characters from string (function)

            Concatenation:
                strcat	Concatenate strings (function)
                strncat	Append characters from string (function)

            Comparison:
                memcmp	Compare two blocks of memory (function)
                strcmp	Compare two strings (function)
                        return value	indicates
                        ============    =================================================================================
                        <0	            the first character that does not match has a lower value in ptr1 than in ptr2
                        0	            the contents of both strings are equal
                        >0	            the first character that does not match has a greater value in ptr1 than in ptr2

                strcoll	Compare two strings using locale (function)
                strncmp	Compare characters of two strings (function)
                strxfrm	Transform string using locale (function)

            Searching:
                memchr	Locate character in block of memory (function)
                strchr	Locate first occurrence of character in string (function)
                strcspn	Get span until character in string (function)
                strpbrk	Locate characters in string (function)
                strrchr	Locate last occurrence of character in string (function)
                strspn	Get span of character set in string (function)
                strstr	Locate substring (function)
                strtok	Split string into tokens (function)

            Other:
                memset	Fill block of memory (function)
                strerror	Get pointer to error message string (function)
                strlen	Get string length (function)

            Macros
                NULL	Null pointer (macro)

            Types
                size_t	Unsigned integral type (type)

    */

    char str1 [] { "A fox jumping over the fence !"};
    char str2 [] { "Two dog jump over the fence !"};
    char target { 'o' };

    cout << str1 << endl;
    cout << "strlen  : " << strlen(str1) << endl;
    cout << "strcmp  : " << strcmp(str1, str2) << endl;
    cout << "strchr  : " << strchr(str1, target) - str1 + 1 << endl; // return location of first occurrence. 
                                                                     // If remove the (-str + 1), it will return the 
                                                                     // string from that position onwards.
    cout << "strchr  : " << strchr(str1, target) << endl; 
    cout << "strstr  : " << strstr(str1, "fox") << endl;             // Locate "fox" in the string and return string
                                                                     // from that position onwards.

    char * tok;

    /*
        On a first call, the function expects a C string as argument for str, 
        whose first character is used as the starting location to scan for tokens. 
        
        In subsequent calls, the function expects a null pointer and uses the position right 
        after the end of the last token as the new starting location for scanning.
    */
    tok = strtok(str1, " ");

    cout << "strtok  : " << endl;

    while (tok != NULL) {
        cout << tok << endl;

        // Once the terminating null character of str is found in a call to strtok, all subsequent
        // calls to this function (with a null pointer as the first argument) return a null pointer.
        tok = strtok(NULL, " ");
    }

    

    return 0;
}