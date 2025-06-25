#include <cstdio>

struct Employee {
	int id;
	const char* name;
	const char* role;
	const char* get_name() {
		return this->name;
	};
};

int main() {
	Employee joe = { 42, "Joe", "Boss" };

	printf("%s is the %s and has id %d \n", joe.get_name(), joe.role, joe.id);

	return 0;
}