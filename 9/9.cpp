#include <iostream>

using namespace std;

int main(int argc, char * * argv) {

	typedef uint32_t NUMBER_t;

	register NUMBER_t
		a = 1,
		b = 1,
		c = 1,
		d;

	for (; a <= 333; a++) {

		d = a * a;

		for (b = a + 1; a + b <= 666; b++) {

			c = 1000 - (a + b);

			if (d + b * b == c * c) {

				cout << "a: " << a << endl
					<< "b: " << b << endl
					<< "c: " << c << endl
					<< "product is " << a * b * c << endl;

				return 0;
			}
		}
	}

	return 1;
}
