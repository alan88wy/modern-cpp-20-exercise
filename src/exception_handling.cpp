import std;

using namespace std;

double safeDivide(double num, double den)
{
    // Division by zero error handling
	if (den == 0) {
		throw invalid_argument{ "Divide by zero" };
	}
	return num / den;
}

vector<int> readIntegerFile(const string& filename)
{
    // Throw integer file error handling
	ifstream inputStream { filename };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw 5;
	}

	// Read the integers one-by-one and add them to a vector.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}
	return integers;
}

vector<int> readIntegerFilev2(const string& filename)
{
    // Throw const* char String error handling
	ifstream inputStream { filename };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw "Unable to open file";
	}

	// Read the integers one-by-one and add them to a vector.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}
	return integers;
}

int main()
{
	try {
		println("{}", safeDivide(5, 2));
		println("{}", safeDivide(10, 0));
		println("{}", safeDivide(3, 3));
	} catch (const invalid_argument& e) {
		println("Caught exception: {}", e.what());
	}

    const string filename{ "IntegerFile.txt" };
	vector<int> myInts;

	try {
		myInts = readIntegerFile(filename);
	} catch (int e) {
		println(cerr, "Unable to open file {} (Error Code {})", filename, e);
		return 1;
	}

	println("{} ", myInts);

    // const string filename{ "IntegerFile.txt" };
	// vector<int> myInts;

	try {
		myInts = readIntegerFilev2(filename);
	} catch (const char* e) {
		println(cerr, "{}", e);
		return 1;
	}

	println("{} ", myInts);
}