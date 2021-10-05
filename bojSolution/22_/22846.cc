#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int K;
bool dp[100010]; // 0 : 후공 승, 1 : 선공 승
vector<int> v[100010];

void prep();

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  prep();
  
  cin >> K;

  for (int i = K; i >= 1; --i) {
    bool f = false;
    for (int x : v[i]) {
      if (i+x > K) continue;
      f |= 1 - dp[i+x];
    }
    dp[i] = f;
  }

  cout << (dp[1] ? "Kali" : "Ringo");
  
  sad;
}

void prep() {
  for (int i = 1; i <= 50000; ++i) {
    for (int j = 1; i*j <= 100000; ++j) v[i*j].push_back(i);
  }
}