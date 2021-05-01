// Header File FOR ALL!
// File Name: ALL.h
// While using, don't forget the namespace!
// Namespace Name: stdplus

// begin WHOLE file

#include <bits/stdc++.h>

namespace stdplus {}

////////////////////////////////////////////////
// File: my_maths.h ////////////////////////////
////////////////////////////////////////////////

// This file is for Mathematic operations
// File Name: my_maths.h

// begin file

namespace stdplus {

	// Constants

	const long long LLINF = 0x7fffffffffffffffLL;
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

	// This function is for the Maximum of the two numbers
	// use template
	// *** Function Name: template <class T> T Max(T a, T b) ***
	template <class T> const T Max(const T& a, const T& b) {
		return (a > b ? a : b);
	}

	// This function is for the Minimum of the two numbers
	// use template
	// *** Function Name: template <class T> T Min(T a, T b) ***
	template <class T> const T Min(const T& a, const T& b) {
		return (a < b ? a : b);
	}

	// This function is for absolute value
	// use template
	// *** Function Name: template <class T> T abs(T a) ***
	template <class T> const T abs(const T& a) {
		return (a < 0 ? -a : a);
	}

	// This function is for the greatest common divisor
	// *** Function Name: const int gcd(const int& a, const int& b) ***
	const int gcd(const int& a, const int& b) {
		if(b == 0) return a;
		else return gcd(b, a % b);
	}

	// Reload gcd
	// *** Function Name: const long long gcd(const long long& a, const long long& b) ***
	const long long gcd(const long long& a, const long long& b) {
		if(b == 0LL) return a;
		else return gcd(b, a % b);
	}

	// This function is for the least common multiple
	// *** Function Name: const int lcm(const int& a, const int& b) ***
	const int lcm(const int& a, const int& b) {
		return (a / gcd(a, b) * b);
	}

