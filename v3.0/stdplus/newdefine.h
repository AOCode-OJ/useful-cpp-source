////////////////////////////////////////////////
// File: newdefine.h ///////////////////////////
////////////////////////////////////////////////

#include "declaring.h"

// This file is for all the defines.
// Go with it! It will be very helpful with you.

namespace stdplus {

	bool __usedefine = false;
	void use_define(bool flag = false) {
		__usedefine = flag;
	}
	
#ifdef __usedefine

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

#endif

	// namespace stdplus
}

// end file