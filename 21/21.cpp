#include <iostream>
#include <cmath>
#include <vector>;

int main (int argc, char * * argv) {

	std::vector< uint16_t > vector(10000);

	uint16_t
		i,
		j,
		k,
		square;

	for (i = 1; i < 10000; i++) {

		square = sqrt(i);
		k = 1;

		for (j = 2; j < square; j++) {
			if (i % j == 0) {
				k += j;
				k += i / j;
			}
		}

		if (i % j == 0) {
			k += j;
		}

		vector[i] = k;
	}

	k = 0;

	for (i = 1; i < 10000; i++) {

		j = vector[i];

		if (vector[j] == i && i < j) {
			k += j + i;
		}
	}

	std::cout << k << std::endl;

	return 0;
}
