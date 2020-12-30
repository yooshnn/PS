#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int TEST; cin >> TEST; while (TEST--) {
		queue<pii> que;
		priority_queue<int> pque;

		int N, Q, r = 0; cin >> N >> Q;
		for (int i = 0, t; i < N; ++i) {
			cin >> t;
			que.push({i, t});
			pque.push(t);
		}
		while (!que.empty()) {
			pii cur = que.front(); que.pop();
			if (cur.second < pque.top()) que.push(cur);
			else {
				r += 1;
				pque.pop();
				if (cur.first == Q) break;
			}
		}

		cout << r << '\n';
	}

}