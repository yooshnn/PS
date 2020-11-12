#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

struct segt {
	int depth, f;
	int* tree;

	segt(int n) {
		tree = new int[n * 4];
		//fill(tree, tree + n * 4, 0);
		for (depth = 1; n > (ll)pow(2, depth - 1); ++depth);
		f = (int)pow(2, depth - 1) - 1;
	}
	~segt() {
		delete tree;
	}

	void build() {
		for (int i = depth - 1; i >= 1; --i) {
			for (int j = 0; j < (int)pow(2, i - 1); ++j) {
				int cur = (int)pow(2, i - 1) + j;
				tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
			}
		}
	}
	void update(int id, int val) {
		tree[f + id] = val;
		id = (id + 1) / 2;
		for (int i = depth - 1; i >= 1; --i) {
			int cur = (int)pow(2, i - 1) - 1 + id;
			tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
			id = (id + 1) / 2;
		}
	}
	int ask(int p, int q) {
		int ret = 0; p += f, q += f;
		while (p <= q) {
			if (p % 2 == 1) ret = max(ret, tree[p]);
			if (q % 2 == 0) ret = max(ret, tree[q]);
			p = (p + 1) / 2, q = (q - 1) / 2;
		}
		return ret;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	N = input(), M = input();

	segt T(N);

	int c;
	for (int i = 1; i <= N; ++i) T.tree[i + T.f] = input();
	T.build();

	for (int i = M - 1; i < N - M + 1; ++i) {
		int m = i;
		int req = T.ask(m - (M - 1) + 1, m + (M - 1) + 1);
		cout << req << " ";
	}
}