#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pis = pair<int, string>;

const int MOD = 1000000007;

struct AhoCorasick {
  enum {alpha = 26, first = 'a'};
  struct Node {
    int back, next[alpha], start = -1, end = -1;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vector<int> backp;
  void insert(string &s, int j) {
    assert(!s.empty());
    int n = 0;
    for (auto& c : s) {
      int &m = N[n].next[c - first];
      if (m == -1) { n = m = N.size(); N.emplace_back(-1); }
      else n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
  }
  AhoCorasick(vector<string> &pat) {
    N.emplace_back(-1);
    for (int i = 0; i < pat.size(); ++i) insert(pat[i], i);
    N[0].back = N.size();
    N.emplace_back(0);

    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      for (int i = 0; i < alpha; ++i) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1) ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          q.push(ed);
        }
      }
    }
  }
  vector<int> find(string word) {
    int n = 0;
    vector<int> res;
    for (auto &c : word) {
      n = N[n].next[c - first];
      res.push_back(N[n].end);
    }
    return res;
  }
  vector<vector<int>> findAll(vector<string> &pat, string word) {
    vector<int> r = find(word);
    vector<vector<int>> res(word.size());
    for (int i = 0; i < word.size(); ++i) {
      int ind = r[i];
      while (ind != -1) {
        res[i - pat[ind].size() + 1].push_back(pat[ind].size());
        ind = backp[ind];
      }
    }
    return res;
  }
};

int N;
string S;

vector<string> pat;
int dp[100010];

void read();

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  read();

  AhoCorasick A(pat);
  vector<vector<int>> req = A.findAll(pat, S);

  dp[0] = 1;
  for (int i = 0; i < S.size(); ++i) {
    for (int x : req[i]) {
      int idx = i + x;
      dp[idx] = (dp[idx] + dp[i]) % MOD;
    }
  }

  cout << dp[S.size()];

  sad;

}

void read() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string s; cin >> s;
    pat.push_back(s);
  }
  cin >> S;
}
