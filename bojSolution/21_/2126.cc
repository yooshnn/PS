#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const double t = 0.000001;

struct Eg {
	ll i, j, t, c;
	double r;
	
	bool operator<(Eg const &other) { return r<other.r; }
};

int N, M, F, root[410];
vector<Eg> v;

int dsfind(int t) { return (t == root[t] ? t : root[t] = dsfind(root[t])); }
void dsmerge(int a, int b) { a = dsfind(a), b = dsfind(b); if (a != b) root[a] = b; }

bool check(double m) {
	for (int i = 1; i <= N; ++i) root[i] = i;
	for (Eg &x : v) x.r = m * (double)x.t + (double)x.c;
	sort(all(v));
		
	double p = 0;
	for (Eg &x : v) {
		if (dsfind(x.i) == dsfind(x.j)) continue;
		dsmerge(x.i, x.j);
		p += x.r;
	}
		
	return p <= (double)F;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> N >> M >> F;
	v.resize(M);
	for (Eg &x : v) cin >> x.i >> x.j >> x.c >> x.t;
	
	double lp = 0, rp = 2e9, m, res = 0;
	while (lp + t <= rp) {
		m = (lp + rp) / 2;
		if (check(m)) lp = m + t, res = max(res, m);
		else rp = m - t;
	}
	
	cout << setprecision(4) << fixed << res;
}