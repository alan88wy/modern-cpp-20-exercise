#include <iostream>
#include <string>

/*
➤ boolalpha and noboolalpha: If boolalpha is used, the string false will be interpreted as the 
   Boolean value false; anything else will be treated as the Boolean value true. If noboolalpha 
   is set, zero will be interpreted as false, anything else as true. The default is noboolalpha.
➤ dec, hex, and oct: Reads numbers in decimal base 10, hexadecimal, or octal notation, respectively. 
   For example, the decimal base 10 number 207 is cf in hexadecimal, and 317 in octal notation.
➤ skipws and noskipws: Tells the stream to either skip whitespace when tokenizing or to read in 
   whitespace as its own token. The default is skipws.
➤ ws: A handy manipulator that simply skips over the current series of whitespace at the current 
   position in the stream.
➤ get_money: A parameterized manipulator that reads a monetary value from a stream. 
➤ get_time: A parameterized manipulator that reads a formatted time from a stream. 
➤ quoted: A parameterized manipulator that reads a string enclosed with quotes and in which 
   embedded quotes are escaped.
*/

using namespace std;

int main()
{
    cin.imbue(locale(""));

    int i;

    cout << "Enter a number: ";
    cin >> i;
    cout << "You have entered: " << i << endl;

    return 0;
}