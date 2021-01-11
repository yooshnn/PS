#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N;

	vector<ll> dist(N, 0); for (int i = 1; i < N; ++i) cin >> dist[i];
	vector<ll> cost(N); for (ll& x : cost) cin >> x;
	for (int i = 1; i < N; ++i) dist[i] += dist[i-1];

	ll res = 0;
	int cur = 0, next = 1;

	while (next < N) {
		while (next != N-1 && cost[next] >= cost[cur]) next++;
		res += cost[cur] * (dist[next]-dist[cur]);
		cur = next++;
	}
	cout << res;

    return_0;
}