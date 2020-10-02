#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N;
char board[101][101];
bool visit[101][101];
string line;
int res1 = 0, res2 = 0;

void dfs(int row, int col, char chr) {
	if (board[row][col] != chr) return;

	visit[row][col] = true;

	for (int i = 0; i < 4; ++i) {
		int nr = row, nc = col;
		if (i == 0) nc += 1;
		else if (i == 1) nr -= 1;
		else if (i == 2) nc -= 1;
		else nr += 1;
		if (visit[nr][nc] || nc < 1 || nc > N || nr < 1 || nr > N) continue;
		dfs(nr, nc, chr);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N;
	cin.ignore();
	cin.clear();

	for (int i = 1; i <= N; ++i) {
		getline(cin, line);
		for (int j = 1; j <= N; ++j) {
			board[i][j] = line[j-1];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (!visit[i][j]) {
				dfs(i, j, board[i][j]);
				res1++;
			}
		}
	}

	memset(visit, 0, sizeof(visit));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (board[i][j] == 'R') board[i][j] = 'G';
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (!visit[i][j]) {
				dfs(i, j, board[i][j]);
				res2++;
			}
		}
	}
	
	cout << res1 << " " << res2 << "\n";

	return 0;
}