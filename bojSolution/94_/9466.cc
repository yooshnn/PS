#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

int con[100010], dup[100010];
bool cycle[100010];

void solve2(int id) {
	cycle[id] = true;
	if (!cycle[con[id]]) solve2(con[id]);
}
void solve(int id) {
	dup[id] = 1;
	if (dup[con[id]] == 0) solve(con[id]);
	else if (dup[con[id]] == 1) solve2(con[id]);
	dup[id] = 2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {

		int res = 0;

		cin >> N;
		memset(dup, 0, (N + 1) * sizeof(int));
		memset(cycle, false, (N + 1) * sizeof(bool));

		for (int i = 1; i <= N; ++i) cin >> con[i];

		for (int i = 1; i <= N; ++i) if (dup[i] == 0) solve(i);

		for (int i = 1; i <= N; ++i) {
			if (!cycle[i]) res++;
		}

		cout << res << "\n";

	}
}