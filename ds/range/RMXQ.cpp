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
0 indexed Range Max Query
- set(ind, val) sets the value at ind to val in O(log n)
- rmxq(l, r) returns the min in [l,r] in O(log n)
not verified
*/

struct RMXQ {
	int len;
	vector<int> segmx;
	vector<int> segmn;
	RMXQ() {}
	RMXQ(int l) {
		len = 1ll<<(int) (log2(l)+1);
		segmx = vector<int>(2*len,-INF);
		segmn = vector<int>(2*len,INF);
	}
	void set(int ind, int val) {
		assert(0 <= ind && ind < len);
		ind += len;
		segmx[ind] = val;
		segmn[ind] = val;
		while (ind /= 2) {
			segmx[ind] = max(segmx[2*ind], segmx[2*ind+1]);
			segmn[ind] = min(segmn[2*ind], segmn[2*ind+1]);
		}
	}
	int rmxq(int l, int r) {
		int res = -INF; r++;
		for (l += len, r += len; l < r; l /= 2, r /= 2) {
			if (l&1) res = max(res, segmx[l++]);
		    if (r&1) res = max(res, segmx[--r]);
		}
		return res;
	}
	int rmnq(int l, int r) {
		int res = INF; r++;
		for (l += len, r += len; l < r; l /= 2, r /= 2) {
			if (l&1) res = min(res, segmn[l++]);
		    if (r&1) res = min(res, segmn[--r]);
		}
		return res;
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
}
