#include <iostream>
#include <algorithm>
#include <queue>
#define INF 2147483647
#define pii pair<int,int>
using namespace std;

int R, C;
int board[501][501];
int ans[501][501];
pii visit[501][501];

pii dfs(int y, int x) {
	pii v = visit[y][x];
	if (v.first != 0 && v.second != 0) return v; // 현 위치에 도착 지점 정보가 찍혀있으면 그 위치 리턴

	pii next = { y, x }; // 다음 위치 (8칸) 탐색
	int boardcmp = board[y][x];
	if (x + 1 <= C)				  if (boardcmp > board[y][x + 1]) { boardcmp = board[y][x + 1];		next = { y, x + 1 }; }
	if (x + 1 <= C && y - 1 > 0)  if (boardcmp > board[y - 1][x + 1]) { boardcmp = board[y - 1][x + 1];	next = { y - 1, x + 1 }; }
	if (y - 1 > 0)				  if (boardcmp > board[y - 1][x]) { boardcmp = board[y - 1][x];		next = { y - 1, x }; }
	if (x - 1 > 0 && y - 1 > 0)   if (boardcmp > board[y - 1][x - 1]) { boardcmp = board[y - 1][x - 1];	next = { y - 1, x - 1 }; }
	if (x - 1 > 0)				  if (boardcmp > board[y][x - 1]) { boardcmp = board[y][x - 1];		next = { y, x - 1 }; }
	if (x - 1 > 0 && y + 1 <= R)  if (boardcmp > board[y + 1][x - 1]) { boardcmp = board[y + 1][x - 1];	next = { y + 1, x - 1 }; }
	if (y + 1 <= R)				  if (boardcmp > board[y + 1][x]) { boardcmp = board[y + 1][x];		next = { y + 1, x }; }
	if (x + 1 <= C && y + 1 <= R) if (boardcmp > board[y + 1][x + 1]) { boardcmp = board[y + 1][x + 1];	next = { y + 1, x + 1 }; }

	if (board[next.first][next.second] >= board[y][x]) { // 현 위치가 제일 작으면 현 위치 정보 리턴	
		return { y , x };
	}
	else { // 다음 위치가 있다면 거기서 정보를 받아와 저장함
		pii request = dfs(next.first, next.second);
		visit[y][x] = request;
		return request;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> R >> C;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			visit[i][j] = { 0,0 };
		}
	}
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			pii request = dfs(i, j);
			ans[request.first][request.second]++;
		}

	}
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}