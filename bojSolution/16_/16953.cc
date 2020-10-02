#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll A, B, res = -1;
priority_queue<pii> Q;
map<ll, bool> visit;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> A >> B;
	Q.push({ 1, A });
	visit[A] = true;
	while (!Q.empty()) {
		pii cur = Q.top(); Q.pop();
		if (cur.second == B) {
			res = cur.first;
			break;
		}
		if (!visit[cur.second * 10 + 1] && cur.second * 10 + 1 <= 1000000000) {
			visit[cur.second * 10 + 1] = true;
			Q.push({ cur.first + 1, cur.second * 10 + 1 });
		}
		if (!visit[cur.second * 2] && cur.second * 2 <= 1000000000) {
			visit[cur.second * 2] = true;
			Q.push({ cur.first + 1, cur.second * 2 });
		}
	}
	cout << res;

	return 0;
}
