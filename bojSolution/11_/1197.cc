#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;
const int MAX = 10000 + 1;

int N, E;

int component[MAX];
priority_queue<tup, vector<tup>, greater<tup>> edges;
int search(int);
void merge(int, int);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> E;
	for (int i = 0; i < E; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges.push({ w, u, v });
	}

	for (int i = 1; i <= N; ++i) component[i] = i;

	int edge = 0, res = 0;
	while (!edges.empty() && edge <= N - 1) {
		tup cur = edges.top(); edges.pop();
		int u = get<1>(cur), v = get<2>(cur), w = get<0>(cur);
		if (search(u) == search(v)) continue;
		merge(u, v); res += w;
	}

	cout << res;

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