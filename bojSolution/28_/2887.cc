#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;
typedef struct pos {
	int x, y, z, id;
	pos(int X, int Y, int Z, int ID) { x = X, y = Y, z = Z, id = ID; }
} pos;
const int MAX = 100000 + 1;

int component[MAX];
priority_queue<tup, vector<tup>, greater<tup>> edges;
int search(int);
void merge(int, int);

int N;
vector<pos> star;

int getDist(pos a, pos b) {
	return min(abs(a.z - b.z), min(abs(a.x - b.x), abs(a.y - b.y)));
}

bool cmpX(const pos& a, const pos& b) { return (a.x < b.x); }
bool cmpY(const pos& a, const pos& b) { return (a.y < b.y); }
bool cmpZ(const pos& a, const pos& b) { return (a.z < b.z); }

map<pii, bool> visit;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x, y, z; cin >> x >> y >> z;
		star.push_back(pos{ x, y, z, i });
	}
	sort(star.begin(), star.end(), cmpX);
	for (int i = 1; i < N; ++i) {
		visit[ {star[i].id, star[i - 1].id} ] = true;
		edges.push({ getDist(star[i], star[i - 1]), star[i].id, star[i - 1].id });
	}
	sort(star.begin(), star.end(), cmpY);
	for (int i = 1; i < N; ++i) {
		if (visit[{star[i].id, star[i - 1].id}]) continue;
		visit[{star[i].id, star[i - 1].id}] = true;
		edges.push({ getDist(star[i], star[i - 1]), star[i].id, star[i - 1].id });
	}
	sort(star.begin(), star.end(), cmpZ);
	for (int i = 1; i < N; ++i) {
		if (visit[{star[i].id, star[i - 1].id}]) continue;
		visit[{star[i].id, star[i - 1].id}] = true;
		edges.push({ getDist(star[i], star[i - 1]), star[i].id, star[i - 1].id });
	}

	for (int i = 1; i <= N; ++i) component[i] = i;

	ll res = 0;
	while (!edges.empty()) {
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