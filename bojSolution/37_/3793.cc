#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

unsigned dp[1001][1001];

int main() {
	string a, b;

	while (1) {
		memset(dp, 0, sizeof(dp));
		if (cin >> a) {
			cin >> b;

			for (unsigned i = 1; i <= a.length(); ++i) {
				for (unsigned j = 1; j <= b.length(); ++j) {
					if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
					else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}

			cout << dp[a.length()][b.length()] << "\n";
		}
		else {
			break;
		}
	}
	return 0;
}