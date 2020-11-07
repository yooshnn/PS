#include <bits/stdc++.h>
using namespace std;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }
typedef pair<int, int> pii;

int N, K, res;
int zCnt = 0;
deque<pii> belt;

void run() {
	res++;

	belt.push_front(belt.back()); belt.pop_back(); belt[N - 1].second = 0;
	for (int i = N - 2; i >= 0; --i) {
		if (belt[i].second == 0) continue;
		if (belt[i + 1].first > 0 && belt[i + 1].second == 0) {
			belt[i + 1].first -= 1; belt[i + 1].second = 1;
			belt[i].second = 0;
			if (belt[i + 1].first == 0) zCnt++;
		}
	}
	belt[N - 1].second = 0;
	if (belt[0].first > 0 && belt[0].second == 0) {
		belt[0].first -= 1; belt[0].second = 1;
		if (belt[0].first == 0) zCnt++;
	}

	if (zCnt >= K) return;
	run();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	N = input(), K = input();
	for (int i = 0; i < 2 * N; ++i) belt.push_back({ input(), 0 });

	run();
	cout << res;

}