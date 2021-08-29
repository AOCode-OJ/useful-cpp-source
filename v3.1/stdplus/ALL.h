// Header File FOR ALL!
// File Name: ALL.h
// While using, don't forget the namespace!
// Namespace Name: stdplus

// begin WHOLE file

#include <bits/stdc++.h>

#define ll long long

namespace stdplus {}

////////////////////////////////////////////////
// File: declaring.h ///////////////////////////
////////////////////////////////////////////////

namespace stdplus {
	// declaring page

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

	// classes & structs

	template <class T> class AVL;
	struct bign;
	template <class T> class BST;
	class basic_graph;
	template <class T> class Circle;
	struct Fraction;
	template <class T> class handqueue;
	template <class T> class handstack;
	template <class T> class handdeque;
	template <class T> class List;
	template <class T> class Rectangle;
	template <class T> class Square;
	struct UFS;

	// functions

	const int add(bign, bign, bign&, const int& = 10);
	const int sub(bign, bign, bign&, const int& = 10);
	const int multi(bign, const int&, bign&, const int& = 10);
	const int multi(bign, bign, bign&, const int& = 10);
	const int div(bign, int, bign&, int&);
	const int div(bign, bign, bign&, bign&);

	Fraction& scanFrac(Fraction&, std::istream&);
	Fraction& scanFrac(Fraction& f, std::ifstream& ifs);
	void showFracResult(Fraction, bool = true, std::ostream& = std::cout);
	void showFracResult(Fraction r, std::ofstream& ofs, bool reduct = true);

	// namespace stdplus
}

////////////////////////////////////////////////
// File: my_maths.h ////////////////////////////
////////////////////////////////////////////////

// This file is for Mathematic operations
// File Name: my_maths.h

// begin file

namespace stdplus {

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

	std::string num_to_str(int x) {
		std::string s;
		int temp = x;
		while(temp > 0) {
			s = char(temp % 10 + '0') + s;
			temp /= 10;
		}
		return s;
	}

	int num_to_arr(int num, int arr[], bool num_reverse_stored = true) {
		if(num == 0)
			return arr[0] = 1, arr[1] = 0, 1;
		int len = 0;
		while(num != 0) {
			arr[++len] = num % 10;
			num /= 10;
		}
		arr[0] = len;
		if(!num_reverse_stored)
			std::reverse(arr + 1, arr + len + 1);
		return len;
	}
	int num_to_arr(ll num, int arr[], bool num_reverse_stored = true) {
		if(num == 0LL)
			return arr[0] = 1, arr[1] = 0, 1;
		int len = 0;
		while(num != 0LL) {
			arr[++len] = num % 10LL;
			num /= 10LL;
		}
		arr[0] = len;
		if(!num_reverse_stored)
			std::reverse(arr + 1, arr + len + 1);
		return len;
	}

	// This function is for copying arrays
	// use template
	template <class T> int arrcpy(T a[], T b[], int st, int pos) {
		for(int i = st; i <= st + pos - 1; i++)
			b[i - st + 1] = a[i];
		return pos;
	} // O(pos)

	// This function is for quick read(int)
	// *** Function Name: const int quick_read_int() ***
	const int quick_read_int() {
		int res = 0, negative = 1;
		char c = getchar();
		while((c < '0' || c > '9') && c != '-')
			c = getchar();
		while(c == '-')
			negative *= -1, c = getchar();
		while(c >= '0' && c <= '9')
			res = res * 10 + (c - '0'), c = getchar();
		return res * negative;
	}
#define qri quick_read_int
#define qrl quick_read_int

	// This function is for quick read(long long)
	// *** Function Name: const long long quick_read_ll() ***
	const ll quick_read_ll() {
		ll res = 0LL, negative = 1LL;
		char c = getchar();
		while((c < '0' || c > '9') && c != '-')
			c = getchar();
		while(c == '-')
			negative *= -1LL, c = getchar();
		while(c >= '0' && c <= '9')
			res = res * 10LL + (ll)(c - '0'), c = getchar();
		return res * negative;
	}
#define qrll quick_read_ll

