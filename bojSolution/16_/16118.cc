#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

struct Dijkstra {
	ll INF = 1e16;

    int cap;
	vector<ll> dist_f;
	vector<ll> dist_w[2];
	vector<vector<pli>> adj;

	Dijkstra(int N) {
        cap = N+1;
		dist_f.resize(cap, INF);
		dist_w[0].resize(cap, INF);
		dist_w[1].resize(cap, INF);
		adj.resize(cap);
	}
	void addEdge(int u, int v, ll w) {
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
	void fox(int base) {
		priority_queue<pli, vector<pli>, greater<pli>> que;
        que.push({ 0LL, base });
		dist_f[base] = 0LL;
		ll cw, nw; int cn, nn;
		while (!que.empty()) {
			tie(cw, cn) = que.top(); que.pop();
			if (dist_f[cn] < cw) continue;
			for (pli& next : adj[cn]) {
				nw = cw + (next.first / 2), nn = next.second;
				if (dist_f[nn] > nw) {
					dist_f[nn] = nw;
					que.push({ nw, nn });
				}
			}
		}
	}
	void wolf(int base) {
		priority_queue<pli, vector<pli>, greater<pli>> que;
        que.push({ 0LL, base });
		dist_w[1][base] = 0LL;
		ll cw, nw; int cn, nn;
		while (!que.empty()) {
			tie(cw, cn) = que.top(); que.pop();
            bool bit = cn > 0; cn = abs(cn);
            if (dist_w[bit][cn] < cw) continue;
            for (pli& next : adj[cn]) {
                nw = cw + (next.first / (bit ? 4 : 1)), nn = next.second;
                if (dist_w[bit^1][nn] > nw) {
                    dist_w[bit^1][nn] = nw;
                    que.push({ nw, (bit ? -nn : nn) });
                }
            }
		}
	}
	bool ask(int a) {
		if (dist_f[a] == INF) return false;
        return (dist_f[a] < min(dist_w[0][a], dist_w[1][a]));
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

    int V, E; cin >> V >> E;
    Dijkstra G(V);

    for (int i = 0; i < E; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        G.addEdge(u, v, w * 4);
    }

    G.fox(1);
    G.wolf(1);

    int res = 0;
    for (int i = 1; i <= V; ++i) {
        if (G.ask(i)) res += 1;
        // cout << G.dist_f[i] << " | " << G.dist_w[0][i] << " " << G.dist_w[1][i] << endl;
    }

    cout << res;
    
}