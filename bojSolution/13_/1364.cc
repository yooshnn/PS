#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

ll N, k;
vector<ll> dp(2);

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  dp[1] = 7;

  for (int i = 2; i*6 <= 1000010; ++i) {
    dp.push_back(dp.back() + i*6);
  }

  cin >> N;
  
  if (N < 6) cout << N;
  else cout << dp[N/6]+max(0LL, ((N%6)*(1+N/6)-1));

  
  sad;
}
