#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;
int x, y;
int board[250001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) cin >> board[i];
	/*for (int i = N; i >= 1; --i) {
		cout << i << " ";
		for (int j = 0; j < board[i]; ++j) cout << "*"; cout << "\n";
	}*/
	for (int i = 1; i <= Q; ++i) {
		cin >> x >> y;
		int req = (lower_bound(board + y, board + N + 1, x - 1, greater<int>()) - (board + y));
		// cout << "@ " << (board[y] - x + 1) << " " << req << " = " << (board[y] - x + 1) + req - 1 << "\n";
		cout << max(0, (board[y] - x + 1) + req - 1) << "\n";
	}

	return 0;
}