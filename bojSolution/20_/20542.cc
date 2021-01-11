#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

bool good(const char& a, const char& b) {
   if (a == 'i') {
      return (b=='i' || b=='j' || b=='l');
   }
   if (a == 'v') {
      return (b=='v' || b=='w');
   }
   return a==b;
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   int n, m; cin >> n >> m;

   string s, t; cin >> s >> t;
   int dp[n+1][m+1];

   for (int i = 0; i <= n; ++i) dp[i][0] = i;
   for (int i = 0; i <= m; ++i) dp[0][i] = i;

   for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (good(s[i-1], t[j-1])) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
		}
	}
   
   cout << dp[n][m];

   return_0;
}