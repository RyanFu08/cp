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

/*
0 indexed Range Sum Query
- set(ind, val) sets the value at ind to val
- rsq(l, r) returns the sum at [l,r]
Verified: https://judge.yosupo.jp/submission/173180
*/

struct RSQ {
	int len;
	vector<int> seg;
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

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
}
