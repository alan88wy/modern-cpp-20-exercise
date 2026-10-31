#include <fstream>
#include <iostream>
#include <string>
#include <print>
 
int main()
{
    std::ofstream file("file_io_01.txt");

    // Check if file opened successfully
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file for writing \n";
    }

    // Write some data to the file
    file << "Hello, World!" << std::endl;
    file << "Writing first line" << std::endl;
    file << "Writing second line" << std::endl;

    // Can also do this
    std::print(file, "Writing third line");

    // Close the file
    file.close();

    // 2. Open the file (automatically done via constructor)
    std::ifstream inputFile("file_io_01.txt");

    // Check if the file successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::println("Print word by word:\n");

    std::string word;
    // 3. Read data (stops at whitespace)
    // word by word
    while (inputFile >> word) {
        std::cout << word << " ";
    }


    // Another example of word by word reading
    // int age;
    // double salary;
    // // Reads an integer followed by a double from the file
    // if (inputFile >> age >> salary) {
    //     // Process data
    // }

    // Rewind to beginning of the file to read again
    // 1. Clear error flags (like EOF) if you've already read to the end
    inputFile.clear();

    // 2. Move the read pointer back to the 0th byte from the beginning
    inputFile.seekg(0, std::ios::beg);

    // line by line
    std::println("");
    std::println("Print line by line:\n");
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << "\n";
    }

    // Rewind to beginning of the file to read again
    // 1. Clear error flags (like EOF) if you've already read to the end
    inputFile.clear();

    // 2. Move the read pointer back to the 0th byte from the beginning
    inputFile.seekg(0, std::ios::beg);
    // character by character

    std::println("");
    std::println("Print character by character:\n");
    char ch;
    while (inputFile.get(ch)) {
        std::cout << ch;
    }

    // The file automatically closes when inputFile goes out of scope, 
    // but you can close it explicitly:
    inputFile.close(); 

    return 0;
}
