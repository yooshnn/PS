#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N, M;
bool maze[100][100];
int visited[100][100];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    memset(visited, 0, sizeof(visited));

    cin >> N >> M;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        for (int j = 0; j < M; ++j) {
            maze[i][j] = true;
            if (s[j] == '0') maze[i][j] = false;
        }
    }

    queue< pair<int, int> >q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int x_ = x + (i == 0) - (i == 2), y_ = y + (i == 3) - (i == 1);
            if (x_ < 0 || x_ >= M || y_ < 0 || y_ >= N || visited[y_][x_] > 0 || !maze[y_][x_]) continue;
            visited[y_][x_] = visited[y][x] + 1;
            q.push(make_pair(y_, x_));
        }
    }/*
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << visited[N - 1][M - 1];

    return 0;
}