#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct cmpStore {
  bool operator()(const pll &lhs, const pll &rhs) const {
    if (lhs.first != rhs.first) return lhs.first < rhs.first;
    return lhs.second < rhs.second;
  }
};
bool cmpCow(pll &lhs, pll &rhs) {
  if (lhs.first != rhs.first) return lhs.first > rhs.first;
  return lhs.second > rhs.second;
}

int N, M;
ll res;
vector<pll> cowDemands; // { min greenness, min price }
multiset<pll, cmpStore> store; // { greenness, price }
multiset<ll> accepted;

ll bisect_left_store(ll minGreenness, ll minPrice) {
  auto it = store.lower_bound({minGreenness, -1});
  for (; it != store.end(); it = store.erase(it)) {
    accepted.insert(it->second);
    //cout << "New Accepted: " << it->first << " " << it->second << endl;
  }
  auto it2 = accepted.lower_bound(minPrice);
  if (it2 == accepted.end()) return -1;
  ll ret = *it2;
  accepted.erase(it2);
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> M;

  cowDemands.resize(N);

  for (int i = 0; i < N; ++i) {
    cin >> cowDemands[i].second >> cowDemands[i].first;
  }
  sort(cowDemands.begin(), cowDemands.end(), cmpCow);
  for (int i = 0; i < M; ++i) {
    pll temp;
    cin >> temp.second >> temp.first;
    store.insert(temp);
  }

  /*
  cout << "# COW" << endl;
  for (pll i : cowDemands) {
    cout << i.first << " " << i.second << endl;
  }
  cout << "# STORE" << endl;
  for (pll i : store) {
    cout << i.first << " " << i.second << endl;
  }

  cout << "# QUERY" << endl;
  */

  for (pll i : cowDemands) {
    // cout << "demanded - grns: " << i.first << " price: " << i.second << endl;
    ll req = bisect_left_store(i.first, i.second);
    if (req == -1) {
      return cout << -1, 0;
    }
    // cout << "bought price: " << req << endl;
    res += req;
  }

  cout << res;

}