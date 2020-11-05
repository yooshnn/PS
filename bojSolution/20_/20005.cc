#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef tuple<int, int, int> tup;
typedef pair<int, int> pii;
struct Player;
struct Boss;

int dir[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };

int R, C, P;
char board[1000][1000];

struct Player {
	int r, c, dps, dist, good = false;
	char id;
	Player() {}
	Player(int R, int C, char ID) { r = R; c = C; id = ID; }
};
struct Boss {
	int r, c, hp;
	Boss() {}
	void set(int R, int C) { r = R; c = C; }
	void set(int HP) { hp = HP; }
	bool at(int R, int C) { return (r == R && c == C); }
};

unordered_map<char, Player> p;
Boss b;

int getDist(char id) {
	bool visit[1000][1000];
	queue<tup> que;
	que.push({ p[id].r, p[id].c, 0 });
	memset(visit, 0, sizeof(visit));
	visit[p[id].r][p[id].c] == true;
	int cr, cc, cd, nr, nc;

	while (!que.empty()) {
		tie(cr, cc, cd) = que.front(); que.pop();
		for (int i = 0; i < 4; ++i) {
			if (b.at(cr + dir[0][i], cc + dir[1][i])) return cd;
		}
		for (int i = 0; i < 4; ++i) {
			nr = cr + dir[0][i], nc = cc + dir[1][i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || board[nr][nc] == 'X' || visit[nr][nc]) continue;
			visit[nr][nc] = true;
			que.push({ nr, nc, cd + 1 });
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> P;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'B') b.set(i, j);
			else if (board[i][j] != 'X' && board[i][j] != '.') {
				p[board[i][j]] = Player(i, j, board[i][j]);
				board[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < P; ++i) {
		char pid; int dps; cin >> pid >> dps;
		p[pid].dps = dps;
	} cin >> b.hp;


	for (auto& i : p) {
		p[i.first].dist = getDist(i.first);
	}

	int time = 0;
	while (b.hp > 0) {
		for (auto& i : p) {
			Player& tar = i.second;
			if (tar.dist == -1) continue;
			if (tar.dist <= time) {
				b.hp -= tar.dps;
				tar.good = true;
			}
		}
		time += 1;
	}

	int res = 0;
	for (auto& i : p) {
		if (i.second.good) res++;
	}
	cout << res;
}