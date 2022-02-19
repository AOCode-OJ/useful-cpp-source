/****************************************
********** File: stlp_binarr.h 
****************************************/

#include "declaring.h"

#ifndef _STDPLUS_STLP_BINARR_H_
#define ll long long
#define _STDPLUS_STLP_BINARR_H_ 1

#if __cplusplus < 201300L // below C++14 (exclusive)

#error This file requires compiler and library support \
for the ISO C++ 2014 standard. This support must be enabled \
with the -std=c++14 or -std=gnu++14 compiler options.

#elif __cplusplus > 201402L // above C++14 (exclusive)

#warning This file fits in compilers and libraries supporting \
the ISO C++ 2014 standard. You are using a version above \
this standard. Maybe some parts of the file will not fit in \
your compiler. You should better use the compiler with the \
-std=c++14 or -std=gnu++14 compiler options.

#endif // not C++14

namespace stdplus {

	namespace binarrcl {

		inline ll lowbit(const ll& x) {
			return (x & (-x));
		}

		struct binarr {
			int len;
			std::vector<ll> val;

			binarr() : len(0), val(std::vector<ll>(1)) {};
			binarr(int n) : len(n), val(std::vector<ll>(n + 1)) {};

			void resize(const int l);

			auto& operator[] (const int i);
			const auto& operator[] (const int i) const;
			auto& at(const int i);
			const auto& at(const int i) const;

			auto getsum(const int i);
			void addx(const int i, const ll& p);
			void setx(const int i, const ll& x);
		};

		void binarr::resize(const int l) {
			len = l;
			val.resize(l + 1);
		}

		auto& binarr::operator[] (const int i) {
			return val[i];
		}
		const auto& binarr::operator[] (const int i) const {
			return val[i];
		}
		auto& binarr::at(const int i) {
			return val[i];
		}
		const auto& binarr::at(const int i) const {
			return val[i];
		}

		auto binarr::getsum(const int i) {
			int ind = i;
			ll ans = 0;
			while(ind != 0) {
				ans += val[ind];
				ind -= lowbit(ind);
			}
			return ans;
		}
		void binarr::addx(const int i, const ll& p) {
			int ind = i;
			while(ind <= len) {
				val[ind] += p;
				ind += lowbit(ind);
			}
		}
		void binarr::setx(const int i, const ll& x) {
			ll ori = getsum(i) - getsum(i - 1);
			ll v = x - ori;
			addx(i, v);
		}

		// namespace stdplus::binarrcl
	}

	// namespace stdplus
}

#endif // _STDPLUS_STLP_BINARR_H_

#undef ll

// end file