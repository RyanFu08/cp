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
Fenwick Tree
KACTL
*/

struct FT {
	vector<int> s;
	FT() {}
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

struct RFT {
	vector<int> s;
	RFT() {}
	RFT(int n) : s(n) {}
	void add(int idx, int val) {
	    for (++idx; idx < s.size(); idx += idx & -idx)
	        s[idx] += val;
	}
	void range_add(int l, int r, int val) {
	    add(l, val);
	    add(r + 1, -val);
	}
	int point_query(int idx) {
	    int ret = 0;
	    for (++idx; idx > 0; idx -= idx & -idx)
	        ret += s[idx];
	    return ret;
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
}
