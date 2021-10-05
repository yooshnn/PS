#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;

int N, K, a1, a2, b1, b2;
vector<int> v;

bool check() {
  for (int i = 0; i < N; ++i) if (v[i] != i+1) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K >> a1 >> a2 >> b1 >> b2;

  for (int i = 0; i < N; ++i) v.push_back(i+1);

  int pp = 0;
  do {
    pp += 1;
    reverse(v.begin() + a1 - 1, v.begin() + a2);
    reverse(v.begin() + b1 - 1, v.begin() + b2);
  } while (!check());
  
  K %= pp;
  while (K--) {
    reverse(v.begin() + a1 - 1, v.begin() + a2);
    reverse(v.begin() + b1 - 1, v.begin() + b2);
  }

  for (int i : v) cout << i << " ";

  sad;
}