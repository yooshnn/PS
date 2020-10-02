#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

vector<int> adj[100001];
queue<pii> game;

bool flag;
int N, M, K;
int indegree[100001];
int built[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N >> M >> K;

	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y; // x를 건설해야 y를 건설할 수 있음
		indegree[y]++;
		adj[x].push_back(y);
	}
	for (int i = 0; i < K; ++i) { // 게임정보
		int x, y;
		cin >> x >> y;
		game.push({ x - 1, y }); // 0: 건설 1: 파괴 / y는 건물번호
	}/*
	for (int i = 1; i <= M; ++i) {
		cout << indegree[i] << " ";
	}cout << "\n";*/
	for (int i = 1; i <= K; ++i) {
		pii cur = game.front();
		game.pop();
		if (cur.first == 0) { // 건설
			if (indegree[cur.second] == 0) { 
				if (built[cur.second] == 0) {
					for (int i = 0; i < adj[cur.second].size(); ++i) {
						indegree[adj[cur.second][i]]--;
					}
				}
				built[cur.second]++;
			}
			else {
				//cout << "INVALID BUILD" << endl;
				flag = true;
			}
		}
		else { // 파괴
			if (built[cur.second] > 0) { 
				built[cur.second]--;
				if (built[cur.second] == 0) {
					for (int i = 0; i < adj[cur.second].size(); ++i) {
						indegree[adj[cur.second][i]]++;
					}
				}
			}
			else {
				//cout << "INVALID BREAK" << endl;
				flag = true;
			}
		}
		if (flag) {
			cout << "Lier!";
			return 0;
		}
	}
	cout << "King-God-Emperor";

	return 0;
}