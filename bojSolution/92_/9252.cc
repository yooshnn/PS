#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

unsigned dp[1001][1001];
string dps[1001][1001];

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);

	for (unsigned i = 1; i <= a.length(); ++i) {
		for (unsigned j = 1; j <= b.length(); ++j) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				dps[i][j] = dps[i - 1][j - 1] + a[i - 1];
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					dps[i][j] = dps[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - 1];
					dps[i][j] = dps[i][j - 1];
				}
			}
		}
	}
	cout << dp[a.length()][b.length()] << "\n";
	cout << dps[a.length()][b.length()];
	return 0;
}