#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

int N;
ll res;
vector<ll> s, pnxt, psum;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  
  s.resize(N);
  pnxt.resize(N, -1);
  psum.resize(N);

  for (ll &i : s) cin >> i;

  pnxt[N-1] = (s[N-1] == 1 ? N-1 : -1);
  psum[N-1] = s[N-1];
  for (int i = N-2; i >= 0; --i) {
    if (s[i] == 1) pnxt[i] = max(pnxt[i+1], (ll)i);
    psum[i] = psum[i+1] + s[i];
  }

  for (int i = 0; i < N; ++i) {
    ll sum = s[i], pro = s[i];
    for (int j = i+1; j < N; ++j) {
      if (s[j] == 1) {
        int pcnt = pnxt[j] - j + 1;
        // cout << pcnt << endl;
        if (sum < pro && pro <= sum + pcnt) res += 1;
        sum += pcnt;
        j = pnxt[j];
      }
      else {
        sum += s[j];
        pro *= s[j];
        if (j != N-1 && sum + psum[j+1] < pro) break;
        if (sum == pro) res += 1;
      }
    }
  }

  cout << res;
}