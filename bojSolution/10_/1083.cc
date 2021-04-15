#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int N, S;
int arr[52];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  cin >> S;

  int comp = -1;
  while (S > 0) {
    pii M{-1, -1};
    for (int i = comp + 1; i <= min(N - 1, comp + 1 + S); ++i) {
      if (arr[i] > M.first) M = {arr[i], i};
    }
    for (int i = M.second; i > comp + 1; --i) {
      swap(arr[i], arr[i - 1]);
      S -= 1;
    }
    comp += 1;
    if (comp == N-1) break;
  }
  for (int i = 0; i < N; ++i) cout << arr[i] << " ";
}