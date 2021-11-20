#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

const int T_SIZE = 1<<17;
int arr[T_SIZE];
vector<int> tree[T_SIZE<<1];

int N, Q;

void update(int x, int v) {
  x |= T_SIZE;
  tree[x].push_back(v);
}
void build() {
  for (int i = 1; i <= N; ++i) update(i, arr[i]);
  for (int i = T_SIZE-1; i; --i) {
    tree[i].resize(tree[i*2].size() + tree[i*2+1].size());
    merge(all(tree[i*2]), all(tree[i*2+1]), tree[i].begin());
  }
}
int query(int l, int r, int k) {
  l |= T_SIZE, r |= T_SIZE;
  int ret = 0;
  while (l <= r) {
    if (l & 1) ret += tree[l].end() - upper_bound(all(tree[l]), k), l++;
    if (~r & 1) ret += tree[r].end() - upper_bound(all(tree[r]), k), r--;
    l >>= 1, r >>= 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> arr[i];
  build();

  cin >> Q;
  for (int l, r, k; Q; Q--) {
    cin >> l >> r >> k;
    cout << query(l, r, k) << "\n";
  }

  sad;
}