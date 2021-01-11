#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int R, C, Q, res;
bool field[240][240];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> C >> R >> Q;
	while (Q--) {
		int c0, r0, c1, r1; cin >> c0 >> r0 >> c1 >> r1;
		c0--; r0--; c1--; r1--;
		for (int r = r0; r <= r1; ++r) for (int c = c0; c <= c1; ++c) {
			field[r][c] = true;
		}
	}

	for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) res += field[r][c];

	cout << res;

    return_0;
}