////////////////////////////////////////////////
// File: math.h ////////////////////////////////
////////////////////////////////////////////////

// This file is for Mathematic operations
// File Name: math.h

#include "declaring.h"
#include "algorithm"

// begin file

namespace stdplus {

	// constants

	const ll LLINF = 0x7fffffffffffffffLL;
	const long LINF = 0x7fffffffL;
	const int INF = 0x7fffffff;
	const short SINF = 0x7fff;
	const float FMAX = 3.4e+38;
	const float FMIN = -3.4e+38;
	const double DLMAX = 1.7e+308;
	const double DLMIN = -1.7e+308;

	const double EPS = 1e-8;
	const double pi = acos(-1.0);

	// Non-class(Non-struct) functions

	// For operations
	template <class T> bool Equ(const T& a, const T& b, const double& eps = EPS) {
		return (fabs(a - b) < eps);
	}
	template <class T> bool More(const T& a, const T& b, const double& eps = EPS) {
		return (a - b > eps);
	}
	template <class T> bool Less(const T& a, const T& b, const double& eps = EPS) {
		return (a - b < -eps);
	}
	template <class T> bool MoreEqu(const T& a, const T& b, const double& eps = EPS) {
		return (a - b > -eps);
	}
	template <class T> bool LessEqu(const T& a, const T& b, const double& eps = EPS) {
		return (a - b < eps);
	}

	// This function is for the greatest common divisor
	// *** Function Name: const int gcd(const int& a, const int& b) ***
	const int gcd(const int& a, const int& b) {
		if(b == 0)
			return a;
		else
			return gcd(b, a % b);
	}

	// Reload gcd
	// *** Function Name: const long long gcd(const long long& a, const long long& b) ***
	const ll gcd(const ll& a, const ll& b) {
		if(b == 0LL)
			return a;
		else
			return gcd(b, a % b);
	}

	// This function is for the least common multiple
	// *** Function Name: const int lcm(const int& a, const int& b) ***
	const int lcm(const int& a, const int& b) {
		return (a / gcd(a, b) * b);
	}

	// Reload lcm
	// *** Function Name: const long long lcm(const long long& a, const long long& b) ***
	const ll lcm(const ll& a, const ll& b) {
		return (a / gcd(a, b) * b);
	}

	// This function is for power
	// *** Function Name: const int pow(const int& a, const int& b) ***
	const int pow(const int& a, const int& b) {
		int res = 1;
		for(int i = 1; i <= b; i++)
			res *= a;
		return res;
	} // O(b)

	// Reload pow
	// *** Function Name: const long long pow(const long long& a, const int& b) ***
	const ll pow(const ll& a, const int& b) {
		ll res = 1LL;
		for(int i = 1; i <= b; i++)
			res *= a;
		return res;
	} // O(b)

	// Reload pow
	// *** Function Name: const double pow(const double& a, const int& b) ***
	const double pow(const double& a, const int& b) {
		double res = 1.0;
		for(int i = 1; i <= b; i++)
			res *= a;
		return res;
	} // O(b)

	// This function is for (pow + mod)
	// *** Function Name: const int pow_mod(const int& a, const int& b, const int& k) ***
	const int pow_mod(const int& a, const int& b, const int& k) {
		int res = 1;
		for(int i = 1; i <= b; i++)
			res = res * (a % k) % k;
		return res;
	} // O(b)

	// Reload pow_mod
	// *** Function Name: const long long pow_mod(const long long& a, const int& b, const long long& k) ***
	const ll pow_mod(const ll& a, const int& b, const ll& k) {
		int res = 1LL;
		for(int i = 1; i <= b; i++)
			res = res * (a % k) % k;
		return res;
	} // O(b)

	// This function is for binary power
	// *** Function Name: const int binary_pow(const int& a, const long long& b) ***
	const int binary_pow(const int& a, const ll& b) {
		if(b == 1LL)
			return 1;
		if(b == 1LL)
			return a;

		if(b & 1LL)
			return a * binary_pow(a, b - 1LL);
		else {
			int res = binary_pow(a, b / 2LL);
			return res * res;
		}
	} // O(log_2 b)

