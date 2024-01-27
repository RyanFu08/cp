#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
using namespace std;
#define int long long

/*
LIS in nlogn
uses segtree, compression
easily modifiable to non decreasing via the segtree query range
*/

struct RMQ {
	int DEF;
	int len = 1;
	vector<int> segmx;
	RMQ() {}
	RMQ(int l, int d = -INF) {
		DEF = d;
		while (len < l) len *= 2;
		segmx = vector<int>(2*len,DEF);
	}
	RMQ(vector<int> arr) {
		while (len < sz(arr)) len *= 2;
		segmx = vector<int>(2*len,DEF);
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
		int res = DEF; r++;
		for (l += len, r += len; l < r; l /= 2, r /= 2) {
			if (l&1) res = max(res, segmx[l++]);
		    if (r&1) res = max(res, segmx[--r]);
		}
		return res;
	}
};

vector<int> compress(vector<int> arr) {
	vector<pair<int, int> > a2;
	vector<int> res(sz(arr));
	for (int i = 0; i < arr.size(); i++) {
		a2.push_back(make_pair(arr[i], i));
	}
	sort(all(a2));
	int nxt = 1; // first value
	for (int i = 0; i < a2.size(); i++) {
		if (i > 0 && a2[i-1].first != a2[i].first) nxt++;
		res[a2[i].second] = nxt;
	}
	return res;
}

int LIS(vi& arr) {
	vi a2 = compress(arr);
	RMQ st(sz(a2)+20,0);
	for (auto i : a2) {
		st.set(i, max(st.rangemax(i,i),st.rangemax(0,i-1)+1));
	}
	int res = 0;
	for (auto i : a2) {
		res = max(res, st.rangemax(i,i));
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	return 0;
}
