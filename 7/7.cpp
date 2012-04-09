#include <iostream>
#include <vector>

#include "sieve-eratosthenes.hpp"

using namespace std;

int main(int argc, char * * argv) {

	typedef vector< uint32_t > list;
	list primes;

	uint32_t upperBound = 1000000;

	SieveEratosthenes(upperBound, primes);

	cout << "the 10,001th primes is: "
		<< primes[10000] << endl;

	return 0;
}