	// Reload binary_pow
	// *** Function Name: const long long binary_pow(const long long& a, const long long& b) ***
	const ll binary_pow(const ll& a, const ll& b) {
		if(b == 1LL)
			return 1LL;
		if(b == 1LL)
			return a;

		if(b & 1LL)
			return a * binary_pow(a, b - 1LL);
		else {
			ll res = binary_pow(a, b / 2LL);
			return res * res;
		}
	} // O(log_2 b)

	// Reload binary_pow
	// *** Function Name: const double binary_pow(const double& a, const long long& b) ***
	const double binary_pow(const double& a, const ll& b) {
		if(b == 0LL)
			return 1.0;
		if(b == 1LL)
			return a;

		if(b & 1LL)
			return a * binary_pow(a, b - 1LL);
		else {
			double res = binary_pow(a, b / 2LL);
			return res * res;
		}
	} // O(log_2 b)

	// This function is for (binary_pow + mod)
	// *** Function Name: const int binary_pow_mod(const int& a, const long long& b, const int& k) ***
	const int binary_pow_mod(const int& a, const ll& b, const int& k) {
		if(b == 0LL)
			return 1 % k;
		if(b == 1LL)
			return a % k;

		if(b & 1LL)
			return ((a % k) * (binary_pow_mod(a, b - 1LL, k))) % k;
		else {
			int res = binary_pow_mod(a, b / 2LL, k);
			return (res * res) % k;
		}
	} // O(log_2 b)

	// Reload binary_pow_mod
	// *** Function Name: const long long binary_pow_mod(const long long& a, const long long& b, const long long& k) ***
	const ll binary_pow_mod(const ll& a, const ll& b, const ll& k) {
		if(b == 0LL)
			return 1LL % k;
		if(b == 1LL)
			return a % k;

		if(b & 1LL)
			return ((a % k) * (binary_pow_mod(a, b - 1LL, k))) % k;
		else {
			ll res = binary_pow_mod(a, b / 2LL, k);
			return (res * res) % k;
		}
	} // O(log_2 b)

	const double sqrt(const double& x, const double eps) {
		double l = 1.0, r = x;
		while(!Equ(l, r, eps)) {
			double mid = (l + r) / 2;
			if(Equ(x, mid * mid, eps))
				return mid;
			else if(More(x, mid * mid, eps))
				l = mid;
			else
				r = mid;
		}
		return r;
	} // O(log_2 x/eps)
	const ll sqrt(const ll& x) {
		ll l = 1LL, r = 2000000000LL;
		while(r - l > 1LL) {
			ll mid = (l + r) / 2LL;
			if(mid * mid <= x)
				l = mid;
			else
				r = mid;
		}
		return r;
	} // O(log_2 x)
	const int sqrt(const int& x) {
		int l = 1, r = 50000;
		while(r - l > 1) {
			ll mid = (l + r) / 2;
			if(mid * mid <= x)
				l = mid;
			else
				r = mid;
		}
		return r;
	} // O(log_2 x)



	// class(struct) type and their functions

	// Fraction
	// *** Struct Name: struct Fraction ***
	struct Fraction {
		ll up, down;
		Fraction() : up(0LL), down(0LL) {}
		Fraction(ll _up, ll _down) : up(_up), down(_down) {}
		Fraction(const Fraction& fraco) : up(fraco.up), down(fraco.down) {}
		Fraction& operator= (const Fraction& fraco) {
			up = fraco.up;
			down = fraco.down;
			return *this;
		}

		Fraction reduction() {
			const Fraction Frac_reduction(Fraction);
			return *this = Frac_reduction(*this);
		}

