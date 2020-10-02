#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int senpai[1001];
bool visit[1001];
int chain[1001];
int N, maxchain, res;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> senpai[i];
	for (int i = 1; i <= N; ++i) {
		memset(visit, false, sizeof(visit));
		int cur = i, cnt = 0;
		while (!visit[cur]) {
			cnt++;
			visit[cur] = true;
			cur = senpai[cur];
			if (cur == i) break;
		}
		chain[i] = cnt;
	}

	res = max_element(chain, chain + N) - chain;
	cout << res;

	return 0;
}
