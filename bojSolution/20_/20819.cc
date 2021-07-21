#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using pii = pair<int, int>;
using ll = long long;

struct Party {
  int day;
  vector<int> discuss;
  Party(int &d, vector<int> &v) { day = d, discuss = v; }
  bool operator<(const Party &other) { return day < other.day; }
};

int
  N, K, // # of parties, TV series(1..K)
  showLen[200010]; // length of i-th TV series
bool
  pushed[200010];
vector<Party>
  party;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> K;
  for (int i = 1; i <= K; ++i) {
    cin >> showLen[i];
  }
  for (int i = 1; i <= N; ++i) {
    int day, t;
    cin >> day >> t;
    vector<int> discussion(t);
    for (int &x : discussion) cin >> x;
    party.push_back(Party(day, discussion));    
  }
  sort(party.begin(), party.end());

  queue<int> mustWatch;
  for (Party x : party) {
    for (int y : x.discuss) {
      if (!pushed[y]) {
        pushed[y] = true;
        mustWatch.push(y);
      }
    }
  }

  int pp = 0;
  for (int i = 0; i <= 200000; ++i) {
    if (party[pp].day == i) {
      bool good = true;
      for (int x : party[pp].discuss) {
        if (showLen[x] != 0) good = false;
      }
      if (!good) {
        return cout << "Nej", 0;
      }
      pp += 1;
    }
    else {
      int tenHours = 10;
      while (tenHours > 0 && !mustWatch.empty()) {
        int tar = mustWatch.front();
        int amnt = min(tenHours, showLen[tar]);
        showLen[tar] -= amnt;
        tenHours -= amnt;
        if (showLen[tar] == 0) mustWatch.pop();
      }
    }
    if (pp == party.size()) break;
  }
  cout << "Ja";
}