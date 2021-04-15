#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;


int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N; cin >> N;
  vector<int> deck(N);

  for (int &i : deck) cin >> i;
  sort(deck.begin(), deck.end());

  int res = deck[0];
  for (int i = 1; i < N; ++i) {
    if (deck[i] != deck[i-1] + 1) res += deck[i];
  }

  cout << res;
  
}