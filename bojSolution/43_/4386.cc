#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;
typedef tuple<double, int, int> tup;
const int MAX = 100 + 1;

int component[MAX];
priority_queue<tup, vector<tup>, greater<tup>> edges;
int search(int);
void merge(int, int);

int N;
vector<pdd> star;

double getDist(pdd a, pdd b) {
	return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		double r, c; cin >> r >> c;
		star.push_back({ r, c });
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			edges.push({ getDist(star[i], star[j]), i, j });
		}
	}

	for (int i = 1; i <= N; ++i) component[i] = i;

	int edge = 0;
	double res = 0;
	while (!edges.empty() && edge < N - 1) {
		tup cur = edges.top(); edges.pop();
		int u = get<1>(cur), v = get<2>(cur);
		double w = get<0>(cur);
		if (search(u) == search(v)) continue;
		edge++;
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