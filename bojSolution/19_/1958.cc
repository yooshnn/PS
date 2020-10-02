#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

unsigned dp[101][101][101];

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	for (unsigned i = 1; i <= a.length(); ++i) {
		for (unsigned j = 1; j <= b.length(); ++j) {
			for (unsigned k = 1; k <= c.length(); ++k) {
				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else dp[i][j][k] = max(dp[i][j][k - 1],max(dp[i - 1][j][k], dp[i][j - 1][k]));
			}
		}
	}

	cout << dp[a.length()][b.length()][c.length()];
	return 0;
}