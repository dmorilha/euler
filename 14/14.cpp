#include <iostream>

#include <list>
#include <map>


template < typename TYPE, uint16_t S >
struct CircularBuffer {

	TYPE buffer_[S];
	uint16_t i_;
	const uint16_t SIZE;

	CircularBuffer(const TYPE v):
		i_(0),
		SIZE(S) {
		for (int i = 0; i < SIZE; i++) {
			this->buffer_[i] = v;
		}
	}

	CircularBuffer(const CircularBuffer & that):
		i_(that.i_),
		SIZE(S) {
		memcpy(this->buffer_, that.buffer_, this->SIZE * sizeof(TYPE));
	}

	inline CircularBuffer & operator= (const CircularBuffer & that) {
		this->i_ = that.i_;
		memcpy(this->buffer_, that.buffer_, this->SIZE * sizeof(TYPE));

		return *this;
	}

	inline const TYPE operator[] (const uint16_t i) const {
		return this->buffer_[(i + this->i_ + 1) % SIZE];
	}

	inline CircularBuffer & operator= (const TYPE v) {
		this->buffer_[this->i_] = v;
		return *this;
	}

	inline CircularBuffer & operator++ (int) {
		this->i_ = ((this->i_ + 1) % SIZE);
		return *this;
	}

	inline CircularBuffer & operator+= (const TYPE v) {
		this->i_ = ((this->i_ + 1) % this->SIZE);
		return this->operator=(v);
	}

	inline void print(void) const {
		for (uint16_t i; i < this->SIZE; i++) {
			std::cout << this->operator[](i) << std::endl;
		}
	}
};

int main(int argc, char * * argv) {

	typedef CircularBuffer< uint32_t, 4 > CIRCULAR_BUFFER;

	typedef std::pair< CIRCULAR_BUFFER, uint32_t > PAIR;
	typedef std::list< PAIR > LIST;

	LIST stack;

	CIRCULAR_BUFFER b(0);

	uint32_t i = 2,
		j = 1,

		k = 3,
		l = 0,
		m = 0;

	b = j;
	b += i;

	const uint32_t M(1000000),
		T(M * 3 + 1);

	while (true) {

		while (i > 1 && i < T) {

			j = i;
			i = (j - 1) / 3;

			if (i == 1 || i * 3 + 1 != j || i % 2 == 0) {
				i = 2 * j;

			} else {
				stack.push_back(PAIR(b, k));
			}
			
			b += i;
			k++;
		}

		for (i = 0, k -= b.SIZE; i < b.SIZE; i++, k++) {

			if (b[i] < M && l < k) {
				m = b[i];
				l = k;
			}
		}

		if (stack.empty()) {
			break;

		} else {
			stack.pop_front();

			b = stack.front().first;
			k = stack.front().second;

			j = b[b.SIZE - 1];
			i = 2 * j;

			b += i;
			k++;
		}
	}

	std::cout << m << " " << l << std::endl;
}
