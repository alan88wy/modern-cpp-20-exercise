#include <iostream>
#include <cstring>
#include <string>

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
                        char * strncpy ( char * destination, const char * source, size_t num );
                        destination
                            Pointer to the destination array where the content is to be copied.
                        source
                            C string to be copied.
                        num
                            Maximum number of characters to be copied from source.
                            size_t is an unsigned integral type.

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
    char str3 [] { " Life's is good !" };
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

    cout << "strcat : " << strcat(str2, str3) << endl;
    char * dest = new char[strlen(str3) + 1];
    dest = strcpy(dest, str3);
    cout << "strcpy : " << dest << endl;
    cout << "strncpy : " << strncpy(dest, str2, strlen(dest)) << endl;

    // Get "the sky is blue" from the sentences below.

    const char src1[] {"will old space the replace"};
    const char src2[] {"sense sky  hit has"};
    const char src3[] {"hello went is get"};
    const char src4[] {"red blue yellow orange"};

    char* result;
    result = new char[20];

    strncpy(result, src1 + 15, 3);
    strncpy(result + 3,src2 + 5, 4 );
    strncpy(result + 7, src3 + 10, 3);

    strncpy(result + 10,src4 + 3, 5 );

    result[15] = '\0';
    cout << "result : " << result << endl << endl;

    /*
        String
        ******

        Member functions
            (constructor)	Construct string object (public member function)
            (destructor)	String destructor (public member function)
            operator=	String assignment (public member function)

        Iterators:
            begin	Return iterator to beginning (public member function)
            end	    Return iterator to end (public member function)
            rbegin	Return reverse iterator to reverse beginning (public member function)
            rend	Return reverse iterator to reverse end (public member function)
            cbegin	Return const_iterator to beginning (public member function)
            cend	Return const_iterator to end (public member function)
            crbegin	Return const_reverse_iterator to reverse beginning (public member function)
            crend	Return const_reverse_iterator to reverse end (public member function)

        Capacity:
            size	        Return length of string (public member function)
            length	        Return length of string (public member function)
            max_size	    Return maximum size of string (public member function)
            resize	        Resize string (public member function)
            capacity	    Return size of allocated storage (public member function)
            reserve	        Request a change in capacity (public member function)
            clear	        Clear string (public member function)
            empty	        Test if string is empty (public member function)
            shrink_to_fit	Shrink to fit (public member function)

        Element access:
            operator[]	    Get character of string (public member function)
            at	            Get character in string (public member function)
            back	        Access last character (public member function)
            front	        Access first character (public member function)

        Modifiers:
            operator+=	    Append to string (public member function)
            append	        Append to string (public member function)
            push_back	    Append character to string (public member function)
            assign	        Assign content to string (public member function)
            insert	        Insert into string (public member function)
            erase	        Erase characters from string (public member function)
            replace	        Replace portion of string (public member function)
            swap	        Swap string values (public member function)
            pop_back	    Delete last character (public member function)

        String operations:
            c_str	            Get C string equivalent (public member function)
        data	                Get string data (public member function)
            get_allocator   	Get allocator (public member function)
            copy        	    Copy sequence of characters from string (public member function)
            find        	    Find content in string (public member function)
            rfind       	    Find last occurrence of content in string (public member function)
            find_first_of   	Find character in string (public member function)
            find_last_of    	Find character in string from the end (public member function)
            find_first_not_of	Find absence of character in string (public member function)
            find_last_not_of	Find non-matching character in string from the end (public member function)
            substr	            Generate substring (public member function)
            compare	            Compare strings (public member function)

        Member constants
            npos	Maximum value for size_t (public static member constant)

        Non-member function overloads
            operator+   	Concatenate strings (function)
        relational          operators	Relational operators for string (function)
            swap	        Exchanges the values of two strings (function)
            operator>>	    Extract string from stream (function)
            operator<<	    Insert string into stream (function)
            getline	        Get line from stream into string (function)
    */
   
    string full_name; // Empty String
    string planet {"Earth. Where the sky is blue"};  // Initialized with string literal
    string preferred_planet {planet}; // Initialized with other string
    string message {"Hello there", 5}; // Initialized with part of string literal
    string weird_message(4, 'e'); // Initialized with multiple copies of a char
    string greeting {"Hello World"};
    string say_hello {greeting, 6, 5}; // Initialize with part of existing string (start at Index 6, take 5 characters)
                                       // result = World
    cout << "String exercise : " << endl << endl;
    cout << "Full Name : " << full_name << endl;
    cout << "Planet : " << planet << endl;
    cout << "Preferred Planet : " << preferred_planet << endl;
    cout << "message : " << message << endl;
    cout << "greeting : " << greeting << endl;
    cout << "Saying Hello : " << say_hello << endl << endl;

    cout << "Concatenate message + say_hello : " << message + " " + say_hello << endl << endl;

    // Using string literals
    cout << "Using string literals :" << endl << endl;
    using namespace string_literals;

    string str5 {"Hello"s + " World!"}; // turn both into strings using the s suffix
    cout << "str5 : " << str5 << endl;

    str5.append(" Welcome.");

    cout << "str5.append(Welcome) : " << str5 << endl;

    // can append multiple character
    str5.append(10, '!');

    cout << "str5.append(! 10 times) : " << str5 << endl;

    // Append substring
    str5.append("Hello World", 0, 5);

    cout << "str5.append('Hello World', 0, 5) : " << str5 << endl;

    cout << "to_string(55) + ' Hello' : " << to_string(55) + " Hello" << endl;

    return 0;
}