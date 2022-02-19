/****************************************
********** File: stlp_segt.h
****************************************/

#include "declaring.h"

#ifndef _STDPLUS_STLP_SEGT_H_
#define _STDPLUS_STLP_SEGT_H_ 1

namespace stdplus {

	namespace segtcl {

#		define lc(n) ((n) * 2)
#		define rc(n) ((n) * 2 + 1)

		struct SegT {
			typedef size_t size_type;

			struct SEGVAL {
				size_type l, r;
				int vmin, vmax, vsum;
			};

			std::vector<int> val;
			std::vector<SEGVAL> sgt;

			inline void build(size_type l, size_type r, size_type ind = 1) {
				sgt[ind].l = l, sgt[ind].r = r;
				if(l == r) {
					sgt[ind].vmin = sgt[ind].vmax = sgt[ind].vsum = val[l];
					return;
				}
				size_type mid = (l + r) >> 1;
				build(l, mid, lc(ind));
				build(mid + 1, r, rc(ind));
				sgt[ind].vmin = std::min(sgt[lc(ind)].vmin, sgt[rc(ind)].vmin);
				sgt[ind].vmax = std::max(sgt[lc(ind)].vmax, sgt[rc(ind)].vmax);
				sgt[ind].vsum = sgt[lc(ind)].vsum + sgt[rc(ind)].vsum;
			}

			inline void update(size_type pos, int x, size_type ind = 1) {
				if(sgt[ind].l == sgt[ind].r) {
					sgt[ind].vmin = sgt[ind].vmax = sgt[ind].vsum = val[pos] = x;
					return;
				}
				size_type mid = (sgt[ind].l + sgt[ind].r) >> 1;
				if(pos <= mid) update(pos, x, lc(ind));
				else update(pos, x, rc(ind));
				sgt[ind].vmin = std::min(sgt[lc(ind)].vmin, sgt[rc(ind)].vmin);
				sgt[ind].vmax = std::max(sgt[lc(ind)].vmax, sgt[rc(ind)].vmax);
				sgt[ind].vsum = sgt[lc(ind)].vsum + sgt[rc(ind)].vsum;
			}

			inline SEGVAL query(size_type vl, size_type vr, size_type ind = 1) {
				SEGVAL ans;
				if(vl == sgt[ind].l && vr == sgt[ind].r) {
					return sgt[ind];
				}
				size_type mid = (sgt[ind].l + sgt[ind].r) >> 1;
				if(vr <= mid) return query(vl, vr, lc(ind));
				if(vl > mid) return query(vl, vr, rc(ind));
				auto a = query(vl, mid, lc(ind));
				auto b = query(mid + 1, vr, rc(ind));
				ans.l = vl, ans.r = vr;
				ans.vmin = std::min(a.vmin, b.vmin);
				ans.vmax = std::max(a.vmax, b.vmax);
				ans.vsum = a.vsum + b.vsum;
				return ans;
			}

			inline SegT() {};
			inline SegT(const size_type& n)
				: val(decltype(val)(n)), sgt(decltype(sgt)(4 * n + 1)) {
				build(0, n - 1);
			};

			inline void resize(const size_type& n) {
				sgt = decltype(sgt)(4 * n + 1);
				build(0, val.size() - 1);
			}

			inline void replace(std::vector<int> v) {
				val = v;
				sgt = decltype(sgt)(val.size() * 4 + 1);
				build(0, val.size() - 1);
			}

		};

#		undef lc
#		undef rc

		// namespace stdplus::segtcl
	}

	// namespace stdplus
}

#endif // _STDPLUS_STLP_SEGT_H_

// end file