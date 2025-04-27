import std;

using namespace std;

/*
Each class in the exception hierarchy supports a what() member function 
that returns a const char* string describing the exception. You can use 
this string in an error message.
*/

vector<int> readIntegerFile(const string& filename)
{
	ifstream inputStream { filename };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
        // Setting the what() - error string using std::format
        // std::format("{}.", filename)

		const string error{ format("Unable to open file {}.", filename) };
		throw invalid_argument{ error };
	}

	// Read the integers one-by-one and add them to a vector.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}

	if (!inputStream.eof()) {
		// We did not reach the end-of-file.
		// This means that some error occurred while reading the file.
		// Throw an exception.
        // Setting the what() - error string.
		const string error{ format("Unable to read file {}.", filename) };
		throw runtime_error{ error };
	}

	return integers;
}

int main()
{
	const string filename{ "IntegerFile.txt" };
	vector<int> myInts;

	try {
		myInts = readIntegerFile(filename);
	} catch (const invalid_argument& e) {
		println(cerr, "{}", e.what());
		return 1;
	} catch (const runtime_error& e) {
		println(cerr, "{}", e.what());
		return 2;
	}

	println("{} ", myInts);
    
}
