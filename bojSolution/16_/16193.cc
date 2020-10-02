#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res;
vector<int> v;
deque<int> d;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i : v) d.push_back(i);

	ll M = d.back(), m = d.front();
	res += M - m;
	d.pop_back(); d.pop_front();

	while (d.size() >= 2) {
		res += abs(M - d.front());
		res += abs(m - d.back());
		m = d.front();
		M = d.back();
		d.pop_front();
		d.pop_back();
	}
	if (!d.empty()) {
		res += max(abs(M - d.front()), abs(m - d.front()));
	}

	cout << res;

	return 0;
}