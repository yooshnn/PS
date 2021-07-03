#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  ll A, N;
  cin >> A >> N;
  A -= 2;
  N += 1;

  cout << N * (2 + (N - 1) * A) / 2;

}