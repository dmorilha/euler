/*
 * 2 3 5 7 11 13 17 19
 *
 * 20 2 * 2 * 5
 * 18 2 * 3 * 3
 * 16 2 * 2 * 2 * 2
 * 15 3 * 5
 * 14 2 * 7
 * 12 2 * 2 * 3
 * 10 2 * 5
 * 9 3 * 3
 * 8 2 * 2 * 2
 * 6 2 * 3
 * 4 2 * 2
 *
 */

#include <iostream>
#include <list>
#include <map>

using namespace std;

template< typename NUMBER_t, typename CONTAINER_t >
static inline void factorizeNumber(const NUMBER_t original, CONTAINER_t & factors) {

	register NUMBER_t factor,
		number;

	register NUMBER_t counter;

	typename CONTAINER_t::iterator iterator(factors.begin());
	const typename CONTAINER_t::const_iterator end(factors.end());

	for (; iterator != end; iterator++) {

		factor = iterator->first;
		counter = 0;
		number = original;

		while (number % factor == 0) {
			number /= factor;
			counter++;
		}

		if (iterator->second < counter) {
			iterator->second = counter;
		}
	}
}

template< typename NUMBER_t, typename CONTAINER_t >
static void SieveEratosthenes(const NUMBER_t LIMIT, CONTAINER_t & container) {

	NUMBER_t
		a1 = 3,
		a2 = 0,
		b,
		c;

	uint32_t d;

	int16_t * buffer;

	const uint32_t BUFFER_SIZE(LIMIT / 2.5 / (sizeof(*buffer) * 8) + 1);
	const uint8_t S(sizeof(*buffer) * 8);


	// allocate and clear buffer.

	buffer = new int16_t[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);


	// add first 3 primes.

	if (LIMIT >= 2) {
		container.push_back(2);
	}

	if (LIMIT >= 3) {
		container.push_back(3);
	}

	if (LIMIT >= 5) {
		container.push_back(5);
	}


	// if less than 7 we are good to return.

	if (LIMIT < 7) {
		return;
	}


	// iterate for number 3.

	b = 3;
	c = 3 * 3;

	while (c <= LIMIT) {

		d = static_cast< uint32_t >(c / 2) - static_cast< uint32_t >((c + 5) / 10) - 1;
		buffer[d / S] |= 0x1 << (d % S);

		b += (b % 10 == 3)? 4: 2;
		c = a1 * b;
	}


	// iterate for number 7 and on.

	a1 += (a1 % 10 == 3)? 4: 2;
	a2++;

	while ( a1 <= LIMIT) {

		if ((buffer[a2 / S] & 0x1 << (a2 % S)) == 0) {

			container.push_back(a1);

			b = a1;
			c = a1 * b;

			while (c <= LIMIT) {

				d = static_cast< uint32_t >(c / 2) - static_cast< uint32_t >((c + 5) / 10) - 1;
				buffer[d / S] |= 0x1 << (d % S);

				b += (b % 10 == 3)? 4: 2;
				c = a1 * b;
			}
		}

		a1 += (a1 % 10 == 3)? 4: 2;
		a2++;
	}


	// delete buffer.
	delete [] buffer;
}

template< typename A_, typename B_ >
struct A: public std::list< std::pair< A_, B_ > > {

	typedef std::pair< A_, B_ > PAIR_t;
	typedef std::list< PAIR_t > PARENT_t;

	inline void push_back(const A_ & a) {
		PARENT_t::push_back(PAIR_t(a, 0));
	}
};

int main(int argc, char * * argv) {

	const uint32_t LOWER_LIMIT(1),
		UPPER_LIMIT(20);

	typedef A< uint32_t, uint16_t > list;

	list primes;

	SieveEratosthenes(UPPER_LIMIT, primes);

	list::const_iterator iterator;
	const list::const_iterator end(primes.end());

	register uint32_t
		i,
		j = 1;

	for (i = LOWER_LIMIT; i < UPPER_LIMIT; i++) {
		factorizeNumber(i, primes);
	}

	for (iterator = primes.begin(); iterator != end; iterator++) {

		for (i = 0; i < iterator->second; i++) {
			j *= iterator->first;
		}

	}

	cout << j << endl;

	return 0;
}

