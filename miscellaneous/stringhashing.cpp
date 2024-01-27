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
hashing for arrays
remember to FIRST RUN genP for prime stuff
then, genhp generates the prefix hash stuff for an array
after storing this, you can pass it back to gethash(l,r) to get the hash for a specific range in the array
semi verified: https://cses.fi/problemset/hack/1753/entry/8306967/
*/

const int p = 31;
const int MOD = 1420696969;
const int MXN = 1e6;

int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

vector<int> invs(const vector<int> &a, int m) {
    int n = a.size();
    vector<int> res;
    if (n == 0) return res;
    vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    int x, y;
    extended_euclidean(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}

vector<int> pw;
vector<int> iv;

void genP() {
	pw.push_back(1);
	for (int i = 0; i <= MXN; i++) {
		pw.push_back((pw[i]*p)%MOD);
	}
	iv = invs(pw, MOD);
}

vector<int> genhp(vector<int>& arr) {
	//gen hash prefix
	vector<int> res(1,0);
	for (int i = 0; i < arr.size(); i++) {
		res.push_back(((arr[i]%MOD)*pw[i] + res[i])%MOD);
	}
	return res;
}

int gethash(int l, int r, vector<int>& hp) {
	return ((hp[r+1] - hp[l] + MOD)%MOD * iv[l])%MOD;
}


//solution to cses string matching
signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	genP();
	string s1; string s2; cin >> s1 >> s2;
	vector<int> a1(s1.size());
	for (int i = 0; i < s1.size(); i++) {
		a1[i] = s1[i] - 'a' + 1;
	}
	vector<int> a2(s2.size());
	for (int i = 0; i < s2.size(); i++) {
		a2[i] = s2[i] - 'a' + 1;
	}
	vector<int> h1 = genhp(a1);
	vector<int> h2 = genhp(a2);
	int cnt = 0;
	for (int i = a2.size()-1; i < a1.size(); i++) {
		if (gethash(i-a2.size()+1, i, h1) == gethash(0,a2.size()-1,h2)) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
