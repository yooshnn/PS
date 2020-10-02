#include <iostream>
#include <tuple>
#include <queue>
#define pii tuple<int,int,int,int>
#define INF 2147483647
using namespace std;

int full = 0;
int M, N, H;
int board[100][100][100];
int time[100][100][100];
bool visit[100][100][100];

int bfs() {
	int ret = 0, cnt = 0;

	queue<pii> Q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < H; ++k) {
				if (board[i][j][k] == 1) {
					Q.push({ i,j,k,0 });
				}
			}
		}
	}

	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();
		if (visit[get<0>(cur)][get<1>(cur)][get<2>(cur)]) continue;
		time[get<0>(cur)][get<1>(cur)][get<2>(cur)] = min(time[get<0>(cur)][get<1>(cur)][get<2>(cur)], get<3>(cur));

		cnt++;
		visit[get<0>(cur)][get<1>(cur)][get<2>(cur)] = true;
		for (int i = 0; i < 6; ++i) {
			int nx, ny, nz, cx, cy, cz;
			cx = get<1>(cur);
			cy = get<0>(cur);
			cz = get<2>(cur);
			if (i == 0) { nz = cz; ny = cy - 1; nx = cx; }
			else if (i == 1) { nz = cz; ny = cy + 1; nx = cx; }
			else if (i == 2) { nz = cz; ny = cy; nx = cx - 1; }
			else if (i == 3) { nz = cz; ny = cy; nx = cx + 1; }
			else if (i == 4) { nz = cz - 1; ny = cy; nx = cx; }
			else if (i == 5) { nz = cz + 1; ny = cy; nx = cx; }
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H || visit[ny][nx][nz] || board[ny][nx][nz] != 0) continue;
			Q.push({ ny,nx,nz,get<3>(cur) + 1 });
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < H; ++k) {
				ret = max(ret, time[i][j][k]);
			}
		}
	}

	if (cnt == full && ret < INF) return ret;
	else return -1;
}

int main() {
	cin >> M >> N >> H;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < H; ++k) {
				time[i][j][k] = INF;
			}
		}
	}

	bool no1 = true;
	for (int k = 0; k < H; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> board[i][j][k];
				if (board[i][j][k] != -1) full++;
				if (board[i][j][k] != 0) time[i][j][k] = 0;
			}
		}
	}

	cout << bfs();

	return 0;
}