import std;

using namespace std;

class FileError: public exception 
{
public:
    explicit FileError(string filename): m_filename { move(filename) } {}
    const char* what() const noexcept override { return m_message.c_str(); }
    virtual const string& getFilename() const noexcept { return m_filename; }
protected:
    virtual void setMessage(string message) { m_message = move(message); }
private:
    string m_filename;
    string m_message;

};

class FileOpenError: public FileError 
{
public:
    explicit FileOpenError(string filename): FileError { move(filename) }
    {
        setMessage(format("Unable to open '{}'.", getFilename()));
    }
};

class FileReadError: public FileError 
{
public:
    explicit FileReadError(string filename, size_t lineNumber): 
        FileError { move(filename) }, m_lineNumber { lineNumber }
    {
        setMessage(format("Error reading '{} at l'i'ne {}.", getFilename(), lineNumber));
    }
    
    virtual size_t getLineNumber() const noexcept { return m_lineNumber; }
private:
    size_t m_lineNumber { 0 };
};

vector<int> readIntegerFile(const string& filename)
{
    ifstream file { filename };
    if (file.fail()) {
        throw FileOpenError { filename };
    }
    
    vector<int> result;
    
    size_t lineNumber { 0 };
    
    while (!file.eof())
    {
        // Read one line from the file
        string line;
        getline(file, line);
        ++lineNumber;

        // create a string stream from the line
        istringstream lineStream { line};

        // Read the integers one bu one and add them to the vector
        int temp;

        while (lineStream >> temp) {
            result.push_back(temp);
        }
        
        if (!lineStream.eof())
        {
            // We did not reach the end of the string stream
            throw FileReadError { filename, lineNumber };
        }

    }
    
    return result;
};

int main() 
{
    const string filename = "numbers.txt";

    try {
        auto result = readIntegerFile(filename);
    } catch (const FileError& e) {
        cout << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cout << "Unknown error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}