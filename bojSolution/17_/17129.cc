#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#define tup tuple<int,int,int>
using namespace std;

int board[3001][3001];
bool visit[3001][3001];

int N, M;
int family_r, family_c;

int bfs(int _sr, int _sc) {
    queue<tup> Q;
    Q.push({ _sr, _sc, 0 });
    while (!Q.empty()) {
        tup cur = Q.front(); Q.pop();
        int cr = get<0>(cur), cc = get<1>(cur), cm = get<2>(cur);
        if (board[cr][cc] > 2) return cm;
        for (int i = 0; i < 4; ++i) {
            int nr = cr, nc = cc;
            if (i == 0) nr++; else if (i == 1) nr--; else if (i == 2) nc++; else nc--;
            if (nr <= 0 || nc <= 0 || nr > N || nc > M || visit[nr][nc] || board[nr][nc] == 1) continue;
            Q.push({ nr, nc, cm+1 });
            visit[nr][nc] = true;
        }
    }
    return -1;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> N >> M;
    cin.ignore(); cin.clear();

    for (int i = 1; i <= N; ++i) {
        string line;
        getline(cin, line);
        for (int j = 1; j <= M; ++j) {
            board[i][j] = int(line[j - 1]-'0');
            if (board[i][j] == 2) { family_r = i; family_c = j; }
        }
    }

    int res = bfs(family_r, family_c);
    if (res == -1) cout << "NIE\n";
    else {
        cout << "TAK\n";
        cout << res << "\n";
    }

    return 0;
}
