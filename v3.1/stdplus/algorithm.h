////////////////////////////////////////////////
// File: algorithm.h ///////////////////////////
////////////////////////////////////////////////

// This file is for sorts
// use templates
// File Name: Sorts.h

#include "declaring.h"

// begin file

namespace stdplus {

	// sorting algorithm

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


	// transformation algorithm

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


	// copying algorithm

	// This function is for copying arrays
	// use template
	template <class T> int arrcpy(T a[], T b[], int st, int pos) {
		for(int i = st; i <= st + pos - 1; i++)
			b[i - st + 1] = a[i];
		return pos;
	} // O(pos)


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

// end file
