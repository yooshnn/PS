#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;

int C, H;
bool dp[50010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  dp[0] = 1;

  cin >> C >> H;

  for (int v; H--; ) {
    cin >> v;
    for (int i = C; i >= v; --i) {
      dp[i] |= (dp[i-v] & 1);
    }
  }

  for (int i = C; i >= 0; --i) {
    if (dp[i]) return cout << i, 0;
  }

  sad;
}
