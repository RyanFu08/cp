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
2 pqs
surely this works right?
*/

template<class T>
struct pq2 {
	priority_queue<T> ord;
	priority_queue<T> del;
	pq2() {}
	pq2(priority_queue<T> o1, priority_queue<T> d1) {
		ord = o1; del = d1;
	}
	void insert(T k) {ord.push(k);}
	void remove(T k) {del.push(k);}
	void prop() {
		while (!ord.empty && !del.empty() && ord.top() == del.top()) {
			ord.pop(); del.pop();
		}
	}
	int top() {
		prop();
		return ord.top();
	}
	int pop() {
		prop();
		T a = ord.top();
		ord.pop();
		return a;
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	return 0;
}
