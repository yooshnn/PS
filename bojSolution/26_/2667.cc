#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool board[25][25];
bool visit[25][25];

int N;
vector<int> v;

int dfs(int y, int x) {
	visit[y][x] = true;
	int ret = 1;
	if (x + 1 < N && !visit[y][x + 1] && board[y][x + 1]) ret += dfs(y, x + 1);
	if (x - 1 >= 0 && !visit[y][x - 1] && board[y][x - 1]) ret += dfs(y, x - 1);
	if (y + 1 < N && !visit[y + 1][x] && board[y + 1][x]) ret += dfs(y + 1, x);
	if (y - 1 >= 0 && !visit[y - 1][x] && board[y - 1][x]) ret += dfs(y - 1, x);
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N;
	cin.ignore();
	cin.clear();

	for (int i = 0; i < N; ++i) {
		string in;
		getline(cin, in);
		for (int j = 0; j < N; ++j) {
			board[i][j] = (in[j] == '1') ? true : false;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visit[i][j] && board[i][j]) {
				int res = 0;
				res += dfs(i, j);
				v.push_back(res);
			}
		}
	}
	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << "\n";
	}


	return 0;
}	