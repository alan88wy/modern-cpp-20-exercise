import std;

int main()
{
    /*
     * 1. std::ifstream – Read from a file
     * 2. std::ofstream – Write to a file 
     * 3. std::fstream – Read from and write to a file
    */

    // Reading a file and display content
    std::fstream fs {"data.txt"};
    std::string s;

    // Read one line at a time
    while (fs)
    {
        std::getline(fs, s);
        std::cout << s << "\n";
    }

    std::cout << "1*********************************************************************\n";
    // read char at a time
    std::fstream fs2 {"data.txt"};
    char c;

    while (fs2 >> std::noskipws >> c)
    {
        std::cout << c;
    }

    std::cout << "2*********************************************************************\n";

    // using fstream to write to file
    // std::ios::out = write to a file
    // std::ios::app = append to a file
    
    std::fstream fs3 {"w1.txt", std::ios::out};

    fs3 << "First Line \n";
    fs3 << "Second Line \n";
    fs3 << "Third Line \n";

    return 0;
}