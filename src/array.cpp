#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {

    // srand has to run once per program
    srand(time(0)); // seed for random number generator

    int scores[] {10, 12, 15, 11, 18, 17, 29};

    cout << "Size of array : " << size(scores) << endl; // size is available in C++17 & C++20
    // Old way (before C++17) : sizeof(scores) / sizeof(scores[0]) to get size of array


    cout << static_cast<char>(toupper('a') )<< endl;

    for (unsigned int i = 0; i <= 7; ++i ) {  // random data printed for scores[7]
        cout << scores[i] << endl;
    }

    // Random number
    unsigned int random_no = rand();  // Generate number between 0 and RAND_MAX - 32767

    cout << random_no << endl;
    cout << RAND_MAX << endl;

    // to get random number between 0 and 10

    cout << "10 random number between 1 & 10" << endl;

    for (unsigned int i = 0; i < 10; i++) {
        random_no = rand() % 11 ;
        cout << i << " : " << random_no << endl;
    }

    string prediction[] {
        "a lot of kinds running in the backyard" ,
        "a lot of empty beer bottles on your table.",
        "you partying too much",
        "you running away from something really scary",
        "cloud gathering in the sky",
        "dogs running around in a deserted empty city",
        "a lot of cars",
        "you sitting in the dark",
        "you laughing your lungs out",
        "you yelling at your boss"
    };

    for (unsigned int i = 0; i < 10; i++) {
        random_no = rand() % 10;
        cout << i << " : " << prediction[random_no] << endl;
    }
    
}