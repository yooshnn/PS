#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

const int INF = 2147483647;
const int V_MAX = 101;
const int E_MAX = 5000;

int V, E; // 정점, 간선
int u, v, w; // 길의 시작, 끝, 가중치
int k_num, K;

vector< pair<int, int> > vertex[V_MAX];
int LOOP;
long int dist[V_MAX];
long int sum_dist[V_MAX];
bool visit[V_MAX];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > PQ;

void flush();
int dijkstra(int sp = 1, int ep = V);

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);

    cin >> LOOP;
    while (LOOP--) {
        cin >> V >> E;

        for (int i = 0; i < V_MAX; ++i) {
            vertex[i].clear();
        }
        memset(sum_dist, 0, sizeof(sum_dist));


        for (int i = 0; i < E; ++i) {
            cin >> u >> v >> w;
            vertex[u].push_back(make_pair(w, v));
            vertex[v].push_back(make_pair(w, u));
        }

        cin >> k_num;
        for (int i = 1; i <= k_num; ++i) {
            cin >> K;
            flush();
            dijkstra(K);
            for (int i = 0; i <= V; ++i) {
                if (sum_dist[i] < INF) {
                    sum_dist[i] += dist[i];
                }
                else {
                    sum_dist[i] = INF;
                }
            }
        }

        long int mnm = INF;
        for (int i = 1; i <= V; ++i) {
            mnm = min(mnm, sum_dist[i]);
        }

        for (int i = 1; i <= V; i++) {
            if (sum_dist[i] == mnm) {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}

void flush() {
    for (int i = 0; i < V_MAX; ++i) {
        dist[i] = INF;
    }
    for (int i = 0; i < V_MAX; ++i) {
        visit[i] = false;
    }
}

int dijkstra(int sp, int ep) {
    dist[sp] = 0;
    PQ.push(make_pair(0, sp));
    while (!PQ.empty()) {
        int cw = PQ.top().first, cv = PQ.top().second;
        PQ.pop();

        if (visit[cv] == true) continue;
        if (dist[cv] < cw) continue;
        visit[cv] = true;

        for (int i = 0; i < vertex[cv].size(); ++i) {
            int there = vertex[cv][i].second, next = cw + vertex[cv][i].first;
            if (dist[there] > next) {
                dist[there] = next;
                PQ.push(make_pair(next, there));
            }
        }
    }
    return dist[ep];
}