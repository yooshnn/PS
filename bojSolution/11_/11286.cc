#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll> tup;

priority_queue<tup, vector<tup>, greater<tup>> que;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; while (TEST--) {
		int n; cin >> n;
		if (n == 0) {
			if (que.empty()) cout << "0\n";
			else {
				cout << get<1>(que.top()) << "\n";
				que.pop();
			}
		}
		else que.push({ n > 0 ? n : -n, n });
	}
}