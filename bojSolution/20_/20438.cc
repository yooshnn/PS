#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K, Q, M;
int slp[5010], bad[5010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    fill(&bad[0], &bad[0] + 5010, 1);
    bad[0] = bad[1] = bad[2] = 0;

    cin >> N >> K >> Q >> M;
    for (int i = 0, t; i < K; ++i) {
        cin >> t; slp[t] = true;
    }
    for (int i = 0, t; i < Q; ++i) {
        cin >> t;
        if (bad[t] == 0 || slp[t]) continue;
        for (int j = 1; t * j <= N + 2; ++j) bad[t * j] = slp[t * j];
    }
    for (int i = 3, t = 0; i <= N + 2; ++i) {
        bad[i] += t;
        t = bad[i];
    }

    for (int i = 0, p, q; i < M; ++i) {
        cin >> p >> q;
        cout << bad[q] - bad[p - 1] << "\n";
    }

    //for (int i = 3; i <= N + 2; ++i) cout << bad[i] << " ";
}