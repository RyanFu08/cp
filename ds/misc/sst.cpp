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
simple set wrapper class
*/

struct sst {
	multiset<int> ds; //replace with set
	void insert(int k) {ds.insert(k);}
	bool erase(int k) {
		if (ds.find(k) != ds.end()) {
			ds.erase(k);
			return 1;
		}
		return 0;
	}
	bool contains(int k) {
		return (ds.find(k) != ds.end());
	}
	int nxt(int k) {
		if (ds.lower_bound(k) == ds.end()) {
			return -1;
		}
		return *(ds.lower_bound(k));
	}
	int prv(int k) {
		if (ds.upper_bound(k) == ds.begin()) {
			return -1;
		}
		return *(--ds.upper_bound(k));
	}
	int size() {return ds.size();}
	void debug() {
		cout << "{ ";
		for (auto i : ds) {
			cout << i << " , ";
		}
		cout << "} \n";
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	return 0;
}
