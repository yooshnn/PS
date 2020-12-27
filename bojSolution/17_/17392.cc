#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> h;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M; h.resize(N);
	for (int& x : h) cin >> x;

	int sad = M - accumulate(h.begin(), h.end(), N);
	int res = 0;

	int t = 0;
	while ((N + 1) * (t + 1) < sad) t++;

	for (int i = 1; i <= t; ++i) res += (N + 1) * i * i;
	
	sad -= (N + 1) * t;

	for (int i = 0; i < sad; ++i) res += (t + 1) * (t + 1);

	cout << res;

}