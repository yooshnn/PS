#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int N;
int xtoi[300000], depth[300000], weight[300000];
int xx;

// xtoi 로 왼쪽에서 x번째 노드의 index 알 수 있음
// index로 depth와 weight 접근 가능

void dfs(int i, int d) {
  depth[i] = d;
  if (2*i <= N) dfs(2*i, d+1);
  xtoi[++xx] = i;
  if (2*i + 1 <= N) dfs(2*i + 1, d+1);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> weight[i];
  dfs(1, 1);

  /*
  for (int i = 1; i <= N; ++i) cout << xtoi[i] << " ";
  cout << endl;
  for (int i = 1; i <= N; ++i) cout << depth[i] << " ";
  cout << endl;
  */

  int maxDepth = *max_element(&depth[1], &depth[1] + N);

  ll res = -2e9, temp;
  for (int u = 1; u <= maxDepth; ++u) {
    for (int l = u; l <= maxDepth; ++l) {
      temp = 0;
      for (int i = 1; i <= N; ++i) {
        int tar = xtoi[i];
        if (depth[tar] < u || depth[tar] > l) continue;
        temp += weight[tar];
        res = max(res, temp);
        if (temp < 0) temp = 0;
      }
    }
  }

  cout << res;
  
}