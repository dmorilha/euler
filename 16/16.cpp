
#include <iostream>
#include <iomanip>

#include <sstream>
#include <string>

template < uint16_t S >
struct BigInt {

	uint32_t b_[S];

	BigInt(const uint32_t n = 0) {
		memset(this->b_, 0, S * sizeof(uint32_t));
		this->b_[S - 1] = n;
	}

	BigInt & operator*= (const uint64_t & n) {

		uint64_t r, s = 0;
		uint16_t i;

		for (i = S - 1; i > 0; i--) {
			r = this->b_[i] * (n % 1000000000);
			this->b_[i] = r % 1000000000;
			this->b_[i] += s;
			s = r / 1000000000;
		}

		this->b_[i] += s;

		return *this;
	}

	const std::string print(void) {

		uint16_t i = 0;
		std::stringstream ss;


		while (this->b_[i] == 0) {
			i++;
		}

		ss << this->b_[i];
		i++;

		for (; i < S; i++) {
			ss << std::setw(9) << std::setfill('0') << this->b_[i];
		}

		return ss.str();
	}
};

int main(int argc, char * * argv) {

	BigInt< 128 > c(1);

	for (uint16_t i = 0; i < 1000; i++) {

		c *= 2;

		if (i % 100 == 0) {
			std::cout << c.print() << std::endl;
		}
	}
	std::string s(c.print());

	std::cout << std::endl << s << std::endl;

	std::string::const_iterator i = s.begin();
	const std::string::const_iterator e(s.end());

	uint64_t n(0);

	for (; i != e; i++) {
		n += (*i - 48);
	}

	std::cout << std::endl << n << std::endl;
}
