#include <iostream>
#include <cstring>
using namespace std;

int T, M, N, K, X, Y, res = 0;
bool bb[50][50];
bool visited[50][50];

void dfs(int y, int x) {
    visited[y][x] = true;

    if (y + 1 < N && !visited[y + 1][x] && bb[y + 1][x]) dfs(y + 1, x);
    if (y - 1 >= 0 && !visited[y - 1][x] && bb[y - 1][x]) dfs(y - 1, x);
    if (x + 1 < M && !visited[y][x + 1] && bb[y][x + 1]) dfs(y, x + 1);
    if (x - 1 >= 0 && !visited[y][x - 1] && bb[y][x - 1]) dfs(y, x - 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    cin >> T;
    while (T--) {
        memset(visited, false, sizeof(visited));
        memset(bb, false, sizeof(bb));
        res = 0;

        cin >> M >> N >> K;
        for (int i = 0; i < K; ++i) {
            cin >> X >> Y;
            bb[Y][X] = true;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (bb[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    res++;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}