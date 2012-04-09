
#include <cstring>

#include <stdint.h>


template < typename A = uint32_t, uint8_t S = 10 >
struct X {
	A a[S];

	X(void) {
		memset(a, 0, S);
	}
};

int main (int argc, char * * argv) {

	X<> x;

	return 0;
}
