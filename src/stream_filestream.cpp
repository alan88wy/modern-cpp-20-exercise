import std;

/*
CONSTANTS:
**********

ios_base::app        - Open, and go to the end before each write operation. 
ios_base::ate        - Open, and go to the end once immediately after opening.
ios_base::binary     - Perform input and output in binary mode as opposed to text mode. 
ios_base::in         - Open for input, start reading at the beginning.
ios_base::out        - Open for output, start writing at the beginning, overwriting existing data.
ios_base::trunc      - Option for out. Delete all existing data (truncate).
ios_base::noreplace  - Option for out. Open in exclusive mode. Open will fail if the file already exists.

Jumping Around with seek() and tell()
*************************************

ios_base::beg        - Beginning of the file.
ios_base::cur        - Current position in the file.
ios_base::end        - End of the file.
ios_base::seekdir    - Used to specify the direction of the seek operation.

*/

using namespace std;

int main(int argc, char* argv[]) {
    
    ofstream outFile { "w1.txt", ios_base::trunc };

    if (!outFile.good()) {
        println(cerr, "Error opening file for writing.");
        return -1;
    }

    outFile << "There were " << argc << " arguments to this program." << endl;
    outFile << "They are : " << endl;

    for (int i = 0; i < argc; ++i) {
        outFile << argv[i] << endl;
    }

    ifstream inFile{"w1.txt", ios_base::in};

    if (!inFile.good()) {
        println(cerr, "Error opening file for reading.");
        return -1;
    }

    string line;

    while (getline(inFile, line)) {
        cout << line << endl; // using cout instead of println
    }

    // Jumping Around with seek() and tell()
    inFile.clear(); // clear EOF flag
    inFile.seekg(0, ios_base::beg); // go to the beginning of the file
    cout << "Current position: " << inFile.tellg() << endl; // should be 0
    inFile.seekg(0, ios_base::end); // go to the end of the file
    cout << "Current position: " << inFile.tellg() << endl; // should be the size of the file
    inFile.seekg(0, ios_base::beg); // go back to the beginning of the file
    cout << "Current position: " << inFile.tellg() << endl; // should be 0
    inFile.seekg(5, ios_base::cur); // go forward 5 bytes from the current position
    cout << "Current position: " << inFile.tellg() << endl; // should be 5
    inFile.seekg(-5, ios_base::cur); // go back 5 bytes from the current position
    cout << "Current position: " << inFile.tellg() << endl; // should be 0
    inFile.seekg(0, ios_base::end); // go to the end of the file
    cout << "Current position: " << inFile.tellg() << endl; // should be the size of the file
    inFile.seekg(-5, ios_base::end); // go back 5 bytes from the end of the file
    cout << "Current position: " << inFile.tellg() << endl; // should be the size of the file - 5
    inFile.seekg(0, ios_base::beg); // go back to the beginning of the file 
    cout << "Current position: " << inFile.tellg() << endl; // should be 0
    inFile.seekg(5, ios_base::beg); // go to the 5th byte from the beginning of the file
    cout << "Current position: " << inFile.tellg() << endl; // should be 5
    inFile.seekg(-5, ios_base::beg); // go back 5 bytes from the beginning of the file
    cout << "Current position: " << inFile.tellg() << endl; // should be -1

    //ad entire file
    inFile.clear(); // clear EOF flag
    inFile.seekg(0, ios_base::beg); // go to the beginning of the file
    string fileContent;
    getline(inFile, fileContent, '\0'); // read until EOF
    cout << "File content -> \n ";
    cout << fileContent << endl; // print the entire file content
    
    return 0;
}