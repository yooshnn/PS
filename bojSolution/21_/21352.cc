#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long fibonacci(int N, char s[]) {
  ll ret = 0;
  vector<ll> psum[2];

  ll b = 0;
  char p = '\0';
  for (int i = 0; i < N; ++i) {
    if (s[i] == 'a' && p == 'a') psum[0].push_back(1);
    else psum[0].push_back(b + 1);
    b = psum[0].back();
    p = s[i];
  }

  b = 0;
  p = '\0';
  for (int i = N-1; i >= 0; --i) {
    if (s[i] == 'a' && p == 'a') psum[1].push_back(1);
    else psum[1].push_back(b + 1);
    b = psum[1].back();
    p = s[i];
  }
  reverse(psum[1].begin(), psum[1].end());

  for (int i = 0; i < N; ++i) ret += (ll)(s[i]=='a') * psum[0][i] * psum[1][i];

  return ret;
}