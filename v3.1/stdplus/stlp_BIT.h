////////////////////////////////////////////////
// File: stlp_bst.h ////////////////////////////
////////////////////////////////////////////////
#include "declaring.h"

// begin file

namespace stdplus{
        // 1-indexed BIT
        struct BIT{
                vector<int> c;
                BIT(){
                        c = std::vector<int>();
                }
                BIT(int n){
                        c = std::vector<int>(n + 1, 0);
                }
                inline int lowbit(int n){
                        return n & (-n);
                }
                void add(int n, int k){
                        while(n < c.size()){
                                c[n] += k;
                                n += lowbit(n);
                        }
                }
                int query(int n, int k){
                        int ans = 0;
                        while(n >= 1){
                                ans += c[n];
                                n -= lowbit(n);
                        }
                        return ans;
                }
                int& operator[] (int pos){
                        return query(pos, pos);
                }
        };
}
