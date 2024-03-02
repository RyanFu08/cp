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

//string matching
//verified: https://cses.fi/problemset/hack/1753/entry/8616096/
//todo: fast mod inverse for cross-string matching

struct stringmatch {
	int n;
	int p = 29;
	int MOD = 1420696969;
	vector<int> pref, ppow;
	stringmatch() {}
	stringmatch(vector<int> arr) {
		n = arr.size();
		ppow.push_back(1);
		for (int i = 0; i < n+5; i++) {
			ppow.push_back((p * ppow[i])%MOD);
		}
		pref.push_back(0);
		for (int i = 0; i < n; i++) {
			pref.push_back((pref[i] + (arr[i]+1)*ppow[i])%MOD);
		}
	}
	bool equiv(int l1, int r1, int l2, int r2) {
		if (r1 - l1 != r2 - l2) return 0;
		if (l1 > l2) {
			swap(l1, l2);
			swap(r1, r2);
		}
		int sub1 = (pref[r1+1] - pref[l1] + MOD)%MOD;
		int sub2 = (pref[r2+1] - pref[l2] + MOD)%MOD;
		sub1 *= ppow[l2-l1]; sub1 %= MOD;
		return (sub1 == sub2);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2; cin >> s1 >> s2;
	int n = s1.size(); int m = s2.size();
	vector<int> sc;
	for (int i = 0; i < m; i++) {
		sc.push_back(s2[i]-'a');
	}
	for (int i = 0; i < n; i++) {
		sc.push_back(s1[i]-'a');
	}
	int cnt = 0;
	stringmatch sm(sc);
	for (int i = m; i <= n; i++) {
		if (sm.equiv(0,m-1,i,i+m-1)) {
			cnt++;
		}
	}
	cout << cnt;
}
