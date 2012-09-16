#include <iostream>
#include <list>
#include <vector>
#include <map>

#include <algorithm>

#include <sieve-eratosthenes.hpp>

#include <cmath>

using namespace std;

int main(int argc, char * * argv) {

	typedef uint32_t NUMBER;

	typedef std::list< NUMBER > LIST;
	typedef std::map< uint16_t, LIST > MAP;
	typedef std::vector< uint16_t > VECTOR;

	MAP map;

	const uint32_t N(60000001);
	VECTOR vector(N);

	const uint64_t D(pow(10.0, 18));

	{
		typedef std::list< uint32_t > PRIMES;
		LIST primes;

		const uint32_t TOP(1000000);

		SieveEratosthenes(TOP, primes);

		LIST::const_iterator prime;
		const LIST::const_iterator PRIMES_END(primes.end());

		NUMBER n = 1,
			n1;

		uint32_t cnt = 0,
			dn = 2,
			dn1,
			e = 1;

		while (n < N) {

			n1 = n + 1;

			if (n1 % 2 == 0) {
				n1 /= 2;
			}

			dn1 = 1;

			for (prime = primes.begin(); prime != PRIMES_END; prime++) {

				if (*prime * *prime > n1) {
					dn1 *= 2;
					break;
				}

				while (n1 % *prime == 0) {
					e += 1;
					n1 /= *prime;
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

			map[cnt].push_back(n);
			vector[n] = cnt;

			n += 1;
		}
	}

	{
		const MAP::const_iterator END(map.end());
		MAP::const_iterator iterator(map.begin());

		LIST::const_iterator i1, e1, i2, e2;

		uint32_t a,
			b,
			c,
			d,
			f;

		uint64_t
			e = 0;

		LIST stack;

		for (; iterator != END; iterator++) {

			i1 = iterator->second.begin();
			e1 = iterator->second.end();

			b = f = 0;
			stack.clear();

			for (; i1 != e1; i1++) {

				d = f;

				i2 = stack.begin();
				e2 = stack.end();

				for (; i2 != e2; i2++) {
					for (c = b + 1; c < *i1; c++) {
						if (vector[*i1] < vector[c] && vector[c] < vector[*i2]) {
							d++;
						}
					}
				}

				for (a = b + 1; a < *i1; a++) {

					for (c = a + 1; c < *i1; c++) {
						if (vector[*i1] < vector[c] && vector[c] < vector[a]) {
							d++;
						}
					}

					if (vector[*i1] < vector[a]) {
						stack.push_back(a);
					}
				}

				b = *i1;
				e += f = d;
				f %= D;
				e %= D;

				//std::cout << "alo alo" << std::endl;
			}
		}

		std::cout << e << std::endl;
	}
}
