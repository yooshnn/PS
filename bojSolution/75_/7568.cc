#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	vector<pair<int, int>>v;
	for (int i = 0; i < T; ++i) {
		int input1, input2;
		cin >> input1 >> input2;
		v.push_back(make_pair(input1, input2));
	}

	for (int i = 0; i < T; ++i) {
		int res = 1;
		for (int j = 0; j < T; ++j) {
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				res++;
			}
		}
		cout << res << " ";
	}

	return 0;
}