#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

string s;
int k, len;
vector<char> seq;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> s >> k;
  len = s.size();

  for (int i = 0; i < len; ++i) {
    while (!seq.empty() && seq.back() > s[i] && seq.size() + len - i > k) {
      seq.pop_back();
    }
    if (seq.size() < k) seq.push_back(s[i]);
  }
  for (char i : seq) cout << i;
  
}