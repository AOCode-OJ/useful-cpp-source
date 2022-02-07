////////////////////////////////////////////////
// File: stlp_ufs.h ////////////////////////////
////////////////////////////////////////////////

#include "declaring.h"

namespace stdplus {

	// Union-Find-Set declare here
	// UPD: added weight
	struct UFS {
		std::vector<int> father, size_;

		UFS() {
			father = std::vector<int>();
			size_ = std::vector<int>();
		}
		UFS(int n) {
			father = std::vector<int>(n, -1);
			size_ = std::vector<int>(n, 1);
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
				father[faA] = -1;
				father[faB] = faA;
				size_[faA] += size_[faB];
				size_[faB] = 0;
			}
		}
		int findNum(){
			set<int> s;
			for(int i = 0;i < father.size();i++){
				s.insert(FindFather(i));
			}
			return s.size();
		}
		int& operator[] (const int& pos) {
			return father[pos];
		}
		int& operator() (const int& pos){
			return size_[pos];
		}
	};
	
	// namespace stdplus
}
