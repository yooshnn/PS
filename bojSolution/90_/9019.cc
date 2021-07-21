#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

const int INF = 2e8;
int a, b;
int dist[10000], par[10000];
char st[10000];

void solve() {
  fill(&dist[0], &dist[0]+10000, INF);
  fill(&par[0], &par[0]+10000, -1);

  queue<int> que;
  dist[a] = 0;
  for (que.push(a); !que.empty(); que.pop()) {
    int cur = que.front(), tar;
    if (cur == b) break;

    tar = (2*cur)%10000;
    if (dist[cur] + 1 < dist[tar]) {
      dist[tar] = dist[cur] + 1;
      par[tar] = cur;
      st[tar] = 'D';
      que.push(tar);
    }

    tar = (9999+cur)%10000;
    if (dist[cur] + 1 < dist[tar]) {
      dist[tar] = dist[cur] + 1;
      par[tar] = cur;
      st[tar] = 'S';
      que.push(tar);
    }

    tar = cur/1000 + (10*cur)%10000;
    if (dist[cur] + 1 < dist[tar]) {
      dist[tar] = dist[cur] + 1;
      par[tar] = cur;
      st[tar] = 'L';
      que.push(tar);
    }

    tar = 1000*(cur%10) + cur/10;
    if (dist[cur] + 1 < dist[tar]) {
      dist[tar] = dist[cur] + 1;
      par[tar] = cur;
      st[tar] = 'R';
      que.push(tar);
    }
  }

  int pp = b;
  stack<char> res;
  while (par[pp] != -1) {
    res.push(st[pp]);
    pp = par[pp];
  }
  while (!res.empty()) {
    cout << res.top();
    res.pop();
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    cin >> a >> b;
    solve();
  }

}