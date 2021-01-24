#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;


int main() {
   ios::sync_with_stdio(0), cin.tie(0);
   
   bool good = true;
   int N, M; cin >> N >> M;

   int pos[N];
   vector<vector<int>> solved(N, vector<int>(M));

   for (int n = 0; n < N; ++n) {
      cin >> pos[n];
      if (pos[n] == M || pos[n] == 0) good = false;
      for (int m = 0; m < M; ++m) {
         cin >> solved[n][m];
         if (solved[n][m]==1) pos[n] -= 1;
      }
   }

   for (int i = 0; i < M; ++i) {
      bool anyone = false;
      for (int n = 0; n < N; ++n) {
         if (solved[n][i] == 1) anyone = true;
      }
      if (!anyone) {
         for (int n = 0; n < N; ++n) {
            if (pos[n] > 0 && solved[n][i] == -1) {
               solved[n][i] = 1;
               pos[n] -= 1;
               break;
            }
         }
      }
   }

   for (int i = 0; i < M; ++i) {
      bool anyone = false;
      for (int n = 0; n < N; ++n) {
         if (solved[n][i] == 1) anyone = true;
      }
      if (!anyone) good = false;
   }

   cout << (good ? "YES" : "NO");
   
}