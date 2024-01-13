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
verified
*/

struct RMQ {
	int len = 1;
	vector<int> segmx;
	RMQ() {}
	RMQ(int l) {
		while (len < l) len *= 2;
		segmx = vector<int>(2*len,-INF);
	}
	RMQ(vector<int> arr) {
		while (len < sz(arr)) len *= 2;
		segmx = vector<int>(2*len,-INF);
		for (int i = 0; i < sz(arr); i++) {segmx[len+i] = arr[i];}
		for (int i = len-1; i > 0; i--) {
			segmx[i] = max(segmx[2*i], segmx[2*i+1]);
		}
	}
	void set(int ind, int val) {
		assert(0 <= ind && ind < len);
		ind += len; segmx[ind] = val;
		while (ind /= 2) {segmx[ind] = max(segmx[2*ind], segmx[2*ind+1]);}
	}
	int rangemax(int l, int r) {
		int res = -INF; r++;
		for (l += len, r += len; l < r; l /= 2, r /= 2) {
			if (l&1) res = max(res, segmx[l++]);
		    if (r&1) res = max(res, segmx[--r]);
		}
		return res;
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
}
