#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int M, N;
bool visit[1001][1001];
int board[1001][1001];
vector<vector<pii>> tar(1000001);
queue<pii> q;

bool bfs() {
    q.push({ 1, 1 });
    visit[1][1] = true;
    while (!q.empty()) {
        int cy = q.front().first, cx = q.front().second; q.pop();
        if (cy == M && cx == N) return true;

        for (pii p : tar[board[cy][cx]]) {
            if (!visit[p.first][p.second]) {
                visit[p.first][p.second] = true;
                if (p.first == M && p.second == N) return true;
                q.push(p);
            }
        }

    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
            tar[i * j].push_back({ i, j });
        }
    }

    cout << (bfs() ? "yes" : "no");

    return 0;
}