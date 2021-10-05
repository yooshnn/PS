#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TEST; cin >> TEST; while (TEST--) {
    priority_queue<int> que1;
    priority_queue<int, vector<int>, greater<int>> que2;
    
    int N; cin >> N;
    cout << (N+1)/2 << "\n";
    for (int i = 1, t; i <= N; ++i) {
      cin >> t;

      if (i&1) que1.push(t);
      else que2.push(t);

      if (i != 1 && que2.top() < que1.top()) {
        int a = que1.top(), b = que2.top();
        que1.pop(), que2.pop();
        que1.push(b), que2.push(a);
      }

      if (i&1) cout << que1.top() << " ";
    }
    cout << "\n";
  }
  
  sad;
}