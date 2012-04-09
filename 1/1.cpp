
#include <iostream>

using namespace std;

int main(int argc, char * * argv) {

	int j = 0;

	for (int i = 0; i < 1000; i += 1) {

		if ( ! (i % 3 && i % 5)) {
			j += i;
		}

	}

	cout << j << endl;
}
