#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;

int n, pp;
multiset<int> num;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 0, t; i < n; ++i) {
    cin >> t;
    num.insert(t);
  }

  pp = *num.begin();

  bool DEBUG = false;

  while (!num.empty()) {
    if (num.upper_bound(pp + 1) != num.end() || *num.begin() < pp) {  // 2 이상 큰수 존재
      if (DEBUG) cout << endl << "CASE #1 " << endl;
      //cout << "pp is " << pp << endl;
      if (*num.begin() == pp) {
        for (int i = 0; i < num.count(pp); ++i) {
          cout << pp << " ";
        }
        num.erase(pp);
        pp = *num.upper_bound(pp + 1);
      }
      else {
        cout << pp << " ";
        num.erase(num.find(pp));
        pp = *num.begin();
      }
      //cout << "pp is now " << pp << endl;
    }
    else {  // 1 큰수만 있거나 이게 마지막 수 
      if (DEBUG) cout << endl << "CASE #2 " << endl;
      //cout << "pp is " << pp << endl;
      if (num.find(pp + 1) != num.end()) {
        for (int i = 0; i < num.count(pp + 1); ++i) {
          cout << pp + 1 << " ";
        }
        num.erase(pp + 1);
      }
      for (int i = 0; i < num.count(pp); ++i) {
        cout << pp << " ";
      }
      num.erase(pp);
      pp -= 1;
    }
      if (DEBUG) cout << endl;
      if (DEBUG) { for (auto x : num) cout << x << " "; cout << endl; }
  }
  
}