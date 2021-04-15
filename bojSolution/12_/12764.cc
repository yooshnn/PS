#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> p, q;

int l;
set<int> ff;
map<int, int> popu, ptoid, qtoid;
int uses[100010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0, a, b; i < N; ++i) {
    cin >> a >> b;
    p.push(a);
    q.push(b);
    ptoid[a] = i;
    qtoid[b] = i;
  }

  while (!p.empty() || !q.empty()) {
    int a = (p.empty() ? 2e8 : p.top()), b = (q.empty() ? 2e8 : q.top());
    if (a < b) {
      p.pop();
      int id = ptoid[a];
      uses[id] = (ff.empty() ? ++l : *ff.begin());
      if (!ff.empty()) ff.erase(*ff.begin());
      popu[uses[id]] += 1;
    }
    else {
      q.pop();
      int id = qtoid[b];
      ff.insert(uses[id]);
    }
  }

  cout << popu.size() << "\n";
  for (auto i : popu) cout << i.second << " ";
  
}