#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;

int main() {
	cin >> N;
	vector<pii> v; for (int i = 0; i < N; ++i) {
		int input; cin >> input; v.push_back({ input, i });
	}
	sort(v.begin(), v.end());

	vector<int> res(N);
	for (int i = 0; i < N; ++i) res[v[i].second] = i;

	for (int i : res) cout << i << " ";
}