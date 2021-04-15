#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using tup = tuple<int, int, int>;

int A, B, C, a, b, c;
set<tup> dup;

set<int> res;

void solve() {
  queue<tup> que;
  dup.insert({a, b, c});
  int t;

  for (que.push({a, b, c}); !que.empty(); que.pop()) {
    auto [a_, b_, c_] = que.front();
    if (a_ == 0) res.insert(c_);
    if (a_ != 0) {
      t = min(a_, B - b_);
      if (dup.find({a_ - t, b_ + t, c_}) == dup.end()) {
        dup.insert({a_ - t, b_ + t, c_});
        que.push({a_ - t, b_ + t, c_});
      }
      t = min(a_, C - c_);
      if (dup.find({a_ - t, b_, c_ + t}) == dup.end()) {
        dup.insert({a_ - t, b_, c_ + t});
        que.push({a_ - t, b_, c_ + t});
      }
    }
    if (b_ != 0) {
      t = min(b_, A - a_);
      if (dup.find({a_ + t, b_ - t, c_}) == dup.end()) {
        dup.insert({a_ + t, b_ - t, c_});
        que.push({a_ + t, b_ - t, c_});
      }
      t = min(b_, C - c_);
      if (dup.find({a_, b_ - t, c_ + t}) == dup.end()) {
        dup.insert({a_, b_ - t, c_ + t});
        que.push({a_, b_ - t, c_ + t});
      }
    }
    if (c_ != 0) {
      t = min(c_, A - a_);
      if (dup.find({a_ + t, b_, c_ - t}) == dup.end()) {
        dup.insert({a_ + t, b_, c_ - t});
        que.push({a_ + t, b_, c_ - t});
      }
      t = min(c_, B - b_);
      if (dup.find({a_, b_ + t, c_ - t}) == dup.end()) {
        dup.insert({a_, b_ + t, c_ - t});
        que.push({a_, b_ + t, c_ - t});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> A >> B >> C;
  c = C;

  solve();
  
  for (int i : res) cout << i << " ";

}