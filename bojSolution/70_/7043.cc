#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, T; cin >> N >> T;
    map<int, int> cow; // cow[i] = j; [i - j]
    set<int> pp;

    for (int i = 0, p, q; i < N; ++i) {
        cin >> p >> q; cow[p] = max(cow[p], q);
        pp.insert(p);
    }

    if (cow.find(1) == cow.end()) {
        cout << -1; return 0;
    }

    int l = 1, L = cow[1], res = 1;
    while (L < T) {
        res += 1;

        int tmp = L;
        for (std::map<int, int>::iterator t = cow.lower_bound(l); t != cow.end() && (t->first <= L + 1); ++t) {
            tmp = max(tmp, t->second);
        }

        if (tmp == L) {
            cout << -1;
            return 0;
        }

        l = L;
        L = tmp;
    }

    cout << res;
}