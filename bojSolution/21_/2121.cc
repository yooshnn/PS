#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
set<pll> t;
vector<pll> tt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, a, b, p, q, res = 0; cin >> n >> a >> b; while (n--) {
        cin >> p >> q; t.insert({ p, q }); tt.push_back({ p, q });
    }
    for (pll& i : tt) {
        int pp = 3;
        if (t.count({ i.first + a, i.second + b })) pp--;
        if (t.count({ i.first + a, i.second })) pp--;
        if (t.count({ i.first, i.second + b })) pp--;
        if (!pp) res++;
    }
    cout << res;
}