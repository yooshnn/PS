#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int res[100];
int adj[101];

void go(int c) {
    res[c] += 1;
    if (adj[c] != -1) go(adj[c]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fill(adj, adj + 100, -1);
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int p, q; cin >> p >> q; adj[p] = q;
    }
    for (int i = 1; i <= N; ++i) {
        go(i);
    }
    for (int i = 1; i <= N; ++i) {
        if (res[i] == N) {
            cout << i; return 0;
        }
    } cout << -1;
}