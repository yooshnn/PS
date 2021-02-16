#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;

int par[202], cnt[202], res;

int search(int tar) {
	if (tar == par[tar]) return tar;
	return par[tar] = search(par[tar]);
}
void merge(int a, int b) {
	a = search(a), b = search(b);
	if (a == b) return;
	par[b] = a;
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0);

   int TEST; cin >> TEST; while (TEST--) {

      int N; cin >> N;

      res = 0;
      for (int i = 0; i < N; ++i) par[i] = i, cnt[i] = 0;

      for (int r = 0, t; r < N; ++r) {
         for (int c = 0; c <= r; ++c) cin >> t;
         for (int c = r+1; c < N; ++c) {
            cin >> t; if (t == 1) merge(r, c);
         }
      }
      
      for (int i = 0; i < N; ++i) {
         cnt[search(i)] += 1;
      }

      for (int i = 0; i < N; ++i) {
         res += max(0, cnt[i] - 1);
      }
      cout << res << "\n";

   }

}