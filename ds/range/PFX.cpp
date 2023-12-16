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
0 indexed 1D Prefix Sum
- initializes from a 1D vector of values
- rsq(l, r) returns the sum in O(1)
Verified: https://cses.fi/problemset/hack/1646/entry/7923280/
*/

struct PFX {
	vector<int> pre;
	PFX(vector<int>& arr) {
		pre = vector<int>(arr.size()+1, 0);
		for (int i = 1; i <= arr.size(); i++) {
			pre[i] = pre[i-1] + arr[i-1];
		}
	}
	int RSQ(int l, int r) {
		assert(0 <= l && l <= r && r < pre.size()-1);
		return pre[r+1]-pre[l];
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	return 0;
}
