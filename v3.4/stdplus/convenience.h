/****************************************
********** File: convenience.h
****************************************/

#include "declaring.h"

#include "math"
/****************************************
Include "math" for these:
	stdplus::
	--	opfunc::
	--	--	binary_pow(const double&, const ll&);
****************************************/

#ifndef _STDPLUS_CONVENIENCE_H_
#define ll long long
#define _STDPLUS_CONVENIENCE_H_ 1

namespace stdplus {
	template <typename _Tp> inline _Tp max(_Tp val) {
		return val;
	}
	template <typename _Tp, typename... Args>
	inline _Tp max(_Tp val, Args... args) {
		return std::max(val, max(args...));
	}
	template <typename _Tp> inline _Tp min(_Tp val) {
		return val;
	}
	template <typename _Tp, typename... Args>
	inline _Tp min(_Tp val, Args... args) {
		return std::min(val, min(args...));
	}

	// quick_read
	namespace quickIO {

		inline int qreadln(int& val) {
			int res = 0, negative = 1;
			char c = getchar();
			while(!isdigit(c) && c != '-') c = getchar();
			while(c == '-') negative *= -1, c = getchar();
			while(isdigit(c)) res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
			return val = res * negative;
		}
		inline uint qreadln(uint& val) {
			uint res = 0u;
			char c = getchar();
			while(!isdigit(c)) c = getchar();
			while(isdigit(c)) res = (res << 3) + (res << 1) + (uint)(c ^ 48), c = getchar();
			return val = res;
		}
		inline ll qreadln(ll& val) {
			ll res = 0LL, negative = 1LL;
			char c = getchar();
			while(!isdigit(c) && c != '-') c = getchar();
			while(c == '-') negative *= -1LL, c = getchar();
			while(isdigit(c)) res = (res << 3) + (res << 1) + (ll)(c ^ 48), c = getchar();
			return val = res * negative;
		}
		inline ull qreadln(ull& val) {
			ull res = 0uLL;
			char c = getchar();
			while(!isdigit(c)) c = getchar();
			while(isdigit(c)) res = (res << 3) + (res << 1) + (ull)(c ^ 48), c = getchar();
			return val = res;
		}
		inline double qreadln(double& val) {
			ll s = 0, w = 1, k = 0, n = 0, m = 0;
			char ch = getchar();
			while(!isdigit(ch)) {
				if(ch == '-') w = -1;
				ch = getchar();
			}
			while((isdigit(ch)) || ch == '.') {
				if(ch == '.') n = 1;
				else if(n == 0) s = (s << 3) + (s << 1) + (ch ^ 48);
				else k = (k << 3) + (k << 1) + (ch ^ 48), m++;
				ch = getchar();
			}
			return val = (pow(0.1, m) * k + s) * w;
		}
		inline std::string qreadln(std::string& val) {
			std::string res;
			char c = getchar();
			while(c == ' ' && c == '\n') c = getchar();
			while(c != ' ' && c != '\n') res.push_back(c), c = getchar();
			return val = res;
		}

		template <class _Tp> inline void qscanln(_Tp& val) {
			qreadln(val);
		}
		template <class _Tp, class... Args>
		inline void qscanln(_Tp& val, Args&... args) {
			qreadln(val), qscanln(args...);
		}

		inline void qwriteln(const std::string& s) {
			for(auto& c : s) putchar(c);
		}
		inline void qwriteln(const char* str) {
			while(*str != '\0') putchar(*str), ++str;
		}
		inline void qwriteln(int x) {
			if(x < 0) putchar('-'), x = -x;
			int&& y = 10, len = 1;
			while(y <= x) y *= 10, ++len;
			while(len--) y /= 10, putchar(x / y + 48), x %= y;
		}
		inline void qwriteln(uint x) {
			uint&& y = 10u, len = 1u;
			while(y <= x) y *= 10u, ++len;
			while(len--) y /= 10u, putchar(x / y + 48u), x %= y;
		}
		inline void qwriteln(ll x) {
			if(x < 0ll) putchar('-'), qwriteln(-x);
			ll&& y = 10ll, len = 1ll;
			while(y <= x) y *= 10ll, ++len;
			while(len--) y /= 10ll, putchar(x / y + 48ll), x %= y;
		}
		inline void qwriteln(ull x) {
			ull&& y = 10ull, len = 1ull;
			while(y <= x) y *= 10ull, ++len;
			while(len--) y /= 10ull, putchar(x / y + 48ull), x %= y;
		}
		inline void qwriteln(const char& val) {
			putchar(val);
		}
		inline void qwriteln(const float& val) {
			qwriteln(std::to_string(val));
		}
		inline void qwriteln(const double& val) {
			qwriteln(std::to_string(val));
		}
		inline void qwriteln(const long double& val) {
			qwriteln(std::to_string(val));
		}

		template <class _Tp> inline void qprintln(const _Tp& val) {
			qwriteln(val);
		}
		template <class _Tp, class... Args>
		inline void qprintln(const _Tp& val, const Args&... args) {
			qwriteln(val), qprinln(args...);
		}
		template <class _Tp> inline void qprintcmln(const char& cm, const _Tp& val) {
			qwriteln(val);
		}
		template <class _Tp, class... Args>
		inline void qprintln(const char& cm, const _Tp& val, const Args&... args) {
			qwriteln(val), qwriteln(cm), qprintcmln(args...);
		}

		// namespace stdplus::quickIO
	}

	// namespace stdplus
}

#endif

// end file
