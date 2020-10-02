#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M, V;
vector<vector<int>> v(101);

bool visit[101];

int bfs(int V) {
    int ret = 0;

    queue<int> Q;
    Q.push(V);

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (visit[cur]) continue;
        visit[cur] = true;
        ret++;

        for (int i = 0; i < v[cur].size(); ++i) {
            if (!visit[v[cur][i]]) {
                Q.push(v[cur][i]);
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    V = 1;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int b_, e_;
        cin >> b_ >> e_;
        v[b_].push_back(e_);
        v[e_].push_back(b_);
    }

    cout << bfs(V) - 1;


    return 0;
}