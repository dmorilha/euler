#include <iostream>

using namespace std;

template< class ITERATOR, class FUNCTION >
uint64_t sum_if(ITERATOR a, ITERATOR b, FUNCTION f) {

	uint64_t sum = 0;

	for (; a != b; a++) {

		if (f(*a) == true) {
			sum += *a;
		}
	}

	return sum;
}

struct Even {
	template < typename TYPE_t >
	inline const bool operator() (const TYPE_t a) const {
		return a % 2 == 0;
	}
};

template< uint32_t LIMIT_t, typename TYPE_t = uint32_t >
struct Fibonacci {

	typedef TYPE_t TYPE;

	class Iterator {

		TYPE_t previous, current;

	public:
		inline Iterator(const TYPE_t previous, const TYPE_t current):
			previous(previous),
			current(current) {
		}
	
		inline const TYPE_t operator++ (const int a) {

			TYPE_t old;

			old = current;
			current += previous;
			return (previous = old);
		}

		inline const bool operator!= (const Iterator that) const {
			return this->current < LIMIT_t;
		}

		inline const TYPE_t operator* (void) const {
			return current;
		}
	};

	Iterator begin(void) {
		return Iterator(0, 1);
	}

	Iterator end(void) {
		return this->begin();
	}
};

int main(int argc, char * * argv) {

	Fibonacci< 4000000 > f;
	Even even;

	cout << sum_if(f.begin(), f.end(), even) << endl;

	return 0;
}
