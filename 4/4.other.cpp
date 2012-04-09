#include <iostream>

using namespace std;

inline const bool isPalindrome(const uint64_t original) {

	register uint64_t
		number = original,
		palindrome = 0;

	do {
		palindrome = (palindrome * 10) + (number % 10);
	} while ((number /= 10) != 0);

	return palindrome == original;
}


int main(int argc, char * * argv) {

	register uint32_t
		i = 999,
		j,
		k,
		l,
		m;

	for (; i > 100; i--) {

		if (i % 11 == 0) {
			j = 999;
			k = 1;

		} else {
			j = 990;
			k = 11;
		}

		for (; j >= i; j -= k) {

			l = j * i;

			if (l < m) {
				continue;
			}

			if (isPalindrome(l)) {
				m = l;
			}
		}
	}

	cout << m << endl;

	return 0;
}
