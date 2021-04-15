#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int N;
map<int, int> weight;
vector<int> v, psum;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0, w; i < N; ++i) {
    cin >> w;
    weight[w] += 1;
  }
  for (pii i : weight) {
    v.push_back(i.first);
    psum.push_back(psum.empty() ? 0 : psum[psum.size()-1]);
    psum[psum.size()-1] += i.first * i.second;
  }

  for (int i = 0; i < psum.size(); ++i) {
    if (psum[i]*2 == psum[psum.size()-1] + v[i]*weight[v[i]]) {
      return cout << v[i], 0;
    }
    if (psum[i]*2 == psum[psum.size()-1]) {
      return cout << v[i]+1, 0;
    }
  }
}