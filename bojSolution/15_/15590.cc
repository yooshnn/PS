#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N, M, R;
ll res;
vector<ll> cow, rent, mm;
vector<pll> milk;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  mm.push_back(0);

  cin >> N >> M >> R;

  cow.resize(N+1), milk.resize(M+1), rent.resize(R+1);
  
  for (int i = 1; i <= N; ++i) cin >> cow[i];
  for (int i = 1; i <= M; ++i) cin >> milk[i].second >> milk[i].first;
  for (int i = 1; i <= R; ++i) cin >> rent[i];

  sort(cow.begin()+1, cow.end(), greater<ll>());
  sort(milk.begin()+1, milk.end(), greater<pll>());
  sort(rent.begin()+1, rent.end(), greater<ll>());

  for (int i = 1; i <= N; ++i) cow[i] += cow[i-1];
  for (int i = 1; i <= M; ++i) {
    mm.push_back(mm.back() + milk[i].first * milk[i].second);
    milk[i].first += milk[i-1].first, milk[i].second += milk[i-1].second;
  }
  for (int i = 1; i <= R; ++i) rent[i] += rent[i-1];
  
  for (int i = 0; i <= N; ++i) {
    ll lcow = cow[i];

    int lp = 0, rp = M, mid, pos;
    while (lp <= rp) {
      mid = (lp+rp)/2;
      if (milk[mid].second > lcow) rp = mid - 1;
      else {
        pos = mid;
        lp = mid + 1;
      }
    }

    res = max({ res,
      rent[min(R, N-i)] + mm[pos] +
      (pos == M ? 0 : (milk[pos+1].first - milk[pos].first) * (lcow - milk[pos].second))
    });
  }

  cout << res;
  
  sad;
}