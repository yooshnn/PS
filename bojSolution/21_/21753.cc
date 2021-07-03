#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  ll n, cnt = 0; cin >> n;

  while (n != 0) {
    cnt += n&1;
    n /= 2;
  }
  cout << (1 << cnt);

}