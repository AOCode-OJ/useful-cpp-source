////////////////////////////////////////////////
// File: stlp_ufs.h ////////////////////////////
////////////////////////////////////////////////

#include "declaring.h"

namespace stdplus {

	// Union-Find-Set declare here
	struct UFS {
		std::vector<int> fa;

		UFS() : fa(std::vector<int>()) {}
		UFS(int n) : fa(std::vector<int>(n, -1)) {}
		int findfa(int x) {
			if(fa[x] < 0)
				return x;
			return fa[x] = findfa(fa[x]);
		}
		void unite(int a, int b) {
			int faA = findfa(a);
			int faB = findfa(b);
			if(faA != faB) {
				fa[faA] += fa[faB];
				fa[faB] = faA;
			}
		}
		int& operator[] (const int& pos) {
			return fa[pos];
		}
	};

	// namespace stdplus
}