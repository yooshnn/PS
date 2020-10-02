#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int>v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tip;
		cin >> tip;
		v.push_back(tip);
	}
	sort(v.begin(), v.end());

	unsigned long long int res = 0;
	for (int i = N - 1; i >= 0; --i) {
		res += max(0, v[i] - (N - i - 1));
	}
	cout << res;
	return 0;
}