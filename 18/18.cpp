#include <algorithm>
#include <iostream>
#include <vector>


template< typename CONTAINER >
void print (const CONTAINER & c) {

	const typename CONTAINER::const_iterator e(c.end());
	typename CONTAINER::const_iterator i(c.begin());

	for (; i != e; i++) {
		std::cout << *i << std::endl;
	}
}

int main(int argc, char * * argv) {

	std::vector< uint64_t > x, z;


	{
		const uint32_t triangle[] = {
			75,
			95, 64,
			17, 47, 82,
			18, 35, 87, 10,
			20,  4, 82, 47, 65,
			19,  1, 23, 75,  3, 34,
			88,  2, 77, 73,  7, 63, 67,
			99, 65,  4, 28,  6, 16, 70, 92,
			41, 41, 26, 56, 83, 40, 80, 70, 33,
			41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
			53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
			70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
			91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
			63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
			 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23
		};


		uint32_t b = 1,
			c = 1,
			d;

		x.push_back(triangle[0]);

		for (uint16_t l = 2; l < 16; l++) {

			b = c;
			c += l;

			x.swap(z);
			x.clear();

			x.push_back(triangle[b] + z.front());

			for (d = b + 1; d < c - 1; d++) {
				x.push_back(triangle[d] + std::max(z[d - b], z[d - b - 1]));
			}

			x.push_back(triangle[d] + z.back());
		}
	}

	{
		const std::vector< uint64_t >::const_iterator e(x.end());
		std::vector< uint64_t >::const_iterator i(x.begin()),
			b;

		b = i;
		i++;

		for (; i != e; i++) {

			if (*b < *i) {
				b = i;
			}

		}

		std::cout << *b << std::endl;
	}
}
