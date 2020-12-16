#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll ans[23];
int dir3[2][6]{ {1, -1, 1, -1, -1, 1}, {1, 0, -1, 1, -1, 0} };
set<pii> dup;

void solve(int depth, pii cur, pii h) {
	pii next;

	for (int i = 3 * (abs(cur.first) % 2); i < 3 + 3 * (abs(cur.first) % 2); ++i) {
		next = { cur.first + dir3[0][i], cur.second + dir3[1][i] };
		if (h == next) continue;
		if (dup.find(next) != dup.end()) {
			ans[depth] += 1;
			// cout << "collision at depth " << depth << ", " << next.first << " " << next.second << "\n";
		}
		else if (depth != 22) {
			dup.insert(next);
			solve(depth + 1, next, cur);
			dup.erase(next);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dup.insert({ 1, 1 });
	dup.insert({ 0, 0 });
	solve(1, { 0, 0 }, { 1, 1 });
	int n; cin >> n; cout << ans[n];
	//for (int i = 1; i <= 22; ++i) cout << ans[i] << " ";
}