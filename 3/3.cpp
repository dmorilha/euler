#include <cmath>

#include <iostream>
#include <vector>

using namespace std;

template< typename TYPE_t = uint64_t >
struct Factors {

	inline static const bool testFactor(TYPE_t & number, const TYPE_t factor) {

		if (number % factor == 0) {

			while (number % factor == 0) {
				number /= factor;
			}

			return true;
		}

		return false;
	}

	static void calculateFactors(const TYPE_t originalNumber, vector< TYPE_t > & factors) {

		TYPE_t
			factor = 7,
			number = originalNumber,
			root = floor(sqrt(number));

		factors.clear();

		if (testFactor(number, 2)) {
			factors.push_back(2);
		}

		if (testFactor(number, 3)) {
			factors.push_back(3);
		}

		if (testFactor(number, 5)) {
			factors.push_back(5);
		}

		while (factor <= root) {

			if (testFactor(number, factor)) {
				factors.push_back(factor);
			}

			factor += (factor % 10 == 3)? 4: 2;
		}

		if (factors.empty()) {
			factors.push_back(originalNumber);
		}
	}

};

int main(int argc, char * * argv) {

	typedef uint64_t TYPE_t;
	typedef vector< TYPE_t > vector;
	typedef Factors< TYPE_t > Factors;

	TYPE_t n = 600851475143;
	vector factors;

	Factors::calculateFactors(n, factors);

	vector::const_iterator iterator;
	const vector::const_iterator end(factors.end());

	for (iterator = factors.begin(); iterator != end; iterator++) {

		cout << *iterator << endl;

	}
}