	// This function is for quick read(double)
	// *** Function Name: const double quick_read_double(const std::string how_read) ***
	const double quick_read_double(const char& how_read = 'F') {
		double res, negative, points, final_e;
		const double binary_pow(const double&, const ll& );
		ll e;
		char c, e_ch;
		if(how_read == 'f' || how_read == 'F' || how_read == 'p' || how_read == 'P') {
			res = 0.0, negative = 1.0, points = 1.0;
			c = getchar();
			while((c < '0' || c > '9') && c != '-' && c != '.')
				c = getchar();
			while(c == '-')
				negative *= -1.0, c = getchar();
			while(c >= '0' && c <= '9')
				res = res * 10.0 + double(c - '0'), c = getchar();
			while(c == '.')
				c = getchar();
			while(c >= '0' && c <= '9')
				res = res * 10.0 + double(c - '0'), points *= 10.0, c = getchar();
			return res = (res * negative / points);
		} else if(how_read == 'e' || how_read == 'E') {
			res = 0.0, negative = 1.0, points = 1.0, e = 0LL, final_e = 0.0;
			c = getchar();
			while((c < '0' || c > '9') && c != '-' && c != '.')
				c = getchar();
			while(c == '-')
				negative *= -1.0, c = getchar();
			while(c >= '0' && c <= '9')
				res = res * 10.0 + double(c - '0'), c = getchar();
			while(c == '.')
				c = getchar();
			while(c >= '0' && c <= '9')
				res = res * 10.0 + double(c - '0'), points *= 10.0, c = getchar();
			while((c == 'e') || (c == 'E'))
				c = getchar();
			while((c == '-') || (c == '+'))
				e_ch = c;
			while(c >= '0' && c <= '9')
				e = e * 10LL + (ll)(c - '0');
			final_e = binary_pow(10.0, e);
			final_e = ((e_ch == '-') ? (1.0 / final_e) : (final_e));
			return res = (res * negative / points * final_e);
		} else {
			std::cerr << "CAN'T READ ---- SIGNAL ERROR!" << std::endl;
			exit(EXIT_FAILURE);
			return 0.0;
		}
	}
#define qrdb quick_read_double
#define qrf quick_read_double
#define qrlf quick_read_double

