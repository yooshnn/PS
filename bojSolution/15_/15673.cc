#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

int N;
ll
  resmin = -INF, resmax = -INF,
  s[100010],
  c[100010][2],
  l[100010][2], r[100010][2];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> s[i];

  c[1][0] = c[1][1] = l[1][0] = l[1][1] = s[1];

  for (int i = 2; i <= N; ++i) {
    c[i][0] = (c[i-1][0] > 0 ? s[i] : c[i-1][0] + s[i]);
    c[i][1] = (c[i-1][1] < 0 ? s[i] : c[i-1][1] + s[i]);

    l[i][0] = min(l[i-1][0], c[i][0]);
    l[i][1] = max(l[i-1][1], c[i][1]);
  }

  memset(&c[0][0], 0, sizeof c);
  c[N][0] = c[N][1] = r[N][0] = r[N][1] = s[N];

  for (int i = N-1; i >= 1; --i) {
    c[i][0] = (c[i+1][0] > 0 ? s[i] : c[i+1][0] + s[i]);
    c[i][1] = (c[i+1][1] < 0 ? s[i] : c[i+1][1] + s[i]);

    r[i][0] = min(r[i+1][0], c[i][0]);
    r[i][1] = max(r[i+1][1], c[i][1]);
  }

  for (int i = 2; i <= N; ++i) {
    resmin = max(resmin, l[i-1][0] * r[i][0]);
    resmax = max(resmax, l[i-1][1] * r[i][1]);
  }
  cout << max(resmin, resmax);


  sad;
}

