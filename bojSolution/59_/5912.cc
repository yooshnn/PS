#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int N, M, z;
ll c[1000001];
ll H[1000001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b; a--;
		c[a] += 1; c[b] -= 1;
	}

	for (int i = 0; i < N; ++i) {
		z += c[i];
		H[i] += z;
	}

	sort(H, H + N);
	cout << H[(N - 1) / 2];

	return 0;
}