#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <functional>

using namespace std;

const int INF = 2147483647;
const int V_MAX = 300001;
const int E_MAX = 1000001;

int V, E, K; // 정점, 간선, 시작점
int u, v, w; // 길의 시작, 끝, 가중치
int X;

vector< pair<int, int> > vertex[V_MAX];
long int dist[V_MAX];
bool visit[V_MAX];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > PQ;

void flush(); // 각 지점까지의 거리, 방문여부 초기화
int dijkstra(int sp = 1, int ep = V); // 다익스트라 default: 1, 마지막 정점

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);

    cin >> V >> E >> X >> K;

    for (int i = 0; i < E; ++i) { // 시작점, 도착점, 가중치 입력
        cin >> u >> v;
        vertex[u].push_back(make_pair(1, v));
        //vertex[v].push_back(make_pair(1, u)); // 일방통행이 아니면 주석 해제
    }

    flush();
    dijkstra(K);

    bool fflag = true;
    for (int i = 1; i <= V; i++) {
        if (dist[i] == X) {
            cout << i << "\n"; fflag = false;
        }
    }
    if (fflag) cout << -1 << "\n";


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