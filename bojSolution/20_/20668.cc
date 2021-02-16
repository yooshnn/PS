#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 9e18;
const ll tenf = 3628800;

struct Dijkstra {
	vector<ll> dist;
	vector<vector<pli>> edges;

	Dijkstra(int n) {
		dist.resize(n, INF);
		edges.resize(n);
	}
	void addEdge(int a, int b, ll w) {
		edges[a].push_back({ w, b });
	}
	void build(int base) {
		priority_queue<pli, vector<pli>, greater<pli>> pque;
		pque.push({ 0.0, base });
		dist[base] = 0;

		ll nw, cw; int nn, cn;
		while (!pque.empty()) {
			tie(cw, cn) = pque.top(); pque.pop();
			if (dist[cn] < cw) continue;

			for (pli& cur : edges[cn]) {
				nw = cw + cur.first, nn = cur.second;
				if (dist[nn] > nw) {
					dist[nn] = nw;
					pque.push({ nw, nn });
				}
			}
		}
	}
	ll ask(int a) {
		return dist[a];
	}
};

int N, M;
int uid(int spd, int i) { return i + 1 + (10005*spd); }

int main() {
   ios::sync_with_stdio(0), cin.tie(0);

   cin >> N >> M;
   Dijkstra G(150000);

   for (int i = 0, a, b, k; i < M; ++i) {
      ll l;
      cin >> a >> b >> l >> k;
      l *= tenf;
      
      for (int s = 1; s <= 10; ++s) {
         if (s <= k) {
            G.addEdge(uid(s, a), uid(s, b), l/s);
            G.addEdge(uid(s, b), uid(s, a), l/s);
         }
         if (s+1 <= k) {
            G.addEdge(uid(s, a), uid(s+1, b), l/(s+1));
            G.addEdge(uid(s, b), uid(s+1, a), l/(s+1));
         }
         if (0 < s-1 && s-1 <= k) {
            G.addEdge(uid(s, a), uid(s-1, b), l/(s-1));
            G.addEdge(uid(s, b), uid(s-1, a), l/(s-1));
         }
      }
   }
   G.build(uid(1, 1));
   
   ll res = INF;
   for (int i = 1; i <= 10; ++i) {
      res = min(res, G.ask(uid(i, N)));
   }

   ll q, r;
   int out[11];

   out[0] = q = res/tenf, r = res%tenf;
   for (int i = 1; i < 11; ++i) {
      q = r*10/tenf, r = (r*10)%tenf;
      out[i] = q;
   }

   if (out[10] >= 5) {
      for (int i = 9; ; --i) {
         out[i] += 1;
         if (i != 0 && out[i] == 10) {
            out[i] = 0;
         }
         else break;
      }
   }
   cout << out[0] << ".";
   for (int i = 1; i <= 9; ++i) cout << out[i];

   
}