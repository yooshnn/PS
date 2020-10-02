#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M, V;
vector<vector<int>> v(1001);

bool visit[1001];


void dfs(int V) {
    cout << V << " ";
    visit[V] = true;

    for (int i = 1; i <= N; ++i) {
        if (count(v[V].begin(), v[V].end(), i)) {
            if (!visit[i]) dfs(i);
        }
    }
}

void bfs(int V) {
    queue<int> Q;
    Q.push(V);
    visit[V] = true;

    while (!Q.empty()) {
        int cur = Q.front();
        visit[cur] = true;
        cout << cur << " ";
        Q.pop();
        
        for (int i = 1; i <= N; ++i) {
            if (count(v[cur].begin(), v[cur].end(), i)) {
                if (!visit[i]) {
                    Q.push(i);
                    visit[i] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> V;
    for (int i = 0; i < M; ++i) {
        int b_, e_;
        cin >> b_ >> e_;
        v[b_].push_back(e_);
        v[e_].push_back(b_);
    }

    dfs(V);
    cout << "\n";
    memset(visit, false, sizeof(visit));
    bfs(V);
        

    return 0;
}