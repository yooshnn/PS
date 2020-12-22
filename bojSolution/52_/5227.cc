#include <bits/stdc++.h>
using namespace std;

int N, M;
struct Graph {
    int N;
    vector<int> deg, grd;
    vector<set<int>> adjGrundy;
    vector<vector<int>> adj;

    Graph(int N) {
        this->N = N;
        deg.resize(N, 0);
        grd.resize(N, -1);
        adjGrundy.resize(N);
        adj.resize(N);
    }

    void connect(int p, int q) {
        adj[q].push_back(p);
        deg[p]++;
    }
    void calc() {
        queue<int> que;
        for (int i = 0; i < N; ++i) {
            if (deg[i] == 0) que.push(i), grd[i] = 0;
        }

        while (!que.empty()) {
            int cur = que.front(); que.pop();
            if (grd[cur] == -1) {
                int tt = 0;
                while (adjGrundy[cur].find(tt) != adjGrundy[cur].end()) {
                    tt++;
                }
                grd[cur] = tt;
            }
            for (int next : adj[cur]) {
                adjGrundy[next].insert(grd[cur]);
                deg[next]--;
                if (deg[next] == 0) que.push(next);
            }
        }
    }

};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    while (1) {
        cin >> N >> M;
        if (N == 0) break;
        Graph G(N);
        for (int i = 0, p, q; i < M; ++i) {
            cin >> p >> q;
            G.connect(p, q);
        }
        G.calc();
        int r = 0;
        for (int i = 0, p; i < N; ++i) {
            cin >> p;
            for (int j = 0; j < p; ++j) r ^= G.grd[i];
        }
        cout << (r == 0 ? "Second" : "First") << "\n";
    }
}