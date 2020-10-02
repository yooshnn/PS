#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

ll res, t;

int s[10];
int yj[10];

void dfs(int depth) {
	if (depth == 10) {
		res += (t >= 5); return;
	}
	for (int i = 1; i <= 5; ++i) {
		if (depth >= 2 && i == yj[depth - 1] && i == yj[depth - 2]) continue;
		yj[depth] = i;
		if (i == s[depth]) t++;
		dfs(depth + 1);
		if (i == s[depth]) t--;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; ++i) cin >> s[i];
	for (int i = 1; i <= 5; ++i) {
		yj[0] = i;
		if (i == s[0]) t++;
		dfs(1);
		if (i == s[0]) t--;
	}
	cout << res;

	return 0;
}