#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M;
bool arr[4010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> arr[i];
  for (int a, b, c; M--; ) {
    cin >> a >> b >> c;
    if (a == 1) arr[b] = c;
    else {
      for (int x = b; x <= c; ++x) {
        if (a == 2) arr[x] ^= 1;
        if (a == 3) arr[x] = 0;
        if (a == 4) arr[x] = 1;
      }
    }
  }

  for (int i = 1; i <= N; ++i) cout << arr[i] << " ";

  sad;

}
