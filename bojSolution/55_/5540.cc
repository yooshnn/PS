#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;

using pii = pair<int, int>;

int
  N, T, S,
  res = 0,
  y[3010][2],
  dpl[3010][3010], dpr[3010][3010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> T >> S;
  for (int i = 1; i <= N; ++i) {
    cin >> y[i][0] >> y[i][1];
  }

  for (int i = 1; i <= N; ++i) {
    for (int t = 1; t <= T; ++t) {
      if (y[i][1] > t) dpl[i][t] = dpl[i-1][t];
      else dpl[i][t] = max(dpl[i-1][t], dpl[i-1][t-y[i][1]] + y[i][0]);
    }
  }
  for (int i = N; i >= 1; --i) {
    for (int t = 1; t <= T; ++t) {
      if (y[i][1] > t) dpr[i][t] = dpr[i+1][t];
      else dpr[i][t] = max(dpr[i+1][t], dpr[i+1][t-y[i][1]] + y[i][0]);
    }
  }

  /*
  cout << "@ DPL" << endl;
  for (int i = 1; i <= N; ++i) {
    for (int t = 1; t <= T; ++t) {
      cout << setw(3) << dpl[i][t];
    } cout << endl;
  } cout << endl;

  cout << "@ DPR" << endl;
  for (int i = 1; i <= N; ++i) {
    for (int t = 1; t <= T; ++t) {
      cout << setw(3) << dpr[i][t];
    } cout << endl;
  } cout << endl;
  */

  for (int i = 0; i <= N; ++i) {
    // cout << i << " " << N-i << " : " << dpl[i][S] << " + " << dpr[i+1][T-S] << " = " << dpl[i][S] + dpr[i+1][T-S] << endl;
    res = max(res, dpl[i][S] + dpr[i+1][T-S]);
  }

  cout << res;

  sad;
}

