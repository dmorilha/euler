#include <iostream>

using namespace std;

int main(int argc, char * * argv) {

	uint64_t
		a = 0,
		b = 0,
		c = 1;

	for (; c <= 100; c++) {
		a += c;
		b += (c * c);

		cout << c << " " << (c * c) << " " << a << " " << b << endl;
	}

	cout << a << endl
		<< b << endl
		<< a * a - b << endl;

	return 0;
}
