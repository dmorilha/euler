#include <iostream>

int main(int argc, char * * argv) {

	uint32_t i,
		j,
		k,

		m,
		o;


	i = 2;
	m = 1;

	while (i < 1000000) {

		j = i;
		m = 1;

		while (j > 1) {

			if (j % 2 == 1) {
				j = 3 * j + 1;

			} else {
				j /= 2;
			}

			m++;
		}

		if (m > o) {
			o = m;
			k = i;
		}

		i++;
	}

	std::cout << k << " " << o << std::endl;

	return 0;
}
