#include <iostream>
#include <string>
#include <queue>
#define pii pair<int,int>
using namespace std;

queue<pii>Q;
char board[1000][1000];
bool visit[1000][1000];

int R, C;
int sheep = 0, wolf = 0;
string line;

void bfs(int x) {
	Q.push({ 0, x });
	while (!Q.empty()) {
		pii cur = Q.front();
		int cy = cur.first, cx = cur.second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy, nx = cx;
			if (i == 0) ny = cy + 1; else if (i == 1) ny = cy - 1; else if (i == 2) nx = cx + 1; else if (i == 3) nx = cx - 1;
			if (nx < 0 || ny < 0 || nx >= C || ny >= R || visit[ny][nx] || board[ny][nx]=='1') continue;
			visit[ny][nx] = true;
			Q.push({ ny,nx });
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
	cin >> R >> C;
	cin.ignore(); cin.clear();
	for (int i = 0; i < R; ++i) {
		getline(cin, line);
		for (int j = 0; j < C; ++j) {
			board[i][j] = line[j];
		}
	}
	for (int j = 0; j < C; ++j) {
		if (!visit[0][j] && board[0][j]=='0') {
			visit[0][j] = true;
			bfs(j);
		}
	}
	for (int j = 0; j < C; ++j) {
		if (visit[R - 1][j]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}