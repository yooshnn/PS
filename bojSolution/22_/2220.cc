#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Heap {
	int last;
	vector<int> heap;

	Heap() {
		heap.push_back(0);
		last = 0;
	}

	void s(int p, int q) {
		heap[p] ^= heap[q]; heap[q] ^= heap[p]; heap[p] ^= heap[q];
	}
	void put(int e) {
		heap.push_back(e);
		if (last != 0) s(last, last + 1);
		upheap(last);
		last++;
	}
	void upheap(int id) {
		int par = id / 2;
		if (par != 0) {
			s(id, par);
			upheap(par);
		}
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	Heap H;
	int n; cin >> n;

	for (int i = 1; i <= n; ++i) H.put(i);

	for (int i = 1; i <= n; ++i) cout << H.heap[i] << " ";
}