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
0 indexed sparse rangemin
- initializes from vector of values in O(nlogn)
- rmq(l, r) returns the min of [l,r] in O(1)
Verified: https://judge.yosupo.jp/submission/176106
*/

struct sparsemin {
	vector<vector<int> > st;
	int h;
	sparsemin() {}
	sparsemin(vector<int> arr) {
		h = log2(arr.size()) + 1;
		st = vector<vector<int> >(h+1);
		st[0] = arr;
		for (int i = 1; i <= h; i++) {
			for (int j = 0; j + (1<<i) <= arr.size(); j++) {
				st[i].push_back(min(st[i-1][j], st[i-1][j + (1<<(i-1))]));
			}
		}
	}
	int rmq(int l, int r) {
		int i = log2(r - l + 1);
		return min(st[i][l], st[i][r - (1<<i) + 1]);
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
}
