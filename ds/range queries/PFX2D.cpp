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
0 indexed 2D Prefix Sum
- initializes from a 2D vector of values
- rsq(x1, y1, x2, y2) returns the sum in O(1)
TODO: Verify
*/


struct PFX2D {
	vector<vector<int> > arr;
	vector<vector<int> > pre;
	PFX2D(vector<vector<int> >& a) {
		arr = a;
		pre = vector<vector<int> >(arr.size() + 1, vector<int>(arr[0].size() + 1, 0));
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr[0].size(); j++) {
				pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + arr[i][j];
			}
		}
	}
	int RSQ(int x1, int y1, int x2, int y2) {
		return pre[x2+1][y2+1] - pre[x2+1][y1] - pre[x1][y2+1] + pre[x1][y1];
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	return 0;
}
