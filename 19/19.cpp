#include <iostream>

template< typename DAY = uint64_t, typename YEAR = uint32_t >
struct Calendar {
	static inline const bool isLeapYear(YEAR year) {

		if (year % 4 == 0)

			if (year % 100 == 0)

				if (year % 400 == 0)
					return true;

				else
					return false;

			else
				return true;

		else
			return false;
		
	}

	static inline const DAY day(const YEAR year) {
		return year * 365 + (year + 3) / 4 - (year + 99) / 100 + (year + 399) / 400;
	}

	static inline const YEAR year(const DAY day) {
		return (day - (day + 1154) / 365 / 4 + (day + 36194) / 36500 - (day + 145694) / 186000) / 365;
	}
};

int main (int argc, char * * argv) {

	const uint8_t

		M[] = {
			31, //JAN
			28, //FEB
			31, //MAR
			30, //APR
			31, //MAY
			30, //JUN
			31, //JUL
			31, //AUG
			30, //SEP
			31, //OCT
			30, //NOV
			31, //DEC
		};

	typedef uint64_t DAY;
	typedef uint32_t YEAR;

	typedef Calendar< DAY, YEAR > Calendar;

	uint16_t c(0);

	DAY d(Calendar::day(1901));
	const DAY e(Calendar::day(2001));

	uint8_t m(0);

	while (d < e) {

		if ((d + 1) % 7 == 2) {
			std::cout << "Sunday " << (m + 1) << " 1st, " <<  Calendar::year(d) << std::endl;
			c++;
		}

		d += M[m];

		if (m == 1 && Calendar::isLeapYear(Calendar::year(d))) {
			d++;
		}

		m++;
		m %= 12;
	}

	std::cout << c << std::endl;

	return 0;
}
