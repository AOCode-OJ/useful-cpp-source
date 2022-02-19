/****************************************
********** File: stlp_rawint.h
****************************************/

#include "declaring.h"

#ifndef _STDPLUS_STLP_RAWINT_H_
#define _STDPLUS_STLP_RAWINT_H_ 1

namespace stdplus {
	namespace __rawint {

		enum __RAWINTIO { bin = 0b0001,
		                oct = 0b0010,
		                dec = 0b0100,
		                hex = 0b1000
		              };

		int __RAWINT_IO_INDEX_SETTING__ = 0b0100;

		std::istream& operator>> (std::istream& is, enum __RAWINTIO p) {
			__RAWINT_IO_INDEX_SETTING__ &= 0b0000;
			__RAWINT_IO_INDEX_SETTING__ |= p;
			return is;
		}
		std::ostream& operator<< (std::ostream& os, enum __RAWINTIO p) {
			__RAWINT_IO_INDEX_SETTING__ &= 0b0000;
			__RAWINT_IO_INDEX_SETTING__ |= p;
			return os;
		}

		struct rawint128 {
			bool nega;
			std::bitset<128> bts;

			rawint128() : nega(false) {};
		};

		std::istream& operator>> (std::istream& is, rawint128& x) {
			if((__RAWINT_IO_INDEX_SETTING__ & bin) == bin) {
				is >> x.bts;
			} else {
				std::string s;
				is >> s;
				if((__RAWINT_IO_INDEX_SETTING__ & oct) == oct) {
				} else if((__RAWINT_IO_INDEX_SETTING__ & dec) == dec) {
				} else if((__RAWINT_IO_INDEX_SETTING__ & hex) == hex) {
				}
			}
			return is;
		}
		std::ostream& operator<< (std::ostream& os, const rawint128& x) {
			return os;
		}
	}
}

#endif

// end file
