#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int N, M, z;
ll c[100001];
ll H[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> H[i];

	for (int i = 0; i < M; ++i) {
		int a, b, k; cin >> a >> b >> k; a--;
		c[a] += k; c[b] -= k;
	}

	for (int i = 0; i < N; ++i) {
		z += c[i];
		cout << H[i] + z << " ";
	}

	return 0;
}