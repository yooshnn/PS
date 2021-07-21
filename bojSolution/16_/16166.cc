#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

deque<tup> que;
int N, M;
vector<int> line[11];
set<pii> dup;
map<pii, vector<pii>> trans;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int K; cin >> K;
    line[i].resize(K);
    for (int &j : line[i]) {
      cin >> j;
      if (j == 0) que.push_back({i, j, 0}), dup.insert({i, j});
    }
  }
  cin >> M;

  for (int i = 1; i < N; ++i) {
    for (int j = i+1; j <= N; ++j) {
      for (int x : line[i]) {
        for (int y : line[j]) {
          if (x != y) continue;
          trans[{i, x}].push_back({j, y});
          trans[{j, y}].push_back({i, x});
        }
      }
    }
  }

  for (; !que.empty();) {
    auto[li, id, tr] = que.front(); que.pop_front();
    if (id == M) {
      cout << tr;
      return 0;
    }
    for (int &i : line[li]) {
      if (dup.find({li, i}) != dup.end()) continue;
      dup.insert({li, i});
      que.push_front({li, i, tr});
    }
    for (pii &i : trans[{li, id}]) {
      if (dup.find(i) != dup.end()) continue;
      dup.insert(i);
      que.push_back({i.first, i.second, tr + 1});
    }
  }

  cout << -1;
  
}