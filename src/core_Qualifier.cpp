#include <cstdio>

class S {
	public:
		int static_value() {
			static int i = 7;

			return ++i;
		}
};

int func() {
	static int i = 7;
	return ++i;
}

int main() {

	printf("Value of Func is %d\n", func());
	printf("Value of Func is %d\n", func());
	printf("Value of Func is %d\n", func());

	S a;
	S b;
	S c;

	printf("Value of a is %d\n", a.static_value());
	printf("Value of b is %d\n", b.static_value());
	printf("Value of c is %d\n", c.static_value());

	return 0;
}