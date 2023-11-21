#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

struct RSQ {
	int len;
	vector<int> seg;
	RSQ() {}
	RSQ(int l) {
		len = 1ll<<(int) (log2(l)+1);
		seg = vector<int>(2*len,0);
	}
	void set(int ind, int val) {
		assert(0 <= ind && ind < len);
		ind += len;
		seg[ind] = val;
		while (ind /= 2) {
			seg[ind] = seg[2*ind] + seg[2*ind+1];
		}
	}
	int rsq(int l, int r) {
		int res = 0; r++;
		for (l += len, r += len; l < r; l /= 2, r /= 2) {
			if (l&1) res += seg[l++];
		    if (r&1) res += seg[--r];
		}
		return res;
	}
};

/*
0 indexed Range Distinct Query
- initializes from vector of values in O(n)
- rdq(qs) answers range distinct queries [l,r] offline in O(n log n)
Verified: https://www.spoj.com/status/DQUERY,maxwell_yang/ns=32204094
Requires RSQ
*/

struct RDQ {
	vector<int> arr;
	RSQ su;
	int mxv = 0;
	RDQ(vector<int> x) {
		arr = x;
		for (auto i : arr) mxv = max(mxv, i);
		assert(mxv < 1e7);
	}
	vector<int> rdq(vector<pair<int, int> >& qs) {
		vector<pair<pair<int, int>, int> > qq;
		for (int i = 0; i < qs.size(); i++) {
			qq.push_back(make_pair(make_pair(qs[i].second, qs[i].first), i));
		}
		sort(qq.begin(), qq.end());
		vector<int> ans(qq.size());
		vector<int> prev(mxv+1,-1);
		su = RSQ(mxv+1); int cpos = 0;
		for (int i = 0; i < arr.size(); i++) {
			su.set(i, 1);
			if (prev[arr[i]] != -1) {
				su.set(prev[arr[i]], 0);
			}
			prev[arr[i]] = i;
			while (cpos < qq.size() && qq[cpos].first.first == i) {
				ans[qq[cpos].second] = su.rsq(qq[cpos].first.second, qq[cpos].first.first);
				cpos++;
			}
		}
		return ans;
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
}
