#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
unsigned long long int res, last = 0;
vector<pair<int, int>>v;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		if (last < v[i].second) {
			res += v[i].second - last;
		}
		last = v[i].second;
	}

	cout << res;

	return 0;
}