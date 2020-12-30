#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;

int N;
double res = 1e8;
vector<pdd> p;

double mag(pdd& a, pdd& b) {
	return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

void solve(vector<int>& v) {
	if (v.size() == N / 2) {
		vector<bool> t(22, 0);
		for (int& i : v) t[i] = 1;
		pdd a{ 0.0, 0.0 }, b{ 0.0, 0.0 };
		for (int i = 0; i < N; ++i) {
			if (t[i]) a.first += p[i].first, a.second += p[i].second;
			else b.first += p[i].first, b.second += p[i].second;
		}
		res = min(res, mag(a, b));
	}
	else {
		for (int i = (v.empty() ? 0 : v[v.size() - 1] + 1); i < N; ++i) {
			v.push_back(i);
			solve(v);
			v.pop_back();
		}
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		cin >> N; p.resize(N);
		for (pdd& x : p) cin >> x.first >> x.second;

		res = 1e8;
		vector<int> v;
		solve(v);

		cout << fixed << setprecision(8) << res << "\n";
	}
}