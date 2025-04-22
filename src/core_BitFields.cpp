#include <cstdio>

struct Prefs {
	bool likesMusic : 1;  // No of bits to use - 1
	bool hasHair : 1; // No of bits to use - 1
	bool hasDinosaur : 1;  // No of bits to use - 1
	bool hasInternet : 1;  // No of bits to use - 1
	unsigned int numberOfChildren : 4;  // No of bits to use - 4
};

int main() {
	Prefs homer;

	homer.likesMusic = true;
	homer.hasHair - false;
	homer.hasInternet = true;
	homer.hasDinosaur - false;
	homer.numberOfChildren = 3;

	printf("sizeof homer: %zd bits\n", sizeof(homer) * 8);
	printf("sizeof int : %zd bits\n", sizeof(int) * 8);

	if (homer.likesMusic) printf("Homer likes music\n");
	if (homer.hasHair) printf("Homer has hair\n");
	if (homer.hasInternet) printf("Homer has the Net\n");
	if (homer.hasDinosaur) printf("Homer has a Dino\n");
	printf("Homer has %d Children\n", homer.numberOfChildren);

	return 0;

}