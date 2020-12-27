#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll N;
unordered_map<ll, int> mos;
vector<ll> check;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0, p, q; i < N; ++i) {
        cin >> p >> q;
        mos[p] += 1;
        mos[q] -= 1;
        check.push_back(p);
        check.push_back(q);
    }

    sort(check.begin(), check.end());
    check.erase(unique(check.begin(), check.end()), check.end());

    int M = -1, h = 0;
    int d0 = -1, d1 = -1, ff = 0, l = 0;

    for (int cur : check) {
        h += mos[cur];
        if (h > M) {
            M = h;
            d0 = cur;
            ff = true;
        }
        if (h < M && ff) {
            d1 = cur;
            ff = false;
        }
        l = cur;
    }
    if (ff) d1 = l;

    cout << M << "\n" << d0 << " " << d1;

}