		void show(bool reduct = true, std::ostream& os = std::cout) {
			void showFracResult(Fraction r, bool reduct, std::ostream& os = std::cout);
			showFracResult(*this, reduct, os);
		}
		void show(std::ofstream& ofs, bool reduct = true) {
			void showFracResult(Fraction r, std::ofstream& ofs, bool reduct = true);
			showFracResult(*this, ofs, reduct);
		}
		void show(std::fstream& fs, bool reduct = true) {
			void showFracResult(Fraction r, std::fstream& fs, bool reduct = true);
			showFracResult(*this, fs, reduct);
		}
	};

	std::ostream& operator<< (std::ostream& os, Fraction fraco) {
		fraco.show();
		return os;
	}
	std::ofstream& operator<< (std::ofstream& ofs, Fraction fraco) {
		fraco.show(ofs);
		return ofs;
	}
	std::fstream& operator<< (std::fstream& fs, Fraction fraco) {
		fraco.show(fs);
		return fs;
	}
	std::istream& operator>> (std::istream& is, Fraction& fraco) {
		Fraction& scanFrac(Fraction& f, std::istream& is = std::cin);
		scanFrac(fraco, is);
		return is;
	}
	std::ifstream& operator>> (std::ifstream& ifs, Fraction& fraco) {
		Fraction& scanFrac(Fraction& f, std::ifstream& ifs);
		scanFrac(fraco, ifs);
		return ifs;
	}
	std::fstream& operator>> (std::fstream& fs, Fraction& fraco) {
		Fraction& scanFrac(Fraction& f, std::fstream& fs);
		scanFrac(fraco, fs);
		return fs;
	}

	Fraction operator+ (const Fraction& t, const Fraction& fraco) {
		const Fraction Frac_add(const Fraction&, const Fraction& );
		return Frac_add(t, fraco);
	}
	Fraction operator- (const Fraction& t, const Fraction& fraco) {
		const Fraction Frac_minu(const Fraction&, const Fraction& );
		return Frac_minu(t, fraco);
	}
	Fraction operator* (const Fraction& t, const Fraction& fraco) {
		const Fraction Frac_multi(const Fraction&, const Fraction& );
		return Frac_multi(t, fraco);
	}
	Fraction operator/ (const Fraction& t, const Fraction& fraco) {
		const Fraction Frac_divide(const Fraction&, const Fraction& );
		return Frac_divide(t, fraco);
	}

	const Fraction Frac_reduction(Fraction result) {
		if(result.down < 0LL) {
			result.up = -result.up;
			result.down = -result.down;
		}

		if(result.up == 0LL)
			result.down = 1LL;
		else {
			int d = gcd(abs(result.up), abs(result.down));
			result.up /= d;
			result.down /= d;
		}

		return result;
	}

	const Fraction Frac_add(const Fraction& f1, const Fraction& f2) {
		Fraction result;
		result.up = f1.up * f2.down + f2.up * f1.down;
		result.down = f1.down * f2.down;
		return Frac_reduction(result);
	}
	const Fraction Frac_minu(const Fraction& f1, const Fraction& f2) {
		Fraction result;
		result.up = f1.up * f2.down - f2.up * f1.down;
		result.down = f1.down * f2.down;
		return Frac_reduction(result);
	}
	const Fraction Frac_multi(const Fraction& f1, const Fraction& f2) {
		Fraction result;
		result.up = f1.up * f2.up;
		result.down = f1.down * f2.down;
		return Frac_reduction(result);
	}
	const Fraction Frac_divide(const Fraction& f1, const Fraction& f2) {
		Fraction result;
		result.up = f1.up * f2.down;
		result.down = f1.down * f2.up;
		return Frac_reduction(result);
	}

