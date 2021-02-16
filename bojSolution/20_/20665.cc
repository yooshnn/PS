#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef pair<int, int> pii;

int N, T, P, res = 0;
vector<pii> v;
vector<int> seat;
map<int, int> idToSeat;

int seatBest() {
   int ret, D = 0;
   for (int i = 0; i < N; ++i) {
      int d;
      for (d = 0;; ++d) {
         if ((i-d >= 0 && seat[i-d]) || (i+d < N && seat[i+d])) break;
         if (i-d < 0 && i+d >= N) break;
      }
      if (d > D) {
         D = d;
         ret = i;
      }
   }
   seat[ret] = true;
   return ret;
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);

   // ifstream cin("input.txt");

   cin >> N >> T >> P;

   seat.resize(N, false), v.resize(T), P--;

   for (int i = 0; i < T; ++i) {
      int &f = v[i].first, &t = v[i].second;
      cin >> f >> t;
      f = (f/100 - 9)*60 + (f%100);
      t = (t/100 - 9)*60 + (t%100);
   }
   sort(v.begin(), v.end());

   // for (pii& x : v) {
   //    cout << x.first << " " << x.second << endl;
   // }

   priority_queue<pii, vector<pii>, greater<pii>> enter, leave;

   for (int i = 0; i < T; ++i) {
      enter.push({v[i].first, i});
      leave.push({v[i].second, i});
   }

   for (int i = 0; i < 720; ++i) {
      set<int> ul;
      vector<int> ue;

      while (!leave.empty() && leave.top().first == i) {
         ul.insert(leave.top().second);
         leave.pop();
      }
      while (!enter.empty() && enter.top().first == i) {
         if (ul.find(enter.top().second) == ul.end()) ue.push_back(enter.top().second);
         enter.pop();
      }

      for (int x : ul) {
         if (idToSeat.find(x) == idToSeat.end()) continue;
         seat[idToSeat[x]] = false;
      }
      for (int x : ue) {
         int req = seatBest();
         idToSeat[x] = req;
      }

      if (seat[P] == false) res += 1;
   }

   cout << res;

}