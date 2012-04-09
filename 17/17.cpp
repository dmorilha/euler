
#include <string>
#include <iostream>

template < typename NUMBER >
struct Number {
	static inline const std::string ones(const NUMBER n) {
		const char * const ONES[] = {
			"zero",
			"one",
			"two",
			"three",
			"four",
			"five",
			"six",
			"seven",
			"eight",
			"nine"
		};

		return ONES[n % 10];
	}

	static inline const std::string tens(NUMBER n) {

		std::stringstream ss;

		const char * const TENS[] = {
			"ten",
			"eleven",
			"twelve",
			"thirteen",
			"fourteen",
			"fifteen",
			"sixteen",
			"seventeen",
			"eighteen",
			"nineteen",
			"twenty",
			"thirty",
			"forthy",
			"fifty",
			"sixty",
			"seventy",
			"eighty",
			"ninety"
		};

		n %= 100;
		n -= 10;

		if (n > 10) {
			n = n / 10 + 9;
		}

		if (n > 10) {

		}

		return ss.str();
	}
};

int main(int argc, char * * argv) {

	if (argc > 1) {
		std::cout << Number< uint16_t >::tens(atoi(argv[1])) << std::endl;
	}

	return 0;
}
