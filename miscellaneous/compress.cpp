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
coordinate compression
faster than set/map/bsearch
input array, outputs compressed version
change the intial value (potentially to 1) as nxt
*/

vector<int> compress(vector<int> arr) {
	vector<pair<int, int> > a2;
	vector<int> res(sz(arr));
	for (int i = 0; i < arr.size(); i++) {
		a2.push_back(make_pair(arr[i], i));
	}
	sort(all(a2));
	int nxt = 0; // first value
	for (int i = 0; i < a2.size(); i++) {
		if (i > 0 && a2[i-1].first != a2[i].first) nxt++;
		res[a2[i].second] = nxt;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	return 0;
}
