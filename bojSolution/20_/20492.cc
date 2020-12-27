#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll N; cin >> N;

	cout << fixed << ll(N - N * 0.22) << " " << ll(N - N * 0.2 * 0.22);
}