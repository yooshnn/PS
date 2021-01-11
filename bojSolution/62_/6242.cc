#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tup;

ll N;
map<ll, vector<ll>> sl;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (ll i = 0, a, b, h; i < N; ++i) {
		cin >> a >> b >> h;
		sl[a].push_back(h);
		sl[b].push_back(-h);
	}

	ll res = 0, lastP = 0, lastH = 0;
	multiset<ll> hs;
	for (auto& p : sl) {
		int curP = p.first;
		res += (curP - lastP) * lastH;
		for (ll& x : p.second) {
			if (x > 0) hs.insert(x);
			else hs.erase(hs.find(-x));
		}
		ll curH = (hs.empty() ? 0 : *hs.rbegin());
		lastP = curP, lastH = curH;
	}

	cout << res;

    return_0;
}