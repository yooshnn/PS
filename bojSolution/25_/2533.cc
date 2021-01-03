#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Graph {
    int cap;
    int res;
    vector<bool> dup;
    vector<pii> dp;
    vector<vector<int>> adj;

    Graph(int N) {
        cap = N+1;
        res = 0;
        adj.resize(cap);
        dp.resize(cap);
        dup.resize(cap, false);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int solve(int id) {
        dup[id] = true;
        dp[id].first = 0, dp[id].second = 1;

        for (int& next: adj[id]) if (!dup[next]) {
            solve(next);
            dp[id].first += dp[next].second;
            dp[id].second += min(dp[next].first, dp[next].second);
        }

        return min(dp[id].first, dp[id].second);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;    
    Graph G(N);

    for (int i = 0, u, v; i < N-1; ++i) {
        cin >> u >> v;
        G.addEdge(u, v);
    }

    cout << G.solve(1) << endl;

}