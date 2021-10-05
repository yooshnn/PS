#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check(vector<int> &seq, bool fr) {
  int cnt = 0;
  deque<int> deq;
  for (int i = fr; i < seq.size() - 1 + fr; ++i) deq.push_back(seq[i]), cnt += (seq[i] == 1);
  cnt = (cnt / 2) % 2; // 0: 

  while (!deq.empty()) {
    assert(deq.size() > 1);
    if (deq.front() == deq.back()) deq.pop_front(), deq.pop_back();
    else break;
  }

  while (!deq.empty()) {
    assert(deq.size() > 1);
    if (deq[0] == deq[1]) deq.pop_front(), deq.pop_front();
    else return 1;
  }

  if (deq.empty()) return (cnt ? 1 : -1);
  return 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  /*
  while (1) {
    int alice = 0, bob = 0;

    int t, turn = 0;
    while (cin >> t) {
      if (t == -1) break;
      if (turn == 0) alice ^= t;
      else bob ^= t;
      turn = !turn;
      cout << "A : " << alice << ", B : " << bob << endl;
    }
  }
  */

  int TEST; cin >> TEST; while (TEST--) {
    int N; cin >> N;

    int xorSum = 0, msb = -1;

    vector<int> seq(N);
    for (int &i : seq) {
      cin >> i;
      xorSum ^= i;
    }

    for (int i = 0; xorSum > 0; ++i, xorSum >>= 1) {
      if ((xorSum & 1) == 1) msb = i;
    }

    if (msb == -1) cout << "Draw\n";
    else if (N % 2 == 0) {
      cout << "First\n";
    }
    else {
      for (int &i : seq) i = ((i >> msb) & 1);
      int f = 1;

      if (seq.front() == 1) {
        f = min(f, check(seq, 1));
      }
      if (f == 1 && seq.back() != 0) {
        f = min(f, check(seq, 0));
      }
      
      if (f == -1) cout << "First\n";
      else if (f == 0) cout << "Draw\n";
      else cout << "Second\n";
    }
  }

  sad;
}