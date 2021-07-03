#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
typedef long long ll;

int N;
multiset<int> pool;
vector<int> s;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N; s.resize(N);
  for (int &i : s) cin >> i;

  int lp = 0, rp = -1, res = 0;

  while (rp + 1 < N){
    rp += 1;
    pool.insert(s[rp]);
    while (lp < rp && *--pool.end() - *pool.begin() > 2) {
      pool.erase(pool.find(s[lp]));
      lp += 1;
    }
    res = max(res, (int)pool.size());
  }

  cout << res;

}