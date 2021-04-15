#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int N, K;

vector<int> seq, res;
vector<bool> ex;
multiset<int> yet;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;

  ex.resize(K+1, false);
  
  for (int i = 0, t; i < N; ++i) {
    cin >> t;
    seq.push_back(t);
    yet.insert(t);
  }

  for (int i = 0; i < N; ++i) {
    yet.erase(yet.find(seq[i]));
    if (ex[seq[i]]) continue;

    if (res.empty() || *--res.end() < seq[i]) {
      res.push_back(seq[i]);
      ex[seq[i]] = true;
    }
    else {
      while (!res.empty() && *--res.end() > seq[i] && yet.find(*--res.end()) != yet.end()) {
        ex[*--res.end()] = false;
        res.pop_back();
      }
      res.push_back(seq[i]);
      ex[seq[i]] = true;
    }
  }

  for (int i : res) cout << i << " ";

}