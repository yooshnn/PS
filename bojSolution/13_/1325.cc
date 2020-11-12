#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + (ch & 15); } return num; }

int rMax = 0;
vector<int> res;
vector<int> edge[10001];
bool dup[10001];

void bfs(int k) {
	int cnt = 0;
	queue<int> que;
	dup[k] = true;
	for (que.push(k); !que.empty(); que.pop()) {
		int cur = que.front();
		for (int& i : edge[cur]) {
			if (!dup[i]) {
				dup[i] = true;
				cnt++;
				que.push(i);
			}
		}
	}

	if (cnt > rMax) {
		res.clear(); res.push_back(k);
		rMax = cnt;
	}
	else if (cnt == rMax) {
		res.push_back(k);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	while (m--) {
		int p, q; cin >> p >> q;
		edge[q].push_back(p);
	}
	for (int i = 1; i <= n; ++i) {
		fill(dup, dup + n + 1, false);
		bfs(i);
	}
	for (int& i : res) cout << i << " ";
}