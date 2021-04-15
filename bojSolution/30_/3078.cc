#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

int len, arr[21];
ll res;
queue<int> que;
string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int N, K;
  
  cin >> N >> K;

  for (int i = 0; i < N; ++i) {
    cin >> s; len = s.size();
    res += (ll)arr[len];
    arr[len] += 1;
    
    que.push(len);
    if (que.size() == K + 1) {
      arr[que.front()] -= 1;
      que.pop();
    }
  }
  cout << res;
}