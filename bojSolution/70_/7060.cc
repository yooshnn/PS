#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

int
  R, C,
  res, cnt,
  root[10200],
  board[110][110];
vector<tup>
  wire;

int dsfind(int tar) {
  if (tar == root[tar]) return tar;
  return root[tar] = dsfind(root[tar]);
}
void dsmerge(int a, int b) {
  a = dsfind(a), b = dsfind(b);
  if (a != b) root[a] = b;
}
int rc2id(int r, int c) { --r; return r*C + c; }
pii id2rc(int i) { --i; return {1 + i/C, 1 + i%C}; }

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  priority_queue<tup, vector<tup>, greater<tup>> que;

  cin >> R >> C;
  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    root[rc2id(r, c)] = rc2id(r, c);
    int &tar = board[r][c];
    cin >> tar;
    if (tar == 1) {
      que.push({0, rc2id(r, c), rc2id(r + 1, c)});
      if (c != C) que.push({2, rc2id(r, c), rc2id(r, c + 1)});
    }
    else if (tar == 2) {
      que.push({0, rc2id(r, c), rc2id(r, c + 1)});
      if (r != R) que.push({1, rc2id(r, c), rc2id(r + 1, c)});
    }
    else if (tar == 3) {
      que.push({0, rc2id(r, c), rc2id(r + 1, c)});
      que.push({0, rc2id(r, c), rc2id(r, c + 1)});
    }
    else {
      if (r != R) que.push({1, rc2id(r, c), rc2id(r + 1, c)});
      if (c != C) que.push({2, rc2id(r, c), rc2id(r, c + 1)});
    }
  }

  while (!que.empty()) {
    auto [w, u, v] = que.top(); que.pop();
    auto [r1, c1] = id2rc(u);
    
    if (dsfind(u) == dsfind(v)) continue;
    dsmerge(u, v);
    
    if (w != 0) {
      res += w;
      cnt += 1;
      wire.push_back({r1, c1, w});
    }
  }

  cout << cnt << " " << res << "\n";
  for (auto [r, c, w] : wire) {
    cout << r << " " << c << " " << w << "\n";
  }

}