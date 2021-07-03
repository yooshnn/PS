#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

map<string, int> strToUid;
map<int, string> uidToStr;
int g = 1;

bool dup[100010];
vector<int> adj[100010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int TT; cin >> TT; while (TT--) {
    int a, b;
    string s;
    cin >> s;
    if (strToUid.find(s) == strToUid.end()) {
      strToUid[s] = g;
      uidToStr[g] = s;
      g += 1;
    }
    a = strToUid[s];
    
    cin >> s >> s;
    if (strToUid.find(s) == strToUid.end()) {
      strToUid[s] = g;
      uidToStr[g] = s;
      g += 1;
    }
    b = strToUid[s];

    adj[a].push_back(b);
  }

  if (strToUid.find("Baba") != strToUid.end()) {
    set<string> res;
    
    queue<int> que;

    for (int &i : adj[strToUid["Baba"]]) que.push(i), dup[i] = true;

    for (; !que.empty(); que.pop()) {
      int cur = que.front();
      res.insert(uidToStr[cur]);
      for (int &i : adj[cur]) {
        if (dup[i]) continue;
        dup[i] = true;
        que.push(i);
      }
    }

    for (string i : res) cout << i << "\n";
  }

}