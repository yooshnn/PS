#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

string name, s, t;
int N;
vector<string> days;
set<string> pos;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> name >> N;

  for (int i = 0; i < name.size(); ++i) {
    s = t = "";
    for (int j = 0; j < i; ++j) s.push_back(name[j]);
    for (int j = i+1; j < name.size(); ++j) t.push_back(name[j]);
    for (char c = 'a'; c <= 'z'; ++c) {
      if (c == name[i]) continue;
      pos.insert(s + c + t);
    }
  }

  int exactDay = -1;
  for (int i = 0; i < N; ++i) {
    cin >> s;
    if (s == name) exactDay = i;
    days.push_back(s);
  }

  int res = N;
  for (int i = 0; i < N; ++i) {
    if (i == exactDay) continue;
    if (pos.find(days[i]) != pos.end()) {
      if (i < exactDay) res = min(res, N-exactDay+i);
      else res = min(res, i - exactDay);
    }
  }

  cout << res;
  
}