	// Reload lcm
	// *** Function Name: const long long lcm(const long long& a, const long long& b) ***
	const long long lcm(const long long& a, const long long& b) {
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
	const long long pow(const long long& a, const int& b) {
		long long res = 1LL;
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
	const long long pow_mod(const long long& a, const int& b, const long long& k) {
		int res = 1LL;
		for(int i = 1; i <= b; i++)
			res = res * (a % k) % k;
		return res;
	} // O(b)

	// This function is for binary power
	// *** Function Name: const int binary_pow(const int& a, const long long& b) ***
	const int binary_pow(const int& a, const long long& b) {
		if(b == 1LL) return 1;
		if(b == 1LL) return a;

		if(b & 1LL)
			return a * binary_pow(a, b - 1LL);
		else {
			int res = binary_pow(a, b / 2LL);
			return res * res;
		}
	} // O(log_2 b)

	// Reload binary_pow
	// *** Function Name: const long long binary_pow(const long long& a, const long long& b) ***
	const long long binary_pow(const long long& a, const long long& b) {
		if(b == 1LL) return 1LL;
		if(b == 1LL) return a;

		if(b & 1LL)
			return a * binary_pow(a, b - 1LL);
		else {
			long long res = binary_pow(a, b / 2LL);
			return res * res;
		}
	} // O(log_2 b)

	// Reload binary_pow
	// *** Function Name: const double binary_pow(const double& a, const long long& b) ***
	const double binary_pow(const double& a, const long long& b) {
		if(b == 0LL) return 1.0;
		if(b == 1LL) return a;

		if(b & 1LL)
			return a * binary_pow(a, b - 1LL);
		else {
			double res = binary_pow(a, b / 2LL);
			return res * res;
		}
	} // O(log_2 b)

	// This function is for (binary_pow + mod)
	// *** Function Name: const int binary_pow_mod(const int& a, const long long& b, const int& k) ***
	const int binary_pow_mod(const int& a, const long long& b, const int& k) {
		if(b == 0LL) return 1 % k;
		if(b == 1LL) return a % k;

		if(b & 1LL)
			return ((a % k) * (binary_pow_mod(a, b - 1LL, k))) % k;
		else {
			int res = binary_pow_mod(a, b / 2LL, k);
			return (res * res) % k;
		}
	} // O(log_2 b)

	// Reload binary_pow_mod
	// *** Function Name: const long long binary_pow_mod(const long long& a, const long long& b, const long long& k) ***
	const long long binary_pow_mod(const long long& a, const long long& b, const long long& k) {
		if(b == 0LL) return 1LL % k;
		if(b == 1LL) return a % k;

		if(b & 1LL)
			return ((a % k) * (binary_pow_mod(a, b - 1LL, k))) % k;
		else {
			long long res = binary_pow_mod(a, b / 2LL, k);
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
			else r = mid;
		}
		return r;
	} // O(log_2 x/eps)
	const long long sqrt(const long long& x) {
		long long l = 1LL, r = 2000000000LL;
		while(r - l > 1LL) {
			long long mid = (l + r) / 2LL;
			if(mid * mid <= x) l = mid;
			else r = mid;
		}
		return r;
	} // O(log_2 x)
	const int sqrt(const int& x) {
		int l = 1, r = 50000;
		while(r - l > 1) {
			long long mid = (l + r) / 2;
			if(mid * mid <= x) l = mid;
			else r = mid;
		}
		return r;
	} // O(log_2 x)

	// This function is for turning array(int) to std::string
	std::string array_to_string(int x[], int len) {
		std::string s;
		for(int i = len; i >= 1; i--)
			s += char(x[i] + '0');
		return s;
	} // O(len)

	// This function is for turning std::string to array(int)
	int string_to_array(std::string s, int x[]) {
		for(int i = 0; i < s.size(); i++)
			x[s.size() - i] = s[i] - '0';
		return s.size();
	} // O(s.size())

	// This function is for turning number(int) to std::string
	std::string num_to_string(int x) {
		std::string s;
		int temp = x;
		while(temp > 0) {
			s = char(temp % 10 + '0') + s;
			temp /= 10;
		}
		return s;
	} // O(??)

	// This function is for turning std::string to number(int)
	void string_to_num(const std::string& s, int& x) {
		x = 0;
		for(int i = 0; i < s.size(); i++)
			x = x * 10 +(s[i] - '0');
	} // O(s.size())

	// Reload string_to_num
	int string_to_num(const std::string& s) {
		int x = 0;
		for(int i = 0; i < s.size(); i++)
			x = x * 10 +(s[i] - '0');
		return x;
	} // O(s.size())

	// This function is for copying arrays
	// use template
	template <class T> int arrcpy(T a[], T b[], int st, int pos) {
		for(int i = st; i <= st + pos - 1; i++)
			b[i - st + 1] = a[i];
		return pos;
	} // O(pos)

	// This function is for comparing arrays
	int arr_compare(int a[], int b[], int lena, int lenb) {
		std::string a1 = array_to_string(a, lena), b1 = array_to_string(b, lenb);
		if(a1.size() < b1.size()) return -1;
		if(a1.size() > b1.size()) return 1;
		if(a1 < b1) return -1;
		if(a1 > b1) return 1;
		return 0;
	} // O(max(lena, lenb))

	// This function is for quick read(int)
	// *** Function Name: const int quick_read_int() ***
	const int quick_read_int() {
		int res = 0, negative = 1;
		char c = getchar();
		while((c < '0' || c > '9') && c != '-') c = getchar();
		while(c == '-') negative *= -1, c = getchar();
		while(c >= '0' && c <= '9') res = res * 10 + (c - '0'), c = getchar();
		return res * negative;
	}
#define qri quick_read_int
#define qrl quick_read_int

	// This function is for quick read(long long)
	// *** Function Name: const long long quick_read_ll() ***
	const long long quick_read_ll() {
		long long res = 0LL, negative = 1LL;
		char c = getchar();
		while((c < '0' || c > '9') && c != '-') c = getchar();
		while(c == '-') negative *= -1LL, c = getchar();
		while(c >= '0' && c <= '9') res = res * 10LL + (long long)(c - '0'), c = getchar();
		return res * negative;
	}
#define qrll quick_read_ll

	// This function is for quick read(double)
	// *** Function Name: const double quick_read_double(const std::string how_read) ***
	const double quick_read_double(const char& how_read = 'F') {
		double res, negative, points, final_e, binary_pow(const double&, const long long&);
		long long e;
		char c, e_ch;
		if(how_read == 'f' || how_read == 'F' || how_read == 'p' || how_read == 'P') {
			res = 0.0, negative = 1.0, points = 1.0;
			c = getchar();
			while((c < '0' || c > '9') && c != '-' && c != '.') c = getchar();
			while(c == '-') negative *= -1.0, c = getchar();
			while(c >= '0' && c <= '9') res = res * 10.0 + double(c - '0'), c = getchar();
			while(c == '.') c = getchar();
			while(c >= '0' && c <= '9') res = res * 10.0 + double(c - '0'), points *= 10.0, c = getchar();
			return res = (res * negative / points);
		} else if(how_read == 'e' || how_read == 'E') {
			res = 0.0, negative = 1.0, points = 1.0, e = 0LL, final_e = 0.0;
			c = getchar();
			while((c < '0' || c > '9') && c != '-' && c != '.') c = getchar();
			while(c == '-') negative *= -1.0, c = getchar();
			while(c >= '0' && c <= '9') res = res * 10.0 + double(c - '0'), c = getchar();
			while(c == '.') c = getchar();
			while(c >= '0' && c <= '9') res = res * 10.0 + double(c - '0'), points *= 10.0, c = getchar();
			while((c == 'e') || (c == 'E')) c = getchar();
			while((c == '-') || (c == '+')) e_ch = c;
			while(c >= '0' && c <= '9') e = e * 10LL + (long long)(c - '0');
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
		long long up, down;
		Fraction() : up(0LL), down(0LL) {}
		Fraction(long long _up, long long _down) : up(_up), down(_down) {}
		Fraction(const Fraction& fraco) : up(fraco.up), down(fraco.down) {}
		Fraction& operator= (const Fraction& fraco) {
			up = fraco.up;
			down = fraco.down;
		}
		Fraction reduction() {
			const Fraction Frac_reduction(Fraction);
			return *this = Frac_reduction(*this);
		}
		void show(bool reduct = true, std::ostream& os = std::cout) {
			void showFracResult(Fraction, bool = true, std::ostream& = std::cout);
			showFracResult(*this, reduct, os);
		}
	};

	std::ostream& operator<< (std::ostream& os, Fraction fraco) {
		fraco.show();
		return os;
	}
	std::istream& operator>> (std::istream& is, Fraction& fraco) {
		Fraction scanFrac(Fraction&, std::istream&);
		scanFrac(fraco, is);
		return is;
	}

	Fraction operator+ (const Fraction& t, const Fraction& fraco) {
		const Fraction Frac_add(const Fraction&, const Fraction&);
		return Frac_add(t, fraco);
	}
	Fraction operator- (const Fraction& t, const Fraction& fraco) {
		const Fraction Frac_minu(const Fraction&, const Fraction&);
		return Frac_minu(t, fraco);
	}
	Fraction operator* (const Fraction& t, const Fraction& fraco) {
		const Fraction Frac_multi(const Fraction&, const Fraction&);
		return Frac_multi(t, fraco);
	}
	Fraction operator/ (const Fraction& t, const Fraction& fraco) {
		const Fraction Frac_divide(const Fraction&, const Fraction&);
		return Frac_divide(t, fraco);
	}

	const Fraction Frac_reduction(Fraction result) {
		if(result.down < 0LL) {
			result.up = -result.up;
			result.down = -result.down;
		}

		if(result.up == 0LL) result.down = 1LL;
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
	void showFracResult(Fraction r, bool reduct = true, std::ostream& os = std::cout) { // standard output(stdout)
		if(reduct) r.reduction();
		if(r.down == 1LL) os << r.up;
		else if(abs(r.up) > r.down)
			os << r.up / r.down << ' ' << abs(r.up) % r.down << '/' << r.down;
		else os << r.up << '/' << r.down;
	}
	void showFracResult(Fraction r, std::ofstream& ofs, bool reduct = true) { // file output
		if(reduct) r.reduction();
		if(r.down == 1LL) ofs << r.up;
		else if(abs(r.up) > r.down)
			ofs << r.up / r.down << ' ' << abs(r.up) % r.down << '/' << r.down;
		else ofs << r.up << '/' << r.down;
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
		bign(int _x, int _value = 10) : value(_value) {
			memset(num, 0, sizeof(num));
			std::string s = num_to_string(_x);
			len = string_to_array(s, num);
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
		}

		void operator= (bign _x) {
			arrcpy(num, _x.num, 0, _x.len);
			len = _x.len;
		}

		const int to_number() {
			std::string s = array_to_string(num, len);
			int x = string_to_num(s);
			return x;
		}
		const std::string to_string() {
			std::string s = array_to_string(num, len);
			return s;
		}
		const char* to_cstring() {
			std::string s = array_to_string(num, len);
			const char* ch = s.c_str();
			return ch;
		}
	};

	const bign operator+ (const bign& t, const bign& _x) {
		int bign_add(bign, bign, bign&, const int& = 10);
		bign ans;
		bign_add(t, _x, ans);
		return ans;
	}
	const bign operator- (const bign& t, const bign& _x) {
		int bign_sub(bign, bign, bign&, const int& = 10);
		bign ans;
		bign_sub(t, _x, ans);
		return ans;
	}
	const bign operator* (const bign& t, const int& x) {
		int bign_multi(bign, const int&, bign&, const int& = 10);
		bign ans;
		bign_multi(t, x, ans);
		return ans;
	}
	const bign operator* (const bign& t, const bign& _x) {
		int bign_multi(bign, bign, bign&, const int& = 10);
		bign ans;
		bign_multi(t, _x, ans);
	}
	const bign operator/ (const bign& t, const int& x) {
		int bign_divide(bign, int, bign&, int&);
		bign ans;
		int r;
		bign_divide(t, x, ans, r);
		return ans;
	}
	const bign operator/ (const bign& t, const bign& _x) {
		int bign_divide(bign, bign, bign&, bign&);
		bign ans;
		bign r;
		bign_divide(t, _x, ans, r);
		return ans;
	}
	const int operator% (const bign& t, const int& x) {
		int bign_divide(bign, int, bign&, int&);
		bign ans;
		int r;
		bign_divide(t, x, ans, r);
		return r;
	}
	const bign operator% (const bign& t, const bign& _x) {
		int bign_divide(bign, bign, bign&, bign&);
		bign ans;
		bign r;
		bign_divide(t, _x, ans, r);
		return r;
	}

	bool operator< (bign t, bign _x) {
		return arr_compare(t.num, _x.num, t.len, _x.len) < 0;
	}
	bool operator>= (bign t, bign _x) {
		return !(t < _x);
	}
	bool operator> (bign t, bign _x) {
		return arr_compare(t.num, _x.num, t.len, _x.len) > 0;
	}
	bool operator<= (bign t, bign _x) {
		return !(t > _x);
	}
	bool operator== (bign t, bign _x) {
		return arr_compare(t.num, _x.num, t.len, _x.len) == 0;
	}
	bool operator!= (bign t, bign _x) {
		return !(t == _x);
	}

	const int bign_add(bign a, bign b, bign& c, const int& value = 10) {
		int mxln = Max(a.len, b.len);
		c.len = 0;
		int x = 0;
		for(int i = 1; i <= mxln + 1; i++) {
			c[i] = a[i] + b[i] + x;
			x = c[i] / value;
			c[i] %= value;
			c.len++;
		}
		while(c[c.len] == 0 && c.len > 1) c.len--;
		return c.len;
	}

	const int bign_sub(bign a, bign b, bign& c, const int& value = 10) {
		if(arr_compare(a.num, b.num, a.len, b.len) < 0) {
			c[0] = int('-');
			std::swap(a, b);
		}

		int mxln = std::max(a.len, b.len);
		c.len = 0;
		int x = 0;
		for(int i = 1; i <= mxln; i++) {
			if(a[i] < b[i]) a[i] += value, a[i + 1]--;
			c[i] = a[i] - b[i];
			c.len++;
		}
		while(c[c.len] == 0 && c.len > 1) c.len--;
		return c.len;
	}

	const int bign_multi(bign a, const int& b, bign& c, const int& value = 10) {
		c.len = a.len + 20;

		for(int i = 1; i <= a.len; i++) {
			c[i] += a[i] * b;
			if(c[i] > value) {
				c[i + 1] += c[i] / value;
				c[i] %= value;
			}
		}

		while(c[c.len] == 0 && c.len > 1) c.len--;
		return c.len;
	}

	const int bign_multi(bign a, bign b, bign& c, const int& value = 10) {
		c.len = a.len + b.len + 2;

		for(int i = 1; i <= a.len; i++)
			for(int j = 1; j <= b.len; j++) {
				c[i + j - 1] += a[i] * b[j];
				if(c[i + j - 1] >= value) {
					c[i + j] += c[i + j - 1] / value;
					c[i + j - 1] %= value;
				}
			}

		while(c[c.len] == 0 && c.len > 1) c.len--;
		return c.len;
	}

	const int bign_divide(bign a, int b, bign& c, int& r) {
		c.len = a.len;
		for(int i = a.len; i > 1; i--) {
			c[i] = a[i] / b;
			a[i - 1] += a[i] % b * 10;
		}
		c[1] = a[1] / b;
		r = a[1] % b;
		while(c[c.len] == 0 && c.len > 1) c.len--;
		return c.len;
	}

	const int bign_divide(bign a, bign b, bign& c, bign& r) {
		c.len = a.len - b.len + 2;
		for(int i = a.len; i >= 1; i--) {
			bign tmp;
			arrcpy(a.num, tmp.num, i, a.len - i + 1);
			while(arr_compare(tmp.num, b.num, a.len - i + 1, b.len) >= 0) {
				c[i]++;
				tmp = tmp - b;
			}
			for(int j = i; j <= a.len; j++)
				a[j] = tmp[j - i + 1];
		}
		while(a[a.len] == 0 && a.len > 1) a.len--;
		if(a[a.len] != 0) {
			r[0] = a.len;
			for(int i = 1; i <= a.len; i++)
				r[i] = a[i];
		} else {
			r[0] = 1;
			r[1] = 0;
		}
		while(c[c.len] == 0 && c.len > 1) c.len--;
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
		while(a[a.len] == 0 && a.len > 1) a.len--;
		return a.len;
	}

	const bign binary_pow(const bign& a, const long long& b) {
		if(b == 1LL) return 1;
		if(b == 1LL) return a;

		if(b & 1LL) {
			bign res = binary_pow(a, b - 1LL);
			return res * a;
		} else {
			bign res = binary_pow(a, b / 2LL);
			return res * res;
		}
	}

	// namespace stdplus
}

// end file

////////////////////////////////////////////////
// File: Sorts.h ///////////////////////////////
////////////////////////////////////////////////

// This file if for sorts
// use templates
// File Name: Sorts.h

// begin file

namespace stdplus {

	template <class T> void mergesort(T a[], int l, int r) {
		if(r - l == 0) return;

		int mid = (l + r) / 2;
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);

		T res[r - l + 5];
		int i = l, j = mid + 1, k = 0;
		while(i <= mid && j <= r)
			if(a[i] <= a[j])
				res[++k] = a[i++];
			else res[++k] = a[j++];
		while(i <= mid)
			res[++k] = a[i++];
		while(j <= r)
			res[++k] = a[j++];

		for(i = l, j = 1; j <= k; i++, j++)
			a[i] = res[j];
	}

	template <class T> int partition(T a[], int l, int r) {
		int k = a[l];
		int i = l, j = r;
		while(i < j) {
			while(a[j] > k && j > i) j--;
			a[l] = a[r];
			while(a[i] <= k && i < j) i++;
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
			while(a[j] > k && j > i) j--;
			a[l] = a[r];
			while(a[i] <= k && i < j) i++;
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
		if(l == r) return a[l];

		int p = randPartition(a, l, r);
		int m = p - l + 1;
		if(k == m) return a[p];
		if(k < m) return randSelect(a, l, p - 1, k);
		else return randSelect(a, p + 1, r, k - m);
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
// File: Types.h ///////////////////////////////
////////////////////////////////////////////////

// This file is for all types
// File Name: Types.h

// begin file

namespace stdplus {

	// reverse_iterator base define here
	template <class T> class reverse_iterator {
		public:
			typedef T                   value_type;
			typedef value_type&         reference;
			typedef const value_type&   const_reference;
			typedef value_type*         pointer;
			typedef const value_type*   const_pointer;

		private:
			pointer re;

		public:
			reverse_iterator(pointer other) : re(other) {}
			reverse_iterator(reverse_iterator& other) : re(other.get()) {}

			pointer& get() {
				return re;
			}

			reverse_iterator operator++ () {
				re++;
			}
	};

	template <class T> std::ostream& operator<< (std::ostream& os, reverse_iterator<T> out) {
	}

#define rt root

	// Binary Search(Sort) Tree
	template <class T> class BST {
		public:
			typedef T value_type;

		private:
			// Private section
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
				while(p->rchild != NULL) p = p->rchild;
				return p.data;
			}
			value_type findMin(node* p) {
				while(p->lchild != NULL)
					p = p->lchild;
				return p.data;
			}
			bool find(value_type x, node* p) {
				if(p == NULL) return false;

				if(p->data == x) return true;
				else if(p->data > x) return find(x, p->lchild);
				else return find(x, p->rchild);
			}
			void insert(value_type x, node*& p) {
				if(p == NULL) {
					p = newNode(x);
					return;
				}

				if(x < p->data) insert(x, p->lchild);
				else insert(x, p->rchild);
			}
			void erase(value_type x, node* p) {
				if(p == NULL) return;
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
				else erase(x, p->rchild);
			}
			void create(value_type data[], int n) {
				for(int i = 1; i <= n; i++)
					insert(data[i]);
			}
			// preorder
			template <class thingdone> void preorder(thingdone do_sth, node* p) {
				if(p == NULL) return;

				do_sth(p->data);
				preorder(do_sth, p->lchild);
				preorder(do_sth, p->rchild);
			}
			// inorder
			template <class thingdone> void inorder(thingdone do_sth, node* p) {
				if(p == NULL) return;

				inorder(do_sth, p->lchild);
				do_sth(p->data);
				inorder(do_sth, p->rchild);
			}
			// postorder
			template <class thingdone> void postorder(thingdone do_sth, node* p) {
				if(p == NULL) return;

				postorder(do_sth, p->lchild);
				postorder(do_sth, p->rchild);
				do_sth(p->data);
			}
			// LayerOrder
			template <class thingdone> void LayerOrder(thingdone do_sth, node* p) {
				if(p == NULL) return;
				std::queue<node*> q;
				q.push(p);
				while(!q.empty()) {
					node* now = q.front();
					q.pop();
					do_sth(now->data);
					if(now->lchild != NULL) q.push(now->lchild);
					if(now->rchild != NULL) q.push(now->rchild);
				}
			}
			value_type get(int pos) {
				if(pos == 1) return root->data;
				int tot = 1;
				std::queue<node*> q;
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

		private:
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
				if(root == NULL) return 0;
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
				if(root == NULL) return NULL;

				if(root->data == x) return root;
				else if(root->data > x) return find(x, root->lchild);
				else return find(x, root->rchild);
			}
			void insert(value_type x, node*& p) {
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
				if(root == NULL) return;

				do_sth(root->data);
				preorder(root->lchild, do_sth);
				preorder(root->rchild, do_sth);
			}
			// inorder
			template <class thingdone> void inorder(thingdone do_sth, node* root) {
				if(root == NULL) return;

				inorder(root->lchild, do_sth);
				do_sth(root->data);
				inorder(root->rchild, do_sth);
			}
			// postorder
			template <class thingdone> void postorder(thingdone do_sth, node* root) {
				if(root == NULL) return;

				postorder(root->lchild, do_sth);
				postorder(root->rchild, do_sth);
				do_sth(root);
			}
			// LayerOrder
			template <class thingdone> void LayerOrder(thingdone do_sth, node* root) {
				std::queue<node*> q;
				q.push(root);
				while(!q.empty()) {
					node* now = q.front();
					q.pop();
					do_sth(now);
					if(now->lchild != NULL) q.push(now->lchild);
					if(now->rchild != NULL) q.push(now->rchild);
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
			if(father[x] < 0) return x;
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

	// pair(normal)
	template <class T1, class T2> struct Pair {
		typedef T1   first_type;
		typedef T2   second_type;

		first_type first;
		second_type second;

		Pair() {
			first = second = 0;
		}
		template <class U, class V> Pair(const Pair<U, V>& pr) {
			first = pr.first;
			second = pr.second;
		}
		Pair(const first_type& a, const second_type& b) {
			first = a;
			second = b;
		}
		Pair& operator= (Pair& x) {
			first = x.first;
			second = x.second;
		}
		bool operator== (const Pair& rhs) {
			return first == rhs.first && second == rhs.second;
		}
		bool operator!= (const Pair& rhs) {
			return !(*this == rhs);
		}
		bool operator<  (const Pair& rhs) {
			return first < rhs.first || (!(rhs.first < first) && second < rhs.second);
		}
		bool operator<= (const Pair& rhs) {
			return !(rhs < *this);
		}
		bool operator>  (const Pair& rhs) {
			return rhs < *this;
		}
		bool operator>= (const Pair& rhs) {
			return !(*this < rhs);
		}
#if __cplusplus >= 201103L
		void swap(Pair& pr) noexcept(noexcept(swap(first,pr.first)) && noexcept(swap(second,pr.second))) {
			swap(first, pr.first);
			swap(second, pr.second);
		}
#endif
	};

	template <class T1, class T2> Pair<T1, T2> make_Pair(T1 a, T2 b) {
		return Pair<T1, T2>(a, b);
	}

	// queue(normal)
	template <class T, class Container = std::deque<T> > class Queue {
		public:
			typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;

		private:
			container_type con;

		public:
			Queue(const container_type& ctnr = container_type()) {
				con = ctnr;
			}
			bool empty() const {
				return con.empty();
			}
			size_type size() const {
				return con.size();
			}
			value_type& front() {
				return con.front();
			}
			const value_type& front() const {
				return con.front();
			}
			value_type& back() {
				return con.back();
			}
			const value_type& back() const {
				return con.back();
			}
			void push(const value_type& val) {
				con.push_back(val);
			}
			void pop() {
				con.pop_front();
			}
			void clear() {
				con.clear();
			}

#if cplusplus >= 201103L
			template <class... Args> void emplace (Args&&... args);
			void swap(Queue& x) noexcept();
#endif
	};

	// stack(normal)
	template <class T, class Container = std::deque<T> > class Stack {
		public:
			typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;

		private:
			container_type con;

		public:
			Stack(const container_type& ctnr = container_type()) {
				con = ctnr;
			}
			bool empty() const {
				return con.empty();
			}
			size_type size() const {
				return con.size();
			}
			value_type& top() {
				return con.back();
			}
			const value_type& top() const {
				return con.back();
			}
			void push(const value_type& val) {
				con.push_back(val);
			}
			void pop() {
				con.pop_back();
			}
			void clear() {
				con.clear();
			}

#if cplusplus >= 201103L
			template <class... Args> void emplace(Args&&... args);
			void swap(Stack& x) noexcept();
#endif
	};

	// priority_queue(heap)
	template <class T, class Container = std::vector<T>,
	         class Compare = std::less<typename Container::value_type> > class Priority_Queue {
		public:
			typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;

		private:
			container_type con;
			Compare comp;

		public:
			Priority_Queue(const Compare& comp = Compare(),
			               const Container& ctnr = container_type()) {
				con = ctnr;
				make_heap(con.begin(), con.end(), comp);
			}
			bool empty() const {
				return con.empty();
			}
			size_type size() const {
				return con.size();
			}
			value_type& top() {
				return con.front();
			}
			const value_type& top() const {
				return con.front();
			}
			void push(const value_type& val) {
				con.push_back();
				push_heap(con.begin(), con.end(), comp);
			}
			void pop() {
				pop_heap(con.begin(), con.end(), comp);
				con.pop_back();
			}
			void clear() {
				con.clear();
				make_heap(con.begin(), con.end());
			}

#if cplusplus >= 201103L
			template <class... Args> void emplace (Args&&... args);
			void swap (Priority_Queue& x) noexcept();
#endif
	};

	// list(normal)
	template <class T> class List {
		public:
			typedef T        value_type;
			typedef size_t   size_type;

		private:
			struct node {
				value_type val;
				node *pre, *next;
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
				while(p != tail && !cmp(p->val, val)) p = p->next;
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
					for(int i = 1; i <= pos_new; i++) p = p->pre;
					return p;
				} else {
					node* p = head;
					for(int i = 1; i <= pos; i++) p = p->next;
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

	template <class T> class handqueue {
		public:
			typedef T                   value_type;
			typedef value_type&         reference;
			typedef const value_type&   const_reference;
			typedef value_type*         pointer;
			typedef const value_type*   const_pointer;
			// Here iterator is simular to pointer
			typedef value_type*         iterator;
			typedef const value_type*   const_iterator;
			typedef size_t              size_type;
			static const int maxlen = 500000;

		private:
			value_type q[500005];
			int f, r;

		public:
			handqueue() : f(0), r(0) {
				memset(q, value_type(), sizeof(q));
			}

			bool empty() {
				return f == r;
			}
			bool full() {
				return (r - f) >= maxlen;
			}

			size_type size() {
				return r - f;
			}

			void push(value_type val) {
				assert(full());
				q[r++ % maxlen] = val;
			}
			void pop() {
				assert(empty());
				++f;
				if(f >= maxlen) f -= maxlen, r -= maxlen;
			}
			void clear() {
				f = r = 0;
			}

			reference front() {
				assert(empty());
				return q[f % maxlen];
			}
			reference back() {
				assert(empty());
				return q[(r - 1) % maxlen];
			}
			const_reference front() const {
				assert(empty());
				return q[f % maxlen];
			}
			const_reference back() const {
				assert(empty());
				return q[(r - 1) % maxlen];
			}

			reference operator[] (int pos) {
				return q[(f + pos) % maxlen];
			}
			reference at(int pos) {
				return q[(f + pos) % maxlen];
			}
	};

	// straight output to type handqueue
	template <class T> std::ostream& operator<< (std::ostream& os, handqueue<T> hq) {
		for(int i = 1; i <= hq.size(); i++)
			os << hq[i] << std::endl;
		return os;
	}

	template <class T> class handstack {
		public:
			typedef T                   value_type;
			typedef value_type&         reference;
			typedef const value_type&   const_reference;
			typedef value_type*         pointer;
			typedef const value_type*   const_pointer;
			// Here iterator is simular to pointer
			typedef value_type*         iterator;
			typedef const value_type*   const_iterator;
			typedef size_t              size_type;
			static const int maxlen = 500000;

		private:
			value_type st[500005];
			int TOP;

		public:
			handstack() : TOP(-1) {
				memset(st, value_type(), sizeof(st));
			}

			bool empty() {
				return TOP == -1;
			}
			bool full() {
				return TOP >= maxlen;
			}

			size_type size() {
				return TOP + 1;
			}

			void push(value_type val) {
				assert(full());
				st[++TOP] = val;
			}
			void pop() {
				assert(empty());
				--TOP;
			}
			void clear() {
				TOP = -1;
			}

			reference top() {
				assert(empty());
				return st[TOP];
			}
			const_reference top() const {
				assert(empty());
				return st[TOP];
			}

			reference operator[] (int pos) {
				return st[pos];
			}
			reference at(int pos) {
				return st[pos];
			}

			void print() {
				for(int i = 0; i < size(); i++)
					std::cout << st[i] << ' ';
				std::cout << std::endl;
			}
	};

	// straight output to type handstack
	template <class T> std::ostream& operator<< (std::ostream& os, handstack<T> hs) {
		for(int i = 1; i <= hs.size(); i++)
			os << hs[i] << std::endl;
		return os;
	}

	template <class T> class handdeque {
		public:
			typedef T                   value_type;
			typedef value_type&         reference;
			typedef const value_type&   const_reference;
			typedef value_type*         pointer;
			typedef const value_type*   const_pointer;
			// Here iterator is simular to pointer
			typedef value_type*         iterator;
			typedef const value_type*   const_iterator;
			typedef size_t              size_type;
			static const int maxlen = 500000;

		private:
			value_type d[500005];
			int f, r;

		public:
			handdeque() : f(0), r(0) {
				memset(d, 0, sizeof(d));
			}

			bool empty() {
				return f == r;
			}
			bool full() {
				return r - f == maxlen;
			}

			size_type size() {
				return r - f;
			}
			size_type max_size() {
				return maxlen;
			}

			void push_back(value_type val) {
				assert(full());
				d[r++ % maxlen] = val;
			}
			void pop_back() {
				assert(empty());
				--r;
				if(r < 0) f += maxlen, r += maxlen;
			}
			void push_front(value_type val) {
				assert(full());
				d[(--f + maxlen) % maxlen] = val;
				if(f < 0) f += maxlen, r += maxlen;
			}
			void pop_front() {
				assert(empty());
				++f;
			}
			void clear() {
				f = r = 0;
			}

			reference front() {
				assert(empty());
				return d[f % maxlen];
			}
			const_reference front() const {
				assert(empty());
				return d[f % maxlen];
			}
			reference back() {
				assert(empty());
				return d[(r - 1) % maxlen];
			}
			const_reference back() const {
				assert(empty());
				return d[(r - 1) % maxlen];
			}

			iterator begin() {
				return &d[f % maxlen];
			}
			iterator end() {
				return &d[(r - 1) % maxlen] + 1;
			}

			reference operator[] (int pos) {
				assert(pos >= size());
				return d[(f + pos) % maxlen];
			}
			reference at(int pos) {
				assert(pos >= size());
				return d[(f + pos) % maxlen];
			}
	};

	// straight output to type handqueue
	template <class T> std::ostream& operator<< (std::ostream& os, handdeque<T> hdq) {
		for(int i = 1; i <= hdq.size(); i++)
			os << hdq[i] << std::endl;
		return os;
	}

	/*
	template <class Key, class T, class Compare = std::less<T>, class Container = AVL<std::pair<Key, T> > > class Map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef Compare compare_type;
			typedef Container container_type;
			typedef std::pair<key_type, mapped_type> value_type;
			typedef typename container_type::node* pointer_type;

		private:
			container_type con;

		public:
			pointer_type begin() {
				return con.rt;
			}
	};
	*/

#if __cplusplus < 201103L

	template <class T, int len> struct array {
		typedef T                   value_type;
		typedef value_type&         reference;
		typedef const value_type&   const_reference;
		typedef value_type*         pointer;
		typedef const value_type*   const_pointer;
		typedef value_type*         iterator;
		typedef const value_type*   const_iterator;
		typedef size_t              size_type;
		typedef ptrdiff_t           difference_type;
	}; // C++11 template struct ---array---

	template <class ForwardIterator, class T> void iota (ForwardIterator first, ForwardIterator last, T val) {
		while(first != last) {
			*first = val;
			++first;
			++val;
		}
	} // C++11 template function ---iota---

#endif

	// namespace stdplus
}

// end file

////////////////////////////////////////////////
// File: Functions.h ///////////////////////////
////////////////////////////////////////////////

namespace stdplus {

	void FileCloseC(FILE*& in, FILE*& out) {
		fclose(in);
		fclose(out);
	}
	void FileCloseCPP(std::ifstream& in, std::ofstream& out) {
		in.close();
		out.close();
	}

// namespace stdplus
}

// end file

////////////////////////////////////////////////
// File: my_defines.h //////////////////////////
////////////////////////////////////////////////

// This file is for all the defines.
// Go with it! It will be very helpful with you.

namespace stdplus {

#define mainend return 0
#define endm(exitnum) exit((exitnum))
#define funcend(exitnum) {if(exitnum == void) return; else return (exitnum);}
#define pt(x) std::cout << (x)
#define ptn(x) std::cout << (x) << std::endl
#define createmod(type, name, modnum) type name = (modnum)
#define setmod(name, modnum) name = (modnum)
#define usemod(num, name) (num) % (name)
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
#define rtn return

	// namespace stdplus
}

// end file

////////////////////////////////////////////////
// File: graph.h //////////////////////////////
////////////////////////////////////////////////

namespace stdplus {

	class basic_graph {
		protected:
			std::string graph_name;
		public:
			basic_graph() {};
	};

	template <class T = int> class Rectangle : protected basic_graph {
		public:
			typedef T value_type;

		protected:
			value_type Long, Width;

		public:
			Rectangle() : Long(value_type()), Width(value_type()) {
				graph_name = "rectangle";
			}
			Rectangle(value_type _long, value_type _width) : Long(_long), Width(_width) {
				graph_name = "rectangle";
			}

			value_type get_long() {
				return Long;
			}
			value_type get_width() {
				return Width;
			}
			value_type get_area() {
				return Long * Width;
			}
			value_type get_perimeter() {
				return 2 * (Long + Width);
			}
			value_type get_peri() {
				return get_perimeter();
			}
			std::string get_graph_name() {
				return graph_name;
			}
			char* get_graph_name_c() {
				return graph_name.c_str();
			}
			void set_long(value_type _long) {
				Long = _long;
			}
			void set_width(value_type _width) {
				Width = _width;
			}
	};

	typedef Rectangle<> rectangle_int;
	typedef rectangle_int rec_int;
	typedef Rectangle<long long> rectangle_ll;
	typedef rectangle_ll rec_ll;
	typedef Rectangle<double> rectangle_double;
	typedef rectangle_double rec_double;
	typedef Rectangle<bign> rectangle_bign;
	typedef rectangle_bign rec_bign;

	template <class T = int> class Square : protected basic_graph {
		public:
			typedef T value_type;

		protected:
			value_type edge_length;

		public:
			Square() : edge_length(value_type()) {
				graph_name = "square";
			}
			Square(value_type edge) : edge_length(edge) {
				graph_name = "square";
			}

			value_type get_area() {
				return edge_length * edge_length;
			}
			value_type get_perimeter() {
				return edge_length * value_type(4);
			}
			value_type get_peri() {
				return get_perimeter;
			}
			value_type get_edge() {
				return edge_length;
			}
			std::string get_graph_name() {
				return graph_name;
			}
			char* get_graph_name_c() {
				return graph_name.c_str();
			}
			void set_edge(value_type edge) {
				edge_length = edge;
			}
	};

	typedef Square<> square_int;
	typedef Square<long long> square_ll;
	typedef Square<double> square_double;
	typedef Square<bign> square_bign;

	template <class T = double> class Circle : protected basic_graph {
		public:
			typedef T value_type;

		protected:
			value_type radius;
			int point_len;
		public:
			value_type pi;

		public:
			Circle() : radius(value_type()), point_len(10), pi(acos(-1.0)) {
				graph_name = "circle";
			}
			Circle(value_type rad, int set_point = 10) : radius(rad), point_len(set_point), pi(acos(-1.0)) {
				point_len = set_point;
				graph_name = "circle";
			}

			value_type point_make(value_type x) {
				return value_type(value_type(floor(x * pow(10.0, point_len))) / pow(10.0, point_len));
			}

			value_type get_area() {
				return point_make(radius * radius * pi);
			}
			value_type get_perimeter() {
				return point_make(2.0 * radius * pi);
			}
			value_type get_peri() {
				return get_perimeter();
			}
			value_type get_radius() {
				return radius;
			}
			value_type get_rad() {
				return radius;
			}
			value_type get_diameter() {
				return 2.0 * radius;
			}
			value_type get_dia() {
				return 2.0 * radius;
			}
			int get_point() {
				return point_len;
			}
			int get_point_len() {
				return point_len;
			}
			void set_point(int set_point) {
				assert(set_point >= 0);
				point_len = set_point;
			}
			void set_point_len(int set_point) {
				assert(set_point >= 0);
				point_len = set_point;
			}
			void set_radius(int rad) {
				radius = rad;
			}
			void set_rad(int rad) {
				radius = rad;
			}
	};

	// namespace stdplus
}

// end file

// end WHOLE file
