#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using elem = pair<int, string>;

const int INF = 2e8;

string word;
int N, res = INF;
vector<elem> book;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> word >> N;
  
  book.resize(N);
  for (elem &i : book) cin >> i.first >> i.second;

  for (int i = 1; i < pow(2, N); ++i) {
    int x = i, cost = 0;
    map<char, int> cnt;

    for (int j = 0; j < N; ++j, x >>= 1) {
      if (x&1) {
        cost += book[j].first;
        for (char &c : book[j].second) cnt[c] += 1;
      }
    }

    bool good = true;
    for (char &c : word) if (--cnt[c] == -1) good = false;
    if (good) res = min(res, cost);
    
  }

  cout << (res == INF ? -1 : res);
  
  sad;
}