#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int dp[50][50];
string dps[50][50];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	string a, b; cin >> a >> b;
	for (int i = 1; i <= a.size(); ++i) for (int j =1; j <= b.size(); ++j) {
		if (a[i-1] == b[j-1]) {
			dp[i][j] = dp[i-1][j-1] + 1;
			dps[i][j] = dps[i-1][j-1] + a[i-1];
		}
		else {
			if (dp[i-1][j] > dp[i][j-1]) {
				dp[i][j] = dp[i-1][j];
				dps[i][j] = dps[i-1][j];
			}
			else {
				dp[i][j] = dp[i][j-1];
				dps[i][j] = dps[i][j-1];
			}
		}
	}

	cout << dps[a.size()][b.size()];

    return_0;
}