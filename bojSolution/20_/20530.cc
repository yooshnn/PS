#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;

int root[200010];
int search(int tar) {
    if (tar == root[tar]) return tar;
    return root[tar] = search(root[tar]);
}
void merge(int a, int b) {
    a = search(a), b = search(b);
    if (a == b) return;
    root[b] = a;
}

struct Graph {
    int cap;
    bool flag;
    vector<bool> dup, cycle;
    vector<int> par;
    vector<vector<int>> adj;

    Graph(int sz) {
        cap = sz + 1;
        flag = false;
        dup.resize(cap, false);
        par.resize(cap, -1);
        cycle.resize(cap, false);
        adj.resize(cap);
    }
    void addEdge(int p, int q) {
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    void dfs(int p, int id) {
        dup[id] = true;
        for (int& next : adj[id]) {
            if (next == p || flag) continue;
            if (dup[next]) {
                flag = true;
                cycleIt(next, id);
                tieIt(next, id);
                return;
            }
            else {
                par[next] = id;
                dfs(id, next);
            }
        }
    }

    void cycleIt(int p, int id) {
        cycle[id] = true;
        if (par[id] != -1 && id != p) cycleIt(p, par[id]);
    }

    void tieIt(int p, int id) {
        for (int& next : adj[id]) {
            if (!cycle[next] && search(id) != search(next)) go(id, next);
        }
        if (par[id] != -1 && id != p) tieIt(p, par[id]);
    }

    void go(int p, int id) {
        merge(p, id);
        for (int& next : adj[id]) {
            if (!cycle[next] && search(id) != search(next)) go(p, next);
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    Graph G(N);
    for (int i = 0, p, q; i < N; ++i) {
        cin >> p >> q;
        G.addEdge(p, q);
        root[i + 1] = i + 1;
    }
    G.dfs(-1, 1);

    /* for (int i = 1; i <= N; ++i) cout << G.par[i] << " ";
     cout << endl;
     for (int i = 1; i <= N; ++i) cout << G.cycle[i] << " ";
     cout << endl;
     for (int i = 1; i <= N; ++i) cout << root[i] << " ";
     cout << endl;*/

    for (int i = 0, p, q; i < Q; ++i) {
        cin >> p >> q;
        if (search(p) == search(q)) cout << 1;
        else cout << 2;
        cout << "\n";
    }

}