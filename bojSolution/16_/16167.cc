#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

const int INF = 2e8;

int N, R;
vector<pii> adj[110];
pii dp[110]; // cost, cnt

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> R;

  for (int i = 0; i < R; ++i) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    adj[a].push_back({b, c + max(0, d * (e - 10))});
  }

  for (int i = 0; i < 110; ++i) dp[i] = {INF, INF};

  queue<tup> que;
  dp[1] = {0, 1};
  for (que.push({0, 1, 1}); !que.empty(); que.pop()) {
    auto[cost, cnt, p] = que.front();
    for (pii &i : adj[p]) { // {dest, cost}
      if (cost + i.second < dp[i.first].first) {
        dp[i.first] = {cost + i.second, cnt + 1};
        que.push({cost + i.second, cnt + 1, i.first});
      }
      else if (cost + i.second == dp[i.first].first && cnt + 1 < dp[i.first].second) {
        dp[i.first] = {cost + i.second, cnt + 1};
        que.push({cost + i.second, cnt + 1, i.first});
      }
    }
  }

  if (dp[N].first == INF) cout << "It is not a great way.";
  else cout << dp[N].first << " " << dp[N].second;
  
  
}