#include <iostream>
#include <stack>
#define pii pair<int,int>
using namespace std;

stack<int> query;

pii con[100001];
bool call[100001];
int root[100001];
long long cost[100001];
int N, M, Q;

long long res = 0;
int search(int);
void merge(int, int);
void merge2(int, int);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M >> Q;
	for (int i = 0; i <= N; ++i) {
		root[i] = i;
		cost[i] = 1;
	}
	for (int i = 1; i <= M; ++i) {
		int u, v;
		cin >> u >> v;
		con[i] = { u, v };
	}
	for (int i = 1; i <= Q; ++i) {
		int q;
		cin >> q;
		call[q] = true;
		query.push(q);
	}
	for (int i = 1; i <= M; ++i) {
		if (call[i]) continue;
		int p = con[i].first, q = con[i].second;
		merge(p, q);
	}
	while (!query.empty()) {
		int cur = query.top(); query.pop();
		int p = con[cur].first, q = con[cur].second;
		merge2(p, q);
	}
	cout << res;

	return 0;
}

int search(int target) {
	if (target == root[target]) return target;
	root[target] = search(root[target]);
	return root[target];
}
void merge(int a, int b) {
	a = search(a); b = search(b);
	if (a == b) return;
	cost[a] += cost[b];
	root[b] = a;
}
void merge2(int a, int b) {
	a = search(a); b = search(b);
	if (a == b) return;
	res += cost[a] * cost[b];
	cost[a] += cost[b];
	root[b] = a;
}