#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

struct Task {
  int vol;
  vector<vector<string>> story;
  vector<int> par;
  vector<char> ltype;
  vector<vector<int>> adj;

  Task(int L) {
    vol = L + 1;
    par.resize(vol, -1);
    story.resize(vol);
    ltype.resize(vol);
    adj.resize(vol);

    rd();
    solve();
  }

  void rd() {
    for (int i = 1; i < vol; ++i) {
      cin >> ltype[i];

      string t;
      bool esc = false;
      do {
        esc = false;
        cin >> t;
        if (t[0] == '"') t = t.substr(1);
        if (t[t.size()-1] == '"') t.pop_back(), esc = true;
        story[i].push_back(t);
      } while (!esc);

      if (ltype[i] == 'C') {
        adj[i].resize(2);
        for (int &x : adj[i]) cin >> x;
      }
      else {
        cin >> t;
        if (t[0] != 'H') ltype[i] = 'D';
      }
    }
  }

  void solve() {
    queue<int> que;
    par[1] = 1;
    for (que.push(1); !que.empty(); que.pop()) {
      int cur = que.front();
      if (ltype[cur] == 'E') {
        stack<int> trace;
        trace.push(cur);
        while (par[cur] != cur) {
          cur = par[cur];
          trace.push(cur);
        }
        while (!trace.empty()) {
          for (string &i : story[trace.top()]) cout << i << " ";
          cout << "\n";
          trace.pop();
        }
        return;
      }
      else if (ltype[cur] == 'C') {
        for (int i = 0; i < 2; ++i) {
          int nxt = adj[cur][i];
          if (par[nxt] == -1) {
            par[nxt] = cur;
            que.push(nxt);
          }
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int _TEST; cin >> _TEST; for (int TEST = 1; TEST <= _TEST; ++TEST) {
    cout << "STORY " << TEST << "\n";
    int L; cin >> L;
    Task T(L);
    cout.flush();
  }

}