#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int N, K, D;
int algo[40];

struct Stu {
  int d;
  vector<int> k;
  bool operator<(const Stu &other) {
    return d < other.d;
  }
} stu[100010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K >> D;
  for (int i = 0; i < N; ++i) {
    int M; cin >> M >> stu[i].d;
    stu[i].k.resize(M);
    for (int &i : stu[i].k) cin >> i;
  }
  sort(stu, stu + N);

  int lp = 0, rp = 0, res = 0;
  while (lp < N) {
    if (rp < N && stu[rp].d - stu[lp].d <= D) {
      int v1 = 0, v2 = 0;
      for (int &i : stu[rp].k) {
        algo[i] += 1;
        if (algo[i] == rp - lp + 1) v2 += 1;
      }
      for (int i = 0; i <= K; ++i) if (algo[i] != 0) v1 += 1;
      res = max(res, (rp - lp + 1) * (v1 - v2));
      rp += 1;
    }
    else {
      for (int &i : stu[lp].k) {
        algo[i] -= 1;
      }
      lp += 1;
    }
  }

  cout << res;

}