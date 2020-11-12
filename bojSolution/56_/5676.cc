#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + (ch & 15); } return num; }

struct segt {
	int depth, f;
	int* tree;

	segt(int n) {
		tree = new int[n * 4];
		fill(tree, tree + n * 4, 0);
		for (depth = 1; n > (int)pow(2, depth - 1); ++depth);
		f = (int)pow(2, depth - 1) - 1;
	}
	~segt() {
		delete tree;
	}

	void build() {
		for (int i = depth - 1; i >= 1; --i) {
			for (int j = 0; j < (int)pow(2, i - 1); ++j) {
				int cur = (int)pow(2, i - 1) + j;
				tree[cur] = tree[cur * 2] * tree[cur * 2 + 1];
			}
		}
	}
	void update(int id, int val) {
		tree[f + id] = val;
		id = (id + 1) / 2;
		for (int i = depth - 1; i >= 1; --i) {
			int cur = (int)pow(2, i - 1) - 1 + id;
			tree[cur] = tree[cur * 2] * tree[cur * 2 + 1];
			id = (id + 1) / 2;
		}
	}
	int ask(int p, int q) {
		int ret = 1; p += f, q += f;
		while (p <= q) {
			if (p % 2 == 1) ret = ret * tree[p];
			if (q % 2 == 0) ret = ret * tree[q];
			p = (p + 1) / 2, q = (q - 1) / 2;
		}
		return ret;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q;
	while (cin >> N) {
		string res = "";
		cin >> Q;
		if (!N) break;
		segt T(N);

		for (int i = 1; i <= N; ++i) {
			int temp; cin >> temp;
			if (temp == 0) T.tree[i + T.f] = 0;
			else if (temp > 0) T.tree[i + T.f] = 1;
			else T.tree[i + T.f] = -1;
		}
		T.build();

		char a; int b, c;
		for (int i = 0; i < Q; ++i) {
			cin >> a >> b >> c;
			if (a == 'C') {
				if (c == 0) T.update(b, 0);
				else if (c > 0) T.update(b, 1);
				else T.update(b, -1);
			}
			else {
				int req = T.ask(b, c);
				if (req == 0) res.push_back('0');
				else if (req < 0) res.push_back('-');
				else res.push_back('+');
			}
		}
		cout << res << "\n";
	}
}