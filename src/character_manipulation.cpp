#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char c { 'C' };

    cout << boolalpha << endl;
    cout << "c        : " << c << endl;
    cout << "isalnum  : " << (bool) isalnum(c) << endl;
    cout << "isalpha  : " << (bool) isalpha(c) << endl;
    cout << "isblank  : " << (bool) isblank(c) << endl;
    cout << "iscntrl  : " << (bool) iscntrl(c) << endl;
    cout << "isdigit  : " << (bool) isdigit(c) << endl;
    cout << "isgraph  : " << (bool) isgraph(c) << endl;
    cout << "islower  : " << (bool) islower(c) << endl;
    cout << "isprint  : " << (bool) isprint(c) << endl;
    cout << "ispunct  : " << (bool) ispunct(c) << endl;
    cout << "isspace  : " << (bool) isspace(c) << endl;
    cout << "isupper  : " << (bool) isupper(c) << endl;
    cout << "isxdigit : " << (bool) isxdigit(c) << endl;
    cout << "tolower  : " << (char) tolower(c) << endl;
    cout << "toupper  : " << (char) toupper(c) << endl;

    return 0;
}