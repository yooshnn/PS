#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

int solve(int S, int T) {
  queue<tup> que;
  map<pii, int> dup;

  for (que.push({S, T, 0}); !que.empty(); que.pop()) {
    auto[s, t, d] = que.front();
    if (s == t) return d;
    if (!dup[{s+1, t}]) {
      dup[{s+1, t}] = true;
      que.push({s+1, t, d+1});
    }
    if (!dup[{s*2, t+3}]) {
      dup[{s*2, t+3}] = true;
      if (s*2 <= t+3) que.push({s*2, t+3, d+1});
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    int S, T;
    cin >> S >> T;
    cout << solve(S, T) << '\n';
  }
  
}