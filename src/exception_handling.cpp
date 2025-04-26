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

/*
Standard exceptions
*******************
* logic_error
  - invalid_argument
  - domain_error
  - length_error
  - out_of_range
  - future_error (since C++11)

* runtime_error
  - range_error
  - overflow_error
  - underflow_error
  - regex_error (since C++11)
  - system_error (since C++11)
    # ios_base::failure (since C++11)
    # filesystem::filesystem_error (since C++17)
  - tx_exception (TM TS)
  - nonexistent_local_time (since C++20)
  - ambiguous_local_time (since C++20)
  - format_error (since C++20)
* bad_typeid
* bad_cast
  - bad_any_cast (since C++17)
* bad_optional_access (since C++17)
* bad_expected_access (since C++23)
* bad_weak_ptr (since C++11)
* bad_function_call (since C++11)
* bad_alloc
  - bad_array_new_length (since C++11)
* bad_exception
* ios_base::failure (until C++11)
* bad_variant_access (since C++17)
*/