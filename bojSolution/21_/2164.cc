#include <bits/stdc++.h>
using namespace std;

struct ArrayQueue {
	int* que;
	int maxSize;
	int f, r, n;

	ArrayQueue(int ms) {
		maxSize = ms;
		f = r = n = 0;
		que = new int[maxSize];
		for (int i = 0; i < maxSize; ++i) que[i] = 0;
	}

	int size() {
		return n;
	}
	bool empty() {
		return (n == 0);
	}
	int front() {
		if (empty()) return -1;
		return que[f];
	}
	int rear() {
		if (empty()) return -1;
		return que[(f + n - 1) % maxSize];
	}
	void enqueue(int e) {
		if (n == maxSize) {
			cout << "Full\n"; return;
		}
		que[r] = e;
		r = (r + 1) % maxSize;
		n++;
	}
	int dequeue() {
		if (n == 0) return -1;
		int ret = que[f];
		f = (f + 1) % maxSize;
		n--;
		return ret;
	}
};

int main() {
	int n; cin >> n;
	ArrayQueue Q(n);
	for (int i = 1; i <= n; ++i) {
		Q.enqueue(i);
	}

	while (1) {
		if (Q.size() > 1) Q.dequeue();
		if (Q.size() > 1) Q.enqueue(Q.dequeue());
		if (Q.size() == 1) break;
	}

	cout << Q.dequeue();
}