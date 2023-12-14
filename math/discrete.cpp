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

const int MOD = 1e9+7;
int binpow(int a, int b, int m = MOD) {
	a %= m; int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m; b >>= 1;
    }
    return res;
}
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
vector<int> lp;
vector<int> pr;
void sieve(int MXN = 2e7) {
	for (int i=2; i <= MXN; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (int j = 0; i * pr[j] <= MXN; ++j) {
	        lp[i * pr[j]] = pr[j];
	        if (pr[j] == lp[i]) break;
	    }
	}
}
vector<int> pfactor(int n) {
	if (!pr.size()) sieve();
	vector<int> res;
	for (auto p : pr) {
		if (p * p > n) break;
		while (n % p == 0) {
			n /= p; res.push_back(p);
		}
	}
	if (n > 1) res.push_back(n);
	return res;
}

int inv(int a, int m = MOD) {
	return binpow(a, a-2, m);
}
vector<int> ft;
void genft(int MX, int m = MOD) {
	ft.push_back(1);
	for (int i = 1; i <= MX; i++) {
		ft.push_back((ft[i-1] * i) % m);
	}
}
int binom(int n, int k, int m = MOD) {
	return ((ft[n] * inv(ft[n-k]))%m * inv(ft[k])) % m;
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	return 0;
}
