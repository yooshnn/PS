#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

struct Graph {
    int cap;
    vector<int> par, pp;
    vector<vector<int>> adj;

    Graph(int N) {
        cap = N+1;
        adj.resize(cap);
        par.resize(cap, -1);
        pp.resize(cap, -1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int id) {
        if (id != 1 && adj[id].size() == 1) return pp[id] = 1;
        int ret = 1;
        for (int& next: adj[id]) {
            if (next == 1 || par[next] != -1) continue;
            par[next] = id;
            ret += dfs(next);
        }
        return pp[id] = ret;
    }

    void solve() {
        for (int i = 1; i < cap; ++i) {
            int cnt;
            bool good = true;
            for (int& next: adj[i]) {
                if (next == par[i]) cnt = cap - pp[i] - 1;
                else cnt = pp[next];
                if (cnt > (cap - 1)/2) good = false;
            }
            if (good) cout << i << "\n";
        }
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

    G.dfs(1);
    G.solve();

    return_0;
}