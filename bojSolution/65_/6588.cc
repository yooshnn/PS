#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool seive[1000002];
vector<int> p;

void solve() {
    seive[0] = seive[1] = true;
    for (int i = 2; i < 1001; ++i) {
        if (seive[i]) continue;
        for (int j = 2; i * j <= 1000000; ++j) seive[i * j] = true;
    }
    for (int i = 2; i < 1000000; ++i) {
        if (!seive[i]) p.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    while (1) {
        int t; cin >> t; if (t == 0) break;
        for (int i : p) {
            if (!seive[t - i]) {
                cout << t << " = " << i << " + " << t - i << "\n";
                break;
            }
        }
    }
}