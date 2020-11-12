#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + (ch & 15); } return num; }

struct segt {
	int depth, f;
	pii* tree;

	segt(int n) {
		tree = new pii[n * 4];
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
				tree[cur] = { tree[cur * 2].first + tree[cur * 2 + 1].first, min(tree[cur * 2].second, tree[cur * 2 + 1].second) };
			}
		}
	}
	pii ask(int p, int q) {
		pii ret = { 0, 2147483647 }; p += f, q += f;
		while (p <= q) {
			if (p % 2 == 1) ret = { ret.first + tree[p].first, min(ret.second, tree[p].second) };
			if (q % 2 == 0) ret = { ret.first + tree[q].first, min(ret.second, tree[q].second) };
			p = (p + 1) / 2, q = (q - 1) / 2;
		}
		return ret;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string src; cin >> src;
	segt T(src.size());
	int idx = 1, psum = 0;
	for (char& c : src) {
		if (c == '(') {
			psum += 1;
			T.tree[idx + T.f] = { 1, psum };
		}
		else {
			psum -= 1;
			T.tree[idx + T.f] = { -1, psum };
		}
		idx++;
	} T.build();
	int res = 0;
	int Q; cin >> Q; while (Q--) {
		int p, q; cin >> p >> q;
		pii req = T.ask(p, q); 
		if (req.first == 0 && req.second - T.ask(p - 1, p - 1).second >= 0) res++;
	}
	cout << res;
}