#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
typedef long long ll;

int N, K, res;
ll s[30];

void solve(int b, int t) {
  if (t == K) res += 1;
  if (b == N-1) return;

  for (int i = b+1; i < N; ++i) {
    solve(i, t + s[i]);
  }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> s[i];

  for (int i = 0; i < N; ++i) {
    solve(i, s[i]);
  }

  cout << res;

}