#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	vector<pair<int, int>>v;

	for (int i = 0; i < T; ++i) {
		int x, y;
		cin >> y >> x;
		v.push_back(make_pair(y, x));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < T; ++i) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}