#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int dup[1000001];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int F, S, G, U, D;
  cin >> F >> S >> G >> U >> D;
  D *= -1;

  for (int i = 1; i <= 1000000; ++i) dup[i] = 2e8;
  dup[S] = 0;

  queue<int> que;
  for (que.push(S); !que.empty(); que.pop()) {
    int cur = que.front();
    if (cur == G) return cout << dup[cur], 0;
    if (cur + U <= F && dup[cur] + 1 < dup[cur + U]) dup[cur + U] = dup[cur] + 1, que.push(cur + U);
    if (cur + D >= 1 && dup[cur] + 1 < dup[cur + D]) dup[cur + D] = dup[cur] + 1, que.push(cur + D);
  }
  cout << "use the stairs";
  
}