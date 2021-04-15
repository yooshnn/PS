#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int N;
string P;

const ll x = 31, md = 998244353;
ll d = 1, pp, res;

vector<pii> adj[500010];
string trace = "";

void solve(int id, ll H) {
  if (H == pp) res += 1;

  // cout << id << " " << H << " " << endl;

  if (trace.size() < P.size()) {
    for (pii &i : adj[id]) {
      trace.push_back(i.second);
      solve(i.first, (H * x + i.second) % md);
      trace.pop_back();
    }
  }
  else {
    for (pii &i : adj[id]) {
      ll nH = (H * x + i.second) % md;
      nH = (nH + (md - d * trace[trace.size() - P.size()] % md) % md) % md;
      
      trace.push_back(i.second);
      solve(i.first, nH);
      trace.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int a, b; char c;
    cin >> a >> b >> c;
    adj[a].push_back({b, 1 + c - 'a'});
  }
  cin >> P;

  for (int i = 0; i < P.size(); ++i) {
    d = (d * x) % md;
    pp = (pp * x + (P[i]-'a'+1)) % md;
  }
  // cout << "pp: " << pp << ", d: " << d << endl;

  solve(1, 0);
  cout << res;

}