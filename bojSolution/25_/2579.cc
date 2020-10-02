#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	vector<int>dp{ 0 };
	vector<int>v{ 0 };
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	if (t > 3) {
		dp.push_back(v[1]);
		dp.push_back(v[1] + v[2]);
		dp.push_back(max(v[1] + v[3], v[2] + v[3]));

		for (int i = 4; i <= t; ++i) {
			dp.push_back(max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]));
		}
		cout << dp[t];
	}
	else {
		if (t == 1) {
			cout << v[1];
		}
		else if (t == 2) {
			cout << v[1] + v[2];
		}
		else {
			cout << max(v[1] + v[3], v[2] + v[3]);
		}
	}


	return 0;
}