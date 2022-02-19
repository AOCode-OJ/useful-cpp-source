/****************************************
********** File: stlp_matrix.h 
****************************************/

#include "declaring.h"

#ifndef _STDPLUS_STLP_MATRIX_H_
#define _STDPLUS_STLP_MATRIX_H_ 1

#if __cplusplus < 201402L // below C++14 (exclusive)

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

	namespace matrixcl {

		struct Matrix {
			int row, col;
			std::vector<std::vector<ll>> mat;

			Matrix() : row(0), col(0) {};
			Matrix(const int& r, const int& c)
				: row(r), col(c),
				  mat(std::vector<std::vector<ll>>(r, std::vector<ll>(c, 0LL))) {};
			Matrix(const int& r, const int& c, const int& val)
				: row(r), col(c),
				  mat(std::vector<std::vector<ll>>(r, std::vector<ll>(c, val))) {};

			auto& operator[] (const int i);
			const auto& operator[] (const int i) const;

			void resize(int r, int c);
		};

		auto& Matrix::operator[] (const int i) {
			return mat[i];
		}
		const auto& Matrix::operator[] (const int i) const {
			return mat[i];
		}

		void Matrix::resize(int r, int c) {
			row = r, col = c;
			mat.resize(r);
			for(auto& x : mat) x.resize(c);
		}

		const Matrix indMatrix(int n) {
			Matrix a(n, n);
			for(int i = 0; i < n; i++)
				a[i][i] = 1;
			return a;
		}

		// Matrix multiplying
		Matrix operator* (const Matrix& a, const Matrix& b) {
			if(a.col != b.row) return Matrix();
			int n = a.row, m = a.col, p = b.col;
			Matrix c(n, p);
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < p; j++) {
					ll sum = 0;
					for(int k = 0; k < m; k++)
						sum += a[i][k] * b[k][j];
					c[i][j] = sum;
				}
			}
			return c;
		}
		Matrix mulmod(const Matrix& a, const Matrix& b, const ll modn) {
			if(a.col != b.row) return Matrix();
			int n = a.row, m = a.col, p = b.col;
			Matrix c(n, p);

			for(int i = 0; i < n; i++) {
				for(int j = 0; j < p; j++) {
					ll sum = 0LL;
					for(int k = 0; k < m; k++) {
						if(a[i][k] < 0LL) std::cerr << "See a[" << i << "][" << k << "] with negative value! Error!" << std::endl;
						sum = (sum % modn + a[i][k] % modn * b[k][j] % modn) % modn;
					}
					c[i][j] = (c[i][j] % modn + sum % modn);
				}
			}
			return c;
		}

		Matrix operator% (Matrix x, const ll modn) {
			for(auto& t : x.mat)
				for(auto& tt : t)
					tt %= modn;
			return x;
		}

		Matrix binary_pow(const Matrix& x, ll e) {
			if(x.row != x.col) return Matrix();
			int n = x.row;
			if(e == 1) return x;
			if(e == 0) return indMatrix(n);
			Matrix a = binary_pow(x, e / 2);
			if(e & 1) return a * a * x;
			return a * a;
		}
		Matrix binary_pow_mod(Matrix x, ll e, const ll& mod) {
			if(x.row != x.col) return Matrix();
			x = x % mod;
			int n = x.row;
			if(e == 1LL) return x;
			if(e == 0LL) return indMatrix(n);
			Matrix a = binary_pow_mod(x, e / 2, mod) % mod;
			if(e & 1LL) return mulmod(mulmod(a, a, mod) % mod, x, mod) % mod;
			return mulmod(a, a, mod) % mod;
		}

		// namespace stdplus::matrixcl
	}

	// namespace stdplus
}

#endif // _STDPLUS_STLP_MATRIX_H_

#undef ll

// end file
