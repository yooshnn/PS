#include <iostream>
#include <tuple>
#include <queue>
#define pii tuple<int,int, int>
#define INF 2147483647
using namespace std;

int full = 0;
int M, N;
int board[1000][1000];
int time[1000][1000];
bool visit[1000][1000];

int bfs() {
	int ret = 0, cnt = 0;

	queue<pii> Q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 1) {
				Q.push({ i,j,0 });
			}
		}
	}

	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();
		if (visit[get<0>(cur)][get<1>(cur)]) continue;
		time[get<0>(cur)][get<1>(cur)] = min(time[get<0>(cur)][get<1>(cur)], get<2>(cur));

		cnt++;
		visit[get<0>(cur)][get<1>(cur)] = true;
		for (int i = 0; i < 4; ++i) {
			int nx, ny, cx, cy;
			cx = get<1>(cur);
			cy = get<0>(cur);
			if (i == 0) { ny = cy - 1; nx = cx; }
			else if (i == 1) { ny = cy + 1; nx = cx; }
			else if (i == 2) { ny = cy; nx = cx - 1; }
			else if (i == 3) { ny = cy; nx = cx + 1; }
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || visit[ny][nx] || board[ny][nx] != 0) continue;
			Q.push({ ny,nx,get<2>(cur) + 1 });
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ret = max(ret, time[i][j]);
		}
	}

	if (cnt == full && ret < INF) return ret;
	else return -1;
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			time[i][j] = INF;
		}
	}

	bool no1 = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] != -1) full++;
			if (board[i][j] != 0) time[i][j] = 0;
		}
	}

	cout << bfs();

	return 0;
}