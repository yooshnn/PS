#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, Q;
vector<int> rnk;
vector<set<int>> key;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	rnk.resize(N); for (int& x : rnk) cin >> x;
	key.resize(N); for (auto& x : key) {
		int cnt, k; cin >> cnt; while (cnt--) {
			cin >> k; x.insert(k);
		}
	}
	priority_queue<pii, vector<pii>, greater<pii>> que;
	cin >> Q; while (Q--) {
		int t; cin >> t;
		for (int i = 0; i < N; ++i) {
			if (key[i].find(t) != key[i].end()) que.push({rnk[i], i+1});
		}
		if (que.empty()) { cout << -1 << "\n"; }
		else {
			while (!que.empty()) {
				cout << que.top().second << " ";
				que.pop();
			}
			cout << "\n";
		}
	}

	//cout << endl; system("pause");
}