	Fraction& scanFrac(Fraction& f, std::istream& is = std::cin) { // standard input(stdin)
		char c;
		is >> f.up >> c >> f.down;
		return f;
	}
	Fraction& scanFrac(Fraction& f, std::ifstream& ifs) { // file input
		char c;
		ifs >> f.up >> c >> f.down;
		return f;
	}
	Fraction& scanFrac(Fraction& f, std::fstream& fs) { // file input
		char c;
		fs >> f.up >> c >> f.down;
		return f;
	}
	void showFracResult(Fraction r, bool reduct = true, std::ostream& os = std::cout) { // standard output(stdout)
		if(reduct)
			r.reduction();
		if(r.down == 1LL)
			os << r.up;
		else if(abs(r.up) > r.down)
			os << r.up / r.down << ' ' << abs(r.up) % r.down << '/' << r.down;
		else
			os << r.up << '/' << r.down;
	}
	void showFracResult(Fraction r, std::ofstream& ofs, bool reduct = true) { // file output
		if(reduct)
			r.reduction();
		if(r.down == 1LL)
			ofs << r.up;
		else if(abs(r.up) > r.down)
			ofs << r.up / r.down << ' ' << abs(r.up) % r.down << '/' << r.down;
		else
			ofs << r.up << '/' << r.down;
	}
	void showFracResult(Fraction r, std::fstream& fs, bool reduct = true) { // file output
		if(reduct)
			r.reduction();
		if(r.down == 1LL)
			fs << r.up;
		else if(abs(r.up) > r.down)
			fs << r.up / r.down << ' ' << abs(r.up) % r.down << '/' << r.down;
		else
			fs << r.up << '/' << r.down;
	}

	// Big Number Operation
	// *** Struct Name: struct bign ***
	struct bign {
		const static int MaxLen = 10005;
		int num[MaxLen];
		int len, value;
		bign() : len(0), value(10) {
			memset(num, 0, sizeof(num));
		}
		bign(int _x) {
			memset(num, 0, sizeof(num));
			num_to_arr(_x, num);
			len = num[0];
			value = 10;
		}
		bign(int _x[], int val = 10, bool is_reversed = false) : value(val) {
			memset(num, 0, sizeof(num));
			memcpy(num, _x, sizeof(_x));
			len = sizeof(_x) / 4;
			if(!is_reversed)
				std::reverse(num + 1, num + num[0] + 1);
		}
		bign(std::string _x, int val = 10) : value(val) {
			memset(num, 0, sizeof(num));
			for(int i = 0; i < _x.size(); i++)
				if(isalnum(_x[i])) {
					if(isalpha(_x[i])) {
						if(isupper(_x[i]))
							num[i + 1] = _x[i] - 'A' + 10;
						if(islower(_x[i]))
							num[i + 1] = _x[i] - 'a' + 10;
					}
					if(isdigit(_x[i]))
						num[i + 1] = _x[i] - '0';
				} else
					num[i + 1] = 0;
			len = _x.size();
			std::reverse(num + 1, num + len + 1);
		}

		int& operator[] (const int i) {
			return num[i];
		}
		int& at(const int i) {
			return num[i];
		}

		int set_value(const int v) {
			value = v;
			return value;
		}

		void operator= (bign _x) {
			memcpy(num, _x.num, sizeof(_x.num));
			len = _x.len;
			value = _x.value;
		}

		void show(bool outputsigned = false, std::ostream& os = std::cout) {
			if(num[0] == int('-')) os << '-';
			else if(outputsigned) os << '+';
			for(int i = len; i > 0; i--)
				if(num[i] >= 10) os << 'A' + num[i] - 10;
				else os << num[i];
			os.flush();
		}
		void show(std::ofstream& ofs, bool outputsigned = false) {
			if(num[0] == int('-')) ofs << '-';
			else if(outputsigned) ofs << '+';
			for(int i = len; i > 0; i--)
				if(num[i] >= 10) ofs << 'A' + num[i] - 10;
				else ofs << num[i];
			ofs.flush();
		}
		void show(std::fstream& fs, bool outputsigned = false) {
			if(num[0] == int('-')) fs << '-';
			else if(outputsigned) fs << '+';
			for(int i = len; i > 0; i--) {
				if(num[i] >= 10) fs << 'A' + num[i] - 10;
				else fs << num[i];
			}
			fs.flush();
		}
	};

