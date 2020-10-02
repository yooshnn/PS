#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tup;
const int MAX = 200000 + 1;

int N, E;

int component[MAX];
priority_queue<tup, vector<tup>, greater<tup>> edges;
int search(int);
void merge(int, int);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		cin >> N >> E; if (N == 0) break;

		ll total = 0;
		for (int i = 0; i < E; ++i) {
			int u, v, w; cin >> u >> v >> w;
			edges.push({ w, u, v });
			total += w;
		}

		for (int i = 0; i < N; ++i) component[i] = i;

		ll edge = 0, res = 0;
		while (!edges.empty() && edge < N - 1) {
			tup cur = edges.top(); edges.pop();
			int u = get<1>(cur), v = get<2>(cur), w = get<0>(cur);
			if (search(u) == search(v)) continue;
			edge++;
			merge(u, v); res += w;
		}

		cout << total - res << "\n";
		while (!edges.empty()) edges.pop();
	}

	return 0;
}

int search(int q) {
	if (component[q] == q) return q;
	return component[q] = search(component[q]);
}
void merge(int p, int q) {
	int a = search(p), b = search(q);
	if (a == b) return;
	component[b] = a;
}