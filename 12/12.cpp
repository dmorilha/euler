#include <iostream>
#include <list>

#include <sieve-eratosthenes.hpp>

using namespace std;

template < typename NUMBER, typename CONTAINER >
static const uint16_t factors(NUMBER n, const CONTAINER & primes) {

	typename CONTAINER::const_iterator iterator(primes.begin());
	const typename CONTAINER::const_iterator end(primes.end());

	uint16_t f(1),
		g(1);

	for (; iterator != end; iterator++) {

		while (n % *iterator == 0) {
			g += 1;
			n /= *iterator;
		}

		if (g > 1) {
			f *= g;
			g = 1;
		}

		if (n == 1) {
			break;
		}
	}

	return f;
}

int main(int argc, char * * argv) {

	typedef std::list< uint32_t > LIST;
	typedef uint32_t NUMBER;

	LIST primes;


	const uint32_t TOP(1000000);

	SieveEratosthenes(TOP, primes);

	LIST::const_iterator i;
	const LIST::const_iterator END(primes.end());

	NUMBER n = 2,
		n1;

	uint16_t cnt = 0,
		dn = 2,
		dn1,
		e = 1;

	while (n < 60000001) {

		n++;
		n1 = n;

		if (n1 % 2 == 0) {
			n1 /= 2;
		}

		dn1 = 1;

		for (i = primes.begin(); i != END; i++) {

			if (*i * *i > n1) {
				dn1 *= 2;
				break;
			}

			while (n1 % *i == 0) {
				e += 1;
				n1 /= *i;
			}

			if (e > 1) {
				dn1 *= e;
				e = 1;
			}

			if (n1 == 1) {
				break;
			}
		}

		cnt = dn * dn1;
		dn = dn1;
	}

	/*
	const uint32_t number(n * (n + 1) / 2);
	std::cout << number << std::endl;
	*/

}