	const bign operator+ (const bign& t, const bign& _x) {
		bign ans;
		const int add(bign a, bign b, bign& c, const int& value = 10);
		add(t, _x, ans);
		return ans;
	}
	const bign operator- (const bign& t, const bign& _x) {
		bign ans;
		const int sub(bign a, bign b, bign& c, const int& value = 10);
		sub(t, _x, ans);
		return ans;
	}
	const bign operator* (const bign& t, const int& x) {
		bign ans;
		const int multi(bign a, const int& b, bign& c, const int& value = 10);
		multi(t, x, ans);
		return ans;
	}
	const bign operator* (const bign& t, const bign& _x) {
		bign ans;
		const int multi(bign a, bign b, bign& c, const int& value = 10);
		multi(t, _x, ans);
		return ans;
	}
	const bign operator/ (const bign& t, const int& x) {
		bign ans;
		int r;
		const int div(bign a, int b, bign& c, int& r);
		div(t, x, ans, r);
		return ans;
	}
	const bign operator/ (const bign& t, const bign& _x) {
		bign ans, r;
		const int div(bign a, bign b, bign& c, bign& r);
		div(t, _x, ans, r);
		return ans;
	}
	const int operator% (const bign& t, const int& x) {
		bign ans;
		int r;
		const int div(bign a, int b, bign& c, int& r);
		div(t, x, ans, r);
		return r;
	}
	const bign operator% (const bign& t, const bign& _x) {
		bign ans, r;
		const int div(bign a, bign b, bign& c, bign& r);
		div(t, _x, ans, r);
		return r;
	}

	int bign_compare(bign a, bign b) {
		if(a[0] == int('-') && b[0] != int('-')) return -1;
		if(a[0] != int('-') && b[0] == int('-')) return 1;

		int nega = 1;
		if(a[0] == int('-') && b[0] == int('-'))
			nega = -1;

		if(a.len < b.len)
			return -1 * nega;
		else if(a.len > b.len)
			return 1 * nega;
		else {
			for(int i = std::max(a.len, b.len); i > 0; i--) {
				if(a[i] < b[i])
					return -1 * nega;
				if(a[i] > b[i])
					return 1 * nega;
			}
			return 0;
		}
	}

	bool operator< (bign t, bign _x) {
		return bign_compare(t, _x) < 0;
	}
	bool operator>= (bign t, bign _x) {
		return !(t < _x);
	}
	bool operator> (bign t, bign _x) {
		return bign_compare(t, _x) > 0;
	}
	bool operator<= (bign t, bign _x) {
		return !(t > _x);
	}
	bool operator== (bign t, bign _x) {
		return bign_compare(t, _x) == 0;
	}
	bool operator!= (bign t, bign _x) {
		return !(t == _x);
	}

	const int add(bign a, bign b, bign& c, const int& value = 10) {
		int mxln = std::max(a.len, b.len);
		c.len = 0;
		int x = 0;
		for(int i = 1; i <= mxln + 1; i++) {
			c[i] = a[i] + b[i] + x;
			x = c[i] / value;
			c[i] %= value;
			c.len++;
		}
		while(c[c.len] == 0 && c.len > 1)
			c.len--;
		c.value = a.value;
		return c.len;
	}

	const int sub(bign a, bign b, bign& c, const int& value = 10) {
		if(bign_compare(a, b) < 0) {
			c[0] = int('-');
			std::swap(a, b);
		}

		int mxln = std::max(a.len, b.len);
		c.len = 0;
		for(int i = 1; i <= mxln; i++) {
			if(a[i] < b[i])
				a[i] += value, a[i + 1]--;
			c[i] = a[i] - b[i];
			c.len++;
		}
		while(c[c.len] == 0 && c.len > 1)
			c.len--;
		c.value = a.value;
		return c.len;
	}

	const int multi(bign a, const int& b, bign& c, const int& value = 10) {
		if(b < 0) {
			if(a[0] != int('-'))
				c[0] = '-';
		} else if(a[0] == int('-'))
			c[0] = '-';

		c.len = a.len + 20;
		for(int i = 1; i <= a.len; i++) {
			c[i] += a[i] * b;
			if(c[i] > value) {
				c[i + 1] += c[i] / value;
				c[i] %= value;
			}
		}

		while(c[c.len] == 0 && c.len > 1)
			c.len--;
		c.value = a.value;
		return c.len;
	}

