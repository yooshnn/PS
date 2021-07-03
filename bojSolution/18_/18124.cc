#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  string c = "01336677";

  ll N;
  cin >> N;

  if (N <= 8) cout << c[N-1]; 
  else {
    ll k = 16, cnt = 0;
    while (k < N) k *= 2;

    cout << k - 1 - (k - N) / 2;
  }

}