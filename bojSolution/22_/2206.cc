#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#define INF 2147483647
#define tup tuple<int,int,int,bool> // y x moves broken
using namespace std;

int N, M;
int board[1000][1000];

bool visit[1000][1000][2];

int bfs() {
	int ret = INF;
	queue<tup> Q;
	Q.push({ 0,0,0,false });

	while (!Q.empty()) {
		tup cur = Q.front();
		Q.pop();

		int cy = get<0>(cur), cx = get<1>(cur), moves = get<2>(cur);
		bool broken = get<3>(cur);

		if (cy == N - 1 && cx == M - 1) {
			return moves + 1;
		}

		if (visit[cy][cx][broken]) continue;
		visit[cy][cx][broken] = true;

		for (int i = 0; i < 4; ++i) {
			int nx = cx, ny = cy;
			if (i == 0) nx += 1; else if (i == 1) ny -= 1; else if (i == 2) nx -= 1; else ny += 1;
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || visit[ny][nx][broken]) continue;
			if (board[ny][nx] == -1) {
				if (broken == false) {
					Q.push({ ny,nx,moves + 1,true });
					continue;
				}
			}
			else {
				Q.push({ ny,nx,moves + 1, broken });
			}
		}
	}

	return ret;
}

int main() {
	cin >> N >> M;

	cin.clear();
	cin.ignore();

	for (int i = 0; i < N; ++i) {
		string line;
		getline(cin, line);
		for (int j = 0; j < M; ++j) {
			board[i][j] = (line[j] - '0' == 0) ? 0 : -1;
		}
	}

	int res = bfs();
	cout << ((res == INF) ? -1 : res);


	return 0;
}