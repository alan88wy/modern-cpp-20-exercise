#include <cstdio>
#include <cstdint>

union ipv4 {
	unsigned __int32 i32;
	struct {
		uint8_t a;
		uint8_t b;
		uint8_t c;
		uint8_t d;
	} octets;
};

int main() {

	union ipv4 addr;

	addr.octets = { 192, 168, 73, 42 };

	printf("addr is %d.%d.%d.%d is %08x\n", addr.octets.a, addr.octets.b, addr.octets.c, addr.octets.d, addr.i32);

	return 0;
}