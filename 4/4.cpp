#include <algorithm>
#include <iostream>
#include <list>

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

	typedef list< uint32_t > list;

	list palindromes;

	register uint32_t
		i = 999,
		j,
		k;

	for (; i > 0; i--) {

		for (j = 999; j >= i; j--) {

			k = j * i;

			if (isPalindrome(k)) {
				palindromes.push_back(k);
			}
		}
	}

	list::const_iterator iterator(max_element(palindromes.begin(), palindromes.end()));

	if (iterator != palindromes.end()) {
		cout << "max palindrome is : " << *iterator << endl;
	}

	return 0;
}
