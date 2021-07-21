#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

ll N, B, pp;
ll arr[100010];
ll cnt, res;
map<ll, ll> mp;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> B;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
    if (arr[i] == B) pp = i;
  }

  cnt = 0;
  for (int i = pp; i >= 1; --i) {
    if (arr[i] > B) cnt += 1;
    else if (arr[i] < B) cnt -= 1;
    mp[cnt] += 1;
  }
  cnt = 0;
  for (int i = pp; i <= N; ++i) {
    if (arr[i] > B) cnt += 1;
    else if (arr[i] < B) cnt -= 1;
    res += mp[-cnt];
  }

  cout << res;

}