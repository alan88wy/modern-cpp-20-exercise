#include <cstdio>

struct Employee {
	public:
		Employee(int id, const char* name, const char* role) 
			: id(id), name(name), role(role) {};
		
		const char* get_name() {
			return this->name;
		};

		const int get_id() {
			return this->id;
		};

		const char* get_role() {
			return this->role;
		};

	private:
		int id;
		const char* name;
		const char* role;
};

int main() {
	Employee joe = { 42, "Joe", "Boss" };

	printf("%s is the %s and has id %d \n", joe.get_name(), joe.get_role(), joe.get_id());

	return 0;
}