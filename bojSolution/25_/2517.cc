#include <bits/stdc++.h>
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

  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  ordered_set pre;
  for (int i : v) {
    pre.insert(-i);
    cout << 1 + pre.order_of_key(-i) << "\n";
  }
}