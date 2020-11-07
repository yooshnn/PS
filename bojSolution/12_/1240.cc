#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> con[1001];
int solve(int u, int v) {
	bool visit[1001];
	fill(begin(visit), end(visit), false);

	priority_queue<pii, vector<pii>, greater<pii>> pque;
	pque.push({ 0, u });

	while (!pque.empty()) {
		pii cur = pque.top(); pque.pop();

		for (pii i : con[cur.second]) {
			int w, d; tie(w, d) = i;
			if (visit[d]) continue;
			visit[d] = true;

			w += cur.first;
			if (d == v) return w;
			pque.push({ w, d });
		}
	}

	assert(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q; cin >> N >> Q;
	for (int i = 0; i < N - 1; ++i) {
		int u, v, w; cin >> u >> v >> w;
		con[u].push_back({ w, v });
		con[v].push_back({ w, u });
	}
	while (Q--) {
		int u, v; cin >> u >> v;
		cout << solve(u, v) << "\n";
	}

	return 0;
}