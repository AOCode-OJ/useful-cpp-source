////////////////////////////////////////////////
// File: stlp_ufs.h ////////////////////////////
////////////////////////////////////////////////

#include "declaring.h"

namespace stdplus {

	// Union-Find-Set declare here
	struct UFS {
		std::vector<int> father;

		UFS() : father std::vector<int>() {}
		UFS(int n) : father(std::vector<int>(n, -1)) {}
		int findfa(int x) {
			if(fa[x] < 0)
				return x;
			return fa[x] = findfa(fa[x]);
		}
		void unite(int a, int b) {
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

	// namespace stdplus
}