#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int M, K, res = 0;
int dp[170010];
bool g[200];
vector<int> adj;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> M >> K;

  adj.resize(K);
  for (int &i : adj) cin >> i;

  for (int i = 1; i <= 170000; ++i) {
    memset(&g[0], 0, sizeof g);
    for (int nxt : adj) {
      if (i-nxt < 0) break;
      g[dp[i-nxt]] = true;
    }
    for (int j = 0; j < 200; ++j) {
      if (!g[j]) {
        dp[i] = j;
        break;
      }
      assert(j < 200);
    }
  }

  if (M <= 170000) {
    for (int i = 1; i <= M; ++i) res += (dp[i] == 0);
    cout << res;
    sad;
  }

  int len = -1, cnt = 0;
  for (int guess = 10000; cnt < 4 && guess >= 1; --guess) {
    bool good = true;
    for (int i = 100001; good && i < 100001+guess; ++i) {
      for (int k = 1; k <= 5; ++k) {
        if (dp[i] != dp[i+guess*k]) good = false; 
      }
    }
    if (good) {
      cnt += 1;
      len = __gcd((len != -1 ? len : guess), guess);
    }
  }

  for (int i = 1; i <= 100000; ++i) res += (dp[i] == 0);
  M -= 100000;
  
  int inCycle = 0;
  for (int i = 100001; i < 100001+len; ++i) inCycle += (dp[i] == 0);
  res += (M/len) * inCycle;
  M %= len;
  for (int i = 100001; i < 100001+M; ++i) res += (dp[i] == 0);

  cout << res;

  sad;

}