	template <class T, class streaminput> T get(streaminput& is = std::cin) {
		T res;
		is >> res;
		return res;
	}

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
			showFracResult(*this, reduct, os);
		}
	};

	std::ostream& operator<< (std::ostream& os, Fraction fraco) {
		fraco.show();
		return os;
	}
	std::istream& operator>> (std::istream& is, Fraction& fraco) {
		scanFrac(fraco, is);
		return is;
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

	Fraction& scanFrac(Fraction& f, std::istream& is) { // standard input(stdin)
		char c;
		is >> f.up >> c >> f.down;
		return f;
	}
	Fraction& scanFrac(Fraction& f, std::ifstream& ifs) { // file input
		char c;
		ifs >> f.up >> c >> f.down;
		return f;
	}
	void showFracResult(Fraction r, bool reduct, std::ostream& os) { // standard output(stdout)
		if(reduct)
			r.reduction();
		if(r.down == 1LL)
			os << r.up;
		else if(abs(r.up) > r.down)
			os << r.up / r.down << ' ' << abs(r.up) % r.down << '/' << r.down;
		else
			os << r.up << '/' << r.down;
	}
	void showFracResult(Fraction r, std::ofstream& ofs, bool reduct) { // file output
		if(reduct)
			r.reduction();
		if(r.down == 1LL)
			ofs << r.up;
		else if(abs(r.up) > r.down)
			ofs << r.up / r.down << ' ' << abs(r.up) % r.down << '/' << r.down;
		else
			ofs << r.up << '/' << r.down;
	}

	// Big Number Operation
	// *** Struct Name: struct bign ***
	struct bign {
		const static int MaxLen = 1005;
		int num[MaxLen];
		int len, value;
		bign() : len(0), value(10) {
			memset(num, 0, sizeof(num));
		}
		bign(int _x) {
			memset(num, 0, sizeof(num));
			num_to_arr(_x, num);
			len = num[0];
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
		}

		int& operator[] (const int i) {
			int& tmp = num[i];
			return tmp;
		}
		int& at(const int i) {
			int& tmp = num[i];
			return tmp;
		}

		int set_value(const int v) {
			value = v;
			return value;
		}

		void operator= (bign _x) {
			arrcpy(num, _x.num, 0, _x.len);
			len = _x.len;
		}
	};

	const bign operator+ (const bign& t, const bign& _x) {
		bign ans;
		add(t, _x, ans);
		return ans;
	}
	const bign operator- (const bign& t, const bign& _x) {
		bign ans;
		sub(t, _x, ans);
		return ans;
	}
	const bign operator* (const bign& t, const int& x) {
		bign ans;
		multi(t, x, ans);
		return ans;
	}
	const bign operator* (const bign& t, const bign& _x) {
		bign ans;
		multi(t, _x, ans);
		return ans;
	}
	const bign operator/ (const bign& t, const int& x) {
		bign ans;
		int r;
		div(t, x, ans, r);
		return ans;
	}
	const bign operator/ (const bign& t, const bign& _x) {
		bign ans;
		bign r;
		div(t, _x, ans, r);
		return ans;
	}
	const int operator% (const bign& t, const int& x) {
		bign ans;
		int r;
		div(t, x, ans, r);
		return r;
	}
	const bign operator% (const bign& t, const bign& _x) {
		bign ans;
		bign r;
		div(t, _x, ans, r);
		return r;
	}

	int bign_compare(bign a, bign b) {
		if(a[0] == int('-') && b[0] != int('-')) return -1;
		if(a[0] != int('-') && b[0] != int('-')) return 1;

		int nega = 1;
		if(a[0] == int('-') && b[0] == int('-'))
			nega = -1;

		if(a.len < b.len)
			return -1 * nega;
		else if(a.len > b.len)
			return 1 * nega;
		else {
			for(int i = 1; i <= a.len; i++) {
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

	const int add(bign a, bign b, bign& c, const int& value) {
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
		return c.len;
	}

	const int sub(bign a, bign b, bign& c, const int& value) {
		if(bign_compare(a, b) < 0) {
			c[0] = int('-');
			std::swap(a, b);
		}

		int mxln = std::max(a.len, b.len);
		c.len = 0;
		int x = 0;
		for(int i = 1; i <= mxln; i++) {
			if(a[i] < b[i])
				a[i] += value, a[i + 1]--;
			c[i] = a[i] - b[i];
			c.len++;
		}
		while(c[c.len] == 0 && c.len > 1)
			c.len--;
		return c.len;
	}

	const int multi(bign a, const int& b, bign& c, const int& value) {
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
		return c.len;
	}

	const int multi(bign a, bign b, bign& c, const int& value) {
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
		return c.len;
	}

	const int div(bign a, bign b, bign& c, bign& r) {
		c.len = a.len - b.len + 2;
		for(int i = a.len; i >= 1; i--) {
			bign tmp;
			arrcpy(a.num, tmp.num, i, a.len - i + 1);
			while(bign_compare(tmp, b) >= 0) {
				c[i]++;
				tmp = tmp - b;
			}
			for(int j = i; j <= a.len; j++)
				a[j] = tmp[j - i + 1];
		}
		while(a[a.len] == 0 && a.len > 1)
			a.len--;
		if(a[a.len] != 0) {
			r[0] = a.len;
			for(int i = 1; i <= a.len; i++)
				r[i] = a[i];
		} else {
			r[0] = 1;
			r[1] = 0;
		}
		while(c[c.len] == 0 && c.len > 1)
			c.len--;
		return c.len;
	}

	const int pow(bign& a, int num, int p, int value) {
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
			os << t[i];
		return os;
	}

	// namespace stdplus
}

// end file

////////////////////////////////////////////////
// File: Sorts.h ///////////////////////////////
////////////////////////////////////////////////

// This file is for sorts
// use templates
// File Name: Sorts.h

// begin file

namespace stdplus {

	template <class T> void merge(T a[], int l1, int r1, int l2, int r2) {
		T res[r1 - l1 + r2 - l2 + 5];
		int i = l1, j = l2, k = 0;
		while(i <= r1 && j <= r2)
			if(a[i] <= a[j])
				res[++k] = a[i++];
			else res[++k] = a[j++];
		while(i <= r1)
			res[++k] = a[i++];
		while(j <= r2)
			res[++k] = a[j++];

		for(i = l1, j = 1; j <= k; i++, j++) {
			a[i] = res[j];
			if(i == r1) i = l2 - 1;
		}
	}

	template <class T> void mergesort(T a[], int l, int r) {
		if(r - l == 0)
			return;

		int mid = (l + r) / 2;
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);

		merge(a, l, mid, mid + 1, r);
	}

	template <class T> int partition(T a[], int l, int r) {
		int k = a[l];
		int i = l, j = r;
		while(i < j) {
			while(a[j] > k && j > i)
				j--;
			a[l] = a[r];
			while(a[i] <= k && i < j)
				i++;
			a[r] = a[l];
		}
		a[i] = k;
		return i;
	}

	template <class T> void quicksort(T a[], int l, int r) {
		if(l < r) {
			int mid = partition(a, l, r);
			quicksort(a, l, mid - 1);
			quicksort(a, mid + 1, r);
		}
	}

	template <class T> int randPartition(T a[], int l, int r) {
		srand((unsigned)time(NULL));
		int p = (int)(round(1.0 * rand() / RAND_MAX * (r - l)) + l);
		swap(a[l], a[p]);

		int k = a[l];
		int i = l, j = r;
		while(i < j) {
			while(a[j] > k && j > i)
				j--;
			a[l] = a[r];
			while(a[i] <= k && i < j)
				i++;
			a[r] = a[l];
		}
		a[i] = k;
		return i;
	}

	template <class T> void randQuicksort(T a[], int l, int r) {
		if(l < r) {
			int mid = randPartition(a, l, r);
			quicksort(a, l, mid - 1);
			quicksort(a, mid + 1, r);
		}
	}

	template <class T> int randSelect(T a[], int l, int r, int k) {
		if(l == r)
			return a[l];

		int p = randPartition(a, l, r);
		int m = p - l + 1;
		if(k == m)
			return a[p];
		if(k < m)
			return randSelect(a, l, p - 1, k);
		else
			return randSelect(a, p + 1, r, k - m);
	}

	template <class T> void bubblesort(T a[], int l, int r) {
		int tmp = r - 1, flag = tmp;
		while(tmp > l) {
			flag = l;
			for(int j = l; j <= tmp; j++)
				if(a[j] > a[j + 1])
					swap(a[j], a[j + 1]), flag = j;
			tmp = flag;
		}
	}

	template <class T> void insertsort(T a[], int l, int r) {
		for(int i = l + 1; i <= r; i++) {
			int pl = i;
			for(int j = l; j < i; j++)
				if(a[j] > a[i]) {
					pl = j;
					break;
				}
			int tmp = a[i];
			for(int j = i; j > pl; j--)
				a[j] = a[j - 1];
			a[pl] = tmp;
		}
	}

	// namespace stdplus
}

// end file


////////////////////////////////////////////////
// File: algorithm.h ///////////////////////////
////////////////////////////////////////////////

// This file includes lots of algorithms, such as sorts, max&min, etc.
// So use it happily!

namespace stdplus {

	// compare algorithm

	// maximum(see C++ original header)
	// minimum(see C++ original header)

	// compare - you pass in(function form)
	template <class T, class compare> T funccmp(T& a, T& b, compare cmp) {
		return cmp(a, b) ? a : b;
	}

	// choose maximum cover
	template <class T> T chmax(T& a, T& b) {
		return a = b = (a > b ? a : b);
	}

	// choose minimum cover
	template <class T> T chmin(T& a, T& b) {
		return a = b = (a < b ? a : b);
	}

	// choose cover(compare way - you pass in in the form of function)
	template <class T, class compare> T chcov(T& a, T& b, compare cmp) {
		return a = b = (cmp(a, b) ? a : b);
	}


	// search algorithm

	// maximum element
	template <class T> int max_element(T a[], int l, int r) {
		T maxv = a[l];
		int pos = l;
		for(int i = l + 1; i <= r; ++i)
			if(a[i] > maxv) {
				maxv = a[i];
				pos = i;
			}
		return pos;
	}

	// minimum element
	template <class T> int min_element(T a[], int l, int r) {
		T minv = a[l];
		int pos = l;
		for(int i = l + 1; i <= r; ++i)
			if(a[i] < minv) {
				minv = a[i];
				pos = i;
			}
		return pos;
	}

	// binary search
	template <class T, class compare> bool binary_search(T a[], int l, int r, T val, compare cmp = std::less<T>()) {
		int mid = (l + r) / 2;
		if(a[mid] == val) return true;
		if(cmp(a[mid], val)) return binary_search(a, mid + 1, r, val, cmp);
		else return binary_search(a, l, mid - 1, val, cmp);
	}

	// lower bound
	template <class T, class compare> int lower_bound(T a[], int l, int r, T val, compare cmp = std::less<T>()) {
	}

	// upper bound
	template <class T, class compare> int upper_bound(T a[], int l, int r, T val, compare cmp = std::less<T>()) {
	}


	// change algorithm

	// fill
	template <class T> void fill(T a[], int l, int r, T val) {
		for(int i = l; i <= r; i++)
			a[i] = val;
	}

	// fill maximum
	template <class T> void fill_max(T a[], int l, int r) {
		int maxv = a[max_element(a, l, r)];
		for(int i = l; i <= r; i++)
			a[i] = maxv;
	}

	// fill minimum
	template <class T> void fill_min(T a[], int l, int r) {
		int minv = a[min_element(a, l, r)];
		for(int i = l; i <= r; i++)
			a[i] = minv;
	}


	// namespace stdplus
}

// end file


////////////////////////////////////////////////
// File: Types.h ///////////////////////////////
////////////////////////////////////////////////

// This file is for all types
// File Name: Types.h

// begin file

namespace stdplus {

#define rt root

	// Binary Search(Sort) Tree
	template <class T> class BST {
		public:
			typedef T value_type;

		public:
			struct node {
				value_type data;
				node* lchild;
				node* rchild;
				node() : data(value_type()), lchild(NULL), rchild(NULL) {}
			};
			node* newNode(const value_type& x) {
				node* Node = new node;
				Node->data = x;
				Node->lchild = Node->rchild = NULL;
				return Node;
			}
			int len;

		public:
			// Public Declarations
			node* root;
			BST() : root(NULL) {}
			value_type findMax(node* p) {
				while(p->rchild != NULL)
					p = p->rchild;
				return p.data;
			}
			value_type findMin(node* p) {
				while(p->lchild != NULL)
					p = p->lchild;
				return p.data;
			}
			bool find(value_type x, node* p) {
				if(p == NULL)
					return false;

				if(p->data == x)
					return true;
				else if(p->data > x)
					return find(x, p->lchild);
				else
					return find(x, p->rchild);
			}
			void insert(value_type x, node* &p) {
				if(p == NULL) {
					p = newNode(x);
					return;
				}

				if(x < p->data)
					insert(x, p->lchild);
				else
					insert(x, p->rchild);
			}
			void erase(value_type x, node* p) {
				if(p == NULL)
					return;
				if(p->data == x) {
					if(p->lchild == NULL && p->rchild == NULL)
						p = NULL;
					else if(p->lchild != NULL) {
						node* pre = findMax(p->lchild);
						p->data = pre->data;
						erase(pre->data, p->lchild);
					} else {
						node* next = findMin(p->rchild);
						p->data = next->data;
						erase(next->data, p->rchild);
					}
				} else if(x < p->data)
					erase(x, p->lchild);
				else
					erase(x, p->rchild);
			}
			void create(value_type data[], int n) {
				for(int i = 1; i <= n; i++)
					insert(data[i]);
			}
			// preorder
			template <class thingdone> void preorder(thingdone do_sth, node* p) {
				if(p == NULL)
					return;

				do_sth(p->data);
				preorder(do_sth, p->lchild);
				preorder(do_sth, p->rchild);
			}
			// inorder
			template <class thingdone> void inorder(thingdone do_sth, node* p) {
				if(p == NULL)
					return;

				inorder(do_sth, p->lchild);
				do_sth(p->data);
				inorder(do_sth, p->rchild);
			}
			// postorder
			template <class thingdone> void postorder(thingdone do_sth, node* p) {
				if(p == NULL)
					return;

				postorder(do_sth, p->lchild);
				postorder(do_sth, p->rchild);
				do_sth(p->data);
			}
			// LayerOrder
			template <class thingdone> void LayerOrder(thingdone do_sth, node* p) {
				if(p == NULL)
					return;
				std::queue<node*> q;
				q.push(p);
				while(!q.empty()) {
					node* now = q.front();
					q.pop();
					do_sth(now->data);
					if(now->lchild != NULL)
						q.push(now->lchild);
					if(now->rchild != NULL)
						q.push(now->rchild);
				}
			}
			value_type get(int pos) {
				if(pos == 1)
					return root->data;
				int tot = 1;
				std::queue<node* > q;
				q.push(root->lchild);
				q.push(root->rchild);
				while(!q.empty()) {
					node* now = q.front();
					q.pop();
					if(now == NULL)
						continue;
					tot++;
					if(tot == pos)
						return now->data;
				}
				if(tot < pos) {
					std::cerr << "Binary_tree get ERROR: POS OVERFLOW!" << std::endl;
					exit(EXIT_FAILURE);
				}
			}
	};

	template <class T> T max(const BST<T>& bst) {
		return bst.findMax(bst.rt);
	}
	template <class T> T min(const BST<T>& bst) {
		return bst.findMin(bst.rt);
	}

	// AVL tree (update for BST)
	template <class T> class AVL {
		public:
			typedef T value_type;
			friend class Map;

		public:
			// Private section
			struct node {
				value_type data;
				node* lchild;
				node* rchild;
				int height;
			};
			node* newNode(const value_type& x) {
				node* p = new node;
				p->data = x;
				p->height = 1;
				p->lchild = p->rchild = NULL;
				return p;
			}
			int getHeight(node* root) {
				if(root == NULL)
					return 0;
				return root->height;
			}
			int getBalanceFactor(node* root) {
				return getHeight(root->lchild) - getHeight(root->rchild);
			}
			void updateHeight(node* root) {
				root->height = max(getHeight(root->lchild), getHeight(root->rchild) + 1);
			}
			// Left Rotation
			void L(node*& root) {
				node* temp = root->rchild;
				root->rchild = temp->lchild;
				temp->lchild = root;
				updateHeight(root);
				updateHeight(temp);
				root = temp;
			}
			// Right Rotation
			void R(node*& root) {
				node* temp = root->lchild;
				root->lchild = temp->rchild;
				temp->rchild = root;
				updateHeight(root);
				updateHeight(temp);
				root = temp;
			}

		public:
			// Public Declarations
			node* root;

			node* find(value_type x, node* root) {
				if(root == NULL)
					return NULL;

				if(root->data == x)
					return root;
				else if(root->data > x)
					return find(x, root->lchild);
				else return find(x, root->rchild);
			}
			void insert(value_type x, node* &p) {
				if(p == NULL) {
					p = newNode(x);
					return;
				}

				if(x < p->data) {
					insert(x, p->lchild);
					updateHeight(p);
					if(getBalanceFactor(p->lchild) == 1)
						R(p);
					else if(getBalanceFactor(p->lchild) == -1) {
						L(p->lchild);
						R(p);
					}
				} else {
					insert(x, p->rchild);
					updateHeight(p);
					if(getBalanceFactor(p) == -2) {
						if(getBalanceFactor(p->rchild) == -1)
							L(p);
						else if(getBalanceFactor(p->rchild) == 1) {
							R(p->rchild);
							L(p);
						}
					}
				}
			}
			void Create(value_type data, int n) {
				node* root = NULL;
				for(int i = 1; i <= n; i++)
					insert(data[i], root);
			}
			// preorder
			template <class thingdone> void preorder(thingdone do_sth, node* root) {
				if(root == NULL)
					return;

				do_sth(root->data);
				preorder(root->lchild, do_sth);
				preorder(root->rchild, do_sth);
			}
			// inorder
			template <class thingdone> void inorder(thingdone do_sth, node* root) {
				if(root == NULL)
					return;

				inorder(root->lchild, do_sth);
				do_sth(root->data);
				inorder(root->rchild, do_sth);
			}
			// postorder
			template <class thingdone> void postorder(thingdone do_sth, node* root) {
				if(root == NULL)
					return;

				postorder(root->lchild, do_sth);
				postorder(root->rchild, do_sth);
				do_sth(root);
			}
			// LayerOrder
			template <class thingdone> void LayerOrder(thingdone do_sth, node* root) {
				std::queue<node* > q;
				q.push(root);
				while(!q.empty()) {
					node* now = q.front();
					q.pop();
					do_sth(now);
					if(now->lchild != NULL)
						q.push(now->lchild);
					if(now->rchild != NULL)
						q.push(now->rchild);
				}
			}
	};

	// Union-Find-Set declare here
	struct UFS {
		std::vector<int> father;

		UFS() {
			father = std::vector<int>();
		}
		UFS(int n) {
			father = std::vector<int>(n, -1);
		}
		int findFather(int x) {
			if(father[x] < 0)
				return x;
			return father[x] = findFather(father[x]);
		}
		void Union(int a, int b) {
			int faA = findFather(a);
			int faB = findFather(b);
			if(faA != faB) {
				father[faA] += father[faB];
				father[faB] = faA;
			}
		}
		int& operator[] (const int& pos) {
			return father[pos];
		}
	};

	// list(normal)
	template <class T> class List {
		public:
			typedef T        value_type;
			typedef size_t   size_type;

		public:
			struct node {
				value_type val;
				node* pre,* next;
				node() : pre(NULL), next(NULL) {};
				node(const value_type& _val) : val(_val) {};
			};
			node *head, *tail;
			size_type len;
			bool is_sorted;

			node* newNode(const value_type& _val) {
				node* p = new node(_val);
				return p;
			}
			void make_loop() {
				head->pre = tail;
				tail->next = head;
			}
			void make_connect(node* &front, node* &back) {
				front->next = back;
				back->pre = front;
			}

		public:
			List() : head(NULL), tail(NULL), len(0), is_sorted(false) {};
			void push_back(const value_type& val) {
				if(head == NULL) {
					head = newNode(val);
					tail = head;
					make_loop();
					return;
				}
				node* p = newNode(val);
				make_connect(tail, p);
				tail = p;
				make_loop();
				len++;
				is_sorted = false;
			}
			void pop_back() {
				if(head == NULL) {
					std::cerr << "List Pop Error: EMPTY LIST!" << std::endl;
					exit(EXIT_FAILURE);
				}
				if(head == tail) {
					delete head;
					head = tail = NULL;
					return;
				}
				node* p = tail->pre;
				delete tail;
				tail = p;
				make_loop();
				len--;
			}
			void push_front(const value_type& val) {
				if(head == NULL) {
					head = newNode(val);
					tail = head;
					make_loop();
					return;
				}
				node* p = newNode(val);
				make_connect(p, head);
				head = p;
				make_loop();
				len++;
				is_sorted = false;
			}
			void pop_front() {
				if(head == NULL) {
					std::cerr << "List Pop Error: EMPTY LIST!" << std::endl;
					exit(EXIT_FAILURE);
				}
				if(head == tail) {
					delete head;
					head = tail = NULL;
				}
				node* p = head->next;
				delete head;
				head = p;
				make_loop();
				len--;
			}
			template <class compare> void sort(compare cmp = std::less<value_type>()) {
				node* fr, ba;
				node* p;
				while(p != tail) {
					fr = p;
					ba = fr->next;
					while(ba != head) {
						if(cmp(ba->val, fr->val))
							if(fr == head) {
								node* ne = ba->next;
								make_connect(ba, fr);
								make_connect(fr, ne);
								head = ba;
								make_loop();
							} else {
								node* pr = fr->pre, ne = ba->next;
								make_connect(ba, fr);
								make_connect(pr, ba);
								make_connect(fr, ne);
							}
						fr = ba;
						ba = fr->next;
					}
					p = p->next;
				}
				is_sorted = true;
			}
			template <class compare> void insert_sort(const value_type& val, compare cmp = std::less<value_type>()) {
				if(!is_sorted) {
					std::cerr << "List Insert_sort Error: THE LIST IS NOT SORTED! " << std::endl;
					exit(EXIT_FAILURE);
				}
				if(cmp(val, head->val)) {
					push_front(val);
					is_sorted = true;
					len++;
					return;
				}
				if(cmp(tail->val, val)) {
					push_back(val);
					is_sorted = true;
					len++;
					return;
				}
				node* p = head->next;
				while(p != tail && !cmp(p->val, val))
					p = p->next;
				p = p->pre;
				node* q = newNode(val);
				make_connect(q, p->next);
				make_connect(p, q);
				make_loop();
				is_sorted = true;
			}
			bool empty() const {
				return (head == NULL && tail == NULL && len == 0);
			}
			size_type size() const {
				return len;
			}
		private:
			node* get_pos(const int& pos) {
				int mid = len / 2;
				if(pos > mid) {
					node* p = tail;
					int pos_new = len - pos;
					for(int i = 1; i <= pos_new; i++)
						p = p->pre;
					return p;
				} else {
					node* p = head;
					for(int i = 1; i <= pos; i++)
						p = p->next;
					return p;
				}
			}
		public:
			void insert(const value_type& val, const int& which) {
				if(which > len) {
					std::cerr << "List Insert Error: INSERT PLACE OVERFLOW! " << std::endl;
					exit(EXIT_FAILURE);
				}
				if(which == 0) {
					push_front(val);
					len++;
					return;
				}
				if(which == len) {
					push_back(val);
					len++;
					return;
				}
				node* p = get_pos(which);
				node* q = newNode(val);
				make_connect(q, p->next);
				make_connect(p, q);
				make_loop();
				is_sorted = false;
				len++;
			}

			value_type& front() {
				if(empty()) {
					std::cout << "List Get Front Error: THE LIST IS EMPTY! " << std::endl;
					exit(EXIT_FAILURE);
				}
				return head->val;
			}
			const value_type& front() const {
				if(empty()) {
					std::cout << "List Get Front Error: THE LIST IS EMPTY! " << std::endl;
					exit(EXIT_FAILURE);
				}
				return head->val;
			}
			value_type& back() {
				if(empty()) {
					std::cout << "List Get Back Error: THE LIST IS EMPTY! " << std::endl;
					exit(EXIT_FAILURE);
				}
				return tail->val;
			}
			const value_type& back() const {
				if(empty()) {
					std::cout << "List Get Back Error: THE LIST IS EMPTY! " << std::endl;
					exit(EXIT_FAILURE);
				}
				return tail->val;
			}
	};

	// namespace stdplus
}

////////////////////////////////////////////////
// File: my_defines.h //////////////////////////
////////////////////////////////////////////////

// This file is for all the defines.
// Go with it! It will be very helpful with you.

namespace stdplus {

#define pt(x) std::cout << (x)
#define ptn(x) std::cout << (x) << std::endl
#define sc(name) std::cin >> name
#define gc(name) name = getchar()
#define pc(c) putchar(char(c))
#define gs(cstr) gets(cstr)
#define ps(cstr) puts(cstr)
#define getl(str) std::getline(std::cin, str)
#define putl(str) std::cout << str << std::endl
#define fgetl(filestream, str) std::getline(filestream, str)
#define fputl(filestream, str) filestream << str << std::endl
#define freopi(name) freopen(name, "r", stdin)
#define freopo(name) freopen(name, "w", stdout)
#define fopi(name) fopen(name, "r")
#define fopo(name) fopen(name, "w")
#define fpt(filestream, x) filestream << (x)
#define fptn(filestream, x) filestream << (x) << std::endl
#define fsc(filestream, name) filestream >> x
#define pb push_back
#define mp make_pair

	// namespace stdplus
}

// end file

#undef ll

// end WHOLE file
