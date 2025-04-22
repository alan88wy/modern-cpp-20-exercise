#include <cstdio>

// Function - reference

// Bad design
int & f(int & i) {
	return ++i; // will change i from the called party because we are passing i by reference
}

// Good Design

const int& f2(const int& i) {
	return i; // cannot use ++i here as you cannot change the constance reference
}

int main() {
	int i = 5;
	int& ir = i; //ir reference to i

	ir = 10;

	printf("Value of i is %d\n", i); // Will print 10

	f(i) = 50;  // This change value of return reference

	printf("Value of i is %d\n", i); // Will print 50

	f(i);

	printf("Value of i is %d\n", i); // Will print 51


	return 0;
}