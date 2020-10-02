#include <iostream>
#include <map>
#define pii pair<int,int>
using namespace std;

map<pii, int> m;

bool visit[1001][1001];
char board[1001][1001];
pii root[1001][1001];
int N, M;
int res;

pii search(pii t) {
	int r = t.first, c = t.second;
	if (t == root[r][c]) return t;
	return root[r][c] = search(root[r][c]);
}
void merge(pii a, pii b) {
	a = search(a); b = search(b);
	if (a == b) return;
	if (visit[b.first][b.second] == false) {
		root[b.first][b.second] = a;
	}
	else {
		root[a.first][a.second] = b;
	}
}
void solve(pii t) {
	int r = t.first, c = t.second;
	if (board[r][c] == 'E') c++;
	else if (board[r][c] == 'W') c--;
	else if (board[r][c] == 'S') r++;
	else if (board[r][c] == 'N') r--;
	merge({ t.first, t.second }, { r,c });
	if (visit[t.first][t.second]) return;
	visit[t.first][t.second] = true;
	solve({ r,c });
	//cout << "Merging " << t.first << "," << t.second << " and " << r << "," << c << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> board[i][j];
			root[i][j] = { i, j };
		}
	}
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			solve({ i, j });
			/*for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= M; ++j) {
					cout << root[i][j].first << "," << root[i][j].second << " ";
				}cout << "\n";
			}*/
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (m[{ root[i][j].first, root[i][j].second }] == 0) {
				m[{ root[i][j].first, root[i][j].second }] = 1;
				res++;
			}
			//cout << root[i][j].first << "," << root[i][j].second << " ";
		}//cout << "\n";
	}

	cout << res;	

	return 0;
}