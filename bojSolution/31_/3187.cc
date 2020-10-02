#include <iostream>
#include <string>
#include <queue>
#define pii pair<int,int>
using namespace std;

queue<pii>Q;
char board[250][250];
bool visit[250][250];

int R, C;
int sheep = 0, wolf = 0;
string line;

pii bfs(int y, int x) {
	int s = 0, w = 0;
	Q.push({ y, x });
	while (!Q.empty()) {
		pii cur = Q.front();
		int cy = cur.first, cx = cur.second;
		Q.pop();
		if (board[cy][cx] == 'v') w++;
		else if (board[cy][cx] == 'k') s++;
		for (int i = 0; i < 4; ++i) {
			int ny = cy, nx = cx;
			if (i == 0) ny = cy + 1; else if (i == 1) ny = cy - 1; else if (i == 2) nx = cx + 1; else if (i == 3) nx = cx - 1;
			if (nx < 0 || ny < 0 || nx >= C || ny >= R || visit[ny][nx]) continue;
			visit[ny][nx] = true;
			Q.push({ ny,nx });
		}
	}
	if (s > w) return { s, 0 };
	else return { 0, w };
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
	cin >> R >> C;
	cin.ignore(); cin.clear();
	for (int i = 0; i < R; ++i) {
		getline(cin, line);
		for (int j = 0; j < C; ++j) {
			board[i][j] = line[j];
			if (line[j] == '#') visit[i][j] = true;
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				pii tempCnt = bfs(i, j);

				/*for (int i = 0; i < R; ++i) {
					for (int j = 0; j < C; ++j) {
						cout << (visit[i][j] ? "â– " : "â–¡");
					}cout << endl;
				}*/

				sheep += tempCnt.first;
				wolf += tempCnt.second;
			}
		}
	}
	cout << sheep << " " << wolf;
}