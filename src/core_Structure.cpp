#include <cstdio>

struct Employee {
	int id;
	const char* name;
	const char* role;
};

int main() {
	Employee joe = { 42, "Joe", "Boss" };

	printf("%s is the %s and has id %d \n", joe.name, joe.role, joe.id);

	return 0;
}