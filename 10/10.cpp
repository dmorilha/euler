#include <iostream>
#include <list>

#include "sieve-eratosthenes.hpp"

using namespace std;

int main(int argc, char * * argv) {

	typedef list< uint32_t > list;
	list primes;

	uint64_t upperBound = 2000000;
	SieveEratosthenes(upperBound, primes);

	list::const_iterator iterator;
	const list::const_iterator end(primes.end());

	register uint64_t sum = 0;

	for (iterator = primes.begin(); iterator != end; iterator++) {
		sum += *iterator;
	}

	cout << "sum is: " << sum << endl;

	return 0;
}