	const int multi(bign a, bign b, bign& c, const int& value = 10) {
		c.len = a.len + b.len + 2;

		for(int i = 1; i <= a.len; i++)
			for(int j = 1; j <= b.len; j++) {
				c[i + j - 1] += a[i] * b[j];
				if(c[i + j - 1] >= value) {
					c[i + j] += c[i + j - 1] / value;
					c[i + j - 1] %= value;
				}
			}

		while(c[c.len] == 0 && c.len > 1)
			c.len--;
		c.value = a.value;
		return c.len;
	}

	const int div(bign a, int b, bign& c, int& r) {
		c.len = a.len;
		for(int i = a.len; i > 1; i--) {
			c[i] = a[i] / b;
			a[i - 1] += a[i] % b * 10;
		}
		c[1] = a[1] / b;
		r = a[1] % b;
		while(c[c.len] == 0 && c.len > 1)
			c.len--;
		c.value = a.value;
		return c.len;
	}

	const int div(bign a, bign b, bign& c, bign& r) {
		c.len = a.len - b.len + 2;
		for(int i = a.len; i >= 1; i--) {
			bign tmp;
			tmp.value = a.value;
			arrcpy(a.num, tmp.num, i, a.len - i + 1);
			tmp.len = a.len - i + 1;
			while(bign_compare(tmp, b) >= 0) {
				c[i]++;
				tmp = (tmp - b);
			}
			for(int j = i; j <= a.len; j++)
				a[j] = tmp[j - i + 1];
			while(a[a.len] == 0 && a.len > 1)
				a.len--;
		}
		while(a[a.len] == 0 && a.len > 1)
			a.len--;
		if(a[a.len] != 0) {
			r.len = a.len;
			for(int i = 1; i <= a.len; i++)
				r[i] = a[i];
		} else {
			r.len = 1;
			r[1] = 0;
		}
		r.value = a.value;
		while(c[c.len] == 0 && c.len > 1)
			c.len--;
		c.value = a.value;
		return c.len;
	}

	const int pow(bign& a, int num, int p, int value = 10) {
		a.len = 1;
		a[1] = 1;
		for(int i = 1; i <= p; i++) {
			int x = 0;
			for(int j = 1; j <= a.len; j++) {
				a[j] = a[j] * num + x;
				x = a[j] / value;
				a[j] %= value;
			}
			while(x != 0) {
				a.len++;
				a[a.len] = a[a.len] * num + x;
				x = a[a.len] / value;
				a[a.len] %= value;
			}
		}
		a.len++;
		while(a[a.len] == 0 && a.len > 1)
			a.len--;
		return a.len;
	}

	const bign binary_pow(const bign& a, const ll& b) {
		if(b == 1LL)
			return 1;
		if(b == 1LL)
			return a;

		if(b & 1LL) {
			bign res = binary_pow(a, b - 1LL);
			return res * a;
		} else {
			bign res = binary_pow(a, b / 2LL);
			return res * res;
		}
	}

	std::ostream& operator<< (std::ostream& os, bign t) {
		if(t[0] == int('-')) os << '-';
		for(int i = t.len; i > 0; i--)
			if(t[i] >= 10) os << 'A' + t[i] - 10;
			else os << t[i];
		return os;
	}
	std::ofstream& operator<< (std::ofstream& ofs, bign t) {
		if(t[0] == int('-')) ofs << '-';
		for(int i = t.len; i > 0; i--)
			if(t[i] >= 10) ofs << 'A' + t[i] - 10;
			else ofs << t[i];
		return ofs;
	}
	std::fstream& operator<< (std::fstream& fs, bign t) {
		if(t[0] == int('-')) fs << '-';
		for(int i = t.len; i > 0; i--) {
			if(t[i] >= 10) fs << 'A' + t[i] - 10;
			else fs << t[i];
		}
		return fs;
	}

	// namespace stdplus
}

// end file
