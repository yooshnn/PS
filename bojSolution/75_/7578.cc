#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sad std::cout.flush(), system("pause")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  ll N, res = 0;
  unordered_map<int, int> idToPos;

  cin >> N;
  vector<int> bridge(N);
  for (int i = 0; i < N; ++i) {
    cin >> bridge[i];
    idToPos[bridge[i]] = i;
  }

  ordered_set pre;
  for (int i = 0; i < N; ++i) {
    int k; cin >> k; k = idToPos[k];
    pre.insert(-k);
    res += (ll)pre.order_of_key(-k);
  }
  cout << res;
}